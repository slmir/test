#ifndef PARAMETRS_H
#define PARAMETRS_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Parametrs;
}

class Parametrs : public QDialog
{
    Q_OBJECT

public:
    explicit Parametrs(QWidget *parent = nullptr);
    ~Parametrs();

private slots:
    void on_buttonBox_accepted();

    void on_OK_button_clicked();

private:
    Ui::Parametrs *ui;
};

#endif // PARAMETRS_H
