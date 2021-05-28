#include "data_link.h"
#include <QFile>
#include <QDataStream>
#include <QBitArray>
#include <QObject>
#include <QSaveFile>
#include <QMessageBox>
#include <QDebug>
#include <QEventLoop>
#include "mainwindow.h"


DataLink::DataLink(MainWindow *mw) {
	this->port = nullptr;
	this->isConnected = false;
	this->NAK_counter = 0;
	connect(this, &DataLink::DataRead, mw, &MainWindow::OnNewDataRead);
	connect(this, &DataLink::ConnectionEstablished, mw, &MainWindow::OnConnectionEstablished);
}


void DataLink::SetPort(QSerialPortInfo portInfo, int baudRate) {
	if (this->port != nullptr && this->port->GetOpenStatus() == true) {
		ClosePort();
	}
	this->port = new Port(portInfo, baudRate, this);
}


int DataLink::OpenPort() {
	if (this->port == nullptr) {
		QMessageBox msg;
		msg.setText("Попытка открыть незаданный порт!");
		msg.exec();
		return -1;
	} else if (this->port->GetOpenStatus() == true) {
		QMessageBox msg;
		msg.setText("Порт уже открыт!");
		msg.exec();
		return 0;
	} else {
		// Сообщения на тему процесса открытия уже есть внутри метода
		return port->Open(QIODevice::ReadWrite);
	}
}


int DataLink::ClosePort() {
	if (this->port == nullptr) {
		QMessageBox msg;
		msg.setText("Попытка закрыть незаданный порт!");
		msg.exec();
		return -1;
	} else if (this->port->GetOpenStatus() == false) {
		QMessageBox msg;
		msg.setText("Порт уже закрыт!");
		msg.exec();
		return 0;
	} else {
		// Сообщения на тему процесса открытия уже есть внутри метода
		return port->Close();
	}
}


bool DataLink::SendHello() {
	if (this->port == nullptr) {
		QMessageBox msg;
		msg.setText("ОШИБКА! Не задан порт");
		msg.exec();
		return false;
	} else if (port->GetOpenStatus() != true) {
		/* В ДАЛЬНЕЙШЕМ ВЕРНУТЬ ЗДЕСЬ ОШИБКУ (Славе надо будет добавить отдельную кнопку)*/
		/*QMessageBox msg;
		msg.setText("ОШИБКА! Порт закрыт");
		msg.exec();
		return false;*/
		OpenPort();
		return false;
	} else {
		SendControlFrame('U');
	}

	return false;
}


void DataLink::SendFile(QString path) {
	qDebug() << "Отправляем файл " + path;
	QFile file(path);
	if (this->port == nullptr) {
		QMessageBox msg;
		msg.setText("ОШИБКА! Не задан порт");
		msg.exec();
		return;
	} else if (port->GetOpenStatus() != true) {
		QMessageBox msg;
		msg.setText("ОШИБКА! Порт закрыт");
		msg.exec();
		return;
	} else if (isConnected == false) {
		QMessageBox msg;
		msg.setText("ОШИБКА! Соединение не установлено");
		msg.exec();
	} else {
		QByteArray bytesToTransmit;
		int fileSize;

		// 1. Читаем исходный файл
		if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			bytesToTransmit = file.readAll();
			fileSize = bytesToTransmit.size();
		} else {
			qDebug() << "Ошибка при открытии файла для передачи";
			return;
		}

		// 2. Отправляем первичный кадр
		SendSizeFrame(fileSize);
		// Получаем ответ (ACK)
		// Работаем в синхронном режиме, поэтому блокируемся до прихода кадра
		WaitForAnswer();
		if (UnwrapControlFrame(*this->receivedData) == 'A') {
			qDebug() << "В ответ на кадр с размером от приёмной стороны получен ACK...";
		} else {
			qDebug() << "ОШИБКА! В ответ на кадр с размером от приёмной стороны получен не ACK...";
		}

		// 3. Передаём файл
		SendInfoFrames(bytesToTransmit, fileSize);
	}
}


void DataLink::WaitForAnswer() {
	QEventLoop loop;
	connect(this->port, &Port::NewDataToRead,  &loop, &QEventLoop::quit);
	loop.exec();
}


void DataLink::SendControlFrame(char type) {
	port->SendData(WrapControlFrame(type));
}


// составляем управляющие кадры
QByteArray DataLink::WrapControlFrame(char type)
{
	QByteArray pack;
	pack.resize(3);
	if (type == 'A' | type == 'R' | type == 'L' |type == 'U' |type == 'S')
	{
		//установим в стартовый и стоповый байт значения в 0xFF
		pack[0] = 0xFF;
		pack[2] = 0xFF;
		// заполним байт, отведённый под тип кадра
		switch(type)
		{
			case 'A': {
				pack[1] = 0x01;
				qDebug() << "Отправлен ACK";
				break;
			}
			case 'N': {
				pack[1] = 0x02;
				qDebug() << "Отправлен NAK";
				break;
			}
			case 'U': {
				pack[1] = 0x03;
				qDebug() << "Отправлен UPLINK";
				break;
			}
			case 'D': {
				qDebug() << "Отправлен DOWNLINK";
				pack[1] = 0x04;
				break;
			}
			default: {
				qDebug() << "Отправлен неизвестный служебный кадр";
				pack[1] = 0x00;
				break;
			}
		}
	}
	return pack;
}


void DataLink::SendSizeFrame(int size) {
	port->SendData(WrapSizeFrame(size));
}


// составляем кадр с размером файла данных
// он передаётся ПЕРВЫМ после установления соединения
QByteArray DataLink::WrapSizeFrame(int size)
{
	qDebug() << QString("Отправляем кадр с размером файла ({0})").arg(size);
	QByteArray frame;
	// ИЗМЕНИЛ, ПОСКОЛЬКУ ФАЙЛЫ МОГУТ ИМЕТЬ РАЗМЕР БОЛЬШЕ 255
	frame.resize(6);
	frame[0] = 0xFF;
	frame[5] = 0xFF;
	for (int i = 0; i < 4; i = i + 1) {
		frame[i + 1] =  size >> i * 8;
	}
	frame[1] = size;
	return frame;
}


/* функция получает на вход файл в виде массива байтов
разбивает на кусочки по 11 бит, кодирует кодом Хэмминга
и упаковывает в информационные кадры по 2 байта закодированных данных */
void DataLink::SendInfoFrames(QByteArray bytes, int size)
{
	// НЕМНОГО ПЕРЕЛОПАТИЛ, т. к. были IndexOutOfRangeException и сё такое
	int bitsAmount = size * 8,
		divSize = bitsAmount / 11,
		modSize = bitsAmount % 11;
	QBitArray ba = ConvertByteArrToBitArr(bytes);
	QBitArray a;
	QByteArray coded;
	QByteArray packed;
	// сначала обработаем те части массива битов, которые разделились на 11
	for (int i = 0; i < divSize; i = i + 1)
	{
		a = To11Bits(ba, i);
		coded = HammingCode(a);
		packed = WrapInfoFrame(coded);
		port->SendData(packed);
		// Проверяем полученный ответ
		WaitForAnswer();
		if (UnwrapControlFrame(*this->receivedData) == 'A') {
			qDebug() << QString("В ответ на информационный кадр #{0} от приёмной стороны получен ACK...").arg(i);
		} else {
			qDebug() << QString("ОШИБКА! В ответ на информационный кадр #{0} от приёмной стороны получен не ACK...").arg(i);
		}
	}

	// для последних битов последовательности (<11)
	// если они есть
	if (modSize != 0)
	{
		a.resize(11);
		for (int i = bitsAmount - modSize; i < bitsAmount; i++)
		{
		   a[i - (bitsAmount - modSize)] = ba[i];
		}

		// остальные биты заполним нулями
		for (int i = modSize; i < 11; i++) {
			a[i] = 0;
		}

		coded = HammingCode(a);
		packed = WrapInfoFrame(coded);
		port->SendData(packed);

		WaitForAnswer();
		if (UnwrapControlFrame(*this->receivedData) == 'A') {
			qDebug() << QString("В ответ на хвостовой информационный кадр от приёмной стороны получен ACK...");
		} else {
			qDebug() << QString("ОШИБКА! В ответ на хвостовой информационный кадр от приёмной стороны получен не ACK...");
		}
	}
}


// универсальный перевод массива байтов в массив битов
QBitArray DataLink::ConvertByteArrToBitArr(QByteArray bytes)
{
	QBitArray bits;
	bits.resize(bytes.size()*8);
	for (int i = 0; i < bytes.size(); ++i)
	{
		for (int b = 0; b < 8; b++)
			bits.setBit(i * 8 + b, bytes.at(i) & (1 << b));
	}
	return bits;
}


// функция выделяет по 11 бит из всего байтового массива
QBitArray DataLink::To11Bits(QBitArray ba, int i)
{
	int start_point = i * 11;
	QBitArray new_ba;
	new_ba.resize(11);
	int k = 0;
	for (int j=start_point;j<start_point+11;j++)
	{
		new_ba.setBit(k,ba[j]);
		k++;
	}
	return new_ba;
}


// кодирование кодом Хэмминга
QByteArray DataLink::HammingCode(QBitArray arr)
{
	QBitArray code;
	// вводим дополнительный нулевой бит слева, чтобы превратить 15 бит в 2 байта
	code.resize(16);
	code.setBit(0, false);
	// заполним информационные разряды
	for (int i = 1; i < 8; i++) {
		code.setBit(i, arr[i-1]);
	}
	code.setBit(9, arr[7]);
	code.setBit(10, arr[8]);
	code.setBit(11, arr[9]);
	code.setBit(13, arr[10]);
	// заполним проверочные разряды
	code.setBit(8, code[7] xor code[6] xor code[5] xor code[4] xor code[3] xor code[2] xor code[1]);
	code.setBit(12, code[11] xor code[10] xor code[9] xor code[4] xor code[3] xor code[2] xor code[1]);
	code.setBit(14, code[13] xor code[10] xor code[9] xor code[6] xor code[5] xor code[2] xor code[1]);
	code.setBit(15, code[13] xor code[11] xor code[9] xor code[7] xor code[5] xor code[3] xor code[1]);

	// сделаем из этого два байта
	return ConvertBitArrToByteArr(code);
}



// упаковка информационных кадров
QByteArray DataLink::WrapInfoFrame(QByteArray info)
{
	QByteArray frame;
	frame.resize(4);
	//установим в стартовый и стоповый байт значения в 0xFF
	frame[0] = 0xFF;
	frame[3] = 0xFF;
	frame[1] = info[0];
	frame[2] = info[1];
	return frame;
}


void DataLink::OnNewDataToRead(QByteArray *data) {
	this->receivedData = new QByteArray(*data);
	if (receivedData->length() == 3) { // Служебные кадры
		char frameType = UnwrapControlFrame(*data),
			 lastSentFrameType = UnwrapControlFrame(*port->GetLastSentFrame()),
			 lastReceivedFrameType = UnwrapControlFrame(*port->GetLastReceivedFrame());
		if (frameType == 'A') { // При установке соединения или получении инфокадра
			qDebug() << "Принят ACK";
			if (lastSentFrameType == 'A') { // Обменялись UPLINK и ACK, соединение установлено
				this->isConnected = true;
				emit ConnectionEstablished();
			} else if (lastSentFrameType == 'U') { // Обменялись UPLINK и получили ACK, осталось вернуть его
				SendControlFrame('A');
				this->isConnected = true;
				emit ConnectionEstablished();
			} else { // Обменялись UPLINK, надо обменяться ACK
				SendControlFrame('A');
			}
		} else if (frameType == 'N') { // При получении инфокадра с ошибкой
			qDebug() << "Принят NAK";

		} else if (frameType == 'U') { // При установке соединения
			qDebug() << "Принят UPLINK";
			if (lastSentFrameType == 'U') { // Уже обменялись UPLINK, пора переходить к ACK
				SendControlFrame('A');
			} else { // UPLINK пока отправлен только в одну сторону, возвращаем его
				// УБРАЛ АВТОМАТИЧЕСКУЮ ПОСЫЛКУ UPLINK, ЧТОБЫ УСТАНОВИТЬ СОЕДИНЕНИЕ ТОЛЬКО ПОСЛЕ НАЖАТИЙ КНОПКИ С ОБЕИХ СТОРОН
				//SendControlFrame('U');
			}

		} else if (frameType == 'D') { // При разрыве соединения
			qDebug() << "Принят DOWNLINK";
		} else { // 404
			qDebug() << "Принят неизвестный служебный кадр";
		}
	} else if (receivedData->length() == 4) { // Информационные кадры
		qDebug() << "Принят инфокадр" << receivedData->at(1) << receivedData->at(2);
		UnwrapInfoFrame(*receivedData);
		SendControlFrame('A');
		this->bitsRead += 11;
		if (this->bitsRead >= this->bytesToRead * 8) {
			ConvertReceivedToFile("D:/read.txt");
		}
	} else { // if len == 6 (кадр размера)
		qDebug() << "Принят кадр размера";
		int size = UnwrapSizeFrame(*receivedData);
		this->receivedBits = new QList<bool>();
		this->bitsRead = 0;
		this->bytesToRead = size;
		SendControlFrame('A');
	}

}


// распаковка служебных кадров
char DataLink::UnwrapControlFrame(QByteArray controlFrame)
{
	if (controlFrame == nullptr || controlFrame.length() == 0) return 0;

	int code = controlFrame[1];
	char frameType;
	switch (code) {
		case 1: {
			frameType = 'A';
			break;
		}
		case 2: {
			frameType = 'N';
			break;
		}
		case 3: {
			frameType = 'U';
			break;
		}
		case 4: {
			frameType = 'D';
			break;
		}
		default: {
			frameType = 0;
			break;
		}
	}
	//qDebug() << QString("Распакованный служебный кадр: ") << frameType;
	return frameType;
}


int DataLink::UnwrapSizeFrame(QByteArray sizeFrame) {
	int result = 0;
	for (int i = 0; i < 4; i = i + 1) {
		result = result | (sizeFrame[i + 1] << i * 8);
	}
	qDebug() << "Приняли размер файла: " << result;
	return result;
}


// распаковываем ПО ОДНОМУ информационному кадру и запихиваем биты в список
// т.е. где-то нужно вызывать это в цикле
void DataLink::UnwrapInfoFrame(QByteArray frame)
{
	QByteArray bytes;
	bytes.resize(2);
	// оставляем только информационные байты
	bytes[0] = frame[1];
	bytes[1] = frame[2];
	QBitArray *bits;
	// представляем в виде битов
	bits = new QBitArray(ConvertByteArrToBitArr(bytes));
	// декодируем
	bits = HammingDecode(*bits);
	// При наличии ошибки в буфер ничего не пишем
	if (bits == nullptr) {
		// ДОБАВИТЬ СИГНАЛ ОБ ОШИБКЕ ДЛЯ ПОВТОРНОЙ ПЕРЕДАЧИ
		return;
	}

	// записываем в буфер
	for (int i = 0; i<11;i++) {
		bool temp = bits->at(i);
		receivedBits->append(temp);
	}

	delete bits;
}


// декодирование на стороне-приёмнике
QBitArray* DataLink::HammingDecode(QBitArray code)
{
	bool h0, h1, h2, h3;
	h0 = code[15] xor code[13] xor code[11] xor code[9] xor code[7] xor code[5] xor code[3] xor code[1];
	h1 = code[14] xor code[13] xor code[10] xor code[9] xor code[6] xor code[5] xor code[2] xor code[1];
	h2 = code[12] xor code[11] xor code[10] xor code[9] xor code[4] xor code[3] xor code[2] xor code[1];
	h3 = code[8] xor code[7] xor code[6] xor code[5] xor code[4] xor code[3] xor code[2] xor code[1];
	// вычислим синдром ошибки
	int syndrome = h3 * 8 + h2 * 4 + h1 * 2 + h0 * 1;

	if (syndrome == 0)
	{
		qDebug() << "Кадр декодирован, ошибок нет. ";
		// ошибки нет, пакет дошёл
		// отправляем квитанцию Success
		WrapControlFrame('S');
		QBitArray *decoded = new QBitArray();
		decoded->resize(11);
		// оставим только проверочные разряды
		for (int i = 0; i < 7; i++)
		{
		   decoded->setBit(i, code[i+1]);
		}
		decoded->setBit(7, code[9]);
		decoded->setBit(8, code[10]);
		decoded->setBit(9, code[11]);
		decoded->setBit(10, code[13]);

		/*for (int i = 0; i < decoded->count(); i = i + 1) {
			qDebug() << decoded->at(i);
		}*/
		return decoded;
	} else {
		qDebug() << "Кадр декодирован с оишбкой!!!";

		// ошибка есть, отправляем квитанцию NAK
		// увеличиваем глобальный счётчик NAK на 1
		WrapControlFrame('R');
		NAK_counter += 1;
		if (NAK_counter == 3) {
			QMessageBox msgbx;
			msgbx.setText("При передаче данных возникли ошибки!");
			msgbx.exec();
		}

		return nullptr;
	}
}


// преобразование массива бит в бинарный файл на приёмной стороне
// !!передать путь в качестве параметра
void DataLink::ConvertReceivedToFile(QString path)
{
	QByteArray* receivedFile = new QByteArray();
	QBitArray ba;
	QByteArray byte;
	for (int i=0;i<this->bytesToRead;i++)
	{
		 ba.clear();
		 ba.resize(8);
		 for (int j=0;j<8;j++)
		 {
			 ba[j] = this->receivedBits->at(0);
			 this->receivedBits->pop_front();
		 }
		 byte = ConvertBitArrToByteArr(ba);
		 qDebug() << "Собрали байт " << byte.toStdString().c_str();
		 receivedFile->append(byte);
	}
	QSaveFile file(path);
	file.open(QIODevice::WriteOnly);
	file.write(*receivedFile);
	file.commit();
}


// универсальный перевод массива битов в массив байтов
QByteArray DataLink::ConvertBitArrToByteArr(QBitArray bits)
{
	QByteArray bytes;
	bytes.resize(bits.count()/8);
	bytes.fill(0);
	for(int b=0; b<bits.count(); ++b)
		bytes[b/8] = ( bytes.at(b/8) | ((bits[b]?1:0)<<(b%8)));
	return bytes;
}
