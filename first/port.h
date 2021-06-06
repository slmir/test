#ifndef PORT_H
#define PORT_H

#include <QDebug>
#include <QtSerialPort/QSerialPort>
//#include "data_link.h"

class DataLink;

class Port : public QObject {
	Q_OBJECT

	public:

		Port();
		Port(QSerialPortInfo portInfo, int baudRate, DataLink* link);

		// Открытие порта с возвращением кода ошибки (0 - её отсутствие)
		int Open(QIODevice::OpenMode openModeValue);
		// Передача порции данных (внутри функции порт не открывается и не закрывается)
		void SendData(QByteArray data);
		// Повторная отправка порции данных, переданной при крайнем вызове SendData()
		void ResendLastDataPiece();
		// Закрытие порта с возвращением кода ошибки (0 - её отсутствие)
		int Close();

		// Получение имени порта (исключительно для прикладного уровня)
		QString GetPortName();
		// Получение статуса порта (открыт - true, закрыт - false)
		bool GetOpenStatus();
		// Получение данных из буфера
		QByteArray* GetLastReceivedFrame();
		QByteArray* GetLastSentFrame();
		// Очистка буфера
		// Пригождается для того, чтобы подчищать оставшиеся хвосты при каких-либо внештатных взаимодействиях
		// (например, нажать на кнопку установки соединения не 1 раз, а 10)
		void ClearBuffers();

		virtual ~Port();
	private:
		QSerialPort* port;
		// Запоминаем последний отправленный кадр (на случай ошибок)
		QByteArray* sentFrameBuffer;
		// И также последний принятый (для корректных обменов на канальном уровне)
		QByteArray* receivedFrameBuffer;
		//
		bool isOpened;

		void GenerateMessageError(QByteArray& data, float errorPercent);

	private slots:
		// Получение порции данных (внутри функции порт не открывается и не закрывается)
		void OnDataReceived();

	signals:
		void NewDataToRead(QByteArray* data);

};

#endif // PORT_H
