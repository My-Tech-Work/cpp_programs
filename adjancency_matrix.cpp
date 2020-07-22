#include<iostream>
using namespace std;
int main()
{
int vertex;
cout<<"enter the number of graph vertex\n";
cin>>vertex;
int adj[vertex][vertex];
for(int i=0;i<vertex;i++)
{
cout<<"enter the "<<i<<" connected edges 0 if edges is not their 1 if it as a edge\n";
for(int j=0;j<vertex;j++)
{
cin>>adj[i][j];
}
}
cout<<"adjancency matrix\n";
for(int n=0;n<vertex;n++)
{
for(int m=0;m<vertex;m++)
{
cout<<" "<<adj[n][m]<<" ";
}
cout<<endl;
}
return 0;
}
