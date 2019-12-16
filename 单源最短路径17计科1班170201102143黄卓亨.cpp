#include<stdio.h>
#include<string.h>
#define NUM 100
#define maxint 10000
void Dijkstra(int n,int v,int dist[],int prev[],int c[][NUM]){
	bool s[NUM];
	int i,j; 
	
	for(i=1;i<=n;i++){
		dist[i]=c[v][i];
		s[i]=false;
		if(dist[i]>maxint)prev[i]=0;
		else prev[i]=v;
	}
	
	dist[v]=0;
	s[v]=true;
	
	for(i=1;i<n;i++){
		int temp=maxint;
		int u=v;
		for(j=2;j<=n;j++){
			if(!(s[j]) && (dist[j]<temp)){
				u=j;
				temp=dist[j];
			}
			s[u]=true;
			for(j=2;j<=n;j++){
				if(!(s[j]) && c[u][j]<maxint){
					int newdist=dist[u]+c[u][j];
					if(newdist<dist[j]){
						dist[j]=newdist;
						prev[j]=u;
					}
				}
			}
		}
	}
}
int main(){
	int m,n;
	while(scanf("%d%d",&n,&m)!=EOF && (m||n)){
		int i,j;
		int dist[NUM]={0};
		int prev[NUM]={0};
		int c[NUM][NUM];
		memset(c,1,sizeof(c));
		int v,w,edge;
		for(i=0;i<m;i++){
			scanf("%d%d%d",&v,&w,&edge);
			c[v][w]=edge;
		}
		Dijkstra(n,1,dist,prev,c);
		for(i=0;i<n;i++){
			printf("%d\n",&prev[i]);			
		}
	}
}
