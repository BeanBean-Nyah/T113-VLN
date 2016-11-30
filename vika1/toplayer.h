#ifndef TOPLAYER_H
#define TOPLAYER_H
#include <vector>
#include "person.h"

class toplayer
{
public:
    toplayer();
    void run();
    void print(vector<Person>& pers);
private:
    void help();
    bool selection();
};

#endif // TOPLAYER_H
