#include "domain.h"
#include "data.h"
#include "person.h"
#include <iostream>
#include <algorithm>

using namespace std;
domain::domain()
{

}

void domain::list()
{
    data dat;
    vector<Person> persons;
    dat.read(persons);

    print(persons);
/*=======
    for(unsigned int i = 0; i < persons.size(); i++) {
        cout << persons[i].getFirstname() << " "
             << persons[i].getLastname() << "\t"
             << persons[i].getSex() << "\t"
             << persons[i].getBirth() << "\t"
             << persons[i].getDeath() << endl;
    }
    cout << "================" << endl;;
>>>>>>> 78de1fdcef954b32a8b367d0ab919d264399f663*/
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


struct PersonComparison {
  bool operator() (Person i,Person j) { return (i.getFirstname()<j.getFirstname());}
}myob;


void domain::sort()
{
    data dat;
    vector<Person> persons;
    dat.read(persons);

    std::sort(persons.begin(), persons.end(), myob);

    print(persons);

}

void domain::print(vector<Person>& pers)
{


    cout << "=========== List ===========" << endl;
    for(unsigned int i = 0; i < pers.size(); i++) {
        cout << pers[i].getFirstname() << " "
             << pers[i].getLastname()  << "\t"
             << pers[i].getSex() << "\t"
             << pers[i].getBirth() << "\t"
             << pers[i].getDeath() << endl;    }
    cout << "============================" << endl;
}


void domain::search(string input)
{
    data dat;
    vector<Person> persons;
    dat.read(persons);
    cout << "===== List =====" << endl;
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
    cout << "================" << endl;;
}
