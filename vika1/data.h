#ifndef DATA_H
#define DATA_H

#include "person.h"

#include <iostream>
#include <fstream>
#include <vector>


class data
{
private:

public:
    data();
    void read(vector<Person>& pers);
    void write();

};

#endif // DATA_H
