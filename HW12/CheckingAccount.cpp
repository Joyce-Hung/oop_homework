#include "CheckingAccount.h"
CheckingAccount::CheckingAccount(double b, double f)
: Account(b)
{
    fee=f;
}
void CheckingAccount::credit(double c)
{
    if(c + getBalance() -fee < 0)
    {
        cout<<"Transaction failed!"<<endl;
    }
    else
    {
        setBalance(getBalance() + c - fee);
        cout<<"Transction succeeded! Transaction fee would be charged."<<endl;
    }
}
void CheckingAccount::debit(double d)
{
    if(d+fee > getBalance())
    {
        cout<<"Transaction failed!"<<endl;
    }
    else
    {
        setBalance(getBalance() - d - fee);
        cout<<"Transction succeeded! Transaction fee would be charged."<<endl;
    }
}