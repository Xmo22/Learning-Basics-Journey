#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "person.h"

class Employee : public Person
{
private:

double salary , bonus ;
int employee_id;
static int employee_counter;

public:
Employee();
Employee(double s , double bo , string n , string nid , string pn);

void set_salary(double s);
double get_salary()const ;

void set_bonus(double bo);
double get_bonus()const ;

void display_info() const override;

int get_employee_id() const;




}; 
#endif