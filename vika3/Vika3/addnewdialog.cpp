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
    clearErrors();
    QString computername = ui->input_computer_name->text();
    QString year = ui->input_computer_year->text();
    QString type = ui->input_computer_type->currentText();
    QString built = ui->input_computer_built->currentText();
    QString personname = ui->input_person_name->text();
    QString sex = ui->input_person_sex->currentText();
    QString birth = ui->input_person_birth->text();
    QString death = ui->input_person_death->text();

    string spersname = personname.toStdString();
    spersname = domain.capFirstLetter(spersname);
    string ssex = sex.toStdString();
    string sbirth = birth.toStdString();
    string sdeath = death.toStdString();
    string scompname = computername.toStdString();
    scompname = domain.capFirstLetter(scompname);
    string syear = year.toStdString();
    string stype = type.toStdString();
    string sbuilt = built.toStdString();

    if (ui->radioButton_new_person->isChecked())
    {
        int personSuccess = addNewPerson();
        if (personSuccess == 1)
        {
            if (domain.add(spersname, ssex, sbirth, sdeath))
            {
                ui->input_person_name->setText("");
                ui->input_person_birth->setText("");
                ui->input_person_death->setText("");
                ui->input_person_sex->setCurrentIndex(0);
                this->done(3);
            }
            else
            {
                ui->label_error_message->setText("This exact person already exists!");
            }
        }

    }
    else if (ui->radioButton_new_computer->isChecked())
    {
        int computerSuccess = addNewComputer();
        if (computerSuccess == 1)
        {
            if (domain.addComputer(scompname, syear, stype, sbuilt))
            {
                ui->input_computer_name->setText("");
                ui->input_computer_year->setText("");
                ui->input_computer_type->setCurrentIndex(0);
                ui->input_computer_built->setCurrentIndex(0);
                this->done(4);
            }
        }
        else
        {
            ui->label_error_message->setText("This exact computer already exists!");
        }
    }
    else if (ui->radioButton_both->isChecked())
    {
        int personSuccess = addNewPerson();
        int computerSuccess = addNewComputer();

        if (personSuccess == 1 && computerSuccess == 1)
        {
            if (domain.add(spersname, ssex, sbirth, sdeath))
            {
                if (domain.addComputer(scompname, syear, stype, sbuilt))
                {
                    ui->input_person_name->setText("");
                    ui->input_person_birth->setText("");
                    ui->input_person_death->setText("");
                    ui->input_person_sex->setCurrentIndex(0);
                    ui->input_computer_name->setText("");
                    ui->input_computer_year->setText("");
                    ui->input_computer_type->setCurrentIndex(0);
                    ui->input_computer_built->setCurrentIndex(0);
                }
                else
                {
                    vector<Person> pers = domain.list();
                    int line = pers.size() - 1;
                    domain.remove(pers, line);
                    ui->label_error_message->setText("This exact computer already exists!");
                    return;
                }
            }
            else
            {
                ui->label_error_message->setText("This exact person already exists!");
                return;
            }

            vector<Person> pers = domain.list();
            vector<Computer> comp = domain.computerList();

            string persID = pers[(pers.size()-1)].getID();
            string compID = comp[(comp.size()-1)].getID();

            if (domain.connectPtoC(persID, compID))
            {
                done(5);
            }
        }
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
        ui->label_error_message->setText("Entries marked red * with can not be empty!");
        if (name.isEmpty())
        {
            ui->label_error_person_name->setText("<span style = 'color: red'>*");
        }
        if (sex.isEmpty())
        {
            ui->label_error_person_sex->setText("<span style = 'color: red'>*");
        }
        if (birth.isEmpty())
        {
            ui->label_error_person_birth->setText("<span style = 'color: red'>*");
        }
        return 2;
    }

    string sname = name.toStdString();
    sname = domain.capFirstLetter(sname);
    string ssex = sex.toStdString();
    string sbirth = birth.toStdString();
    string sdeath = death.toStdString();

    if (domain.contains_number(sname))
    {
        ui->label_error_message->setText("Name can not contain numbers!");
        return 2;
    }

    if (domain.contains_letters(sbirth) || domain.contains_letters(sdeath))
    {
        ui->label_error_message->setText("Year of birth and death can not contain letters");
        return 2;
    }
    if (atoi(sbirth.c_str()) > 2016 || atoi(sdeath.c_str()) > 2016)
    {
        ui->label_error_message->setText("Year of birth and death can not be in the future!");
        return 2;
    }

    if (atoi(sbirth.c_str()) > atoi(sdeath.c_str()) && sdeath != "")
    {
        ui->label_error_message->setText("Persons can not be born after they die!");
        return 2;
    }

    return 1;
}

int AddNewDialog::addNewComputer()
{
    QString name = ui->input_computer_name->text();
    QString year = ui->input_computer_year->text();
    QString type = ui->input_computer_type->currentText();
    QString built = ui->input_computer_built->currentText();

    if (name.isEmpty() || type.isEmpty() || built.isEmpty())
    {
        //skila villu um hvad er ad

        ui->label_error_message->setText("Entries marked red * with can not be empty!");
        if (name.isEmpty())
        {
            ui->label_error_computer_name->setText("<span style = 'color: red'>*");
        }
        if (type.isEmpty())
        {
            ui->label_error_computer_type->setText("<span style = 'color: red'>*");
        }
        if (built.isEmpty())
        {
            ui->label_error_computer_built->setText("<span style = 'color: red'>*");
        }
        return 2;
    }
    string sname = name.toStdString();
    sname = domain.capFirstLetter(sname);
    string syear = year.toStdString();
    string stype = type.toStdString();
    string sbuilt = built.toStdString();

    if (domain.contains_letters(syear))
    {
        ui->label_error_message->setText("Year can not contain letters!");
        return 2;
    }
    if (sbuilt == "Yes" && syear.empty())
    {
        ui->label_error_message->setText("The computer must have been built some year!");
        return 2;
    }
    if (sbuilt == "No" && !(syear.empty()))
    {
        ui->label_error_message->setText("If the compter has some year it must have been built!");
        return 2;
    }
    if (atoi(syear.c_str()) > 2016)
    {
        ui->label_error_message->setText("The computer cant be built in the future!");
        return 2;
    }

    return 1;
}

void AddNewDialog::clearErrors()
{
    ui->label_error_message->setText("");
    ui->label_error_person_name->setText("");
    ui->label_error_person_birth->setText("");
    ui->label_error_person_sex->setText("");
    ui->label_error_computer_type->setText("");
    ui->label_error_computer_built->setText("");
    ui->label_error_computer_year->setText("");
    ui->label_error_computer_name->setText("");
}

