#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
class Shape
{
public:
    Shape(double = 1.0, double = 1.0);
    virtual double calculateArea()=0;
    virtual double calculatePerimeter()=0;
    virtual void displayInfo()=0;
private:
    double x;
    double y;
};
Shape::Shape(double m, double n)
:x(m),y(n)
{
}
class TwoDimensionalShape : public Shape
{
public:
    TwoDimensionalShape(double =1.0, double =1.0);
    virtual double calculateArea(){};
    virtual double calculatePerimeter(){};
    virtual void displayInfo(){};
};
TwoDimensionalShape::TwoDimensionalShape(double l, double w)
:Shape(l,w)
{
}
class ThreeDimensionalShape : public Shape
{
public:
    ThreeDimensionalShape(double =1.0 ,double = 1.0);
    virtual double calculateVolume(){};
    virtual double calculateSurfaceArea(){};
    virtual void displayInfo(){};
};
ThreeDimensionalShape::ThreeDimensionalShape(double a, double b)
:Shape(a)
{
}
class Rectangle : public TwoDimensionalShape 
{
public:
    Rectangle(double = 1.0, double = 1.0);
    virtual double calculateArea();
    virtual double calculatePerimeter();
    virtual void displayInfo();
    
private:
    double length;
    double width;
};
Rectangle::Rectangle(double l, double w)
:TwoDimensionalShape(l, w)
{
    
    if(l<=0.0 || w<=0.0)
    {
        l=0.0;
        w=0.0;
        cout<<"Invalid input!"<<endl;
    }
    length = l;
    width = w;
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
        <<"Length: "<<length<<" units"<<endl<<"Width: "<<width<<" units"<<endl
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
private:
    double radius;
};
Circle::Circle(double r)
:TwoDimensionalShape(r)
{
    if(r<=0.0)
    {
        r = 0.0;
        cout<<"Invalid input!"<<endl;
    }
    radius = r;
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
        <<"Radius: "<<radius<<" units"<<endl
        <<"Perimeter: "<<calculatePerimeter()<<" units"<<endl
        <<"Area: "<<calculateArea()<<" square units"<<endl;

}


class Sphere : public ThreeDimensionalShape 
{
public:
    Sphere(double = 1.0);
    virtual double calculateArea(){};
    virtual double calculatePerimeter(){};
    virtual double calculateSurfaceArea();
    virtual double calculateVolume();
    virtual void displayInfo();
private:
    double radius;
};
Sphere::Sphere(double r)
:ThreeDimensionalShape(r)
{

    if(radius<=0.0)
    {
        radius = 0.0;
        cout<<"Invalid input!"<<endl;
    }
    radius = r;
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
        <<"Radius: "<<radius<<" units"<<endl
        <<"SurfaceArea: "<<calculateSurfaceArea()<<" square units"<<endl
        <<"Volume: "<<calculateVolume()<<" cubic units"<<endl;
}
int main()
{
    int x;
    cout<<"Enter the numbers of shapes: ";
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