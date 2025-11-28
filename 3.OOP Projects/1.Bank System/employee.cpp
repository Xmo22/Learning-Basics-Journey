#include "employee.h"
#include <iostream>

int Employee::employee_counter = 500;

Employee :: Employee(){
    salary = 0;
    bonus =0;
}

Employee :: Employee(double s , double bo , string n , string nid , string pn) : Person(n,nid,pn){
    employee_counter++;
    employee_id = employee_counter;
    set_salary(s);
    set_bonus(bo);
}

void Employee :: set_salary(double s){
    if(s <= 0){
        cout << "Invalid Salary go to HR Department" << "\n";
    }
    else{
        salary = s;
    }
}
double Employee :: get_salary() const{
    return salary;
}

void Employee :: set_bonus(double bo){
    if(bo < 0){
        cout << "Invalid Bonus Go to HR Department" << "\n";
    }
    else{
        bonus = bo;
    }
}
double Employee :: get_bonus()const{
    return bonus;
}
int Employee::get_employee_id() const {
    return employee_id;
}

void Employee :: display_info()const{
    cout << "\n---------------- EMPLOYEE DETAILS ----------------\n";
    cout << "Employee ID: " << employee_id << "\n";
    cout << "Employee Name: " << get_name() << "\n";;
    cout << "National ID: " << get_nationalID() << "\n";;
    cout << "Phone Number: " << get_phoneNumber() << "\n";;
    cout << "Salary: " << get_salary() << "\n";
    cout << "Bonus This Month: " << get_bonus() << "\n";
}

