#include<iostream>
#define MAX 5
using namespace std;
int visited[MAX];
int stack[MAX];
int top=-1;
void make_unvisited(int n)
{
for(int i=0;i<n;i++)
{
visited[i]=0;
}
}
int adjacent(int mat[][5],int n,int i,int target)
{
if(mat[target][i] == 1 && visited[i] == 0)
return i;
if(i == n)
{
return target;
}
i=i+1;
return adjacent(mat,n,i,target);
}
void dfs(int adj[][5],int i,int n)
{
static int getval = -1;
if(visited[i] == 0)
{
visited[i]=1;
stack[++top]=i;
cout<<" -> "<<stack[top];
}
getval = adjacent(adj,n,0,stack[top]);
if(getval == stack[top])
top=top-1;
if(top != -1)
dfs(adj,getval,n);
}
int main()
{
int n;
cout<<"enter the number of vertex\n";
cin>>n;
make_unvisited(n);
int adj[n][5];
cout<<"enter the array elements\n";
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
cin>>adj[i][j];
}
}
cout<<"dfs traversal of a given graph\n";
dfs(adj,0,n-1);
cout<<endl;
return 0;
}
