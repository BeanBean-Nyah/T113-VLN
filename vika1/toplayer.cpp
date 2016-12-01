#include "toplayer.h"
#include "domain.h"
#include <iostream>


using namespace std;

toplayer::toplayer()
{

}
void toplayer::run()
{
    help();
    cout << "\n Enter -help to display the command list again " << endl;
    while(selection())
    {

    }
}
void toplayer::help()
{
    cout << "*********************************************************" << endl;
    cout << "**        Notable Computer Scientists In History       **" << endl;
    cout << "**                                                     **" << endl;
    cout << "**     Enter -new to add a new person                  **" << endl;
    cout << "**     Enter -list for a full list                     **" << endl;
    cout << "**     Enter -search to search the list                **" << endl;
    cout << "**     Enter -remove to remove element from the list   **" << endl;
    cout << "**     Enter -sort to sort the list                    **" << endl;
    cout << "**     Enter -exit to exit the program                 **" << endl;
    cout << "**                                                     **" << endl;
    cout << "*********************************************************" << endl;
}

void toplayer::print(vector<Person>& pers) {

    for(unsigned int i = 0; i < pers.size(); i++) {
        cout.width(10);
        cout << left;
        cout << pers[i].getFirstname();
        cout.width(10);
        cout <<left;
        cout << pers[i].getLastname();
        cout.width(10);
        cout << left;
        cout << pers[i].getSex();
        cout.width(10);
        cout <<left;
        cout << pers[i].getBirth();
        cout.width(10);
        cout << left;
        cout << pers[i].getDeath() << endl;
    }
    cout << "======================================" << endl;

}

bool toplayer::selection()
{
    string input;
    cin >> input;
    if (input == "-list")
    {
        vector<Person> p;
        domain d;
        p = d.list();
        cout << "================ List ================" << endl;
        print(p);
    }
    else if (input == "-search")
    {
        vector<Person> p;
        domain d;
        string whattype, input;
        cout << "What do you want to search for?" << endl;
        cout << "-firstname" << endl << "-lastname" << endl << "-sex"
             << endl << "-birthyear" << endl << "-deathyear" << endl;
        cout << "Enter your choice: ";
        cin >> whattype;
        cout << "What is word do you want to serch for? ";
        cin >> input;
        p = d.search(whattype, input);
        if (p.size() == 0){
            cout << "Sorry, no results!" << endl;
        } else {
            cout << "===== Search results =====" << endl;
            print(p);
        }

    }
    else if (input == "-new")
    {
        string firstname, lastname, sex, death;
        int birth;
        cout << "Enter first and last name: ";
        cin >> firstname;
        cin >> lastname;
        cout << "Enter sex: ";
        cin >> sex;
        cout << "Enter year of birth: ";
        while(!(cin>>birth)) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input!" << endl << "Try again: ";
            }
        cout << "Enter year of death, if the person has not died please type \"-\": ";
        cin >> death;
        domain d;
        d.add(firstname, lastname, sex, birth, death);
        cout << "You successfully created new person!" << endl;
    }
    else if (input == "-sort")
    {
        vector<Person> p;
        string input;
        cout << "What do you want to sort by?" << endl;
        cout << "-firstname" << endl << "-lastname" << endl << "-sex" << endl
             << "-yearborn" << endl << "-deathyear" << endl;
        cin >> input;
        domain d;
        p = d.sort(input);
        cout << "===== Sorted list =====" << endl;
        print(p);
    }
    else if (input == "-remove")
    {
        unsigned int lineNumber = 1;
        vector<Person> p;
        domain d;
        p = d.list();
        cout << "===== List =====" << endl;
        for(unsigned int i = 0; i < p.size(); i++){
            cout << i+1 << "\t"
                 << p[i].getFirstname() << "\t"
                 << p[i].getLastname() << "\t"
                 << p[i].getSex() << "\t"
                 << p[i].getBirth() << "\t"
                 << p[i].getDeath() << endl;
        }
        cout << "Which entry do you want to remove?" << endl;
        cout << "Type the line number: ";
        do {
            if (lineNumber <= 0 || lineNumber > p.size()) {
                cout << "Sorry this isn't a vailid line, try again: ";
            }
            cin >> lineNumber;
        } while (lineNumber <= 0 || lineNumber > p.size());
        p.erase (p.begin()+(lineNumber-1));
        d.remove(p);
        cout << "You successfully removed line " << lineNumber << endl;
    }
    else if (input == "-help")
    {
        help();
    }
    else if (input == "-exit")
    {
        return false;
    }
    else
    {
        cout << "This command does not exist" << endl;
    }
    return true;

}

