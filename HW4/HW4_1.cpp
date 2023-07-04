#include<iostream>
#include<cstring>
#include<string>

using namespace std;
class Account 
{
public:
    Account(int=0);   
    void credit(int);
    void debit(int);
    void print_in();
    void print_over();
    int getBalance();
private:
    int bal;
};

Account::Account(int v)
{
    if(v<0)
    {
        bal=0;
        print_in();
    }
    else bal=v;
    
}
void Account::print_in()
{
    cout<<"Invalid initial balance."<<endl;
}
void Account::print_over()
{
    cout<<"Debit amount exceeded account balance."<<endl;
}
void Account::credit(int a)
{
    bal=bal+a;
    getBalance();
}
void Account::debit(int d)
{
    if(bal-d<0)
    {
        print_over();
    }
    else bal=bal-d;
    getBalance();
}

int Account::getBalance()
{
    return bal;
}
int main()
{
    cout<<"case 1:"<<endl;
    Account m1(100);//initial value of case1

    cout<<"current balance:"<<m1.getBalance()<<endl;
    m1.debit(50);
    cout<<"current balance:"<<m1.getBalance()<<endl<<endl;

    cout<<"case 2:"<<endl;
    Account m2(-30);//initial value of case2
    cout<<"current balance:"<<m2.getBalance()<<endl<<endl;

    cout<<"case 3:"<<endl;//initial value of case3
    Account m3(10);
    cout<<"current balance:"<<m3.getBalance()<<endl;
    m3.credit(30);
    cout<<"current balance:"<<m3.getBalance()<<endl<<endl;

    cout<<"case 4:"<<endl;//initial value of case4
    Account m4(20);
    cout<<"current balance:"<<m4.getBalance()<<endl;
    m4.debit(40);
    cout<<"current balance:"<<m4.getBalance()<<endl;

}