#ifndef PORT_H
#define PORT_H

#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QBitArray>
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
		QString GetPortName();
		bool GetOpenStatus();
		QByteArray* GetLastReceivedFrame();

		virtual ~Port();
	private:
		QSerialPort* port;
		// Запоминаем последний отправленный кадр (на случай ошибок)
		QByteArray* sentFrameBuffer;
		// И также последний принятый (для корректных обменов на канальном уровне)
		QByteArray* receivedFrameBuffer;

		bool isOpened;

		void GenerateMessageError(QByteArray& data, float errorPercent);

	private slots:
		// Получение порции данных (внутри функции порт не открывается и не закрывается)
		void OnDataReceived();

	signals:
		void NewDataToRead(QByteArray* data);

};

#endif // PORT_H
