#include<iostream>
using namespace std;
class Bank
{
public:
string accnt_name;
int acnt_num;
int balance=0;
void daily();
void monthly();
int find_account(int accnt_num,Bank accnt[],int num);
void update_balance(int bal,int a,int j,Bank obj[]);
};
class Bank1 : public Bank
{
public:
void daily()
{
cout<<"enter the account holder name\n";
cin>>accnt_name;
cout<<"enter the account number\n";
cin>>acnt_num;
cout<<"account created successfully\n";
cout<<"Balance = "<<this->balance<<endl;
}
void monthly()
{
cout<<"enter the account holder name\n";
cin>>accnt_name;
cout<<"enter the account number\n";
cin>>acnt_num;
cout<<"account created successfully\n";
cout<<"Balance = "<<this->balance<<endl;
}
int find_account(int accnt_num,Bank accnt[],int num)
{
for(int i=0;i<num;i++)
{
if(accnt_num == accnt[i].acnt_num)
{
return i;
}
}
cout<<"Invalid Account Number\n";
}
void update_balance(int bal,int a,int j,Bank obj[])
{
if(a == obj[j].acnt_num)
{
obj[j].balance = obj[j].balance + bal;
cout<<"Name  "<<obj[j].accnt_name<<endl;
cout<<"Balance "<<obj[j].balance<<endl;
}
else
{
cout<<"Invalid account number\n";
}
}
};
int main()
{
int accnt_num;
int temp;
Bank1 c;
cout<<"enter the total number of customer\n";
int n;
cin>>n;
Bank1 *obj = new Bank1[n];
int option;
int i = 0;
for(;;)
{
cout<<"1 Create Account\n2 Update Balance\n";
cin>>option;
int accnt_type;
switch(option)
{
case 1:cout<<"1 Daily Account\n2 Monthly Account\n";
       cin>>accnt_type;
       if(i < n)
       {
       if(accnt_type == 1)
       obj[i].daily();
       if(accnt_type == 2)
       obj[i].monthly();
       }
       break;
case 2:cout<<"Account Number\n";
       int accnt_n;
       cin>>accnt_n;
       int val;
       cout<<"enter the amount to update the balance\n";
       cin>>val;
       temp=c.find_account(accnt_n,obj,n);
       if(temp < n)
       obj[temp].update_balance(val,accnt_n,temp,obj);
       else
       cout<<"Invalid Account number\n";
	break;
	default : break;
}
i++;
}
return 0;
}

