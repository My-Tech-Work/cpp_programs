#include<iostream>
using namespace std;
class node 
{
	public:
	int data;
	node *link;
};
class opr
{
public:
void print(node *obj);
};
void opr :: print(node *obj)
{
while(obj!=NULL)
{
cout<<obj->data<<endl;
obj = obj->link;
}
}
int main()
{
	node *head = NULL;
	node *first;
	first = new node();
	first->data = 10;
	first->link = NULL;

        node *second = NULL;
	second = new node();
        second->data = 20;
        first->link = NULL;

        node *third=NULL;
	third = new node();
        third->data = 30;
        third->link = NULL;
	
	head = first;
	first->link = second;
	second->link = third;
	opr call;
	call.print(head);
	return 0;
}
