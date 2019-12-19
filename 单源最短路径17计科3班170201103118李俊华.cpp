#define maxint 10000
#include<stdlib.h>
#include<stdio.h>
#include<time.h> 
int c[100][100]={0};

void Dijkstra(int n,int v,int dist[],int prev[])
{
    bool s[maxint];
    for(int i=1; i<=n; i++)
    {
        dist[i] = c[v][i];
        s[i] = false;
        if (dist[i]==maxint) prev[i] = 0;
        else prev[i] = v;
    }
    
    dist[v] = 0;
    s[v] = true;
    for(int i=1; i<n; i++)
    {
        int mintmp = maxint;
        int u = v;
        for(int j=1; j<=n; j++){
            if(!(s[j]) && (dist[j]<mintmp)){
                u = j;
                mintmp = dist[j];
            }
        }
        s[u] = true; 
        for(int j=1; j<=n; j++){
            if(!(s[j]) && c[u][j]<maxint){
                int newdist = dist[u]+c[u][j];
                if (newdist<dist[j]){
                    dist[j] = newdist;
                    prev[j] = u;
                }
            }
        }
    }
}

int main(){
	int n,v;
    printf("请输入顶点数：");
	scanf("%d",&n);
	srand(time(0));
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			if(i!=j){
				if((c[j][i]==0)||(c[j][i]==1000))
					c[i][j]=rand()%100+1;
				else c[i][j]=1000;
				if(c[i][j]>50)
					c[i][j]=1000;
			}
		}
	}
	printf("请输入源点：");
	scanf("%d",&v);
	int dist[n+1],prev[n+1];
	printf("\n路径：\n");
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++)
			printf("%5d",c[i][j]);
		printf("\n");
	}
	Dijkstra(n,v,dist,prev);
	for(int i=1;i<n+1;i++){
		printf("\n%d到%d的最短路径为：%d",v,i,dist[i]);
	}
}

