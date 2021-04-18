#include "parametrs.h"
#include "mainwindow.h"
#include "ui_parametrs.h"
#include <QMessageBox>
#include <QDebug>

Parametrs::Parametrs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Parametrs)
{
    ui->setupUi(this);
}

Parametrs::~Parametrs()
{
    delete ui;
}



void Parametrs::on_OK_button_clicked()
{

}
