#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Person.h"
#include "Domain.h"
#include "Computer.h"
#include "addnewdialog.h"
#include "dialogedit.h"

#include <vector>
#include <QMainWindow>
#include <QTableWidgetItem>
#include <QDebug>



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

    void on_input_filter_textChanged(const QString &arg1);

    void on_comboBox_person_sort_currentIndexChanged(int index);

    void on_btnEdit_clicked();

private:
    Ui::MainWindow *ui;
    Domain domain;
    void displayAllPersons();
    void displayPersons(vector<Person> pers);
    void displayAllComputers();
    void displayComputers(vector<Computer> comp);
    string getCurrentSortBy();
    vector<Person> currentlyDisplayedPersons;
    vector<Computer> currentlyDisplayedComputers;
};

#endif // MAINWINDOW_H
