#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person
{
public:
    Person();
    Person(string firstname, string lastname, string sex, int birth, int death);


    int getBirth() const
    {
        return _birth;
    }
    int getDeath() const
    {
        return _death;
    }
    string getFirstname() const
    {
        return _firstname;
    }
    void setFirstname(string firstname)
    {
        _firstname = firstname;
    }

    string getLastname() const
    {
        return _lastname;
    }
    void setLastname(string lastname)
    {
       _lastname = lastname;
    }

    string getSex() const
    {
        return _sex;
    }


private:
    string _firstname;
    string _lastname;
    string _sex;
    int _death;
    int _birth;
};

#endif // PERSON_H
