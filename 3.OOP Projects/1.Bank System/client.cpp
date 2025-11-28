#include "client.h"
#include <iostream>
using namespace std;
#include "bankaccount.h"


Client::Client(string n, string nid, string pn, BankAccount* account) 
    : Person(n, nid, pn) 
{

    this->myAccount = account; 
}


Client::~Client() {

    if (myAccount != nullptr) {
        delete myAccount;
    }
}


BankAccount* Client::getAccount() const {
    return myAccount;
}


void Client::display_info() const {
    cout << "\n---------------- CLIENT PROFILE ----------------\n";
    cout << "Name           : " << get_name() << "\n";
    cout << "National ID    : " << get_nationalID() << "\n";
    cout << "Phone Number   : " << get_phoneNumber() << "\n";
    

    if (myAccount != nullptr) {

        myAccount->display(); 
    }
    else {
        cout << "No Bank Account Linked.\n";
    }
    
    cout << "------------------------------------------------\n";
}