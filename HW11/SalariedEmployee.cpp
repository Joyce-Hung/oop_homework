#include"SalariedEmployee.h"
#include<string>
using namespace std;
SalariedEmployee::SalariedEmployee(const string &first, const string &last, 
    const string &ssn ,double salary, int m, int d, int y)
    :Employee(first, last, ssn, m, d, y)
{
    setWeeklySalary(salary);
}
void SalariedEmployee::setWeeklySalary(double salary)
{
    weeklySalary = ( salary<0.0 )? 0.0 : salary ;
}
double SalariedEmployee::getWeeklySalary() const
{
    return weeklySalary;
}
double SalariedEmployee::earnings(int m)  //return bool to check if it is the birthday month
{
    //temp.05.26
    if( getBirthDate().getMonth() == m )//
        return weeklySalary + 100;
    else return weeklySalary;
    
}
void SalariedEmployee::print() const
{
    cout<< "salaried employee: ";
    Employee::print();
    cout<<"\nmonthly salary: "<<getWeeklySalary();
}