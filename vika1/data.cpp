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

void data::write(string& name, string& sex, int& birth, int& death)
{
  ofstream output ("..\\vika1\\people.txt", ios::app);

    if (output.is_open())
    {
        // nafn
        output << name << endl;
        // sex
        output << sex << endl;
        // Birth
        output << birth << endl;
        // Death
        output << death << endl;
        output.close();
    }
    else
    {
        cout << "File didn't open!" << endl;
    }

}

