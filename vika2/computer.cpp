#include "computer.h"

Computer::Computer()
{

}

Computer::Computer(string name, string year, string type, string built, string creator)
{
    _name = name;
    _year = year;
    _type = type;
    _built = built;
    _creator = creator;
}
