#include "person.h"

Person::Person()
{

}

Person::Person(string ID, string firstname, string sex, string birth, string death)
{
    _ID = ID;
    _firstname  = firstname;
    _sex   = sex;
    _birth = birth;
    _death = death;
}
