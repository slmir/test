#ifndef PRAM_CONNECTION_H
#define PRAM_CONNECTION_H

#include <QDialog>

namespace Ui {
class Pram_connection;
}

class Pram_connection : public QDialog
{
    Q_OBJECT

public:
    explicit Pram_connection(QWidget *parent = nullptr);
    ~Pram_connection();

private:
    Ui::Pram_connection *ui;
};

#endif // PRAM_CONNECTION_H
