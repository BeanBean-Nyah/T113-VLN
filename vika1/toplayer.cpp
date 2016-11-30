#include "toplayer.h"
#include "domain.h"
#include <iostream>


using namespace std;

toplayer::toplayer()
{

}
void toplayer::run()
{
    help();
    cout << "\n enter -help to display the command list again " << endl;
    while(selection())
    {

    }
}
void toplayer::help()
{
    cout << "*********************************************" << endl;
    cout << "**     enter -list for a list              **" << endl;
    cout << "**     enter -search to search the list    **" << endl;
    cout << "**     enter -new  to add a new person     **" << endl;
    cout << "**     enter -exit to exit the program     **" << endl;
    cout << "*********************************************" << endl;
}
bool toplayer::selection()
{
    string input;
    cin >> input;
    if (input == "-list")
    {
        domain d;
        d.list();
    }
    if (input == "-search")
    {
        domain d;
        d.search();
    }
    else if (input == "-new")
    {
        domain d;
        d.add();
    }
    else if (input == "-help")
    {
        help();
    }
    else if (input == "-exit")
    {
        return false;
    }
    else
    {
        cout << "this command does not exist" << endl;
    }
    return true;

}
