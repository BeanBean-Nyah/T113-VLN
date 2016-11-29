#include <iostream>
#include "toplayer.h"
#include "data.h"
#include "person.h"
#include <vector>


using namespace std;

int main()
{
    vector<Person> persons;

    data dat;

    dat.write();
    dat.read(persons);

    for (unsigned int i = 0; i < persons.size(); i++) {
        cout << persons[i].getName() << endl;
        cout << persons[i].getSex() << endl;
        cout << persons[i].getBirth() << endl;
        cout << persons[i].getDeath() << endl;
    }

    toplayer ui;
    ui.run();



    return 0;
}

