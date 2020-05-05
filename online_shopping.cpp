#include<iostream>
#include<stdlib.h>
#include<malloc.h>
#include<iomanip>
#include<string.h>
using namespace std;
struct seller_detail
{
	string sellername;
	int sellerid;
	int yourprofit;

};
struct goods 
{
	int retailerid;
	string pname;
	int pid;
	int pquantity;
	int price;
};
struct seller_detail *store_address[200];
struct goods *product[10000];
struct goods *temp_store[10000];
void add_seller(string name,int id)
{
	struct seller_detail *x;
	x = (struct seller_detail*)malloc(sizeof(struct seller_detail));
	int i;
	static int j = 0;
	x->sellername = name;
	x->sellerid = id;
	store_address[j] = x;
	j++;
}
void store_room(int rid)
{
int check = 0;
for(int k=0;store_address[k]!=NULL;k++)
{
if(rid == store_address[k]->sellerid)
{
int c,pid1;
check = 1;
cout<<"enter 1 for update product\nenter 2 for New product\n";
cin>>c;
if(c == 1)
{
cout<<"enter the product id\n";
cin>>pid1;
for(int x=0;product[x]!=NULL;x++)
{
if(product[x]->retailerid == rid)
{
if(product[x]->pid == pid1)
{
int quan;
int oldquan;
cout<<"enter the Number of quantity of "<<product[x]->pname<<" to be increased\n";
cin>>quan;
oldquan = product[x]->pquantity;
product[x]->pquantity = product[x]->pquantity+quan;
quan = 0;
cout<<"Retailer Name "<<store_address[k]->sellername<<endl;
cout<<"Quantity before updating "<<oldquan<<endl;
cout<<"Quantity after updating "<<product[x]->pname<<" = "<<product[x]->pquantity<<endl;
}
}
}
}
if(c == 2)
{
cout<<"enter the number of product you like to add\n";
int n;
cin>>n;
for(int l=0;l<n;l++)
{
static int p1 = 0;
struct goods *ac;
ac = (struct goods*)malloc(sizeof(struct goods));
cout<<"enter the product name\n";
string nam;
cin>>nam;
ac->pname = nam;
int id1;
cout<<"enter the product id\n";
cin>>id1;
ac->pid = id1;
cout<<"enter the quantity\n";
int q;
cin>>q;
ac->pquantity = q;
cout<<"enter the price\n";
int p;
cin>>p;
ac->price = p;
ac->retailerid = rid;
product[p1] = ac;
p1++;
cout<<"one product added successfully\n";
}
}
}
}
if(check == 0)
{
cout<<"Please Register your Retailer Id\n";
}
}
void close(int retailerid)
{
int count = 0;
for(int inx=0;store_address[inx]!=NULL;inx++)
{
count++;
}
for(int pnx=0;store_address[pnx]!=NULL;pnx++)
{
if(retailerid == store_address[pnx]->sellerid)
{
cout<<store_address[pnx]->sellername<<" Seller is deleted\n";
free(store_address[pnx]);
if(count == 1)
{
store_address[pnx]=NULL;
}
}
}
for(int z=count-1;z>0;z--)
{
store_address[z-1]=store_address[z];
}
count=0;
for(int opo=0;product[opo]!=NULL;opo++)
{
count++;
}
for(int tnt=0;product[tnt]!=NULL;tnt++)
{
if(retailerid == product[tnt]->retailerid)
{
free(product[tnt]);
if(count == 1)
{
product[tnt]=NULL;
}
}
}
for(int u=count-1;u>0;u--)
{
product[u-1]=product[u];
}
}
void customer()
{
int finalpayment = 0;
cout<<"/*****Welcome to our online Shopping App*****/\n";
int number,q,n,e;
cout<<"enter the number of items you want to buy\n";
cin>>n;
string pnam[n];
int pprice[n];
int ppprice[n];
int pquan[n];
for(e=0;e<n;e++)
{
cout<<"Enter the Serial Number seen above to buy the product\n";
cin>>number;
b1:cout<<"Enter the quantity\n";
cin>>q;
if(q > temp_store[number-1]->pquantity)
{
cout<<"out of stock reduce the number of quantity\n";
goto b1;
}
pquan[e]=q;
pnam[e]=temp_store[number-1]->pname;
pprice[e]=temp_store[number-1]->price;
ppprice[e]=pprice[e]*pquan[e];
temp_store[number-1]->pquantity-=q;
int yt=0;
while(store_address[yt]!=NULL)
{
if(temp_store[number-1]->retailerid == store_address[yt]->sellerid)
{
store_address[yt]->yourprofit += ppprice[e];
}
yt++;
}
}
cout<<"Invoice for the purchased goods\n";
cout<<"----------------------------------------------\n";
cout<<"Product Name"<<"     "<<"Quantity"<<"     "<<"Price"<<"     "<<"Total price of product"<<endl;
for(int t=0;t<n;t++)
{
int l=pnam[t].length();
cout<<pnam[t]<<setw(20-l)<<pquan[t]<<setw(14)<<pprice[t]<<setw(11)<<ppprice[t]<<endl;
finalpayment +=finalpayment+ppprice[t];
}
cout<<"Total amount payable "<<finalpayment<<"Rs"<<endl;
cout<<"Paytm | GooglePay | PhonePay\n";
}
int profit(int idg)
{
for(int pyt=0;store_address[pyt]!=NULL;pyt++)
{
if(store_address[pyt]->sellerid == idg)
{
	return store_address[pyt]->yourprofit;
}
}
return 0;
}
void checkprofit()
{
int idnum;
cout<<"enter the retailer id\n";
cin>>idnum;
cout<<"Your Amount after selling goods is "<<profit(idnum);
}
int main()
{
string name;
int id=0;
int counter = 0;
int option;
int chk=0;
rollback:cout<<"Enter 1 for Selling goods\nEnter 2 for Purchasing goods\n";
cin>>chk;
if(chk == 1)
{
for(;;)
{
cout<<"*******/If Your Seller Add Your Details To Our App/*******\n";
cout<<"1 Add Retailer of shop\n2 Add goods\n3 Close your Business in our App\n4 If you wish the customer purchase products\n5check Amount gained after seeling your goods\n";
cin>>option;
switch(option)
{
case 1:cout<<"Enter your Retailer Name\n";
cin>>name;
back : cout<<"Enter 5 digit Number that is considered as your Retailer id\n";
cin>>id;
if(counter == 0)
{
add_seller(name,id);
counter++;
}
else
{
for(int i=0;store_address[i]!=NULL;i++)
{
	if(id == store_address[i]->sellerid)
	{
	cout<<"id already exists\n";
	goto back;
	}
}
add_seller(name,id);
}
break;
case 2:cout<<"Enter your retialer id to add or update products\n"; 
int rid12;
cin>>rid12;
store_room(rid12);
break;
case 3:cout<<"Enter the Retailer Id\n";
	int id123;
	cin>>id123;
	close(id123);
	break;
case 4:goto rollback;
break;
case 5:checkprofit();
break;
default:exit(0);
}
}
}
if(chk == 2)
{
cout<<"/*****Goods Available For Customer Purchase*****/"<<endl;
cout<<"Product Name"<<"     "<<"Quantity"<<"     "<<"Price"<<endl;
int sl=1;
for(int ttt=0;product[ttt]!=NULL;ttt++)
{
temp_store[ttt]=product[ttt];
int len=product[ttt]->pname.length();
cout<<sl<<" "<<product[ttt]->pname<<setw((20-(len+2)))<<product[ttt]->pquantity<<setw(13)<<product[ttt]->price<<"Rs"<<endl;
sl++;
}
customer();
goto rollback;
}
return 0;
}
