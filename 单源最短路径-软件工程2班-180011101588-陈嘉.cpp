#include<iostream>
#include<string.h>
#define INF 999999
using namespace std;
int n,m;
int a,b,c;
int G[20005][2005];
int vis[2005],dis[2005];

void dij()
{
	for(int i=1;i<=n;i++)
	{
		int x=INF,min=INF;
		for(int j=1;j<=n;j++)
		{
			if(!vis[j]&&min>=dis[j])
			{
				min=dis[j];
				x=j;
			}
		}
		vis[x]=1;
		for(int j=1;j<=n;j++)
		{
			if(dis[j]>dis[x]+G[x][j])
				dis[j]=dis[x]+G[x][j];
		}
	}
}

int main()
{
	while(cin>>m>>n)
	{
		memset(vis,0,sizeof(vis));
		memset(G,INF,sizeof(G));
		for(int i=1;i<=n;i++)
			dis[i]=(i==1?0:INF);
		if(n==0||m==0)
		break;
		for(int i=1;i<=m;i++)
		{
			cin>>a>>b>>c;
			if(G[a][b]>c)
			{
			G[a][b]=c;
			G[b][a]=c;	
			}
		}
		dij();
		cout<<dis[n]<<endl;
	}
	return 0;
}

