#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <sstream>

using namespace std;

class Person
{
public:
    Person();
    Person(string firstname, string lastname, string sex, string birth, string death);


    string getBirth() const
    {
        return _birth;
    }
    // Notad til ad sortera eftir birthyear
    int getBirthint() const
    {
        int b = atoi(_birth.c_str());
        return b;
    }
    string getDeath() const
    {
        return _death;
    }
    // Notad til ad sortera eftir deathyear
    int getDeathint() const
    {
        int d = atoi(_death.c_str());
        return d;
    }
    string getFirstname() const
    {
        return _firstname;
    }


    string getLastname() const
    {
        return _lastname;
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
    string _birth;
};

#endif // PERSON_H
