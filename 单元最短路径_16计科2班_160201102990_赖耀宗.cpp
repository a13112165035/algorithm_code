//单元最短路径
//16计科2班-160201102990-赖耀宗

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

#define maxn 110        
#define INF 0xffffff    
int w[maxn][maxn];      
int n;                 

struct node             
{
    int id, weight;     
    friend bool operator<(node a, node b)   
    {
        return a.weight > b.weight;
    }
};
priority_queue<node> q;     
int parent[maxn];          
bool visited[maxn];        
node d[maxn];               
void Dijkstra(int s)       
{
    for(int i = 1; i <= n; i++)     
    {
        d[i].id = i;
        d[i].weight = INF;          
        parent[i] = -1;            
        visited[i] = false;         
    }
    d[s].weight = 0;                
    q.push(d[s]);                  
    while(!q.empty())              
    {
        node cd = q.top();         
        q.pop();
        int u = cd.id;
        if(visited[u])
            continue;
        visited[u] = true;

        for(int v = 1; v <= n; v++)
        {
            if(v != u && !visited[v] && d[v].weight > d[u].weight+w[u][v])
            {
                d[v].weight = d[u].weight+w[u][v];
                parent[v] = u;
                q.push(d[v]);
            }
        }
    }
}
int main()
{
    int m, a, b, c, st, ed;
    printf("请输入顶点数和边数：\n");
    scanf("%d%d", &n, &m);
    printf("请输入边以及权值（a, b, c)\n");
    for(int i = 1; i <= n; i++)  
        for(int j = i; j <= n; j++)
            w[i][j] = w[j][i] = INF;
    while(m--)
    {
        scanf("%d%d%d", &a, &b, &c);
        if(w[a][b] > c)
            w[a][b]= w[b][a] = c;
    }
    printf("请输入起点和终点：\n");
    scanf("%d%d", &st, &ed);
    Dijkstra(st);
    if(d[ed].weight != INF)
        printf("最短路径权值为：%d\n", d[ed].weight);
    else
        printf("不存在从顶点%d到顶点%d的最短路径。\n", st, ed);
    return 0;
}


