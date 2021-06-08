#include "data_link.h"
#include <QTime>
#include <QFile>
#include <QDataStream>
#include <QBitArray>
#include <QObject>
#include <QSaveFile>
#include <QMessageBox>
#include <QDebug>
#include <QEventLoop>
#include <QtGlobal>
#include "mainwindow.h"


DataLink::DataLink(MainWindow *mw, QTableWidget* table) {
	this->mw = mw;
	this->debugTable = table;
	this->port = nullptr;
	this->isConnected = false;
	this->NAK_counter = 0;
	// Связываем с прикладным уровнем (с физическим будет связан при задании порта)
	connect(this, &DataLink::ConnectionStatusChanged, mw, &MainWindow::OnConnectionStatusChanged);
	connect(this, &DataLink::PortStatusChanged, mw, &MainWindow::OnPortStatusChanged);
	connect(this, &DataLink::FileSendRequested, mw, &MainWindow::OnFileSendRequestReceived);
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
		emit PortStatusChanged(true);
		// Сообщения на тему процесса открытия уже есть внутри метода
		InsertNewDebugMessage("Порт открыт");
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
		if (this->isConnected == true) {
			SendGoodbye();
			WaitForAnswer();
			WaitForAnswer();
		}

		emit PortStatusChanged(false);
		// Сообщения на тему процесса открытия уже есть внутри метода
		InsertNewDebugMessage("Порт закрыт");
		return port->Close();
	}
}


bool DataLink::SendHello() {
	if (this->port == nullptr) {
		QMessageBox msg;
		msg.setText("ОШИБКА! Не задан порт");
		msg.exec();
		return false;
	}

	if (port->GetOpenStatus() != true) {
		//OpenPort();
		return false;
	} else {
		port->ClearBuffers();
		SendControlFrame('U');
		return true;
	}
}


bool DataLink::GetConnectionStatus() {
	return this->isConnected;
}


bool DataLink::GetPortStatus() {
	if (this->port == nullptr) return false;

	return this->port->GetOpenStatus();
}


bool DataLink::SendGoodbye() {
	port->ClearBuffers();
	if (port->GetOpenStatus() == true) {
		SendControlFrame('D');
		return true;
	} else {
		QMessageBox msg;
		msg.setText("ОШИБКА! Порт уже был закрыт");
		msg.exec();
		return false;
	}
}


void DataLink::SendFile(QString path) {
	port->ClearBuffers();

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
		InsertNewDebugMessage("Отправляем файл " + path);
		QFile file(path);
		QByteArray bytesToTransmit;
		int fileSize;

		// 1. Читаем исходный файл
		if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			bytesToTransmit = file.readAll();
			fileSize = bytesToTransmit.size();
		} else {
			InsertNewDebugMessage("Ошибка при открытии файла для передачи");
			return;
		}
		// 2. Готовимся к передаче файла
		//SendInfoFrames(bytesToTransmit, fileSize);
		FormInfoFrames(bytesToTransmit);

		// 3. Отправляем первичный кадр
		SendSizeFrame(fileSize);
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
	//установим в стартовый и стоповый байт значения в 0xFF
	pack[0] = 0xFF;
	pack[2] = 0xFF;
	// заполним байт, отведённый под тип кадра
	switch(type)
	{
		case 'A': {
			pack[1] = 0x01;
			//InsertNewDebugMessage("Отправлен ACK");
			break;
		}
		case 'N': {
			pack[1] = 0x02;
			InsertNewDebugMessage("Отправлен NAK");
			break;
		}
		case 'U': {
			pack[1] = 0x03;
			InsertNewDebugMessage("Отправлен UPLINK");
			break;
		}
		case 'D': {
			InsertNewDebugMessage("Отправлен DOWNLINK");
			pack[1] = 0x04;
			break;
		}
		default: {
			InsertNewDebugMessage("Отправлен неизвестный служебный кадр");
			pack[1] = 0x00;
			break;
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
	InsertNewDebugMessage(QString("Отправляем кадр с размером файла (%1 байт)").arg(size));
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
/*void DataLink::SendInfoFrames(QByteArray bytes, int size)
{
	QList<QByteArray> *formedPackets = FormInfoFrames(bytes);

	char received;
	for (int i = 0; i < formedPackets->size(); i = i + 1)
	{
		received = 0;
		// Повторяем до тех пор, пока не придёт подтверждение
		while (received != 'A') {
			InsertNewDebugMessage("Отправляем информационный кадр #" + QString::number(i));
			port->SendData(formedPackets->at(i));

			WaitForAnswer();
			received = UnwrapControlFrame(*this->receivedData);
			if (received == 'N') {
				if (NAK_counter < 3) {
					InsertNewDebugMessage("Информационный кадр содержит ошибку, отправлен запрос повторной отправки! NAK_Counter = " + QString::number(NAK_counter));
				} else {
					InsertNewDebugMessage("Слишком много ошибок (NAK_counter >= 3)!");
					SendGoodbye();
					// Продолжать передачу смысла нет, выходим
					return;
				}
			}
		}
	}
}*/


QList<QByteArray>* DataLink::FormInfoFrames(QByteArray source) {
	QList<QByteArray> *result = new QList<QByteArray>();

	QBitArray ba = ConvertByteArrToBitArr(source);
	int bitsAmount = ba.size(),
		divSize = bitsAmount / 11,
		modSize = bitsAmount % 11;

	// сначала обработаем те части массива битов, которые разделились на 11
	for (int i = 0; i < divSize; i = i + 1)
	{
		result->insert(i, WrapInfoFrame(HammingCode(To11Bits(ba, i))));
	}

	// для последних битов последовательности (<11)
	// если они есть
	if (modSize != 0)
	{
		QBitArray a;
		a.resize(11);
		for (int i = bitsAmount - modSize; i < bitsAmount; i++)
		{
		   a[i - (bitsAmount - modSize)] = ba[i];
		}

		// остальные биты заполним нулями
		for (int i = modSize; i < 11; i++) {
			a[i] = 0;
		}

		result->insert(divSize, WrapInfoFrame(HammingCode(a)));
	}

	this->infoFramesToSend = result;
	return result;
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


void DataLink::SendAnotherInfoFrame() {
	// Данный метод вызывается после получения ACK в ответ на инфокадр, а у нас ACK приходит в том числе после хвостового кадра
	if (infoFramesToSend->size() == 0) {
		InsertNewDebugMessage("Отправка файла успешно завершена");
		return;
	}

	//InsertNewDebugMessage("Отправляем информационный кадр");
	port->SendData(this->infoFramesToSend->at(0));
	infoFramesToSend->pop_front();
}


void DataLink::OnNewDataToRead(QByteArray *data) {
	this->receivedData = new QByteArray(*data);
	if (receivedData->length() == 3) { // Служебные кадры
		char frameType = UnwrapControlFrame(*data),
			 lastSentFrameType = UnwrapControlFrame(*port->GetLastSentFrame()),
			 lastReceivedFrameType = UnwrapControlFrame(*port->GetLastReceivedFrame());
		if (frameType == 'A') { // При установке соединения или получении инфокадра
			//InsertNewDebugMessage("Принят ACK");

			if (lastSentFrameType == 'A' && (lastReceivedFrameType == 'U' || lastReceivedFrameType == 'D')) { // Обменялись UPLINK/DOWNLINK и ACK, соединение установлено
				isConnected = !isConnected;
				emit ConnectionStatusChanged(isConnected);
			} else if (lastSentFrameType == 'U') { // Обменялись UPLINK и получили ACK, осталось вернуть его
				SendControlFrame('A');
				isConnected = true;
				emit ConnectionStatusChanged(true);
			} else if (lastSentFrameType == 'D') { // Аналогично для DOWNLINK
				SendControlFrame('A');
				isConnected = false;
				emit ConnectionStatusChanged(false);
				//ClosePort();
			} else if (lastSentFrameType == 0) { // Обменялись UPLINK, надо обменяться ACK
				SendControlFrame('A');
			} else if (lastSentFrameType == 'S') { // Получили разрешение в ответ на кадр размера
				InsertNewDebugMessage("Получено разрешение на передачу файла");
				SendAnotherInfoFrame();
			} else if (lastSentFrameType == -1) { // Получили ответ на успешную передачу информационного кадра
				SendAnotherInfoFrame();
			}
		} else if (frameType == 'N') { // При получении инфокадра с ошибкой или отмене передачи файла
			InsertNewDebugMessage("Принят NAK");
			NAK_counter += 1;

			if (lastSentFrameType == 'S') {
				InsertNewDebugMessage("Отказано в передаче файла");
				NAK_counter = 0;
				port->ClearBuffers();
			} else if (lastSentFrameType == -1) {
				if (NAK_counter < 3) {
					InsertNewDebugMessage("Ошибка в информационном кадре! NAK_Counter = " + QString::number(NAK_counter));
					port->ResendLastDataPiece();
				} else {
					InsertNewDebugMessage("Слишком много ошибок (NAK_counter >= 3)!");
					SendGoodbye();
					emit ExchangeAborted();
					// Продолжать передачу смысла нет, выходим
					return;
				}
				// Сама передача будет в другом методе (SendInfoFrames)

			}

		} else if (frameType == 'U') { // При установке соединения
			InsertNewDebugMessage("Принят UPLINK");

			if (lastSentFrameType == 'U') { // Уже обменялись UPLINK, пора переходить к ACK
				SendControlFrame('A');
			} else { // UPLINK пока отправлен только в одну сторону, возвращаем его
				// УБРАЛ АВТОМАТИЧЕСКУЮ ПОСЫЛКУ UPLINK, ЧТОБЫ УСТАНОВИТЬ СОЕДИНЕНИЕ ТОЛЬКО ПОСЛЕ НАЖАТИЙ КНОПКИ С ОБЕИХ СТОРОН
				//SendControlFrame('U');
			}

		} else if (frameType == 'D') { // При разрыве соединения
			// Обнуляем счётчик ошибок, т. к. при попытке нескольких передач нельзя будет ошибиться ни разу
			NAK_counter = 0;

			InsertNewDebugMessage("Принят DOWNLINK");

			if (lastSentFrameType == 'N') { // DOWNLINK пришёл из-за ошибок передачи. Передача остановлена, а окно приёма закрыто
				emit ExchangeAborted();
				SendControlFrame('D');
			} else if (lastSentFrameType == 'D') { // Уже обменялись DOWNLINK, пора переходить к ACK
				SendControlFrame('A');
			} else { // DOWNLINK пока отправлен только в одну сторону, возвращаем его
				SendControlFrame('D');
			}
		} else { // 404
			// Системное сообщение формируется внутри UnwrapControlFrame
		}
	} else if (receivedData->length() == 4) { // Информационные кадры
		//InsertNewDebugMessage("Принят инфокадр");

		if (UnwrapInfoFrame(*receivedData) == true) {
			SendControlFrame('A');
		} else {
			if (NAK_counter < 3) {
				SendControlFrame('N');
			} else {
				SendGoodbye();
			}
			return;
		}

		this->bitsRead += 11;
		emit NewInfoFrameReceived(qBound(0.f, static_cast<float>(bitsRead) / (bytesToRead * 8), 1.f));
		qDebug() << static_cast<float>(bitsRead) / (bytesToRead * 8);
		if (this->bitsRead >= this->bytesToRead * 8) {
			// УБРАЛ АВТОМАТИЧЕСКУЮ КОНВЕРТАЦИЮ ПОЛУЧЕННОГО В ФАЙЛ, ПОСКОЛЬКУ ЭТО ДЕЛАЕТСЯ ТЕПЕРЬ ПОСЛЕ НАЖАТИЯ КНОПКИ
			//ConvertReceivedToFile("D:/read.txt");
			//port->ClearBuffers();
		}
	} else { // Кадр размера (len == 6)
		InsertNewDebugMessage("Принят кадр размера");

		port->ClearBuffers();
		int size = UnwrapSizeFrame(*receivedData);
		this->receivedBits = new QList<bool>();
		this->bitsRead = 0;
		this->bytesToRead = size;

		if (mw->OnFileSendRequestReceived(size) == false) {
			port->ClearBuffers();
			SendControlFrame('N');
		} else {
			// Не отправляем пакет сразу, т. к. нужно дождаться нажатия кнопки в другом окне
			//SendControlFrame('A');
		}
	}
}


void DataLink::OnReceiveAccepted() {
	SendControlFrame('A');
}


void DataLink::OnReceiveAborted() {
	port->ClearBuffers();
	SendControlFrame('N');
}


void DataLink::OnSaveFileButtonClicked(QString path) {
	ConvertReceivedToFile(path);
	port->ClearBuffers();
}


// распаковка служебных кадров
char DataLink::UnwrapControlFrame(QByteArray controlFrame)
{
	if (controlFrame == nullptr || controlFrame.length() == 0) return 0;
	if (controlFrame.length() == 4) {
		return -1;
	}
	if (controlFrame.length() == 6) {
		return 'S';
	}

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

	return frameType;
}


int DataLink::UnwrapSizeFrame(QByteArray sizeFrame) {
	int result = 0;
	for (int i = 0; i < 4; i = i + 1) {
		// Вдвигаем первый значащий байт кадра в левый октант и так далее
		// Побитовое ИЛИ - чтобы все четыре по очереди вносимых байта подружились и составили БАААЛЬШОЕ число
		result = result | (sizeFrame[i + 1] << i * 8);
	}
	InsertNewDebugMessage("Приняли размер файла: " + QString::number(result));
	return result;
}


// распаковываем ПО ОДНОМУ информационному кадру и запихиваем биты в список
// т.е. где-то нужно вызывать это в цикле
bool DataLink::UnwrapInfoFrame(QByteArray frame)
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
		return false;
	}

	// записываем в буфер
	for (int i = 0; i<11;i++) {
		bool temp = bits->at(i);
		receivedBits->append(temp);
	}

	delete bits;
	return true;
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
		//InsertNewDebugMessage("Кадр декодирован, ошибок нет. ");
		// ошибки нет, пакет дошёл
		//SendControlFrame('A');
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
		return decoded;
	} else {
		/*NAK_counter += 1;
		if (NAK_counter < 3) {
			InsertNewDebugMessage("Информационный кадр содержит ошибку, отправлен запрос повторной отправки! NAK_Counter = " + QString::number(NAK_counter));
		} else {
			InsertNewDebugMessage("Слишком много ошибок (NAK_counter >= 3)!");
			emit ExchangeAborted();
		}*/
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
			ba[j] = this->receivedBits->at(i * 8 + j);
		}
		byte = ConvertBitArrToByteArr(ba);
		receivedFile->append(byte);

		InsertNewDebugMessage(QString("Собрали байт " + byte));

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


void DataLink::InsertNewDebugMessage(QString message) {
	if (debugTable->rowCount() > 0) { // Изначально виджет создаётся с одной пустой строкой
		this->debugTable->insertRow(debugTable->rowCount());
	}

	QTableWidgetItem *mes = new QTableWidgetItem(message),
					 *systemTime = new QTableWidgetItem(QTime::currentTime().toString("hh:mm:ss.zzz"));

	debugTable->setItem(debugTable->rowCount() - 1, 0, systemTime);
	debugTable->setItem(debugTable->rowCount() - 1, 1, mes);

	// Все равно оставил, так как иногда удобнее смотреть в IDE
	qDebug() << message;
}
