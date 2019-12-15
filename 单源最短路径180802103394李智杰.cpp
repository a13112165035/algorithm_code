#include<queue>
#include<stdio.h>
using namespace std;
 
template<class Type>
class Graph{
	friend void main(void);
	public:
	void ShortestPaths(int);
	private:
	int n,*prev;Type**c,*dist; 
}; 
template<class Type>
class MinHeapNode{
	friend Graph<Type>;
	public:
		operator int () const {return length;}
		private:
			int i;
			Type length;
}; 

template<class Type>
void Graph<Type>::ShortestPaths(int v){
	priorty_queue<MinHeapNode<int> H(1000);
	MinHeapNode<Type> E;
	E.i=v;
	E.length =0;
	dist[v]=0;
	while(true){
		for(int j=1;j<=n;j++){
			if(((c[E.i][j]<inf))&&(E.length+c[E.i][j]<dist[j])){
				dist[j]=E.length+c[E.i][j];
				prev[j]=E.i;
				MinHeapNode<Type> N;
				N.i=j;
				N.length=dist[j];
				H.Insert(N);
			}
		try{
		E=H.top();
		H.pop()}
		catch(OutOfBounds){break;}
		};
			}
			}
		}
	}
} 

int main(){
	Grapa<int> G;
	G.c=g;
	int y[5];
	G.dist=y;
	G.ShortestPaths(4);
}
