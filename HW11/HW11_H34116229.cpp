#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "HourlyEmployee.h"
#include "BasePlusCommissionEmployee.h"
#include "Date.h"

using namespace std;
int main()
{
    cout<<fixed<<setprecision(2);
    SalariedEmployee salariedEmployee("John", "Smith", "111-11-1111", 800, 5,10,1986);
    HourlyEmployee hourlyEmployee("Karen", "Price", "222-22-2222", 16.75, 40, 2,16,1960);
    CommissionEmployee commissionEmployee("Sue", "Johns", "333-33-3333", 10000, 0.06, 
    7,4,1970);
    BasePlusCommissionEmployee basePlusCommissionEmployee("Bob", "Lewis", "444-44-4444",
    5000, 0.04, 300, 12,29,1983);
    
    vector < Employee * > employees(4);
    employees[0] = &salariedEmployee;
    employees[1] = &hourlyEmployee;
    employees[2] = &commissionEmployee;
    employees[3] = &basePlusCommissionEmployee;

    for(int i = 0; i < employees.size(); i++)
    {
        employees[i]->print();
        cout<<endl<<"Salary each month:"<<endl;
        for(int j = 0; j < 12; j++)
        {
            cout<<j+1<<":"<<employees[i]->earnings(j+1)<<endl;
        }
        cout<<endl;
    }
    
}


