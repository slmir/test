/********************************************************************************
** Form generated from reading UI file 'recieve_file_mode.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECIEVE_FILE_MODE_H
#define UI_RECIEVE_FILE_MODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Recieve_file_mode
{
public:
    QPushButton *Soglsie_to_recieve_file_button;
    QGroupBox *Save_file_gropubox;
    QPushButton *Save_file_button;
    QLineEdit *File_directory_choosed;
    QLabel *Save_file_label;
    QPushButton *Open_folder_dialog_button;
    QLineEdit *File_name_input;
    QPushButton *Check_file_name_button;
    QLabel *Save_file_label_2;

    void setupUi(QDialog *Recieve_file_mode)
    {
        if (Recieve_file_mode->objectName().isEmpty())
            Recieve_file_mode->setObjectName(QString::fromUtf8("Recieve_file_mode"));
        Recieve_file_mode->resize(760, 483);
        Soglsie_to_recieve_file_button = new QPushButton(Recieve_file_mode);
        Soglsie_to_recieve_file_button->setObjectName(QString::fromUtf8("Soglsie_to_recieve_file_button"));
        Soglsie_to_recieve_file_button->setGeometry(QRect(160, 20, 391, 61));
        Save_file_gropubox = new QGroupBox(Recieve_file_mode);
        Save_file_gropubox->setObjectName(QString::fromUtf8("Save_file_gropubox"));
        Save_file_gropubox->setGeometry(QRect(10, 110, 731, 251));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        Save_file_gropubox->setFont(font);
        Save_file_gropubox->setFlat(false);
        Save_file_button = new QPushButton(Save_file_gropubox);
        Save_file_button->setObjectName(QString::fromUtf8("Save_file_button"));
        Save_file_button->setEnabled(false);
        Save_file_button->setGeometry(QRect(500, 210, 211, 28));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setWeight(50);
        Save_file_button->setFont(font1);
        File_directory_choosed = new QLineEdit(Save_file_gropubox);
        File_directory_choosed->setObjectName(QString::fromUtf8("File_directory_choosed"));
        File_directory_choosed->setEnabled(true);
        File_directory_choosed->setGeometry(QRect(20, 60, 591, 31));
        File_directory_choosed->setReadOnly(false);
        File_directory_choosed->setClearButtonEnabled(false);
        Save_file_label = new QLabel(Save_file_gropubox);
        Save_file_label->setObjectName(QString::fromUtf8("Save_file_label"));
        Save_file_label->setGeometry(QRect(20, 30, 111, 16));
        Save_file_label->setFont(font1);
        Open_folder_dialog_button = new QPushButton(Save_file_gropubox);
        Open_folder_dialog_button->setObjectName(QString::fromUtf8("Open_folder_dialog_button"));
        Open_folder_dialog_button->setGeometry(QRect(620, 60, 91, 31));
        Open_folder_dialog_button->setFont(font1);
        File_name_input = new QLineEdit(Save_file_gropubox);
        File_name_input->setObjectName(QString::fromUtf8("File_name_input"));
        File_name_input->setEnabled(true);
        File_name_input->setGeometry(QRect(20, 160, 521, 31));
        File_name_input->setReadOnly(false);
        File_name_input->setClearButtonEnabled(false);
        Check_file_name_button = new QPushButton(Save_file_gropubox);
        Check_file_name_button->setObjectName(QString::fromUtf8("Check_file_name_button"));
        Check_file_name_button->setGeometry(QRect(580, 160, 131, 31));
        Check_file_name_button->setFont(font1);
        Save_file_label_2 = new QLabel(Save_file_gropubox);
        Save_file_label_2->setObjectName(QString::fromUtf8("Save_file_label_2"));
        Save_file_label_2->setGeometry(QRect(20, 120, 191, 16));
        Save_file_label_2->setFont(font1);

        retranslateUi(Recieve_file_mode);

        QMetaObject::connectSlotsByName(Recieve_file_mode);
    } // setupUi

    void retranslateUi(QDialog *Recieve_file_mode)
    {
        Recieve_file_mode->setWindowTitle(QCoreApplication::translate("Recieve_file_mode", "\320\240\320\265\320\266\320\270\320\274 \320\277\320\276\320\273\321\203\321\207\320\265\320\275\320\270\321\217", nullptr));
        Soglsie_to_recieve_file_button->setText(QCoreApplication::translate("Recieve_file_mode", "\320\235\320\260\320\266\320\274\320\270", nullptr));
        Save_file_gropubox->setTitle(QCoreApplication::translate("Recieve_file_mode", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        Save_file_button->setText(QCoreApplication::translate("Recieve_file_mode", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        Save_file_label->setText(QCoreApplication::translate("Recieve_file_mode", "\320\243\320\272\320\260\320\266\320\270\321\202\320\265 \320\277\321\203\321\202\321\214:", nullptr));
        Open_folder_dialog_button->setText(QCoreApplication::translate("Recieve_file_mode", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214...", nullptr));
        Check_file_name_button->setText(QCoreApplication::translate("Recieve_file_mode", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", nullptr));
        Save_file_label_2->setText(QCoreApplication::translate("Recieve_file_mode", "\320\243\320\272\320\260\320\266\320\270\321\202\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\204\320\260\320\271\320\273\320\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Recieve_file_mode: public Ui_Recieve_file_mode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECIEVE_FILE_MODE_H
