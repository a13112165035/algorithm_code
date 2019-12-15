#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N=1010,INF=1e9+7;
int n,start;
int map[N][N],dis[N],pre[N];
bool vis[N];

struct node{
	int idx,dis,pre;
	friend bool operator<(node a,node b)
	{
		return a.dis>b.dis;
	}
};

priority_queue<node>q;

void dijkstra()
{
	dis[start] = 0;
	q.push(node{start,dis[start],start});
	while(!q.empty())
	{
		node now=q.top();
		q.pop();
		int k=now.idx;
		if(!vis[k])
		{
			vis[k]=1;
			pre[k]=now.pre;
			for(int j=1;j<=n;j++)
				if(dis[j]>dis[k]+map[k][j])
				{
					dis[j] = dis[k]+map[k][j];
					q.push(node{j,dis[j],k});
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
	int m;
	memset(map,0x3f,sizeof map);
	memset(dis,0x3f,sizeof dis);
	cout<<"输入图中点的个数，边的个数"<<endl;
	cin>>n>>m;
	cout<<"输入每条边连通的两个点的序号，边的权重"<<endl;
	for(int i=0;i<m;i++)
	{
		int x,y,z; 
		cin>>x>>y>>z;
		if(z<map[x][y]) 
		{
			map[x][y]=z;
			map[y][x]=z;
		}
	}
	cout<<"输入起点编号：";
	cin>>start; 
	dijkstra(); 
	for(int i=1;i<=n;i++)
		if(dis[i]!=INF)
		{
			find(i); 
			cout<<"，"<<start<<"点到"<<i<<"号点的最短距离："<<dis[i]<<endl; 
		} 
		else cout<<start<<"与"<<i<<"号点不连通"<<endl; 
	return 0; 
}
