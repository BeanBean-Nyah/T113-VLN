#include "person.h"

Person::Person()
{

}

Person::Person(string name, string sex, int birth, int death)
{
    _name  = name;
    _sex   = sex;
    _birth = birth;
    _death = death;
}
