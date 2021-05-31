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


        //Сделать активной кнопку сохранения файла
        //ui->Save_recieved_file_button->setEnabled(1);
    }
    else {
        qDebug() << "Продолжение работы приложения";
    }

}

void Recieve_file_mode::on_Save_recieved_file_button_clicked()
{

}


void Recieve_file_mode::on_Open_folder_dialog_button_clicked()
{
    QString str = QFileDialog::getExistingDirectory(0, "Directory Dialog", "");
    ui->File_directory_choosed->setText(str);
    ui->File_directory_choosed->editingFinished();
}


void Recieve_file_mode::on_File_directory_choosed_textEdited(const QString &arg1)
{
    QDir dir(ui->File_directory_choosed->text());
    //такая директория существует
    if (dir.exists()) {
        ui->Save_file_button->setEnabled(1);

    }

    //this->savePath = ui->File_directory_choosed->text();
}


void Recieve_file_mode::on_File_directory_choosed_textChanged(const QString &arg1)
{
    QDir dir(ui->File_directory_choosed->text());
    //такая директория существует
    if (dir.exists()) {
        ui->Save_file_button->setEnabled(1);

    }

    //this->savePath = ui->File_directory_choosed->text();
}


void Recieve_file_mode::on_Save_file_button_clicked()
{
    //Сохранение файла с введенным именем в выбранной дериктории (создается пустая болванка, в которую наверное легче вписывать данные)

    QString fileName = QFileDialog::getSaveFileName(this, ui->File_directory_choosed->text(), ui->File_name_input->text(), "*.txt");

    //возможно это как то поможет с записью данных в файле
    if (fileName.isEmpty())
             return;
         else {
             QFile file(fileName);
             if (!file.open(QIODevice::WriteOnly)) {
                 QMessageBox::information(this, tr("Невозможно открыть файл!"),
                     file.errorString());
                 return;
             }
    }


}


void Recieve_file_mode::on_Check_file_name_button_clicked()
{
    QString str =  ui->Check_file_name_button->text();
    if (str == "Подтвердить") {
        ui->File_name_input->setEnabled(0);
        ui->Check_file_name_button->setText("Изменить");
    }
    else {
        ui->File_name_input->setEnabled(1);
        ui->Check_file_name_button->setText("Подтвердить");
    }

}

