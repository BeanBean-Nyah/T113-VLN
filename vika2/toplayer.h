#ifndef TOPLAYER_H
#define TOPLAYER_H
#include <vector>
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
    void printList(vector<Person>& p);
    void printLine(vector<Person>& pers, const int& i);
    void clearScreen();
    void print(vector<Person>& pers);

    bool selection();
    bool contains_number(const string &c);
    bool contains_letters(const string &c);
    bool isListEmpty();

    string Lower_Ans(string word);
    string capFirstLetter(string& str);


    int lineEntry(const vector<Person>& p);

    string getInputType();
    string getNewFirstname();
    string getNewLastname();
    string getNewSex();
    string getNewBirth();
    string getNewDeath();
};

#endif // TOPLAYER_H
