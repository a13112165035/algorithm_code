#include<stdio.h>
#include<iostream>
using namespace std;

const int size=100;
const int inf=5000;
const int n=6;
int dist[]={0,0,5000,5000,5000};
int c[n][n]={{0,0,0,0,0,0},{0,0,2,3,5000,5000},{0,5000,0,1,2,5000},{0,5000,5000,0,9,2},{0,5000,5000,5000,0,2},{0,5000,5000,5000,5000,0}};

template<class Type>
class Graph{
	friend int main(void);
public:
	void ShortestPaths(int);
private:
	int n,        //图G的顶点数 
	*prev;    //前驱顶点数组 
	Type**c, //图G的领接矩阵  
	*dist;    //最短距离数组 
};
template<class Type>
class MinHeapNode {
	friend Graph<Type>;
public:
	operator int() const{ return length;}
private:
	int i;       //顶点编号 
	Type length; //当前路长 
};

template<class Type>
void Graph<Type>::ShortestPaths(int v){
	MinHeapNode<MinHeapNode<Type>> H(100);
	MinHeapNode<Type> E;
	E.i=v;
	E.length=0;
	dist[v]=0;
	while(true){
		for(int j=1;j<=n;j++){
			if((c[E.i][j]<inf)&&(E.length+c[E.i][j]<dist[j])){
				dist[j]=E.length+c[E.i][j];
				prev[j]=E.i;
				MinHeapNode<Type> N;
				N.i=j;
				N.length=dist[j];
				H.Insert(N);
			}
			try{ 
				H.DeleteMin(E);
			}
			catch(OutOfBounds){
				break;
			}
		}
	}
}


int main(){
	int n=11;
	int prev[12]={0,0,0,0,0,0,0,0,0,0,0,0};//初始化前驱顶点数组  
	int dist[12]={1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};//初始化最短距离数组
	cout<<"单源图的领接矩阵如下："<<endl;
	int **c=new int*[n+1];
	for(int i=1;i<=n;i++){//输入图的领接矩阵 
		c[i]=new int[n+1];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	int v=1; //源结点1
	Graph<int> G;
	G.n=n;
	G.c=c;
	G.dist=dist;
	G.prev=prev;

	G.ShortestPaths(v);//调用图的最短路径查找算法   
	cout<<"从S到T的最短路长是："<<dist[11]<<endl;//输出从源结点的最短路径 
	for(int i=2;i<=n;i++){//输出每个结点的前驱结点 
		cout<<"prev("<<i<<")="<<prev[i]<<" "<<endl;
	}
	for(int i=2;i<=n;i++){//输出从源结点到其他结点的最短路径长度 
		cout<<"从1到"<<i<<"的最短路长是："<<dist[i]<<endl;
	}
	for(int i=1;i<=n;i++){ //删除动态分配时的内存  
		delete[] c[i];
	}
	delete[] c;
	c=0;
	cout<<endl;
	return 0;
}
