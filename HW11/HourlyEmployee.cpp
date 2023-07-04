#include"HourlyEmployee.h"
#include<iostream>
using namespace std;
HourlyEmployee::HourlyEmployee(const string &first, const string &last, const string &ssn,
    double hourlyWage, double hoursWorked, int m, int d, int y)
    :Employee(first, last, ssn, m, d, y)
{
    setWage(hourlyWage);
    setHours(hoursWorked);
}
void HourlyEmployee::setWage(double hourlyWage)
{
    wage = (hourlyWage < 0.0 ? 0.0: hourlyWage);
}
double HourlyEmployee::getWage() const
{
    return wage;
}
void HourlyEmployee::setHours(double hoursWorked)
{
    hours = ((hoursWorked >= 0.0) && (hoursWorked<=hoursPerWeek) ? hoursWorked : 0.0); 
}
double HourlyEmployee::getHours() const
{
    return hours;
}
double HourlyEmployee::earnings(int m)
{
    if(getHours()<=40)
        if(getBirthDate().getMonth() != m)
            return getWage()*getHours();
        else return getWage()*getHours() + 100;
    else 
        if(getBirthDate().getMonth() != m)
            return 40*getWage() + ((getHours() - 40)* getWage() * 1.5);
        else return 40*getWage() + ((getHours() - 40)* getWage() * 1.5) + 100;

}
void HourlyEmployee::print()const
{
    cout<<"hourly employee: ";
    Employee::print();
    cout<<"\nhourly wage: "<<getWage()<<"; hours worked: "<<getHours();
}