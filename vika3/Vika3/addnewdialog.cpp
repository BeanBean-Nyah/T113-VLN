#include "addnewdialog.h"
#include "ui_addnewdialog.h"

AddNewDialog::AddNewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewDialog)
{
    ui->setupUi(this);
}

AddNewDialog::~AddNewDialog()
{
    delete ui;
}
