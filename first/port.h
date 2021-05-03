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
		~Port();
	private:
		QSerialPort* port;

		void GenerateMessageError(QByteArray*& data, float errorPercent);
		float GetExponentialRand(float lambda);
		void PortError(QSerialPort::SerialPortError error);
	private slots:
		// Если понадобится на канальном уровне, сделаю перегрузку для битового массива
		void SendData(QByteArray* data);
		QByteArray* ReceiveData();

};

#endif // PORT_H
