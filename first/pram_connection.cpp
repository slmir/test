#include "pram_connection.h"
#include "ui_pram_connection.h"
#include <QListView>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QString>
#include <QTextEdit>

Pram_connection::Pram_connection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pram_connection)
{
    ui->setupUi(this);

    listView = new QListView(ui->Port_number_comboBox);
    ui->Port_number_comboBox->setView(listView);

    ui->Port_number_comboBox->addItem("COM 1");
    ui->Port_number_comboBox->addItem("COM 2");
    ui->Port_number_comboBox->addItem("...");

    listView = new QListView(ui->Bits_in_second_comboBox);
    ui->Bits_in_second_comboBox->setView(listView);

    ui->Bits_in_second_comboBox->addItem("9600");
    ui->Bits_in_second_comboBox->addItem("4800");
    ui->Bits_in_second_comboBox->addItem("2400");
    ui->Bits_in_second_comboBox->addItem("1200");
    ui->Bits_in_second_comboBox->addItem("600");
    ui->Bits_in_second_comboBox->addItem("...");

    listView = new QListView(ui->Data_bits_comboBox);
    ui->Data_bits_comboBox->setView(listView);

    ui->Data_bits_comboBox->addItem("8");
    ui->Data_bits_comboBox->addItem("4");
    ui->Data_bits_comboBox->addItem("2");
    ui->Data_bits_comboBox->addItem("1");
    ui->Data_bits_comboBox->addItem("...");

    listView = new QListView(ui->Chetnost_comboBox);
    ui->Chetnost_comboBox->setView(listView);

    ui->Chetnost_comboBox->addItem("None");
    ui->Chetnost_comboBox->addItem("1");
    ui->Chetnost_comboBox->addItem("0");
    ui->Chetnost_comboBox->addItem("...");

    listView = new QListView(ui->Stop_bits_comboBox);
    ui->Stop_bits_comboBox->setView(listView);

    ui->Stop_bits_comboBox->addItem("One");
    ui->Stop_bits_comboBox->addItem("Two");
    ui->Stop_bits_comboBox->addItem("None");
    ui->Stop_bits_comboBox->addItem("...");

    listView = new QListView(ui->Upravl_steam_comboBox);
    ui->Upravl_steam_comboBox->setView(listView);

    ui->Upravl_steam_comboBox->addItem("None");
    ui->Upravl_steam_comboBox->addItem("True");
    ui->Upravl_steam_comboBox->addItem("False");
    ui->Upravl_steam_comboBox->addItem("...");
}

Pram_connection::~Pram_connection()
{
    delete ui;
}

void Pram_connection::on_OK_button_clicked()
{
    //Применить параметры соединения



    QMessageBox::StandardButton reply = QMessageBox::question(this,"Параметры", "Вы уверены что хотите утвердить параметры?",QMessageBox::Yes | QMessageBox::No);

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
