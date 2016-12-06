#ifndef DATA_H
#define DATA_H

#include "person.h"

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
    void write(string& firstname, string& sex, string& birth, string& death);
    void remove(string& name);
    void edit(string& ID, string& value, string& type);
    QSqlDatabase m_db;
    void openDatabase();

};

#endif // DATA_H
