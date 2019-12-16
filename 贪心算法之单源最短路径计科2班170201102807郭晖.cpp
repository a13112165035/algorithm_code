#include <stdlib.h>
#include <stdio.h>
int* Dijkstra(int n,int u,int*dist,int*p,int**C,int*f)
{
	//如果s[i]等于true,说明顶点i已加入集合S;否则,顶点i属于集合V-S;
	//集合S标志是否在其中
	int* s;
	int fi=1;
	s=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
	{
//初始化源点u到各个顶点之间的最短路径长度
		dist[i]=C[u][i];
		s[i]=0;
		
//满足条件说明顶点i与源点u不相邻，设置p[i]=-1
		if(dist[i]==1000)
		{
			p[i]=-1;
		}
		else
		{
//说明顶点i与源点u相邻，设置p[i]=u
			p[i]=u;
		}
	}
	
	dist[u]=0;
//初始时，集合s中只有一个元素:源点u
	s[u]=1;
	f[0]=u;
	for(int i=0;i<n;i++)
	{
		int temp=1000;
		int t=u;
		for(int j=0;j<n;j++)
		{
//不在集合S中
			if((!s[j])&&(dist[j]<temp))
			{
				t=j;
				f[fi]=j;
				fi++;
				temp=dist[j];
			}
		}
//如果找不到t，跳出循环
		
		if(t!=u){s[t]=1;}	
//否则将t加入集合s中
		else
		{
			break;
		}
//更新与t相邻的顶点到源点u的距离
		for(int j=0;j<n;j++)
		{
			if(!(s[j])&&(C[t][j]<1000))
			{
				if(dist[j]>(dist[t]+C[t][j]))
				{
					//更新距离
					dist[j]=dist[t]+C[t][j];
					//更新前驱
					p[j]=t;
				}
			}
		}
	}
	return s;
}
int main()
{
int **C;//带权边
int i;
int d;//顶点数
int j;
int n;//起始边
int m;//结束边
int q;//权值
int* s;
int flag=1;
int *f;
//初始化带权邻接矩阵
printf("请输入边和权\n");
printf("请输入有几个顶点\n");
scanf("%d",&d);
C=(int**)malloc(sizeof(int*)*d);//分配空间
for(i=0;i<d;i++)
{
	C[i]=(int*)malloc(sizeof(int)*d);
}
f=(int*)malloc(sizeof(int)*d);
//预置边权为一个大数
for(i=0;i<d;i++)
{
	for(j=0;j<d;j++)
	{
		C[i][j]=1000;
	}
}
for(i=0;i<(d*(d-1));i++){
printf("顶点都是按顺序来的如：顶点0，顶点1,……所以请按如上的边值输入起始边和结束边\n");
printf("请分别输入起始边和结束边\n");
printf("起始边:");
scanf("%d",&n);
printf("\n");
printf("结束边:");
scanf("%d",&m);
printf("\n");
printf("请输入权值:");
scanf("%d",&q);
//给邻接矩阵赋值
C[n][m]=q;
printf("输入完毕？未完请按1\n");
scanf("%d",&flag);
if(flag==0)
{
	break;
}
}
//构建前驱结点
int* p;
p=(int*)malloc(sizeof(int)*d);
//构建最短路径长度
int* dist;
dist=(int*)malloc(sizeof(int)*d);
for(int i=0;i<d;i++)
{
	dist[i]=1000;
	p[i]=-1;
}
//测试
s=Dijkstra(d,0,dist,p,C,f);
printf("输出p和dist:\n");
for(int i=0;i<d;i++)
{
	printf("%d,%d\n",p[i],dist[i]);
	/*for(int j=0;j<d;j++)
	{
		printf("%d",C[i][j]);
		printf("\n");
	}*/
}
//s=Dijkstra(d,0,dist,p,C);
//输出
for(i=0;i<d;i++)
{
printf("%d ",f[i]);
}
}
