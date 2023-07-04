#include "Account.h"
#include<iostream>
Account::Account(double bal)
{
    setBalance(bal);
}
void Account::setBalance(double bal)
{
    if(bal<0)
    {
        cout<<"Invalid initial balance."<<endl;
        balance = 0.0;
    }
    else balance = bal;
}
double Account::getBalance()
{
    return balance;
}

