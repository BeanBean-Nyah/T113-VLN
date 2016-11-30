#include "domain.h"
#include "data.h"
#include "person.h"
#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;
domain::domain()
{

}

void domain::list()
{
    data dat;
    vector<Person> persons;
    dat.read(persons);
    cout << "===== List =====" << endl;
    print(persons);
}

void domain::add()
{
    string firstname, lastname, sex, death;
    int birth;
    cout << "Enter first and last name: ";
    cin >> firstname;
    cin >> lastname;
    cout << "Enter sex: ";
    cin >> sex;
    cout << "Enter year of birth: ";
    cin >> birth;
    cout << "Enter year of death, if the person has not died please type \"-\": ";
    cin >> death;

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
  bool operator() (Person i,Person j)
  {
      return (i.getBirth()<j.getBirth());
  }
}yearBorn;

struct DeathYearSorting {
  bool operator() (Person i,Person j) { return (i.getDeath()<j.getDeath());}
}yearDeath;

void domain::sort()
{
    data dat;
    vector<Person> persons;
    dat.read(persons);
    string input;
    cout << "What do you want to sort by?" << endl;
    cout << "-firstname" << endl << "-lastname" << endl << "-sex" << endl
         << "-yearborn" << endl << "-deathyear" << endl;
    cin >> input;
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

    cout << "===== Sorted list =====" << endl;
    print(persons);

}

void domain::print(vector<Person>& pers)
{
    for(unsigned int i = 0; i < pers.size(); i++) {
        cout << pers[i].getFirstname() << "\t"
             << pers[i].getLastname()  << "\t"
             << pers[i].getSex() << "\t"
             << pers[i].getBirth() << "\t"
             << pers[i].getDeath() << endl;
    }
    cout << "============================" << endl;
}


void domain::search(string input)
{
    data dat;
    vector<Person> persons;
    dat.read(persons);
    cout << "===== Search results =====" << endl;
    for(unsigned int i = 0; i < persons.size(); i++) {
            if(persons[i].getFirstname() == input)
            {
                cout << persons[i].getFirstname() << " "
                     << persons[i].getLastname() << "\t"
                     << persons[i].getSex() << "\t"
                     << persons[i].getBirth() << "\t"
                     << persons[i].getDeath() << endl;
            }
    }
    cout << "================" << endl;
}
