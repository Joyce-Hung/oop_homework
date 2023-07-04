#include<iostream>
using namespace std;
class Account
{
public:
    Account(double=0.0);
    void setBalance(double);
    double getBalance();
    void credit(double);
    bool debit(double);
private:
    double balance;
};
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
void Account::credit(double c)
{
    balance += c;
}
bool Account::debit(double d)
{
    bool flag = true;
    if(balance - d < 0)
    {
        cout<< "Debit amount exceeded account balance."<<endl;
        flag = false;
    }
    else balance -= d;
    return flag;
}

class SavingsAccount : public Account
{
public:
    SavingsAccount(double=0.0,double=0.0);
    double calculateInterest();
private:
    double InterestRate;
};
SavingsAccount::SavingsAccount(double b, double i)
:Account(b)
{
    InterestRate = i;
}
double SavingsAccount::calculateInterest()
{
    return getBalance()*InterestRate*0.01;
}

class CheckingAccount : public Account
{
public:
    CheckingAccount(double = 0.0, double = 0.0);
    void credit(double);
    void debit(double);
private:
    double fee;
};
CheckingAccount::CheckingAccount(double b, double f)
: Account(b)
{
    fee=f;
}
void CheckingAccount::credit(double c)
{
    Account::credit(c-fee);
    cout<<"Transaction succeeded! Transaction fee would be charged."<<endl;;
}
void CheckingAccount::debit(double d)
{
    if(Account::debit(d+fee) == 0)
    {
        cout<<"Transaction failed!"<<endl;
    }
    else if(Account::debit(d+fee) == 1)
    {
        Account::credit(d+fee);
        cout<<"Transction succeeded! Transaction fee would be charged."<<endl;
    }
}
int main()
{
    SavingsAccount save(3000,1.6);
    cout<<"Initial Balance: "<<save.getBalance()<<endl;
    save.credit(save.calculateInterest());
    cout<<"Balance after adding interest: "<<save.getBalance()<<endl<<endl;

    CheckingAccount check(500,3);
    cout<<"Initial Balnce: "<<check.getBalance()<<endl;
    check.credit(20);
    cout<<"Current Balance:  "<<check.getBalance()<<endl;
    check.debit(100);
    cout<<"Current Balance:  "<<check.getBalance()<<endl;
    //cout<<"Balance after subtracting the transaction fee: "<<check.getBalance()<<endl;
    check.debit(500);
    cout<<"Current Balance: "<<check.getBalance()<<endl;
    return 0;
}