#include <stdio.h>

#define M 65535 
#define N 5 

void Dijkstra(int c[][N], int v, int dist[], int prev[])
{
    int s[N];
    for(int i=0; i<N; i++)
    {
        dist[i] = c[v][i];
        s[i] = 0;
        if(dist[i] == M)
            prev[i] = -1;
        else
            prev[i] = v;
    }
    dist[v] = 0;
    s[v] = 1; 
    for(int i=1; i < N; i++)
    {
        int temp = M;
        int u = v;
        for (int j=0; j < N; j++)
            if((!s[j])&&(dist[j]<temp))
            {
                temp = dist [j];
                u = j;
            }
        s[u] = 1;
        for(int j=0; j<N; j++)
        if((!s[j]) && c[u][j]<M)
        {
            int newdist = dist[u] +c[u][j];
            if(newdist<dist[j])
            {
				prev[j] = u;
                dist[j] = newdist;
            }
        } 
    } 
}
void PrintPrev(int prev[],int v,int vn)
{
    int tmp = vn;
    int i, j;
    int tmpprv[N];
    for(i=0; i < N; i++)
        tmpprv[i] = 0;
    tmpprv[0] = vn+1;
    for(i =0, j=1; j < N ;j++)
    {
        if(prev[tmp]!=-1 && tmp!=0)
        {
            tmpprv[i] = prev[tmp]+1;
            tmp = prev[tmp];
            i++;
        }
        else break;
    }
    for(i=N-1; i >= 0; i--)
    {
        if(tmpprv[i] != 0)
        { 
            printf("V%d", tmpprv[i]);
            if(i) 
                printf("-->");
        }
    }
    printf("-->V%d", vn+1);
}

int main()
{
    char *Vertex[N]={"v1", "v2", "v3", "v4", "v5"};
    int c[N][N]={
        {0, 10, M, 30, 100},
        {M, 0, 50, M, M},
        {M, M, 0, M, 10},
        {M, M, 20, 0, 60},
        {M, M, M, M, 0},
    };
    int dist[N]; 
    int prev[N]; 
    int i;
    Dijkstra(c, 0, dist, prev);
    for(i=0; i < N; i++)
    {
        printf("%s-->%s:%d\t", Vertex[0], Vertex[i], dist[i]);
        PrintPrev(prev, 0, i);
        printf("\n");
    }
    return 0;
}
