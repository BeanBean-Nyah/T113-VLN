#include "Domain.h"
#include "Data.h"
#include "Person.h"
#include <iostream>
#include <algorithm>

using namespace std;
Domain::Domain()
{

}

//Skilar skemmitlegri stadreynd
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

//Skilar vector sem inni heldur allar persons
vector<Person> Domain::list()
{
    Data dat;
    vector<Person> persons;
    dat.read(persons);

    return persons;
}

//Segir til um hvort tokst ad opna tengingu vid database
bool Domain::openDatabase()
{
    Data dat;
    if (dat.openDatabase())
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Skilar hvort thad tokst ad skrifa nyja personu i database
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
        }
        else
        {
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

//Skilar hvort thad tokst ad skrifa nyja computer i database
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

//Skilar sorterudum vector af persons
vector<Person> Domain::sorting(string& input)
{
    Data dat;
    vector<Person> pers;
    pers = dat.sortPersons(input);

    return pers;
}

//skilar vector af nidurstodum ur leit
vector<Person> Domain::search(string& whattype, string input)
{
    Data dat;
    vector<Person> persons, res;
    persons = dat.sortPersons(whattype);
    string valname, valsex, valbirth, valdeath, innerinput;
    size_t foundname, foundbirth, foundsex, founddeath;

    for(unsigned int i = 0; i < persons.size(); i++)
    {
        valname = Lower_Ans(persons[i].getFirstname());
        valsex = Lower_Ans(persons[i].getSex());
        valbirth = Lower_Ans(persons[i].getBirth());
        valdeath = Lower_Ans(persons[i].getDeath());
        innerinput = Lower_Ans(input);
        foundname = valname.find(innerinput);
        foundsex = valsex.find(innerinput);
        foundbirth = valbirth.find(innerinput);
        founddeath = valdeath.find(innerinput);

        if (foundname!=string::npos)
        {
            Person p(persons[i].getID(), persons[i].getFirstname(),
                     persons[i].getSex(), persons[i].getBirth(), persons[i].getDeath());
            res.push_back(p);

        }
        else if (foundsex!=string::npos)
        {
            Person p(persons[i].getID(), persons[i].getFirstname(),
                     persons[i].getSex(), persons[i].getBirth(), persons[i].getDeath());
            res.push_back(p);

        }
        else if (foundbirth!=string::npos)
        {
            Person p(persons[i].getID(), persons[i].getFirstname(),
                     persons[i].getSex(), persons[i].getBirth(), persons[i].getDeath());
            res.push_back(p);
        }
        else if (founddeath!=string::npos)
        {
            Person p(persons[i].getID(), persons[i].getFirstname(),
                     persons[i].getSex(), persons[i].getBirth(), persons[i].getDeath());
            res.push_back(p);
        }
    }
    return res;
}

//kallar i fall sem merkir personu eydda i database
void Domain::remove(vector<Person>& pers, int& line)
{
    int type = 0;
    string ID = pers[line].getID();
    Data dat;
    dat.remove(ID, type);
}

//kallar i fall sem breytir upplysingum i database
void Domain::edit(vector<Person>& pers, int& line, string& type, string& newValue)
{
    string ID = pers[line].getID();
    Data dat;
    dat.edit(ID, newValue, type);
}

//Computer functions

//Skilar vector sem inniheldur allar computers ur database
vector<Computer> Domain::computerList()
{
    vector<Computer> comp;
    Data d;
    d.readComputer(comp);
    return comp;
}

//skilar sorterudum vectour af computers ur database
vector<Computer> Domain::sortComputer(string& value)
{
    vector<Computer> comp;
    Data d;
    comp = d.sortComputer(value);
    return comp;
}

//kallar i fall sem fjarlaegir computer ur database
void Domain::removeComputer(vector<Computer>& comp, int& line)
{
    int type = 1;
    string ID = comp[line].getID();
    Data dat;
    dat.remove(ID, type);
}

//Skilar vector af venslum yfir computers og persons
vector<PersonsAndComputers> Domain::persAndCompList()
{
    vector<PersonsAndComputers> pAc;
    Data d;
    d.getPACjoined(pAc);
    return pAc;
}




bool Domain::editPtoC(string& ID)
{
    Data dat;
    if (dat.editPAC(ID))
    {
        return true;
    }
    return false;
}

//skilar vector af nidurstodum ur leit
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

//kallar i fall sem breytir um upplysingum computer i database
void Domain::editComputer(vector<Computer>& comp, int& line, string& type, string& newValue)
{
    string ID = comp[line].getID();
    Data dat;
    dat.editComp(ID, newValue, type);

}

//skilar tvi hvort thad tokst ad tengja person og computer saman
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
        } else
        {
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

//skilar tvi hvort tekist hafi ad hreinsa toflu i database
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
    {
        return true;
    }
    return false;
}

//breytir ollum stofum i streng i lagstafi
string Domain::Lower_Ans(string word)
{
    transform(word.begin(), word.end(), word.begin(), ::tolower); // scope resolution operator
    return word;
}

