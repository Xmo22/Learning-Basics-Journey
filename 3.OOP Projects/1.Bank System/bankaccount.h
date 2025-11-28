#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class BankAccount {

protected:
    int accountID;      
    double balance;     
    static int idCounter; 

public:

    BankAccount();
    BankAccount(double startBalance);

  
    virtual ~BankAccount() {}



    void deposit(double amount);

    virtual bool withdraw(double amount) = 0;



    
    int getAccountID() const;
    double getBalance() const;

    virtual void display() const;
};

#endif