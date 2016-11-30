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
    string firstname, lastname, sex;
    int birth = 0, death = 0;
    ifstream input;
    input.open ("..\\vika1\\people.txt");
    while (!input.eof()) {

        input >> firstname >> lastname >> sex >> birth >> death;
        Person p(firstname, lastname, sex, birth, death);
        pers.push_back(p);
    }

    input.close();

}

void data::write(string& firstname, string& lastname, string& sex, int& birth, int& death)
{
  ofstream output ("..\\vika1\\people.txt", ios::app);

    if (output.is_open())
    {
        // nafn
        output << firstname  << lastname  << endl;
        // sex
        output << sex  << endl;
        // Birth
        output << birth  << endl;
        // Death
        output << death  << endl;
        output.close();
    }
    else
    {
        cout << "File didn't open!" << endl;
    }

}

