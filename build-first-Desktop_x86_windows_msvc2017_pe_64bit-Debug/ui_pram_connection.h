/********************************************************************************
** Form generated from reading UI file 'pram_connection.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRAM_CONNECTION_H
#define UI_PRAM_CONNECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Pram_connection
{
public:
    QFrame *frame;
    QGroupBox *groupBox_2;
    QLabel *label_2;
    QComboBox *Port_number_comboBox;
    QGroupBox *groupBox_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QComboBox *comboBox_5;
    QComboBox *comboBox_6;
    QComboBox *comboBox_2;
    QPushButton *OK_button;
    QPushButton *Back_button;

    void setupUi(QDialog *Pram_connection)
    {
        if (Pram_connection->objectName().isEmpty())
            Pram_connection->setObjectName(QString::fromUtf8("Pram_connection"));
        Pram_connection->resize(535, 494);
        frame = new QFrame(Pram_connection);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(40, 30, 471, 401));
        frame->setFrameShape(QFrame::Box);
        frame->setLineWidth(2);
        frame->setMidLineWidth(1);
        groupBox_2 = new QGroupBox(frame);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 20, 431, 81));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 30, 91, 16));
        Port_number_comboBox = new QComboBox(groupBox_2);
        Port_number_comboBox->setObjectName(QString::fromUtf8("Port_number_comboBox"));
        Port_number_comboBox->setGeometry(QRect(180, 30, 221, 22));
        groupBox_3 = new QGroupBox(frame);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 120, 431, 271));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 40, 86, 16));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 80, 91, 16));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 130, 91, 16));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(40, 180, 111, 16));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(40, 230, 141, 16));
        comboBox_3 = new QComboBox(groupBox_3);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setEnabled(false);
        comboBox_3->setGeometry(QRect(180, 80, 221, 22));
        comboBox_4 = new QComboBox(groupBox_3);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setEnabled(false);
        comboBox_4->setGeometry(QRect(180, 130, 221, 22));
        comboBox_5 = new QComboBox(groupBox_3);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setGeometry(QRect(180, 180, 221, 22));
        comboBox_6 = new QComboBox(groupBox_3);
        comboBox_6->setObjectName(QString::fromUtf8("comboBox_6"));
        comboBox_6->setGeometry(QRect(180, 230, 221, 22));
        comboBox_2 = new QComboBox(groupBox_3);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(180, 30, 221, 22));
        OK_button = new QPushButton(Pram_connection);
        OK_button->setObjectName(QString::fromUtf8("OK_button"));
        OK_button->setGeometry(QRect(310, 450, 93, 28));
        Back_button = new QPushButton(Pram_connection);
        Back_button->setObjectName(QString::fromUtf8("Back_button"));
        Back_button->setGeometry(QRect(420, 450, 93, 28));

        retranslateUi(Pram_connection);

        QMetaObject::connectSlotsByName(Pram_connection);
    } // setupUi

    void retranslateUi(QDialog *Pram_connection)
    {
        Pram_connection->setWindowTitle(QCoreApplication::translate("Pram_connection", "Dialog", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Pram_connection", "\320\237\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\321\213\320\271 \320\277\320\276\321\200\321\202", nullptr));
        label_2->setText(QCoreApplication::translate("Pram_connection", "\320\235\320\276\320\274\320\265\321\200 \320\277\320\276\321\200\321\202\320\260:", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Pram_connection", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\277\320\276\321\200\321\202\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("Pram_connection", "\320\221\320\270\321\202 \320\262 \321\201\320\265\320\272\321\203\320\275\320\264\321\203:", nullptr));
        label_5->setText(QCoreApplication::translate("Pram_connection", "\320\221\320\270\321\202\321\213 \320\264\320\260\320\275\320\275\321\213\321\205:", nullptr));
        label_6->setText(QCoreApplication::translate("Pram_connection", "\320\247\320\265\321\202\320\275\320\276\321\201\321\202\321\214:", nullptr));
        label_7->setText(QCoreApplication::translate("Pram_connection", "\320\241\321\202\320\276\320\277\320\276\320\262\321\213\320\265 \320\261\320\270\321\202\321\213:", nullptr));
        label_8->setText(QCoreApplication::translate("Pram_connection", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\320\276\321\202\320\276\320\272\320\276\320\274:", nullptr));
        OK_button->setText(QCoreApplication::translate("Pram_connection", "\320\236\320\232", nullptr));
        Back_button->setText(QCoreApplication::translate("Pram_connection", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Pram_connection: public Ui_Pram_connection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRAM_CONNECTION_H
