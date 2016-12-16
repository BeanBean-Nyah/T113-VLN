#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Person.h"
#include "Domain.h"
#include "Computer.h"
#include "PersonsAndComputers.h"
#include "persandcomp.h"
#include "addnewdialog.h"
#include "dialogedit.h"
#include "dialogeditcomputer.h"
#include "dialognewrelation.h"
#include "dialogabout.h"
#include "dialogmoreinfo.h"
#include "dialogmoreinfocomputer.h"

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

    void on_tblComputers_clicked();

    void on_tblPersons_clicked();

    void on_input_filter_person_textChanged();

    void on_comboBox_person_sort_currentIndexChanged();

    void on_btnEdit_clicked();

    void on_radioButton_person_sort_asc_toggled();

    void on_radioButton_person_sort_desc_toggled();

    void on_actionNew_triggered();

    void on_radioButton_computer_sort_asc_toggled();

    void on_radioButton_computer_sort_desc_toggled();

    void on_comboBox_computer_sort_currentIndexChanged();

    void on_input_filter_computer_textChanged();

    void on_input_filter_both_textChanged();

    void on_comboBox_sort_both_currentIndexChanged();

    void on_radioButton_sort_both_asc_toggled();

    void on_radioButton_sort_both_desc_toggled();

    void on_tblPersAndComp_clicked();

    void on_actionAbout_triggered();

    void on_actionExit_triggered();

    void on_actionEdit_triggered();

    void on_actionRemove_triggered();

    void on_btnMoreInfo_clicked();

    void on_tblPersons_doubleClicked();

    void on_tblComputers_doubleClicked();

    void on_actionBiography_triggered();

    void on_tabWidget_tabBarClicked();

private:
    Ui::MainWindow *ui;
    Domain domain;

    void displayAllPersons();
    void displayPersons(vector<Person> pers);
    void displayAllComputers();
    void displayComputers(vector<Computer> comp);
    void displayAllPersAndComp();
    void displayPersAndComp(vector<PersAndComp> pAc);

    string getPersonCurrentSortBy();
    string getComputerCurrentSortBy();
    string getBothCurrentSortBy();

    vector<Person> currentlyDisplayedPersons;
    vector<Computer> currentlyDisplayedComputers;
    vector<PersAndComp> currentlyDisplayedPersAndComp;
};

#endif // MAINWINDOW_H
