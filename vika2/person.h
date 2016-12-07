#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <sstream>

using namespace std;

class Person
{
public:
    Person();
    Person(string ID, string firstname, string sex, string birth, string death);

    string getID()
    {
        return _ID;
    }

    // Notad til ad sortera eftir birthyear
    int getBirthint() const
    {
        int b = atoi(_birth.c_str());
        return b;
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
    string getSex() const
    {
        return _sex;
    }
    string getBirth() const
    {
        return _birth;
    }
    string getDeath() const
    {
        return _death;
    }
    void setFirstname(const string& fn)
    {
         _firstname = fn;
    }
    void setSex(const string& sex)
    {
        _sex = sex;
    }
    void setBirth(const string& b)
    {
        _birth = b;
    }
    void setDeath(const string& d)
    {
        _death = d;
    }

private:
    string _ID;
    string _firstname;
    string _sex;
    string _birth;
    string _death;
};

#endif // PERSON_H
