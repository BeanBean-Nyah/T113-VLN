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

bool domain::openDatabase()
{
    data dat;
    if (dat.openDatabase())
    {
        return true;
    } else {
        return false;
    }
}

bool domain::add(string& firstname, string& sex, string& birth, string& death)
{
    data dat;
    bool check = true;
    vector<Person> persons;
    dat.read(persons);
    for (unsigned int i = 0; i < persons.size(); i++)
    {
        if (firstname == persons[i].getFirstname() && sex == persons[i].getSex() &&
                birth == persons[i].getBirth() && death == persons[i].getDeath())
        {
            check = false;
        } else {
            check = true;
        }
    }
    if (check)
    {
        dat.write(firstname, sex, birth, death);
        return true;
    }
    else
    {
        return false;
    }
    return true;
}

bool domain::addComputer(string& name, int& year, string& type, string& built)
{
    data dat;
    bool check = true;
    vector<Computer> comp;
    dat.readComputer(comp);
    for (unsigned int i = 0; i < comp.size(); i++)
    {
        if (name == comp[i].getName() && year == comp[i].getYear() &&
                type == comp[i].getType() && built == comp[i].getBuilt())
        {
            check = false;
        } else {
            check = true;
        }
    }
    if (check)
    {
        dat.writeComputer(name, year, type, built);
        return true;
    }
    else
    {
        return false;
    }
    return true;
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
            string name = Lower_Ans(persons[i].getFirstname());
            string innerinput = Lower_Ans(input);
            size_t found = name.find(innerinput);
            if (found!=string::npos){
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


vector<PersonsAndComputers> domain::persAndCompList()
{
    vector<PersonsAndComputers> pAc;
    data d;
    d.getPACjoined(pAc);
    return pAc;
}

vector<Computer> domain::searchComputer(string& whattype, string& input)
{
    data dat;
    vector<Computer> computers, res;
    dat.readComputer(computers);

    for(unsigned int i = 0; i < computers.size(); i++)
    {
        if (whattype == "-name")
        {
            string name = Lower_Ans(computers[i].getName());
            string innerinput = Lower_Ans(input);
            size_t found = name.find(innerinput);
            if (found!=string::npos)
            {
                Computer c(computers[i].getID(), computers[i].getName(),
                       computers[i].getYear(), computers[i].getType(), computers[i].getBuilt());
                res.push_back(c);
            }
        }
        else if (whattype == "-year")
        {
            if (computers[i].getYearString() == input)
            {
                Computer c(computers[i].getID(), computers[i].getName(),
                       computers[i].getYear(), computers[i].getType(), computers[i].getBuilt());
                res.push_back(c);
            }
        }
        else if (whattype == "-type")
        {
            if(computers[i].getType() == input)
            {
                Computer c(computers[i].getID(), computers[i].getName(),
                       computers[i].getYear(), computers[i].getType(), computers[i].getBuilt());
                res.push_back(c);
            }
        }
        else if (whattype == "-built")
        {
            if(computers[i].getBuilt() == input)
            {
                Computer c(computers[i].getID(), computers[i].getName(),
                       computers[i].getYear(), computers[i].getType(), computers[i].getBuilt());
                res.push_back(c);
            }
        }
    }
    return res;
}

void domain::editComputer(vector<Computer>& comp, int& line, string& type, string& newValue)
{
    string ID = comp[line].getID();
    data dat;
    dat.editComp(ID, newValue, type);

}

void domain::connectPtoC(string& persID, string& compID)
{
    data d;
    d.writePAC(persID, compID);
}

string domain::Lower_Ans(string word)
{
    transform(word.begin(), word.end(), word.begin(), ::tolower); // scope resolution operator
    return word;
}
