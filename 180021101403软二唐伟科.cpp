#include<stdio.h>
#include<stdlib.h>
#define MaxVertices 100 //假设包含100个顶点
#define MaxWeight 32767 //不邻接时为32767，但输出时用 "∞"
#define MAX 100
#define INF         (~(0x1<<31)) 
typedef struct{ //包含权的邻接矩阵的的定义
    char Vertices[MaxVertices];  //顶点信息的数组
    int Edge[MaxVertices][MaxVertices]; //边的权信息的数组
    int numV; //当前的顶点数
    int numE; //当前的边数
}AdjMatrix;

void CreateGraph(AdjMatrix *G) //图的生成函数
{ 
    int n,e,vi,vj,w,i,j;
    printf("请输入图的顶点数和边数（以空格分隔）：");
    scanf("%d%d",&n,&e);
    G->numV=n;G->numE=e;
    for(i=0;i<n;i++) //图的初始化
        for(j=0;j<n;j++)
            { 
            if(i==j)
                G->Edge[i][j]=0;
            else 
                G->Edge[i][j]=32767;
            }
    for(i=0;i<n;i++)
        for(i=0;i<G->numV;i++) //将顶点存入数组中
        { 
        printf("请输入第%d个顶点的信息(整型):",i+1);  
      // G->adjlist[i].vertex=getchar(); 
        scanf(" %c",&G->Vertices[i]);
        }
    printf("\n");

    for(i=0;i<G->numE;i++)
    { 
        printf("请输入边的信息i,j,w(以空格分隔):");
        scanf("%d%d%d",&vi,&vj,&w); 
        //若为不带权值的图，则w输入1
        //若为带权值的图，则w输入对应权值

        G->Edge[vi-1][vj-1]=w;//①
        //G->Edge[vj-1][vi-1]=w;//②
        //无向图具有对称性的规律，通过①②实现
        //有向图不具备此性质，所以只需要①
    }
}
void DispGraph(AdjMatrix G) //输出邻接矩阵的信息
{ 
    int i,j;
    printf("\n输出顶点的信息（整型）:\n");
    for(i=0;i<G.numV;i++)
        printf("%8c",G.Vertices[i]);

    printf("\n输出邻接矩阵:\n");
    printf("\t");
    for(i=0;i<G.numV;i++)
        printf("%8c",G.Vertices[i]);

    for(i=0;i<G.numV;i++)
    { 
        printf("\n%8d",i+1);
        for(j=0;j<G.numV;j++)
        { 
        if(G.Edge[i][j]==32767) 
        //两点之间无连接时权值为默认的32767，但输出时为了方便输出 "∞"
            printf("%8s", "∞");
        else
            printf("%8d",G.Edge[i][j]);
        }
        printf("\n");   
    }
}
void dijkstra(AdjMatrix *G)
{
    int i,j;
    int min,minid;
    int tmp;
    int vs;
    int prev[MAX] = {0};
    int dist[MAX] = {0};
    int visited[MAX];      // visited[i]=1表示"顶点vs"到"顶点i"的最短路径已成功获取。

    // 初始化
    printf("请输入要查询的单源顶点");
    scanf("%d",&vs);
    vs-=1;
    for (i = 0; i < G->numV; i++)
    {
        visited[i] = 0;              // 顶点i的最短路径还没获取到。
        prev[i] = 0;              // 顶点i的前驱顶点为0。
        dist[i] = G->Edge[vs][i];// 顶点i的最短路径为"顶点vs"到"顶点i"的权。
    }
    // 对"顶点vs"进行初始化
    visited[vs] = 1;//将顶点vs加入最短路径，对应的visited[i]置为1 
    dist[vs] = 0;//到自己的权为0 

    // 遍历G.vexnum-1次；每次找出一个顶点的最短路径。
    for (i = 1; i < G->numV; i++)
    {
        // 寻找当前最小的路径；
        // 即，在未获取最短路径的顶点中，找到离vs最近的顶点(minid)。
        min = INF;
        for (j = 0; j < G->numV; j++)
        {
            if (visited[j]==0 && dist[j]<min)
            {
                min = dist[j];
                minid = j;
            }
        }
        visited[minid] = 1;// 标记"顶点minid"为已经获取到最短路径

        // 更新当前最短路径和前驱顶点
        // 即，当已经"顶点minid的最短路径"之后，更新"未获取最短路径的顶点的最短路径和前驱顶点"。
        for (j = 0; j < G->numV; j++)
        {
            tmp = (G->Edge[minid][j]==INF ? INF : (min + G->Edge[minid][j]));// 防止溢出 

            if (visited[j] == 0 && (tmp  < dist[j]) )
            {
                dist[j] = tmp;
                prev[j] = minid;
            }
        }
    }

    // 打印dijkstra最短路径的结果
    printf("dijkstra(%c): \n", G->Vertices[vs]);
    for (i = 0; i < G->numV; i++)
        printf("  shortest(%c, %c)=%d\n", G->Vertices[vs], G->Vertices[i], dist[i]);
}
int main()
{ 
    AdjMatrix G;
    freopen("1.txt","r",stdin);
    CreateGraph(&G);
    dijkstra(&G);
    DispGraph(G);
