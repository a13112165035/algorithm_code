template<class Type>
class Graph{
	friend void main(void);
	public:
		void ShortextPaths(int);
	private:
		int n,
		*prev,
		**c,
		*dist;
};
template<class Type> 
class MinHeapNide{
	friend  Graph<Type>;
	public:
		operator int () const {return length;}
	private:
		int i;
		int length;
};
template<class Type>
void Graph<Type>::ShortextPaths(int v){
	MinHeap<MinHeapNide<Type>> H(1000);
    MinHeapNode<Type> E;
	E.i=v;
	E.length=0;
	dist[v]=0;
	while(true){
		for(int j=1;j<=n;j++){
			if((c[E.i][j]<inf)&&E.length+c[E.i][j]<dist[j]){
				dist[j]=E.length+c[E.i][j];
				prev[j]=E.i;
				MinHeapNode<Type> N;
				N.i=j;
				N.length=dist[j];
				H.Insert(N);
			}
			try{H.deleteMin(E); 
			}catch(OutOfBounds){break;
			}
		}
	}
	printf("%d",E.length);
}
int main(){
	int v=5;
	ShortextPaths(v);
}
