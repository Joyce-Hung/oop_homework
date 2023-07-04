#include<iostream>
#include<string>
using namespace std;
class Book
{
public:
    //Book();
    Book(string=" " ,string=" ", float=0.0, int=0);

    void printdata() ;
    void updatedata(char);

    void settitle(string) ;
    string gettitle();

    void setauthor(string);
    string getauthor() ;

    void setprice(float);
    float getprice() ;

    void setnumber(int);
    int getnumber() ;
private:
    string title;
    string author;
    float price;
    int number;
};
Book::Book(string bookname,string authorname, float bookprice, int num)
    :title(bookname), author(authorname), price(bookprice), number(num)
{
}
class Bookstore:  public Book
{
public:
    Bookstore();
    void addbook(Book);
    void printstock();
    void updatebook(string);
private:
    Book instock[10];
    int count;
};
void Book::settitle(string bookname)
{
    title=bookname;
}
string Book::gettitle() 
{
    return title;
}

void Book::setauthor(string authorname)
{
    author=authorname;
}
string Book::getauthor()
{
    return author;
}

void Book::setprice(float bookprice)
{
    price=bookprice;
}
float Book::getprice()
{
    return price;
}

void Book::setnumber(int booknumber)
{
    number=booknumber;
}
int Book::getnumber()
{
    return number;
}

void Book::printdata() 
{
    cout<<"Title: "<<gettitle()<<endl;
    cout<<"Author: "<<getauthor()<<endl;
    cout<<"Price: "<<getprice()<<endl;
    cout<<"Number of copies in stocks: "<<getnumber()<<endl;
}
void Book::updatedata(char code)
{
    string x;
    float y;
    int z;
    cout<<"Enter data: ";
    if(code=='T')
    {
        cin>>x;
        settitle(x);
    }
    else if(code=='A')
    {
        cin>>x;
        setauthor(x);
    }
    else if(code=='P')
    {
        cin>>y;
        setprice(y);
    }
    else if(code=='C')
    {
        cin>>z;
        setnumber(z);
    }
}
Bookstore::Bookstore()
{
    count=0;
}
void Bookstore::addbook(Book add)
{
        if(count<10)
        {
            instock[count]=add;
            count++;
        }
        else cout<<"Stock full!"<<endl;
        
}
void Bookstore::printstock()
{
    for(int i=0;i<count;i++)
    {
        if(instock[i].gettitle()!=" ")
        {
            cout<<"Book"<<i+1<<":"<<endl;
            instock[i].printdata();
        }
        
    }
}
void Bookstore::updatebook(string t)
{
    bool flag=0;
    char s;
    cin>>s;
    for(int i=0;i<count;i++)
    {
        if(instock[i].gettitle()==t)
        {
            instock[i].updatedata(s);
            flag=1;
        }
    }
    if(flag==0)
    {
        cout<<"Not found!"<<endl;
    }
    
}
int main()
{
    Book b1("Harry Potter","Amy",30.5,2);
    Book b2("Wonder","Bob",31.2,3);
    Bookstore bookstock;
    bookstock.addbook(b1);
    bookstock.addbook(b2);
    bookstock.printstock();

    cout<<"Enter 'T', 'A', 'P', or 'C' to modify the book data: ";
    bookstock.updatebook("Harry Potter");
    bookstock.printstock();
    cout<<endl;
}