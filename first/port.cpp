#include "port.h"
#include <math.h>
#include <QMessageBox>
#include <QtSerialPort/QSerialPortInfo>
#include "data_link.h"

class DataLink;
class QSerialPortInfo;

Port::Port()
{
	ClearBuffers();
	this->isOpened = false;

}


Port::Port(QSerialPortInfo portInfo, int baudRate, DataLink* link): Port() {
	this->port = new QSerialPort(portInfo);

	// Соединяем порт с данным классом
	connect(port, &QSerialPort::readyRead, this, &Port::OnDataReceived);
	// Соединяем физ. уровень с канальным
	connect(this, &Port::NewDataToRead, link, &DataLink::OnNewDataToRead);
	port->setBaudRate(baudRate);
	qDebug() << QString("Новый порт! %1, %2 бод\n").arg(portInfo.portName(), QString::number(baudRate));
}


bool Port::GetOpenStatus() {
	return this->isOpened;
}


QByteArray* Port::GetLastReceivedFrame() {
	return this->receivedFrameBuffer;
}

QByteArray* Port::GetLastSentFrame() {
	return this->sentFrameBuffer;
}

void Port::ClearBuffers() {
	this->sentFrameBuffer = new QByteArray(4, '0');
	this->receivedFrameBuffer = new QByteArray(4, '0');
}

QString Port::GetPortName() {
	return port->portName();
}


int Port::Open(QIODevice::OpenMode openModeValue) {
	QMessageBox* box;

	if (port->open(openModeValue)) {
		box = new QMessageBox(QMessageBox::Icon::Information, QString("Уведомление"), QString("Порт %1 успешно открыт!").arg(port->portName()));
		this->isOpened = true;
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

		box->exec();
	}

	delete box;
	this->port->readAll();
	ClearBuffers();
	return port->error();
}


void Port::SendData(QByteArray data) {
	// Занести отправляемую информацию в буфер, чтобы повторить отправку при возникновении ошибок
	this->sentFrameBuffer = new QByteArray(data);

<<<<<<< HEAD
<<<<<<< HEAD
	/*qDebug() << "Массив до генерации ошибок: ";
	for (auto byte : *data) {
		qDebug() << byte;
	}*/
	GenerateMessageError(data, 1e-05f);
	/*qDebug() << "Массив после генерации ошибок: ";
	for (auto byte : *data) {
		qDebug() << byte;
	}*/

=======
	if (data.length() == 4) { // кодируем только информационные кадры
		GenerateMessageError(data, 1e-05f);
	}
>>>>>>> interface
=======
	if (data.length() == 4) { // кодируем только информационные кадры
		GenerateMessageError(data, 1e-05f);
	}
>>>>>>> interface

	port->write(data);
	bool result = true;

	if (result != true) {
		if (port->error() == QSerialPort::WriteError) {
			qDebug() << QString("Ошибка при записи (порт %1)").arg(port->portName());
			return;
		} else {
			qDebug() << QString("Запись не прошла (%1)").arg(port->error());
		}
	} else {
		qDebug() << QString("Физ. уровень записал данные " + data.toHex()) << port->portName();
	}
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


void Port::GenerateMessageError(QByteArray& data, float errorProbability) {
	for (int i = 0; i < data.length(); i = i + 1) {
		for (int bitNum = 0; bitNum < 8; bitNum = bitNum + 1) {
			if ((static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) < errorProbability) {
				char replaced = (data.at(i) ^ (1 << bitNum));
				data.replace(i, 1, &replaced, 1);
			}
		}
	}
}


void Port::OnDataReceived() {
	QByteArray* readData = nullptr;
	readData = new QByteArray(port->readAll());

	if (port->error() == QSerialPort::ReadError) {
		qDebug() << "Ошибка при чтении (порт %1)" + port->portName();
	} else {
		qDebug() << QString("Физ. уровень прочёл данные: ") + readData->toHex();
	}


	emit NewDataToRead(readData);
	this->receivedFrameBuffer = new QByteArray(readData->toStdString().c_str(), readData->length());
	delete readData;
}


int Port::Close() {
	QMessageBox* box;
	port->close();
	if (port->error() == 0) {
		box = new QMessageBox(QMessageBox::Icon::Information, QString("Уведомление"), QString("Порт %1 успешно закрыт!").arg(port->portName()));
		this->isOpened = false;
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
