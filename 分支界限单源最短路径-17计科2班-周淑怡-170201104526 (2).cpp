#include<iostream>
using namespace std; 
#include "MinHeap.h" 
#define  INF 10000 
template<class Type>class Graph{
	private: 	
		int n,			//the number of Graph's node		
		*prev;		//array of previous node	
		Type **c,			// adjcent matrix of Graph G		
		*dist;				//array of shortest distance 
	public: 	
		Graph(const int m); 	void setAdjMartix(int **cAdj);       //interface  	
		void ShortestPath(const int v);		
		~Graph(); 	
		friend int main();   //可以通过Graph类的实例访问其私有和保护成员和方法
};  
template<class Type>class MinHeapNode{	
	private:		
	int i;			//the number code of node		
	Type length;		//current length of road 	
	public:		
	int operator<=(MinHeapNode a)		
	{			
		return (length <= a.length);		
	} 		
	int operator < (MinHeapNode a)		
	{			
		return (length<a.length);		
	} 		
	int operator >(MinHeapNode a)		
	{			
		return (length > a.length);		
	} 		
	int operator >=(MinHeapNode a)		
	{			
		return (length >= a.length);
			
			}  	
	friend class Graph<Type>;
}; 
template<class Type>Graph<Type>::Graph(const int m){	
		n = m;           //the number of Graph's node	
		dist = new int[m + 1];				//array of shortest distance	
		prev = new int[m + 1];    //array of previous node
} 
template<class Type>Graph<Type>::~Graph(){ 	
		delete[] dist;	
		delete[] prev;	
		for (int i = 0; i <= n; i++)	
		{		
			delete[] c[i];     //delete everything  the Array's pointer has pointed	
		}	
		delete[] c;   //delete the pointer arrays
		} 
template<class Type>void Graph<Type>::setAdjMartix(int **cAdj)
{	
		c = cAdj;
}  
template<class Type>void Graph<Type>::ShortestPath(const int v){ 	//定义堆的最小容量为1000	
		MinHeap<MinHeapNode<Type> > H(1000);   //主要问题是“>> ”不要写在一起 	//定义源为扩展节点	
		MinHeapNode<Type> E; 	
		for (int k = 1; k <= n; k++){		
			dist[k] = INF;		
			prev[k] = -1;	
		} 	//初始化源点	
		E.i = v;	
		E.length = 0;	
		dist[v] = 0; 	//搜索问题的解空间	
		while (true)	{		
			for (int j = 1; j <= n; j++)			
				if ((c[E.i][j]<INF) && (E.length + c[E.i][j]<dist[j]))			
				{			//顶点i到顶点j可达，且满足控制约束			
					dist[j] = E.length + c[E.i][j];			
					prev[j] = E.i;			//加入活结点优先队列			
					MinHeapNode<Type> N;			
					N.i = j;			
					N.length = dist[j];			
					H.Insert(N);			
				}		
			try		{			
				E = H.RemoveMin();		
			}		
			catch (int)		
			{			
				break; 		
			}	
		}
	}  
		int** CreatGraph_AdjMatrix(int &n){ 	
		int i, j, k, e;	
		int weight;	
		int **c;	
		printf("please input graph's vexnum and arcnum:\n");	
		cin >> n >> e;
			 	
		c = new int *[n + 1];	
		for (i = 0; i <= n; i++)		
			c[i] = new int[n+1];
				 	
		for (i = 1; i <= n; i++)		
			for (j = 1; j <= n; j++)			
				c[i][j] = INF;	
		for (k = 1; k <= e; k++)	
		{		
			printf("please input NO.%d edge's start,end and weight:\n", k);		
			cin >> i >> j >> weight;		
			c[i][j] = weight;	
		}	
		return c;     
		}  
int main(){	
		int **c=NULL, n;
		 	
		c=CreatGraph_AdjMatrix(n); 	
		Graph<int> G(n);	
		G.setAdjMartix(c); 	
		G.ShortestPath(1); 	
		
		cout << "previous\t" << "i\t"<<"current" << endl;	
		for (int i = 1; i <= G.n; i++)		
			cout << G.prev[i] << "\t" << i <<"\t"<<G.dist[i]<< endl;	
		cout << endl;
		}

