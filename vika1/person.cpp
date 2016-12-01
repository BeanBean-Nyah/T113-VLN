#include "person.h"

Person::Person()
{

}

Person::Person(string firstname, string lastname, string sex, string birth, string death)
{
    _firstname  = firstname;
    _lastname = lastname;
    _sex   = sex;
    _birth = birth;
    _death = death;
}
