#ifndef DATA_LINK_H
#define DATA_LINK_H
#include <QFile>
#include <QDataStream>
#include <QBitArray>
#include <QObject>
#include <QSaveFile>
#include <port.h>

class DataLink
{
public:
	DataLink();
	// Инициализация с чтением файла
	DataLink(QFile file);

	void SetPort(QSerialPortInfo portInfo, int baudRate);
	// Оболочка для передачи данных
	void Send_Pipeline(QFile file);
	// Оболочка для приёма данных
	void Receive_Pipeline(QString path);
private:
	Port* port;

	QByteArray ReceivedFile;
	//QByteArray BytesToTransmit;
	//QList<bool> bitList;
	//int size;
	int NAK_counter;

	// QByteArray -> QBitArray
	QBitArray ConvertByteArrToBitArr(QByteArray bytes);
	// QBitArray -> QByteArray
	QByteArray ConvertBitArrToByteArr(QBitArray bits);
	// Вычленение из данных по 11 бит (для кодирования по Хэммингу)
	QBitArray To11Bits(QBitArray ba, int i);

	// Формирование информационного кадра из передаваемых данных
	QByteArray WrapInfoFrame(QByteArray info);
	// Формирование управляющего кадра на основе получаемого служебного символа
	QByteArray WrapControlFrame(char type);
	// Формирование первичного кадра с указанием длины передаваемого файла
	QByteArray WrapSizeFrame(int size);
	// Отправка файла
	void SendInfoPackets(QByteArray	bytes, int size);

	// Извлечение данных из информационных кадров
	void UnwrapInfoFrame(QByteArray frame, QList<bool> &receivedBits);
	// Формирование двоичного файла из полученных данных с указанием пути назначения
	void ConvertReceivedToFile(QString path, int size, QList<bool> &receivedBits);
	// Получение файла
	void ReceiveInfoPackets(int sizeToReceive, QString path);

    QByteArray HammingCode(QBitArray arr);
    QBitArray HammingDecode(QBitArray code);
};

#endif // DATA_LINK_H
