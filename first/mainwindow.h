#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "recieve_file_mode.h"
#include "about_1.h"
#include "pram_connection.h"
#include "data_link.h"
#include <QTableWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QHBoxLayout>


class DataLink;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private:

    void RefreshTable();

private slots:


    void slotAdd(QString a);

    void on_pushButton_clicked();

    void on_Parameters_connect_button_clicked();

    void on_Open_file_button_clicked();

    void on_File_name_choosed_textChanged(const QString &arg1);

    void on_Send_file_button_clicked();

    void on_Do_connect_button_clicked();

    void on_action_4_triggered();

    void on_about_menu_triggered();

    void on_action_5_triggered();

    void on_action_triggered();

    void on_action_3_triggered();

	void OnPortChanged(QSerialPortInfo port, int baudRate);

    void on_File_name_choosed_editingFinished();

    void on_Do_connection_button_clicked();

public slots:
	void OnNewDataRead();
	void OnConnectionEstablished();

private:
    Ui::MainWindow *ui;
	DataLink* link;
	QString chosenPath;
};
#endif // MAINWINDOW_H
