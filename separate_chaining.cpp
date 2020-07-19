#include<iostream>
#include<stdlib.h>
#include<malloc.h>
using namespace std;
struct node 
{
int data;
struct node *link;
};
typedef struct node *point;
int size;
point *arr;
int hash1(int key)
{
return (key % size);
}
point memory()
{
point alloc = (point)malloc(sizeof(struct node));
return alloc;
}
void create_hash_table(int d)
{
int hash_code = hash1(d);
if(hash_code >= size || hash_code < 0)
{
cout<<"please reinput the  key\n";
exit(0);
}	
point temp = memory();
temp->data = d;
temp->link=NULL;
if(arr[hash_code] == NULL)
{
arr[hash_code]=temp;
}
else
{
point conn;
point trav = arr[hash_code];
while(trav != NULL)
{
conn = trav;
trav=trav->link;
}
conn->link = temp;
}
}
int search(int key)
{
int hc = hash1(key);
if(hc >= size || hc < 0)
{
cout<<"key cannot be searched\n";
}
point p = arr[hc];
int count=0,chk=0;
while(p != NULL)
{
if(p->data == key)
{
cout<<"key found at = "<<hc<<" "<<count<<endl;
chk=1;
break;
}
count++;
p=p->link;
}
if(chk == 0)
{
cout<<"key not found\n";
}
}
int main()
{
int option,ele,val;
cout<<"enter the array size\n";
cin>>size;
arr = new point[size];
for(;;)
{
cout<<"1 INSERT\n2 SEARCH\n3 EXIT\n";
cin>>option;
switch(option)
{
case 1:cout<<"enter the value for the node\n";
       cin>>ele;
        create_hash_table(ele);
 	break;
case 2:cout<<"enter the search element\n";
       cin>>val;
       search(val);
       break;
default:exit(0);
}
}
}
