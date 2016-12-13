#include "addnewdialog.h"
#include "ui_addnewdialog.h"

AddNewDialog::AddNewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewDialog)
{
    ui->setupUi(this);

    ui->input_person_sex->addItem("Female");
    ui->input_person_sex->addItem("Male");

    ui->input_computer_type->addItem("Electronic");
    ui->input_computer_type->addItem("Mechanical");
    ui->input_computer_type->addItem("Transistor");

}

AddNewDialog::~AddNewDialog()
{
    delete ui;
}



void AddNewDialog::on_radioButton_new_person_toggled(bool checked)
{
    if(checked)
    {
        ui->input_person_name->setEnabled(true);
        ui->input_person_sex->setEnabled(true);
        ui->input_person_birth->setEnabled(true);
        ui->input_person_death->setEnabled(true);
    }
    else
    {
        ui->input_person_name->setEnabled(false);
        ui->input_person_sex->setEnabled(false);
        ui->input_person_birth->setEnabled(false);
        ui->input_person_death->setEnabled(false);
    }
}



void AddNewDialog::on_radioButton_new_computer_toggled(bool checked)
{
    if(checked)
    {
        ui->input_computer_name->setEnabled(true);
        ui->input_computer_year->setEnabled(true);
        ui->input_computer_type->setEnabled(true);
        ui->input_computer_built->setEnabled(true);
    }
    else
    {
        ui->input_computer_name->setEnabled(false);
        ui->input_computer_year->setEnabled(false);
        ui->input_computer_type->setEnabled(false);
        ui->input_computer_built->setEnabled(false);
    }
}

void AddNewDialog::on_radioButton_both_toggled(bool checked)
{
    if(checked)
    {
        on_radioButton_new_computer_toggled(true);
        on_radioButton_new_person_toggled(true);
    }
    else
    {
        on_radioButton_new_computer_toggled(false);
        on_radioButton_new_person_toggled(false);
    }
}

void AddNewDialog::on_pushButton_clicked()
{
    QString name = ui->input_person_name->text();
    //QString sex = ui->input_person_sex->text();
    QString birth = ui->input_person_birth->text();
    QString death = ui->input_person_death->text();

    if (name.isEmpty() || birth.isEmpty() || death.isEmpty())
    {
        //do nothing
        return;
    }
    string sex = "male";
    string sname = name.toStdString();
    string sbirth = birth.toStdString();
    string sdeath = death.toStdString();
    Domain d;

    if (d.add(sname, sex, sbirth, sdeath))
    {
        ui->input_person_name->setText("");
        ui->input_person_birth->setText("");
        ui->input_person_death->setText("");
        this->done(0);
    }
    else
    {
        this->done(1);
    }


}
