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
    void add(string& firstname, string& sex, string& birth, string& death);
    void addComputer(string& name, int& year, string& type, string& built);
    vector<Computer> sortComputer(string& value);
    vector<Person> sorting(string& input);
    vector<Person> search(string& whattype, string& input);
    void edit(vector<Person>& pers, int& line, string& type, string& newValue);
    vector<Person> list();
    void openDatabase();
    vector<Computer> computerList();
    void remove(vector<Person>& pers, int& line);

};

#endif // DOMAIN_H
