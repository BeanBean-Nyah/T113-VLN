#include "person.h"

Person::Person()
{

}

Person::Person(string firstname, string sex, string birth, string death)
{
    _firstname  = firstname;
    _sex   = sex;
    _birth = birth;
    _death = death;
}
