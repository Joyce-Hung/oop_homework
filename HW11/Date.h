#include<iostream>
using namespace std;
#ifndef DATE_H
#define DATE_H 
class Date
{
    friend ostream &operator<<( ostream &, const Date &);
public:
    Date( int m = 1, int d =1, int y = 1900);
    void setDate(int, int, int);
    Date &operator++();
    Date operator++(int);
    const Date &operator+=(int);
    static bool leapYear(int);
    bool endOfMonth(int) const;
    int getMonth();
    void printDate() const;
private:
    int month;
    int year;
    int day;

    static const int days[];
    void helpIncrement();
}; 
#endif