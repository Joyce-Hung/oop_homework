#include "Employee.h"
class HourlyEmployee: public Employee
{
public:
    static const int hoursPerWeek = 168;

    HourlyEmployee(const string &, const string &, const string &, 
    double = 0.0, double = 0.0, int = 1, int = 1, int = 1900);

    void setWage(double);
    double getWage() const;

    void setHours(double);
    double getHours() const;

    virtual double earnings(int);
    virtual void print() const;
private:
    double wage;
    double hours;
};