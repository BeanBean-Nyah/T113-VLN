#ifndef PERSANDCOMP_H
#define PERSANDCOMP_H

#include <string>

using namespace std;

class PersAndComp
{
public:
    PersAndComp();
    PersAndComp(string id, string persName, string compName)
    {
        _id = id;
        _persName = persName;
        _compName = compName;
    }

    string getID()
    {
        return _id;
    }

    string getPersName()
    {
        return _persName;
    }

    string getCompName()
    {
        return _compName;
    }


private:
    string _id;
    string _persName;
    string _compName;
};

#endif // PERSANDCOMP_H
