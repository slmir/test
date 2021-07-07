#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "recieve_file_mode.h"
#include "about_1.h"
#include "pram_connection.h"
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QString>
#include <QTextEdit>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDateTime>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	this->link = new DataLink(this);
<<<<<<< HEAD
<<<<<<< HEAD
	this->receiver = new FileReceiver(this);
	this->fileReceiveThread = new QThread();
	this->fileSendThread = new QThread();
	receiver->moveToThread(fileReceiveThread);
	connect(fileReceiveThread, &QThread::finished, receiver, &QObject::deleteLater);
}


DataLink* MainWindow::GetLinkLevelInstance() {
	return this->link;
=======
=======
>>>>>>> interface
    QStringList name_table;
    //QTableWidget *tableWidget = new QTableWidget(this);
    ui->System_messages_tableWidget->setRowCount(0);
    ui->System_messages_tableWidget->setColumnCount(2);
    name_table << "Событие" << "Дата";
    ui->System_messages_tableWidget->setHorizontalHeaderLabels(name_table);
<<<<<<< HEAD
>>>>>>> interface
=======
>>>>>>> interface
}


MainWindow::~MainWindow()
{
    delete ui;
	delete link;
}

void MainWindow:: slotAdd(QString a){
    ui->System_messages_tableWidget->setRowCount(ui->System_messages_tableWidget->rowCount() + 1);
    QTableWidgetItem *item = new QTableWidgetItem;
    item = new QTableWidgetItem;
    QTableWidgetItem* item1 = new QTableWidgetItem;
    QDateTime cdt = QDateTime::currentDateTime();
    item->setText(a);
    item->setTextAlignment(Qt::AlignCenter);
    item1->setText(cdt.toString("hh:mm:ss dd-M-yyyy"));
    ui->System_messages_tableWidget->setItem(ui->System_messages_tableWidget->rowCount()-1, 0, item);
    ui->System_messages_tableWidget->setItem(ui->System_messages_tableWidget->rowCount()-1, 1, item1);
}

void MainWindow:: RefreshTable(){

}

void MainWindow::on_pushButton_clicked()
{
    // Закрытие приложения
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Выход из приложения", "Вы уверены что хотите выйти из приложения?",QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes){
        QApplication::quit();
    }
    else {
        qDebug() << "Продолжение работы приложения";
    }
}

// Checked
void MainWindow::on_Parameters_connect_button_clicked()
{
    //Перейти к параметру соединений

    Pram_connection winparam;
	connect(&winparam, &Pram_connection::portChanged, this, &MainWindow::OnPortChanged);
    winparam.setModal(true);
    winparam.exec();
}

void MainWindow::on_Open_file_button_clicked()
{
    QString str = QFileDialog::getOpenFileName(0, "Выберите файл", "", "*.txt");
    ui->File_name_choosed->setText(str);
    ui->File_name_choosed->editingFinished();
}

void MainWindow::on_File_name_choosed_textChanged(const QString &arg1)
{
	QFile file(ui->File_name_choosed->text());
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        ui->Send_file_button->setEnabled(true);
        //можно сделать мэссадж бокс что файл успешно загружен
        //считывание файла
        //ui->textBrowser->setText(file.readAll());
        file.close();
    }

	this->chosenPath = ui->File_name_choosed->text();
}

void MainWindow::on_Send_file_button_clicked()
{
	link->SendFile(this->chosenPath);
    if(ui->Connect_status_frame_label)
    {

    }
}

void MainWindow::OnOpenPortButtonClicked()
{
<<<<<<< HEAD
<<<<<<< HEAD
	if (link->GetConnectionStatus() == false) {
		link->SendHello();
	} else {
		link->SendGoodbye();
	}

}

void MainWindow::OnConnectionStatusChanged(bool status) {
	if (status == true) {
		ui->Connection_status_label->setText("Соединение установлено");
		ui->Connection_status_label->setStyleSheet("color: rgb(0, 255, 0)");
		ui->Do_connect_button->setText("Разорвать соединение");
	} else {
		ui->Connection_status_label->setText("Соединение не установлено");
		ui->Connection_status_label->setStyleSheet("color: rgb(255, 0, 0)");
		ui->Do_connect_button->setText("Установить соединение");
=======
	/*if (ui->Do_connect_button->text() == ("Открыть порт")) {
        //НЕОБХОДИМЫЙ ФУНКЦИОНАЛ ДЛЯ ОТКРЫТИЯ ПОРТА


        //link->SendHello();


        //ЕСЛИ ПОРТ УСПЕШНО ОТКРЫТ
        //ui->Do_connect_button->setText("Закрыть порт");
        ui->Do_connect_button->setEnabled(0);
        slotAdd("Порт открыт");
	}*/
}

=======
	/*if (ui->Do_connect_button->text() == ("Открыть порт")) {
        //НЕОБХОДИМЫЙ ФУНКЦИОНАЛ ДЛЯ ОТКРЫТИЯ ПОРТА


        //link->SendHello();


        //ЕСЛИ ПОРТ УСПЕШНО ОТКРЫТ
        //ui->Do_connect_button->setText("Закрыть порт");
        ui->Do_connect_button->setEnabled(0);
        slotAdd("Порт открыт");
	}*/
}

>>>>>>> interface

void MainWindow::OnPortStatusChanged(bool status) {
	if (status == true) {
		ui->Port_status_label->setText("Порт открыт");
		ui->Port_status_label->setStyleSheet("color: rgb(0, 255, 0)");
		ui->Do_open_button->setText("Закрыть порт");
	} else {
		ui->Port_status_label->setText("Порт закрыт");
		ui->Port_status_label->setStyleSheet("color: rgb(255, 0, 0)");
		ui->Do_open_button->setText("Открыть порт");
<<<<<<< HEAD
>>>>>>> interface
	}
}


=======
	}
}


>>>>>>> interface
void MainWindow::OnConnectionStatusChanged(bool status) {
	if (status == true) {
		qDebug() << "Открыли соединение";
		ui->Connection_status_label->setText("Соединение установлено");
		ui->Connection_status_label->setStyleSheet("color: rgb(0, 255, 0)");
		ui->Do_connection_button->setText("Разорвать соединение");
	} else {
		qDebug() << "Закрыли соединение";
		ui->Connection_status_label->setText("Соединение не установлено");
		ui->Connection_status_label->setStyleSheet("color: rgb(255, 0, 0)");
		ui->Do_connection_button->setText("Установить соединение");
	}
}

void MainWindow::on_action_4_triggered()
{
    //Перейти в режим приема файла

	Recieve_file_mode winparam;
    winparam.setModal(true);
    winparam.exec();
}

void MainWindow::on_about_menu_triggered()
{
    //Открыть окно с информацией об исполнителях

    about_1 winparam;
    winparam.setModal(true);
    winparam.exec();
}


void MainWindow::on_action_5_triggered()
{
    Pram_connection winparam;
	connect(&winparam, &Pram_connection::portChanged, this, &MainWindow::OnPortChanged);
    winparam.setModal(true);
    winparam.exec();
}


void MainWindow::on_action_triggered()
{
    QString str = QFileDialog::getOpenFileName(0, "Выберите файл", "", "*.txt");
    ui->File_name_choosed->setText(str);
    ui->File_name_choosed->editingFinished();
}


void MainWindow::on_action_3_triggered()
{
    MainWindow winparam;
    winparam.show();
}


void MainWindow::OnPortChanged(QSerialPortInfo portInfo, int baudRate) {
	this->link->SetPort(portInfo, baudRate);

}


<<<<<<< HEAD
void MainWindow::OnNewDataRead() {
=======
/*void MainWindow::OnNewDataRead() {
>>>>>>> interface
	//qDebug() << "Получены данные: " << this->port->ReceiveData(3);
}*/


void MainWindow::on_File_name_choosed_editingFinished()
{

}


void MainWindow::on_Do_connection_button_clicked()
{
	if (link->GetConnectionStatus() == false) {
		link->SendHello();
	} else {
		link->SendGoodbye();
	}
}


bool MainWindow::OnFileSendRequestReceived(int fileSize) {
	QMessageBox::StandardButton reply = QMessageBox::question(this, "Принятие файла", "Получен запрос на отправку файла! Принять файл?", QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes){
		Recieve_file_mode *winparam = new Recieve_file_mode(this->link, this);
		winparam->setModal(false);
		winparam->show();
		return true;
	} else {
		return false;
	}
	//connect(this, StartExchange());
	//fileReceiveThread->start();
	//receiver->OnReceive(this);
}




void MainWindow::on_Do_open_button_clicked()
{
	if (link->GetPortStatus() == false) {
		link->OpenPort();
	} else {
		link->ClosePort();
	}
}

<<<<<<< HEAD
bool MainWindow::OnFileSendRequestReceived(int fileSize) {
	Recieve_file_mode *winparam = new Recieve_file_mode(this->link, this);
	winparam->setModal(false);
	winparam->show();

=======

void MainWindow::on_File_name_choosed_editingFinished()
{

}


void MainWindow::on_Do_connection_button_clicked()
{
	if (link->GetConnectionStatus() == false) {
		link->SendHello();
	} else {
		link->SendGoodbye();
	}
}


bool MainWindow::OnFileSendRequestReceived(int fileSize) {
	QMessageBox::StandardButton reply = QMessageBox::question(this, "Принятие файла", "Получен запрос на отправку файла! Принять файл?", QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes){
		Recieve_file_mode *winparam = new Recieve_file_mode(this->link, this);
		winparam->setModal(false);
		winparam->show();
		return true;
	} else {
		return false;
	}
>>>>>>> interface
	//connect(this, StartExchange());
	//fileReceiveThread->start();
	//receiver->OnReceive(this);
}


<<<<<<< HEAD
/*void FileExchangeProcess::OnExchange(MainWindow *mw) {
	Recieve_file_mode *window = new Recieve_file_mode(mw->GetLinkLevelInstance(), mw);
	window->show();
}*/
=======


void MainWindow::on_Do_open_button_clicked()
{
	if (link->GetPortStatus() == false) {
		link->OpenPort();
	} else {
		link->ClosePort();
	}
}
>>>>>>> interface
