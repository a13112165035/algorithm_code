#include<stdio.h>
#define MAX 9
void input (int d[],int s[],int t[][MAX], int ti[][MAX], int n, int k);
void fenzhi (int d[],int s[],int t[][MAX], int ti[][MAX], int n, int k);
void output(int d[], int s[], int n);
int main(){
	int n,k;
	int d[MAX], s[MAX],t[MAX][MAX]={0},ti[MAX][MAX]={0};
	n=7;
	k=11;
	printf("input node num");
	scanf("%d",&n);
	printf("input nodes side num");
	scanf("%d",&k);
	input(d,s,t,ti,n,k);
	fenzhi(d,s,t,ti,n,k);
	output(d,s,n);
	return 0;
}
void input (int d[],int s[],int t[][MAX], int ti[][MAX], int n, int k)
{
	int i,j,m,z;
	printf("input 图 的 边");
	for(z-0;z<k;z++){
		scanf("%d %d %d",&i,&j,&m);
		t[i][j]=m;
		ti[i][j]=1;
	}
	for(i=0;i<n;i++){
		d[i]=99;
		s[i]=-1;
	}
}
void fenzhi (int d[],int s[],int t[][MAX], int ti[][MAX], int n, int k){
	int i,j,zi;
	d[0]=0;
	s[0]=-1;
	for(i=0;i<n;i++){
		printf("当前节点：%d,权重%d\n",i,d[i]);
		for(i=0;j<n;j++){
			if(ti[i][j]==1){
				if(d[j]>t[i][j]+d[i]){
					d[j]=t[i][j]+d[i];{
					s[j]=i;
					}
					if(j!=n)
					printf("入队节点%d 最优权重%d\n",j,d[j]);
				}
			}
			printf("\n");
		}
	}	
}
void output(int d[], int s[], int n){
	int i,j=0,zi[MAX];
	printf("源到各个节点最短\n");
	for(i=0;i<n;i++)
	printf("dist[%d]=%d\n",i,d[i]);
	printf("\n");
	printf("从源点到终点的最短路径为%d \n",d[n-1]);
	printf("路径为%d",n-1);
	zi[j]=s[n-1];
	printf("--->%d",zi[j]);
	while(zi[j]!=0){
		j++;
		zi[j]=s[zi[j-1]];
		printf("--->%d",zi[j]);
	} 
	printf("\n");
}
