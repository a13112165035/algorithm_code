#include <stdio.h>
#include <stdlib.h>
# define SIZE 7
#define ElementType int
int edge[SIZE+1][SIZE+1]={0};
ElementType queue[SIZE];
ElementType dist[SIZE+1];

ElementType path[SIZE+1]={-1};
int in=0;//入队指针
int out=0;//出队指针
void ShortestPath(ElementType v)
{
	queue[in++]=v;
	int p,i;
	while(in!=out)
	{
		p=queue[out++];
		for(i=1;i<=SIZE;i++)
		{
			if(edge[p][i]==1 && dist[i]==-1)
			{
				dist[i]=dist[p]+1;
				path[i]=p;
				queue[in++]=i;
			}
		}
	}
	
	
}

int main(int argc, char** argv) {
	int num_edge;
	int i;
	scanf("%d",&num_edge);
	int start,end;
	for(i=0;i<num_edge;i++)
	{
		scanf("%d %d",&start,&end);
		edge[start][end]=1;
	}
	for(i=1;i<=SIZE;i++)
	{
		dist[i]=-1;
		path[i]=-1;
	}
		
	dist[3]=0;
	ShortestPath(3); 
	for(i=1;i<=SIZE;i++)
	{
		int location=i;
		while(location!=-1)
		{
			printf("%d ",location);
			location=path[location];
		}
		printf("\n");
	}
	
	return 0;
}

