 #include <stdio.h>
#include <stdlib.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define ElementType int
#define MAXSIZE 10
#define MAX 11111
typedef struct GraphNode
{
	ElementType data;
	struct GraphNode* next;
}Graph;
int node_num;
int path[MAXSIZE];
int edge[MAXSIZE][MAXSIZE]={0};
int dist[MAXSIZE];
int collected[MAXSIZE];
void Dijkstra(Graph* G){
	dist[0]=0;
	while(1){
		int min=11112;
		int v=-1;
		for(int i=0;i<node_num;i++){
			if(dist[i]<min && collected[i]==0){
				if(dist[i]<min && collected[i]==0){
				min=dist[i];
				v=i;	
			}
		}
		if(v==-1)	return;
		collected[v]=1;
		Graph* t=&G[v];
		while(t->next){
			int w=t->next->data;
			if(collected[w]==0 && dist[v]+edge[v][w]<dist[w]){
				dist[w]=dist[v]+edge[v][w];
				path[w]=v;
			}
			t=t->next;
		}
	}
}
int main(int argc, char* argv){
	 
	Graph* G=(Graph*)malloc(MAXSIZE*sizeof(GraphNode));
	int edge_num;
	scanf("%d %d",&node_num,&edge_num);
	for(int i=0;i<node_num;i++){
		dist[i]=MAX;
		path[i]=-1;
		collected[i]=0;
		G[i].data=i;
		G[i].next=NULL;
	}
	for(int i=0;i<edge_num;i++){		
		int start,end,value;
		scanf("%d %d %d",&start,&end,&value);
		Graph* newG=(Graph*)malloc(sizeof(GraphNode));
		newG->data=end;
		newG->next=G[start].next;
		G[start].next=newG;
		edge[start][end]=value;	
	}
	Dijkstra(G);
	printf("**************\n");
	//找出第0个结点到其他结点的路径
	for(int i=1;i<node_num;i++){
		int location=i;
		while(location!=-1){
			printf("%d ",location);
			location=path[location];
		}
		printf("\n");
	} 
	return 0;
} 

