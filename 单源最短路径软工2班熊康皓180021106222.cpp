
#include <stdio.h>
#include <stdlib.h>
 
typedef int Vertex;//图节点编号
#define x 10000 //表示无穷大
#define size 7//节点数目
 
int Graph[size][size] = 

 
{
	x, 2, x, 1, x, x, x,//1
	x, x, x, 3, 10, x, x,//2
	4, x, x, x, x, 5, x,//3
	x, x, 2, x, 2, 8, 4,//4
	x, x, x, x, x, x, 6,//5
	x, x, x, x, x, x, x,//6
	x, x, x, x, x, 1, x //7
};
int Graph_Dist[size] = { x,x,x,x,x,x,x };
int Graph_Path[size] = { -1,-1,-1,-1,-1,-1,-1 };
int Graph_Order[size] = { 0 };
 
void
Dijkstra(Vertex V0)
{
	Vertex V, W;
	int Order;
	Graph_Path[V0 - 1] = 0;
	Graph_Dist[V0 - 1] = 0;
	Graph_Order[V0 - 1] = 1;
	for (Order = 1; Order <= size; Order++)
	{
		for (V = 0; V < size; V++)
		{
			if (Graph_Order[V] == Order)
			{
				for (W = 0; W<size; W++)
				{
					if (Graph[V][W]!=x&&Graph_Dist[W] > Graph_Dist[V] + Graph[V][W])
					
					{
						Graph_Dist[W] = Graph_Dist[V] + Graph[V][W];
						Graph_Path[W] = V+1;
						Graph_Order[W] = Order + 1;
					}
				}
			}
 
		}
	}
}
 
void printarray(int a[]){
	for (int i = 0; i < size; i++)
		printf("%d ", a[i]);
}
 
void main()
{
	Dijkstra(1);
 
	printarray(Graph_Dist);
	
}

