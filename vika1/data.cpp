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
    input.open ("..\\vika1\\people.txt");
    while (!input.eof()) {

        input >> aa;

    }
    cout << "---" << aa << endl;
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
        // year born
        output << "1992" << endl;
        output.close();
      }
    else {
        cout << "File didn't open!" << endl;
    }

}

