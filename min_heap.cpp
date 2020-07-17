#include<iostream>
using namespace std;
struct node
{
int data;
struct node *left;
struct node *right;
};
typedef struct node *create;
int size,m;
create *temp;
create memory()
{
create x;
x=(create)malloc(sizeof(struct node));
if(x == NULL)
{
cout<<"out of memory\n";
return x;
}
return x;
}
void display(create r)
{
if(r==NULL)
return;
display(r->left);
cout<<r->data<<endl;
display(r->right);
}
create root = NULL;
void insert(int d,int i)
{
create t1;
create t = memory();
t->data=d;
t->left=NULL;
t->right=NULL;
temp[i]=t;
int x = i;
while(x >= 1)
{
if(temp[x]->data < temp[(x-1)/2]->data)
{
t1 = temp[x];
temp[x] = temp[(x-1)/2];
temp[(x-1)/2]=t1;
}
x--;
}
for(int k=0;k<=i;k++)
{
temp[k]->left=temp[2*k+1];
temp[k]->right=temp[2*k+2];
}
root=temp[0];
}
int main()
{
int option,ele,n=0;
cout<<"enter the number of nodes in the tree\n";
cin>>size;
temp = new create[size*2];
for(;;)
{
cout<<"1 INSERT\n2 DISPLAY\n3 EXIT\n";
cin>>option;
switch(option)
{
case 1:cout<<"enter the elements\n";
       cin>>ele;
       insert(ele,n);
       n++;
       break;
case 2:display(root);
       break;
default:delete[] temp;
        exit(0);
}
}
return 0;
}
