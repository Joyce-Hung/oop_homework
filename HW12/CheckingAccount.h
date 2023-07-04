#ifndef CHECK_H
#define CHECK_H
#include"Account.h"
class CheckingAccount : public Account
{
public:
    CheckingAccount(double = 0.0, double = 0.0);
    virtual void credit(double);
    virtual void debit(double);
private:
    double fee;
};
#endif