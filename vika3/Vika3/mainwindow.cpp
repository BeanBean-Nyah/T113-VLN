#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    domain.openDatabase();
    ui->setupUi(this);

    ui->tblPersons->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tblComputers->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tblPersAndComp->setSelectionMode(QAbstractItemView::SingleSelection);

    displayAllPersons();
    displayAllComputers();
    displayAllPersAndComp();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAllPersons()
{
    string type = getPersonCurrentSortBy();
    vector<Person> pers = domain.sorting(type);
    displayPersons(pers);

    currentlyDisplayedPersons = pers;
}

void MainWindow::displayPersons(vector<Person> pers)
{
    ui->tblPersons->clearContents();

    ui->tblPersons->setRowCount(pers.size());

    for (unsigned int row = 0; row < pers.size(); row++)
    {
        Person currentPerson = pers.at(row);
        QString name = QString::fromStdString(currentPerson.getFirstname());
        QString sex = QString::fromStdString(currentPerson.getSex());
        QString birth = QString::fromStdString(currentPerson.getBirth());
        QString death = QString::fromStdString(currentPerson.getDeath());
        QString id = QString::fromStdString(currentPerson.getID());

        ui->tblPersons->setItem(row, 0, new QTableWidgetItem(name));
        ui->tblPersons->setItem(row, 1, new QTableWidgetItem(sex));
        ui->tblPersons->setItem(row, 2, new QTableWidgetItem(birth));
        ui->tblPersons->setItem(row, 3, new QTableWidgetItem(death));
        ui->tblPersons->setItem(row, 4, new QTableWidgetItem(id));

    }
}

void MainWindow::displayAllComputers()
{
    string type = getComputerCurrentSortBy();
    vector<Computer> comp = domain.sortComputer(type);
    displayComputers(comp);

    currentlyDisplayedComputers = comp;
}

void MainWindow::displayComputers(vector<Computer> comp)
{
    ui->tblComputers->clearContents();

    ui->tblComputers->setRowCount(comp.size());

    for (unsigned int row = 0; row < comp.size(); row++)
    {
        Computer currentComputer = comp.at(row);
        QString name = QString::fromStdString(currentComputer.getName());
        QString year = QString::fromStdString(currentComputer.getYear());
        QString type = QString::fromStdString(currentComputer.getType());
        QString built = QString::fromStdString(currentComputer.getBuilt());

        ui->tblComputers->setItem(row, 0, new QTableWidgetItem(name));
        ui->tblComputers->setItem(row, 1, new QTableWidgetItem(year));
        ui->tblComputers->setItem(row, 2, new QTableWidgetItem(type));
        ui->tblComputers->setItem(row, 3, new QTableWidgetItem(built));
    }
}

void MainWindow::displayAllPersAndComp()
{
    vector<PersAndComp> pAc = domain.persAndCompListTest();
    displayPersAndComp(pAc);
    currentlyDisplayedPersAndComp = pAc;
}

void MainWindow::displayPersAndComp(vector<PersAndComp> pAc)
{
    ui->tblPersAndComp->clearContents();

    ui->tblPersAndComp->setRowCount(pAc.size());

    for (unsigned int row = 0; row < pAc.size(); row++)
    {
        PersAndComp currentPaC = pAc.at(row);

        QString persName = QString::fromStdString(currentPaC.getPersName());
        QString compName = QString::fromStdString(currentPaC.getCompName());

        ui->tblPersAndComp->setItem(row, 0, new QTableWidgetItem(compName));
        ui->tblPersAndComp->setItem(row, 1, new QTableWidgetItem(persName));
    }
}

/*
void MainWindow::displayPersAndComp(vector<PersonsAndComputers> pAc)
{
    vector<Person> pers = domain.list();

    vector<Computer> comp = domain.computerList();

    ui->tblPersAndComp->clearContents();

    ui->tblPersAndComp->setRowCount(pAc.size());

    int row = 0;
    string id;
    for (unsigned int r = 0; r < comp.size(); r++)
    {
        Computer currentComputer = comp.at(r);
        QString compName = QString::fromStdString(currentComputer.getName());
        QString year = QString::fromStdString(currentComputer.getYear());
        QString built = QString::fromStdString(currentComputer.getType());

        ui->tblPersAndComp->setItem(row, 0, new QTableWidgetItem(compName));
        ui->tblPersAndComp->setItem(row, 2, new QTableWidgetItem(year));
        ui->tblPersAndComp->setItem(row, 3, new QTableWidgetItem(built));

        int t = 0;
        for (unsigned int k = 0; k < pAc.size(); k++)
        {
            if (comp[r].getID() == pAc[k].getComp_ID())
            {
                id = pAc[k].getPers_ID();
                for (unsigned int j = 0; j < pers.size(); j++)
                {
                    if (pers[j].getID() == id)
                    {
                        Person currentPerson = pers.at(j);

                        QString persName = QString::fromStdString(currentPerson.getFirstname());

                        ui->tblPersAndComp->setItem(row, 1, new QTableWidgetItem(persName));

                        if (row < comp.size())
                        {
                            row++;
                        }
                    }
                }
            }
            t++;
        }
    }
}
*/

string MainWindow::getPersonCurrentSortBy()
{
    string valueInOrderBy = ui->comboBox_person_sort->currentText().toStdString();

    if (valueInOrderBy == "Name" && ui->radioButton_person_sort_asc->isChecked())
    {
        return "nameasc";
    }
    else if (valueInOrderBy == "Name" && ui->radioButton_person_sort_desc->isChecked())
    {
        return "namedesc";
    }
    else if (valueInOrderBy == "Sex" && ui->radioButton_person_sort_asc->isChecked())
    {
        return "sexasc";
    }
    else if (valueInOrderBy == "Sex" && ui->radioButton_person_sort_desc->isChecked())
    {
        return "sexdesc";
    }
    else if (valueInOrderBy == "Birth year" && ui->radioButton_person_sort_asc->isChecked())
    {
        return "birthasc";
    }
    else if (valueInOrderBy == "Birth year" && ui->radioButton_person_sort_desc->isChecked())
    {
        return "birthdesc";
    }
    else if (valueInOrderBy == "Year of death" && ui->radioButton_person_sort_asc->isChecked())
    {
        return "deathasc";
    }
    else if (valueInOrderBy == "Year of death" && ui->radioButton_person_sort_desc->isChecked())
    {
        return "deathdesc";
    }
    else
    {
        return "nameasc";
    }

    return valueInOrderBy;
}

string MainWindow::getComputerCurrentSortBy()
{
    string valueInOrderBy = ui->comboBox_computer_sort->currentText().toStdString();

    if (valueInOrderBy == "Name" && ui->radioButton_computer_sort_asc->isChecked())
    {
        return "nameasc";
    }
    else if (valueInOrderBy == "Name" && ui->radioButton_computer_sort_desc->isChecked())
    {
        return "namedesc";
    }
    else if (valueInOrderBy == "Year" && ui->radioButton_computer_sort_asc->isChecked())
    {
        return "yearasc";
    }
    else if (valueInOrderBy == "Year" && ui->radioButton_computer_sort_desc->isChecked())
    {
        return "yeardesc";
    }
    else if (valueInOrderBy == "Type" && ui->radioButton_computer_sort_asc->isChecked())
    {
        return "typeasc";
    }
    else if (valueInOrderBy == "Type" && ui->radioButton_computer_sort_desc->isChecked())
    {
        return "typedesc";
    }
    else if (valueInOrderBy == "Built" && ui->radioButton_computer_sort_asc->isChecked())
    {
        return "builtasc";
    }
    else if (valueInOrderBy == "Built" && ui->radioButton_computer_sort_desc->isChecked())
    {
        return "builtdesc";
    }
    else
    {
        return "nameasc";
    }

    return valueInOrderBy;
}

void MainWindow::on_btnNew_clicked()
{
    AddNewDialog addNewDialog;
    int status = addNewDialog.exec();
    if (status == 0)
    {
        ui->statusBar->showMessage("Successfully added!", 2000);
    }
    else if (status == 1)
    {
        // error
    }
    ui->input_filter_person->setText("");
    ui->input_filter_computer->setText("");
    displayAllPersons();
    displayAllComputers();
    displayAllPersAndComp();
}

void MainWindow::on_btnDelete_clicked()
{
    int currentTabIndex = ui->tabWidget->currentIndex();
    if (currentTabIndex == 0)
    {
        int currentlySelected = ui->tblPersons->currentIndex().row();
        domain.remove(currentlyDisplayedPersons, currentlySelected);
        displayAllPersons();
        ui->btnDelete->setEnabled(false);
        ui->input_filter_computer->setText("");
    }
    else if (currentTabIndex == 1)
    {
        int currentlySelected = ui->tblComputers->currentIndex().row();
        domain.removeComputer(currentlyDisplayedComputers, currentlySelected);
        displayAllComputers();
        ui->btnDelete->setEnabled(false);
        ui->input_filter_computer->setText("");
    }

}

void MainWindow::on_tblComputers_clicked(const QModelIndex &index)
{        
    ui->btnDelete->setEnabled(true);
    ui->btnEdit->setEnabled(true);
}

void MainWindow::on_tblPersons_clicked(const QModelIndex &index)
{
    ui->btnDelete->setEnabled(true);
    ui->btnEdit->setEnabled(true);
}

void MainWindow::on_input_filter_person_textChanged(const QString &arg1)
{
    if (ui->tblPersons->isActiveWindow())
    {
        const string&& filterInput = ui->input_filter_person->text().toStdString();
        string sort = getPersonCurrentSortBy();
        vector<Person> pers = domain.search(sort, filterInput);
        currentlyDisplayedPersons = pers;
        displayPersons(pers);
    }
}

void MainWindow::on_input_filter_computer_textChanged(const QString &arg1)
{
    if (ui->tblComputers->isActiveWindow())
    {
        const string&& filterInput = ui->input_filter_computer->text().toStdString();
        string sort = getComputerCurrentSortBy();
        vector<Computer> comp = domain.searchComputer(sort, filterInput);
        currentlyDisplayedComputers = comp;
        displayComputers(comp);
    }
}

void MainWindow::on_btnEdit_clicked()
{
    int currentTabIndex = ui->tabWidget->currentIndex();
    if(currentTabIndex == 0)
    {
        int currentlySelected = ui->tblPersons->currentIndex().row();
        string name, sex, birth, death, id;
        name = currentlyDisplayedPersons[currentlySelected].getFirstname();
        sex = currentlyDisplayedPersons[currentlySelected].getSex();
        birth = currentlyDisplayedPersons[currentlySelected].getBirth();
        death = currentlyDisplayedPersons[currentlySelected].getDeath();
        id = currentlyDisplayedPersons[currentlySelected].getID();

        dialogEdit newdialogEdit;
        newdialogEdit.setTextbox(name, sex, birth, death, id);
        int status = newdialogEdit.exec();

        if (status == 0)
        {

        }
        else if (status == 1)
        {

        }

    }
    else if (currentTabIndex == 1)
    {
        int currentlySelected = ui->tblComputers->currentIndex().row();
        string name, year, type, built, id;
        name = currentlyDisplayedComputers[currentlySelected].getName();
        year = currentlyDisplayedComputers[currentlySelected].getYear();
        type = currentlyDisplayedComputers[currentlySelected].getType();
        built = currentlyDisplayedComputers[currentlySelected].getBuilt();
        id = currentlyDisplayedComputers[currentlySelected].getID();

        DialogEditComputer  newdialogEditComputer;
        newdialogEditComputer.setTextbox(name, year, type, built, id);
        int status = newdialogEditComputer.exec();
    }

    displayAllPersons();
    displayAllComputers();
    displayAllPersAndComp();
    ui->btnDelete->setEnabled(false);
    ui->btnEdit->setEnabled(false);
}



void MainWindow::on_radioButton_person_sort_asc_toggled(bool checked)
{
    displayAllPersons();
}


void MainWindow::on_radioButton_person_sort_desc_toggled(bool checked)
{
    displayAllPersons();
}

void MainWindow::on_actionNew_triggered()
{
        AddNewDialog addNewDialog;
        int status = addNewDialog.exec();
        if (status == 0)
        {
            ui->input_filter_person->setText("");
            ui->input_filter_computer->setText("");
            displayAllPersons();
            displayAllComputers();
        }
        else if (status == 1)
        {
            // error
        }
}

void MainWindow::on_comboBox_person_sort_currentIndexChanged(int index)
{
    on_input_filter_person_textChanged("");
}

void MainWindow::on_comboBox_computer_sort_currentIndexChanged(int index)
{
    on_input_filter_computer_textChanged("");
}

void MainWindow::on_radioButton_computer_sort_asc_toggled(bool checked)
{
    displayAllComputers();
}

void MainWindow::on_radioButton_computer_sort_desc_toggled(bool checked)
{
    displayAllComputers();
}




