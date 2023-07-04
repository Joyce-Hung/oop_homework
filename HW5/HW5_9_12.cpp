#include<iostream>
using namespace std;
class Date
{
public:
    Date(int=1,int=1,int=2000);
    void setDay(int,int,int);
    void setyear(int);
    void setmonth(int);
    void setdate(int);
    void displayDate();

    int getyear();
    int getmonth();
    int getdate();
private:
    int month;
    int date;
    int year;
};
Date::Date(int yr, int mth, int dt)
{
    setDay(yr,mth,dt);
}
void Date::setDay(int y,int m,int d)
{
    setyear(y);
    setmonth(m);
    setdate(d);
}
void Date::setyear(int y)
{
    year=y;
}
void Date::setmonth(int m)
{
    if(m<=0 || m>12)
    {
        m=1;
    }
    month=m;
}
void Date::setdate(int d)
{
    date=d;
}

int Date::getyear()
{
    return year;
}
int Date::getmonth()
{
    return month;
}
int Date::getdate()
{
    return date;
}

void Date::displayDate()
{
    cout<<month<<"/"<<date<<"/"<<year<<endl;
}

int main()
{
    Date day1,day2;
    day1.setDay(2006,5,28);
    day2.setDay(2023,13,4);

    cout<<"Date1: "<<endl;
    cout<<"Year: "<<day1.getyear()<<endl;
    cout<<"Month: "<<day1.getmonth()<<endl;
    cout<<"Date: "<<day1.getdate()<<endl;
    day1.displayDate();

    cout<<"Date2: "<<endl;
    cout<<"Year: "<<day2.getyear()<<endl;
    cout<<"Month: "<<day2.getmonth()<<endl;
    cout<<"Date: "<<day2.getdate()<<endl;
    day2.displayDate();
}