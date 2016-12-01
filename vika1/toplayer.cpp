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
        cout.width(12);
        cout<<left;
        cout << pers[i].getFirstname();
        cout.width(12);
        cout<<left;
        cout << pers[i].getLastname();
        cout.width(10);
        cout<<left;
        cout << pers[i].getSex();
        cout.width(10);
        cout<<left;
        cout << pers[i].getBirth();
        cout.width(10);
        cout<<left;
        cout << pers[i].getDeath()<<endl;
    }
    cout << "================================================" << endl << endl;
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
        cout << "===================== List =====================" << endl;
        print(p);
        system("pause");
        clearScreen();
        help();
    }
    else if (input == "-search")
    {
        vector<Person> p;
        domain d;
        string whattype, input;
        cout << "What do you want to search for?" << endl;
        cout << "-firstname" << endl << "-lastname" << endl << "-sex"
             << endl << "-birth" << endl << "-death" << endl;
        cout << "Enter your choice: ";
        do {
            cin >> whattype;
            if (whattype != "-firstname" && whattype != "-lastname" && whattype != "-sex" &&
                whattype != "-birth" && whattype != "-death") {
                cout << whattype << " is not valid input! Try again: ";
            }
        } while (whattype != "-firstname" && whattype != "-lastname" && whattype != "-sex" &&
                 whattype != "-birth" && whattype != "-death");

        cout << "What is the word you want to search for? ";
        cin >> input;
        p = d.search(whattype, input);
        if (p.size() == 0){
            cout << "Sorry, no results!" << endl;
        } else {
            cout << "===== Search results =====" << endl;
            print(p);
        }
        system("pause");
        clearScreen();
        help();
    }
    else if (input == "-new")
    {
        string firstname, lastname, sex, birth, death;

        cout << "Enter first name: ";
        do {
            cin >> firstname;
            if (contains_number(firstname)) {
                cout << "First name can not contain numbers try again: ";
            }
        } while (contains_number(firstname));

        cout << "Enter last name: ";
        do {
            cin >> lastname;
            if (contains_number(lastname)) {
                cout << "Last name can not contain numbers try again: ";
            }
        } while (contains_number(lastname));

        cout << "Enter sex: ";
        do {
            cin >> sex;
            if (sex != "male" && sex != "female"){
                cout << sex << " is not a gender, please choose male or female: ";
            }
        } while (sex != "male" && sex != "female");

        cout << "Enter year of birth: ";
        do {
            cin >> birth;
            if (contains_letters(birth)){
                cout << "Year of death can not contain letters, try again: ";
            }
        } while (contains_letters(birth));

        cout << "Enter year of death, if the person has not died please type \"-\": ";
        do {
            cin >> death;
            if (contains_letters(death)){
                cout << "Year of death can not contain letters, try again: ";
            }
        } while (contains_letters(death));
        domain d;
        d.add(firstname, lastname, sex, birth, death);
        cout << "You successfully added a new person!" << endl << endl;
        system("pause");
        clearScreen();
        help();
    }
    else if (input == "-sort")
    {
        vector<Person> p;
        string input;
        cout << "What do you want to sort by?" << endl;
        cout << "-firstname" << endl << "-lastname" << endl << "-sex" << endl
             << "-birth" << endl << "-death" << endl;
        do {
            cin >> input;
            if (input != "-firstname" && input != "-lastname" && input != "-sex" &&
                input != "-birth" && input != "-death") {
                cout << input << " is not valid command! Try again: ";
            }
        } while (input != "-firstname" && input != "-lastname" && input != "-sex" &&
                 input != "-birth" && input != "-death");
        domain d;
        p = d.sort(input);

        cout << "===== Sorted list =====" << endl;
        print(p);
        system("pause");
        clearScreen();
        help();
    }
    else if (input == "-remove")
    {
        unsigned int lineNumber = 1;
        vector<Person> p;
        domain d;
        p = d.list();
        cout << "=========================== List ===========================" << endl;
        for(unsigned int i = 0; i < p.size(); i++){
            cout.width(10);
            cout << left;
            cout << i+1;
            cout.width(12);
            cout << left;
            cout << p[i].getFirstname();
            cout.width(12);
            cout << left;
            cout << p[i].getLastname();
            cout.width(10);
            cout << left;
            cout << p[i].getSex();
            cout.width(10);
            cout << left;
            cout << p[i].getBirth();
            cout.width(10);
            cout << left;
            cout << p[i].getDeath() << endl;

        }
        cout << "Which entry do you want to remove?" << endl;
        cout << "Type the line number: ";
        do {
            if (lineNumber <= 0 || lineNumber > p.size()) {
                cout << "Sorry this isn't a valid line, try again: ";
            }
            while (!(cin >> lineNumber)) {
               cin.clear();
               cin.ignore();
               cout << "Invalid input, try again: ";
            }

        } while (lineNumber <= 0 || lineNumber > p.size());
        p.erase (p.begin()+(lineNumber-1));
        d.remove(p);
        cout << "You successfully removed a line " << lineNumber << endl << endl;
        system("pause");
        clearScreen();
        help();
    }
    else if (input == "-help")
    {
        clearScreen();
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

// Villutjekk, athugar hvort thad se tolustafur i strengnum
bool toplayer::contains_number(const string &c)
{
    return (c.find_first_of("0123456789") != string::npos);
}

bool toplayer::contains_letters(const string &c)
{
    return (c.find_first_of("qwertyuioplkjhgfdsazxcvbnm") != string::npos);
}

void toplayer::clearScreen()
{
    system("cls");
}
