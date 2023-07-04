#include<iostream>
#include<iomanip>
#include "Time.h"
using namespace std;
Time::Time(int t)
{
    time=0;
}
Time &Time::setTime(int h, int m, int s )
{
    setHour(h);
    setMinute(m);
    setSecond(s);
    return *this;
}
Time &Time::setHour(int h)
{
    if(h<0 || h>=24)
    {
        h=0;
    }
    time+=3600*h;
    return *this;
}
Time &Time::setMinute(int m)
{
    if(m>=60 || m<0)
    {
        m=0;
    }
    time+=60*m;
    return *this;
}
Time &Time::setSecond(int s)
{
    time+=s;
}
int Time::getHour()
{
    int hour;
    hour=time/3600;
    return hour;
}
int Time::getMinute()
{
    int minute;
    minute=(time%3600)/60;
    return minute;
}
int Time::getSecond()
{
    int second;
    second=(time%3600)%60;
    return second;
}
void Time::printUniversal() const
{
    cout<<setfill('0')<<setw(2)<<time/3600<<":"<<setw(2)<<(time%3600)/60<<":"<<setw(2)
    <<(time%3600)%60;

}
void Time::printStandard() const
{
    cout<<((time/3600==0||time/3600==12)?12:(time/3600)%12)
    <<":"<<setfill('0')<<setw(2)<<(time%3600)/60
    <<":"<<setw(2)<<(time%3600)%60<<(time/3600<12?" AM":" PM");

}