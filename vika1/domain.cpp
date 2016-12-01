#include "domain.h"
#include "data.h"
#include "person.h"
#include <iostream>
#include <algorithm>

//prufu komment

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

void domain::add(string& firstname, string& lastname, string& sex, string& birth, string& death)
{
    data dat;
    dat.write(firstname, lastname, sex, birth, death);
}


struct FirstNameComparison {
  bool operator() (Person i,Person j) { return (i.getFirstname()<j.getFirstname());}
}firstName;

struct LastNameComparison {
  bool operator() (Person i,Person j) { return (i.getLastname()<j.getLastname());}
}lastName;

struct SexSorting {
  bool operator() (Person i,Person j) { return (i.getSex()<j.getSex());}
}sex;

struct BirthYearSorting {
  bool operator() (Person i,Person j) { return (i.getBirthint()<j.getBirthint());}
}yearBorn;

struct DeathYearSorting {
  bool operator() (Person i,Person j) { return (i.getDeathint()<j.getDeathint());}
}yearDeath;

vector<Person> domain::sort(string& input)
{
    data dat;
    vector<Person> persons;
    dat.read(persons);

    if (input == "-firstname") {
        std::sort(persons.begin(), persons.end(), firstName);
    }
    else if (input == "-lastname")
    {
        std::sort(persons.begin(), persons.end(), lastName);
    }
    else if (input == "-sex")
    {
        std::sort(persons.begin(), persons.end(), sex);
    }
    else if (input == "-yearborn")
    {
        std::sort(persons.begin(), persons.end(), yearBorn);
    }
    else if (input == "-deathyear")
    {
        std::sort(persons.begin(), persons.end(), yearDeath);
    }
    return persons;
}

vector<Person> domain::search(string& whattype, string& input)
{
    data dat;
    vector<Person> persons, res;
    dat.read(persons);

    for(unsigned int i = 0; i < persons.size(); i++) {
        if (whattype == "-firstname")
        {
            if(persons[i].getFirstname() == input)
            {
                Person p(persons[i].getFirstname(), persons[i].getLastname(),
                       persons[i].getSex(), persons[i].getBirth(), persons[i].getDeath());
                res.push_back(p);
            }
        } else if (whattype == "-lastname"){
            if(persons[i].getLastname() == input)
            {
                Person p(persons[i].getFirstname(), persons[i].getLastname(),
                       persons[i].getSex(), persons[i].getBirth(), persons[i].getDeath());
                res.push_back(p);
            }
        } else if (whattype == "-sex"){
            if(persons[i].getSex() == input)
            {
                Person p(persons[i].getFirstname(), persons[i].getLastname(),
                       persons[i].getSex(), persons[i].getBirth(), persons[i].getDeath());
                res.push_back(p);
            }
        } else if (whattype == "-birthyear"){
            if(persons[i].getBirth() == input)
            {
                Person p(persons[i].getFirstname(), persons[i].getLastname(),
                       persons[i].getSex(), persons[i].getBirth(), persons[i].getDeath());
                res.push_back(p);
            }
        } else if (whattype == "-deathyear"){
            if(persons[i].getDeath() == input)
            {
                Person p(persons[i].getFirstname(), persons[i].getLastname(),
                       persons[i].getSex(), persons[i].getBirth(), persons[i].getDeath());
                res.push_back(p);
            }
        }
    }
    return res;
}

void domain::edit(vector<Person>& pers) {
    data dat;
    dat.remove(pers);
}
