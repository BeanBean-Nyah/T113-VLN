#ifndef ADDNEWDIALOG_H
#define ADDNEWDIALOG_H

#include <QDialog>

namespace Ui {
class AddNewDialog;
}

class AddNewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewDialog(QWidget *parent = 0);
    ~AddNewDialog();

private:
    Ui::AddNewDialog *ui;
};

#endif // ADDNEWDIALOG_H
