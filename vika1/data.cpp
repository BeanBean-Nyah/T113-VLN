#include "data.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;
data::data()
{

}

void data::read(vector<Person>& pers)
{
    string name, sex;
    int birth = 0, death = 0;
    ifstream input;
    input.open ("..\\vika1\\people.txt");
    while (!input.eof()) {

        input >> name >> sex >> birth >> death;
        Person p(name, sex, birth, death);
        pers.push_back(p);
    }

    input.close();

}

void data::write()
{
  ofstream output ("..\\vika1\\people.txt", ios::app);


    if (output.is_open())
      {
        cout << "file is open!" << endl;
        // nafn
        output << "Smari" << endl;
        // sex
        output << "Male" << endl;
        // Birth
        output << "1954" << endl;
        // Death
        output << "2043" << endl;
        output.close();
      }
    else {
        cout << "File didn't open!" << endl;
    }

}

