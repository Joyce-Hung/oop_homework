#include<iostream>
#include<iomanip>
using namespace std;
class Rational
{
public:
    Rational(int=1,int=1,int=1,int=1);
    void setvalue(int,int,int,int);
    void add();
    void sub();
    void mul();
    void div();
    void print_r();
private:
    int denm;
    int num;
    int num1;
    int denm1;
    int num2;
    int denm2;
};
Rational::Rational(int keyn1, int keyd1,int keyn2,int keyd2)
{
    num=denm=1;
    setvalue(keyn1,keyd1,keyn2,keyd2);
    
}
void Rational::setvalue(int n1,int d1,int n2,int d2)
{
    int min=0;
    int temp=0;
    //transfer the first rational number to reduced form
    if(n1>d1)
    {
        min=d1;
    }
    else min=n1;
    for(int i=1;i<=min;++i)
    {
        if(n1%i==0 && d1%i==0)
        {
            temp=i;
        }
    }
    num1=n1/temp;
    denm1=d1/temp;
    //transfer the second rational number to reduced form
    min=temp=1;
    if(n2>d2)
    {
        min=d2;
    }
    else min=n2;
    for(int i=1;i<=min;i++)
    {
        if(n2%i==0 && d2%i==0)
        {
            temp=i;
        }
    }
    num2=n2/temp;
    denm2=d2/temp;
}

void Rational::add()
{
    int times=1;
    int min=0,temp=0;
    while(true)
    {
        if(times%denm1==0 && times%denm2==0)
        {
            break;
        }
        times++;
    }
    denm=times;
    num=num1*(times/denm1)+num2*(times/denm2);
    min=temp=1;
    if(num>denm)
    {
        min=denm;
    }
    else min=num;
    for(int i=1;i<=min;i++)
    {
        if(num%i==0 && denm%i==0)
        {
            temp=i;
        }
    }
    num=num/temp;
    denm=denm/temp;
}
void Rational::sub()
{
    int times=1;
    int min=0,temp=0;
    while(true)
    {
        if(times%denm1==0 && times%denm2==0)
        {
            break;
        }
        times++;
    }
    denm=times;
    num=num1*(times/denm1)-num2*(times/denm2);
    min=temp=1;
    if(num>denm)
    {
        min=denm;
    }
    else min=num;
    for(int i=1;i<=min;i++)
    {
        if(num%i==0 && denm%i==0)
        {
            temp=i;
        }
    }
    num=num/temp;
    denm=denm/temp;
}
void Rational::mul()
{
    num=num1*num2;
    denm=denm1*denm2;
    int min=0,temp=0;
    if(num>denm)
        min=denm;
    else min=num;
    for(int j=1;j<=min;j++)
    {
        if(denm%j==0 && num%j==0)
        {
            temp=j;
        }
    }
    num=num/temp;
    denm=denm/temp;
}
void Rational::div()
{
    denm=denm1*num2;
    num=num1*denm2;
    int min=0,temp=0;
    if(num>denm)
        min=denm;
    else min=num;
    for(int j=1;j<=min;j++)
    {
        if(denm%j==0 && num%j==0)
        {
            temp=j;
        }
    }
    num=num/temp;
    denm=denm/temp;
}
void Rational::print_r()
{
    cout<<num<<"/"<<denm<<" = "<<setprecision(6)<<float(num)/float(denm)<<endl;
}
int main()
{
    Rational r1;
    r1.setvalue(6,4,15,9);
    cout<<"Given two rational numbers : 6/4 and 15/9"<<endl;
    r1.add();
    cout<<"Addition :  ";
    r1.print_r();
    cout<<endl;
    r1.sub();
    cout<<"Subtraction :  ";
    r1.print_r();
    cout<<endl;
    r1.mul();
    cout<<"Multiplication :  ";
    r1.print_r();
    cout<<endl;
    r1.div();
    cout<<"Division :  ";
    r1.print_r();
    cout<<endl;
}