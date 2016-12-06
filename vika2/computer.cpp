#include "computer.h"

Computer::Computer()
{

}

Computer::Computer(string id, string name, string year, string type, string built)
{
    _id = id;
    _name = name;
    _year = year;
    _type = type;
    _built = built;
}
