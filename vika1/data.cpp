#include "data.h"
#include <iostream>
#include <fstream>

using namespace std;
data::data()
{

}

void data::read()
{
    string aa;
    ifstream input;
    input.open ("people.txt");
    while (input >> aa) {
        cout << aa << endl;
    }
}

void data::write()
{
    ofstream output;
    output.open ("people.txt");


    if (output.is_open())
      {
        cout << "file is open!" << endl;
        // nafn
        output << "Smari MC";
        // year born
        output << "1992" << endl;
        output.close();
      }
    else {
        cout << "File didn't open!" << endl;
    }


}
