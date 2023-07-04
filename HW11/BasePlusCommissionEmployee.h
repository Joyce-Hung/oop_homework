#include"CommissionEmployee.h"
#ifndef BC_H
#define BC_H
class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
    BasePlusCommissionEmployee(const string &, const string &, const string &, 
    double = 0.0, double = 0.0,double = 0.0, int = 1, int = 1,int = 1900);

    void setBaseSalary(double);
    double getBaseSalary() const;

    virtual double earnings(int);
    virtual void print() const;
private:
    double baseSalary;
};
#endif