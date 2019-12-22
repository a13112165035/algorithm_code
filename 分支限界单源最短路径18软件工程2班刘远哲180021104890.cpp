#include<bits/stdc++.h>
using namespace std;
const int N=105;
const int INF=1e9+7;

struct Node
{
	int id;
	int length;
};

bool operator > (const Node &a, const Node &b)
{
    return a.length > b.length;
}

int c[N][N];
int dist[N];
int n,m,v;

void ShortestPaths()
{
    priority_queue<Node, vector<Node>, greater<Node> > q; // 小根堆 
    dist[v] = 0; 											//初始化
    Node E;													//当前节点 
    E.id = v;
    E.length = 0;
    q.push(E);
    while(!q.empty())
    {
        E = q.top(); 										//取出堆顶的点
        q.pop(); 
		for(int i = 1; i <= n; i ++)						//寻找与E相连的点(即：边) 
        {
            if(c[E.id][i]!=INF && (E.length + c[E.id][i] < dist[i]))
            {
                dist[i] = E.length + c[E.id][i];
                Node N;
                N.id = i;
                N.length = dist[i];
                q.push(N);
            }
        }
    }
}

void init()
{
	cout << "请输入图的点数,边数及起点：";
	cin >> n >> m >> v;
	//初始化数据 
	for (int i=0;i<=n;i ++) for (int j=0;j<=n;j ++) c[i][j] = INF;
	for (int i=0;i<=n;i ++) dist[i] = INF;
	cout << "请依次输入每条边及权值" << endl;
	for(int i=1;i<=m;i++)
	{
		int x,y,len;
		cin >> x >> y >> len;
		c[x][y]=len;
	}
}

void print()			//输出每个点的最短路径 
{
	for(int i=1;i<=n;i++)
		if(i!=v)
			cout << "点" << v << "到点" << i << "的最短距离为：" << dist[i] << endl;
	
}

int main()
{
    init();
    ShortestPaths();
    print();
    return 0;
}
