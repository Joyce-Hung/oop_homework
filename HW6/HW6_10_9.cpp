#include<iostream>
#include<iomanip>
using namespace std;
class Time
{
public:
    Time(int =0);

    Time &setTime(int=0,int=0,int=0);
    Time &setHour(int);
    Time &setMinute(int);
    Time &setSecond(int);

    int getHour();
    int getMinute();
    int getSecond();

    void printUniversal();
    void printStandard();
private:
    int time;
};

Time::Time(int t)
{
    time=0;
}
Time &Time::setTime(int h, int m, int s )
{
    time=0;
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
    if(s>=60 || s<0)
    {
        s=0;
    }
    time+=s;
    return *this;
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
void Time::printUniversal()
{
    cout<<setfill('0')<<setw(2)<<time/3600<<":"<<setw(2)<<(time%3600)/60<<":"<<setw(2)
    <<(time%3600)%60;

}
void Time::printStandard()
{
    cout<<(((time/3600)==0||(time/3600)==12)?12:(time/3600)%12)
    <<":"<<setfill('0')<<setw(2)<<(time%3600)/60
    <<":"<<setw(2)<<(time%3600)%60<<(time/3600<12?" AM":" PM");

}

int main()
{
    Time t;

    t.setHour(18).setMinute(30).setSecond(22);

    cout<<"Universal time: ";
    t.printUniversal();

    cout<<"\nStandard time: ";
    t.printStandard();

    cout<<"\n\nNew standard time: ";

    t.setTime(20,20,20).printStandard();
    cout<<endl;
}