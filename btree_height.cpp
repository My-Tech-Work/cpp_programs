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
}
}
}
int height(p traverse)
{
if(traverse == NULL)
{
return 0;
}
else
{
int lh=height(traverse->left);
int rh=height(traverse->right);
if(lh > rh)
return lh+1;
else
return rh+1;
}
}
int main()
{
        for(;;)
        {
        cout<<"1 Insert\n2 display\n3 delete\n4 height of a tree\n5 EXIT\n";
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
      /*  case 3:cout<<"enter key to delete node\n";
               cin>>val;
               del(root,val);
               break;*/
        case 4:cout<<"Height of a tree = "<<height(root)<<endl;
               break;
	case 5:exit(0);
	       break;
        default:exit(0);
        }
        }
        return 0;
}

