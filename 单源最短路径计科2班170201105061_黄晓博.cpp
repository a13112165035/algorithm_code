
#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 100
#define INFINITY  65535
//#define MaxSize 10
typedef int Vertex;
typedef int WeightType;
typedef char DataType;
//图的数据结构 
typedef struct GNode * PtrToGNode;
struct GNode{
	int Nv;
	int Ne;
	WeightType G[MaxVertexNum][MaxVertexNum];
	DataType Data[MaxVertexNum]; 
};
typedef PtrToGNode MGraph;
 
typedef struct ENode * PtrToENode;
struct ENode{
	Vertex V1,V2;
	WeightType Weight;
};
typedef PtrToENode Edge;
//队列的数据结构 
typedef int ElementType;
typedef struct QNode * PtrToQNode;
struct QNode{
	int * Data;
	int Front,Rear;
	int MaxSize;
}; 
typedef PtrToQNode Queue;
 
bool Visited[]={false};
 
//队列的算法
//创建队列
Queue CreateQueue(int MaxSize){
	Queue Q = (Queue)malloc (sizeof(struct QNode));
	Q->Data=(ElementType *)malloc(MaxSize * sizeof(ElementType));
	Q->Front=Q->Rear=0;
	Q->MaxSize=MaxSize;
	return Q; 
} 
 
//入队
bool IsFull(Queue Q){
	return ((Q->Rear+1) % Q->MaxSize == Q->Front);
} 
 
bool AddQ(Queue Q,int X){
	if(IsFull(Q)){
		printf("队列满\n");
	}else{
		Q->Rear=(Q->Rear+1) % Q->MaxSize;
		Q->Data[Q->Rear] = X;
		return true;
	}
}
 
bool IsEmpty(Queue Q){
	return (Q->Front==Q->Rear);
} 
 
#define ERROR -1
int DeleteQ(Queue Q){
	if(IsEmpty(Q)){
		printf("队列空\n");
		return ERROR;
	}else{
		Q->Front=(Q->Front+1) % Q->MaxSize;
		return Q->Data[Q->Front];
	}
}
 
MGraph CreateGraph(int VertexNum){
	Vertex V,W;
	MGraph Graph;
	
	Graph=(MGraph)malloc(sizeof(struct GNode));
	Graph->Nv=VertexNum;
	Graph->Ne=0;
	for(V=0;V<Graph->Nv;V++)
		for(W=0;W<Graph->Nv;W++)
			Graph->G[V][W]=INFINITY;
	return Graph;
}
 
void InsertEdge(MGraph Graph,Edge E){
	Graph->G[E->V1][E->V2]=E->Weight;
	Graph->G[E->V2][E->V1]=E->Weight;
}
 
MGraph BuildGraph(){
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv,i;
	
	printf("请输入顶点个数: "); 
	scanf("%d",&Nv);
	Graph=CreateGraph(Nv);
	
	printf("请输入边的个数: "); 
	scanf("%d",&(Graph->Ne));
	if(Graph->Ne!=0){
		E=(Edge)malloc(sizeof(struct ENode));
		for(i=0;i<Graph->Ne;i++){
			//输入带权重的边 
			printf("读入边，格式为起点 终点 权重。请输入: "); 
			scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
			InsertEdge(Graph,E);
		}
	}
	
//	for(V=0;V<Graph->Nv;V++)
//		scanf("%c",&(Graph->Data[V]));
		
	return Graph;
}
Vertex FindMinDist(MGraph Graph,int dist[],int collected[]){
	Vertex MinV,V;
	int MinDist=INFINITY;
	
	for(V=0;V<Graph->Nv;V++) {
		if(collected[V]==false&&dist[V]<MinDist){
			MinDist=dist[V];
			MinV=V;
		}
	}
	if(MinDist<INFINITY)
		return MinV;
	else return ERROR;
}
 
bool Dijkstra(MGraph Graph,int dist[],int path[],Vertex S){
	int collected[MaxVertexNum];
	Vertex V,W;
	
	for(V=0;V<Graph->Nv;V++){
		dist[V]=Graph->G[S][V];
		path[V]=-1;
		collected[V]=false;
	}
	dist[S]=0;
	collected[S]=true;
	
	while(1){
		V=FindMinDist(Graph,dist,collected);
		if(V==ERROR)
			break; 
		collected[V]=true;
		for(W=0;W<Graph->Nv;W++)
			if(collected[W]==false&&Graph->G[V][W]<INFINITY){
				if(Graph->G[V][W]<0)
					return false;
				if(dist[V]+Graph->G[V][W]<dist[W]){
					dist[W]=dist[V]+Graph->G[V][W];
//					printf("dist[%d] = %d ",W,dist[W]);
					path[W]=V;
				}
			
			}
//			printf("起点%d到结点%d的最短距离为： \n",S,dist[W]);
	}
	for(W=S+1;W<Graph->Nv;W++)
		printf("起点%d到结点%d的最短距离为:%d \n",S,W,dist[W]);
	return true;
	
}
 
int main(){
	MGraph graph= BuildGraph();
	int dist[30]={0},path[30]={0};
	int z,i;
	printf("请输入起点: ");
	scanf("%d",&z); 
	Dijkstra(graph,dist,path,z);
	return 0;
	}
