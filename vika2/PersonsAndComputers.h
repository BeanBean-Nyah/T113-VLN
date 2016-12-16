#ifndef PERSONSANDCOMPUTERS_H
#define PERSONSANDCOMPUTERS_H

#include <string>

using namespace std;

class PersonsAndComputers
{
public:
    PersonsAndComputers();
    PersonsAndComputers(string ID, string pers_ID, string comp_ID);

    string getID()
    {
        return _ID;
    }

    string getPers_ID()
    {
        return _pers_ID;
    }

    string getComp_ID()
    {
        return _comp_ID;
    }

private:
    string _ID;
    string _pers_ID;
    string _comp_ID;
};

#endif // PERSONSANDCOMPUTERS_H
