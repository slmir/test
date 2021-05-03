#ifndef PRAM_CONNECTION_H
#define PRAM_CONNECTION_H

#include <QDialog>
#include <QListView>
#include <QSerialPortInfo>
namespace Ui {
class Pram_connection;
}

class Pram_connection : public QDialog
{
    Q_OBJECT

public:
    explicit Pram_connection(QWidget *parent = nullptr);
    ~Pram_connection();

private slots:
    void on_OK_button_clicked();

    void on_Back_button_clicked();

private:
    Ui::Pram_connection *ui;
    QListView *listView; // указатель на список элементов
	QList<QSerialPortInfo> ports; // список доступных портов
};

#endif // PRAM_CONNECTION_H
