#include "pram_connection.h"
#include "ui_pram_connection.h"

Pram_connection::Pram_connection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pram_connection)
{
    ui->setupUi(this);
}

Pram_connection::~Pram_connection()
{
    delete ui;
}
