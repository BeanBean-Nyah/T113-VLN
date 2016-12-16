#include "dialogedit.h"
#include "ui_dialogedit.h"

dialogEdit::dialogEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogEdit)
{
    ui->setupUi(this);
    ui->txtNewGender->addItem("Female");
    ui->txtNewGender->addItem("Male");
}

dialogEdit::~dialogEdit()
{
    delete ui;
}

//fyllir upp i texaboxin med videigandi upplysingum
void dialogEdit::setTextbox(string& _name, string& _sex, string& _birth, string& _death, string& _ID)
{
    name = QString::fromStdString(_name);
    sex  = QString::fromStdString(_sex);
    birth = QString::fromStdString(_birth);
    death = QString::fromStdString(_death);
    id = _ID;
    int currentSexIndex = 0;
    if (sex == "Female")
    {
        currentSexIndex = 1;
    }
    else if (sex == "Male")
    {
        currentSexIndex = 2;
    }

    ui->txtNewName->setText(name);
    ui->txtNewGender->setCurrentIndex(currentSexIndex);
    ui->txtNewBirth->setText(birth);
    ui->txtNewDeath->setText(death);

}

//villucheckar input og skilar videigandi skilabodum
void dialogEdit::on_buttonBox_accepted()
{
    //set new values
    name = ui->txtNewName->text();
    sex  = ui->txtNewGender->currentText();
    birth = ui->txtNewBirth->text();
    death = ui->txtNewDeath->text();
    string nName = name.toStdString();
    nName = domain.capFirstLetter(nName);
    string nSex = sex.toStdString();
    string nBirth = birth.toStdString();
    string nDeath = death.toStdString();

    if (name.isEmpty() || sex.isEmpty() || birth.isEmpty())
    {
        //Name, sex or birth can't be empty!
        done(2);
        return;
    }

    if (domain.contains_number(nName))
    {
        //Name can not contain numbers!
        done(3);
        return;
    }

    if (domain.contains_letters(nBirth) || domain.contains_letters(nDeath))
    {
        //Year of birth and death can not contain letters
        done(4);
        return;
    }

    if (atoi(nBirth.c_str()) > 2016 || atoi(nDeath.c_str()) > 2016)
    {
        //Year of birth and death can not be in the future!
        done(5);
        return;
    }

    if (atoi(nBirth.c_str()) > atoi(nDeath.c_str()) && nDeath != "")
    {
        //Persons can not be born after they die!
        done(6);
        return;
    }


    if (domain.edit(id, nName, nSex, nBirth, nDeath))
    {
        done(1);
    }
    else
    {
        done(0);
    }

    //return new values

}
