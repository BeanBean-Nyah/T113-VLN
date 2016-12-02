#ifndef DOMAIN_H
#define DOMAIN_H
#include "person.h"
#include <vector>
#include <iostream>
#include "data.h"
#include <algorithm>

using namespace std;

class domain
{
private:

public:
    domain();
    vector<Person> list();
    void add(string& firstname, string& lastname, string& sex, string& birth, string& death);
    vector<Person> sorting(string& input);
    vector<Person> search(string& whattype, string& input);
    void edit(vector<Person>& pers);
};

#endif // DOMAIN_H
