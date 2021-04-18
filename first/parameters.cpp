#include "parameters.h"
#include "ui_parameters.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QDebug>

Parameters::Parameters(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Parameters)
{
    ui->setupUi(this);
}

Parameters::~Parameters()
{
    delete ui;
}
