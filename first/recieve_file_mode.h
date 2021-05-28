#ifndef RECIEVE_FILE_MODE_H
#define RECIEVE_FILE_MODE_H

#include <QDialog>
#include <QProgressBar>
#include "data_link.h"

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
	void OnNewFrameReceived(float currentProgress);

private:
	Ui::Recieve_file_mode *ui;
	QProgressBar *ProgressIndicator;
	int sizeToRead;
	int sizeRead;

	void InitiateExchange();
};

#endif // RECIEVE_FILE_MODE_H
