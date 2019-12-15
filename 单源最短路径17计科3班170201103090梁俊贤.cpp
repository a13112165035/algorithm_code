#include<iostream>
using namespace std;
#define maxint 1000

int n;//有向图的顶点数
int pre[100];//pre[i]记录的是从源点到顶点i的最短路径的前一个顶点
int dis[100];//dis[i]表示当前从源到顶点i的最短特殊路径
int c[100][100];//c[i][j]表示边(i,j)的权 不通的边的权为无穷大 可以用1000代替
int v;//源顶点
int PATH[100];//存储路径
 
void input()
{
    cout<<"请输入有向图顶点的个数:"<<endl;
    cin>>n;
    cout<<"请输入源:"<<endl;
    cin>>v;
    cout<<"请以二维数组的形式输入有向图中各个结点的权(路径),无穷大的用1000表示"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>c[i][j];
        }
    }
}
void Dijkstra()
{
    //初始化操作
    bool s[maxint];
    for(int i=1;i<=n;i++)
    {
        dis[i]=c[v][i];
        s[i]=false;//集合S先置为空
        if(dis[i]==maxint)
            pre[i]=0;
        else
            pre[i]=v; 
    }
    //源点到源点距离为0；先把源点加入到集合S
    dis[v]=0;
    s[v]=true;
    for(int i=1;i<n;i++)//迭代n-1次
    {
        //找出从源点出发到各个顶点最短距离的那个顶点并将它加入集合S
        int temp = maxint;
        int u=v;
        for(int j=1;j<=n;j++)
            if((!s[j])&&(dis[j]<temp))
            {
                u=j;
                temp=dis[j];
            }
        s[u]=true;
        //更新路径
        for(int j=1;j<=n;j++)
        {
            if((!s[j])&&(c[u][j]<maxint))
            {
                int newdis=dis[u]+c[u][j];
                if(newdis<dis[j])
                {
                    dis[j]=newdis;
                    pre[j]=u;
                }
            }
        } 
    }
}

void Path(int destination)//利用pre数组回溯pre数组存储的是最短路径的上一个结点
{
    int Count=0;
    for(int i=pre[destination];i!=v;i=pre[i])
    {
        PATH[Count++]=i;
    }
    //因为pre记录的是上一个位置结点，所以需要反向输出。
    cout<<v;
    for(int i=Count-1;i>=0;i--)
    {
        cout<<"-->"<<PATH[i];
    }
    cout<<"-->"<<destination<<endl;
}

int main()
{
    int destination;
    input();
    Dijkstra();
    cout<<"请输入目的地"<<endl;
    cin>>destination;
    Path(destination);
    return 0;
}

