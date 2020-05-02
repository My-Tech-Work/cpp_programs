#include<iostream>
using namespace std;
int main()
{
	int n,str;
	cout<<"enter the value\n";
	cin>>n;
	str=n;
	cout<<"values after printing one number is\n";
	for(int i = n;i>=0;i--)
	{
		if(i == str && str>=0)
		{
			cout<<i<<endl;
			str = i-2;
		}
	}
	return 0;
}
