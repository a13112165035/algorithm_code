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
typedef long long ll;
const int maxn = 1e3 + 10;
const int INF = 1 << 30;
int T, n, m;
int Map[maxn][maxn];//邻接矩阵存图
int v[maxn];//v[i] = 1表示已加入集合S
int d[maxn];//dist[i]表示距离源点的最短距离
int path[maxn];//记录路径
void dijkstra(int u0)//求顶点为u到其他顶点的最短路
{
    memset(v, 0, sizeof(v));
    for(int i = 0; i < n; i++)d[i] = (i == u0 ? 0 : INF);
    for(int i = 0; i < n; i++)path[i] = -1;
    for(int i = 0; i < n; i++)//每次加入一个节点，循环n次
    {
        int x, m = INF;
        for(int y = 0; y < n; y++)if(!v[y] && d[y] <= m)m = d[x = y];//记录当前最小值
        v[x] = 1;//标记已经加入集合
        for(int y = 0; y < n; y++)
        {
            if(d[y] > d[x] + Map[x][y])//松弛操作
            {
                d[y] = d[x] + Map[x][y];
                path[y] = x;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(i == u0)continue;
        printf("从%d到%d距离是：%2d   ", u0, i, d[i]);
        stack<int>q;
        int x = i;
        while(path[x] != -1)
        {
            q.push(x);
            x = path[x];
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
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)Map[i][j] = 0;
            else Map[i][j] = INF;
        }
    }
    int x, y, z;
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        Map[x][y] = z;
    }
    dijkstra(0);
    return 0;
}
