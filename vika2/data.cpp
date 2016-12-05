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

    string firstname, lastname, sex, birth, death;
    ifstream input;
    input.open ("..\\vika1\\people.txt");
    while (input >> firstname >> lastname >> sex >> birth >> death) {
        Person p(firstname, lastname, sex, birth, death);
        pers.push_back(p);
    }

    input.close();

}

void data::write(string& firstname, string& lastname, string& sex, string& birth, string& death)
{
  ofstream output ("..\\vika1\\people.txt", ios::app);

    if (output.is_open())
    {
        // nafn
        output << firstname << endl;
        output << lastname  << endl;
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
//Overridear people.txt med nyjum vector
void data::remove(vector<Person>& pers) {
    ofstream output ("..\\vika1\\people.txt");

      if (output.is_open())
      {
          for (unsigned int i = 0; i < pers.size(); i++) {
          output << pers[i].getFirstname() << endl;
          output << pers[i].getLastname()  << endl;
          output << pers[i].getSex()  << endl;
          output << pers[i].getBirth() << endl;
          output << pers[i].getDeath()  << endl;
          }
          output.close();
      }
      else
      {
          cout << "File didn't open!" << endl;
      }
}
