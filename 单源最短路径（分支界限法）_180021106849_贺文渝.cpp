#include<stdlib.h>
#include<iostream> 
#include<queue>
using namespace std;



typedef struct{
	int weight;//权值 
	int dist;//最短路径 
}Matrix;

typedef struct{
	int i;//节点编号 
	int length;
}Node;

typedef struct{
	int n;
	Matrix M[100][100];//邻接矩阵 
	Node N[100];
}Graph;



Graph G;
queue<int> q;
 
void CreateGraph()
{
    int m,n,t;
    cout<<"输入顶点数:"<<endl;
    cin>>G.n;
    cout<<"输入顶点:"<<endl;
    for(int i=1;i<=G.n;i++)
    {
        cin>>G.N[i].i;
        G.N[i].length=10000;
    }
 
    for(int i=1;i<=G.n;i++)
        for(int j=1;j<=G.n;j++)
        {
            G.M[i][j].weight=0;
        }
 
    cout<<"输入弧数及权重:\n";
    int num;
    cin >> num;
    for(int i=1;i<=num;i++)
        {
            cin>>m>>n>>t;
            G.M[m][n].weight=1;
            G.M[m][n].dist=t;
        }
 
}


int NextNode(int a,int b)
{
    for(int i=b+1;i<=G.n;i++)
        if(G.M[a][i].weight)
            return i;
    return 0;
}
 
void ShortestPaths(int v)
{
    int k=0;
    int t;
    G.N[v].length=0;
    q.push(G.N[v].i);
    while(!q.empty())
    {
        t=q.front();
        k=NextNode(t,k);
        while(k!=0)
        {
            if(G.N[t].length+G.M[t][k].weight<=G.N[k].length)//减枝操作
            {
                G.N[k].length=G.N[t].length+G.M[t][k].weight;
                q.push(G.N[k].i);
            }
            k=NextNode(t,k);
        }
        q.pop();
    }
}
 
void out()
{
    for(int i=1;i<=G.n;i++)
        cout<<G.N[i].i<<"------"<<G.N[i].length<<endl;
}


int main(){
	CreateGraph();
    ShortestPaths(1);
    out();
    return 0;
}
