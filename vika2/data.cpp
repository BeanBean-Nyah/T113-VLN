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


}

void data::write(string& firstname, string& lastname, string& sex, string& birth, string& death)
{


}
//Overridear people.txt med nyjum vector
void data::remove(vector<Person>& pers) {

}
