#include <iostream>
#include <cstdlib>
#include <cstdlib>
//#include <cstring>
#include <queue>
using std::cout;
using std::endl;
using std::cin;
using std::priority_queue;

static const int inf=0xFFFF;
const int n=4;
int prev[n]={},dist[n]={},v=0, //v起点
	c[n][n]={
		{inf,100,10,inf},
		{inf,inf,inf,inf},
		{inf,inf,inf,10},
		{inf,10,inf,inf}
	};
template<typename T> struct MinHeapNode{
	int i; // 顶点编号
	T length; // 当前边长
	//operator int () const { return length; }
	bool operator < (const MinHeapNode<T> &x) const {
		return length>x.length;
	}
};
template<typename T> struct Graph{
	//friend int main();

	//int n,*prev; // 图G顶点数 前驱顶点数组
	//T **c,*dist; // 图G邻接矩阵 最短距离数组
public:
	void ShortestPaths(int v){
		priority_queue<MinHeapNode<T>> H;
		MinHeapNode<T> E;
		E.i=v,E.length=0,dist[v]=0;
		while(true){
			for(int j=1;j<=n;++j){
				if(c[E.i][j]<inf && (E.length+c[E.i][j]<dist[j])){
					dist[j]=E.length+c[E.i][j];
					prev[j]=E.i;
					MinHeapNode<T> N;
					N.i=j,N.length=dist[j];
					H.push(N);
				}
				if(!H.empty()){
					E=H.top();
					H.pop();
				}else return;
			}
		}
	}
};

int main(){
	Graph<int> G;
	/*const int n=4;
	int prev[n]={},dist[n]={},v=0, //v起点
		c[n][n]={
			{inf,100,10,inf},
			{inf,inf,inf,inf},
			{inf,inf,inf,10},
			{inf,10,inf,inf}
		};
	G.n=n,G.dist=dist,G.prev=prev,G.c=c;*/
	G.ShortestPaths(v);
	return 0;
}
