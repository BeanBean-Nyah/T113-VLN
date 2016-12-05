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
    void write(string& firstname, string& lastname, string& sex, string& birth, string& death);
    void remove(vector<Person>& pers);
    QSqlDatabase m_db;

};

#endif // DATA_H
