#ifndef FINALPROJECT1_LIST_H
#define FINALPROJECT1_LIST_H

#include <iostream>
#include "ListNode.h"
#include "AddressBook.h"
using namespace std;

template<typename NODETYPE>
class List{
public:
   ~List(){
       if (!isEmpty()){
           ListNode<AddressBook>* currentPtr{firstPtr};
           ListNode<AddressBook>* tempPtr{};

           while (currentPtr != nullptr) {
               tempPtr = currentPtr;
               currentPtr = currentPtr->nextPtr;
               delete tempPtr;
           }
       }
   }

   void insertAtFront(const AddressBook& value){
       ListNode<AddressBook>* newPtr{getNewNode(value)};

       if (isEmpty()){
           firstPtr = lastPtr = newPtr;
       }
       else{
           newPtr->nextPtr = firstPtr;
           firstPtr = newPtr;
       }
   }

   bool deleteFromList(string& last, string& first){
       if (isEmpty()){
           return false;
       }

       else {
           ListNode<AddressBook>* tempPtr{firstPtr};
           ListNode<AddressBook>* prevPtr{nullptr};

           if (tempPtr->data.getLastName() == last && tempPtr->data.getFirstName() == first){
               firstPtr = tempPtr->nextPtr;
               delete tempPtr;
               return true;
           }
           else {
               while (tempPtr != nullptr && tempPtr->data.getLastName() != last && tempPtr->data.getFirstName() != first){
                   prevPtr = tempPtr;
                   tempPtr = tempPtr->nextPtr;
               }

               if (tempPtr == nullptr){
                   return false;
               }

               prevPtr->nextPtr = tempPtr->nextPtr;

               delete tempPtr;
               return true;
           }
       }
   }

   void changeData(string& last, string& first){
       if (isEmpty()){
           cout << "No data in list\n";
       }

       else {
           ListNode<AddressBook>* tempPtr{firstPtr};
               while (tempPtr != nullptr){
                   if (tempPtr->data.getLastName() == last){
                       if (tempPtr->data.getFirstName() == first){
                           tempPtr->data.changeNameOrDate();
                           cout << "Data changed\n";
                       }
                   }
                   tempPtr = tempPtr->nextPtr;
               }
       }
   }

   void showBirthdayCards(string& date){
       ListNode<AddressBook>* tempPtr{firstPtr};

       while (tempPtr != nullptr){
           if (tempPtr->data.getBirthday() == date){
               tempPtr->data.generateBirthdayCard();
           }
           tempPtr = tempPtr->nextPtr;
       }
   }

   void showAnniversaryCards(string& date){
       ListNode<AddressBook>* tempPtr{firstPtr};

       while (tempPtr != nullptr){
           if (tempPtr->data.getAnniversary() == date){
               tempPtr->data.generateAnniversaryCard();
           }
           tempPtr = tempPtr->nextPtr;
       }
   }

   bool isEmpty() const{
       return firstPtr == nullptr;
   }

   void print() const{
       if (isEmpty()){
           cout << "List is empty";
           return;
       }

       ListNode<AddressBook>* currentPtr{firstPtr};

       cout << "The list is \n\n";

       while (currentPtr != nullptr){
           cout << currentPtr->data.getLastName() << ", " << currentPtr->data.getFirstName() << "\n"
               << currentPtr->data.getAddress()
               << "Birthday: " << currentPtr->data.getBirthday() << "\n"
               << "Anniversary: " << currentPtr->data.getAnniversary() << "\n\n";
           currentPtr = currentPtr->nextPtr;
       }
   }
private:
   ListNode<AddressBook>* firstPtr{nullptr};
   ListNode<AddressBook>* lastPtr{nullptr};

   ListNode<AddressBook>* getNewNode(const AddressBook& value){
       return new ListNode<AddressBook>{value};
   }
};
#endif //FINALPROJECT1_LIST_H

