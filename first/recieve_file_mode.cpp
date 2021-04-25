#include <time.h>
#include "recieve_file_mode.h"
#include "ui_recieve_file_mode.h"
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QString>
#include <QTextEdit>
#include <QProgressBar>

Recieve_file_mode::Recieve_file_mode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Recieve_file_mode)
{
    ui->setupUi(this);
}

Recieve_file_mode::~Recieve_file_mode()
{
    delete ui;
}

int ProgressBar(int data_sent, int data_total) {
        return (data_sent * 100) / data_total;
    }


void Recieve_file_mode::on_Soglsie_to_recieve_file_button_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Принятие файла", "Вы уверены что хотите принять файл?",QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes){
        ui->Soglsie_to_recieve_file_button->setText("В последствии сообщение будет появляться автоматически \n при получении запроса на передачу файла");
        //начало процедуры передачи
        ProgressIndicator = new QProgressBar(ui->Recieving_progressBar);
        //ui->Recieving_progressBar->resize(200,25);
        ui->Recieving_progressBar->setRange(0,100);
        ui->Recieving_progressBar->setValue(0);
        //ui->Recieving_progressBar->setOrientation(Qt::Horizontal);
        //connect(ProgressIndicator,SIGNAL(ProgressBar(0, 100)),ProgressIndicator,SLOT(setValue(int)));
        // or as alternative to the two above, you could call
        // progressBar.setRange(0,100);

        for( int i = 0; i <100; ++i ) {
           ui->Recieving_progressBar->setValue(i);
           _sleep(50);
        }
        _sleep(500);
        //Условие если файл до конца получен
        ui->Recieving_progressBar->setValue(100);

        //Сделать активной кнопку сохранения файла
        ui->Save_recieved_file_button->setEnabled(1);
    }
    else {
        qDebug() << "Продолжение работы приложения";
    }

}
