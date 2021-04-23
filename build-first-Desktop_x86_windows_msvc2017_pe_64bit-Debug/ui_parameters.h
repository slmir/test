/********************************************************************************
** Form generated from reading UI file 'parameters.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETERS_H
#define UI_PARAMETERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Parameters
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *label;
    QFrame *frame_2;
    QLabel *label_2;
    QTextBrowser *textBrowser;
    QFrame *frame_3;
    QLabel *label_4;
    QPlainTextEdit *plainTextEdit_2;
    QLabel *label_5;
    QTextBrowser *textBrowser_3;
    QLabel *label_6;
    QTextBrowser *textBrowser_4;
    QLabel *label_7;
    QTextBrowser *textBrowser_5;
    QLabel *label_8;
    QTextBrowser *textBrowser_6;
    QLabel *label_3;
    QPushButton *OK_button;
    QPushButton *Back_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Parameters)
    {
        if (Parameters->objectName().isEmpty())
            Parameters->setObjectName(QString::fromUtf8("Parameters"));
        Parameters->resize(510, 537);
        centralwidget = new QWidget(Parameters);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 20, 471, 401));
        frame->setFrameShape(QFrame::Box);
        frame->setLineWidth(2);
        frame->setMidLineWidth(1);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 171, 16));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(20, 50, 431, 51));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 20, 91, 16));
        textBrowser = new QTextBrowser(frame_2);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(170, 10, 241, 31));
        textBrowser->setSource(QUrl(QString::fromUtf8("file:///Z:/qt/Kurs/first/Resources/Com.txt")));
        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(20, 140, 431, 251));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 20, 91, 16));
        plainTextEdit_2 = new QPlainTextEdit(frame_3);
        plainTextEdit_2->setObjectName(QString::fromUtf8("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(170, 10, 241, 31));
        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 70, 91, 16));
        textBrowser_3 = new QTextBrowser(frame_3);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(170, 60, 241, 31));
        label_6 = new QLabel(frame_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 120, 91, 16));
        textBrowser_4 = new QTextBrowser(frame_3);
        textBrowser_4->setObjectName(QString::fromUtf8("textBrowser_4"));
        textBrowser_4->setGeometry(QRect(170, 110, 241, 31));
        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 170, 111, 16));
        textBrowser_5 = new QTextBrowser(frame_3);
        textBrowser_5->setObjectName(QString::fromUtf8("textBrowser_5"));
        textBrowser_5->setGeometry(QRect(170, 160, 241, 31));
        label_8 = new QLabel(frame_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 220, 141, 16));
        textBrowser_6 = new QTextBrowser(frame_3);
        textBrowser_6->setObjectName(QString::fromUtf8("textBrowser_6"));
        textBrowser_6->setGeometry(QRect(170, 210, 241, 31));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 110, 171, 16));
        OK_button = new QPushButton(centralwidget);
        OK_button->setObjectName(QString::fromUtf8("OK_button"));
        OK_button->setGeometry(QRect(290, 450, 93, 28));
        Back_button = new QPushButton(centralwidget);
        Back_button->setObjectName(QString::fromUtf8("Back_button"));
        Back_button->setGeometry(QRect(400, 450, 93, 28));
        Parameters->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Parameters);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 510, 26));
        Parameters->setMenuBar(menubar);
        statusbar = new QStatusBar(Parameters);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Parameters->setStatusBar(statusbar);

        retranslateUi(Parameters);

        QMetaObject::connectSlotsByName(Parameters);
    } // setupUi

    void retranslateUi(QMainWindow *Parameters)
    {
        Parameters->setWindowTitle(QCoreApplication::translate("Parameters", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("Parameters", "\320\237\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\321\213\320\271 \320\277\320\276\321\200\321\202", nullptr));
        label_2->setText(QCoreApplication::translate("Parameters", "\320\235\320\276\320\274\320\265\321\200 \320\277\320\276\321\200\321\202\320\260:", nullptr));
        label_4->setText(QCoreApplication::translate("Parameters", "\320\221\320\270\321\202 \320\262 \321\201\320\265\320\272\321\203\320\275\320\264\321\203:", nullptr));
        label_5->setText(QCoreApplication::translate("Parameters", "\320\221\320\270\321\202\321\213 \320\264\320\260\320\275\320\275\321\213\321\205:", nullptr));
        label_6->setText(QCoreApplication::translate("Parameters", "\320\247\320\265\321\202\320\275\320\276\321\201\321\202\321\214:", nullptr));
        label_7->setText(QCoreApplication::translate("Parameters", "\320\241\321\202\320\276\320\277\320\276\320\262\321\213\320\265 \320\261\320\270\321\202\321\213:", nullptr));
        label_8->setText(QCoreApplication::translate("Parameters", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\320\276\321\202\320\276\320\272\320\276\320\274:", nullptr));
        label_3->setText(QCoreApplication::translate("Parameters", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\277\320\276\321\200\321\202\320\260", nullptr));
        OK_button->setText(QCoreApplication::translate("Parameters", "\320\236\320\232", nullptr));
        Back_button->setText(QCoreApplication::translate("Parameters", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Parameters: public Ui_Parameters {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETERS_H
