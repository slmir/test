/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *about_menu;
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QWidget *centralwidget;
    QFrame *frame;
    QGroupBox *Connect_groupBox;
    QFrame *frame_3;
    QLabel *Connection_status_label;
    QPushButton *Do_open_button;
    QPushButton *Parameters_connect_button;
    QPushButton *Do_connection_button;
    QLabel *Port_status_label;
    QLabel *Connect_status_frame_label;
    QLabel *System_message_label;
    QTableWidget *System_messages_tableWidget;
    QGroupBox *Send_file_gropubox;
    QPushButton *Send_file_button;
    QLineEdit *File_name_choosed;
    QLabel *Choose_file_label;
    QPushButton *Open_file_button;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *To_file_menu;
    QMenu *menu_3;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1003, 624);
        about_menu = new QAction(MainWindow);
        about_menu->setObjectName(QString::fromUtf8("about_menu"));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QString::fromUtf8("action_4"));
        action_5 = new QAction(MainWindow);
        action_5->setObjectName(QString::fromUtf8("action_5"));
        action_5->setShortcutContext(Qt::WindowShortcut);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 10, 961, 541));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(1);
        frame->setMidLineWidth(1);
        Connect_groupBox = new QGroupBox(frame);
        Connect_groupBox->setObjectName(QString::fromUtf8("Connect_groupBox"));
        Connect_groupBox->setGeometry(QRect(30, 220, 921, 311));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        Connect_groupBox->setFont(font);
        Connect_groupBox->setFlat(false);
        frame_3 = new QFrame(Connect_groupBox);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(20, 60, 351, 231));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_3->setLineWidth(2);
        frame_3->setMidLineWidth(1);
        Connection_status_label = new QLabel(frame_3);
        Connection_status_label->setObjectName(QString::fromUtf8("Connection_status_label"));
        Connection_status_label->setGeometry(QRect(40, 39, 271, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        Connection_status_label->setFont(font1);
        Connection_status_label->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        Connection_status_label->setAlignment(Qt::AlignCenter);
        Do_open_button = new QPushButton(frame_3);
        Do_open_button->setObjectName(QString::fromUtf8("Do_open_button"));
        Do_open_button->setEnabled(true);
        Do_open_button->setGeometry(QRect(40, 70, 271, 41));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setWeight(50);
        Do_open_button->setFont(font2);
        Parameters_connect_button = new QPushButton(frame_3);
        Parameters_connect_button->setObjectName(QString::fromUtf8("Parameters_connect_button"));
        Parameters_connect_button->setGeometry(QRect(40, 170, 271, 41));
        Parameters_connect_button->setFont(font2);
        Do_connection_button = new QPushButton(frame_3);
        Do_connection_button->setObjectName(QString::fromUtf8("Do_connection_button"));
        Do_connection_button->setEnabled(true);
        Do_connection_button->setGeometry(QRect(40, 120, 271, 41));
        Do_connection_button->setFont(font2);
        Port_status_label = new QLabel(frame_3);
        Port_status_label->setObjectName(QString::fromUtf8("Port_status_label"));
        Port_status_label->setGeometry(QRect(40, 9, 271, 31));
        Port_status_label->setFont(font1);
        Port_status_label->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        Port_status_label->setAlignment(Qt::AlignCenter);
        Connect_status_frame_label = new QLabel(Connect_groupBox);
        Connect_status_frame_label->setObjectName(QString::fromUtf8("Connect_status_frame_label"));
        Connect_status_frame_label->setGeometry(QRect(20, 30, 141, 16));
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(false);
        font3.setWeight(50);
        Connect_status_frame_label->setFont(font3);
        System_message_label = new QLabel(Connect_groupBox);
        System_message_label->setObjectName(QString::fromUtf8("System_message_label"));
        System_message_label->setGeometry(QRect(440, 30, 171, 16));
        System_message_label->setFont(font3);
        System_messages_tableWidget = new QTableWidget(Connect_groupBox);
        System_messages_tableWidget->setObjectName(QString::fromUtf8("System_messages_tableWidget"));
        System_messages_tableWidget->setGeometry(QRect(440, 60, 461, 231));
        System_messages_tableWidget->setFont(font3);
        Send_file_gropubox = new QGroupBox(frame);
        Send_file_gropubox->setObjectName(QString::fromUtf8("Send_file_gropubox"));
        Send_file_gropubox->setGeometry(QRect(30, 20, 921, 181));
        Send_file_gropubox->setFont(font);
        Send_file_gropubox->setFlat(false);
        Send_file_button = new QPushButton(Send_file_gropubox);
        Send_file_button->setObjectName(QString::fromUtf8("Send_file_button"));
        Send_file_button->setEnabled(false);
        Send_file_button->setGeometry(QRect(570, 130, 211, 28));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(false);
        font4.setWeight(50);
        Send_file_button->setFont(font4);
        File_name_choosed = new QLineEdit(Send_file_gropubox);
        File_name_choosed->setObjectName(QString::fromUtf8("File_name_choosed"));
        File_name_choosed->setEnabled(true);
        File_name_choosed->setGeometry(QRect(20, 90, 761, 31));
        File_name_choosed->setReadOnly(true);
        File_name_choosed->setClearButtonEnabled(false);
        Choose_file_label = new QLabel(Send_file_gropubox);
        Choose_file_label->setObjectName(QString::fromUtf8("Choose_file_label"));
        Choose_file_label->setGeometry(QRect(20, 30, 111, 16));
        Choose_file_label->setFont(font3);
        Open_file_button = new QPushButton(Send_file_gropubox);
        Open_file_button->setObjectName(QString::fromUtf8("Open_file_button"));
        Open_file_button->setGeometry(QRect(790, 90, 111, 31));
        Open_file_button->setFont(font4);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(810, 560, 171, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1003, 20));
        To_file_menu = new QMenu(menubar);
        To_file_menu->setObjectName(QString::fromUtf8("To_file_menu"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(To_file_menu->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu->menuAction());
        To_file_menu->addAction(action);
        menu_3->addAction(about_menu);
        menu->addAction(action_3);
        menu->addAction(action_4);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\232\321\203\321\200\321\201\320\276\320\262\320\260\321\217 \321\200\320\260\320\261\320\276\321\202\320\260. \320\223\320\273\320\260\320\262\320\275\320\260\321\217", nullptr));
        about_menu->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265...", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214...", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214...", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\272\320\260...", nullptr));
        action_4->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\321\221\320\274...", nullptr));
        action_5->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\321\217...", nullptr));
        Connect_groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\320\265", nullptr));
        Connection_status_label->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\320\265 \320\275\320\265 \321\203\321\201\321\202\320\260\320\275\320\276\320\262\320\273\320\265\320\275\320\276", nullptr));
        Do_open_button->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\277\320\276\321\200\321\202", nullptr));
        Parameters_connect_button->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\321\217", nullptr));
        Do_connection_button->setText(QCoreApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\320\265", nullptr));
        Port_status_label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\200\321\202 \320\267\320\260\320\272\321\200\321\213\321\202", nullptr));
        Connect_status_frame_label->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\321\217", nullptr));
        System_message_label->setText(QCoreApplication::translate("MainWindow", "\320\241\320\270\321\201\321\202\320\265\320\274\320\275\321\213\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\321\217", nullptr));
        Send_file_gropubox->setTitle(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        Send_file_button->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        Choose_file_label->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\204\320\260\320\271\320\273:", nullptr));
        Open_file_button->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214...", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270 \320\270\320\267 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", nullptr));
        To_file_menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\266\320\270\320\274 \321\200\320\260\320\261\320\276\321\202\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
