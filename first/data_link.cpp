#include "data_link.h"
#include <QFile>
#include <QDataStream>
#include <QBitArray>
#include <QObject>
#include <QSaveFile>
#include <QMessageBox>
#include <QDebug>

DataLink::DataLink()
{
}

// чтение файла и представление его в виде массива байтов (конструктор)
DataLink::DataLink(QFile file)
{
	/*if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        BytesToTransmit = file.readAll();
    NAK_counter = 0;
	size = BytesToTransmit.size();*/
}


void DataLink::SetPort(QSerialPortInfo portInfo, int baudRate) {
	this->port = new Port(portInfo, baudRate);
}

void DataLink::Send_Pipeline(QFile file) {
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

	// 2. Открываем порт
	port->Open(QIODevice::WriteOnly);

	// 3. Устанавливаем соединение
	port->SendData(WrapControlFrame('U'));
	// Получаем ответ (ACK)
	// ... НЕ ХВАТАЕТ МЕТОДА UnwrapControlFrame();

	// 4. Отправка первичного кадра
	port->SendData(WrapSizeFrame(fileSize));
	// Получаем ответ (ACK)
	// ...

	// 5. Передаём файл
	SendInfoPackets(bytesToTransmit, fileSize);

	// 6. Закрываем порт
	port->Close();

}

void DataLink::Receive_Pipeline(QString path) {
	// 1. Открываем порт
	port->Open(QIODevice::ReadOnly);

	QByteArray *received;
	// 2. Получаем запрос на соединение
	received = new QByteArray(*port->ReceiveData(3)); // Надо ещё проверить полученное (упомянутого выше UnwrapControlFrame() хватит)
	// Возвращаем ACK
	port->SendData(WrapControlFrame('A'));

	// 3. Получаем первичный кадр
	received = new QByteArray(*port->ReceiveData(3)); // ПРАВИЛЬНЫЕ ЛИ ДЛИНЫ ЗДЕСЬ И ВЫШЕ?
	// Записываем размер файла
	int fileSize = received->length();
	// Возвращаем ACK
	port->SendData(WrapControlFrame('A'));

	// 4. Получаем файл
	ReceiveInfoPackets(fileSize, path);

	// 5. Закрываем порт
	port->Close();
}

// универсальный перевод массива байтов в массив битов
QBitArray DataLink::ConvertByteArrToBitArr(QByteArray bytes)
{
    QBitArray bits;
    bits.resize(bytes.size()*8);
    for (int i = 0; i < bits.size(); ++i)
    {
        for (int b = 0; b < 8; b++)
            bits.setBit(i * 8 + b, bytes.at(i) & (1 << (7 - b)));
    }
    return bits;
}

// универсальный перевод массива битов в массив байтов
QByteArray DataLink::ConvertBitArrToByteArr(QBitArray bits)
{
    QByteArray bytes;
    bytes.resize(bits.count()/8+1);
    bytes.fill(0);
    for(int b=0; b<bits.count(); ++b)
        bytes[b/8] = ( bytes.at(b/8) | ((bits[b]?1:0)<<(b%8)));
    return bytes;
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
            case 'A': pack[1] = 0x00;
                      break;
            case 'R': pack[1] = 0x01;
                      break;
            case 'L': pack[1] = 0x02;
                      break;
            case 'U': pack[1] = 0x03;
                      break;
            case 'S': pack[1] = 0x04;
                  break;
        }
    }
    return pack;
}


// составляем кадр с размером файла данных
// он передаётся ПЕРВЫМ после установления соединения
QByteArray DataLink::WrapSizeFrame(int size)
{
    QByteArray frame;
    frame.resize(3);
    frame[0] = 0xFF;
    frame[1] = size;
    frame[2] = 0xFF;

    return frame;
}


/* функция получает на вход файл в виде массива байтов
разбивает на кусочки по 11 бит, кодирует кодом Хэмминга
и упаковывает в информационные кадры по 2 байта закодированных данных */
void DataLink::SendInfoPackets(QByteArray bytes, int size)
{


	QBitArray ba = ConvertByteArrToBitArr(bytes);
	QBitArray a;
	QByteArray coded;
	QByteArray packed;
	// сначала обработаем те части массива битов, которые разделились на 11
	for (int i=0; i< size/11 + 1; i+=11)
	{
		a = To11Bits(ba, i);
		coded = HammingCode(a);
		packed = WrapInfoFrame(coded);
		port->SendData(packed);
	}

	// для последних битов последовательности (<11)
	// если они есть
	if (size % 11 != 0)
	{
		int res = size % 11;
		QBitArray resid;
		resid.resize(11);
		int j=0;
		for (int i=size-res;i<size;i++)
		{
		   resid[j] = ba[i];
		   j++;
		}
		// остальные биты заполним нулями
		for (int i=res;i<12;i++)
			resid[i] = 0;
		QBitArray coded_resid;
		coded_resid.resize(16);
		coded_resid[0] = 0;
		j = 0;
		for (int i=1;i<12;i++){
			if (i != 8)
				coded_resid[i] = resid[j];
			j++;
		}
		// заполним проверочные разряды
		coded_resid.setBit(8, coded_resid[6] xor coded_resid[5] xor coded_resid[4] xor coded_resid[3] xor coded_resid[2] xor coded_resid[1] xor coded_resid[0]);
		coded_resid.setBit(12, coded_resid[10] xor coded_resid[9] xor coded_resid[8] xor coded_resid[3] xor coded_resid[2] xor coded_resid[1] xor coded_resid[0]);
		coded_resid.setBit(14, coded_resid[12] xor coded_resid[9] xor coded_resid[8] xor coded_resid[5] xor coded_resid[4] xor coded_resid[1] xor coded_resid[0]);
		coded_resid.setBit(15, coded_resid[12] xor coded_resid[10] xor coded_resid[8] xor coded_resid[6] xor coded_resid[4] xor coded_resid[2] xor coded_resid[0]);
		QByteArray bytes = ConvertBitArrToByteArr(coded_resid);
		QByteArray packed_resid = WrapInfoFrame(bytes);
		port->SendData(packed_resid);
	}
}


// функция выделяет по 11 бит из всего байтового массива
QBitArray DataLink::To11Bits(QBitArray ba, int i)
{
	int start_point = i * 3;
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


void DataLink::ReceiveInfoPackets(int sizeToReceive, QString path) {
	// ЗДЕСЬ ЕСТЬ ТОЛЬКО ЗАГОТОВКА, ПОСМОТРИ И МОЖЕТ ЧТО ДОДЕЛАЙ
	int infoPacketSize; // = 4?
	int dataSize = 2;

	QList<bool> *receivedBits = new QList<bool>();

	for (int i = 0; i < sizeToReceive; i = i + dataSize) {
		QByteArray frame = *port->ReceiveData(infoPacketSize);
		UnwrapInfoFrame(frame, *receivedBits);
	}

	ConvertReceivedToFile(path, sizeToReceive, *receivedBits);

	delete receivedBits;
}


// распаковываем ПО ОДНОМУ информационному кадру и запихиваем биты в список
// т.е. где-то нужно вызывать это в цикле
void DataLink::UnwrapInfoFrame(QByteArray frame, QList<bool> &receivedBits)
{
    QByteArray bytes;
    bytes.resize(2);
    // оставляем только информационные байты
    bytes[0] = frame[1];
    bytes[1] = frame[2];
    QBitArray bits, decoded_bits;
    // представляем в виде битов
	bits = ConvertByteArrToBitArr(bytes);
    // декодируем
    decoded_bits = HammingDecode(bits);
	// записываем в буфер
	for (int i = 0; i<11;i++)
		receivedBits.append(decoded_bits[i]);
}


// преобразование массива бит в бинарный файл на приёмной стороне
// !!передать путь в качестве параметра
void DataLink::ConvertReceivedToFile(QString path, int size, QList<bool> &receivedBits)
{
    QBitArray ba;
    QByteArray byte;
    for (int i=0;i<size;i++)
    {
         ba.clear();
         ba.resize(8);
         for (int j=0;j<8;j++)
         {
			 ba[j] = receivedBits.at(0);
			 receivedBits.pop_front();
         }
		 byte = ConvertBitArrToByteArr(ba);
         ReceivedFile.append(byte);
    }
    QSaveFile file(path);
    file.open(QIODevice::WriteOnly);
    file.write(ReceivedFile);
    file.commit();
}


// кодирование кодом Хэмминга
QByteArray DataLink::HammingCode(QBitArray arr)
{
	QBitArray code;
	// вводим дополнительный нулевой бит слева, чтобы превратить 15 бит в 2 байта
	code.resize(16);
	code.setBit(0, false);
	// заполним информационные разряды
	for (int i = 1; i < 8; i++)
		code.setBit(i, arr[i]);
	code.setBit(9, arr[7]);
	code.setBit(10, arr[8]);
	code.setBit(11, arr[9]);
	code.setBit(13, arr[10]);
	// заполним проверочные разряды
	code.setBit(8, code[6] xor code[5] xor code[4] xor code[3] xor code[2] xor code[1] xor code[0]);
	code.setBit(12, code[10] xor code[9] xor code[8] xor code[3] xor code[2] xor code[1] xor code[0]);
	code.setBit(14, code[12] xor code[9] xor code[8] xor code[5] xor code[4] xor code[1] xor code[0]);
	code.setBit(15, code[12] xor code[10] xor code[8] xor code[6] xor code[4] xor code[2] xor code[0]);

	// сделаем из этого два байта
	return ConvertBitArrToByteArr(code);
}


// декодирование на стороне-приёмнике
QBitArray DataLink::HammingDecode(QBitArray code)
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
		// ошибки нет, пакет дошёл
		// отправляем квитанцию Success
		WrapControlFrame('S');
		QBitArray decoded;
		decoded.resize(11);
		// оставим только проверочные разряды
		for (int i = 0; i < 7; i++)
		{
		   decoded.setBit(i, code[i+1]);
		}
		decoded.setBit(7, code[9]);
		decoded.setBit(8, code[10]);
		decoded.setBit(9, code[11]);
		decoded.setBit(10, code[13]);

		return decoded;
	}
	else {
		// ошибка есть, отправляем квитанцию NAK
		// увеличиваем глобальный счётчик NAK на 1
		WrapControlFrame('N');
		NAK_counter += 1;
		if (NAK_counter == 3)
			{
			QMessageBox msgbx;
			msgbx.setText("При передаче данных возникли ошибки!");
			msgbx.exec();
			}
	}
}
