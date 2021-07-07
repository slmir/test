#include "about_1.h"
#include "ui_about_1.h"
#include <QPixmap>

about_1::about_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about_1)
{
    ui->setupUi(this);
    QPixmap pix(":/img/Resources/cable.jpg");
    int w = ui->label01->width();
    int h = ui->label01->height();

    ui->label01->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

about_1::~about_1()
{
    delete ui;
}

void about_1::on_OK_button_clicked()
{
    QWidget::close();
}
