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
    void add(string& firstname, string& sex, string& birth, string& death);
    vector<Person> sorting(string& input);
    vector<Person> search(string& whattype, string& input);
    void remove(vector<Person>& pers, int& line);
    void edit(vector<Person>& pers, int& line, string& type, string& newValue);
    void openDatabase();
};

#endif // DOMAIN_H
