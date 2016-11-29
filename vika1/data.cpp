#include "data.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
data::data()
{

}

void data::read()
{
    string aa;
    ifstream input;
    input.open ("people.txt");
    while (!input.eof()) {
        input >> aa;
    }
    cout << "---" << aa << endl;

}

void data::write()
{
    ofstream output ("people1.txt");


    if (output.is_open())
      {
        cout << "file is open!" << endl;
        // nafn
        output << "Smari" << endl;
        // year born
        output << "1992" << endl;
        output.close();
      }
    else {
        cout << "File didn't open!" << endl;
    }

}

