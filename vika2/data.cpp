#include "Data.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
Data::Data()
{

}

//opnar a tengingu vid database og skilar tvi hvort tenging hafi tekist
bool Data::openDatabase()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("..\\vika2\\databaseFinal.sqlite");

    if (!m_db.open())
    {
       return false;
    }
    else
    {
       return true;
    }
}

//les inn upplysingar ur tofluni persons i vector
void Data::read(vector<Person>& pers)
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

//Skrifar ut nyjar upplysingar i tofluna persons
void Data::write(string& firstname, string& sex, string& birth, string& death)
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

//skilar upplysingar ur toflunni persons sorterudum eftir vali i vector
vector<Person> Data::sortPersons(string& type)
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

//Merkir personu eydda i toflunni sem vid a
void Data::remove(string& ID, int& type)
{
    QSqlQuery query;
    QString qID = QString::fromStdString(ID);
    if (type == 0)
    {
        query.prepare("UPDATE persons SET status = 1 WHERE ID = :id");
        query.bindValue(":id", qID);
    }
    else if (type == 1)
    {
        query.prepare("UPDATE computer SET computer_status = 1 WHERE computer_ID = :id");
        query.bindValue(":id", qID);
    }

    query.exec();
}

//breytir voldum upplysingum i toflunni persons
void Data::edit(string& ID, string& value, string& type)
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

//les inn i vector allar upplysingar ur toflunni computer
void Data::readComputer(vector<Computer>& comp)
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
            string year = qyear.toLocal8Bit().constData();
            QString qtype = query.value(idType).toString();
            string type = qtype.toLocal8Bit().constData();
            QString qbuilt = query.value(idBuilt).toString();
            string built = qbuilt.toLocal8Bit().constData();
            Computer c(id, name, year, type, built);
            comp.push_back(c);
        }
    }
}

//skrifar ut nyjar upplysingar ut i tofluna computer
void Data::writeComputer(string& name, string& year, string& type, string& built)
{
    QSqlQuery query;
    QString qname = QString::fromStdString(name);
    QString qyear = QString::fromStdString(year);
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

//breytir voldum upplysingum i toflunni computer
void Data::editComp(string& ID, string& value, string& type)
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

//skilar upplysingar ur toflunni computer sorterudum eftir vali i vector
vector<Computer> Data::sortComputer(string& type)
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
            string year = qyear.toLocal8Bit().constData();
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

//skrifar upplysingar ur toflunni personsandcomputers i vector
void Data::getPACjoined(vector<PersonsAndComputers>& pAc)
{
    QSqlQuery query("SELECT ID, computer_ID, person_ID, pac_status FROM personsandcomputers");

    int idID = query.record().indexOf("ID");
    int idComp_ID = query.record().indexOf("computer_ID");
    int idPers_ID = query.record().indexOf("person_ID");
    int idStatus = query.record().indexOf("pac_status");
    while (query.next())
    {
        if (query.value(idStatus) == 0)
        {
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

//Skrifar tengls person og computer ut i tolfuna personsandcomputers
void Data::writePAC(string& pers_id, string& comp_id)
{
    QSqlQuery query;
    QString qpers_id = QString::fromStdString(pers_id);
    QString qcomp_id = QString::fromStdString(comp_id);
    query.prepare("INSERT INTO personsandcomputers (person_id, computer_id) VALUES (:pers_id, :comp_id)");
        query.bindValue(":pers_id", qpers_id);
        query.bindValue(":comp_id", qcomp_id);
        query.exec();
}

bool Data::editPAC(string& ID)
{
    QSqlQuery query;
    QString qID = QString::fromStdString(ID);
    query.prepare("UPDATE personsandcomputers SET pac_status = 1 WHERE ID = :id");
    query.bindValue(":id", qID);
    if (query.exec())
    {
        return true;
    }
    return false;
}

//Hreinsar tolfu i database
bool Data::clear(int& type)
{
    QSqlQuery query;
    if (type == 1)
    {
        if(query.exec("DELETE FROM persons"))
            return true;
    }
    else if (type == 2)
    {
        if(query.exec("DELETE FROM computer"))
            return true;
    }
    else if (type == 3)
    {
        if (query.exec("DELETE FROM personsandcomputers"))
            return true;
    }
    else if (type == 4)
    {
        query.exec("DELETE FROM persons");
        query.exec("DELETE FROM computer");
        query.exec("DELETE FROM personsandcomputers");
        return true;
    }
    return false;
}

//les inn inn vector upplysingar ur toflunni funfacts
//sem inniheldur strengi af stadreyndum
void Data::getFact(vector<Facts>& fac)
{
    QSqlQuery query("SELECT ID, fact FROM funfacts");

    int idID = query.record().indexOf("ID");
    int idFact = query.record().indexOf("fact");
    while (query.next())
    {
        QString qid = query.value(idID).toString();
        int id = qid.split(" ")[0].toInt();
        QString qfact = query.value(idFact).toString();
        string fact = qfact.toLocal8Bit().constData();
        Facts f(id, fact);
        fac.push_back(f);
    }
}
