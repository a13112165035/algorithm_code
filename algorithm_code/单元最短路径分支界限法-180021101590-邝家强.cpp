#include<stdio.h>
#include <queue>
#include <iostream>
template<class Type>
class Graph{
    friend	void main(void);
	public:
	    void ShortestPaths(int);
	public:
	    int n,
		*prev;
		Type **c,
		*dist; 
}; 
template<class Type>
class MinHeapNode{
	friend Graph<Type>;
	public:
		 operator int()const{return length;} 
	public:
	    int i;
		Type length; 
};
bool operator< (MinHeapNode x,MinHeapNode y){
	reture (x.length<y.length);
}
template<class Type>
void Graph<Type>::ShortestPaths(int v){
    priority_queue <MinHeapNode<int>> H;
	MinHeapNode<Type> E;
	int inf=10000;
	E.i=v;
	E.length=0;
	dist[v]=0;
	while(true){
		for(int j=1;j<=n;j++){
			if((c[E.i][j]<inf)&&(E.length+c[E.i][j]<dist[j])){
				dist[j]=E.length+c[E.length][j];
				prev[j]=E.i;
				MinHeapNode<Type> N;
				N.i=j;
				N.length=dist[j];
				H.Insert(N);
				try{E=H.Top();
				H.pop();
				}catch(OutOfBounds){
					break;
				}
			}
		}
	}
}
int main(void){
	Graph<int> g;
	int n=6;
	int **a=new int*[n+1];
	for(int i=1;i<=n;i++)
	    a[i]=new int[n+1];
	a[1][2]=2;
	a[1][3]=3;
	a[1][4]=4;
	a[2][5]=2;
	a[3][5]=12;
	a[3][6]=5;
	a[4][6]=6;
	a[5][6]=5; 
	g.c=a;
	g.n=n;
	g.dist=new int[n+1];
	g.prev=new int[n+1];
	g.ShortestPaths(4);
	delete []a; 
	delete []g.c;
	delete []g.dist,g.prev;
} 
