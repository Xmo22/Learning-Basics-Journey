#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;

class Person {
private:
    string name;
    string NationalID;
    string PhoneNumber;

public:
    Person();
    Person(string n, string nid, string pn);

   
    void set_name(string n);
    void set_nationalID(string nid);
    void set_phoneNumber(string pn);

    string get_name() const;
    string get_nationalID() const;
    string get_phoneNumber() const;

   
    virtual void display_info() const = 0;

 
    static bool isValidNationalID(string nid);
    static bool isValidPhoneNumber(string pn);
};

#endif