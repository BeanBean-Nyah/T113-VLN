#include "addnewcomputerdialog.h"
#include "ui_addnewcomputerdialog.h"

addNewComputerDialog::addNewComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addNewComputerDialog)
{
    ui->setupUi(this);
}

addNewComputerDialog::~addNewComputerDialog()
{
    delete ui;
}
