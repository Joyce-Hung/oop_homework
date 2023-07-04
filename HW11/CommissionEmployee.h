#include "Employee.h"
#ifndef CE_H
#define CE_H 
class CommissionEmployee : public Employee
{
public:
    CommissionEmployee(const string &, const string &, const string &, 
    double = 0.0, double = 0.0, int = 1, int = 1,int = 1900);

    void setCommissionRate(double);
    double getCommissionRate() const;

    void setGrossSales(double);
    double getGrossSales() const;

    virtual double earnings(int);
    virtual void print() const;
private:
    double grossSales;
    double commissionRate;
};
#endif