#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> >adj;
vector<vector<int> >set;
void form_set()
{
vector<int>temp;
int str,ch3;
for(int k=0;k<adj.size();k++)
{
for(int m=0;m<adj.size();m++)
{
if(adj[k][m] == 1)
{
temp.clear();
temp.push_back(k);
temp.push_back(m);
if(set.empty())
{
set.insert(set.begin()+k,temp);
}
else
{
str=-1;
ch3=0;
for(int chk1=0;chk1<set.size();chk1++)
{
for(int chk2=0;chk2<set[chk1].size();chk2++)
{
if(set[chk1][chk2] == k)
{
for(int a1=0;a1<set[chk1].size();a1++)
{
if(set[chk1][a1] == m)
{
ch3 = 1;
break;
}
if(a1 == set.size() && ch3 == 0)
break;
}
}
}
}
if(ch3 == 0)
{
temp.clear();
temp.push_back(k);
temp.push_back(m);
set.insert(set.begin()+k,temp);
}
if(str != -1 && ch3 == 0)
{
temp.clear();
temp.push_back(k);
temp.push_back(m);
set.insert(set.begin()+k,temp);
}
}
}
}
}
}
int main()
{
int n;
cin>>n;
int val;
cout<<"enter 0 or 1 representation of graph\n";
for(int i=0;i<n;i++)
{
vector<int>a;
for(int j=0;j<n;j++)
{
cin>>val;
a.push_back(val);
}
adj.push_back(a);
}
form_set();
for(int x=0;x<set.size();x++)
{
for(int y=0;y<set[x].size();y++)
{
cout<<set[x][y]<<",";
}
cout<<endl;
}
return 0;
}
