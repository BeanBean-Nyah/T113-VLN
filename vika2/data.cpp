#include "data.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;
data::data()
{

}

void data::openDatabase() {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("..\\..\\sqldatabase\\vika2.sqlite");

    if (!m_db.open())
    {
       cout << "Error: connection with database fail" << endl;
    }
    else
    {
       cout << "Database: connection ok" << endl;
    }
}

void data::read(vector<Person>& pers)
{
    QSqlQuery query("SELECT Name, Sex, Birth, Death, Status FROM persons");
    int idName = query.record().indexOf("Name");
    int idSex = query.record().indexOf("Sex");
    int idBirth = query.record().indexOf("Birth");
    int idDeath = query.record().indexOf("Death");
    int idStatus = query.record().indexOf("Status");
    while (query.next())
    {
        if (query.value(idStatus) == 0) {
        QString qname = query.value(idName).toString();
        string name = qname.toLocal8Bit().constData();
        QString qsex = query.value(idSex).toString();
        string sex = qsex.toLocal8Bit().constData();
        QString qbirth = query.value(idBirth).toString();
        string birth = qbirth.toLocal8Bit().constData();
        QString qdeath = query.value(idDeath).toString();
        string death = qdeath.toLocal8Bit().constData();
        Person p(name, sex, birth, death);
        pers.push_back(p);
        }
    }
}

void data::write(string& firstname, string& sex, string& birth, string& death)
{
    QSqlQuery query;
    QString qfirstname = QString::fromStdString(firstname);
    QString qsex = QString::fromStdString(sex);
    QString qbirth = QString::fromStdString(birth);
    QString qdeath= QString::fromStdString(death);
    query.prepare("INSERT INTO persons (Name, Sex, Birth, Death)"
                      "VALUES (:name, :sex, :birth, :death)");
        query.bindValue(":name", qfirstname);
        query.bindValue(":sex", qsex);
        query.bindValue(":birth", qbirth);
        query.bindValue(":death", qdeath);
        query.exec();


}

void data::remove(string& name) {
    QSqlQuery query;
    QString qname = QString::fromStdString(name);
    query.prepare("UPDATE persons SET status = 1 WHERE name = :name");

    query.bindValue(":name", qname);
    query.exec();
}

void data::edit(string& value, string& type) {
    QSqlQuery query;
    QString qvalue = QString::fromStdString(value);
    if (type == "-firstname")
    {
        query.prepare("Update persons SET name = :value WHERE ID = :id");
        query.bindValue(":id", 2);
        query.bindValue(":value", qvalue);
    }
    else if (type == "-sex")
    {
        query.prepare("Update persons SET sex = :value WHERE ID = :id");
        query.bindValue(":id", 2);
        query.bindValue(":value", qvalue);
    }
    else if (type == "-birth")
    {
        query.prepare("Update persons SET birth = :value WHERE ID = :id");
        query.bindValue(":id", 2);
        query.bindValue(":value", qvalue);
    }
    else if (type == "-death")
    {
        query.prepare("Update persons SET death = :value WHERE ID = :id");
        query.bindValue(":id", 2);
        query.bindValue(":value", qvalue);
    }
    query.exec();

}
