#ifndef TOPLAYER_H
#define TOPLAYER_H
#include <vector>
#include <string>
#include "person.h"
#include <stdlib.h>
#include <algorithm>

class toplayer
{
public:
    toplayer();
    void run();

private:
    void help();
    void newPerson();
    void searchPerson();
    void newComputer();
    void searchComputer();
    void printList(vector<Person>& p);
    void printLine(vector<Person>& pers, const int& i);
    void clearScreen();
    void print(vector<Person>& pers);

    char PersOrComp();

    bool selection();
    bool contains_number(const string &c);
    bool contains_letters(const string &c);
    bool isListEmpty();

    string Lower_Ans(string word);
    string capFirstLetter(string& str);


    int lineEntry(const vector<Person>& p);

    string getInputType();
    string getNewFirstname();
    string getNewSex();
    string getNewBirth();
    string getNewDeath();
    string getNewDate();
};

#endif // TOPLAYER_H
