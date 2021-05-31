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
    QStringList name_table;
    //QTableWidget *tableWidget = new QTableWidget(this);
    ui->System_messages_tableWidget->setRowCount(0);
    ui->System_messages_tableWidget->setColumnCount(2);
    name_table << "Событие" << "Дата";
    ui->System_messages_tableWidget->setHorizontalHeaderLabels(name_table);
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

void MainWindow::on_Do_connect_button_clicked()
{
    if (ui->Do_connect_button->text() == ("Открыть порт")) {
        //НЕОБХОДИМЫЙ ФУНКЦИОНАЛ ДЛЯ ОТКРЫТИЯ ПОРТА


        //link->SendHello();


        //ЕСЛИ ПОРТ УСПЕШНО ОТКРЫТ
        ui->Do_connect_button->setText("Установить соединение");
        slotAdd("Порт открыт");



    }
    //УСТАНОВКА СОЕДИНЕНИЯ
    else if (ui->Do_connect_button->text() == ("Установить соединение")){
        link->SendHello();
        ui->Connection_status_label->setText("Соединение установлено");
        ui->Connection_status_label->setStyleSheet("color: rgb(0, 200, 0)");

        ui->Do_connect_button->setText("Разорвать соединение");
        slotAdd("Соединение установлено");
    }
    //РАЗРЫВ СОЕДИНЕНИЯ
    else if (ui->Do_connect_button->text() == ("Разорвать соединение")){
        link->SendHello();
        ui->Connection_status_label->setText("Соединение не установлено");
        ui->Connection_status_label->setStyleSheet("color: rgb(200, 0, 0)");

        //СООБЩЕНИЕ О ТОМ ЧТО СОЕДИНЕНИЕ УСПЕШНО РАЗОРВАНО
        ui->Do_connect_button->setText("Открыть порт");
        slotAdd("Соединение разорвано");
    }
}

void MainWindow::OnConnectionEstablished() {
	if (ui->Connection_status_label->text() == "Соединение не установлено") {
		ui->Connection_status_label->setText("Соединение установлено");
		ui->Connection_status_label->setStyleSheet("color: rgb(0, 200, 0)");
		ui->Do_connect_button->setText("Разорвать соединение");
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

void MainWindow::OnNewDataRead() {
	//qDebug() << "Получены данные: " << this->port->ReceiveData(3);
}

void MainWindow::on_File_name_choosed_editingFinished()
{

}

