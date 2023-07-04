#ifndef SAVING_H
#define SAVING_H
#include "Account.h"
class SavingsAccount : public Account
{
public:
    SavingsAccount(double=0.0,double=0.0);
    double calculateInterest();
    void credit(double);
    void debit(double);
private:
    double InterestRate;
};
#endif
