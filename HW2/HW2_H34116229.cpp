#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
  int flag=1;
  int word=0;
  int count=1;
  char m[100]={};
  char temp=' ';
  cin.getline(m,100);
  int len=strlen(m);
  for(char *mptr=m ; *mptr!='\0' ; ++mptr)
  {
    if(*mptr==' ')
      word++;
    *mptr=tolower(*mptr);
  }
  word++;
  if(word==1)
  {
    cout<<word<<" word"<<endl;
  }
  else cout<<word<<" words"<<endl;
  
  for(char *mptr1=m ; *mptr1!='\0' ; ++mptr1)
  {

    for(char *mptr2=mptr1 ; *mptr2!='\0' ; ++mptr2)
    {
      if(int(*mptr1)>int(*mptr2))
      {
        temp=*mptr2;
        *mptr2=*mptr1;
        *mptr1=temp;
      }
    }
  }

  for(char *p=m;*p<=m[len-2];++p)
  {
    if(*p!=' ' && *p!=',' && *p!='.')
    {
      if(*p==*(p+1))
      {
        ++count; 
        if(*p==m[len-2])
        {
          cout<<count<<" "<<*(p+1)<<endl;
          break;
        }
      }
      else if(*p!=*(p+1))
      {
        if(*p==m[len-2])
        {
          flag=0;
          cout<<count<<" "<<*p<<endl;
          cout<<count<<" "<<*(p+1)<<endl;
          break;
        }
        else cout<<count<<" "<<*p<<endl;
        count=1;
      }
      
    }
  }
  return 0;
}
