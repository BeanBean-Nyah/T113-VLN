#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person
{
public:
    Person();
    Person(string name, string sex, int birth, int death);


    int getBirth() const
    {
        return _birth;
    }
    int getDeath() const
    {
        return _death;
    }
    string getName() const
    {
        return _name;
    }
    string getSex() const
    {
        return _sex;
    }


private:
    string _name;
    string _sex;
    int _death;
    int _birth;
};

#endif // PERSON_H
