#ifndef DIALOGNEWRELATION_H
#define DIALOGNEWRELATION_H
#include "Person.h"
#include "Computer.h"
#include "Domain.h"
#include <vector>
#include <QDialog>

using namespace std;

namespace Ui {
class DialogNewRelation;
}

class DialogNewRelation : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNewRelation(QWidget *parent = 0);
    ~DialogNewRelation();

private slots:
    void on_pushButton_save_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::DialogNewRelation *ui;

    void displayAllPersons();
    void displayPersons(vector<Person> pers);
    void displayAllComputers();
    void displayComputers(vector<Computer> comp);

    vector<Person> currentlyDisplayedPersons;
    vector<Computer> currentlyDisplayedComputers;

    Domain domain;
};

#endif // DIALOGNEWRELATION_H
