#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

#include "bankaccount.h"



class SavingsBankAccount : public BankAccount {
private:
    double minBalance; 

public:

    SavingsBankAccount(double balance, double min = 1000);


    bool withdraw(double amount) override;



    void display() const override;
    

    double getMinBalance() const;
    void setMinBalance(double min);
};

#endif