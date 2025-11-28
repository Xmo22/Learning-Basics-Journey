#include "person.h"
#include <iostream>
#include <regex>   
#include <cctype> 
using namespace std;


bool Person::isValidNationalID(string nid) {

    if (nid.length() != 14) 
        return false;


    for (char c : nid) {
        if (!isdigit(c)) 
            return false;
    }


    if (nid[0] != '2' && nid[0] != '3') 
        return false;

    return true; 
}

bool Person::isValidPhoneNumber(string pn) {

    regex pattern("^01[0-25][0-9]{8}$");
    return regex_match(pn, pattern);
}



Person::Person() {
    name = "unknown";
    NationalID = "0000";
    PhoneNumber = "0000";
}

Person::Person(string n, string nid, string pn) {
    set_name(n);
    set_nationalID(nid);
    set_phoneNumber(pn);
}



void Person::set_name(string n) {

    name = n;
}

string Person::get_name() const {
    return name;
}

void Person::set_nationalID(string nid) {

    if (isValidNationalID(nid)) {
        NationalID = nid;
    } else {

        cout << "Error: Invalid National ID format.\n";
    }
}

string Person::get_nationalID() const {
    return NationalID;
}

void Person::set_phoneNumber(string pn) {

    if (isValidPhoneNumber(pn)) {
        PhoneNumber = pn;
    } else {
        cout << "Error: Invalid Phone Number format.\n";
    }
}

string Person::get_phoneNumber() const {
    return PhoneNumber;
}