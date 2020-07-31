#include<iostream>
#include<vector>
using namespace std;
vector<vector <int> >mat;
int *visited;
int *stack;
int n;
int top = -1;
void check_visited()
{
for(int i = 0;i<n;i++)
{
visited[i]=0;
}
}
void check_adjacency(int n1,int i,int target)
{
if(visited[i]==0 && mat[target][i]==1)
{
visited[i]=1;
top=top+1;
stack[top]=i;
}
if(i==n)
{
if(visited[target] == 0)
{
visited[target]=1;
top=top+1;
stack[top]=target;
}
return;
}
i=i+1;
check_adjacency(n1,i,target);
}
void topology_call(int k,int n2)
{
if(k <= n2)
{
check_adjacency(n2,0,k);
k=k+1;
topology_call(k,n2);
}
}
void print_stack_value(int m)
{
if(m <= top)
{
cout<<" -> "<<stack[m];
m=m+1;
print_stack_value(m);
}
}
int main()
{
cout<<"enter the number of vertices\n";
cin>>n;
visited = new int(n);
stack = new int(n);
check_visited();
cout<<"enter the adjacency matrix of the graph\n";
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
mat.push_back(temp);
}
topology_call(0,n-1);
cout<<"Topology order of given graph is\n";
print_stack_value(0);
cout<<endl;
return 0;
}
