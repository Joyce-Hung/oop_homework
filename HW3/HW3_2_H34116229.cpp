#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
    char s[100]={};
    string w[50]={};
    while(cin.getline(s,100))
    {
        for(int i=0;i<50;++i)
        {
            w[i]="";
        }
        if(s[0]=='q')
        {
            break;//Enter 'q' to quit 
        }
        int a=0;
        for(char *c=s;*c;++c)
        {
            if(*c!=' ' && *c!=',' && *c!='.')
            {
                w[a]+=*c;
            }
            else if(*c==' ' || *c!=',' || *c!='.')
            {
                ++a;
                w[a]=*c;
                ++a;
            }
        }
        for(int i=0;i<50;++i)
        {
            if(w[i]=="his")
            {
                w[i]="her(s) or "+w[i];
            }
            else if(w[i]=="him")
            {
                w[i]="her or "+w[i];
            }
            else if(w[i]=="he")
            {
                w[i]="she or "+w[i];
            }
            else if(w[i]=="He")
            {
                w[i]=w[i]+" or she";
            }
            else if(w[i]=="His")
            {
                w[i]=w[i]+" or her(s)";
            }
            else if(w[i]=="Him")
            {
                w[i]=w[i]+" or her";
            }
            cout<<w[i];
        }
        cout<<endl;
        s[100]={};
    }   
    return 0;
}