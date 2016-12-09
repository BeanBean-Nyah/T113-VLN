#include "Domain.h"
#include "Data.h"
#include "Person.h"
#include <iostream>
#include <algorithm>

using namespace std;
Domain::Domain()
{

}

string Domain::funFact()
{
    string output;
    Data dat;
    vector<Facts> fact;
    dat.getFact(fact);
    int randomIndex = rand() % fact.size();
    output = fact[randomIndex].getFact();
    return output;
}

vector<Person> Domain::list()
{
    Data dat;
    vector<Person> persons;
    dat.read(persons);

    return persons;
}

bool Domain::openDatabase()
{
    Data dat;
    if (dat.openDatabase())
    {
        return true;
    } else
    {
        return false;
    }
}

bool Domain::add(string& firstname, string& sex, string& birth, string& death)
{
    Data dat;
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

bool Domain::addComputer(string& name, string& year, string& type, string& built)
{
    Data dat;
    bool check = true;
    vector<Computer> comp;
    dat.readComputer(comp);
    for (unsigned int i = 0; i < comp.size(); i++)
    {
        if (name == comp[i].getName() && year == comp[i].getYear() &&
                type == comp[i].getType() && built == comp[i].getBuilt())
        {
            check = false;
        }
        else
        {
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

vector<Person> Domain::sorting(string& input)
{
    Data dat;
    vector<Person> pers;
    pers = dat.sortPersons(input);

    return pers;
}

vector<Person> Domain::search(string& whattype, string& input)
{
    Data dat;
    vector<Person> persons, res;
    dat.read(persons);

    for(unsigned int i = 0; i < persons.size(); i++)
    {


        if (whattype == "-name")
        {
            string name = Lower_Ans(persons[i].getFirstname());
            string innerinput = Lower_Ans(input);
            size_t found = name.find(innerinput);
            if (found!=string::npos)
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

void Domain::remove(vector<Person>& pers, int& line)
{
    int type = 0;
    string ID = pers[line].getID();
    Data dat;
    dat.remove(ID, type);
}

void Domain::edit(vector<Person>& pers, int& line, string& type, string& newValue)
{
    string ID = pers[line].getID();
    Data dat;
    dat.edit(ID, newValue, type);
}
//Computer functions

vector<Computer> Domain::computerList()
{
    vector<Computer> comp;
    Data d;
    d.readComputer(comp);
    return comp;
}

vector<Computer> Domain::sortComputer(string& value)
{
    vector<Computer> comp;
    Data d;
    comp = d.sortComputer(value);
    return comp;
}

void Domain::removeComputer(vector<Computer>& comp, int& line)
{
    int type = 1;
    string ID = comp[line].getID();
    Data dat;
    dat.remove(ID, type);
}

vector<PersonsAndComputers> Domain::persAndCompList()
{
    vector<PersonsAndComputers> pAc;
    Data d;
    d.getPACjoined(pAc);
    return pAc;
}

vector<Computer> Domain::searchComputer(string& whattype, string& input)
{
    Data dat;
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
            if (computers[i].getYear() == input)
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

void Domain::editComputer(vector<Computer>& comp, int& line, string& type, string& newValue)
{
    string ID = comp[line].getID();
    Data dat;
    dat.editComp(ID, newValue, type);

}

bool Domain::connectPtoC(string& persID, string& compID)
{
    Data d;
    bool check = true;
    vector<PersonsAndComputers> pAc;
    d.getPACjoined(pAc);
    for (unsigned int i = 0; i < pAc.size(); i++)
    {
        if (persID == pAc[i].getPers_ID() && compID == pAc[i].getComp_ID())
        {
            check = false;
        } else {
            check = true;
        }
    }
    if (check)
    {
        d.writePAC(persID, compID);
        return true;
    }
    else
    {
        return false;
    }
    return true;

}

bool Domain::clear(string& type)
{
    int ttype = 0;
    if (type == "persons")
    {
        ttype = 1;
    }
    else if (type == "computers")
    {
        ttype = 2;
    }
    else if (type == "connections")
    {
        ttype = 3;
    }
    else if (type == "everything")
    {
        ttype = 4;
    }
    Data d;
    if(d.clear(ttype))
        return true;
    return false;
}

string Domain::Lower_Ans(string word)
{
    transform(word.begin(), word.end(), word.begin(), ::tolower); // scope resolution operator
    return word;
}
