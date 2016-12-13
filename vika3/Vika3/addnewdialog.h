#ifndef ADDNEWDIALOG_H
#define ADDNEWDIALOG_H

#include "Domain.h"

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class AddNewDialog;
}

class AddNewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewDialog(QWidget *parent = 0);
    ~AddNewDialog();

private slots:


    void on_radioButton_new_person_toggled(bool checked);

    void on_radioButton_new_computer_toggled(bool checked);

    void on_radioButton_both_toggled(bool checked);

    void on_pushButton_clicked();

private:
    Ui::AddNewDialog *ui;
    Domain domain;

    int addNewPerson();
    int addNewComputer();
};

#endif // ADDNEWDIALOG_H
