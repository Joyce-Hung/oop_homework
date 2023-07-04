#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
    char line[100]={};
    while(cin.getline(line,100))
    {
        int flag=0;
        if(line[0]=='q')
        {
            break;
        }
        int j,count=0;
        for(int i=count;i<100;++i)
        {
            if(int(line[i])>=48 && int(line[i])<=57 && line[i-1]==' ')
            {
                flag=1;
                for(j=i;line[j]!=' ';++j)
                {
                    if(int(line[j])<48 || int(line[j])>57)
                    {
                        flag=0;
                    }
                }
                count=j;
                if(flag==1)
                {
                    for(int n=i;n<=j-1;n++)
                    {
                        line[n]='x';
                    }
                }
            }
        }
        for(char *a=line;*a;++a)
        {
            cout<<*a;
        }
        cout<<endl;
        line[100]={};
    }//Enter 'q' to quit the loop
}