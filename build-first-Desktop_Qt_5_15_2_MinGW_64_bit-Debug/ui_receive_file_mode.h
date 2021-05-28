/********************************************************************************
** Form generated from reading UI file 'receive_file_mode.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVE_FILE_MODE_H
#define UI_RECEIVE_FILE_MODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Recieve_file_mode
{
public:
    QPushButton *Soglsie_to_recieve_file_button;
    QGroupBox *groupBox;
    QProgressBar *Recieving_progressBar;
    QPushButton *Save_recieved_file_button;

    void setupUi(QDialog *Recieve_file_mode)
    {
        if (Recieve_file_mode->objectName().isEmpty())
            Recieve_file_mode->setObjectName(QString::fromUtf8("Recieve_file_mode"));
        Recieve_file_mode->resize(760, 483);
        Soglsie_to_recieve_file_button = new QPushButton(Recieve_file_mode);
        Soglsie_to_recieve_file_button->setObjectName(QString::fromUtf8("Soglsie_to_recieve_file_button"));
        Soglsie_to_recieve_file_button->setGeometry(QRect(150, 100, 391, 61));
        groupBox = new QGroupBox(Recieve_file_mode);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(110, 190, 501, 61));
        groupBox->setFlat(false);
        Recieving_progressBar = new QProgressBar(groupBox);
        Recieving_progressBar->setObjectName(QString::fromUtf8("Recieving_progressBar"));
        Recieving_progressBar->setGeometry(QRect(10, 20, 471, 21));
        Recieving_progressBar->setValue(0);
        Save_recieved_file_button = new QPushButton(Recieve_file_mode);
        Save_recieved_file_button->setObjectName(QString::fromUtf8("Save_recieved_file_button"));
        Save_recieved_file_button->setEnabled(false);
        Save_recieved_file_button->setGeometry(QRect(232, 280, 221, 28));

        retranslateUi(Recieve_file_mode);

        QMetaObject::connectSlotsByName(Recieve_file_mode);
    } // setupUi

    void retranslateUi(QDialog *Recieve_file_mode)
    {
        Recieve_file_mode->setWindowTitle(QCoreApplication::translate("Recieve_file_mode", "\320\240\320\265\320\266\320\270\320\274 \320\277\320\276\320\273\321\203\321\207\320\265\320\275\320\270\321\217", nullptr));
        Soglsie_to_recieve_file_button->setText(QCoreApplication::translate("Recieve_file_mode", "\320\235\320\260\320\266\320\274\320\270", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Recieve_file_mode", "\320\237\320\276\320\273\321\203\321\207\320\265\320\275\320\270\320\265 \321\204\320\260\320\271\320\273\320\260", nullptr));
        Recieving_progressBar->setFormat(QCoreApplication::translate("Recieve_file_mode", "%p%", "2"));
        Save_recieved_file_button->setText(QCoreApplication::translate("Recieve_file_mode", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\204\320\260\320\271\320\273...", nullptr));
    } // retranslateUi

};

namespaceReceive_file_modeecieve_file_mode: public Ui_Recieve_file_mode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVE_FILE_MODE_H
