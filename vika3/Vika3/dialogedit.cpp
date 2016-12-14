#include "dialogedit.h"
#include "ui_dialogedit.h"

dialogEdit::dialogEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogEdit)
{
    ui->setupUi(this);
}

dialogEdit::~dialogEdit()
{
    delete ui;
}
void dialogEdit::setTextbox(string& _name, string& _sex, string& _birth, string& _death)
{
    name = QString::fromStdString(_name);
    sex  = QString::fromStdString(_sex);
    birth = QString::fromStdString(_birth);
    death = QString::fromStdString(_death);

    ui->txtNewName->setText(name);
    ui->txtNewGender->setText(sex);
    ui->txtNewBirth->setText(birth);
    ui->txtNewDeath->setText(death);

    on_buttonBox_accepted();
    _name = ui->txtNewName->text().toStdString();

    _sex  = ui->txtNewGender->text().toStdString();
    _birth = ui->txtNewBirth->text().toStdString();
    _death = ui->txtNewDeath->text().toStdString();
}

void dialogEdit::on_buttonBox_accepted() // todo a check for input errors
{
    //set new values
    name = ui->txtNewName->text();
    sex  = ui->txtNewGender->text();
    birth = ui->txtNewBirth->text();
    death = ui->txtNewDeath->text();
    //return new values

}
