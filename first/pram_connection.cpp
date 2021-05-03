#include "pram_connection.h"
#include "ui_pram_connection.h"
#include <QListView>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QString>
#include <QTextEdit>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QIODevice>

Pram_connection::Pram_connection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pram_connection)
{
    ui->setupUi(this);
	this->ports	= QSerialPortInfo::availablePorts();

	/* ДОСТУПНЫЕ ПОРТЫ */
    listView = new QListView(ui->Port_number_comboBox);
    ui->Port_number_comboBox->setView(listView);
	for (auto port : this->ports) {
		// Если запихнуть выражение сразу в addItem, то почему-то программа отказывается работать
		QString option = QString("%1 (%2))").arg(port.portName(), port.description());
		ui->Port_number_comboBox->addItem(option);
	}

	/* СКОРОСТЬ СОЕДИНЕНИЯ */
    listView = new QListView(ui->Bits_in_second_comboBox);
	ui->Bits_in_second_comboBox->setView(listView);
	for (auto rate : QSerialPortInfo::standardBaudRates()) {
		QString option =  QString::number(rate);
		ui->Bits_in_second_comboBox->addItem(option);
	}

	/* КОЛИЧЕСТВО ПАКУЕМЫХ БИТ */
    listView = new QListView(ui->Data_bits_comboBox);
    ui->Data_bits_comboBox->setView(listView);
	// Будем передавать выбранное численное значение в QSerialPort::setDataBits()
	// Выбор варианта не пригодится
	ui->Data_bits_comboBox->addItem(QString::number(8));

	/* КОНТРОЛЬ ЧЁТНОСТИ */
    listView = new QListView(ui->Chetnost_comboBox);
    ui->Chetnost_comboBox->setView(listView);
	// Будем передавать выбранное численное значение в QSerialPort::setParity()
	// Выбор нам не пригодится, так как контроль чётности на канальном уровне
    ui->Chetnost_comboBox->addItem("None");

	/* СТОПОВЫЕ БИТЫ */
    listView = new QListView(ui->Stop_bits_comboBox);
    ui->Stop_bits_comboBox->setView(listView);
	// Будем передавать выбранное численное значение в QSerialPort::setStopBits()
	// Пока не знаю, сколько у нас будет
	for (auto stopBitsOption : {1, 2}) {
		ui->Stop_bits_comboBox->addItem(QString::number(stopBitsOption));
	}

	/* УПРАВЛЕНИЕ ПОТОКОМ */
    listView = new QListView(ui->Upravl_steam_comboBox);
    ui->Upravl_steam_comboBox->setView(listView);
	// Будем передавать выбранное численное значение в QSerialPort::setFlowControl()
	// Пока не знаю, сколько у нас будет
	for (auto flowControlOption : {0, 1, 2}) {
		ui->Upravl_steam_comboBox->addItem(QString::number(flowControlOption));
	}
}

Pram_connection::~Pram_connection()
{
    delete ui;
}

void Pram_connection::on_OK_button_clicked()
{
    //Применить параметры соединения
	QString selected = QString("Порт %1; скорость соединения = %2").arg(this->ports[ui->Port_number_comboBox->currentIndex()].portName(), ui->Bits_in_second_comboBox->currentText());
	QMessageBox::StandardButton reply = QMessageBox::question(this,"Параметры", "Вы уверены что хотите утвердить параметры?\n" + selected, QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes){
        QApplication::quit();
    }
    else {
        qDebug() << "Продолжение работы приложения";
    }
}

void Pram_connection::on_Back_button_clicked()
{
    QWidget::close();
}
