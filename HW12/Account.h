#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<iostream>
#include <typeinfo>
using namespace std;
class Account
{
public:
    Account(double=0.0);
    void setBalance(double);
    double getBalance();
    virtual void credit(double) =0;
    virtual void debit(double) =0;
private:
    double balance;
};
#endif