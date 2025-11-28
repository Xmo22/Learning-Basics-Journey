#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "bankaccount.h"

class CheckingBankAccount : public BankAccount {
private:
    double fee; 

public:

    CheckingBankAccount(double balance, double f = 50);


    bool withdraw(double amount) override;


    void display() const override;
};

#endif