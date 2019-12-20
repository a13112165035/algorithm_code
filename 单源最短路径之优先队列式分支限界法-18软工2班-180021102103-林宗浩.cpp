#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
const int N=105;
const int inf=0x3f3f3f;

struct Node
{
	int id;
	int length;
};

bool operator < (const Node &a, const Node &b)
{
    return a.length < b.length;
}

bool operator > (const Node &a, const Node &b)
{
    return a.length > b.length;
}

//class MinHeapNode
//{
//public:
//    int id;
//    int length; //从起始点 v 到点 id 的距离
//public:
//    friend bool operator < (const MinHeapNode &a, const MinHeapNode &b)
//    {
//        return a.length < b.length;
//    }
//    friend bool operator > (const MinHeapNode &a, const MinHeapNode &b)
//    {
//        return a.length > b.length;
//    }
//};

int c[N][N];
int dist[N];
int pre[N];
int n,m,v;

void ShortestPaths()
{
	//优先队列 
    priority_queue<Node, vector<Node>, greater<Node> > q; // 小顶堆
    memset(dist, inf, sizeof(dist));
    dist[v] = 0; //初始化
    pre[v] = v;
    Node E;
    E.id = v;
    E.length = 0;
    q.push(E);
    while(true)
    {
        if(q.empty())
            break;
        E = q.top(); //取出堆顶的点
        q.pop(); // 在优先队列中删除刚取出的点
        for(int i = 1; i <= n; ++i)
        {
            if(c[E.id][i] != inf && (E.length + c[E.id][i] < dist[i]))
            {
                dist[i] = E.length + c[E.id][i];
                pre[i] = E.id;
                Node N;
                N.id = i;
                N.length = dist[i];
                q.push(N);
            }
        }
    }
}

void cin_input()
{
	cout << "请输入图的起点、节点数、边数：";
	int x,y,len;
	cin >> v >> n >> m;
	memset(c,inf,sizeof(c));
	cout << "请输入图的连接情况:(点，点，权值)" << endl;
	for(int i=1;i<=m;i++)
	{
		cin >> x >> y >> len;
		c[x][y]=c[y][x]=len;
	}
}

void out_path(int i)
{
    //从终点i往起点搜索，直到到达起点才开始往回return 
	if(i==pre[i])//该点的前驱节点等于自己，即起点，他是从终点i往起点搜索 
	{
		cout << i;//起点不用空格 
		return;
	}
	else
	{
		out_path(pre[i]);//一直递归到起点 
		cout << " -> " << i;
	}
}

void out()
{
	cout << endl;
    //所有点到起点的最短距离都输出来 
	for(int i=1;i<=n;i++)
	{
		if(i!=v)//起点到起点不用说 
		{
			cout << "点" << v << "到点" << i << "的最短距离为：" << dist[i] << endl;
			cout << "行进的路径为：";
			out_path(i);
			cout << endl; 
			if(i!=n)
				cout << "============================" << endl << endl; 
		}
	}
}

int main()
{
    cin_input();
    ShortestPaths();
    out();
    return 0;
}
