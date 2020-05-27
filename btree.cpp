#include<iostream>
#include<stdlib.h>
#include<malloc.h>
#define max 100
using namespace std;
struct node
{
int data;
struct node *left;
struct node *right;
};
typedef struct node *p;
p queue[max];
int f=-1;
int r=0;
p root;
void display(p traverse)
{
if(traverse == NULL)
return;
display(traverse->left);
if(traverse->left!=NULL || traverse->right!=NULL)
{
cout<<"root = "<<traverse->data<<endl;
}	
else
{
cout<<traverse->data<<endl;
}
display(traverse->right);
}
p memory()
{
p x;
x = (p)malloc(sizeof(struct node));
if(x == NULL)
{
cout<<"out of memory\n";
exit(0);
}
return x;
}
void insert(int d)
{
int val;
p temp = memory();
temp->data=d;
temp->left=NULL;
temp->right=NULL;
if(root == NULL)
{
root=temp;
queue[++f]=temp;
}
else
{
back:cout<<"enter the node value where you want to insert\n";
for(int i=0;i<=f;i++)
{
if(queue[i]!=NULL)
{
cout<<queue[i]->data<<" ";
}
}
cin>>val;
cout<<"enter 1 to connect to left\nenter 2 to connect to right\n";
int option;
cin>>option;
if(option == 1)
{
for(int k=0;k<=f;k++)
{
if(queue[k]!=NULL)
{
if(queue[k]->data == val)
{
if(queue[2*k+1]!=NULL)
{
goto back;
}
else
{
queue[2*k+1]=temp;
queue[k]->left=queue[2*k+1];
f=2*k+1;
break;
}
}
}
}
}
if(option == 2)
{
for(int p=0;p<=f;p++)
{
if(queue[p]!=NULL)
{
if(queue[p]->data==val)
{
if(queue[2*p+2]!=NULL)
{
goto back;
}
else
{
queue[2*p+2]=temp;
queue[p]->right=queue[2*p+2];
f=2*p+2;
break;
}
}
}
}
}
}
}
p inorder(p addr)
{
if(addr==NULL)
return NULL;
inorder(addr->left);
if(addr->left == NULL && addr->right == NULL)
return addr;
inorder(addr->right);
}
p store;
void del(p addr,int k)
{
if(root==NULL)
{
cout<<"tree is empty\n";
f=-1;
}
else
{
if(root->data == k)
{
free(root);
root=NULL;
for(int j=0;j<f+1;j++)
{
queue[j]=queue[j+1];
}
for(int j=0;j<f+1;j++)
{
if(queue[j]!=NULL)
{
queue[j]->left=queue[2*j+1];
queue[j]->right=queue[2*j+2];
}
}
root=queue[0];
}
else
{
for(int i=1;i<f+1;i++)
{
if(queue[i]!=NULL)
{
if(queue[i]->data == k)
{
if(queue[i]->left==NULL && queue[i]->right==NULL)
{
free(queue[i]);
queue[i]=NULL;
for(int j=0;j<f+1;j++)
{
if(queue[j]!=NULL)
{
queue[j]->left=queue[2*j+1];
queue[j]->right=queue[2*j+2];
}
}
}
else if(queue[i]->left!=NULL && queue[i]->right==NULL)
{
store=queue[i]->left;
free(queue[i]);
queue[i]=NULL;
queue[i]=store; 		
for(int x=0;x<f+1;x++)
{
if(queue[x]!=NULL)
{
queue[x]->left=queue[2*x+1];
queue[x]->right=queue[2*x+2];
}
}
}
else if(queue[i]->left==NULL && queue[i]->right!=NULL)
{
store=queue[i]->right;
free(queue[i]);
queue[i]=NULL;
queue[i]=store;
for(int g=0;g<f+1;g++)
{
if(queue[g]!=NULL)
{
queue[g]->left=queue[2*g+1];
queue[g]->right=queue[2*g+2];
}
}
}
else if(queue[i]->left!=NULL && queue[i]->right!=NULL)
{
for(int z=f;z>=0;z--)
{
if(queue[z]!=NULL)
{
if(queue[z]->left==NULL && queue[z]->right==NULL)
{
free(queue[i]);
queue[i]=NULL;
queue[i]=queue[z];
queue[z]=NULL;
queue[i]->left=queue[2*i+1];
queue[i]->right=queue[2*i+2];
for(int con=0;con<f+1;con++)
{
if(queue[con]!=NULL)
{
queue[con]->left=queue[2*con+1];
queue[con]->right=queue[2*con+2];
}
}
break;
}
}
}
}
}
}
}
}
}
}
int main()
{
	for(;;)
	{
	cout<<"1 Insert\n2 display\n3 delete\n4 exit\n";
	int opt,d,val;
	cin>>opt;
	switch(opt)
	{
	case 1:cout<<"value\n";
	       cin>>d;
		insert(d);
	       break;
	case 2:display(root);
	       break;
	case 3:cout<<"enter key to delete node\n";
	       cin>>val;
	       del(root,val);
	       break;
	case 4:exit(0);
	       break;
	default:exit(0);
	}
	}
	return 0;
}
