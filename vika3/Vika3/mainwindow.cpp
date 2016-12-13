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
    vector<Person> pers = domain.list();
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

        ui->tblPersons->setItem(row, 0, new QTableWidgetItem(name));
        ui->tblPersons->setItem(row, 1, new QTableWidgetItem(sex));
        ui->tblPersons->setItem(row, 2, new QTableWidgetItem(birth));
        ui->tblPersons->setItem(row, 3, new QTableWidgetItem(death));
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

void MainWindow::on_btnNew_clicked()
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

void MainWindow::on_btnDelete_clicked()
{
    if (ui->tblPersons->isActiveWindow())
    {
        int currentlySelected = ui->tblPersons->currentIndex().row();
        domain.remove(currentlyDisplayedPersons, currentlySelected);
        displayAllPersons();
        ui->btnDelete->setEnabled(false);
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
    string name = "-name";
    vector<Person> pers = domain.search(name, filterInput);
    displayPersons(pers);
}

void MainWindow::on_btnEdit_clicked()
{
    if(ui->tblPersons->isActiveWindow())
    {
        int currentlySelected = ui->tblPersons->currentIndex().row();
        vector<Person> pers = domain.list();
        string name = pers[currentlySelected].getFirstname();
        string sex = pers[currentlySelected].getSex();
        string birth = pers[currentlySelected].getBirth();
        string death = pers[currentlySelected].getDeath();

        dialogEdit newdialogEdit;
        newdialogEdit.setTextbox(name, sex, birth, death);
        int status = newdialogEdit.exec();

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
    else if (ui->tblComputers->isActiveWindow())
    {
        //dostuff
    }
}
