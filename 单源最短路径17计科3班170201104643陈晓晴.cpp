#include <iostream>
using namespace std;
#define maxnum 100//最大顶点数
#define maxint 9999//最大权值


void Dijkstra(int n,int v,int *dist,int *prev,int c[maxnum][maxnum])
{
    bool s[maxnum];//s数组，即符合最短路径的集合
    for (int i=1;i<=n;i++)
    {
        dist[i] = c[v][i];
        if (dist[i]==maxint)
        {
            prev[i] = 0;
        }
        else
        {
            prev[i] = v;
        }
    }
    dist[v] = 0;
    s[v] = 1;//设置起始点已访问，且起始到起始点距离为0
    for (int i=2;i<=n;++i)//再寻找剩下的n-1个节点
    {
        int tmp = maxint;
        int u = v;
        for (int j=1;j<=n;++j)
        {
            if ((!s[j]) && dist[j]<tmp)//寻找邻接最短边以及对应点
            {
                u = j;
                tmp = dist[j];
            }
        }
        s[u] = 1;//收录该点

        for (int j=1;j<=n;++j)
        {
            if ((!s[j]) && c[u][j]<maxint)//更新每个点距离起点的最小值
            {
                int newdist = dist[u] + c[u][j];
                if (newdist<dist[j])
                {
                    dist[j] = newdist;
                    prev[j] = u;//更新前驱节点
                }
            }
        }
    }
}
//利用一个数组保存prev的前驱节点路径，prev[j]表示第j点的前一个点
void MinPath(int *prev,int v,int n)
{
    int que[maxnum];
    int t = 2;
    que[1] = n;//第一个点即保存的是终点
    int tmp = prev[n];//终点前的一个点
    while (tmp != v)//只要没到起点则继续储存
    {
        que[t] = tmp;
        t++;
        tmp = prev[tmp];
    }
    que[t] = v;
    for (int j=t;j>=1;--j)//打印路径
    {
        if (j!=1)
        {
            cout<<que[j]<<"->";
        }
        else
            cout<<que[j]<<endl;
    }
}
/*数据为
5
7
1 2 10
1 4 30
1 5 100
2 3 50
3 5 10
4 3 20
4 5 60
*/
int main()
{
    int n,edgenum;//顶点，边数
    int dist[maxnum];
    int prev[maxnum];
    int c[maxnum][maxnum];
    while (cin>>n>>edgenum)
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                c[i][j] = maxint;

        int p,q,weight;
        for (int i=1;i<=edgenum;i++)
        {
            cin>>p>>q>>weight;
            if (weight < c[p][q])
            { 
                c[p][q] = c[q][p] = weight;
            }
        }
        for (int i=1;i<=n;i++)
        {
            dist[i] = maxint;
        }
        for (int i=1;i<=n;++i)//打印权值矩阵
        {
            for (int j=1;j<=n;j++)
            {
                cout<<c[i][j];
                if (j == n)
                {
                    continue;
                }
                cout<<" ";
            }
            cout<<endl;
        }
        Dijkstra(n,1,dist,prev,c);
        cout<<"到最后一个点的最短路径长度为："<<dist[n]<<endl;
        cout<<"从起点到最后一个点的路径为： ";
        MinPath(prev,1,n);
    }
    return 0;
}

