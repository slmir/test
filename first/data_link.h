#ifndef DATA_LINK_H
#define DATA_LINK_H
#include <QFile>
#include <QDataStream>
#include <QBitArray>
#include <QObject>
#include <QSaveFile>
#include <QtSerialPort/QSerialPortInfo>
#include "port.h"

class MainWindow;
class Port;

class DataLink : public QObject {
	Q_OBJECT

	public:
		Port* port;
		// Окошко передаётся для связи сигналов и слотов
		DataLink(MainWindow* mw);

		// Задание рабочего порта (отправка или приём - не важно)
		void SetPort(QSerialPortInfo portInfo, int baudRate);
		// Открытие рабочего порта (возвращает код ошибки; 0 - отсутствие)
		int OpenPort();
		// Закрытие рабочего порта (аналогичное поведение)
		int ClosePort();
		// Оболочка для передачи данных
		void SendFile(QString path);
		// Проверка установки соединения (пока что всегда возвращает false, потому что я уведомление об установке перенёс на слот-сигнал)
		bool SendHello();
		//
		bool GetConnectionStatus();
		//
		bool SendGoodbye();

	private:
		// Флаг установки соединения
		bool isConnected;
		// Число прочитанных бит
		int bitsRead;
		// Размер передачи в байтах
		int bytesToRead;
		// Сюды запихиваем раскодированные данные
		QList<bool> *receivedBits;
		// Сюды отправляется последний принятый кадр (от слота OnNewDataToRead)
		QByteArray *receivedData;
		// Счётчик ошибок (пока не работал с ошибками; просто поставил вероятность ошибки 1е-10 у себя)
		int NAK_counter;

		// QByteArray -> QBitArray
		QBitArray ConvertByteArrToBitArr(QByteArray bytes);
		// QBitArray -> QByteArray
		QByteArray ConvertBitArrToByteArr(QBitArray bits);
		// Вычленение из данных по 11 бит (для кодирования по Хэммингу)
		QBitArray To11Bits(QBitArray ba, int i);

		// Формирование управляющего кадра на основе получаемого служебного символа
		QByteArray WrapControlFrame(char type);
		// Формирование первичного кадра с указанием длины передаваемого файла
		QByteArray WrapSizeFrame(int size);
		// Формирование информационного кадра из передаваемых данных
		QByteArray WrapInfoFrame(QByteArray info);

		// Обёртка над методами WRAP; результат упаковки сразу отправляет в порт
		void SendControlFrame(char type);
		void SendSizeFrame(int size);
		void SendInfoFrames(QByteArray bytes, int size);
		bool SendInfoFrame(QByteArray frame);

		// Вычленение инфы из кадров
		char UnwrapControlFrame(QByteArray controlFrame);
		int UnwrapSizeFrame(QByteArray sizeFrame);
		void UnwrapInfoFrame(QByteArray frame);

		// Формирование двоичного файла из полученных данных с указанием пути назначения (пока что там заглушка на D:/read.txt)
		void ConvertReceivedToFile(QString path);

		// Дядя Хэм ёпты
		QByteArray HammingCode(QBitArray arr);
		QBitArray* HammingDecode(QBitArray code);

		// Блокировка программы до получения ответного кадра (ACK или об ошибке)
		void WaitForAnswer();

	public slots:
		// Обработчик приходящих данных
		void OnNewDataToRead(QByteArray* data);

	signals:
		void DataRead();
		void ConnectionStatusChanged(bool status);
};

#endif // DATA_LINK_H
