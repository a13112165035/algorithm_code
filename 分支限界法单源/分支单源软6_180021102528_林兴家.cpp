#include <iostream>
#include<queue>
using namespace std;
 
typedef struct {
    int w;//权
    int dist;//最短路径
}Maxtrix;
 
typedef struct{
    int i;
    int length;
}Node;
 
typedef struct{
	int n;//n is number of point
	Node N[100];
	Maxtrix M[100][100];//图的邻接矩阵 
}Graph;
 
Graph G;
queue<int> q;

void GetGraph()
{
    int m,n,t;
    cout<<"顶点的数量为："<<endl;
    cin>>G.n;
    
    cout<<"输入顶点："<<endl;
    for(int i=1;i<=G.n;i++)
    {
        cin>>G.N[i].i;
        G.N[i].length=10000;
    }
 
    for(int i=1;i<=G.n;i++)
        for(int j=1;j<=G.n;j++)
        {
            G.M[i][j].w=0;
        }
 
    cout<<"输入其权重：";//num
    int num;
    cin>>num;
    for(int i=1;i<=num;i++)
        {
            cin>>m>>n>>t;
            G.M[m][n].w=1;
            G.M[m][n].dist=t;
        }
 
}
 
int NextNode(int a,int b)
{
    for(int i=b+1;i<=G.n;i++)
        if(G.M[a][i].w)
            return i;
    return 0;//找不到 
}
 
void ShortestPaths(int v)
{
    int k=0;//从首个节点开始访问
    int t;
    G.N[v].length=0;
    q.push(G.N[v].i);
    while(!q.empty())
    {
        t=q.front();
        k=NextNode(t,k);
        while(k!=0)
        {
            if(G.N[t].length+G.M[t][k].w<=G.N[k].length)//减枝
            {
                G.N[k].length=G.N[t].length+G.M[t][k].w;
                q.push(G.N[k].i);
            }
            k=NextNode(t,k);
        }
        q.pop();
    }
}
 
void printf()
{
    for(int i=1;i<=G.n;i++)
        printf("%d的最短路径为：%d\n",G.N[i].i,G.N[i].length);
}
 
int main()
{
    GetGraph();
    ShortestPaths(1);
    printf();
    return 0;
}

