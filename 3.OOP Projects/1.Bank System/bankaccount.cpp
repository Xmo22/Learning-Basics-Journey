#include "bankaccount.h"
#include <iostream>
using namespace std;
#include "client.h"

int BankAccount::idCounter = 1000; 


BankAccount::BankAccount() {
    idCounter++;            
    accountID = idCounter; 
    balance = 0.0;
}


BankAccount::BankAccount(double startBalance) {
    idCounter++;
    accountID = idCounter;
    

    if (startBalance >= 0) {
        balance = startBalance;
    } else {
        balance = 0;
        cout << "Error: Initial balance cannot be negative. Set to 0.\n";
    }
}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        cout << "Success: Deposited " << amount << ". New Balance: " << balance << endl;
    } else {
        cout << "Error: Deposit amount must be positive.\n";
    }
}



int BankAccount::getAccountID() const {
    return accountID;
}

double BankAccount::getBalance() const {
    return balance;
}

void BankAccount::display() const {
    cout << "Account ID : " << accountID << endl;
    cout << "Balance    : " << balance << " EGP" << endl;
}