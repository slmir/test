#ifndef ABOUT_1_H
#define ABOUT_1_H

#include <QDialog>

namespace Ui {
class about_1;
}

class about_1 : public QDialog
{
    Q_OBJECT

public:
    explicit about_1(QWidget *parent = nullptr);
    ~about_1();

private slots:
    void on_OK_button_clicked();

private:
    Ui::about_1 *ui;
};

#endif // ABOUT_1_H
