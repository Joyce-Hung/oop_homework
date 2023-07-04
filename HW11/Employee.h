#include<iostream>
using namespace std;
#include"Date.h"
#ifndef EM_H
#define EM_H
class Employee
{
public:
    Employee( const string &, const string &, const string &, int = 1, int = 1,int = 1900);

    void setFirstName( const string &);
    string getFirstName() const;

    void setLastName( const string &);
    string getLastName() const;

    void setSocialSecurityNumber( const string &);
    string getSocialSecurityNumber() const;

    Date getBirthDate() const;
    virtual double earnings(int) = 0;
    virtual void print() const;


private:
    string firstName;
    string lastName;
    string socialSecurityNumber;
    Date birthDate;//New data member
};
#endif