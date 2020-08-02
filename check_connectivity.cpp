#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> >adj;
int *queue;
int *visited;
int f = -1;
int r = 0;
void make_unvisited(int num)
{
for(int i=0;i<num;i++)
{
visited[i]=0;
}
}
void connnectivity(int s,int d,int n)
{
int chk = 0;
if(visited[s] == 0)
{
visited[s]=1;
queue[++f]=s;
}
int i = queue[r];
while(r <= n)
{
for(int j=0;j<=n;j++)
{
if(adj[i][j] == 1 && visited[j] == 0)
{
visited[j] = 1;
queue[++f] = j;
if(d == j)
{
chk = 1;
cout<<"their is a path to "<<s<<" "<<d<<endl;
break;
}
}
}
if(chk == 0 && i==n)
{
cout<<"their  is no path between this vertex\n";
break;
}
i=queue[++r];
}
}
int main()
{
int n;
cout<<"enter the number of vertices\n";
cin>>n;
visited = new int(n);
queue = new int(n);
make_unvisited(n);
for(int i=0;i<n;i++)
{
vector<int>temp;
temp.clear();
for(int j=0;j<n;j++)
{
int val;
cin>>val;
temp.push_back(val);
}
adj.push_back(temp);
}
int s,d;
cout<<"enter the source and destination vertex\n";
cin>>s>>d;
connnectivity(s,d,n-1);
return 0;
}
