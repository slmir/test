#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class Parameters;
}

class Parameters : public QMainWindow
{
    Q_OBJECT

public:
    explicit Parameters(QWidget *parent = nullptr);
    ~Parameters();

private:
    Ui::Parameters *ui;
};

#endif // PARAMETERS_H
