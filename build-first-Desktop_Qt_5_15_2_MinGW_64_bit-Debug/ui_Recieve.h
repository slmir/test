/********************************************************************************
** Form generated from reading UI file 'Recieve.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECIEVE_H
#define UI_RECIEVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *Soglsie_to_recieve_file_button;
    QGroupBox *groupBox;
    QProgressBar *Recieving_progressBar;
    QGroupBox *Connect_groupBox;
    QFrame *Status_frame;
    QLabel *Connection_status_label;
    QPushButton *Do_connect_button;
    QPushButton *objectName;
    QLabel *Connect_status_frame_label;
    QFrame *frame_4;
    QLabel *System_message_label;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(773, 540);
        Soglsie_to_recieve_file_button = new QPushButton(Dialog);
        Soglsie_to_recieve_file_button->setObjectName(QString::fromUtf8("Soglsie_to_recieve_file_button"));
        Soglsie_to_recieve_file_button->setGeometry(QRect(20, 310, 391, 28));
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 370, 501, 61));
        Recieving_progressBar = new QProgressBar(groupBox);
        Recieving_progressBar->setObjectName(QString::fromUtf8("Recieving_progressBar"));
        Recieving_progressBar->setGeometry(QRect(10, 20, 471, 21));
        Recieving_progressBar->setValue(24);
        Connect_groupBox = new QGroupBox(Dialog);
        Connect_groupBox->setObjectName(QString::fromUtf8("Connect_groupBox"));
        Connect_groupBox->setGeometry(QRect(20, 60, 741, 231));
        Status_frame = new QFrame(Connect_groupBox);
        Status_frame->setObjectName(QString::fromUtf8("Status_frame"));
        Status_frame->setGeometry(QRect(20, 70, 291, 141));
        Status_frame->setFrameShape(QFrame::Box);
        Status_frame->setFrameShadow(QFrame::Raised);
        Status_frame->setLineWidth(2);
        Status_frame->setMidLineWidth(1);
        Connection_status_label = new QLabel(Status_frame);
        Connection_status_label->setObjectName(QString::fromUtf8("Connection_status_label"));
        Connection_status_label->setGeometry(QRect(20, 20, 251, 16));
        Connection_status_label->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        Connection_status_label->setAlignment(Qt::AlignCenter);
        Do_connect_button = new QPushButton(Status_frame);
        Do_connect_button->setObjectName(QString::fromUtf8("Do_connect_button"));
        Do_connect_button->setEnabled(false);
        Do_connect_button->setGeometry(QRect(10, 60, 271, 28));
        objectName = new QPushButton(Status_frame);
        objectName->setObjectName(QString::fromUtf8("objectName"));
        objectName->setGeometry(QRect(10, 100, 271, 28));
        Connect_status_frame_label = new QLabel(Connect_groupBox);
        Connect_status_frame_label->setObjectName(QString::fromUtf8("Connect_status_frame_label"));
        Connect_status_frame_label->setGeometry(QRect(20, 40, 141, 16));
        frame_4 = new QFrame(Connect_groupBox);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(360, 70, 351, 141));
        frame_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 205);"));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Plain);
        frame_4->setLineWidth(2);
        frame_4->setMidLineWidth(1);
        System_message_label = new QLabel(Connect_groupBox);
        System_message_label->setObjectName(QString::fromUtf8("System_message_label"));
        System_message_label->setGeometry(QRect(360, 40, 171, 16));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        Soglsie_to_recieve_file_button->setText(QCoreApplication::translate("Dialog", "\320\222 \320\277\320\276\321\201\320\273\320\265\320\264\321\201\321\202\320\262\320\270\320\270 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265 \320\261\321\203\320\264\320\265\321\202 \320\277\320\276\321\217\320\262\320\273\321\217\321\202\321\214\321\201\321\217 \320\260\320\262\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\270", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Dialog", "\320\237\320\276\320\273\321\203\321\207\320\265\320\275\320\270\320\265 \321\204\320\260\320\271\320\273\320\260", nullptr));
        Connect_groupBox->setTitle(QCoreApplication::translate("Dialog", "\320\241\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\320\265", nullptr));
        Connection_status_label->setText(QCoreApplication::translate("Dialog", "\320\241\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\320\265 \320\275\320\265 \321\203\321\201\321\202\320\260\320\275\320\276\320\262\320\273\320\265\320\275\320\276", nullptr));
        Do_connect_button->setText(QCoreApplication::translate("Dialog", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\320\265", nullptr));
        objectName->setText(QCoreApplication::translate("Dialog", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\321\217", nullptr));
        Connect_status_frame_label->setText(QCoreApplication::translate("Dialog", "\320\241\321\202\320\260\321\202\321\203\321\201 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\321\217", nullptr));
        System_message_label->setText(QCoreApplication::translate("Dialog", "\320\241\320\270\321\201\321\202\320\265\320\274\320\275\321\213\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECIEVE_H
