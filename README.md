# AddressBook
AddressBook to help store birthdays, anniversaries, and originate cards.

Main.cpp
This file acts as a base program where we can launch the other files in the repository. This program allows users to add, delete, and modify different people in the Linked List. Each user is created as an object and stored in a Linked List. Each object contains a first name, last name, birthday, anniversary. Users can also create birthday or anniversary cards depending on the date. 

AddressBook.h
This header file works with AddressBook.cpp and declares prototypes for the functions that will help create each object in the Linked List. 

AddressBook.cpp
This is the main AddressBook object file, where the initiazation of each object can take place. It creates a constructor and functions to initialize the first name, last name, birthday, anniversary, and also creates functions to get those same variables. It also contains functions to create a birthday card and anniversary card. 

List.h
This header file creates a Linked List with different functions to add, delete, and modify the linked list. There are also aspects of the linked list that allows the user to utilize the get cards functions as well as a function to check if the list is empty. 

ListNode.h
This acts as a template function for the linked list nodes that the program utilizes to create the linked list of the AddressBook object. 
