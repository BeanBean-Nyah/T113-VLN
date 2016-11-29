#include "toplayer.h"
#include <iostream>

using namespace std;

toplayer::toplayer()
{

}
void toplayer::run()
{
    help();
}
void toplayer::help()
{
    cout << "************************************" << endl;
    cout << "** enter -list for a list          *" << endl;
    cout << "** enter -new  to add a new person *" << endl;
    cout << "************************************" << endl;
}
