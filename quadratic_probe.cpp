#include<iostream>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
struct node 
{
int key;
};
typedef struct node *ptr;
ptr memory()
{
return (ptr)malloc(sizeof(struct node));
}
ptr *arr;
int size;
int hash1(int key)
{
return (key % size);
}
int collision(int u,int i)
{
return ((u+(i*i)) % size);
}
void create_hash_table(int d)
{
static int count = -1;
if(count == size-1)
{
cout<<"the array is full\n";
}
else
{
int chk=0;
ptr temp = memory();
temp->key = d;
int u = hash1(d);
if(arr[u] != NULL)
{
int j=-1;
for(;;)
{
if(chk == 1)
{
break;
}
j += 1;
int x = collision(u,j);
if(arr[x] == NULL)
{
arr[x]=temp;
count++;
break;
}
if(j==size-1)
{
for(int p=0;p<size-1;p++)
{
if(arr[p] == NULL)
{
arr[p]=temp;
count++;
chk=1;
break;
}
}
}
}
}
else
{
arr[u]=temp;
count++; 
}
}
}
void show_data()
{
for(int i=0;i<=size-1;i++)
{
if(arr[i] != NULL)
cout<<i<<"->"<<arr[i]->key<<endl;
}
}
int main()
{
int option,ele;
cout<<"enter the array size\n";
cin>>size;
arr = new ptr[size];
for(;;)
{
cout<<"1 INSERT\n2 DISPLAY\n3 EXIT\n";
cin>>option;
switch(option)
{
case 1:cout<<"enter the key value\n";
       cin>>ele;
	create_hash_table(ele);
	break;
case 2:show_data();
       break;
default:exit(0);
}
}
return 0;
}
