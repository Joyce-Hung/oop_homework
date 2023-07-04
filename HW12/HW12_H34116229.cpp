#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "typeinfo"
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector < Account * > account(2);
    SavingsAccount savings(40000, 0.02);
    CheckingAccount check(20000,10);
    account[0] = &savings;
    account[1] = &check;
    for(int i=0; i<account.size(); i++)
    {
        int m;
        cout<<"Input the money you want to withdraw: ";
        cin>>m;
        account[i]->debit(m);
        cout<<"Current balance: "<<account[i]->getBalance()<<endl;

        cout<<"Input the money you want to save: ";
        cin>>m;
        account[i]->credit(m);
        cout<<"Current balance: "<<account[i]->getBalance()<<endl;
        SavingsAccount *saveptr = dynamic_cast < SavingsAccount* > (account[i]);
        if(saveptr != 0)
        {
            cout<<"It's a savings account."<<endl;
            account[i]->credit(saveptr->calculateInterest());
            cout<<"Current balance: "<<account[i]->getBalance()<<endl;
        }
        else cout<<"It's a CheckingAccount."<<endl;
    }
    
    return 0;
}