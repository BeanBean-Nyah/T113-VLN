#include "domain.h"
#include "data.h"
#include <iostream>

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
    for(unsigned int i = 0; i < persons.size(); i++) {
        cout << persons[i].getFirstname() << " "
             << persons[i].getLastname() << "\t"
             << persons[i].getSex() << "\t"
             << persons[i].getBirth() << "\t"
             << persons[i].getDeath() << endl;
    }
    cout << "================" << endl;;
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

void domain::sort()
{

}

void domain::search()
{

}
