#include<iostream>
#include "Employee.h"
using namespace std;
#ifndef SE_H
#define SE_H 
class SalariedEmployee : public Employee
{
public:
    SalariedEmployee(const string &, const string &, const string &, double = 0.0, 
    int = 1, int = 1, int = 1900);

    void setWeeklySalary(double);
    double getWeeklySalary() const;

    virtual double earnings(int);
    virtual void print() const;
private:
    double weeklySalary;
};
#endif
