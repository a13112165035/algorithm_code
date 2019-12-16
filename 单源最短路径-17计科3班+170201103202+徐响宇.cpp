#include<stdio.h>
#define maxint 100

int k=0,b[maxint];
//----------------------数据声明------------------------
//n表示边数
//V表示源点
//dist[]表示当前从源到顶点i的最短特殊路径长度
//prve[]表示记录从源点到顶点i的最短路径上的i的前一个顶点
//c[][]表示边（i，j）的权
//-------------------------------------------------------

void Dijkstra(int n,int v,int dist[],int prev[],int c[][maxint]){
	bool s[maxint];            //判断是否已存入该点到S集合
	for(int i=1;i<=n;i++){
		dist[i]=c[v][i];
		s[i]=0;            //初始都未用过该点
		if(dist[i]==maxint)
			prev[i]=0;	       //表示v到i前一顶点不存在
		else
			prev[i]=v;
	}
	dist[v]=0;
	s[v]=1;
	for(int i=1;i<n;i++){
		int temp=maxint;
		int u=v;
		for(int j=1;j<=n;j++)	
			if((!s[j])&&(dist[j]<temp)){         //j不在s中，v到j距离不在为无穷大
				u=j;                             //u保存当前邻接点中距离最小的点的
				temp=dist[j];
			}
		s[u]=1;
		for(int j=1;j<=n;j++){
			if((!s[j])&&(c[u][j]<maxint)){       
				int newdist=dist[u]+c[u][j];
				if(newdist<dist[j]){
					dist[j]=newdist;
					prev[j]=u;
				}
			}
		}
		
	}
	
} 



int main(void){
	int i,j,k,m,n,v=1;
	int dist[maxint],prev[maxint],c[maxint][maxint];
	printf("请输入顶点个数：\n");
	scanf("%d",&n);
	printf("请输入边的个数：\n");
	scanf("%d",&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j){
				c[i][j]=0;
			}
			else c[i][j]=maxint;
		}
	}
	printf("请输入每条边的权(格式为：i  j  权)：\n");
	for(k=1;k<=m;k++){
		scanf("%d",&i);
		scanf("%d",&j);
		scanf("%d",&c[i][j]);
	}
	Dijkstra(n,v,dist,prev,c);
	printf("---------------------------------\n");
	for(int i=1;i<=n;i++){
		printf("V1-->V%d:%d\t",i,dist[i]);
		printf("\n");
	} 

	return 0;
	
}
