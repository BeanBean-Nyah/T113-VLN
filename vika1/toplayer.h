#ifndef TOPLAYER_H
#define TOPLAYER_H
#include <vector>
#include "person.h"
#include <stdlib.h>
class toplayer
{
public:
    toplayer();
    void run();
    void print(vector<Person>& pers);
private:
    void help();
    bool selection();
    bool contains_number(const string &c);
    bool contains_letters(const string &c);
    void clearScreen();
};

#endif // TOPLAYER_H
