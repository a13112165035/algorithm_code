#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<sstream>
using namespace std;
const int INF = 1 << 30;
int T,n,m;
int Map[maxn][maxn];
int v[maxn];
int d[maxn];
int path[maxn];
void dijkstra(int u0)
{
	memset(v,0,sizeof(v));
	for(int i=0;i<n;i++)d[i]=(i==u0?0:INF);
	for(int i=0;i<n;i++)path[i]=-1;
	for(int i=0;i<n;i++)
	{
		int x,m=INF;
		for(int y=0;y<n;y++)if(!v[y]&&d[y]<=m)m=d[x=y];
		v[x]=1;
		for(int y=0;y<n;y++)
		{
			if(d[y]>d[x]+Map[x][y])
			{
				d[y]=d[x]+Map[x][y];
				path[y]=x;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i==u0)continue;
		printf("´Ó%dµ½%d¾àÀëÊÇ£º%2d",u0,i,d[i]);
		stack<int>q;
		int x=i;
		while(path[x]!=-1)
		{
			q.push(x);
			x=path[x];
		}
		cout<<u0;
		while(!q.empty())
		{
			cout<<"->"<<q.top();
			q.pop();
		}
		cout<<endl;
	}
 } 
 int main()
 {
 	cin>>n>>m;
 	for(int i=0;i<n;i++)
 	{
 		for(int j=0;j<n;j++)
 		{
 			if(i==j)Map[i][j]=0;
 			else Map[i][j]=INF;
		 }
	 }
	 int x,y,z;
	 for(int i=0;i<m;i++)
	 {
	 	cin>>x>>y>>z;
	 	Map[x][y]=z;
	 }
	 dijkstra(0);
	 return 0;
 }
