#include "checkingaccount.h"
#include <iostream>
using namespace std;


CheckingBankAccount::CheckingBankAccount(double balance, double f) 
    : BankAccount(balance) 
{
    fee = f;
}


bool CheckingBankAccount::withdraw(double amount) {
    if (amount <= 0) {
        cout << "Invalid Amount!\n";
        return false; 
    }

    double totalAmount = amount + fee;
    if (balance >= totalAmount) {
        balance -= totalAmount;
        cout << "Transaction Successful. New Balance: " << balance << endl;
        return true;
    } else {
        cout << "Rejected. Insufficient balance.\n";
        return false;
    }
}


void CheckingBankAccount::display() const {
    cout << "--- Checking Account ---\n";
    BankAccount::display(); 
    cout << "Transaction Fee: " << fee << endl;
}
