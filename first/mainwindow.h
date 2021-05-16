#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "recieve_file_mode.h"
#include "about_1.h"
#include "pram_connection.h"
#include "data_link.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
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

	void onPortChanged(QSerialPortInfo port, int baudRate);

private:
    Ui::MainWindow *ui;
	DataLink link;
	Port* port;
};
#endif // MAINWINDOW_H
