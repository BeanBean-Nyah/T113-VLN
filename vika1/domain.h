#ifndef DOMAIN_H
#define DOMAIN_H
#include "person.h"
#include <vector>
#include <iostream>
#include "data.h"

using namespace std;

class domain
{
public:
    domain();
    vector<Person> list();
    void add(string& firstname, string& lastname, string& sex, int& birth, string& death);
    vector<Person> sort(string& input);
    vector<Person> search(string& whattype, string& input);
    void remove(vector<Person>& pers);
};

#endif // DOMAIN_H
