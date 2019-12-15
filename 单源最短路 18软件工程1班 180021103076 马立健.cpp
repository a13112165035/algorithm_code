#include<iostream>
#include<string.h>
using namespace std;

const int maxint=1000005;
int c[10000][10000];
int dist[10000];
int pre[10000];
int n,m;
int start;


void dijkstra(int n,int v)
{
	bool s[maxint];
	for(int i=1;i<=n;i++)
	{
		dist[i]=c[v][i];
		s[i]=false;
		if(dist[i]==maxint)
		{
			pre[i]=0;
		}
		else
		{
			pre[i]=v;
		}
	}
	dist[v]=0;
	s[v]=true;
	for(int i=1;i<n;i++)
	{
		int temp=maxint;
		int u=v;
		for(int j=1;j<=n;j++)
		{
			if((!s[j])&&(dist[j]<temp))
			{
				u=j;
				temp=dist[j];
			}
		}
		s[u]=true;
		for(int j=1;j<=n;j++)
		{
			if((!s[j])&&(c[u][j]<maxint))
			{
				int newdist=dist[u]+c[u][j];
				if(newdist<dist[j])
				{
					dist[j]=newdist;
					pre[j]=u;
				}
			}
		}
	}
}

void find(int x)
{
	if(x!=start)
	{
		find(pre[x]);
		cout<<"->";
	}
	cout<<x;
}

int main()
{
	memset(c,1000005,sizeof(c));
	memset(dist,1000005,sizeof(dist));
	cout<<"Please enter the number of points and edges in the connected graph:"<<endl;
	cin>>n>>m;
	cout<<"Please enter the number of two points connected by each edge and the weight of the edge:"<<endl;
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if(z<c[x][y])
		{
			c[x][y]=z;
			c[y][x]=z;
		}
	}
	cout<<"Please enter the starting point number:";
	cin>>start;
	cout<<endl;
	dijkstra(n,start);
	for(int i=1;i<=n;i++)
	{
		if(i!=start)
		{
			if(dist[i]!=maxint)
			{
				find(i);
				cout<<endl;
				cout<<"Starting point "<<start<<" to "<<i<<" point distance is:"<<dist[i]<<endl<<endl;
			}
			else
			{
				cout<<"Starting point "<<start<<" and "<<i<<" disconnected"<<endl;
			}
		}
	}
	return 0;
}
