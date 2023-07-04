#include<iostream>
using namespace std;
class Date
{
public:
    Date(int=1,int=1,int=2000);
    void nextDay();
    void print();
private:
    int month;
    int day;
    int year;

};
Date::Date(int m, int d, int y)
{
    month=m;
    day=d;
    year=y;
}

void Date::nextDay()
{
    ++day;
    if(month==2)
    {
        if(year%100!=0 && year%4==0)
        {
            if(day>29)
            {
                ++month;
                day=1;
            }
        }
        else if(year%100==0 || year%4!=0)
        {
            if(day>28)
            {
                ++month;
                day=1;
            }
        }
    }
    else if(month==4 || month==6 || month==9 || month==11)
    {
        if(day>30)
        {
            ++month;
            day=1;
        }
    }
    else if(month==12)
    {
        if(day>31)
        {
            ++year;
            month=1;
            day=1;
        }
    }
    else if(month==1 || month==5 || month==7 || month==8 || month==10)
    {
        if(day>31)
        {
            ++month;
            day=1;
        }
    }
    
}
void Date::print()
{
    cout<<month<<'/'<<day<<'/'<<year;
}
int main()
{
    Date date1(12,29,2007);
    Date date2(2,25,2004);
    Date date3(2,26,2000);
    //loop of date1
    cout<<"current date of date1: ";
    date1.print();
    cout<<endl;
    for(int i=0;i<5;++i)
    {
        date1.nextDay();
        date1.print();
        cout<<endl;
    }
    //loop of date2
    cout<<"current date of date2: ";
    date2.print();
    cout<<endl;
    for(int i=0;i<5;++i)
    {
        date2.nextDay();
        date2.print();
        cout<<endl;
    }
    //loop of date3
    cout<<"current date of date3: ";
    date3.print();
    cout<<endl;
    for(int i=0;i<5;++i)
    {
        date3.nextDay();
        date3.print();
        cout<<endl;
    }
    
}