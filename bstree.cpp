#include<iostream>
#include<stdlib.h>
#include<malloc.h>
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node *newnode;
newnode memory()
{
 newnode x;
x = (newnode)malloc(sizeof(struct node));
if(x == NULL)
{
cout<<"out of memory\n";
}
return x;
}
newnode root = NULL;
void connection(newnode r,newnode addr)
{
if(r == NULL)
{
cout<<"connection cannot be done as root not inserted\n";
return;
}
else
{
if(r->data < addr->data)
{
if(r->left == NULL)
r->left=addr;
else
connection(r->left,addr);
}
if(r->data > addr->data)
{
if(r->right == NULL)
r->right=addr;
else
connection(r->right,addr);
}
}
}
void insert(int d)
{
newnode temp;
temp=memory();
temp->data=d;
temp->left=NULL;
temp->right=NULL;
if(root == NULL)
{
root=temp;
}
else
{
newnode str=root,trav;
while(str!=NULL)
{
if(str->data > d)
{
trav = str;
str = str->left;
}
else
{
trav = str;
str=str->right;
}
}
if(trav->data >= d)
{
trav->left=temp;
}
else
{
trav->right=temp;
}
}
}
void display(newnode traverse)
{
if(traverse == NULL)
return;
display(traverse->left);
cout<<traverse->data<<endl;
display(traverse->right);
}
newnode search(newnode address,int key)
{
newnode s1,s2;
if(address == NULL)
return NULL;
else
{
if(address->data == key)
return address;
s1=search(address->left,key);
s2=search(address->right,key);
}
if(s1!=NULL)
{
if(s1->data == key)
return s1;
}
if(s2!=NULL)
{
if(s2->data == key)
return s2;
}
}
int max(newnode r)
{
int res;
if(r == NULL)
return INT_MIN;
res=r->data;
int str=max(r->left);
int str1=max(r->right);
if(res < str)
res=str;
if(res < str1)
res=str1;
return res;
}
int min(newnode r)
{
int res1;
if(r == NULL)
return INT_MAX;
res1=r->data;
int s=min(r->left);
int s1=min(r->right);
if(res1 > s)
res1=s;
if(res1 > s1)
res1=s1;
return res1;
}
newnode find_parent(newnode r,int data1)
{
if(r==NULL || r->data == data1)
return NULL;
if((r->left != NULL && r->left->data == data1) || (r->right != NULL && r->right->data == data1))
{
return r;
}
newnode t = find_parent(r->left,data1);
if(t != NULL)
return t;
t = find_parent(r->right,data1);
return t;
}
void del(int key)
{
newnode searched = search(root,key);
newnode parent_searched = find_parent(root,key);
if(searched == NULL)
{
cout<<"Node not inserted insert this node\n";
return;
}
if(searched->left == NULL && searched->right == NULL)
{
newnode p1 = find_parent(root,searched->data);
if(p1 == 0)
{
free(root);
root=NULL;
cout<<"No Node in the tree left to be Deleted\n";
return;
}
if(p1->left != NULL && p1->left->data == searched->data)
{
p1->left = NULL;
}
if(p1->right != NULL && p1->right->data == searched->data)
{
p1->right = NULL;
}
free(searched);
return;
}
int fetch_for_conn;
if(root->data==key)
{
fetch_for_conn=max(root->left);
if(root->left == NULL)
fetch_for_conn=min(root->right);
}
if(root->data < key)
{
fetch_for_conn=max(searched->left);
if(searched->left == NULL)
fetch_for_conn=min(searched->right);
}
if(root->data > key)
{
fetch_for_conn=min(searched->right);
if(searched->right == NULL)
fetch_for_conn=max(searched->left);
}
newnode par=find_parent(root,fetch_for_conn);
newnode ftadr = search(root,fetch_for_conn);
if(par->left != NULL && par->left->data == fetch_for_conn)
{
par->left = NULL;
}
if(par->right != NULL && par->right->data == fetch_for_conn)
{
par->right = NULL;
}
if(root->data == searched->data)
{
root=ftadr;
}
if(parent_searched != 0)
{
if(parent_searched->left != NULL && parent_searched->left->data == searched->data)
{
parent_searched->left=ftadr;
}
if(parent_searched->right != NULL && parent_searched->right->data == searched->data)
{
parent_searched->right=ftadr;
}
}
newnode t,t1;
t=searched->left;
t1=searched->right;
newnode f1,f2;
f1=ftadr->left;
f2=ftadr->right;
delete(searched);
ftadr->left=t;
ftadr->right=t1;
if(f1!=NULL)
connection(root,f1);
if(f2!=NULL)
connection(root,f2);
}
int main()
{
int opt,data;
for(;;)
{
cout<<"1 Insert\n2 display\n3 delete\n4 exit\n";
cin>>opt;
switch(opt)
{
case 1:cout<<"enter the value\n";
       cin>>data;
       insert(data);
       break;
case 2:display(root);
       break;
case 3:cout<<"enter the element to delete\n";
       cin>>data;
       del(data);
       break;
default:exit(0);
}
}	
return 0;
}
