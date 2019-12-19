#include <iostream>
#include<iomanip>
#include<cstdlib>
#include<stdio.h>
#define maxint 5000 
using namespace std; 



template<class Type>
void Dijkstra(int n,int v,Type dist[],int prev[],Type **c)    
{
	
    bool s[maxint];
	for(int i=1;i<=n;i++)
	{
		dist[i]=c[v][i]; 
		s[i]=false;
		if(dist[i]==maxint) prev[i]=0;     
		else prev[i]=v;                  
	}
	dist[v]=0;s[v]=true;     
	for(int i=1;i<n;i++)
	{
		int temp=maxint;
		int u=v;                    
		for(int j=1;j<=n;j++)
			if((!s[j])&&(dist[j]<temp))    
			{
				u=j;                     
				temp=dist[j];
			}
			s[u]=true;                    
			for(int j=1;j<=n;j++)
			{
				if((!s[j])&&(c[u][j]<maxint))
				{
					Type newdist=dist[u]+c[u][j];
					if(newdist<dist[j])    
					{
						dist[j]=newdist;   
						prev[j]=u;         
					}
				}
			}

 	}	
}

void ShowPath(int n,int v,int u,int *dist,int *prev)
{
   int j = 0;
   int w = u;
   int count = 0;
   int *way ;
   way=(int *)malloc(sizeof(int)*(n+1));
//回溯路径
while (w != v)
{
count++;
way[count] = prev[w];
w = prev[w];
}
//输出路径
printf("the best path is:\n");
for (j = count; j >= 1; j--)
{
printf("%d -> ",way[j]);
}
printf("%d\n",u);
}


int main()
{
   int i,j,t;
   int n,v,u;
   int **cost;//代价矩阵
   int *dist;//最短路径代价
   int *prev;//前一跳节点空间
   printf("please input the node number: ");
   scanf("%d",&n);
   printf("please input the cost status:\n");
   cost=(int **)malloc(sizeof(int)*(n+1));
   for (i = 1; i <= n; i++)
   {
   cost[i]=(int *)malloc(sizeof(int)*(n+1));
   }
//输入代价矩阵
  for (j = 1; j <= n; j++)
  {
   for (t = 1; t <= n; t++)
   {
    scanf("%d",&cost[j][t]);
   }
  }
   dist = (int *)malloc(sizeof(int)*n);
   prev = (int *)malloc(sizeof(int)*n);
   printf("please input the source node: ");
   scanf("%d",&v);
   
   
  Dijkstra(n, v, dist, prev, cost);
  for(i = 1; i <= n ; i++)
  {
   if(i!=v)
   {
    printf("the distance cost from node %d to node %d is %d\n",v,i,dist[i]);
    printf("the pre-node of node %d is node %d \n",i,prev[i]);
    ShowPath(n,v,i, dist, prev);
   }
  }
   system("pause");
   return 0;
}
