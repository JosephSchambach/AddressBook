#include "AddressBook.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

AddressBook::AddressBook(string& last, string& first, string& addr,
                        string& cty, string& ste, string& zip,
                        string& bday, string anniv){
   setLastName(last);
   setFirstName(first);
   setAddress(addr, cty, ste, zip);
   setBirthday(bday);
   if (anniv.empty()){
       anniversary = "";
   }
   else
       setAnniversary(anniv);
}

void AddressBook::setFirstName(string& first){
   firstName = first;
}

string AddressBook::getFirstName(){
   return firstName;
}

void AddressBook::setLastName(string& last){
   lastName = last;
}

string AddressBook::getLastName(){
   return lastName;
}

void AddressBook::setAddress(string& addr, string& cty, string& ste, string& zp){
   address = addr;
   city = cty;
   state = ste;
   zip = zp;
}

string AddressBook::getAddress() const{
   ostringstream output;
   output << address << "\n"
       << city << ", " << state << " " << zip << "\n";
   return output.str();
}
void AddressBook::setBirthday(string& bday){
   birthday = bday;
}

string AddressBook::getBirthday(){
   return birthday;
}

void AddressBook::setAnniversary(string anniv){
   anniversary = anniv;
}

string AddressBook::getAnniversary() {
   return anniversary;
}

void AddressBook::generateBirthdayCard(){
   cout << "Dear " << firstName << ", \n\n"
        << "Today is " << birthday << ". Hope you have the best birthday ever today!\n\n"
        << "Sincerely, me\n\n";
}

void AddressBook::generateAnniversaryCard(){
   cout << "Dear " << firstName << ", \n\n";
   cout << "Today is " << anniversary << ". I wish you and your spouse the best upcoming year. \n"
       << "Happy anniversary!\n\n"
       << "Sincerely, me\n\n";
}

void AddressBook::changeNameOrDate(){
   char answer;
   cout << "Which do you want to change? (n or d): ";
   cin >> answer;
   if (answer == 'n'){
       string first, last;
       cout << "Please enter a first name: ";
       cin >> first;
       cout << "Please enter a last name: ";
       cin >> last;
       firstName = first;
       lastName = last;
   }
   if (answer == 'd'){
       char choice;
       cout << firstName << ". Which do you want to change? (b = birthday and a = anniversary): ";
       cin >> choice;
       if (choice == 'b'){
           string day, month;
           cout << "Enter in this format (month day): ";
           cin >> month;
           cin >> day;
           birthday = month + ' ' + ' ' + day;
       }
       if (choice == 'a'){
           string day, month;
           cout << "Enter in this format (month day): ";
           cin >> month;
           cin >> day;
           anniversary = month + ' ' + day;
       }
   }
}

