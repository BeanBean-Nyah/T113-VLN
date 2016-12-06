#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
#include <sstream>


using namespace std;

class Computer
{
public:
    Computer();

    Computer(string id, string name, string year, string type, string built);

    int getYearint() const
    {
        int y = atoi(_year.c_str());
        return y;
    }

    string getName() const
    {
        return _name;
    }

    string getType() const
    {
        return _type;
    }

    string getBuilt() const
    {
        return _built;
    }

    void setName(const string& n)
    {
        _name = n;
    }

    void setYear(const string& y)
    {
        _year = y;
    }

    void setType(const string& t)
    {
        _type = t;
    }

    void setBuilt(const string& b)
    {
        _built = b;
    }

private:
    string _id;
    string _name;
    string _year;
    string _type;
    string _built;

};

#endif // COMPUTER_H
