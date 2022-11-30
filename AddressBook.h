#ifndef FINALPROJECT1_ADDRESSBOOK_H
#define FINALPROJECT1_ADDRESSBOOK_H

#include <string>
using namespace std;

class AddressBook {
public:
   AddressBook(string&, string&, string&, string&,
               string&,string&, string&, string = "");

   void setFirstName(string&);
   string getFirstName();
   void setLastName(string&);
   string getLastName();
   void setAddress(string&, string&, string&, string&);
   string getAddress() const;
   void setBirthday(string&);
   string getBirthday();
   void setAnniversary(string);
   string getAnniversary();

   void generateBirthdayCard();
   void generateAnniversaryCard();

   void changeNameOrDate();
private:
   std::string firstName;
   std::string lastName;
   std::string address;
   std::string city;
   std::string state;
   std::string zip;
   std::string birthday;
   std::string anniversary;
};


#endif //FINALPROJECT1_ADDRESSBOOK_H

