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
        cout << persons[i].getName() << "\t" << persons[i].getSex() << "\t"
        << persons[i].getBirth() << "\t" << persons[i].getDeath() << endl;
    }
    cout << "================" << endl;;
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

void domain::sort()
{

}
