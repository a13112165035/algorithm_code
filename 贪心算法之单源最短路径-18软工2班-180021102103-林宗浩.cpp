#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<cstdlib>
using namespace std;
#define maxint 32767//表示极大值,即∞(无穷远)
#define mvnum 1005//最大顶点数
const int N=1005,INF=1e9+7;
int start;//起点
int c[N][N],dist[N],prev[N];

/*
步骤：
（1）先建立两个集合：用来存已经找到的最短路径的结点即S={}；用来存未找到的最短路径的结点即U={}
	S 和U互补，S U U=全集（所有结点），当U为空时，算法结束，找到最短路径
（2）若源与点i直接相连，则dist[i]等于权重，若源与i不直接相连，则dist[i]=∞
（3）建立数组dist[i],存源到i点的距离，选取最小的dist[i]存入到S中，将i从U中移除
	随着找到的路径结点更新源i 到未找到点的距离dist[i]	若点i已经在S中之后将不再更新dist[i]
（4）重复（3）步骤，直到U为空时，结束算法
*/

void Dijkstra(int n, int v)
{
	bool s[mvnum];//mvnum表示最大顶点数 
	//初始化 
	for(int i=1;i<=n;i++)
	{
		//从源点到i点的最短距离dist 
		dist[i]=c[v][i];//v为源点,i为除源点之外的点
		s[i]=false;//一开始集合S里无点,表示将i点,即所有点都不加入S集合中 
		if(dist[i]==maxint)//表示从源点到i点暂时无路,即无穷远 
		{
			prev[i]=0;
		}
		else
		{
			prev[i]=v;//一开始,都是直接从源点连接i点,如果有路,则将他的上一点个,即父亲点记录在prev中
		}
	}
	dist[v]=0;//从源点到源点距离为0
	s[v]=true;//将源点v加入集合S中
	for(int i=1;i<n;i++)//少了源点,即只要循环n-1次 
	{
		int temp=maxint;//中间变量为无穷远
		int u=v;//一开始,先将u点置为源点 
		for(int j=1;j<=n;j++)
		{//遍历所有点, 每次从剩余顶点中找出一个当前距离源点最近的顶点
			//如果这个点还未加入集合S,并且从源点到该点的距离小于无穷远 
			if((!s[j]) && (dist[j]<temp))
			{//只有与源点直接相连的点,即与源点相邻,有路的点才能将u置为该点 
				u=j;
				temp=dist[j];//然后将从源点到该点的距离赋给temp变量,temp表示当前为放入集合S的最小dist 
			}
		}
		//u表示当前为放入集合S的点,表示当前的最小距离 
		s[u]=true;//将点u加入集合S
		//从这个u点出发,看能不能找到改变其他点到源点的命运,即通过u点到源点能有更短的距离 
		for(int j=1;j<=n;j++)
		{
			//如果这个点还未加入集合S,并且从新加入的点u点到该点的距离小于无穷远,表示有路,u到j有路,即源点到该点有路 
			if((!s[j]) && (c[u][j]<maxint))
			{
				int newdist=dist[u]+c[u][j];//新距离,即更短的从源点到j点的距离
				if(newdist<dist[j])//测试从源点到u点再到j点的新距离,是不是比目前的距离更短 
				{//如果是,那么更新dist[j],并将他的父点置为u点,因为是通过u点才找到的更加短的距离 
					dist[j]=newdist;
					prev[j]=u;
				}
			}
		}
	}
}

void find(int x)
{
	if(x!=start)
	{
		find(prev[x]);
		cout << " -> ";
	}
	cout << x;
}

int main()
{
	int n,m;//顶点个数和边的个数
	cout << "请输入图的顶点和边的个数(格式：顶点个数 边个数)："; 
	cin >> n >> m;
//	memset(c,0x3f,sizeof(c));
//	memset(dist,0x3f,sizeof(dist));
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(i!=j)
				c[i][j]=c[j][i]=maxint;
			else
				c[i][j]=0;
		}
	}
	int minx,maxy;
	cout << "请输入图的路径长度(格式：起点 终点 长度)：" << endl;
	for(int i=0;i<m;i++)
	{
		//cout << "请输入第" << i+1 << "条边的连接情况(如:1 2 10,表示顶点1与顶点2相连,且权值为10):"; 
		int x,y,weight;
		cin >> x >> y >> weight;
		if(i!=0)
		{
			minx=min(minx,x);
			maxy=max(maxy,y);
		}
		else
		{
			minx=x;
			maxy=y;
		}
		if(weight<c[x][y])
        {
            //无向有权图
            c[x][y]=weight;
            c[y][x]=weight;
        }
	}
	cout << endl;
	cout<<"请输入起点编号：";
	cin>>start;
	Dijkstra(n,start);
	for(int i=minx;i<=maxy;i++)
    {
    	cout << endl << i << "号节点:" << endl; 
    	if(dist[i]!=maxint)
    	{
    		cout << "最优方案:"; 
    		find(i);
    		cout << endl;
    		cout << "起点" << start << "到" << i << "号点的最短距离为:" << dist[i] << endl;
    		cout << "前驱点是：" << prev[i] << endl;
		}
		else
			cout << "起点" << start << "点与" << i << "号点无路" << endl;
		cout << "----------------------" << endl; 
//          cout << i << "节点的最短距离是：" << dist[i] << "；前驱点是：" << prev[i] << endl;
    }
	return 0;
}
