#include<iostream>
#include<cmath>
#include<vector>
#include "Shape.h"
using namespace std;
/*class Shape
{
public:
    Shape();
    virtual double calculateArea()=0;
    virtual double calculatePerimeter()=0;
    virtual void displayInfo()=0;
};
Shape::Shape()
{
}*/
class TwoDimensionalShape : public Shape
{
public:
    TwoDimensionalShape();
    virtual double calculateArea(){};
    virtual double calculatePerimeter(){};
    virtual void displayInfo(){};
};
TwoDimensionalShape::TwoDimensionalShape()
{
}
class ThreeDimensionalShape : public Shape
{
public:
    ThreeDimensionalShape();
    virtual double calculateArea(){};
    virtual double calculatePerimeter(){};
    virtual double calculateVolume(){};
    virtual double calculateSurfaceArea(){};
    virtual void displayInfo(){};
};
ThreeDimensionalShape::ThreeDimensionalShape()
{
}
class Rectangle : public TwoDimensionalShape 
{
public:
    Rectangle(double = 1.0, double = 1.0);
    virtual double calculateArea();
    virtual double calculatePerimeter();
    virtual void displayInfo();
    void set_length(double);
    double get_length();
    void set_width(double);
    double get_width();
private:
    double length;
    double width;
};
Rectangle::Rectangle(double l, double w)
{
    set_length(l);
    set_width(w);
}
void Rectangle::set_width(double w)
{
    if(w<=0.0)
    {
        w=0.0;
        cout<<"Invalid input!"<<endl;
    }
    width = w;
}

void Rectangle::set_length(double l)
{
    if(l<=0.0)
    {
        l=0.0;
        cout<<"Invalid input!"<<endl;
    }
    length = l;
}

double Rectangle::get_width()
{
    return width;
}
double Rectangle::get_length()
{
    return length;
}
double Rectangle::calculateArea()
{
    return width*length;
}
double Rectangle::calculatePerimeter()
{
    return (length+width)*2;
}
void Rectangle::displayInfo()
{
    cout<<"Rectangle Information: "<<endl
        <<"Type: Rectangle"<<endl
        <<"Length: "<<get_length()<<" units"<<endl<<"Width: "<<get_width()<<" units"<<endl
        <<"Perimeter: "<<calculatePerimeter()<<" units"<<endl
        <<"Area: "<<calculateArea()<<" square units"<<endl;

}

class Circle : public TwoDimensionalShape 
{
public:
    Circle(double = 1.0);
    virtual double calculateArea();
    virtual double calculatePerimeter();
    virtual void displayInfo();
    void set_radius(double);
    double get_radius();
private:
    double radius;
};
Circle::Circle(double r)
{
    set_radius(r);
}
void Circle::set_radius(double r)
{
    if(r<=0.0)
    {
        r = 0.0;
        cout<<"Invalid input!"<<endl;
    }
    radius = r;
}
double Circle::get_radius()
{
    return radius;
}
double Circle::calculateArea()
{
    return radius*radius*M_PI;
}
double Circle::calculatePerimeter()
{
    return 2*radius*M_PI;
}
void Circle::displayInfo()
{
    cout<<"Circle Information: "<<endl
        <<"Type: Circle"<<endl
        <<"Radius: "<<get_radius()<<" units"<<endl
        <<"Perimeter: "<<calculatePerimeter()<<" units"<<endl
        <<"Area: "<<calculateArea()<<" square units"<<endl;

}


class Sphere : public ThreeDimensionalShape 
{
public:
    Sphere(double = 1.0);
    virtual double calculateSurfaceArea();
    virtual double calculateVolume();
    virtual void displayInfo();
    void set_radius(double);
    double get_radius();
private:
    double radius;
};
Sphere::Sphere(double r)
{
    set_radius(r);
}
void Sphere::set_radius(double r)
{
    if(radius<=0.0)
    {
        radius = 0.0;
        cout<<"Invalid input!"<<endl;
    }
    radius = r;
}
double Sphere::get_radius()
{
    return radius;
}
double Sphere::calculateSurfaceArea()
{
    return 4*M_PI*radius*radius;
}
double Sphere::calculateVolume()
{
    return 4.0/3.0*M_PI*pow(radius,3);
}
void Sphere::displayInfo()
{
    cout<<"Sphere Information: "<<endl
        <<"Type: Sphere"<<endl
        <<"Radius: "<<get_radius()<<" units"<<endl
        <<"Surface Area: "<<calculateSurfaceArea()<<" square units"<<endl
        <<"Volume: "<<calculateVolume()<<" cubic units"<<endl;
}
int main()
{
    int x;
    cout<<"Enter the number of shapes: ";
    cin>>x;
    cout<<endl<<endl;
    Rectangle rectangle(5.0, 3.0);
    Circle circle(4.0);
    Sphere sphere(3.0);
    vector < Shape * > shape(x);
    shape[0] = &rectangle;
    shape[1] = &circle;
    shape[2] = &sphere;
    for(int i=0;i<shape.size();i++)
    {
        cout<<"Shape "<<i+1<<":"<<endl;
        shape[i]->displayInfo();
        cout<<endl;
    }
    return 0;
}