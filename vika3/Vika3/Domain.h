#ifndef DOMAIN_H
#define DOMAIN_H
#include "Person.h"
#include "PersonsAndComputers.h"
#include "persandcomp.h"
#include <vector>
#include <iostream>
#include "Data.h"
#include <algorithm>

using namespace std;

class Domain
{
private:

public:
    Domain();

    bool openDatabase();

    bool add(string& firstname, string& sex, string& birth, string& death);
    bool addComputer(string& name, string& year, string& type, string& built);

    vector<Computer> sortComputer(string& value);
    vector<PersAndComp> sortBoth(string& value);
    vector<Person> sorting(string& input);

    vector<Person> search(string& whattype, string input);
    vector<Computer> searchComputer(string& whattype, string input);
    vector<PersAndComp> searchBoth(string& whattype, string input);

    bool edit(string& _ID, string& _name, string& _sex, string& birth, string& death);
    bool editComputer(string& _ID, string& _name, string& _year, string& _type, string& _built);

    vector<Person> list();
    vector<Computer> computerList();

    bool connectPtoC(string& persID, string& compID);
    bool editPtoC(string& ID);

    void remove(vector<Person>& pers, int& line);
    void removeComputer(vector<Computer>& comp, int& line);
    void removeConnection(vector<PersAndComp>& pAc, int& line);

    vector<PersonsAndComputers> persAndCompList();
    vector<PersAndComp> persAndCompListTest();

    string capFirstLetter(string& str);
    string Lower_Ans(string word);
    bool contains_letters(const string &c);
    bool contains_number(const string &c);

    bool clear(string& type);
    string funFact();
};

#endif // DOMAIN_H
