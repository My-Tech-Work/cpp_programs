#include<iostream>
#include<stdlib.h>
using namespace std;
class node
{
	public:
	int data;
	node *link;
};
class operation
{
public:
node *insert_conn(int num)
{
node *n[num];
node *head = NULL;
for(int i=0;i<num;i++)
{
int d;
cout<<"enter the node data\n";
cin>>d;
n[i] = new node();
n[i]->data = d;
n[i]->link = NULL;
if(head == NULL)
{
head=n[i];
}
else
{
node *tra = head;
while(tra->link != NULL)
{
tra=tra->link;
}
tra->link = n[i];
}
}
return head;
}
void display(node *obj)
{
if(obj == NULL)
{
cout<<"No Node is created\n";
}
else
{
while(obj != NULL)
{
cout<<obj->data<<endl;
obj = obj->link;
}
}
}
};
int main()
{
int number;
cout<<"enter the Number of nodes\n";
cin>>number;
operation op;
node *str;
str=op.insert_conn(number);
system("CLS");
cout<<"wish to display values in the node if so press 1\n";
int yes;
cin>>yes;
if(yes == 1)
{
node call;
op.display(str);
}
else
{
cout<<"exiting....";
}
exit(0);
return 0;
}
