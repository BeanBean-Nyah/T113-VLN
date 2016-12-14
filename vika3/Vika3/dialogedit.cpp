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
void dialogEdit::setTextbox(string& _name, string& _sex, string& _birth, string& _death, string& _ID)
{
    name = QString::fromStdString(_name);
    sex  = QString::fromStdString(_sex);
    birth = QString::fromStdString(_birth);
    death = QString::fromStdString(_death);
    id = _ID;

    ui->txtNewName->setText(name);
    ui->txtNewGender->setText(sex);
    ui->txtNewBirth->setText(birth);
    ui->txtNewDeath->setText(death);

}

void dialogEdit::on_buttonBox_accepted() // todo a check for input errors
{
    //set new values
    name = ui->txtNewName->text();
    sex  = ui->txtNewGender->text();
    birth = ui->txtNewBirth->text();
    death = ui->txtNewDeath->text();
    string nName = name.toStdString();
    string nSex = sex.toStdString();
    string nBirth = birth.toStdString();
    string nDeath = death.toStdString();
    Domain d;
    d.edit(id, nName, nSex, nBirth, nDeath);
    //return new values

}
