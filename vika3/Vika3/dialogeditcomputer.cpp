#include "dialogeditcomputer.h"
#include "ui_dialogeditcomputer.h"

DialogEditComputer::DialogEditComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditComputer)
{
    ui->setupUi(this);

}

DialogEditComputer::~DialogEditComputer()
{
    delete ui;
}

//fyllir upp i texaboxin med videigandi upplysingum
void DialogEditComputer::setTextbox(string& _name, string& _year, string& _type, string& _built, string& _ID)
{
    name = QString::fromStdString(_name);
    year  = QString::fromStdString(_year);
    type = QString::fromStdString(_type);
    built = QString::fromStdString(_built);
    id = _ID;

    int typeIndex, builtIndex;
    if (_type == "Electronic")
    {
        typeIndex = 0;
    }
    else if (_type == "Mechanical")
    {
        typeIndex = 1;
    }
    else if (_type == "Transistor")
    {
        typeIndex = 2;
    }

    if (_built == "Yes")
    {
        builtIndex = 0;
    }
    else if (_built == "No")
    {
        builtIndex = 1;
    }

    ui->txtNewName->setText(name);
    ui->txtNewYear->setText(year);
    ui->comboBoxNewType->setCurrentIndex(typeIndex);
    ui->comboBoxNewBuilt->setCurrentIndex(builtIndex);

}

//villucheckar input og skilar videigandi skilabodum
void DialogEditComputer::on_pushButton_save_clicked()
{
    name = ui->txtNewName->text();
    year  = ui->txtNewYear->text();
    type = ui->comboBoxNewType->currentText();
    built = ui->comboBoxNewBuilt->currentText();
    string nName = name.toStdString();
    nName = domain.capFirstLetter(nName);
    string nYear = year.toStdString();
    string nType = type.toStdString();
    string nBuilt = built.toStdString();

    if (name.isEmpty() || type.isEmpty() || built.isEmpty())
    {
        //Name, type and built cant be empty!
        done(2);
    }
    if (domain.contains_letters(nYear))
    {
        //Year can not contain letters!
        done(3);
        return;
    }
    if (nBuilt == "Yes" && nYear.empty())
    {
        //The computer must have been built some year!
        done(4);
        return;
    }
    if (atoi(nYear.c_str()) > 2016)
    {
        //The computer cant be built in the future!
        done(5);
        return;
    }
    if (nBuilt == "No" && !(nYear.empty()))
    {
        //If the compter has some year it must have been built!
        done(6);
        return;
    }

    if (domain.editComputer(id, nName, nYear, nType, nBuilt))
    {
        done(1);
    }

    else
    {
        done(0);
    }

}

//lokar glugga
void DialogEditComputer::on_pushButton_cancel_clicked()
{
    done(0);
}
