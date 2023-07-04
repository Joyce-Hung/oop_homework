#include<iostream>
#include<string>
using namespace std;
class Test
{
public:
    Test(char);
    void printname();
private:
    string str;

};
Test::Test( char temp)
{
    str=temp;
}
void Test::printname()
{
    cout<<str;
}
int main()
{
    char ch;
    cin>>ch;
    Test test(ch);
    test.printname();
}
