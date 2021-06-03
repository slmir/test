#include <time.h>
#include "recieve_file_mode.h"
#include "ui_recieve_file_mode.h"
#include "math.h"
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QString>
#include <QTextEdit>
#include <QProgressBar>

<<<<<<< HEAD
class Recieve_file_mode;
=======
>>>>>>> interface

Recieve_file_mode::Recieve_file_mode(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Recieve_file_mode)
{
	ui->setupUi(this);

}

Recieve_file_mode::Recieve_file_mode(DataLink *link, QWidget *parent) : Recieve_file_mode(parent) {
	connect(link, &DataLink::NewInfoFrameReceived, this, &Recieve_file_mode::OnNewFrameReceived);
	InitiateExchange();
}


Recieve_file_mode::Recieve_file_mode(DataLink *link, QWidget *parent) : Recieve_file_mode(parent) {
	connect(link, &DataLink::NewInfoFrameReceived, this, &Recieve_file_mode::OnNewFrameReceived);
	connect(this, &Recieve_file_mode::ReceiveAccepted, link, &DataLink::OnReceiveAccepted);
	connect(this, &Recieve_file_mode::ReceiveAborted, link, &DataLink::OnReceiveAborted);
	connect(this, &Recieve_file_mode::SaveFileButtonClicked, link, &DataLink::OnSaveFileButtonClicked);
	InitiateExchange();
}


int ProgressBar(int data_sent, int data_total) {
	return (data_sent * 100) / data_total;
}


Recieve_file_mode::~Recieve_file_mode()
{
	delete ui;
}

<<<<<<< HEAD
int ProgressBar(int data_sent, int data_total) {
	return (data_sent * 100) / data_total;
}


void Recieve_file_mode::on_Soglsie_to_recieve_file_button_clicked()
{
	// ВРЕМЕННАЯ ЗАГЛУШКА, ЧТОБЫ НЕ КОНФЛИКТОВАТЬ С МОЕЙ РАЗРАБОТКОЙ
	return;

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


void Recieve_file_mode::InitiateExchange() {
	QMessageBox::StandardButton reply = QMessageBox::question(this, "Принятие файла", "Получен запрос на отправку файла! Принять файл?", QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes){
		ProgressIndicator = new QProgressBar(ui->Recieving_progressBar);
		ui->Recieving_progressBar->setRange(0,100);
		ui->Recieving_progressBar->setValue(0);
	} else {
		this->close();
	}
}

=======

void Recieve_file_mode::on_Soglsie_to_recieve_file_button_clicked()
{
	QMessageBox::StandardButton reply = QMessageBox::question(this,"Принятие файла", "Вы уверены что хотите принять файл?", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes){
		qDebug() << "Готов к получению файла";
		emit ReceiveAccepted();
    }
    else {
		qDebug() << "Отмена получения файла";
		emit ReceiveAborted();
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

	emit SaveFileButtonClicked(fileName);

	// ЗАКОММЕНЧИВАЮ, ТАК КАК УЖЕ ЕСТЬ СВОЙ МЕТОД ДЛЯ ЗАПИСИ ПРОЧИТАННЫХ ДАННЫХ В ФАЙЛ
	/*//возможно это как то поможет с записью данных в файле
    if (fileName.isEmpty())
             return;
         else {
             QFile file(fileName);
             if (!file.open(QIODevice::WriteOnly)) {
                 QMessageBox::information(this, tr("Невозможно открыть файл!"),
                     file.errorString());
                 return;
             }
	}*/


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
>>>>>>> interface

void Recieve_file_mode::OnNewFrameReceived(float currentProgress) {
	ui->Recieving_progressBar->setValue(round(currentProgress * 100));
}


void Recieve_file_mode::InitiateExchange() {
	ProgressIndicator = new QProgressBar(ui->Recieving_progressBar);
	ui->Recieving_progressBar->setRange(0,100);
	ui->Recieving_progressBar->setValue(0);
}


void Recieve_file_mode::OnNewFrameReceived(float currentProgress) {
	ui->Recieving_progressBar->setValue(ceil(currentProgress * 100));
}

