#include<iostream>
#include<iomanip>
using namespace std;
class SavingsAccount
{
public:
    SavingsAccount(double=0);
    void calculateMonthlyInterest();
    static double modifyInterestRate(double);
    double getInterestRate();
private:
    static double annualInterestRate;
    double savingBalance;
    
};
double SavingsAccount::annualInterestRate=0.03;
SavingsAccount::SavingsAccount(double b)
    : savingBalance(b)
{
}
void SavingsAccount::calculateMonthlyInterest()
{
    savingBalance=savingBalance*(1+annualInterestRate/12);
    getInterestRate();
}
double SavingsAccount::modifyInterestRate(double newrate)
{
    annualInterestRate=newrate;
}
double SavingsAccount::getInterestRate()
{
    return savingBalance;
}
int main()
{
    cout<<"The 1st month of balance :"<<endl;
    SavingsAccount saver1(2000.00);
    saver1.calculateMonthlyInterest(); 
    cout<<"New balance for saver1 : "<<saver1.getInterestRate()<<endl;

    SavingsAccount saver2(3000.00);
    saver2.calculateMonthlyInterest(); 
    cout<<"New balance for saver2 : "<<saver2.getInterestRate()<<endl;

    SavingsAccount::modifyInterestRate(0.04);
    cout<<"The 2nd month of balance (after modifying the interest rate) :"<<endl;
    saver1.calculateMonthlyInterest();
    cout<<"New balance for saver1 : "<<saver1.getInterestRate()<<endl;
    saver2.calculateMonthlyInterest(); 
    cout<<"New balance for saver2 : "<<saver2.getInterestRate()<<endl;
    

}