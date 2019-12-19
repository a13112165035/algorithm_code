#include <stdio.h>

#define size 200
#define maxint 1000000;

int dist[size][size];
int prev[size];
int s[size];

int a,b;

int Dijkstra(int n,int v){
	int i;
	for(i=1;i<=a;i++){
		s[i]=0;
		prev[i]=dist[n][i];
	}
	int j;
	for(i=1;i<a;++i){
		int temp=maxint;
		int u;
		for(j=1;j<=a;++j){
			if(!s[j] && temp>prev[j]){
				u=j;
				temp=prev[j];
			}
		}
		s[u]=1;
		for(j=1;j<=a;++j){
			if(!s[j] && (prev[j]>(prev[u]+dist[u][j]))){
				prev[j]=prev[u]+dist[u][j];
			}
		}
	}
	return prev[v];
} 

int main() {
	int i,j;
	printf("请输入a和b的值：");
	scanf("%d%d",&a,&b);
	for(i=1;i<=a;++i){
		for(j=1;j<=a;++j){
			dist[i][j] = maxint;
		}
	}
	int z,x,c;
	for(i=1;i<=b;++i){
		printf("请输入z，x,c的值：") ;
		scanf("%d%d%d",&z,&x,&c);
		dist[z][x]=dist[x][z]=c;
	}
	int t=maxint;
	for(i=1;i<=a;++i){
		for(j=1;j<=a;++j){
			if(dist[i][j]==t){
				dist[i][j]=dist[j][i]; 
			}
		}
	}
	int rul=Dijkstra(1,5);
	printf("结果为：");
	printf("%d",rul);
	return 0;
}
