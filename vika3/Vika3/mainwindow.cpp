#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    domain.openDatabase();
    ui->setupUi(this);


    displayAllPersons();
    displayAllComputers();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAllPersons()
{
    string type = getCurrentSortBy();
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
    vector<Computer> comp = domain.computerList();
    displayComputers(comp);

    currentlyDisplayedComputers = comp;
}

void MainWindow::displayComputers(vector<Computer> comp)
{
    ui->tblComputers->clearContents();

    ui->tblComputers->setStyleSheet("QTableWidget::item { padding-left: 40px }");
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

string MainWindow::getCurrentSortBy()
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

void MainWindow::on_btnNew_clicked()
{
    AddNewDialog addNewDialog;
    int status = addNewDialog.exec();
    if (status == 0)
    {
        ui->input_filter->setText("");
        displayAllPersons();
        displayAllComputers();

        ui->statusBar->showMessage("Successfully added!", 2000);
    }
    else if (status == 1)
    {
        // error
    }
}

void MainWindow::on_btnDelete_clicked()
{

    if (ui->tblPersons->isActiveWindow())
    {
        //QItemSelectionModel *select = ui->tblPersons->selectionModel();
        //qDebug()<<select->selectedRows(3).value(0).data().toString();
        int currentlySelected = ui->tblPersons->currentIndex().row();
        domain.remove(currentlyDisplayedPersons, currentlySelected);
        displayAllPersons();
        ui->btnDelete->setEnabled(false);
        ui->input_filter->setText("");
    }
    else if (ui->tblComputers->isActiveWindow())
    {
        int currentlySelected = ui->tblComputers->currentIndex().row();
        domain.removeComputer(currentlyDisplayedComputers, currentlySelected);
        displayAllComputers();
        ui->btnDelete->setEnabled(false);
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

void MainWindow::on_input_filter_textChanged(const QString &arg1)
{
    const string&& filterInput = ui->input_filter->text().toStdString();
    string sort = getCurrentSortBy();
    vector<Person> pers = domain.search(sort, filterInput);
    currentlyDisplayedPersons = pers;
    displayPersons(pers);
}

void MainWindow::on_comboBox_person_sort_currentIndexChanged(int index)
{
    on_input_filter_textChanged("");

}

void MainWindow::on_btnEdit_clicked()
{
    if(ui->tblPersons->isActiveWindow())
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
        name = newdialogEdit.getName();

        if (status == 0)
        {
            name = newdialogEdit.getName();
            sex = newdialogEdit.getSex();
            birth = newdialogEdit.getBirt();
            death = newdialogEdit.getDeath();
            string nType = "-name";
            string sType = "-sex";
            string bType = "-birth";
            string dType = "-death";
            domain.edit(currentlyDisplayedPersons, currentlySelected, name, nType);
            domain.edit(currentlyDisplayedPersons, currentlySelected, sex, sType);
            domain.edit(currentlyDisplayedPersons, currentlySelected, birth, bType);
            domain.edit(currentlyDisplayedPersons, currentlySelected, death, dType);
            ui->input_filter->setText("");
            displayAllPersons();
            displayAllComputers();
            ui->btnEdit->setEnabled(false);
        }
        else if (status == 1)
        {
        ui->btnEdit->setEnabled(false);
        }

    }
    else if (ui->tblComputers->isActiveWindow())
    {
        //dostuff
    }
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
            ui->input_filter->setText("");
            displayAllPersons();
            displayAllComputers();
        }
        else if (status == 1)
        {
            // error
        }
}
