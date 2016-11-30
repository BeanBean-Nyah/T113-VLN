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
    void write(string& name, string& sex, int& birth, int& death);

};

#endif // DATA_H
