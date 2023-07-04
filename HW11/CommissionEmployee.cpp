#include<iostream>
#include"CommissionEmployee.h"
using namespace std;
CommissionEmployee::CommissionEmployee(const string &first, const string &last, 
    const string &ssn, double  sales, double rate, int m, int d, int y)
    :Employee(first, last, ssn, m, d, y)
{
    setGrossSales(sales);
    setCommissionRate(rate);
}
void CommissionEmployee::setCommissionRate(double rate)
{
    commissionRate = ((rate<1.0 && rate>0.0)? rate : 0.0);
}
double CommissionEmployee::getCommissionRate()const
{
    return commissionRate;
}

void CommissionEmployee::setGrossSales(double sales)
{
    grossSales = (sales<0.0)? 0.0 : sales;
}
double CommissionEmployee::getGrossSales()const
{
    return grossSales;
}
double CommissionEmployee::earnings(int m)
{
    if(getBirthDate().getMonth() != m)
        return getCommissionRate() * getGrossSales();
    else return getCommissionRate() * getGrossSales() + 100;
}
void CommissionEmployee::print() const
{
    cout<<"commission employee: ";
    Employee::print();
    cout<<"\ngross sales: "<<getGrossSales()<<"; commission rate: "<<getCommissionRate();
}