#include <iostream>
#include <queue>
#include <stdlib.h>
using namespace std;
#define max 9999
#define N 60
int n,dist[N],G[N][N];
class HeapNode{
	public:
		int i,length;
		HeapNode(){
		}
		HeapNode(int a,int b)
		{
			i=a;
			length=b;
		}
		bool operator<(const HeapNode& node)const
		{
			return length<node.length;
		}
};

void shorest(int v)
{
	priority_queue<HeapNode> heap;
	HeapNode E(v,0);
	for(int i=1;i<=n;i++) dist[i]=max;
	dist[v]=0;
	while(1)
	{
		for(int j=1;j<=n;j++)
		{
			if(G[E.i][j]<max && E.length+G[E.i][j]<dist[j])
			{
				dist[j]=E.length+G[E.i][j];
				HeapNode node(j,dist[j]);
				heap.push(node);
			}
		}
		if(heap.empty()) break;
		else
		{
			E=heap.top();
			heap.pop();
		}
	}
}

int main()
{
	int v,i,o;
	cout<<"顶点个数：";
	cin>>n;
	cout<<"源点：";
	cin>>v;
	cout<<"边数：";
	cin>>o; 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			G[i][j]=max;
		}
	for( int i=0;i<o;i++)
	{
		int a,b,c;
		cout<<"请输入两个顶点和其对应的边的权值："<<endl;
		cin>>a>>b>>c;
		G[a][b]=G[b][a]=c;  
	}
	cout<<"\n路径："<<endl;
	for(i=1;i<n+1;i++)
	{
		for(int j=1;j<n+1;j++)
			cout<<G[i][j]<<"   ";
		cout<<endl;
	}
	shorest(v);
	cout<<endl;
	for(i=2;i<n;i++){
		cout<<v<<"到"<<i<<"的最短路径为："<<dist[i]<<endl;
	}
	cout<<v<<"到"<<i<<"的最短路径为："<<dist[n]<<endl;
	return 0;
}
