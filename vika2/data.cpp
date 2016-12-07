#include "data.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
data::data()
{
}

void data::openDatabase()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    //m_db.setDatabaseName("vika2.sqlite");
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
    QSqlQuery query("SELECT ID, Name, Sex, Birth, Death, Status FROM persons");
    int idID = query.record().indexOf("ID");
    int idName = query.record().indexOf("Name");
    int idSex = query.record().indexOf("Sex");
    int idBirth = query.record().indexOf("Birth");
    int idDeath = query.record().indexOf("Death");
    int idStatus = query.record().indexOf("Status");
    while (query.next())
    {
        if (query.value(idStatus) == 0)
        {
        QString qid = query.value(idID).toString();
        string id = qid.toLocal8Bit().constData();
        QString qname = query.value(idName).toString();
        string name = qname.toLocal8Bit().constData();
        QString qsex = query.value(idSex).toString();
        string sex = qsex.toLocal8Bit().constData();
        QString qbirth = query.value(idBirth).toString();
        string birth = qbirth.toLocal8Bit().constData();
        QString qdeath = query.value(idDeath).toString();
        string death = qdeath.toLocal8Bit().constData();
        Person p(id, name, sex, birth, death);
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
    query.prepare("INSERT INTO persons (Name, Sex, Birth, Death,Status)"
                   "VALUES (:name, :sex, :birth, :death, :status)");

    query.bindValue(":name", qfirstname);
    query.bindValue(":sex", qsex);
    query.bindValue(":birth", qbirth);
    query.bindValue(":death", qdeath);
    query.bindValue(":status",0);
    query.exec();
}

vector<Person> data::sortPersons(string& type)
{
    vector<Person> pers;
    QSqlQuery query;
    if (type == "-nameasc")
    {
        query.exec("SELECT ID, Name, Sex, Birth, Death, Status FROM persons ORDER BY Name ASC");
    }
    else if (type == "-sexasc")
    {
        query.exec("SELECT ID, Name, Sex, Birth, Death, Status FROM persons ORDER BY Sex ASC");
    }
    else if (type == "-birthasc")
    {
        query.exec("SELECT ID, Name, Sex, Birth, Death, Status FROM persons ORDER BY Birth ASC");
    }
    else if (type == "-deathasc")
    {
        query.exec("SELECT ID, Name, Sex, Birth, Death, Status FROM persons ORDER BY Death ASC");
    }
    else if (type == "-namedesc")
    {
        query.exec("SELECT ID, Name, Sex, Birth, Death, Status FROM persons ORDER BY Name DESC");
    }
    else if (type == "-sexdesc")
    {
        query.exec("SELECT ID, Name, Sex, Birth, Death, Status FROM persons ORDER BY Sex DESC");
    }
    else if (type == "-birthdesc")
    {
        query.exec("SELECT ID, Name, Sex, Birth, Death, Status FROM persons ORDER BY Birth DESC");
    }
    else if (type == "-deathdesc")
    {
        query.exec("SELECT ID, Name, Sex, Birth, Death, Status FROM persons ORDER BY Death DESC");
    }

    int idID = query.record().indexOf("ID");
    int idName = query.record().indexOf("Name");
    int idSex = query.record().indexOf("Sex");
    int idBirth = query.record().indexOf("Birth");
    int idDeath = query.record().indexOf("Death");
    int idStatus = query.record().indexOf("Status");
    while (query.next())
    {
        if (query.value(idStatus) == 0)
        {
            QString qid = query.value(idID).toString();
            string id = qid.toLocal8Bit().constData();
            QString qname = query.value(idName).toString();
            string name = qname.toLocal8Bit().constData();
            QString qsex = query.value(idSex).toString();
            string sex = qsex.toLocal8Bit().constData();
            QString qbirth = query.value(idBirth).toString();
            string birth = qbirth.toLocal8Bit().constData();
            QString qdeath = query.value(idDeath).toString();
            string death = qdeath.toLocal8Bit().constData();
            Person p(id, name, sex, birth, death);
            pers.push_back(p);
        }
    }

    return pers;
}

void data::remove(string& ID) {
    QSqlQuery query;
    QString qID = QString::fromStdString(ID);
    query.prepare("UPDATE persons SET status = 1 WHERE ID = :id");
    query.bindValue(":id", qID);
    query.exec();
}

void data::edit(string& ID, string& value, string& type)
{
    QSqlQuery query;
    QString qID = QString::fromStdString(ID);
    QString qvalue = QString::fromStdString(value);
    if (type == "-name")
    {
        query.prepare("Update persons SET name = :value WHERE ID = :id");
        query.bindValue(":id", qID);
        query.bindValue(":value", qvalue);
    }
    else if (type == "-sex")
    {
        query.prepare("Update persons SET sex = :value WHERE ID = :id");
        query.bindValue(":id", qID);
        query.bindValue(":value", qvalue);
    }
    else if (type == "-birth")
    {
        query.prepare("Update persons SET birth = :value WHERE ID = :id");
        query.bindValue(":id", qID);
        query.bindValue(":value", qvalue);
    }
    else if (type == "-death")
    {
        query.prepare("Update persons SET death = :value WHERE ID = :id");
        query.bindValue(":id", qID);
        query.bindValue(":value", qvalue);
    }
    query.exec();
}

void data::readComputer(vector<Computer>& comp)
{
    QSqlQuery query("SELECT computer_ID, computer_Name, computer_Year, "
                   "computer_Type, computer_Built, computer_Status FROM computer");

    int idID = query.record().indexOf("computer_ID");
    int idName = query.record().indexOf("computer_name");
    int idYear = query.record().indexOf("computer_Year");
    int idType = query.record().indexOf("computer_Type");
    int idBuilt = query.record().indexOf("computer_Built");
    int idStatus = query.record().indexOf("computer_Status");
    while (query.next())
    {
        if (query.value(idStatus) == 0)
        {
            QString qid = query.value(idID).toString();
            string id = qid.toLocal8Bit().constData();
            QString qname = query.value(idName).toString();
            string name = qname.toLocal8Bit().constData();
            QString qyear = query.value(idYear).toString();
            int year = qyear.split(" ")[0].toInt();
            QString qtype = query.value(idType).toString();
            string type = qtype.toLocal8Bit().constData();
            QString qbuilt = query.value(idBuilt).toString();
            string built = qbuilt.toLocal8Bit().constData();
            Computer c(id, name, year, type, built);
            comp.push_back(c);
        }
    }
}

void data::writeComputer(string& name, int& year, string& type, string& built)
{
    QSqlQuery query;
    QString qname = QString::fromStdString(name);
    QString qyear = QString::number(year);
    QString qtype = QString::fromStdString(type);
    QString qbuilt = QString::fromStdString(built);
    query.prepare("INSERT INTO computer (computer_name, computer_year, computer_type, computer_built)"
                  "VALUES (:name, :year, :type, :built)");
        query.bindValue(":name", qname);
        query.bindValue(":year", qyear);
        query.bindValue(":type", qtype);
        query.bindValue(":built", qbuilt);
        query.exec();
}

void data::editComp(string& ID, string& value, string& type)
{
    QSqlQuery query;
    QString qID = QString::fromStdString(ID);
    QString qvalue = QString::fromStdString(value);
    if (type == "-name")
    {
        query.prepare("Update computer SET computer_name = :value WHERE computer_ID = :id");
        query.bindValue(":id", qID);
        query.bindValue(":value", qvalue);
    }
    else if (type == "-year")
    {
        query.prepare("Update computer SET computer_year = :value WHERE computer_ID = :id");
        query.bindValue(":id", qID);
        query.bindValue(":value", qvalue);
    }
    else if (type == "-type")
    {
        query.prepare("Update computer SET computer_type = :value WHERE computer_ID = :id");
        query.bindValue(":id", qID);
        query.bindValue(":value", qvalue);
    }
    else if (type == "-built")
    {
        query.prepare("Update computer SET computer_built = :value WHERE computer_ID = :id");
        query.bindValue(":id", qID);
        query.bindValue(":value", qvalue);
    }
    query.exec();
}

vector<Computer> data::sortComputer(string& type)
{
    vector<Computer> comp;
    QSqlQuery query;
    if (type == "-nameasc")
    {
        query.exec("SELECT computer_ID, computer_Name, computer_Year, computer_Type, "
                        "computer_Built, computer_Status FROM computer ORDER BY computer_name ASC");
    }
    else if (type == "-yearasc")
    {
        query.exec("SELECT computer_ID, computer_Name, computer_Year, computer_Type, "
                        "computer_Built, computer_Status FROM computer ORDER BY computer_year ASC");
    }
    else if (type == "-typeasc")
    {
        query.exec("SELECT computer_ID, computer_Name, computer_Year, computer_Type, "
                        "computer_Built, computer_Status FROM computer ORDER BY computer_type ASC");
    }
    else if (type == "-builtasc")
    {
        query.exec("SELECT computer_ID, computer_Name, computer_Year, computer_Type, "
                        "computer_Built, computer_Status FROM computer ORDER BY computer_built ASC");
    }
    else if (type == "-namedesc")
    {
        query.exec("SELECT computer_ID, computer_Name, computer_Year, computer_Type, "
                        "computer_Built, computer_Status FROM computer ORDER BY computer_name DESC");
    }
    else if (type == "-yeardesc")
    {
        query.exec("SELECT computer_ID, computer_Name, computer_Year, computer_Type, "
                        "computer_Built, computer_Status FROM computer ORDER BY computer_year DESC");
    }
    else if (type == "-typedesc")
    {
        query.exec("SELECT computer_ID, computer_Name, computer_Year, computer_Type, "
                        "computer_Built, computer_Status FROM computer ORDER BY computer_type DESC");
    }
    else if (type == "-builtdesc")
    {
        query.exec("SELECT computer_ID, computer_Name, computer_Year, computer_Type, "
                        "computer_Built, computer_Status FROM computer ORDER BY computer_built DESC");
    }
    int idID = query.record().indexOf("computer_ID");
    int idName = query.record().indexOf("computer_name");
    int idYear = query.record().indexOf("computer_Year");
    int idType = query.record().indexOf("computer_Type");
    int idBuilt = query.record().indexOf("computer_Built");
    int idStatus = query.record().indexOf("computer_Status");
    while (query.next())
    {
        if (query.value(idStatus) == 0)
        {
            QString qid = query.value(idID).toString();
            string id = qid.toLocal8Bit().constData();
            QString qname = query.value(idName).toString();
            string name = qname.toLocal8Bit().constData();
            QString qyear = query.value(idYear).toString();
            int year = qyear.split(" ")[0].toInt();
            QString qtype = query.value(idType).toString();
            string type = qtype.toLocal8Bit().constData();
            QString qbuilt = query.value(idBuilt).toString();
            string built = qbuilt.toLocal8Bit().constData();
            Computer c(id, name, year, type, built);
            comp.push_back(c);
        }
    }
    return comp;
}

void data::getPACjoined(vector<PersonsAndComputers>& pAc) {
    QSqlQuery query("SELECT ID, computer_ID, person_ID, pac_status FROM personsandcomputers");

    int idID = query.record().indexOf("ID");
    int idComp_ID = query.record().indexOf("computer_ID");
    int idPers_ID = query.record().indexOf("person_ID");
    int idStatus = query.record().indexOf("pac_status");
    while (query.next())
    {
        if (query.value(idStatus) == 0) {
            QString qid = query.value(idID).toString();
            string id = qid.toLocal8Bit().constData();
            QString qcomp_id = query.value(idComp_ID).toString();
            string comp_id = qcomp_id.toLocal8Bit().constData();
            QString qpers_id = query.value(idPers_ID).toString();
            string pers_id = qpers_id.toLocal8Bit().constData();
            PersonsAndComputers pc(id, pers_id, comp_id);
            pAc.push_back(pc);
        }
    }
}

void data::writePAC(string& pers_id, string& comp_id)
{
    QSqlQuery query;
    QString qpers_id = QString::fromStdString(pers_id);
    QString qcomp_id = QString::fromStdString(comp_id);
    query.prepare("INSERT INTO personsandcomputers (person_id, computer_id) VALUES (:pers_id, :comp_id)");
        query.bindValue(":pers_id", qpers_id);
        query.bindValue(":comp_id", qcomp_id);
        query.exec();
}
