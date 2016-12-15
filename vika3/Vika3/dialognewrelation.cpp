#include "dialognewrelation.h"
#include "ui_dialognewrelation.h"

DialogNewRelation::DialogNewRelation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNewRelation)
{
    ui->setupUi(this);

    ui->tableWidget_creators->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_computers->setSelectionMode(QAbstractItemView::SingleSelection);

    displayAllPersons();
    displayAllComputers();
}

DialogNewRelation::~DialogNewRelation()
{
    delete ui;

}

void DialogNewRelation::displayAllPersons()
{
    string type = "nameasc";
    vector<Person> pers = domain.sorting(type);
    displayPersons(pers);

    currentlyDisplayedPersons = pers;
}

void DialogNewRelation::displayPersons(vector<Person> pers)
{

    ui->tableWidget_creators->clearContents();

    ui->tableWidget_creators->setRowCount(pers.size());

    for (unsigned int row = 0; row < pers.size(); row++)
    {
        Person currentPerson = pers.at(row);
        QString name = QString::fromStdString(currentPerson.getFirstname());
        QString id = QString::fromStdString(currentPerson.getID());

        ui->tableWidget_creators->setItem(row, 0, new QTableWidgetItem(name));

    }
}

void DialogNewRelation::displayAllComputers()
{
    string type = "nameasc";
    vector<Computer> comp = domain.sortComputer(type);
    displayComputers(comp);

    currentlyDisplayedComputers = comp;
}

void DialogNewRelation::displayComputers(vector<Computer> comp)
{
    ui->tableWidget_computers->clearContents();

    ui->tableWidget_computers->setRowCount(comp.size());

    for (unsigned int row = 0; row < comp.size(); row++)
    {
        Computer currentComputer = comp.at(row);
        QString name = QString::fromStdString(currentComputer.getName());

        ui->tableWidget_computers->setItem(row, 0, new QTableWidgetItem(name));

    }
}

void DialogNewRelation::on_pushButton_save_clicked()
{
    int currentlySelectedComp = ui->tableWidget_computers->currentIndex().row();
    int currentlySelectedPers = ui->tableWidget_creators->currentIndex().row();
    string persID = currentlyDisplayedPersons[currentlySelectedPers].getID();
    string compID = currentlyDisplayedComputers[currentlySelectedComp].getID();

    if (domain.connectPtoC(persID, compID))
    {
        //skila ad tenging hafi tekist
        done(0);
    }
    else
    {
        //skila ad tenging se nu thegar til
        done(2);
    }


}

void DialogNewRelation::on_pushButton_cancel_clicked()
{
    done(1);
}
