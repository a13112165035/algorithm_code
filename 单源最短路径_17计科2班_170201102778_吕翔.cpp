//4.5 单源最短路径
#include<iostream>

using namespace std;

#define maxint 10000

template<class Type>

/**
* 单源最短路径
*
*@param n 结点个数 
*@param v 源点编号 
*@param dist[i] 源结点v到结点i的最短路径长度 
*@param prev[i] 到达结点i最短路径时，上一个结点编号 
*@param c[i][j] 存放有向图中i到j的边的权 
*@return 
*/ 
void Dijkstra(int n, int v, Type *dist, int *prev, Type (*c)[6])
{
	bool s[maxint]; //用于记录红点集 
	
	/*
	 初始化 
	*/ 
	for(int i=1; i<=n; i++)
	{
		dist[i] = c[v][i];
		s[i] = false;
		
		if(dist[i] == maxint)
			prev[i] = 0;
		else
			prev[i] = v;
	}
	
	dist[v] = 0;
	s[v] = true;
	
	/*
	 core 
	*/ 
	for(int i=1; i<n; i++)
	{
		int temp = maxint;
		int u = v;
		
		for(int j=1; j<=n; j++)
			if((!s[j]) && (dist[j]<temp)) //选出不在红点集 且 路径最短的结点 
			{
				u = j;
				temp = dist[j];
			}
		
		s[u] = true;
		
		for(int j=1; j<=n; j++) //更新到所有未加入红点集节点的最短距离 
		{
			if((!s[j]) && (c[u][j] < maxint))
			{
				Type newdist = dist[u] + c[u][j];
			
				if(newdist < dist[j])
				{
					dist[j] = newdist;
					prev[j] = u;
				}
			}
		}
	}
} 

int main()
{
	int n=5;
	int v=1;
	int dist[6] = {0};
	int prev[6] = {0};
	int c[6][6];
	c[1][2]=10; c[1][4]=30; c[1][5]=100;
	c[2][3]=50;
	c[3][5]=10;
	c[4][3]=20; c[4][5]=60;
	
	Dijkstra(n, v, dist, prev, c);
	
	for(int i=2; i<=n; i++){
		cout<<"结点1到结点"<<i<<"的最短路径:"<<dist[i]<<"\t";
		cout<<"前一个结点是"<<prev[i]<<endl; 
	}
	
	return 0;
}
