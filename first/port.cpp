#include "port.h"
#include <math.h>
#include <QMessageBox>


Port::Port()
{
	this->sentFrameBuffer = new QByteArray();
}


Port::Port(QSerialPortInfo portInfo, int baudRate): Port() {
	this->port = new QSerialPort(portInfo);
	port->setBaudRate(baudRate);
	qDebug() << QString("Новый порт! %1, %2 бод\n").arg(portInfo.portName(), QString::number(baudRate));
}


int Port::Open(QIODevice::OpenMode openModeValue) {
	QMessageBox* box;

	if (port->open(openModeValue)) {
		box = new QMessageBox(QMessageBox::Icon::Information, QString("Уведомление"), QString("Порт %1 успешно открыт!").arg(port->portName()));
		box->exec();
	} else {
		box = new QMessageBox(QMessageBox::Icon::Critical, QString("ОШИБКА"), "");

		switch (port->error()) {
			case QSerialPort::OpenError: {
				box->setText(QString("Порт %1 уже был открыт!").arg(port->portName()));
				break;
			}
			case QSerialPort::DeviceNotFoundError: {
				box->setText(QString("Порт %1 не найден!").arg(port->portName()));
				break;
			}
			case QSerialPort::UnknownError: {
				box->setText(QString("Неизвестная критическая ошибка при открытии порта %1!").arg(port->portName()));
				break;
			}
			default: {
				box->setText(QString("Ошибка при открытии порта %1! (код: %2)").arg(port->portName(), port->error()));
				break;
			}
		}
	}
	box->exec();

	delete box;
	return port->error();
}


void Port::SendData(QByteArray data) {
	// Занести отправляемую информацию в буфер, чтобы повторить отправку при возникновении ошибок
	this->sentFrameBuffer = new QByteArray(data);

	/*qDebug() << "Массив до генерации ошибок: ";
	for (auto byte : *data) {
		qDebug() << byte;
	}*/
	GenerateMessageError(data, 0.02f);
	/*qDebug() << "Массив после генерации ошибок: ";
	for (auto byte : *data) {
		qDebug() << byte;
	}*/


	port->write(data);
	if (port->error() == QSerialPort::WriteError) {
		qDebug() << QString("\nОшибка при записи (порт %1)").arg(port->portName());
		return;
	} else {
		qDebug() << QString("\nЗапись прошла успешно.");
	}
	return;
}

void Port::ResendLastDataPiece() {
	port->write(*(this->sentFrameBuffer));

	if (port->error() == QSerialPort::WriteError) {
		qDebug() << QString("\nОшибка при повторной отправке последнего кадра (порт %1)").arg(port->portName());
		return;
	} else {
		qDebug() << QString("\nПовторная отправка последнего кадра прошла успешно.");
	}
	return;
}


void Port::GenerateMessageError(QByteArray& data, float errorPercent) {
	for (int i = 0; i < data.length(); i = i + 1) {
		for (int bitNum = 0; bitNum < 8; bitNum = bitNum + 1) {
			if ((static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) < errorPercent) {
				//qDebug() << data->at(i) << QString::number((int) data->at(i));
				char replaced = (data.at(i) ^ (1 << bitNum));
				data.replace(i, 1, &replaced, 1);
				//qDebug() << replaced << QString::number((int) replaced) << QString(" (bit changed: %1)").arg(QString::number(bitNum));
			}
		}
	}
}


QByteArray* Port::ReceiveData(int sizeToRead) {
	QByteArray* readData = new QByteArray();

	while (port->waitForReadyRead()) {
		readData->append(port->read(sizeToRead));
		if (port->error() == QSerialPort::ReadError) {
			qDebug() << QString("\nОшибка при чтении (порт %1)").arg(port->portName());
			delete readData;
			return nullptr;
		} else {
			qDebug() << QString("\nЧтение прошло успешно.");
		}

		return readData;
	}

	return nullptr;
}


int Port::Close() {
	QMessageBox* box;

	port->close();


	if (port->error() == 0) {
		box = new QMessageBox(QMessageBox::Icon::Information, QString("Уведомление"), QString("Порт %1 успешно закрыт!").arg(port->portName()));
	} else {
		box = new QMessageBox(QMessageBox::Icon::Critical, QString("ОШИБКА"), "");
		switch (port->error()) {
			case QSerialPort::NotOpenError: {
				box->setText(QString("Порт %1 уже был закрыт!").arg(port->portName()));
				break;
			}
			default: {
				box->setText(QString("Ошибка при закрытии порта %1! (код: %2)").arg(port->portName(), port->error()));
				break;
			}
		}
		box->exec();
	}

	delete box;
	return port->error();
}


Port::~Port() {
	delete sentFrameBuffer;
	delete port;
}
