#ifndef RECIEVE_FILE_MODE_H
#define RECIEVE_FILE_MODE_H

#include <QDialog>

namespace Ui {
class Recieve_file_mode;
}

class Recieve_file_mode : public QDialog
{
    Q_OBJECT

public:
    explicit Recieve_file_mode(QWidget *parent = nullptr);
    ~Recieve_file_mode();

private:
    Ui::Recieve_file_mode *ui;
};

#endif // RECIEVE_FILE_MODE_H
