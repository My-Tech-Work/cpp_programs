#include<iostream>
#include<string.h>
using namespace std;
int main()
{
string str;
string str1;
cout<<"enter the string\n";
cin>>str;
int len = str.length();
cout<<"which part of a string you wish to replace\n";
cin>>str1;
int len1 = str1.length();
cout<<"enter the  new string\n";
string str2;
cin>>str2;
int j=0;
for(int i=0;i<len;i++)
{
if(str[i]==str1[j])
{
j++;
if(j==len1)
{
int p=0;
int p1=i;
p1 += 1;
p1=p1-len1;
while(p<len1)
{
str[p1]=str2[p];
p++;
p1++;
}
}
}
else
{
j=0;
}
}
for(int k=0;k<len;k++)
{
cout<<str[k];
}
return 0;
}
