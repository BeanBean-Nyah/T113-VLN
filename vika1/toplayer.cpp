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
    cout << "\n Enter -help to display the command list again " << endl;
    while(selection())
    {

    }
}
void toplayer::help()
{
    cout << "*********************************************" << endl;
    cout << "**  Notable Computer Scientists In History **" << endl;
    cout << "**                                         **" << endl;
    cout << "**     Enter -new to add a new person      **" << endl;
    cout << "**     Enter -list for a full list         **" << endl;
    cout << "**     Enter -search to search the list    **" << endl;
    cout << "**     enter -sort to sort the list        **" << endl;
    cout << "**     Enter -exit to exit the program     **" << endl;
    cout << "**                                         **" << endl;
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
    else if (input == "-search")
    {
        domain d;
        string in;
        cout << "enter a name to search for: ";
        cin >> in;
        d.search(in);
    }
    else if (input == "-new")
    {
        domain d;
        d.add();
    }
    else if (input == "-sort")
    {
        domain d;
        d.sort();
    }
    else if (input == "-search")
    {
        domain d;
        string in;
        cout << "enter a name to search for: ";
        cin >> in;
        d.search(in);
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
