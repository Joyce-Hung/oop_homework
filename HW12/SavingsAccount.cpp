#include "SavingsAccount.h"
SavingsAccount::SavingsAccount(double b, double i)
:Account(b)
{
    InterestRate = i;
}
double SavingsAccount::calculateInterest()
{
    return getBalance()*InterestRate*0.01;
}
void SavingsAccount::credit(double c)
{
    setBalance(c + getBalance());
}
void SavingsAccount::debit(double d)
{
    if(getBalance() - d < 0)
    {
        cout<< "Debit amount exceeded account balance."<<endl;
    }
    else setBalance(getBalance()-d);
}