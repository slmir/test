#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "parametrs.h"

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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H