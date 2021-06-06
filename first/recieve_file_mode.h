#ifndef RECIEVE_FILE_MODE_H
#define RECIEVE_FILE_MODE_H

#include <QDialog>
#include <QProgressBar>
#include "data_link.h"


class DataLink;


namespace Ui {
class Recieve_file_mode;
}

class Recieve_file_mode : public QDialog
{
    Q_OBJECT

public:
    explicit Recieve_file_mode(QWidget *parent = nullptr);
	Recieve_file_mode(DataLink *link, QWidget *parent = nullptr);
    ~Recieve_file_mode();

private slots:
    void on_Soglsie_to_recieve_file_button_clicked();

    void on_Save_recieved_file_button_clicked();

    void on_Open_folder_dialog_button_clicked();

    void on_File_directory_choosed_textEdited(const QString &arg1);

    void on_File_directory_choosed_textChanged(const QString &arg1);

    void on_Save_file_button_clicked();

    void on_Check_file_name_button_clicked();

	void OnNewFrameReceived(float currentProgress);

private:
    Ui::Recieve_file_mode *ui;
    QProgressBar *ProgressIndicator;
	int sizeToRead;
	int sizeRead;

	void InitiateExchange();


signals:
	// Сигналы, отправляемые в канальный уровень
	void ReceiveAccepted();
	void ReceiveAborted();
	void SaveFileButtonClicked(QString path);
};

#endif // RECIEVE_FILE_MODE_H
