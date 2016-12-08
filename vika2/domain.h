#ifndef DOMAIN_H
#define DOMAIN_H
#include "person.h"
#include "personsandcomputers.h"
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

    bool openDatabase();

    bool add(string& firstname, string& sex, string& birth, string& death);
    bool addComputer(string& name, int& year, string& type, string& built);

    vector<Computer> sortComputer(string& value);
    vector<Person> sorting(string& input);

    vector<Person> search(string& whattype, string& input);
    vector<Computer> searchComputer(string& whattype, string& input);

    void edit(vector<Person>& pers, int& line, string& type, string& newValue);
    void editComputer(vector<Computer>& comp, int& line, string& type, string& newValue);

    vector<Person> list();
    vector<Computer> computerList();

    void connectPtoC(string& persID, string& compID);

    void remove(vector<Person>& pers, int& line);
    vector<PersonsAndComputers> persAndCompList();
    string Lower_Ans(string word);

};

#endif // DOMAIN_H
