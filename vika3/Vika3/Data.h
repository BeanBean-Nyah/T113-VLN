#ifndef DATA_H
#define DATA_H

#include "Person.h"
#include "Computer.h"
#include "PersonsAndComputers.h"
#include "persandcomp.h"
#include "Facts.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QVariant>


class Data
{
private:

public:
    Data();
    void read(vector<Person>& pers);
    void readComputer(vector<Computer>& comp);
    void write(string& firstname, string& sex, string& birth, string& death);
    void writeComputer(string& name, string& year, string& type, string& built);
    void remove(string& name, int& type);
    void edit(string& ID, string& value, string& type);
    void edit(string& ID, string& name, string& sex, string& birth, string& death);
    void editComp(string& _ID, string& _name, string& _year, string& _type, string& _built);
    QSqlDatabase m_db;
    bool openDatabase();

    vector<Person> sortPersons(string& type);
    vector<Computer> sortComputer(string& type);
    vector<PersAndComp> sortBoth(string& type);

    void getPACjoined(vector<PersonsAndComputers>& pAc);
    void getPACjoinedTest(vector<PersAndComp>& pAc);
    void writePAC(string& pers_id, string& comp_id);
    bool editPAC(string& ID);
    void getFact(vector<Facts>& fac);

    bool clear(int& type);

    string getInfo(string& _ID);
    string getInfoComputer(string& _ID);


};

#endif // DATA_H
