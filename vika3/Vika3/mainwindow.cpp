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
    string type = getBothCurrentSortBy();
    vector<PersAndComp> pAc = domain.sortBoth(type);
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

string MainWindow::getBothCurrentSortBy()
{
    string valueInOrderBy = ui->comboBox_sort_both->currentText().toStdString();

    if (valueInOrderBy == "Computers" && ui->radioButton_sort_both_asc->isChecked())
    {
        return "computersasc";
    }
    else if (valueInOrderBy == "Computers" && ui->radioButton_sort_both_desc->isChecked())
    {
        return "computersdesc";
    }
    else if (valueInOrderBy == "Creators" && ui->radioButton_sort_both_asc->isChecked())
    {
        return "creatorsasc";
    }
    else if (valueInOrderBy == "Creators" && ui->radioButton_sort_both_desc->isChecked())
    {
        return "creatorsdesc";
    }
    else
    {
        return "computersasc";
    }

    return valueInOrderBy;
}

void MainWindow::on_btnNew_clicked()
{
    int currentTabIndex = ui->tabWidget->currentIndex();
    if (currentTabIndex == 0 || currentTabIndex == 1)
    {
        AddNewDialog addNewDialog;
        int status = addNewDialog.exec();
        if (status == 3)
        {
            ui->statusBar->showMessage("Successfully added new person!", 3000);
        }
        else if (status == 4)
        {
            ui->statusBar->showMessage("Successfully added new computer!", 3000);
        }
        else if (status == 5)
        {
            ui->statusBar->showMessage("Successfully added new person and computer!", 3000);
        }
        else if (status == 2)
        {
            // error
        }
    }
    else if (currentTabIndex == 2)
    {
        DialogNewRelation dialogNewRelation;
        int status = dialogNewRelation.exec();
        if (status == 1)
        {
            ui->statusBar->showMessage("Successfully added new relaiton!", 3000);
        }
        else if (status == 2)
        {
            ui->statusBar->showMessage("This exact relation already exists!", 3000);
        }
    }
    ui->input_filter_both->setText("");
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
        ui->btnMoreInfo->setEnabled(false);
        ui->btnDelete->setEnabled(false);
        ui->btnEdit->setEnabled(false);
        ui->actionEdit->setEnabled(false);
        ui->actionRemove->setEnabled(false);
        ui->input_filter_computer->setText("");
    }
    else if (currentTabIndex == 1)
    {
        int currentlySelected = ui->tblComputers->currentIndex().row();
        domain.removeComputer(currentlyDisplayedComputers, currentlySelected);
        displayAllComputers();
        ui->btnMoreInfo->setEnabled(false);
        ui->btnDelete->setEnabled(false);
        ui->btnEdit->setEnabled(false);
        ui->actionEdit->setEnabled(false);
        ui->actionRemove->setEnabled(false);
        ui->input_filter_computer->setText("");
    }
    else if (currentTabIndex == 2)
    {
        int currentlySelected = ui->tblPersAndComp->currentIndex().row();
        domain.removeConnection(currentlyDisplayedPersAndComp, currentlySelected);
        displayAllPersAndComp();
        ui->btnMoreInfo->setEnabled(false);
        ui->btnDelete->setEnabled(false);
        ui->btnEdit->setEnabled(false);
        ui->actionEdit->setEnabled(false);
        ui->actionRemove->setEnabled(false);
        ui->input_filter_both->setText("");
    }

}

void MainWindow::on_tblComputers_clicked(const QModelIndex &index)
{        
    ui->btnMoreInfo->setEnabled(true);
    ui->btnDelete->setEnabled(true);
    ui->btnEdit->setEnabled(true);
    ui->actionEdit->setEnabled(true);
    ui->actionRemove->setEnabled(true);
}

void MainWindow::on_tblPersons_clicked(const QModelIndex &index)
{
    ui->btnMoreInfo->setEnabled(true);
    ui->btnDelete->setEnabled(true);
    ui->btnEdit->setEnabled(true);
    ui->actionEdit->setEnabled(true);
    ui->actionRemove->setEnabled(true);
}

void MainWindow::on_tblPersAndComp_clicked(const QModelIndex &index)
{
    ui->btnMoreInfo->setEnabled(false);
    ui->btnDelete->setEnabled(true);
    ui->btnEdit->setEnabled(false);
    ui->actionEdit->setEnabled(false);
    ui->actionRemove->setEnabled(true);
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

void MainWindow::on_input_filter_both_textChanged(const QString &arg1)
{
    if (ui->tblPersAndComp->isActiveWindow())
    {
        const string&& filterInput = ui->input_filter_both->text().toStdString();
        string sort = getBothCurrentSortBy();
        vector<PersAndComp> pAc = domain.searchBoth(sort, filterInput);
        currentlyDisplayedPersAndComp = pAc;
        displayPersAndComp(pAc);
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
            ui->statusBar->showMessage("This exact person already exists!", 3000);
        }
        else if (status == 1)
        {
            ui->statusBar->showMessage("Successfully edited a person!", 3000);
        }
        else if (status == 2)
        {
            ui->statusBar->showMessage("Name, sex or birth can't be empty!", 3000);
        }
        else if (status == 3)
        {
            ui->statusBar->showMessage("Name can not contain numbers!", 3000);
        }
        else if (status == 4)
        {
            ui->statusBar->showMessage("Year of birth and death can not contain letters!", 3000);
        }
        else if (status == 5)
        {
            ui->statusBar->showMessage("Year of birth and death can not be in the future!", 3000);
        }
        else if (status == 6)
        {
            ui->statusBar->showMessage("Persons can not be born after they die!", 3000);
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

        if (status == 0)
        {
            ui->statusBar->showMessage("This exact computer already exists!", 3000);
        }
        else if (status == 1)
        {
            ui->statusBar->showMessage("Successfully edited a computer!", 3000);
        }
        else if (status == 2)
        {
            ui->statusBar->showMessage("Name, type and built cant be empty!", 3000);
        }
        else if (status == 3)
        {
            ui->statusBar->showMessage("Year can not contain letters!", 3000);
        }
        else if (status == 4)
        {
            ui->statusBar->showMessage("The computer must have been built some year!", 3000);
        }
        else if (status == 5)
        {
            ui->statusBar->showMessage("The computer cant be built in the future!", 3000);
        }
        else if (status == 6)
        {
            ui->statusBar->showMessage("If the compter has some year it must have been built!", 3000);
        }
    }

    displayAllPersons();
    displayAllComputers();
    displayAllPersAndComp();
    ui->btnMoreInfo->setEnabled(false);
    ui->btnDelete->setEnabled(false);
    ui->btnEdit->setEnabled(false);
    ui->actionEdit->setEnabled(false);
    ui->actionRemove->setEnabled(false);
}

void MainWindow::on_actionNew_triggered()
{
    on_btnNew_clicked();
}

void MainWindow::on_comboBox_person_sort_currentIndexChanged(int index)
{
    on_input_filter_person_textChanged("");
}

void MainWindow::on_radioButton_person_sort_asc_toggled(bool checked)
{
    on_input_filter_person_textChanged("");
}

void MainWindow::on_radioButton_person_sort_desc_toggled(bool checked)
{
    on_input_filter_person_textChanged("");
}

void MainWindow::on_comboBox_computer_sort_currentIndexChanged(int index)
{
    on_input_filter_computer_textChanged("");
}

void MainWindow::on_radioButton_computer_sort_asc_toggled(bool checked)
{
    on_input_filter_computer_textChanged("");
}

void MainWindow::on_radioButton_computer_sort_desc_toggled(bool checked)
{
    on_input_filter_computer_textChanged("");
}

void MainWindow::on_comboBox_sort_both_currentIndexChanged(int index)
{
    on_input_filter_both_textChanged("");
}

void MainWindow::on_radioButton_sort_both_asc_toggled(bool checked)
{
    on_input_filter_both_textChanged("");
}

void MainWindow::on_radioButton_sort_both_desc_toggled(bool checked)
{
    on_input_filter_both_textChanged("");
}

void MainWindow::on_actionAbout_triggered()
{
    DialogAbout about;
    about.exec();
}

void MainWindow::on_actionAbout_toggled(bool arg1)
{

}

void MainWindow::on_actionExit_triggered()
{
    QApplication::exit(0);
}

void MainWindow::on_actionEdit_triggered()
{
    on_btnEdit_clicked();
}

void MainWindow::on_actionRemove_triggered()
{
    on_btnDelete_clicked();
}

void MainWindow::on_btnMoreInfo_clicked()
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

        DialogMoreInfo dialogMoreInfo;
        dialogMoreInfo.setInfo(id, name, birth, death, sex);
        int status = dialogMoreInfo.exec();
    }
    else if(currentTabIndex == 1)
    {
        int currentlySelected = ui->tblComputers->currentIndex().row();
        string name, year, type, built, id;
        name = currentlyDisplayedComputers[currentlySelected].getName();
        year = currentlyDisplayedComputers[currentlySelected].getYear();
        type = currentlyDisplayedComputers[currentlySelected].getType();
        built = currentlyDisplayedComputers[currentlySelected].getBuilt();
        id = currentlyDisplayedComputers[currentlySelected].getID();

        DialogMoreInfoComputer dialogMoreInfo;
        dialogMoreInfo.setInfo(id, name, year, type, built, name);
        int status = dialogMoreInfo.exec();
    }
}

void MainWindow::on_tblPersons_doubleClicked(const QModelIndex &index)
{
    on_btnMoreInfo_clicked();
}
