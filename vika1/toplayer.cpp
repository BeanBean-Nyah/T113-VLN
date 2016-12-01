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
    cout << "**     Enter -edit to edit the list                    **" << endl;
    cout << "**     Enter -remove to remove element from the list   **" << endl;
    cout << "**     Enter -sort to sort the list                    **" << endl;
    cout << "**     Enter -exit to exit the program                 **" << endl;
    cout << "**                                                     **" << endl;
    cout << "*********************************************************" << endl;
}

//Prentar ut lista med ollum personunum ur vector
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

//Prentar ut eina linu ur vector
void toplayer::printLine(vector<Person>& pers, const int& i) {
    int k = i - 1;
    cout << endl << "================ Line to edit ==================" << endl;
    cout.width(12);
    cout<<left;
    cout << pers[k].getFirstname();
    cout.width(12);
    cout<<left;
    cout << pers[k].getLastname();
    cout.width(10);
    cout<<left;
    cout << pers[k].getSex();
    cout.width(10);
    cout<<left;
    cout << pers[k].getBirth();
    cout.width(10);
    cout<<left;
    cout << pers[k].getDeath()<<endl;
    cout << "================================================" << endl << endl;
}

//Prentar ut lista med numerum fyrir framan hvern einstakling
void toplayer::printList(vector<Person>& p) {
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
}

bool toplayer::selection()
{
    string input;
    cin >> input;
    if (input == "-list")
    {
        if (!(isListEmpty())) {
            cout << "================ List is empty =================" << endl << endl;
        } else {
            vector<Person> p;
            domain d;
            p = d.list();
            cout << "===================== List =====================" << endl;
            print(p);
        }
        system("pause");
        clearScreen();
        help();
    }
    else if (input == "-search")
    {
        if (!(isListEmpty())) {
            cout << "================ List is empty =================" << endl << endl;
        } else {
            vector<Person> p;
            domain d;
            string whattype, input;
            cout << "What do you want to search for?" << endl;
            cout << "-firstname" << endl << "-lastname" << endl << "-sex"
                 << endl << "-birth" << endl << "-death" << endl;
            cout << "Enter your choice: ";
            whattype = getInputType();
            cout << "What is the word you want to search for? ";
            cin >> input;
            p = d.search(whattype, input);
            if (p.size() == 0){
                cout << "Sorry, no results!" << endl;
            } else {
                cout << "===== Search results =====" << endl;
                print(p);
            }
        }
        system("pause");
        clearScreen();
        help();
    }
    else if (input == "-new")
    {
        string firstname, lastname, sex, birth, death;

        firstname = getNewFirstname();
        lastname = getNewLastname();
        sex = getNewSex();
        birth = getNewBirth();
        death = getNewDeath();

        domain d;
        d.add(firstname, lastname, sex, birth, death);
        cout << "You successfully added a new person!" << endl << endl;
        system("pause");
        clearScreen();
        help();
    }
    else if (input == "-sort")
    {
        if (!(isListEmpty())) {
            cout << "================ List is empty =================" << endl << endl;
        } else {
            vector<Person> p;
            cout << "What do you want to sort by?" << endl;
            cout << "   -firstname" << endl << "   -lastname" << endl << "   -sex" << endl
                 << "   -birth" << endl << "   -death" << endl;
            string input = getInputType();
            domain d;
            p = d.sort(input);

            cout << "================== Sorted list =================" << endl;
            print(p);
        }
        system("pause");
        clearScreen();
        help();
    }
    else if (input == "-edit")
    {
        if (!(isListEmpty())) {
            cout << "================ List is empty =================" << endl << endl;
        } else {
            string input, newElement;
            bool yesno = true;
            vector<Person> p;
            domain d;
            p = d.list();
            printList(p);
            cout << "Which entry do you want to edit? " << endl;
            int lineNumber = lineEntry(p);
            clearScreen();
            while (yesno) {
                printLine(p, lineNumber);
                cout << "Which element do you want to edit? " << endl << "For firstname type: \t -firstname" <<
                     endl << "For lastname type: \t -lastname" << endl << "For sex type: \t \t -sex" << endl <<
                     "For birth year type: \t -birth" << endl << "For year of death type:  -death" << endl;
                input = getInputType();

                if (input == "-firstname") {
                    string firstname = getNewFirstname();
                    p[lineNumber-1].setFirstname(firstname);
                } else if (input == "-lastname") {
                    string lastname = getNewLastname();
                    p[lineNumber-1].setLastname(lastname);
                } else if (input == "-sex") {
                    string sex = getNewSex();
                    p[lineNumber-1].setSex(sex);
                } else if (input == "-birth") {
                    string birth = getNewBirth();
                    p[lineNumber-1].setBirth(birth);
                } else if (input == "-death") {
                    string death = getNewDeath();
                    p[lineNumber-1].setDeath(death);
                }
                string yesorno;
                cout << "Do you want to edit another element in this entry? " << endl << endl;
                cout << "Type -yes if you want to else type anything else: ";
                cin >> yesorno;
                if (yesorno == "-yes") {
                    yesno = true;
                    clearScreen();
                } else {
                    yesno = false;
                }
            }
            d.edit(p);
        }
        system("pause");
        clearScreen();
        help();
    }
    else if (input == "-remove")
    {
        if (!(isListEmpty())) {
            cout << "================ List is empty =================" << endl << endl;
        } else {
            vector<Person> p;
            domain d;
            p = d.list();
            cout << "=========================== List ===========================" << endl;
            printList(p);
            cout << "Which entry do you want to remove?" << endl;
            int lineNumber = lineEntry(p);
            p.erase (p.begin()+(lineNumber-1));
            d.edit(p);
            cout << "You successfully removed a line " << lineNumber << endl << endl;
        }
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
        cout << input << " is not a valid command! Try again: ";
    }
    return true;
}

//Athugar hvort listinn se tomur
bool toplayer::isListEmpty() {
    vector<Person> p;
    domain d;
    p = d.list();
    if (p.size() > 0) {
        return true;
    } else {
        return false;
    }
}

// Villutjekk, athugar hvort thad se tolustafur i strengnum
bool toplayer::contains_number(const string &c)
{
    return (c.find_first_of("0123456789") != string::npos);
}
// Villutjekk, athugar hvort thad se bokstafur i strengnum
bool toplayer::contains_letters(const string &c)
{
    return (c.find_first_of("qwertyuioplkjhgfdsazxcvbnm") != string::npos);
}
// clear -ar console
void toplayer::clearScreen()
{
    system("cls");
}
//skila valinni linu ur lista
int toplayer::lineEntry(const vector<Person>& p) {
    unsigned int lineNumber = 1;
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
    cout << endl;
    return lineNumber;
}
// skilar input-i fra notanda
string toplayer::getInputType() {
    string input;
    do {
        cout << "Enter your choice: ";
        cin >> input;
        if (input != "-firstname" && input != "-lastname" && input != "-sex" &&
            input != "-birth" && input != "-death") {
            cout << input << " is not valid command! Try again: ";
        }
    } while (input != "-firstname" && input != "-lastname" && input != "-sex" &&
             input != "-birth" && input != "-death");
    return input;
}
//skilar nyju firstname
string toplayer::getNewFirstname() {
    string firstname;
    cout << "Enter first name: ";
    do {
        cin >> firstname;
        if (contains_number(firstname)) {
            cout << "First name can not contain numbers try again: ";
        }
    } while (contains_number(firstname));
    return firstname;
}
//skilar nyju lastname
string toplayer::getNewLastname() {
    string lastname;
    cout << "Enter last name: ";
    do {
        cin >> lastname;
        if (contains_number(lastname)) {
            cout << "Last name can not contain numbers try again: ";
        }
    } while (contains_number(lastname));
    return lastname;
}
//skilar nyju sex
string toplayer::getNewSex() {
    string sex;
    cout << "Enter sex: ";
    do {
        cin >> sex;
        if (sex != "male" && sex != "female"){
            cout << sex << " is not a gender, please choose male or female: ";
        }
    } while (sex != "male" && sex != "female");
    return sex;
}
// skilar nyju birth
string toplayer::getNewBirth() {
    string birth;
    cout << "Enter year of birth: ";
    do {
        cin >> birth;
        if (contains_letters(birth)){
            cout << "Year of death can not contain letters, try again: ";
        }
    } while (contains_letters(birth));
    return birth;
}
// skilar nyju death
string toplayer::getNewDeath() {
    string death;
    cout << "Enter year of death, if the person has not died please type \"-\": ";
    do {
        cin >> death;
        if (contains_letters(death)){
            cout << "Year of death can not contain letters, try again: ";
        }
    } while (contains_letters(death));
    return death;
}
