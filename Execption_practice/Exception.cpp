#include<iostream>
#include<stdexcept>
#include<sstream>
using namespace std;

class DayError : public runtime_error
{
public:
    DayError(): runtime_error("Invalid day!"){}
};

class MonthError : public runtime_error
{
public:
    MonthError():runtime_error("Invalid month!"){}
};
int validate_month(string md)
{
    string month;
    int m;
    stringstream ss;
    for(int i=0; md[i]!='/';++i)
    {
        month+=md[i];
    }
    ss<<month;
    ss>>m;
    if(m>12 || m<1)
    {
        throw MonthError();
    }
    return m;
}
int validate_day(string md)
{
    int m;
    int d;
    string day;
    stringstream ss;
    for(int i=0; i<md.size();++i)
    {
        if(md[i]=='/')
        {
            for(int j=i+1 ; j<md.size() ; j++)
            {
                day+=md[j];
            }
            break;
        }
    }
    ss<<day;
    ss>>d;
    m=validate_month(md);
    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) 
    {
        if(d<1 || d>31)
            throw DayError();
    }
    else if(m==2)
    {
        if(d<1 || d>29)
            throw DayError();
    }
    else
    {
        if(d<1 || d>30)
            throw DayError();
    }
    return d;
}
int main()
{
    string date;
    string month[12]={"Jan", "Feb", "Mar", "Apr", "May","Jun", "Jul", "Aug", 
    "Sep", "Oct", "Nov", "Dec"};
    cout<<" Enter a date (month/day): ";
    while(cin>>date)
    {
        if(date == "end")
        {
            break;
        }
        cout<<"\nAfter converted: ";
        try
        {
            cout<<month[validate_month(date)-1]<<" "<<validate_day(date)<<endl;

        }
        catch(MonthError &montherror)
        {
            cout<< "Exception occured: " << montherror.what() << '\n';
        }
        catch(DayError &dayerror)
        {
            cout<< "Exception occured: " << dayerror.what() << '\n';
        }
        cout<< endl <<" Enter a date (month/day): ";
        
    }
    

}