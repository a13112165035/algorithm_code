#include <iostream>
#include<queue>
using namespace std;
typedef struct ArcCell{
    int adj;//保存权值 
    int info;//存储路径最短长度 
}
ArcCell,AdjMaxtrix[100][100];
typedef struct{
    int data;
    int length;
}VerType;

typedef struct{
    VerType vexs[100];//顶点向量 
    AdjMaxtrix arcs;
    int vexnum;//定点数 
    int arcnum;//弧数 
}Graph;
Graph G;
queue<int> q;
void CreateGraph()
{
    int m,n,t;
    printf("输入顶点数和弧数:");
    scanf("%d%d",&G.vexnum,&G.arcnum);
    printf("输入顶点:");
    for(int i=1;i<=G.vexnum;i++)
    {
        scanf("%d",&G.vexs[i].data);
        G.vexs[i].length=10000;
    }
    for(int i=1;i<=G.vexnum;i++)
        for(int j=1;j<=G.vexnum;j++)
        {
            G.arcs[i][j].adj=0;
        }
    printf("输入弧及权重:\n");
    for(int i=1;i<=G.arcnum;i++)
        {
            scanf("%d%d%d",&m,&n,&t);
            G.arcs[m][n].adj=1;
            G.arcs[m][n].info=t;
        }
}

int NextAdj(int v,int w)
{
    for(int i=w+1;i<=G.vexnum;i++)
        if(G.arcs[v][i].adj)
            return i;
    return 0;//not found;
}

void ShortestPaths(int v)
{
    int k=0;
    int t;
    G.vexs[v].length=0;
    q.push(G.vexs[v].data);
    while(!q.empty())
    {
        t=q.front();
        k=NextAdj(t,k);
        while(k!=0)
        {
            if(G.vexs[t].length+G.arcs[t][k].info<=G.vexs[k].length)
            {
               G.vexs[k].length=G.vexs[t].length+G.arcs[t][k].info;
                q.push(G.vexs[k].data);
            }
            k=NextAdj(t,k);
        }
        q.pop();
    }
}
void Print()
{
    for(int i=1;i<=G.vexnum;i++)
        printf("%d------%d\n",G.vexs[i].data,G.vexs[i].length);
}
int main()
{
    CreateGraph();
    ShortestPaths(1);
    Print();
    return 0;
}

