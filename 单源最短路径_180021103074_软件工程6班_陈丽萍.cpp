#include <iostream>
typedef int Type;
#define max 1000 
//#define H 1000
#define inf 10000  
//template<class Type>
//
template<class Type>
class Graph{

	friend void main(void);
		public:
			void ShortestPaths(int);
		private:
			int n,*prev;//图G的顶点数 、前驱顶点组数 
			int **c,*dist;//图G的邻接矩阵、最短距离组 
}; 
template<class Type>//class   MinHeap;
class MinHeapNode{
	public:
		operator int() const{return length;}
	private:
		int i;//顶点编号 
		int length;//当前路长 
};
template<class Type>
void Graph<Type>::ShortestPaths(int v){//单源最短路径的优先队列分支界限 
	  MinHeapNode<Type> H(1000);
	MinHeapNode<Type> E;//初始扩展结点 
	E.i=v;//初始化 
	E.length=0;
	while(true){//搜索问题的解空间 
		for(int j=1;j<=n;j++){
			if((c[E.i][j]<inf)&&(E.length+c[E.i][j]<dist[j])){
				dist[j]=E.length+c[E.i][j];
				prev[j]=E.i;
				MinHeapNode<Type> N;// 加入活结点优先队列 
				N.i=j;
				N.length=dist[j];
				H.Insert(N);//放入队列 
			}
		
				H.DeleteMin(E);//取堆顶 
		}
	}
}
int main(){
	int n=5;
	int c[6][6];
	int dist[6];
	int prev[6]; 
	c[n][n]={{0,2,3,4,max,max},
	{max,0,3,max,2,max},//输入邻接矩阵 
	{max,max,0,max,9,2},
	{max,max,max,0,max,2},
	{max,max,max,max,0,1},
	{max,max,max,max,max,0}};
	ShortestPaths(1);//调用    
	return 0;
}
