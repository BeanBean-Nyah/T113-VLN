#include "toplayer.h"
#include <iostream>
#include <cstdlib>

using namespace std;

toplayer::toplayer()
{

}
void toplayer::run()
{
    help();
    cout << "\n enter -help to display the command list again " << endl;
    for (int i = 0; i < 100; i++)
    {
        selection();
    }
}
void toplayer::help()
{
    cout << "*************************************" << endl;
    cout << "** enter -list for a list          **" << endl;
    cout << "** enter -new  to add a new person **" << endl;
    cout << "** enter -exit to exit the program **" << endl;
    cout << "*************************************" << endl;
}
void toplayer::selection()
{
    string input;
    cin >> input;
    if (input == "-list")
    {
        cout << "getting list";
        //todo
    }
    else if (input == "-new")
    {
        cout << "adding new";
        //todo
    }
    else if (input == "-help")
    {
        help();
    }
    else if (input == "-exit")
    {
        exit(0);
    }
    else
    {
        cout << "this command does not exist" << endl;
    }

}
