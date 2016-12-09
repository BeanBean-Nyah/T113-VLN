#ifndef FACTS_H
#define FACTS_H

#include <string>

using namespace std;

class Facts
{
public:
    Facts();
    Facts(int ID, string funfact);

    string getFact()
    {
        return _funfact;
    }

private:
    int _ID;
    string _funfact;
};

#endif // FACTS_H
