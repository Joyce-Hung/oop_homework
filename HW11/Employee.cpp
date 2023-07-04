#include "Employee.h"
#include <iostream>
#include<string>
#include "Date.h"
using namespace std;
Employee::Employee( const string &first, const string &last, const string &ssn, int m,
    int d,int y)
:firstName(first), lastName(last), socialSecurityNumber(ssn), birthDate(m,d,y)
{
}
void Employee::setFirstName(const string &first)
{
    firstName = first;
}
string Employee::getFirstName() const
{
    return firstName;
}
void Employee::setLastName(const string &last)
{
    lastName = last;
}
string Employee::getLastName() const
{
    return lastName;
}
void Employee::setSocialSecurityNumber(const string &ssn)
{
    socialSecurityNumber = ssn;
}
string Employee::getSocialSecurityNumber() const
{
    return socialSecurityNumber;
}
Date Employee::getBirthDate() const
{
    return birthDate;
}
void Employee::print() const
{
    cout<< getFirstName() << ' ' << getLastName()<<
    "\nsocial security number: "<<getSocialSecurityNumber()<<endl
    <<"Birth date: ";
    birthDate.printDate();
    
}