#include "domain.h"
#include "data.h"
#include "person.h"
#include <iostream>
#include <algorithm>

using namespace std;
domain::domain()
{

}

vector<Person> domain::list()
{
    data dat;
    vector<Person> persons;
    dat.read(persons);

    return persons;
}

void domain::openDatabase()
{
    data dat;
    dat.openDatabase();
}

void domain::add(string& firstname, string& sex, string& birth, string& death)
{
    data dat;
    dat.write(firstname, sex, birth, death);
}

void domain::addComputer(string& name, int& year, string& type, string& built)
{
    data dat;
    dat.writeComputer(name, year, type, built);
}

vector<Person> domain::sorting(string& input)
{
    data dat;
    vector<Person> pers;
    pers = dat.sortPersons(input);

    return pers;
}

vector<Person> domain::search(string& whattype, string& input)
{
    data dat;
    vector<Person> persons, res;
    dat.read(persons);

    for(unsigned int i = 0; i < persons.size(); i++)
    {
        if (whattype == "-name")
        {
            if(persons[i].getFirstname() == input)
            {
                Person p(persons[i].getID(), persons[i].getFirstname(),
                       persons[i].getSex(), persons[i].getBirth(), persons[i].getDeath());
                res.push_back(p);
            }
        }
        else if (whattype == "-sex")
        {
            if(persons[i].getSex() == input)
            {
                Person p(persons[i].getID(), persons[i].getFirstname(),
                       persons[i].getSex(), persons[i].getBirth(), persons[i].getDeath());
                res.push_back(p);
            }
        }
        else if (whattype == "-birthyear")
        {
            if(persons[i].getBirth() == input)
            {
                Person p(persons[i].getID(), persons[i].getFirstname(),
                       persons[i].getSex(), persons[i].getBirth(), persons[i].getDeath());
                res.push_back(p);
            }
        }
        else if (whattype == "-deathyear")
        {
            if(persons[i].getDeath() == input)
            {
                Person p(persons[i].getID(), persons[i].getFirstname(),
                       persons[i].getSex(), persons[i].getBirth(), persons[i].getDeath());
                res.push_back(p);
            }
        }
    }
    return res;
}

void domain::remove(vector<Person>& pers, int& line)
{
    string ID = pers[line].getID();
    data dat;
    dat.remove(ID);
}

void domain::edit(vector<Person>& pers, int& line, string& type, string& newValue)
{
    string ID = pers[line].getID();
    data dat;
    dat.edit(ID, newValue, type);
}
//Computer functions

vector<Computer> domain::computerList()
{
    vector<Computer> comp;
    data d;
    d.readComputer(comp);
    return comp;
}

vector<Computer> domain::sortComputer(string& value)
{
    vector<Computer> comp;
    data d;
    comp = d.sortComputer(value);
    return comp;
}
