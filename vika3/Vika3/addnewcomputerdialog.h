#ifndef ADDNEWCOMPUTERDIALOG_H
#define ADDNEWCOMPUTERDIALOG_H

#include <QDialog>

namespace Ui {
class addNewComputerDialog;
}

class addNewComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addNewComputerDialog(QWidget *parent = 0);
    ~addNewComputerDialog();

private:
    Ui::addNewComputerDialog *ui;
};

#endif // ADDNEWCOMPUTERDIALOG_H
