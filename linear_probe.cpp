#include<iostream>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
struct node 
{
int key;
};
typedef struct node *ptr;
int size;
ptr *arr;
ptr memory()
{
ptr x = (ptr)malloc(sizeof(struct node));
return x;
}
int hash1(int k)
{
return (k % size);
}
void create_hash_table(int data)
{
int h = hash1(data);
if(h < size || h > 0)
{
ptr temp = memory();
temp->key=data;
int lc = 0;
for(int i = h;i<=size-1;i++)
{
if(arr[i] == NULL)
{
arr[i] = temp;
break;
}
if(lc == 0 && i == size-1)
{
lc=1;
i=0;
}
}	
}
}
void display()
{
for(int j=0;j<=size-1;j++)
{
if(arr[j] != NULL)
cout<<j<<"->"<<arr[j]->key<<endl;
}
}
int main()
{
int option,data1,ele,s;
cout<<"enter the size of the array\n";
cin>>size;
arr = new ptr[size];
for(;;)
{
cout<<"1 INSERT\n2 DISPLAY\n3 EXIT\n";
cin>>option;
switch(option)
{
case 1:cout<<"enter the key\n";
       cin>>ele;
       create_hash_table(ele);
       break;
case 2:display();
       break;
default:exit(0);

}
}
return 0;
}
