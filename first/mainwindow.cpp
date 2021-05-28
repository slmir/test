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


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	this->link = new DataLink(this);
}


MainWindow::~MainWindow()
{
    delete ui;
	delete link;
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
