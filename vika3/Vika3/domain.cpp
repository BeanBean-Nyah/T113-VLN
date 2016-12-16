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
          break;
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
            break;
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
bool Domain::edit(string& _ID, string& _name, string& _sex, string& _birth, string& _death)
{
    Data dat;
    bool check = true;
    vector<Person> persons;
    dat.read(persons);
    for (unsigned int i = 0; i < persons.size(); i++)
    {
        if (_name == persons[i].getFirstname() && _sex == persons[i].getSex() &&
                _birth == persons[i].getBirth() && _death == persons[i].getDeath())
        {
          check = false;
          break;
        }
        else
        {
            check = true;
        }
    }
    if (check)
    {
        dat.edit(_ID, _name, _sex, _birth, _death);
        return true;
    }
    else
    {
        return false;
    }
    return true;
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

vector<PersAndComp> Domain::sortBoth(string &value)
{
    vector<PersAndComp> pAc;
    Data d;
    pAc = d.sortBoth(value);
    return pAc;
}

//kallar i fall sem fjarlaegir computer ur database
void Domain::removeComputer(vector<Computer>& comp, int& line)
{
    int type = 1;
    string ID = comp[line].getID();
    Data dat;
    dat.remove(ID, type);
}

//kallar i fall sem fjarlaegir vensl ur database
void Domain::removeConnection(vector<PersAndComp>& pAc, int& line)
{
    int type = 2;
    string ID = pAc[line].getID();
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

vector<PersAndComp> Domain::persAndCompListTest()
{
    vector<PersAndComp> pAc;
    Data d;
    d.getPACjoinedTest(pAc);
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
vector<Computer> Domain::searchComputer(string& whattype, string input)
{
    Data dat;
    vector<Computer> computers, res;
    computers = dat.sortComputer(whattype);

    string valname, valyear, valtype, valbuilt, innerinput;
    size_t foundname, foundyear, foundtype, foundbuilt;


    for(unsigned int i = 0; i < computers.size(); i++)
    {
        valname = Lower_Ans(computers[i].getName());
        valyear = Lower_Ans(computers[i].getYear());
        valtype = Lower_Ans(computers[i].getType());
        valbuilt = Lower_Ans(computers[i].getBuilt());
        innerinput = Lower_Ans(input);
        foundname = valname.find(innerinput);
        foundyear = valyear.find(innerinput);
        foundtype = valtype.find(innerinput);
        foundbuilt = valbuilt.find(innerinput);

        if (foundname!=string::npos)
        {
            Computer c(computers[i].getID(), computers[i].getName(),
                       computers[i].getYear(), computers[i].getType(), computers[i].getBuilt());
            res.push_back(c);
        }
        else if (foundyear!=string::npos)
        {
            Computer c(computers[i].getID(), computers[i].getName(),
                       computers[i].getYear(), computers[i].getType(), computers[i].getBuilt());
            res.push_back(c);
        }
        else if(foundtype!=string::npos)
        {
            Computer c(computers[i].getID(), computers[i].getName(),
                       computers[i].getYear(), computers[i].getType(), computers[i].getBuilt());
            res.push_back(c);
        }
        else if(foundbuilt!=string::npos)
        {
            Computer c(computers[i].getID(), computers[i].getName(),
                       computers[i].getYear(), computers[i].getType(), computers[i].getBuilt());
            res.push_back(c);
        }

    }
    return res;
}

//skilar vector af nidurstodum ur leit
vector<PersAndComp> Domain::searchBoth(string& whattype, string input)
{
    Data dat;
    vector<PersAndComp> pAc, res;
    pAc = dat.sortBoth(whattype);

    string valcompname, valpersname, innerinput;
    size_t foundcompname, foundpersname;


    for(unsigned int i = 0; i < pAc.size(); i++)
    {
        valcompname = Lower_Ans(pAc[i].getCompName());
        valpersname = Lower_Ans(pAc[i].getPersName());
        innerinput = Lower_Ans(input);
        foundcompname = valcompname.find(innerinput);
        foundpersname = valpersname.find(innerinput);

        if (foundcompname!=string::npos)
        {
            PersAndComp c(pAc[i].getID(), pAc[i].getPersName(), pAc[i].getCompName());
            res.push_back(c);
        }
        else if (foundpersname!=string::npos)
        {
            PersAndComp c(pAc[i].getID(), pAc[i].getPersName(), pAc[i].getCompName());
            res.push_back(c);
        }
    }
    return res;
}

//kallar i fall sem breytir um upplysingum computer i database


bool Domain::editComputer(string& _ID, string& _name, string& _year, string& _type, string& _built)
{
    Data dat;
    bool check = true;
    vector<Computer> comp;
    dat.readComputer(comp);
    for (unsigned int i = 0; i < comp.size(); i++)
    {
        if (_name == comp[i].getName() && _year == comp[i].getYear() &&
                _type == comp[i].getType() && _built == comp[i].getBuilt())
        {
            check = false;
            break;
        }
        else
        {
            check = true;
        }
    }
    if (check)
    {
        dat.editComp(_ID, _name, _year, _type, _built);
        return true;
    }
    else
    {
        return false;
    }
    return true;
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

// Villutjekk, athugar hvort thad se tolustafur i strengnum
bool Domain::contains_number(const string &c)
{
    return (c.find_first_of("0123456789") != string::npos);
}

// Villutjekk, athugar hvort thad se bokstafur i strengnum
bool Domain::contains_letters(const string &c)
{
    return (c.find_first_of("qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM") != string::npos);
}

// Gerir alla stafi i streng lower case
string Domain::Lower_Ans(string word)
{
    transform(word.begin(), word.end(), word.begin(), ::tolower); // scope resolution operator
    return word;
}

// Fixar input thannig ad fyrsti stafur er alltaf stor og rest litlir
string Domain::capFirstLetter(string& str)
{
    string output = Lower_Ans(str);
    size_t f = output.find(" ");
    output[0] = toupper(output[0]);
    output[f+1] = toupper(output[f+1]);
    f = output.find(" ",f+1);
    output[f+1] = toupper(output[f+1]);
    return output;
}

string Domain::aboutPerson(string& _ID)
{
    Data dat;
    string retValue = dat.getInfo(_ID);
    return retValue;
}

string Domain::aboutComputer(string& _ID)
{
    Data dat;
    return dat.getInfoComputer(_ID);
}
