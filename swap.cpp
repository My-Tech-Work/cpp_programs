#include<iostream>
using namespace std;
int main()
{
	int first,second,temp;
	cout<<"enter 2 value\n";
	cin>>first>>second;
	cout<<"Value before swapping\n";
	cout<<first<<endl<<second<<endl;
	temp = first;
	first = second;
	second = temp;
	cout<<"Value after swapping\n";
	cout<<first<<endl<<second<<endl;
	return 0;
}
