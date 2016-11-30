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
    cout << "===== List =====" << endl;
    print(persons);
}

void domain::add()
{
    string name, sex;
    int birth, death;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter sex: ";
    cin >> sex;
    cout << "Enter year of birth: ";
    cin >> birth;
    cout << "Enter year of death: ";
    cin >> death;

    data dat;
    dat.write(name, sex, birth, death);
}


struct PersonComparison {
  bool operator() (Person i,Person j) { return (i.getName()<j.getName());}
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
    cout << pers[1].getBirth();

    /*cout << "===== List =====" << endl;
    for(unsigned int i = 0; i < pers.size(); i++) {
        cout << pers[i].getName() << "\t" << pers[i].getSex() << "\t"
        << pers[i].getBirth() << "\t" << pers[i].getDeath() << endl;
    }
    cout << "================" << endl;*/
}

void domain::search()
{

}
