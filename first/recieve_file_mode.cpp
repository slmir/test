#include "recieve_file_mode.h"
#include "ui_recieve_file_mode.h"

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
