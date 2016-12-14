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
void DialogEditComputer::on_pushButton_save_clicked()
{
    name = ui->txtNewName->text();
    year  = ui->txtNewYear->text();
    type = ui->comboBoxNewType->currentText();
    built = ui->comboBoxNewBuilt->currentText();
    string nName = name.toStdString();
    string nYear = year.toStdString();
    string nType = type.toStdString();
    string nBuilt = built.toStdString();

    domain.editComputer(id, nName, nYear, nType, nBuilt);
    done(1);
}

void DialogEditComputer::on_pushButton_cancel_clicked()
{
    done(0);
}
