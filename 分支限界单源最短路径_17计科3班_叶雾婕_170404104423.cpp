#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f
class MinHeapNode
{
public:
	friend bool operator < (const MinHeapNode &a, const MinHeapNode &b)
	{
		return a.length < b.length;
	}
	friend bool operator > (const MinHeapNode &a, const MinHeapNode &b)
	{
		return a.length > b.length;
	}
public:
	int i; 
	int length; //从起始点 v 到点 id 的距离
};
const int max_ = 0x3f3f3f;
int n,						//图G的顶点数 
	prev[100];				//前驱顶点数组 
int c[100][100],		//图G的邻接矩阵 
	dist[100];				//最短距离数组 
int m,						//图G的边数
	v;						//起点 
void ShortestPaths()
{
	priority_queue<MinHeapNode, vector<MinHeapNode>, greater<MinHeapNode> > H; // 小顶堆 
	memset(dist, max_, sizeof(dist));
	MinHeapNode E;
	E.i = v;
	E.length = 0;
	dist[v]=0;
	prev[v] = v;
	H.push(E);
	while(true)
	 {
	 	if(H.empty() == 1)	break;
	 	E= H.top(); //取出堆顶的点
		H.pop(); // 在优先队列中删除刚取出的点
	 	for(int j=1;j<=n;j++)
	 	{
		 	if((c[E.i][j]<inf) && (E.length+c[E.i][j] < dist[j]))
		 	{
		 		dist[j] = E.length+c[E.i][j];
				prev[j] = E.i;
				MinHeapNode N;
				N.i = j;
				N.length=dist[j];
				H.push(N);
			}
		 }
	}
}
void InPut()
{
	int x, y, len;
	cin>>v>>n>>m;
	 memset(c, max_, sizeof(c));
	for(int i = 1; i <= m; ++i)
	{
		cin>>x>>y>>len;
		c[x][y] = c[y][x] = len;	
	}
}
void OutPutPath(int i)
{
	if(i == prev[i])
	{
		cout<<i<<"\t";
		return;
	}
	else
	{
		OutPutPath(prev[i]);
		cout<<i<<"\t";
	}
}
void OutPut()
{
	for(int i = 1; i <= n; ++i)
	{
		 if(i != v)
		{
			 cout<<"点"<<v<<"到"<<i<<"的最短距离是"<<dist[i]<<endl;
			 cout<<"路径为：";
			 OutPutPath(i);
			 cout<<endl;
		}
	}
}
int main()
{
	 InPut();
	 ShortestPaths();
	 OutPut();
}
/*测试数据
1 5 7
1 2 10
1 5 100
1 4 30
2 3 50
3 5 10
4 3 20
4 5 60
*/ 
