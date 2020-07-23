#include<iostream>
using namespace std;
void bfs(int n,int adj[][3])
{
int visited[n];
int queue[n];
int f=-1;
int r=0;
for(int i=0;i<n;i++)
{
visited[i]=0;
}
for(int k=0;k<n;k++)
{
if(visited[k]==0)
{
visited[k]=1;
queue[++f]=k;
}
for(int j=0;j<n;j++)
{
if(adj[queue[k]][j]==1 && visited[j]==0)
{
queue[++f]=j;
visited[j]=1;
}
}
}
for(r=0;r<=f;r++)
{
cout<<queue[r]<<" ";
}
}
int main()
{
int n;
cin>>n;
int adj[n][3];
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
cin>>adj[i][j];
}
}
bfs(n,adj);
return 0;
}
