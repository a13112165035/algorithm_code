#include<iostream>
#include<queue>

using namespace std;

#define inf 10000


class Graph 
{
public:
	
	void ShortestPaths(int k);
	Graph(int n, int *prev, int (*c)[6], int *dist)
	{
		this->n = n;
		this->prev = prev;
		this->c = c;
		this->dist = dist;	
	}
private:
	int n,  
		*prev;  
	int (*c)[6], 
		*dist;  
};



class MinHeapNode 
{
	friend Graph;
public:
	operator int() const 
	{ 
		return length; 
	}
private:
	int i;  
	int length;  
};


void Graph::ShortestPaths(int v)
{
	priority_queue<MinHeapNode > H; 
	MinHeapNode E;//<int>
	E.i = v;
	E.length = 0;
	dist[v] = 0;
	
	while(true)
	{
		for(int j=1; j<=n; j++)
		{
			if((c[E.i][j]<inf) && (E.length+c[E.i][j]<dist[j])) 
			{
				dist[j] = E.length+c[E.i][j];
				prev[j] = E.i;
				MinHeapNode N;
				N.i = j;
				N.length = dist[j];
				H.push(N);
			}
		}
		
		if(H.empty())
		{
		break;
	    }
		else
	    {
			E = H.top();
			H.pop();
		}
	}
} 

void createGraph(int (*g)[6], int *dist, int *prev)
{	
//初始化 
	for(int i=1;i<6;i++){
		for(int j=1;j<5;j++){
			g[i][j]=inf;			
		}		
	}
	
	for(int i=0;i<6;i++){
		dist[i]=inf;
	}
	
	for(int i=0;i<6;i++){
		prev[i]=i;
	}
	
	g[1][2]=2; g[1][3]=3; g[1][4]=4;
	g[2][3]=4; g[2][5]=2;
	g[3][5]=9; g[3][6]=13;
	g[4][6]=4;
	
}

int main(){
	int n=5;
	int prev[6];
	int g[7][6];
	int dist[6];
	
	createGraph(g, dist, prev);
	Graph* G = new Graph(n, prev, g, dist);
	
	G->ShortestPaths(1);		
	
	for(int i=1; i<7; i++)
	{
		cout<<"结点1到结点"<<i<<"的最短路径:"<<dist[i]<<endl;
	
	}
}
