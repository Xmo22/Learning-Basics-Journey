#include "bankaccount.h" 
#include "savingaccount.h"
#include <iostream>
using namespace std;


SavingsBankAccount :: SavingsBankAccount(double balance, double min) 
    : BankAccount(balance) 
{

    if (min >= 0) {
        minBalance = min;
    } else {
        minBalance = 1000; // لو دخل قيمة غلط، نثبتها على 1000
        cout << "Invalid min balance, set to default (1000)\n";
    }
}


bool SavingsBankAccount::withdraw(double amount) {
    if (amount <= 0) {
        cout << "Invalid Amount!\n";
        return false; // فشل
    }

    if (balance - amount >= minBalance) {
        balance -= amount;
        cout << "Transaction Successful. New Balance: " << balance << endl;
        return true; // نجاح
    } else {
        cout << "Rejected. Min balance limit.\n";
        return false; // فشل
    }
}


void SavingsBankAccount::display() const {
    cout << "\n--- Savings Account Details ---\n";
    

    BankAccount::display(); 
    

    cout << "Minimum Balance: " << minBalance << endl;
    cout << "-------------------------------\n";
}

double SavingsBankAccount::getMinBalance() const {
    return minBalance;
}

void SavingsBankAccount::setMinBalance(double min) {
    if (min >= 0) minBalance = min;
}
