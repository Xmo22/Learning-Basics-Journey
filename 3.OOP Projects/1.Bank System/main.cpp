#include <iostream>
#include <vector>
#include <fstream>  // للملفات
#include <sstream>  // لتقطيع النصوص
#include "client.h"
#include "employee.h"
#include "savingaccount.h"
#include "checkingaccount.h"

using namespace std;


Client* findClient(vector<Client*>& list, string nid) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i]->get_nationalID() == nid) return list[i];
    }
    return nullptr;
}

Client* findClientByAccountID(vector<Client*>& list, int accID) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i]->getAccount() != nullptr) {
            if (list[i]->getAccount()->getAccountID() == accID) return list[i];
        }
    }
    return nullptr;
}

bool isClientPhoneExist(vector<Client*>& list, string phone) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i]->get_phoneNumber() == phone) return true;
    }
    return false;
}

bool isEmployeeNidExist(vector<Employee*>& list, string nid) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i]->get_nationalID() == nid) return true;
    }
    return false;
}

bool isEmployeePhoneExist(vector<Employee*>& list, string phone) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i]->get_phoneNumber() == phone) return true;
    }
    return false;
}


void saveClientsData(vector<Client*>& list) {
    ofstream file("clients.txt"); 
    if (!file.is_open()) { cout << ">>> Error: Unable to open clients file!\n"; return; }

    for (Client* c : list) {
        string accType = "CHECKING";
        if (dynamic_cast<SavingsBankAccount*>(c->getAccount())) accType = "SAVINGS";

        file << c->get_name() << "|" << c->get_nationalID() << "|" << c->get_phoneNumber() << "|"
             << accType << "|" << c->getAccount()->getBalance() << endl;
    }
    file.close();
    cout << ">>> Clients Data saved successfully!\n";
}

void loadClientsData(vector<Client*>& list) {
    ifstream file("clients.txt");
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string segment;
        vector<string> data;
        while (getline(ss, segment, '|')) data.push_back(segment);

        if (data.size() >= 5) {
            string name = data[0];
            string nid = data[1];
            string phone = data[2];
            string type = data[3];
            double balance = stod(data[4]);

            BankAccount* account = nullptr;
            if (type == "SAVINGS") account = new SavingsBankAccount(balance, 1000); 
            else account = new CheckingBankAccount(balance, 5); // ثبتنا المصاريف 5

            list.push_back(new Client(name, nid, phone, account));
        }
    }
    file.close();
    cout << ">>> Clients Data Loaded (" << list.size() << ").\n";
}



void saveEmployeesData(vector<Employee*>& list) {
    ofstream file("employees.txt");
    if (!file.is_open()) { cout << ">>> Error: Unable to open employees file!\n"; return; }

    for (Employee* e : list) {
        file << e->get_name() << "|" << e->get_nationalID() << "|" << e->get_phoneNumber() << "|"
             << e->get_salary() << "|" << e->get_bonus() << endl;
    }
    file.close();
    cout << ">>> Employees Data saved successfully!\n";
}

void loadEmployeesData(vector<Employee*>& list) {
    ifstream file("employees.txt");
    if (!file.is_open()) return;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string segment;
        vector<string> data;
        while (getline(ss, segment, '|')) data.push_back(segment);

        if (data.size() >= 5) {
            string name = data[0];
            string nid = data[1];
            string phone = data[2];
            double salary = stod(data[3]);
            double bonus = stod(data[4]);

            list.push_back(new Employee(salary, bonus, name, nid, phone));
        }
    }
    file.close();
    cout << ">>> Employees Data Loaded (" << list.size() << ").\n";
}


int main() {
    vector<Client*> clients;
    vector<Employee*> employees;


    loadClientsData(clients);
    loadEmployeesData(employees);

    int choice = -1;

    while (choice != 0) {
        cout << "\n======= BANK MANAGEMENT SYSTEM =======\n";
        cout << "1. Add New Client\n";
        cout << "2. Display All Clients\n";
        cout << "3. Add New Employee\n";
        cout << "4. Display All Employees\n";
        cout << "5. Deposit Money\n";
        cout << "6. Withdraw Money\n";
        cout << "7. Transfer Money\n";
        cout << "0. Exit (Save & Close)\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) { 
            string name, nid, phone;
            double balance;
            int accType;

            cout << "\n--- Enter Client Details ---\n";
            cout << "Name: "; 
            cin.ignore(); getline(cin, name); 

            while (true) {
                cout << "National ID: "; cin >> nid;
                if (!Person::isValidNationalID(nid)) { cout << ">>> Invalid ID format.\n"; continue; }
                if (findClient(clients, nid) != nullptr) { cout << ">>> ID already registered!\n"; continue; }
                break;
            }
            while (true) {
                cout << "Phone: "; cin >> phone;
                if (!Person::isValidPhoneNumber(phone)) { cout << ">>> Invalid Phone format.\n"; continue; }
                if (isClientPhoneExist(clients, phone)) { cout << ">>> Phone already registered!\n"; continue; }
                break;
            }
            
            cout << "Account Type (1. Savings / 2. Checking): "; cin >> accType;
            cout << "Initial Balance: "; cin >> balance;

            BankAccount* account = nullptr;
            if (accType == 1) account = new SavingsBankAccount(balance, 1000); 
            else account = new CheckingBankAccount(balance, 5); 

            clients.push_back(new Client(name, nid, phone, account));
            cout << "Client Added Successfully!\n";
        } 
        
        else if (choice == 2) { 
            if (clients.empty()) cout << "No clients found.\n";
            else for (auto c : clients) c->display_info();
        }

        else if (choice == 3) { 
            string name, nid, phone;
            double salary, bonus;
            cout << "\n--- Enter Employee Details ---\n";
            cout << "Name: "; 
            cin.ignore(); getline(cin, name);

            while (true) {
                cout << "National ID: "; cin >> nid;
                if (!Person::isValidNationalID(nid)) { cout << ">>> Invalid ID format.\n"; continue; }
                if (isEmployeeNidExist(employees, nid)) { cout << ">>> ID already registered!\n"; continue; }
                break;
            }
            while (true) {
                cout << "Phone: "; cin >> phone;
                if (!Person::isValidPhoneNumber(phone)) { cout << ">>> Invalid Phone format.\n"; continue; }
                if (isEmployeePhoneExist(employees, phone)) { cout << ">>> Phone already registered!\n"; continue; }
                break;
            }
            cout << "Salary: "; cin >> salary;
            cout << "Bonus: "; cin >> bonus;
            employees.push_back(new Employee(salary, bonus, name, nid, phone));
            cout << "Employee Added Successfully!\n";
        }

        else if (choice == 4) { 
            if (employees.empty()) cout << "No employees found.\n";
            else for (auto e : employees) e->display_info();
        }

        else if (choice == 5) { 
            string nid;
            cout << "Enter National ID: "; cin >> nid;
            Client* c = findClient(clients, nid);
            if (c) {
                double amount;
                cout << "Found: " << c->get_name() << ". Deposit: "; cin >> amount;
                c->getAccount()->deposit(amount);
            } else cout << "Client Not Found!\n";
        }

        else if (choice == 6) { 
            string nid;
            cout << "Enter National ID: "; cin >> nid;
            Client* c = findClient(clients, nid);
            if (c) {
                double amount;
                cout << "Found: " << c->get_name() << ". Withdraw: "; cin >> amount;
                c->getAccount()->withdraw(amount);
            } else cout << "Client Not Found!\n";
        }

        else if (choice == 7) {
            int sID, rID;
            double amt;
            cout << "\n--- Money Transfer ---\n";
            cout << "From Account ID: "; cin >> sID;
            Client* s = findClientByAccountID(clients, sID);
            if (!s) { cout << "Sender Not Found!\n"; continue; }

            cout << "To Account ID: "; cin >> rID;
            if (sID == rID) { cout << "Cannot transfer to self.\n"; continue; }
            Client* r = findClientByAccountID(clients, rID);
            if (!r) { cout << "Receiver Not Found!\n"; continue; }

            cout << "Transfer " << s->get_name() << " -> " << r->get_name() << "\n";
            cout << "Amount: "; cin >> amt;

            if (s->getAccount()->withdraw(amt)) {
                r->getAccount()->deposit(amt);
                cout << ">>> Transfer Successful!\n";
            } else cout << ">>> Transfer Failed!\n";
        }

        else if (choice == 0) {
            saveClientsData(clients);
            saveEmployeesData(employees);
            cout << "Goodbye!\n";
        }
        else cout << "Invalid choice!\n";
    }


    for (auto c : clients) delete c;
    clients.clear();
    for (auto e : employees) delete e;
    employees.clear();

    return 0;
}