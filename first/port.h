#ifndef PORT_H
#define PORT_H

#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QBitArray>

class Port
{
	public:
		Port();
		Port(QSerialPortInfo portInfo, int baudRate);

		// Открытие порта с возвращением кода ошибки (0 - её отсутствие)
		int Open(QIODevice::OpenMode openModeValue);
		// Передача порции данных (внутри функции порт не открывается и не закрывается)
		void SendData(QByteArray data);
		// Повторная отправка порции данных, переданной при крайнем вызове SendData()
		void ResendLastDataPiece();
		// Получение порции данных (внутри функции порт не открывается и не закрывается)
		QByteArray* ReceiveData(int sizeToRead);
		// Закрытие порта с возвращением кода ошибки (0 - её отсутствие)
		int Close();

		~Port();
	private:
		QSerialPort* port;
		QByteArray* sentFrameBuffer;

		void GenerateMessageError(QByteArray& data, float errorPercent);

};

#endif // PORT_H
