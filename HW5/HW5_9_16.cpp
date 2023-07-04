#include<iostream>
#include<iomanip>
using namespace std;

class Time
{
public:
    Time(int=0,int=0,int=0);
    void tick();
    void setTime(int,int,int);
    void printStandard();
    
private:
    int hour;
    int minute;
    int second;
};
Time::Time(int hr, int min, int sec)
{
    setTime(hr, min, sec);
}
void Time::tick()
{
    int temps=second;
    int tempm=minute;
    int temph=hour;
    ++temps;
    if(temps==60)
    {
        ++tempm;
        if(tempm==60)
        {
            ++temph;
        }
    }
    setTime(temph, tempm, temps);
}
void Time::setTime(int h,int m,int s)
{
    hour=(h>=0 && h<=24)? h:0;
    minute=(m>=0 && m<=59)? m:0;
    second=(s>=0 && s<=59)? s:0;
}

void Time::printStandard()
{
    cout<<((hour==0 || hour==12 || hour==24)?12 : hour%12)<<":"<<setfill('0')
    <<setw(2)<<minute<<":"<<setw(2)<<second<<((hour<12 || hour==24)? " AM" : " PM");
}

int main()
{
    Time t1(23,59,59);
    Time t2(11,30,59);
    Time t3(11,59,59);
    Time t4(15,19,16);
    //time increment loop for t1
    cout<<"Given time t1, ";
    t1.printStandard();
    for(int i=0;i<5;i++)
    {
        t1.tick();
        cout<<endl;
        cout<<"Standard time after"<<" an increment of "<<i+1<<" second(s) ";
        t1.printStandard();
        cout<<endl;
        
    }
    //time increment loop for t2
    cout<<endl<<"Given time t2, ";
    t2.printStandard();
    for(int i=0;i<5;i++)
    {
        t2.tick();
        cout<<endl;
        cout<<"Standard time after"<<" an increment of "<<i+1<<" second(s) ";
        t2.printStandard();
        cout<<endl;
    }

    //time increment loop for t3
    cout<<endl<<"Given time t3, ";
    t3.printStandard();
    for(int i=0;i<5;i++)
    {
        t3.tick();
        cout<<endl;
        cout<<"Standard time after"<<" an increment of "<<i+1<<" second(s) ";
        t3.printStandard();
        cout<<endl;
    }

    //time increment loop for t4
    cout<<endl<<"Given time t4, ";
    t4.printStandard();
    for(int i=0;i<5;i++)
    {
        t4.tick();
        cout<<endl;
        cout<<"Standard time after"<<" an increment of "<<i+1<<" second(s) ";
        t4.printStandard();
        cout<<endl;
    }
}