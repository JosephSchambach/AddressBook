#include <iostream>
#include <string>
#include "List.h"
#include "AddressBook.h"
using namespace std;

void selection();
void createInitialLinkedList(List<AddressBook>&);
void displayList(List<AddressBook>&);
void addToList(List<AddressBook>&);
void deleteFromList(List<AddressBook>&);
void changeNameOrDate(List<AddressBook>&);
void birthdayCard(List<AddressBook>&);
void anniversaryCard(List<AddressBook>&);

int main() {
   List<AddressBook> list;
   createInitialLinkedList(list);
   int answer;

   selection();
   cin >> answer;
   while(answer != 7) {
       switch (answer){
           case(1):
               cout << "Entering a new name to the address book: \n\n";
               addToList(list);
               break;
           case(2):
               cout << "Deleting a name from the address book: \n\n";
               deleteFromList(list);
               break;
           case(3):
               cout << "Changing a name in the address book: \n\n";
               changeNameOrDate(list);
               break;
           case(4):
               cout << "Displaying the whole address book: \n\n";
               displayList(list);
               break;
           case(5):
               cout << "Generating birthday cards: \n\n";
               birthdayCard(list);
               break;
           case(6):
               cout << "Generating anniversary cards: \n\n";
               anniversaryCard(list);
               break;
           case(7):
               cout << "Closing program\n\n";
               break;
       }

       selection();
       cin >> answer;
   }

   return 0;
}

// Give the user the list of options
void selection(){
   cout << "What do you want to do?\n\n"
       <<"Choose from the following list: \n"
       << "1 for entering a name to the address book\n"
       << "2 for deleting a name from the address book\n"
       << "3 for changing a name or address in the address book\n"
       << "4 for displaying the whole address book\n"
       << "5 for generating a birthday card\n"
       << "6 for generating an anniversary card\n"
       << "7 for exiting card program\n"
       << "?";
}

void displayList(List<AddressBook>& list){
   list.print();
}

void addToList(List<AddressBook>& list){
   string last, first, streetNum, streetName, streetType, city, state, zip;
   cout << "Enter last name: ";
   cin >> last;
   cout << "Enter first name: ";
   cin >> first;

   cout << "Enter street address: ";
   cin >> streetNum >> streetName >> streetType;
   string address = streetNum + ' ' + streetName + ' ' + streetType;
   cout << "Enter city: ";
   cin >> city;
   cout << "Enter state: ";
   cin >> state;
   cout << "Enter zip: ";
   cin >> zip;

   string birth, birthday, birthmonth;
   cout << "Enter a birthday in the following format (month day): ";
   cin >> birthmonth >> birthday;
   birth = birthmonth + ' ' + birthday;
   cout << "Creating class and adding to list\n";
   AddressBook object(last, first, address, city, state, zip, birth);
   list.insertAtFront(object);
}

void deleteFromList(List<AddressBook>& list){
   string last, first;
   cout << "Who do you want to delete? (last first): ";
   cin >> last >> first;

   bool result;
   result = list.deleteFromList(last, first);

   if (result){
       cout << last << ", " << first << " was deleted\n\n";
   }
   else
       cout << "Could not find " << last << ", " << first << " in list\n\n";
}

void changeNameOrDate(List<AddressBook>& list){
   string last, first;
   cout << "Who do you want to update? (last first): ";
   cin >> last >> first;
   list.changeData(last, first);
}

void createInitialLinkedList(List<AddressBook>& list){
   string l, f, a, c, s, z, b;
   l = "Schambach";
   f = "Joseph";
   a = "123 Somewhere Dr.";
   c = "Anytown";
   s = "IL";
   z = "12345";
   b = "Sep 2";
   AddressBook object(l, f, a, c, s, z, b);

   string l2, f2, a2, c2, s2, z2, b2;
   l2 = "Schambach";
   f2 = "Lindsey";
   a2 = "456 Place St.";
   c2 = "SmallTown";
   s2 = "IL";
   z2 = "45678";
   b2 = "Feb 28";
   AddressBook object2(l2, f2, a2, c2, s2, z2, b2, "Aug 7");

   string l3, f3, a3, c3, s3, z3, b3;
   l3 = "Glosson";
   f3 = "Blake";
   a3 = "859 Road Blvd";
   c3 = "SmallTown";
   s3 = "IL";
   z3 = " 44444";
   b3 = "Sep 2";
   AddressBook object3(l3, f3, a3, c3, s3, z3, b3);

   string l4, f4, a4, c4, s4, z4, b4;
   l4 = "Acosta";
   f4 = "Nick";
   a4 = "888 Drive St";
   c4 = "Anytown";
   s4 = "IL";
   z4 = "12345";
   b4 = "Apr 14";
   AddressBook object4(l4, f4, a4, c4, s4, z4, b4, "");

   string l5, f5, a5, c5, s5, z5, b5;
   l5 = "Schambach";
   f5 = "Jack";
   a5 = "999 Beard Ln";
   c5 = "BigTown";
   s5 = "CO";
   z5 = "65487";
   b5 = "June 27";
   AddressBook object5(l5, f5, a5, c5, s5, z5, b5, "Oct 10");

   list.insertAtFront(object);
   list.insertAtFront(object2);
   list.insertAtFront(object3);
   list.insertAtFront(object4);
   list.insertAtFront(object5);
}

void birthdayCard(List<AddressBook>& list){
   string month, day, today;
   cout << "Enter today's date in following format (month day): ";
   cin >> month >> day;
   today = month + ' ' + day;

   list.showBirthdayCards(today);
}

void anniversaryCard(List<AddressBook>& list){
   string month, day, today;
   cout << "Enter today's date in the following format (month day): ";
   cin >> month >> day;
   today = month + ' ' + day;

   list.showAnniversaryCards(today);
}
