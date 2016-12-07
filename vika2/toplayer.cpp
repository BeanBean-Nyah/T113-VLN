#include "toplayer.h"
#include "domain.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <iomanip>


using namespace std;

toplayer::toplayer()
{

}
void toplayer::run()
{
    domain d;
    d.openDatabase();
    help();
    cout << "\n Enter -help to display the command list again " << endl;
    while(selection())
    {

    }
}
void toplayer::help()
{
    cout << "*********************************************************" << endl;
    cout << "**     Notable Computer Scientists In History          **" << endl;
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

//Prentar ut lista med ollum personum ur vector
void toplayer::print(vector<Person>& pers)
{
    cout << left << setw(25) << "Name" << setw(10)
         << "Sex" << setw(10) << "Birth" << setw(10) << "Death" << endl << endl;
    for(unsigned int i = 0; i < pers.size(); i++)
    {
        cout.width(25);
        cout<<left;
        cout << pers[i].getFirstname();
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
    cout << "==================================================" << endl << endl;
}

//Prentar ut eina linu ur vector
void toplayer::printLine(vector<Person>& pers, const int& i)
{
    int k = i - 1;
    cout << endl << "================ Line to edit =====================" << endl;
    cout << left << setw(25) << "Name" << setw(10)
         << "Sex" << setw(10) << "Birth" << setw(10) << "Death" << endl << endl;
    cout.width(12);
    cout<<left;
    cout << pers[k].getFirstname();
    cout.width(10);
    cout<<left;
    cout << pers[k].getSex();
    cout.width(10);
    cout<<left;
    cout << pers[k].getBirth();
    cout.width(10);
    cout<<left;
    cout << pers[k].getDeath()<<endl;
    cout << "===================================================" << endl << endl;
}

//Prentar ut lista med numerum fyrir framan hvern einstakling
void toplayer::printList(vector<Person>& p)
{
    cout << left << setw(5) << "Nr." << setw(25) << "Name" << setw(10)
         << "Sex" << setw(10) << "Birth" << setw(10) << "Death" << endl << endl;
    for(unsigned int i = 0; i < p.size(); i++)
    {
        cout.width(5);
        cout << left;
        cout << i+1;
        cout.width(25);
        cout << left;
        cout << p[i].getFirstname();
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
    cout << "=======================================================" << endl << endl;
}
//Prentar ut computer lista
void toplayer::printComputer(vector<Computer> comp)
{
    cout << left << setw(20) << "Name" << setw(10)
         << "Year" << setw(10) << "Type" << setw(10) << "Built" << endl << endl;
    for(unsigned int i = 0; i < comp.size(); i++)
    {
        cout.width(20);
        cout<<left;
        cout << comp[i].getName();
        cout.width(10);
        cout<<left;
        cout << comp[i].getYear();
        cout.width(10);
        cout<<left;
        cout << comp[i].getType();
        cout.width(10);
        cout<<left;
        cout << comp[i].getBuilt()<<endl;
    }
    cout << "==================================================" << endl << endl;
}

bool toplayer::selection()
{
    string input;
    cin >> input;
    if (input == "-list")
    {
        if (!(isListEmpty()))
        {
            cout << "================ List is empty =================" << endl << endl;
        }
        else
        {
            vector<Person> pers;
            vector<Computer> comp;
            domain d;
            char selection, human = 'p', com = 'c';
            selection = PersOrComp();
            switch (selection)
            {
                case 'p':
                        pers = d.list();
                        break;
                case 'c':
                        comp = d.computerList();
                        break;
                default:
                        cout << "error" << endl;
            }
            cout << "====================== List =======================" << endl;
            if (selection == human)
            {
                print(pers);
            }
            else if (selection == com)
            {
                printComputer(comp);
            }

       }
        system("pause");
        clearScreen();
        help();
    }
    else if (input == "-search")
    {
        switch(PersOrComp())
        {
            case 'p': searchPerson();
                    break;

            case 'c': searchComputer();
                    break;

            default : cout << "fatal error have you tried turning it off and on again" << endl;
        }

        system("pause");
        clearScreen();
        help();
    }
    else if (input == "-new")
    {
        switch(PersOrComp())
        {
            case 'p': newPerson();
                    break;

            case 'c': newComputer();
                    break;

            default : cout << "fatal error have you tried turning it off and on again" << endl;
        }
    }
    else if (input == "-sort")
    {
        if (!(isListEmpty()))
        {
            cout << "================ List is empty =================" << endl << endl;
        } else
        {
            switch(PersOrComp())
            {
                case 'p': sortPerson();
                          break;
                case 'c': sortComputer();
                          break;

                default : cout << "fatal error have you tried turning it off and on again" << endl;
            }
        }
        system("pause");
        clearScreen();
        help();
    }
    else if (input == "-edit")
    {
        if (!(isListEmpty()))
        {
            cout << "================ List is empty =================" << endl << endl;
        } else {
            switch(PersOrComp()) {
                case 'p': editPerson();
                        break;

                case 'c': editComputer();
                        break;

                default : cout << "fatal error have you tried turning it off and on again" << endl;
            }
        }
        system("pause");
        clearScreen();
        help();
    }
    else if (input == "-remove")
    {
        if (!(isListEmpty()))
        {
            cout << "================ List is empty =================" << endl << endl;
        } else {
            switch(PersOrComp()) {
                case 'p': removePerson();
                        break;

                case 'c': removeComputer();
                        break;

                default : cout << "fatal error have you tried turning it off and on again" << endl;
            }
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
void toplayer::newPerson()
{
    string firstname, sex, birth, death;

    firstname = getNewFirstname();
    sex = getNewSex();
    birth = getNewBirth();
    death = getNewDeath();

    domain d;
    d.add(firstname, sex, birth, death);
    cout << "You successfully added a new person!" << endl << endl;
    system("pause");
    clearScreen();
    help();
}
void toplayer::searchPerson()
{
    if (!(isListEmpty()))
    {
        cout << "================ List is empty =================" << endl << endl;
    }
    else
        {
        vector<Person> p;
        int gildi = 0;
        domain d;
        string whattype, input;
        cout << "What do you want to search for?" << endl;
        cout << "-name" << endl << "-sex"
             << endl << "-birth" << endl << "-death" << endl;
        cout << "Enter your choice: ";
        whattype = getInputType(gildi);
        cout << "What is the word you want to search for? ";
        cin.ignore();
        getline(cin,input);
        input = capFirstLetter(input);
        p = d.search(whattype, input);
        if (p.size() == 0)
        {
            cout << "Sorry, no results!" << endl;
        }
        else
        {
            cout << "================ Search results ==================" << endl;
            print(p);
        }
        }
}
void toplayer::sortPerson()
{
    vector<Person> p;
    int gildi = 0;
    cout << "What do you want to sort by?" << endl;
    cout << "   -name" << endl << "   -sex" << endl
         << "   -birth" << endl << "   -death" << endl;
    string input = getInputType(gildi);
    domain d;
    p = d.sorting(input);
    print(p);
}
void toplayer::editPerson()
{
    string input, newElement, newValue;
    bool yesno = true;
    vector<Person> p;
    domain d;
    p = d.list();
    printList(p);
    cout << "Which entry do you want to edit? " << endl;
    int lineNumber = lineEntry(p);
    clearScreen();
    while (yesno) {
        int gildi = 0;
        printLine(p, lineNumber);
        cout << "Which element do you want to edit? " << endl << "For name type: \t -name" <<
             endl << "For sex type: \t \t -sex" << endl <<
             "For birth year type: \t -birth" << endl << "For year of death type:  -death" << endl;
        input = getInputType(gildi);

        if (input == "-name") {
            newValue = getNewFirstname();
        } else if (input == "-sex") {
            newValue = getNewSex();
        } else if (input == "-birth") {
            newValue = getNewBirth();
        } else if (input == "-death") {
            newValue = getNewDeath();
        }
        lineNumber = lineNumber - 1;
        d.edit(p, lineNumber, input, newValue);
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
}
void toplayer::removePerson()
{
    vector<Person> p;
    domain d;
    p = d.list();
    cout << "========================= List ========================" << endl;
    printList(p);
    cout << "Which entry do you want to remove?" << endl;
    int lineNumber = lineEntry(p) - 1;
    d.remove(p, lineNumber);
    cout << "You successfully removed a line " << lineNumber + 1 << endl << endl;

}
void toplayer::newComputer()
{
    string cName, cType, cBuilt;
    int cYear = 0;
    cName = getNewFirstname();
    cYear = getNewDate();
    cType = getNewType();
    cBuilt = getNewBuilt();
    domain d;
    d.addComputer(cName,cYear,cType,cBuilt);
    cout << "You successfully added a new computer!" << endl << endl;
    system("pause");
    clearScreen();
    help();
}
void toplayer::searchComputer()
{
    if (!(isListEmpty()))
    {
        cout << "================ List is empty =================" << endl << endl;
    }
    else
        {
        vector<Computer> p;
        int gildi = 1;
        domain d;
        string whattype, input;
        cout << "What do you want to search for?" << endl;
        cout << "-name" << endl << "-year"
             << endl << "-type" << endl << "-built" << endl;
        cout << "Enter your choice: ";
        whattype = getInputType(gildi);
        cout << "What is the word you want to search for? ";
        cin.ignore();
        getline(cin,input);
        input = capFirstLetter(input);
        p = d.searchComputer(whattype, input);
        if (p.size() == 0)
        {
            cout << "Sorry, no results!" << endl;
        }
        else
        {
            cout << "================ Search results ==================" << endl;
            printComputer(p);
        }
        }
}
void toplayer::sortComputer()
{
    vector<Computer> c;
    int gildi = 1;
    cout << "What do you want to sort by?" << endl;
    cout << "   -name" << endl << "   -year" << endl
         << "   -type" << endl << "   -built" << endl;
    string input = getInputType(gildi);
    domain d;
    c = d.sortComputer(input);
    printComputer(c);
}
void toplayer::editComputer()
{
    cout << "TODO" << endl;
}
void toplayer::removeComputer()
{
    cout << "TODO" << endl;
}
//Athugar hvort listinn se tomur
bool toplayer::isListEmpty()
{
    vector<Person> p;
    domain d;
    vector<Computer> c;
    c = d.computerList();
    p = d.list();
    if (p.size() > 0)
    {
        return true;
    } else if(c.size() > 0){
        return true;
    }else {
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
    return (c.find_first_of("qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM") != string::npos);
}
// gerir alla stafi i streng lower case
string toplayer::Lower_Ans(string word)
{
    transform(word.begin(), word.end(), word.begin(), ::tolower); // scope resolution operator
    return word;
}

//fixar input thannig ad fyrsti stafur er alltaf stor og rest litlir
string toplayer::capFirstLetter(string& str)
{
    string output = Lower_Ans(str);
    output[0] = toupper(output[0]);
    return output;
}

// clear -ar console
void toplayer::clearScreen()
{
    system("cls");
}
//skila valinni linu ur lista
int toplayer::lineEntry(const vector<Person>& p)
{
    unsigned int lineNumber = 1;
    cout << "Type the line number: ";
    do
    {
        if (lineNumber <= 0 || lineNumber > p.size())
        {
            cout << "Sorry this isn't a valid line, try again: ";
        }
        while (!(cin >> lineNumber))
        {
           cin.clear();
           cin.ignore();
           cout << "Invalid input, try again: ";
        }
    }
    while (lineNumber <= 0 || lineNumber > p.size());
    cout << endl;
    return lineNumber;
}
// skilar input-i fra notanda
string toplayer::getInputType(int& type)
{
    string input;
    if (type == 0)
    {
        do
        {
            cout << "Enter your choice: ";
            cin >> input;
            input = Lower_Ans(input);
            if (input != "-name" && input != "-sex" &&
                input != "-birth" && input != "-death")
            {
                cout << input << " is not valid command! Try again: ";
            }
        }
        while (input != "-name" && input != "-sex" &&
                 input != "-birth" && input != "-death");
    }
        else if (type == 1)
    {
        do
        {
            cout << "Enter your choice: ";
            cin >> input;
            input = Lower_Ans(input);
            if (input != "-name" && input != "-year" &&
                input != "-type" && input != "-built")
            {
                cout << input << " is not valid command! Try again: ";
            }
        }
        while (input != "-name" && input != "-year" &&
                 input != "-type" && input != "-built");
    }
    return input;
}
//skilar nyju firstname
string toplayer::getNewFirstname()
{
    string firstname;
    cout << "Enter name: ";
    do
    {
        cin.ignore();
        getline (cin, firstname);
        firstname = capFirstLetter(firstname);
        if (contains_number(firstname))
        {
            cout << "First name can not contain numbers try again: ";
        }
    } while (contains_number(firstname));
    return firstname;
}

//skilar nyju sex
string toplayer::getNewSex()
{
    string sex;
    cout << "Enter sex: ";
    do
    {
        cin >> sex;
        sex = capFirstLetter(sex);
        if (sex != "Male" && sex != "Female")
        {
            cout << sex << " is not a gender, please choose male or female: ";
        }
    } while (sex != "Male" && sex != "Female");
    return sex;
}
// skilar nyju birth
string toplayer::getNewBirth()
{
    string birth;
    cout << "Enter year of birth: ";
    do
    {
        cin >> birth;
        if (contains_letters(birth))
        {
            cout << "Year of death can not contain letters, try again: ";
        }
    } while (contains_letters(birth));
    return birth;
}
// skilar nyju death
string toplayer::getNewDeath()
{
    string death;
    cout << "Enter year of death, if the person has not died please type \"-\": ";
    do
    {
        cin >> death;
        if (contains_letters(death))
        {
            cout << "Year of death can not contain letters, try again: ";
        }
    }
    while (contains_letters(death));
    return death;
}
// skilar nyju ari fyrir computer
int toplayer::getNewDate()
{
    int year;
    cout << "Enter year: ";
    while (!(cin >> year))
    {
       cin.clear();
       cin.ignore();
       cout << "Invalid input, try again: ";
    };
    return year;
}
// skilar nyju type i fyrir computer
string toplayer::getNewType()
{
    string type;
    cout << "Enter type: ";
    do
    {
        cin >> type;
        type = capFirstLetter(type);

        if (type != "Male" && type != "Female")
        {
            cout << type << " is not a gender, please choose male or female: ";
        }

        if (type != "Mekkanísk" && type != "Elektrónísk" && type != "Smáravél")
        {
            cout << type << " Type of machine is not \"Mekkanísk\", \"Elektrónísk\" or \"Smáravél\": ";

        }
    }
    while (type != "Mekkanísk" && type != "Elektrónísk" && type != "Smáravél");
    return type;
}


// skilar hvort computer var built eda ekki
string toplayer::getNewBuilt()
{
    string built;
    cout << "Was the computer built: ";
    do
    {
        cin >> built;
        built = capFirstLetter(built);
        if (built != "Yes" && built != "No")
        {
            cout << built << " isn't clear enough, please choose Yes or No: ";
        }
    } while (built != "Yes" && built != "NO");
    return built;
}

char toplayer::PersOrComp()
{
    char selector;
    do
    {
        cout << "Enter 'p' for a person. \n" <<
                "Or enter 'c' for a computer \n" <<
                "input: ";
        cin >> selector;
    } while (selector !='c' && selector !='p');
    return selector;
}
