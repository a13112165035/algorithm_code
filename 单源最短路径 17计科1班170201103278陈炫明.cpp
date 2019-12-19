#include <stdio.h>
#define M	65535 
#define N	5 
void Dijkstra(int Cost[][N], int v0, int Distance[], int prev[])
{
    int s[N];
    int mindis,dis;
    int i, j, u;
    for(i=0; i<N; i++)
    {
        Distance[i] = Cost[v0][i];
        s[i] = 0;
        if(Distance[i] == M)
			prev[i] = -1;
        else
			prev[i] = v0;
    }
    Distance[v0] = 0;
    s[v0] = 1;
    for(i=1; i < N; i++)
    {
        mindis = M;
        u = v0;
        for (j=0; j < N; j++) 
			if(s[j]==0 && Distance[j]<mindis)
			{
				mindis = Distance [j];
				u = j;
			} 
        s[u] = 1;
        for(j=0; j<N; j++) 
        if(s[j]==0 && Cost[u][j]<M)
        {    
            dis = Distance[u] +Cost[u][j];          
            if(Distance[j] > dis)
            {
                Distance[j] = dis;
                prev[j] = u;
            }
        } 
    } 
}
void PrintPrev(int prev[],int v0,int vn)
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
    char *Vertex[N]={"V1", "V2", "V3", "V4", "V5"};
    int Cost[N][N]={
		{0, 10, M, 30, 100},
        {M, 0, 50, M, M},
        {M, M, 0, M, 10},
        {M, M, 20, 0, 60},
        {M, M, M, M, 0},
    };
    int Distance[N]; 
    int prev[N];  
	int i;
    Dijkstra(Cost, 0, Distance, prev);
    for(i=0; i < N; i++)
    {
        printf("%s-->%s:%d\t", Vertex[0], Vertex[i], Distance[i]);
        PrintPrev(prev, 0, i);
        printf("\n");
    }
 
    return 0;
}
