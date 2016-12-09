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
    if (d.openDatabase())
    {
        cout << "Database: connection ok" << endl;
    } else {
        cout << "Error: connection with database failed" << endl;
    }
    help();
    cout << "\n Enter -help to display the command list again " << endl;
    while(selection())
    {

    }
}
void toplayer::help()
{
    cout << "*********************************************************" << endl;
    cout << "**                                                     **" << endl;
    cout << "**                Notable Computers And                **" << endl;
    cout << "**           Computer Scientists In History            **" << endl;
    cout << "**                                                     **" << endl;
    cout << "**     Enter -new to add a new person or computer      **" << endl;
    cout << "**     Enter -list for a see the lists                 **" << endl;
    cout << "**     Enter -search to search list                    **" << endl;
    cout << "**     Enter -edit to edit list                        **" << endl;
    cout << "**     Enter -funfact to get fun fact                  **" << endl;
    cout << "**     Enter -remove to remove element from list       **" << endl;
    cout << "**     Enter -clear to clear from database             **" << endl;
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
    cout << "======================================================" << endl << endl;
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
void toplayer::printLineComputer(vector<Computer>& comp, const int& i)
{
    int k = i - 1;
    cout << endl << "================ Line to edit =====================" << endl;
    cout << left << setw(25) << "Name" << setw(10)
         << "Year" << setw(10) << "Type" << setw(10) << "Built" << endl << endl;
    cout.width(12);
    cout<<left;
    cout << comp[k].getName();
    cout.width(10);
    cout<<left;
    cout << comp[k].getYear();
    cout.width(10);
    cout<<left;
    cout << comp[k].getType();
    cout.width(10);
    cout<<left;
    cout << comp[k].getBuilt()<<endl;
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
//Prentar ut lista yfir tolvur
void toplayer::printComputer(vector<Computer> comp)
{
    cout << left << setw(20) << "Name" << setw(10)
         << "Year" << setw(15) << "Type" << setw(10) << "Built" << endl << endl;
    for(unsigned int i = 0; i < comp.size(); i++)
    {
        cout.width(20);
        cout<<left;
        cout << comp[i].getName();
        cout.width(10);
        cout<<left;
        cout << comp[i].getYear();
        cout.width(15);
        cout<<left;
        cout << comp[i].getType();
        cout.width(10);
        cout<<left;
        cout << comp[i].getBuilt()<<endl;
    }
    cout << "=========================================================" << endl << endl;
}
void toplayer::printListComputer(vector<Computer>& p)
{
    cout << left << setw(5) << "Nr." << setw(25) << "Name" << setw(10)
         << "Year" << setw(15) << "Type" << setw(10) << "Built" << endl << endl;
    for(unsigned int i = 0; i < p.size(); i++)
    {
        cout.width(5);
        cout << left;
        cout << i+1;
        cout.width(25);
        cout << left;
        cout << p[i].getName();
        cout.width(10);
        cout << left;
        cout << p[i].getYear();
        cout.width(15);
        cout << left;
        cout << p[i].getType();
        cout.width(10);
        cout << left;
        cout << p[i].getBuilt() << endl;
    }
    cout << "=======================================================" << endl << endl;
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
            vector<PersonsAndComputers> pAc;
            domain d;
            char selector;
            do
            {
                cout << "Enter 'p' for person. \n" <<
                        "Enter 'c' for computer \n" <<
                        "Enter 'b' for computer and associated person  \n" <<
                        "input: ";
                cin >> selector;
                if (selector != 'p' && selector != 'c' && selector != 'b')
                {
                    cout << "\"" << selector << "\"" << " Is not a valid command! Try again: ";
                }
            } while (selector !='c' && selector !='p' && selector != 'b');
            switch (selector)
            {
                case 'p':
                        pers = d.list();
                        sortPerson();
                        break;
                case 'c':
                        comp = d.computerList();
                        sortComputer();
                        break;
                case 'b':
                        pAc = d.persAndCompList();
                        cout << "========================= List ==========================" << endl;
                        printPersAndComp(pAc);
                default:
                        cout <<"";
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

            default : cout << "Fatal error have you tried turning it off and on again" << endl;
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

            default : cout << "Fatal error have you tried turning it off and on again" << endl;
        }
    }
    else if (input == "-sort")
    {
        if (!(isListEmpty()))
        {
            cout << "================ List is empty =================" << endl << endl;
        }
        else
        {
            switch(PersOrComp())
            {
                case 'p': sortPerson();
                          break;
                case 'c': sortComputer();
                          break;

                default : cout << "Fatal error have you tried turning it off and on again" << endl;
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
        }
        else
        {
            switch(PersOrComp()) {
                case 'p': editPerson();
                        break;

                case 'c': editComputer();
                        break;

                default : cout << "Fatal error have you tried turning it off and on again" << endl;
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
        }
        else
        {
            switch(PersOrComp())
            {
                case 'p': removePerson();
                        break;

                case 'c': removeComputer();
                        break;

                default : cout << "Fatal error have you tried turning it off and on again" << endl;
            }
        }
        system("pause");
        clearScreen();
        help();
    }
    else if (input == "-funfact")
    {
        domain d;
        string fact = d.funFact();
        cout << endl << fact << endl << endl;
        system("pause");
        clearScreen();
        help();
    }
    else if (input == "-clear")
    {
        domain d;
        string input;
        cout << "Type 'persons' if you want to clear all persons from the database" << endl;
        cout << "Type 'computers' if you want to clear all computers from the database" << endl;
        cout << "Type 'connections' if you want to clear all connections between persons and computers" << endl;
        cout << "Type 'everything' if you want to clear everything from the database" << endl;
        cout << "Type 'back' if you want to go back" << endl;
        do {
            cin >> input;
            Lower_Ans(input);
            if (input != "persons" && input != "computers" && input != "connections" &&
                    input != "everything" && input != "back")
            {
                cout << "Invalid input, try again: ";
            }
        } while (input != "persons" && input != "computers" && input != "connections" &&
                 input != "everything" && input != "back");
        if (d.clear(input))
            cout << "You successfully cleared everything from " << input << endl;
        else
            cout << "Something went wrong" << endl;
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
        cout << input << " Is not a valid command! Try again: ";
    }
    return true;
}
void toplayer::newPerson()
{
    string firstname, sex, birth, death, tempPersName, persID;
    vector<Person> pers;
    firstname = getNewFirstname();
    sex = getNewSex();
    int birthint;
    int deathint;

    do
    {
        birth = getNewBirth();
        death = getNewDeath();
        birthint = atoi(birth.c_str());
        deathint = atoi(death.c_str());
        if (birthint > deathint)
        {
            cout << "You can not be born after you die, please try again!" << endl;
        }

    } while (birthint > deathint);

    if (death == "99999999")
    {
        death.clear();
    }

    domain d;
    if (d.add(firstname, sex, birth, death))
    {
        cout << "You successfully added a new person!" << endl << endl;
        pers = d.list();
        for (unsigned int i = 0; i < pers.size(); i++) {
            tempPersName = pers[i].getFirstname();
            if (tempPersName == firstname)
            {
                persID = pers[i].getID();
            }
        }
        int type = 0;
        connectToPerson(persID, type);
    }
    else
    {
        cout << "This exact person already exists in the database, so it wasn't added!" << endl << endl;
    }

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
    cout << "   -nameasc" << endl << "   -namedesc" << endl
         << "   -sexasc" << endl << "   -sexdesc" << endl
         << "   -birthasc" << endl << "   -birthdesc" << endl
         << "   -deathasc" << endl << "   -deathdesc" << endl;
    string input = getInputSortType(gildi);
    domain d;
    p = d.sorting(input);
    cout << "========================= List =======================" << endl;
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

        if (input == "-name")
        {
            newValue = getNewFirstname();
        }
        else if (input == "-sex")
        {
            newValue = getNewSex();
        } else if (input == "-birth") {
            do {
                newValue = getNewBirth();
                cout << (atoi(newValue.c_str())) << endl;
                cout << (atoi(p[lineNumber-1].getDeath().c_str())) << endl;
                if ((atoi(newValue.c_str())) > (atoi(p[lineNumber-1].getDeath().c_str())))
                {
                    cout << "You can not be born after you die, please try again!" << endl;
                }
            } while ((atoi(newValue.c_str())) > (atoi(p[lineNumber-1].getDeath().c_str())));
        } else if (input == "-death") {
            do {
                newValue = getNewDeath();
                if ((atoi(p[lineNumber-1].getBirth().c_str())) > (atoi(newValue.c_str())))
                {
                    cout << "You can not die before you are born, please try again!" << endl;
                }
            } while ((atoi(p[lineNumber-1].getBirth().c_str())) > (atoi(newValue.c_str())));
            if (newValue == "99999999")
            {
                newValue.clear();
            }
        }
        lineNumber = lineNumber - 1;
        d.edit(p, lineNumber, input, newValue);
        string yesorno;
        cout << "Do you want to edit another element in this entry? " << endl << endl;
        cout << "Type -yes if you want to else type anything else: ";
        cin >> yesorno;
        if (yesorno == "-yes")
        {
            yesno = true;
            clearScreen();
        }
        else
        {
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
    vector<Computer> comp;
    domain d;
    string cName, cYear, cType, cBuilt, compID, tempCompName;
    cName = getNewCompname();
    cYear = getNewDate();
    cType = getNewType();
    cBuilt = getNewBuilt();

    if (d.addComputer(cName,cYear,cType,cBuilt))
    {
        cout << "You successfully added a new computer!" << endl << endl;
        comp = d.computerList();
        for (unsigned int i = 0; i < comp.size(); i++) {
            tempCompName = comp[i].getName();
            if (tempCompName == cName)
            {
                compID = comp[i].getID();
            }
        }
        int type = 1;
        connectToPerson(compID, type);
    }
    else
    {
        cout << "This exact computer already exists in the database, so it wasn't added!" << endl << endl;
    }
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
    cout << "   -nameasc"  << endl << "   -namedesc"  << endl
         << "   -yearasc"  << endl << "   -yeardesc"  << endl
         << "   -typeasc"  << endl << "   -typedesc"  << endl
         << "   -builtasc" << endl << "   -builtdesc" << endl;
    string input = getInputSortType(gildi);
    domain d;
    c = d.sortComputer(input);
    cout << "========================= List =======================" << endl;
    printComputer(c);
}
void toplayer::editComputer()
{
    string input, newElement, newValue;
    bool yesno = true;
    vector<Computer> c;
    domain d;
    c = d.computerList();
    printListComputer(c);
    cout << "Which entry do you want to edit? " << endl;
    int lineNumber = lineEntryComputer(c);
    clearScreen();
    while (yesno)
    {
        int gildi = 1;
        printLineComputer(c, lineNumber);
        cout << "Which element do you want to edit? " << endl << "For name type: \t -name" <<
             endl << "For year type: \t \t -year" << endl <<
             "For type type: \t -type" << endl << "For built type:  -built" << endl;
        input = getInputType(gildi);

        if (input == "-name")
        {
            newValue = getNewFirstname();
        }
        else if (input == "-year")
        {
            newValue = getNewDate();
        }
        else if (input == "-type")
        {
            newValue = getNewType();
        }
        else if (input == "-built")
        {
            newValue = getNewBuilt();
        }
        lineNumber = lineNumber - 1;
        d.editComputer(c, lineNumber, input, newValue);
        string yesorno;
        cout << "Do you want to edit another element in this entry? " << endl << endl;
        cout << "Type -yes if you want to else type anything else: ";
        cin >> yesorno;
        if (yesorno == "-yes")
        {
            yesno = true;
            clearScreen();
        }
        else
        {
            yesno = false;
        }
    }
}
void toplayer::removeComputer()
{
    vector<Computer> comp;
    domain d;
    comp = d.computerList();
    cout << "========================= List ========================" << endl;
    printListComputer(comp);
    cout << "Which entry do you want to remove?" << endl;
    int lineNumber = lineEntryComputer(comp) - 1;
    d.removeComputer(comp, lineNumber);
    cout << "You successfully removed a line " << lineNumber + 1 << endl << endl;
}

void toplayer::connectToPerson(string& ID, int& type)
{
    string yesorno, choice, inneryesorno;
    bool YN = true;
    cout << "Do you want to connect a person and computer together? " << endl;
    cout << "Type yes if you want to, else anything else: ";
    cin >> yesorno;

    if (yesorno == "yes")
    {
        do
        {
            cout << "Do you want to connect an existing person or create a new one?" << endl;
            cout << "Type 'old' for existing one or 'new' for new one ";
            do
            {
                cin >> choice;
                choice = Lower_Ans(choice);
                if (choice != "new" && choice != "old")
                {
                    cout << choice << " Is not a valid command! Try again: ";
                }
            }
            while (choice != "new" && choice != "old");
            vector<Person> pers;
            vector<Computer> comp;
            domain d;
            string persID, compID;
            if (type == 1)
            {
                if (choice == "old")
                {
                    pers = d.list();
                    printList(pers);
                    cout << "Which person do you want to connect to this computer?" << endl;
                    int lineNumber = lineEntry(pers) - 1;
                    persID = pers[lineNumber].getID();
                    if (d.connectPtoC(persID, ID))
                    {
                        cout << "You successfully connected a person to this computer!" << endl;
                    }
                    else
                    {
                        cout << "This exact person is already connected to this computer!" << endl;
                    }
                }
                else if (choice == "new")
                {
                    newPerson();
                    pers = d.list();
                    int latest = pers.size() - 1;
                    persID = pers[latest].getID();
                    if (d.connectPtoC(persID, ID))
                    {
                        cout << "You successfully connected a person to this computer!" << endl;
                    }
                    else
                    {
                        cout << "This exact person is already connected to this computer!" << endl;
                    }
                }
            }
            else if (type == 0)
            {
                if (choice == "old")
                {
                    comp = d.computerList();
                    printListComputer(comp);
                    cout << "Which computer do you want to connect to this person?" << endl;
                    int lineNumber = lineEntryComputer(comp) - 1;
                    compID = comp[lineNumber].getID();
                    if (d.connectPtoC(ID, compID))
                    {
                        cout << "You successfully connected a person to this computer!" << endl;
                    }
                    else
                    {
                        cout << "This exact computer is already connected to this person!" << endl;
                    }
                }
                else if (choice == "new")
                {
                    newComputer();
                    comp = d.computerList();
                    int latest = comp.size() - 1;
                    compID = comp[latest].getID();
                    if (d.connectPtoC(ID, compID))
                    {
                        cout << "You successfully connected a computer to this person!" << endl;
                    }
                    else
                    {
                        cout << "This exact computer is already connected to this person!" << endl;
                    }
                }
            }

            cout << "Do you want to connect another person and computer together? " << endl;
            cout << "Type yes if you want to, else anything else: ";
            cin >> inneryesorno;
            inneryesorno = Lower_Ans(inneryesorno);
            if (inneryesorno == "yes")
            {
                YN = true;
            }
            else
            {
                YN = false;
            }
        } while(YN);
    }
}
/*void toplayer::connectToComputer(string& ID, int& type)
{
    string yesorno, choice, inneryesorno;
    bool YN = true;
    cout << "Do you want to connect a person and computer together? " << endl;
    cout << "Type yes if you want to, else anything else: ";
    cin >> yesorno;

    if (yesorno == "yes")
    {
        do
        {
            cout << "Do you want to connect an existing computer or create a new one?" << endl;
            cout << "Type 'old' for existing one or 'new' for new one ";
            do
            {
                cin >> choice;
                choice = Lower_Ans(choice);
                if (choice != "new" && choice != "old")
                {
                    cout << choice << " Is not a valid command! Try again: ";
                }
            }
            while (choice != "new" && choice != "old");
            vector<Person> pers;
            vector<Computer> comp;
            domain d;
            string persID, compID;
            if (type == 1)
            {
                if (choice == "old")
                {
                    pers = d.list();
                    printList(pers);
                    cout << "Which person do you want to connect to this computer?" << endl;
                    int lineNumber = lineEntry(pers) - 1;
                    persID = pers[lineNumber].getID();
                    if (d.connectPtoC(persID, ID))
                    {
                        cout << "You successfully connected a person to this computer!" << endl;
                    }
                    else
                    {
                        cout << "This exact person is already connected to this computer!" << endl;
                    }
                }
                else if (choice == "new")
                {
                    newPerson();
                    pers = d.list();
                    int latest = pers.size() - 1;
                    persID = pers[latest].getID();
                    if (d.connectPtoC(persID, ID))
                    {
                        cout << "You successfully connected a person to this computer!" << endl;
                    }
                    else
                    {
                        cout << "This exact person is already connected to this computer!" << endl;
                    }
                }
            }
            else if (type == 0)
            {
                if (choice == "old")
                {
                    comp = d.computerList();
                    printListComputer(comp);
                    cout << "Which computer do you want to connect to this person?" << endl;
                    int lineNumber = lineEntryComputer(comp) - 1;
                    compID = comp[lineNumber].getID();
                    if (d.connectPtoC(ID, compID))
                    {
                        cout << "You successfully connected a person to this computer!" << endl;
                    }
                    else
                    {
                        cout << "This exact computer is already connected to this person!" << endl;
                    }
                }
                else if (choice == "new")
                {
                    newComputer();
                    comp = d.computerList();
                    int latest = comp.size() - 1;
                    compID = comp[latest].getID();
                    if (d.connectPtoC(ID, compID))
                    {
                        cout << "You successfully connected a computer to this person!" << endl;
                    }
                    else
                    {
                        cout << "This exact computer is already connected to this person!" << endl;
                    }
                }
            }

            cout << "Do you want to connect another person and computer together? " << endl;
            cout << "Type yes if you want to, else anything else: ";
            cin >> inneryesorno;
            inneryesorno = Lower_Ans(inneryesorno);
            if (inneryesorno == "yes")
            {
                YN = true;
            }
            else
            {
                YN = false;
            }
        } while(YN);
    }
}*/

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
    }
    else if(c.size() > 0)
    {
        return true;
    }
    else
    {
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
// Gerir alla stafi i streng lower case
string toplayer::Lower_Ans(string word)
{
    transform(word.begin(), word.end(), word.begin(), ::tolower); // scope resolution operator
    return word;
}

// Fixar input thannig ad fyrsti stafur er alltaf stor og rest litlir
string toplayer::capFirstLetter(string& str)
{
    string output = Lower_Ans(str);
    size_t f = output.find(" ");
    output[0] = toupper(output[0]);
    output[f+1] = toupper(output[f+1]);
    f = output.find(" ",f+1);
    output[f+1] = toupper(output[f+1]);
    return output;
}

// Clear -ar console
void toplayer::clearScreen()
{
    system("cls");
}
//Skilar valinni linu ur lista
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
int toplayer::lineEntryComputer(const vector<Computer>& p)
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
// Skilar input-i fra notanda
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
                cout << input << " Is not valid command! Try again: ";
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
                cout << input << " Is not valid command! Try again: ";
            }
        }
        while (input != "-name" && input != "-year" &&
                 input != "-type" && input != "-built");
    }
    return input;
}

string toplayer::getInputSortType(int& type)
{
    string input;
    if (type == 0)
    {
        do
        {
            cout << "Enter your choice: ";
            cin >> input;
            input = Lower_Ans(input);
            if (input != "-nameasc" && input != "-sexasc" &&
                input != "-birthasc" && input != "-deathasc" &&
                input != "-namedesc" && input != "-sexdesc" &&
                input != "-birthdesc" && input != "-deathdesc")
            {
                cout << input << " Is not valid command! Try again: ";
            }
        }
        while (input != "-nameasc" && input != "-sexasc" &&
               input != "-birthasc" && input != "-deathasc" &&
               input != "-namedesc" && input != "-sexdesc" &&
               input != "-birthdesc" && input != "-deathdesc");
    }
    else if (type == 1)
    {
        cout << "Enter your choice: ";
        do
        {
            cin >> input;
            input = Lower_Ans(input);
            if (input != "-nameasc" && input != "-yearasc" &&
                input != "-typeasc" && input != "-builtasc" &&
                input != "-namedesc" && input != "-yeardesc" &&
                input != "-typedesc" && input != "-builtdesc")
            {
                cout << input << " Is not valid command! Try again: ";
            }
        }
        while (input != "-nameasc" && input != "-yearasc" &&
               input != "-typeasc" && input != "-builtasc" &&
               input != "-namedesc" && input != "-yeardesc" &&
               input != "-typedesc" && input != "-builtdesc");
    }
    return input;
}
// Skilar nyju firstname
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
            cout << "First name can not contain numbers, try again: ";
        }
    }
    while (contains_number(firstname));
    return firstname;
}
string toplayer::getNewCompname()
{
    string firstname;
    cout << "Enter computer name: ";
        cin.ignore();
        getline (cin, firstname);
        firstname = capFirstLetter(firstname);
return firstname;
}
// Skilar nyju sex
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
            cout << sex << " Is not a gender, please choose male or female: ";
        }
    } while (sex != "Male" && sex != "Female");
    return sex;
}
// Skilar nyju birth
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
    }
    while (contains_letters(birth));
    return birth;
}
// Skilar nyju death
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
    if (death == "-") {
        death = "99999999";
    }
    return death;
}
// Skilar nyju ari fyrir computer
string toplayer::getNewDate()
{
    string year;
    cout << "Enter year: ";
    do
    {
        cin >> year;
        if (contains_letters(year))
        {
            cout << "Year can not contain letters, try again: ";
        }
    }
    while (contains_letters(year));

    return year;
}
// Skilar nyju type-i fyrir computer
string toplayer::getNewType()
{
    string type;
    cout << "Enter type, you can choose 'Mechanical', 'Electronic' or 'Transistor': ";
    do
    {
        cin >> type;
        type = capFirstLetter(type);

        if (type != "Mechanical" && type != "Electronic" && type != "Transistor")
        {
            cout << type << " Type of machine is not \"Mechanical\", \"Electronic\" or \"Transistor\": ";
        }
    }
    while (type != "Mechanical" && type != "Electronic" && type != "Transistor");
    return type;
}


// Skilar hvort computer var built eda ekki
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
            cout << built << " Isn't clear enough, please choose Yes or No: ";
        }
    }
    while (built != "Yes" && built != "No");
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

void toplayer::printPersAndComp(vector<PersonsAndComputers> pAc)
{
    vector<Person> pers;
    vector<Computer> comp;
    domain d;
    pers = d.list();
    comp = d.computerList();
    string id;
    cout << left << setw(25) << "Computer" << setw(20)
         << "Creators" << setw(10) << "Year" << setw(10) << "Built" << endl << endl;
    for (unsigned int i = 0; i < comp.size(); i++)
    {
        cout.width(25);
        cout<<left;
        cout << comp[i].getName();
        int t = 0;
        for (unsigned int k = 0; k < pAc.size(); k++)
        {
            if (comp[i].getID() == pAc[k].getComp_ID())
            {
                id = pAc[k].getPers_ID();
                for (unsigned int j = 0; j < pers.size(); j++)
                {
                    if (pers[j].getID() == id) {
                        if (t > 0) {
                            cout.width(25);
                            cout<<left;
                            cout << "";
                        }
                        cout.width(20);
                        cout<<left;
                        cout << pers[j].getFirstname();
                        if (t > 0) {
                            cout << endl;
                        }
                        if (t == 0) {
                        cout.width(10);
                        cout<<left;
                        cout << comp[i].getYear();
                        cout.width(10);
                        cout<<left;
                        cout << comp[i].getBuilt()<<endl;
                        }
                    }
                }
                t++;
            }
        }
    } cout << "=========================================================" << endl << endl;
}
