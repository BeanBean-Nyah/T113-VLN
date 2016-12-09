# T113-VLN

Readme 
This program “Notable Computers and Computer Scientists in History” is a simple program that is 
connected to a SQLite database that contains information about notable computers and scientists in history.  
The user can retrieve information though the program and add new entries. 

The first display offers 8 options to the user:

-new: allows the user to add a new person or a computer to the database.

-list: Offers the following list options to the user: 
•	Persons
•	Computers
•	Both

Under each choice you can select how you want to sort the list, for persons the options are: 
name, sex, birth and death, for computers the options are: name, year, type and whether it was built 
or not. All options on these two lists are available in both ascending (asc) and descending (desc) order.

The “b” option stands for “both” and generates a list that displays computers and persons and shows if they are linked together.

-search: The user can search for either person or computer. If "p" is chosen you can search by name, gender, year born and year of death. 
The computer list can be searched by name, year, type and if the machine was built or not. 

-edit:  Lets the user edit previous entries on the list. If this option is used the program displays the list with numbers in front 
of each line and askes the user which line he would like to edit. When the line is chosen the user can decide which individual field he 
would like to edit. Under -edit you can also change existing relations between persons and computers.

-funfact: is an additional feature to the program that displays a random fact related to computers and computer science. 

-remove: Lets the user remove either a person or a computer from the list. Like in edit the program displays a list and the user 
enters the number of the line he wants to remove. 

-clear: Lets the user clear a whole table from the database or clear the entire database. When this option is used the program 
offers your options to clear the computers, persons, connections or the whole database. 

-exit:  Closes the program 

-help:  Displays the command list again


