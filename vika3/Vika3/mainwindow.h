#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Person.h"
#include "Domain.h"
#include "Computer.h"
#include "addnewdialog.h"

#include <vector>
#include <QMainWindow>
#include <QTableWidgetItem>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnNew_clicked();

    void on_btnDelete_clicked();

    void on_tblComputers_clicked(const QModelIndex &index);

    void on_tblPersons_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    void displayAllPersons();
    void displayPersons(vector<Person> pers);
    void displayAllComputers();
    void displayComputers(vector<Computer> comp);
    vector<Person> currentlyDisplayedPersons;
    vector<Computer> currentlyDisplayedComputers;
};

#endif // MAINWINDOW_H
