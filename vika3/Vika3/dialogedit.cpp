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
void dialogEdit::setTextbox(string& _id, string& _name, string& _sex, string& _birth, string& _death)
{
    name = QString::fromStdString(_name);
    sex  = QString::fromStdString(_sex);
    birth = QString::fromStdString(_birth);
    death = QString::fromStdString(_death);
    id = QString::fromStdString(_id);

    ui->txtNewName->setText(name);
    ui->txtNewGender->setText(sex);
    ui->txtNewBirth->setText(birth);
    ui->txtNewDeath->setText(death);

}

void dialogEdit::on_buttonBox_accepted() // todo a check for input errors
{
    //set new values
    string _name, _sex, _birth, _death;
    _name = ui->txtNewName->text().toStdString();
    _sex  = ui->txtNewGender->text().toStdString();
    _birth = ui->txtNewBirth->text().toStdString();
    _death = ui->txtNewDeath->text().toStdString();

    //return new values

}
