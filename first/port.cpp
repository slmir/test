#include "port.h"
#include <math.h>
#include <QMessageBox>


Port::Port()
{

}

Port::Port(QSerialPortInfo portInfo, int baudRate) {
	this->port = new QSerialPort(portInfo);
	port->setBaudRate(baudRate);
	qDebug() << QString("Новый порт! %1, %2 бод\n").arg(portInfo.portName(), QString::number(baudRate));
	SendData(new QByteArray());
}

void Port::SendData(QByteArray* data) {
	/*qDebug() << "Массив до генерации ошибок: ";
	for (auto byte : *data) {
		qDebug() << byte;
	}*/
	GenerateMessageError(data, 0.02f);
	/*qDebug() << "Массив после генерации ошибок: ";
	for (auto byte : *data) {
		qDebug() << byte;
	}*/

	if (this->port->open(QIODevice::WriteOnly)) {
		qDebug() << QString("Порт %1 открыт!").arg(this->port->portName());
	} else {
		qDebug() << QString("Порт %1 не открыт!").arg(this->port->portName());
		return;
	}

	this->port->write(*data);
	if (this->port->error() == QSerialPort::WriteError) {
		qDebug() << QString("\nОшибка при записи (порт %1)").arg(this->port->portName());
		return;
	} else {
		qDebug() << QString("\nЗапись прошла успешно.");
	}

	this->port->close();
	return;
}

void Port::GenerateMessageError(QByteArray*& data, float errorPercent) {
	for (int i = 0; i < data->length(); i = i + 1) {
		for (int bitNum = 0; bitNum < 8; bitNum = bitNum + 1) {
			if ((static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) < errorPercent) {
				//qDebug() << data->at(i) << QString::number((int) data->at(i));
				char replaced = (data->at(i) ^ (1 << bitNum));
				data->replace(i, 1, &replaced, 1);
				//qDebug() << replaced << QString::number((int) replaced) << QString(" (bit changed: %1)").arg(QString::number(bitNum));
			}
		}
	}
}

QByteArray* Port::ReceiveData() {
	QByteArray* readData = new QByteArray();

	if (this->port->open(QIODevice::WriteOnly)) {
		qDebug() << QString("Порт %1 открыт!").arg(this->port->portName());
	} else {
		qDebug() << QString("Порт %1 не открыт!").arg(this->port->portName());
		delete readData;
		return nullptr;
	}

	while (this->port->waitForReadyRead()) {
		readData->append(this->port->readAll());
		if (this->port->error() == QSerialPort::ReadError) {
			qDebug() << QString("\nОшибка при чтении (порт %1)").arg(this->port->portName());
			delete readData;
			return nullptr;
		} else {
			qDebug() << QString("\nЧтение прошло успешно.");
		}
	}

	return readData;
}

Port::~Port() {
	delete this->port;
}
