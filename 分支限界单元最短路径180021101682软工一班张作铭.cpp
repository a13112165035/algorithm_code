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
int c[N][N];
int dist[N];
int pre[N];
int n,m,v;

void ShortestPaths()
{
    priority_queue<Node, vector<Node>, greater<Node> > q;
    memset(dist, inf, sizeof(dist));
    dist[v] = 0; 
    pre[v] = v;
    Node E;
    E.id = v;
    E.length = 0;
    q.push(E);
    while(true)
    {
        if(q.empty())
            break;
        E = q.top(); 
        q.pop(); 
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
	if(i==pre[i])
	{
		cout << i;
		return;
	}
	else
	{
		out_path(pre[i]);
		cout << " -> " << i;
	} 
}

void out()
{
	cout << endl;
	for(int i=1;i<=n;i++)
	{
		if(i!=v)
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
