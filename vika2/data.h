#ifndef DATA_H
#define DATA_H

#include "person.h"
#include "computer.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QVariant>


class data
{
private:

public:
    data();
    void read(vector<Person>& pers);
    void readComputer(vector<Computer>& comp);
    void write(string& firstname, string& sex, string& birth, string& death);
    void writeComputer(string& name, int& year, string& type, string& built);
    void remove(string& name);
    void edit(string& ID, string& value, string& type);
    void editComp(string& ID, string& value, string& type);
    QSqlDatabase m_db;
    void openDatabase();
    vector<Person> sortPersons(string& type);
    vector<Computer> sortComputer(string& type);

    void getPACjoined();
    void writePAC(string& pers_id, string& comp_id);


};

#endif // DATA_H
