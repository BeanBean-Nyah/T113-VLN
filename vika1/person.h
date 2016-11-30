#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <sstream>

using namespace std;

class Person
{
public:
    Person();
    Person(string firstname, string lastname, string sex, int birth, string death);


    int getBirth() const
    {
        return _birth;
    }
    string getDeath() const
    {
        return _death;
    }
    string getBirthstring() const
    {
        string bi = static_cast<ostringstream*>( &(ostringstream() << _birth) )->str();
        return bi;
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
    string _death;
    int _birth;
};

#endif // PERSON_H
