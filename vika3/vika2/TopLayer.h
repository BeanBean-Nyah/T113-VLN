#ifndef TOPLAYER_H
#define TOPLAYER_H
#include <vector>
#include <string>
#include "Person.h"
#include "Computer.h"
#include "PersonsAndComputers.h"
#include <windows.h>
#include <stdlib.h>
#include <algorithm>

class TopLayer
{
public:
    TopLayer();
    void run();

private:
    void clearScreen();
    void help();
    void editComputer();
    void editPerson();
    string newComputer();
    string newPerson();
    void removeComputer();
    void removePerson();
    void searchComputer();
    void searchPerson();
    void sortComputer();
    void sortPerson();
    void print(vector<Person>& pers);
    void printLine(vector<Person>& pers, const int& i);
    void printLineComputer(vector<Computer>& comp, const int& i);
    void printList(vector<Person>& p);
    void printListComputer(vector<Computer>& p);
    void printPersAndComp(vector<PersonsAndComputers> pAc);
    void printListPersandComp(vector<PersonsAndComputers>& pAc);
    void editPaC();


    char PersOrComp();
    char PCB();

    bool contains_number(const string &c);
    bool contains_letters(const string &c);
    bool isListEmpty();
    bool isPersListEmpty();
    bool isCompListEmpty();
    bool selection();

    string capFirstLetter(string& str);
    string Lower_Ans(string word);

    int lineEntry(const vector<Person>& p);
    int lineEntryComputer(const vector<Computer>& p);
    int lineEntryPaC(const vector<PersonsAndComputers>& p);
    void printComputer(vector<Computer> comp);

    void connectToPerson(string& compID, int& type);
    void connectToComputer(string& ID, int& type);

    string getInputType(int& type);
    string getInputSortType(int& type);
    string getNewFirstname();
    string getNewCompname();
    string getNewSex();
    string getNewBirth();
    string getNewDeath();
    string getNewDate();
    string getNewType();
    string getNewBuilt();

    int modulus(int iN, int iMod);
    char getChar(int iGenerator, char cBase, int iRange);
    void surprise();
};

#endif // TopLayer_H
