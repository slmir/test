/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *OK_button;
    QLabel *label01;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QString::fromUtf8("About"));
        About->resize(915, 485);
        label = new QLabel(About);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 841, 71));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(About);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(440, 150, 141, 31));
        QFont font1;
        font1.setPointSize(14);
        label_2->setFont(font1);
        label_3 = new QLabel(About);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 70, 711, 71));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(About);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(490, 200, 261, 31));
        QFont font2;
        font2.setPointSize(12);
        label_4->setFont(font2);
        label_5 = new QLabel(About);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(490, 240, 281, 31));
        label_5->setFont(font2);
        label_6 = new QLabel(About);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(490, 280, 281, 31));
        label_6->setFont(font2);
        label_7 = new QLabel(About);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(280, 330, 301, 51));
        label_7->setFont(font2);
        label_8 = new QLabel(About);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(120, 370, 611, 51));
        label_8->setFont(font2);
        label_9 = new QLabel(About);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(380, 410, 101, 51));
        QFont font3;
        font3.setPointSize(10);
        label_9->setFont(font3);
        OK_button = new QPushButton(About);
        OK_button->setObjectName(QString::fromUtf8("OK_button"));
        OK_button->setGeometry(QRect(792, 437, 101, 31));
        label01 = new QLabel(About);
        label01->setObjectName(QString::fromUtf8("label01"));
        label01->setGeometry(QRect(80, 200, 321, 121));

        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QCoreApplication::translate("About", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("About", "\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260 \320\277\320\265\321\200\320\265\320\264\320\260\321\207\320\270 \321\202\320\265\320\272\321\201\321\202\320\276\320\262\321\213\321\205 \321\204\320\260\320\271\320\273\320\276\320\262 ", nullptr));
        label_2->setText(QCoreApplication::translate("About", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\320\273\320\270:", nullptr));
        label_3->setText(QCoreApplication::translate("About", "\321\207\320\265\321\200\320\265\320\267 \320\277\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\321\213\320\271 \320\277\320\276\321\200\321\202", nullptr));
        label_4->setText(QCoreApplication::translate("About", "\320\227\320\260\320\261\321\203\321\200\321\203\320\275\320\276\320\262 \320\233\320\265\320\276\320\275\320\270\320\264, \320\240\320\2425-61\320\221", nullptr));
        label_5->setText(QCoreApplication::translate("About", "\320\234\320\270\321\200\321\201\320\276\320\275\320\276\320\262 \320\222\321\217\321\207\320\265\321\201\320\273\320\260\320\262, \320\240\320\2425-61\320\221", nullptr));
        label_6->setText(QCoreApplication::translate("About", "\320\237\320\276\320\277\320\276\320\262\320\260 \320\224\320\260\321\200\321\214\321\217, \320\240\320\2425-61\320\221", nullptr));
        label_7->setText(QCoreApplication::translate("About", "\320\244\320\260\320\272\321\203\320\273\321\214\321\202\320\265\321\202: \320\240\320\260\320\264\320\270\320\276\321\202\320\265\321\205\320\275\320\270\321\207\320\265\321\201\320\272\320\270\320\271", nullptr));
        label_8->setText(QCoreApplication::translate("About", "\320\232\320\260\321\204\320\265\320\264\321\200\320\260: \320\241\320\270\321\201\321\202\320\265\320\274\321\213 \320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\270 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\320\270 \320\270 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217 (\320\230\320\2435)", nullptr));
        label_9->setText(QCoreApplication::translate("About", "2021 \320\263\320\276\320\264.", nullptr));
        OK_button->setText(QCoreApplication::translate("About", "\320\236\320\232", nullptr));
        label01->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
