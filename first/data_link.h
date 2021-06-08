#ifndef DATA_LINK_H
#define DATA_LINK_H
#include <QFile>
#include <QBitArray>
#include <QObject>
#include <QTableWidget>
#include <QtSerialPort/QSerialPortInfo>
#include "port.h"


class MainWindow;
class Port;


class DataLink : public QObject {
	Q_OBJECT

	public:
		// Физический уровень
		Port* port;
		// Окошко передаётся для связи сигналов и слотов
		DataLink(MainWindow* mw, QTableWidget* table);

		// Задание рабочего порта (отправка или приём - не важно)
		void SetPort(QSerialPortInfo portInfo, int baudRate);
		// Открытие рабочего порта (возвращает код ошибки; 0 - отсутствие)
		int OpenPort();
		// Закрытие рабочего порта (аналогичное поведение)
		int ClosePort();
		// Оболочка для передачи данных
		void SendFile(QString path);
		// Инициация процедуры установки соединения (UPLINK)
		bool SendHello();
		// Получение статуса соединения (установлено - true, разорвано - false)
		bool GetConnectionStatus();
		// Получение статуса порта (внутри только вызов соотв-ей функции физ. уровня)
		bool GetPortStatus();
		// Инициация процедуры разрыва соединения (DOWNLINK)
		bool SendGoodbye();

	private:
		// Ссылка на окно с отладочными сообщениями
		QTableWidget* debugTable;
		// Ссылка на основное окно (связь с прикладным уровнем)
		MainWindow* mw;
		// Флаг установки соединения
		bool isConnected;
		// Число прочитанных при обмене файлом бит
		int bitsRead;
		// Размер передаваемого файла в байтах
		int bytesToRead;
		// Сюды запихиваем сформированные для отправки кадры
		QList<QByteArray> *infoFramesToSend;
		// Сюды запихиваем раскодированные данные
		QList<bool> *receivedBits;
		// Сюды отправляется последний принятый кадр (от слота OnNewDataToRead)
		QByteArray *receivedData;
		// Счётчик ошибок
		int NAK_counter;

		// Превращение файла с последовательность кадров
		QList<QByteArray>* FormInfoFrames(QByteArray source);
		// Отправка следующего информационного кадра
		void SendAnotherInfoFrame();

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
		//void SendInfoFrames(QByteArray bytes, int size);
		//bool SendInfoFrame(QByteArray frame);

		// Вычленение информации из кадров
		char UnwrapControlFrame(QByteArray controlFrame);
		int UnwrapSizeFrame(QByteArray sizeFrame);
		bool UnwrapInfoFrame(QByteArray frame);

		// Формирование двоичного файла из полученных данных с указанием пути назначения
		void ConvertReceivedToFile(QString path);

		// Дядя Хэм
		QByteArray HammingCode(QBitArray arr);
		QBitArray* HammingDecode(QBitArray code);

		// Блокировка программы до получения ответного кадра (ACK/NAK).
		// Используется в случае, когда после получения ответа нужно продолжить работу в методе
		// (изначально управление переходит на слот OnNewDataToRead, после чего идёт возврат на точку)
		void WaitForAnswer();

		// Внесение нового отладочного сообщения
		void InsertNewDebugMessage(QString message);

	public slots:
		// Обработчик приходящих данных
		void OnNewDataToRead(QByteArray* data);
		// Слоты для реакции на действия пользователя при начале процедуры обмена файла
		void OnReceiveAccepted();
		void OnReceiveAborted();
		void OnSaveFileButtonClicked(QString path);

	signals:
		// Сигнал получения нового файла (используется для заполнения прогрессбара)
		void NewInfoFrameReceived(float currentProgress);
		// Сигнал смены статуса соединения (для уведомления пользователя в основном окне)
		void ConnectionStatusChanged(bool status);
		// Сигнал смены статуса порта (для уведомления пользователя в основном окне)
		void PortStatusChanged(bool status);
		// Сигнал получения запроса на передачу файла (при получении первичного кадра с размером)
		bool FileSendRequested(int fileSize);
		// Прерываем передачу файла при возникновении слишком большого числа ошибок
		void ExchangeAborted();
};

#endif // DATA_LINK_H
