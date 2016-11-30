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
    void list();
    void add();
    void sort();

    void print(vector<Person>& pers);


    void search(string input);
};

#endif // DOMAIN_H
