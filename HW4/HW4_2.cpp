#include<iostream>
#include<cstring>
#include<string>
#include<iomanip>
using namespace std;

class Invoice
{
public:
    Invoice();
    void set_num(string);
    void set_des(string);
    void set_amount(int);
    void set_price(int);

    string get_num();
    string get_des();
    int get_amount();
    int get_price();
    int getInvoiceAmount();
private:
    string num;
    string des;
    int amount;
    int price;
};
Invoice::Invoice()
{
    num=des=" ";
    amount=price=0;
}
void Invoice::set_num(string snum)
{
    num=snum;
}
string Invoice::get_num()
{
    return num;
}
void Invoice::set_des(string sdes)
{
    des=sdes;
}
string Invoice::get_des()
{
    return des;
}
void Invoice::set_amount(int sa)
{
    if(sa<0)
    {
        sa=0;
    }
    amount=sa;
}
int Invoice::get_amount()
{
    return amount;
}
void Invoice::set_price(int sp)
{
    if(sp<0)
    {
        sp=0;
    }
    price=sp;
}
int Invoice::get_price()
{
    return price;
}
int Invoice::getInvoiceAmount()
{
    return amount*price;
}
int main()
{
    cout<<"number "<<setw(6)<<"description"<<setw(10)<<"amount"<<setw(10)<<"price"<<
    setw(18)<<"invoice amount"<<endl;
    Invoice item1;
    item1.set_num("1");
    item1.set_des("Notebook");
    item1.set_amount(1);
    item1.set_price(20000);
    cout<<setw(6)<<item1.get_num()<<setw(12)<<item1.get_des()<<setw(10)<<item1.get_amount()<<setw(10)
    <<item1.get_price()<<setw(18)<<item1.getInvoiceAmount()<<endl;

    Invoice item2;
    item2.set_num("2");
    item2.set_des("Mouse");
    item2.set_amount(2);
    item2.set_price(800);
    cout<<setw(6)<<item2.get_num()<<setw(12)<<item2.get_des()<<setw(10)<<item2.get_amount()<<setw(10)
    <<item2.get_price()<<setw(18)<<item2.getInvoiceAmount()<<endl;

}