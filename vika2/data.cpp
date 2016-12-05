#include "data.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;
data::data()
{

}

void data::read(vector<Person>& pers)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
       m_db.setDatabaseName("..\\..\\sqldatabase\\vika2.sqlite");

       if (!m_db.open())
       {
          cout << "Error: connection with database fail";
       }
       else
       {
          cout << "Database: connection ok";
       }

       QSqlQuery query("SELECT Name, Sex, Birth, Death FROM persons");
       int idName = query.record().indexOf("Name");
       int idSex = query.record().indexOf("Sex");
       int idBirth = query.record().indexOf("Birth");
       int idDeath = query.record().indexOf("Death");
       while (query.next())
       {
          QString qname = query.value(idName).toString();
          string name = qname.toLocal8Bit().constData();
          QString qsex = query.value(idSex).toString();
          string sex = qsex.toLocal8Bit().constData();
          QString qbirth = query.value(idBirth).toString();
          string birth = qbirth.toLocal8Bit().constData();
          QString qdeath = query.value(idDeath).toString();
          string death = qdeath.toLocal8Bit().constData();
          Person p(name, "jj", sex, birth, death);
          pers.push_back(p);
       }

}

void data::write(string& firstname, string& lastname, string& sex, string& birth, string& death)
{
    QSqlQuery query;
    QString qfirstname = QString::fromStdString(firstname);
    QString qsex = QString::fromStdString(sex);
    QString qbirth = QString::fromStdString(birth);
    QString qdeath= QString::fromStdString(death);
    query.prepare("INSERT INTO persons (Name, Sex, Birth, Death) "
                      "VALUES (:name, :sex, :birth, :death)");
        query.bindValue(":name", qfirstname);
        query.bindValue(":sex", qsex);
        query.bindValue(":birth", qbirth);
        query.bindValue(":death", qdeath);
        query.exec();


}
//Overridear people.txt med nyjum vector
void data::remove(vector<Person>& pers) {

}
