#include "addnewdialog.h"
#include "ui_addnewdialog.h"

AddNewDialog::AddNewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewDialog)
{
    ui->setupUi(this);

    ui->input_person_sex->addItem("");
    ui->input_person_sex->addItem("Female");
    ui->input_person_sex->addItem("Male");

    ui->input_computer_type->addItem("");
    ui->input_computer_type->addItem("Electronic");
    ui->input_computer_type->addItem("Mechanical");
    ui->input_computer_type->addItem("Transistor");

    ui->input_computer_built->addItem("");
    ui->input_computer_built->addItem("Yes");
    ui->input_computer_built->addItem("No");

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

    if (ui->radioButton_new_person->isChecked())
    {
        int personSuccess = addNewPerson();
    }
    else if (ui->radioButton_new_computer->isChecked())
    {
        int computerSuccess = addNewComputer();
    }
    else if (ui->radioButton_both->isChecked())
    {
        int personSuccess = addNewPerson();
        int computerSuccess = addNewComputer();
    }
}

int AddNewDialog::addNewPerson()
{
    QString name = ui->input_person_name->text();
    QString sex = ui->input_person_sex->currentText();
    QString birth = ui->input_person_birth->text();
    QString death = ui->input_person_death->text();

    if (name.isEmpty() || sex.isEmpty() || birth.isEmpty())
    {
        //skila villu um hvad er ad
        return 2;
    }
    string sname = name.toStdString();
    string ssex = sex.toStdString();
    string sbirth = birth.toStdString();
    string sdeath = death.toStdString();

    if (domain.add(sname, ssex, sbirth, sdeath))
    {
        ui->input_person_name->setText("");
        ui->input_person_birth->setText("");
        ui->input_person_death->setText("");
        this->done(0);
    }
    else
    {
        // skila villu um ad ekki hafi tekist ad baeta vid personu
        this->done(1);
    }
}

int AddNewDialog::addNewComputer()
{
    QString name = ui->input_computer_name->text();
    QString year = ui->input_computer_year->text();
    QString type = ui->input_computer_type->currentText();
    QString built = ui->input_computer_built->currentText();

    if (name.isEmpty() || year.isEmpty() || type.isEmpty() || built.isEmpty())
    {
        //skila villu um hvad er ad
        return 2;
    }
    string sname = name.toStdString();
    string syear = year.toStdString();
    string stype = type.toStdString();
    string sbuilt = built.toStdString();


    if (domain.addComputer(sname, syear, stype, sbuilt))
    {
        ui->input_computer_name->setText("");
        ui->input_computer_year->setText("");
        this->done(0);
    }
    else
    {
        // skila villu um ad ekki hafi tekist ad baeta vid personu
        this->done(1);
    }
}
