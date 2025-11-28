#ifndef CLIENT_H
#define CLIENT_H

#include "person.h"
#include "bankaccount.h" 

class Client : public Person {
private:

    BankAccount* myAccount; 

public:

    Client(string n, string nid, string pn, BankAccount* account);


    ~Client();


    BankAccount* getAccount() const; 
    

    void display_info() const override;
};

#endif