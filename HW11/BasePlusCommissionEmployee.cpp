#include"BasePlusCommissionEmployee.h"
#include "Date.h"
using namespace std;
#ifndef BPE_H
#define BPE_H
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string &first, 
    const string &last, const string &ssn, double  sales, double rate, double salary, 
    int m, int d, int y)
    : CommissionEmployee(first, last, ssn, sales, rate, m, d, y)
{
    setBaseSalary(salary);
}
void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
    baseSalary = ((salary<0.0)? 0.0 : salary);
}
double BasePlusCommissionEmployee::getBaseSalary()const
{
    return baseSalary;
}
double BasePlusCommissionEmployee::earnings(int m)
{
    if(getBirthDate().getMonth() != m)
        return baseSalary + CommissionEmployee::earnings(m);
    else return baseSalary +CommissionEmployee::earnings(m) + 100;
}
void BasePlusCommissionEmployee::print() const
{
    cout<<"based-salaried: ";
    CommissionEmployee::print();
    cout<<"\ngross sales: "<<getBaseSalary();
}
#endif