#include<iostream>
#include<string>
using namespace std;
class Package
{
public:
    Package(string = " ", string = " ",string="",string=" ", string = " ", double = 0, double = 0);
    double calculateCost();

    void set_weight(double);
    double get_weight();

    void set_cost(double);
    double get_cost();
    void print();

private:
    string name;
    string address;
    string city;
    string state;
    double weight;
    double cost;
    string zip;
};
Package::Package (string n, string ad, string ci, string st, string z, double w, double c)
    :name(n), address(ad), city(ci), state(st), zip(z)
{
    set_cost(c);
    set_weight(w);
}
void Package::set_cost(double c)
{
    if(c<0)
    {
        c=0;
    }
    else cost=c;
    
}
void Package::set_weight(double w)
{
    if(w<0)
    {
        w=0;
    }
    else weight=w;
}
double Package::get_cost()
{
    return cost;
}
double Package::get_weight()
{
    return weight;
}
double Package::calculateCost()
{
    return get_cost() * get_weight();
}
void Package::print()
{
    cout<<"Name: "<<name<<endl;
    cout<<"Address: "<<address<<endl;
    cout<<"City: "<<city<<endl;
    cout<<"State: "<<state<<endl;
    cout<<"ZIP code: "<<zip<<endl;
}

class TwoDayPackage : public Package
{
public:
    TwoDayPackage(string = " ", string = " ",string="",string=" ", string = " ", double = 0, double = 0);
    double calculateCost();
    void set_flatfee();
    double get_flatfee();
private:
    double flatfee;
};
TwoDayPackage::TwoDayPackage(string n, string ad, string ci, string st, string z, double w, double c)
    :Package(n, ad, ci, st, z, w, c)
{
    set_flatfee();
}
void TwoDayPackage::set_flatfee()
{
    flatfee=4.23;
}
double TwoDayPackage::get_flatfee()
{
    return flatfee;
}
double TwoDayPackage::calculateCost()
{
    return Package::calculateCost()+get_flatfee();
}
class OvernightPackage : public Package
{
public:
    OvernightPackage(string = " ", string = " ",string="",string=" ", string = "", double = 0, double = 0);
    double calculateCost();
    void set_addfee();
    double get_addfee();
private:
    double addfee;
};
OvernightPackage::OvernightPackage(string n, string ad, string ci, string st, string z, double w, double c)
    :Package(n, ad, ci, st, z, w, c)
{
    set_addfee();
}
void OvernightPackage::set_addfee()
{
    addfee=5.54;
}
double OvernightPackage::get_addfee()
{
    return addfee;
}
double OvernightPackage::calculateCost()
{
    return (get_addfee()+get_cost())*get_weight();
}
int main()
{
    cout<<"General Package: "<<endl;
    Package p1 ("Jane", "A1-1", "Miami", "Florida", "33101", 0.5, 20);
    p1.print();
    cout << "Total Cost: "<<p1.calculateCost() << endl << endl;

    cout<<"Two Day Package: "<<endl;
    TwoDayPackage p2 ("John", "A3-3", "Seattle", "Washington","98101", 0.6, 30);
    p2.print();
    cout << "Total Cost: "<< p2.calculateCost() << endl << endl;

    cout<<"Overnight  Package: "<<endl;
    OvernightPackage p3 ("Tom", "A2-2", "L.A.", "California", "90001", 0.7, 40);
    p3.print();
    cout << "Total Cost: "<< p3.calculateCost() << endl << endl;
    return 0;
}