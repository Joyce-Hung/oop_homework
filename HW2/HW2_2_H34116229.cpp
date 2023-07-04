#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
    int count=0;
    char name[70]={0};
    string str[3]={};
    cin.getline(name,70);
    for(char *p=name;*p;++p)
    {
        if(*p!=' ')
        {
            str[count]+=*p;
        }
        else ++count;
    }
    if(count==1)
    {
        cout<<str[1]<<", "<<str[0];
    }
    else cout<<str[2]<<", "<<str[0]<<" "<<str[1];
    return 0;
}