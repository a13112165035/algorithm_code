#include <iostream>
#include <queue>
#include<stdlib.h>
using namespace std;
#define MAX 9999
#define N 60
int n,dist[N],a[N][N];
class HeapNode
{
public:
int i,length;
HeapNode() { }
HeapNode(int ii,int l)
{
i=ii;
length=l;
}
bool operator<(const HeapNode& node)const
{
return length<node.length;
}
};
void shorest(int v)
{
priority_queue<HeapNode>  heap;
HeapNode enode(v,0);
for(int i=1; i<=n; i++)  dist[i]=MAX;
dist[v]=0;
while(1)
{
for(int j=1; j<=n; j++)
if(a[enode.i][j]<MAX && enode.length+a[enode.i][j]<dist[j])//顶点I到J是可达的，并且满足控制约束
{
dist[j]=enode.length+a[enode.i][j];
HeapNode node(j,dist[j]);
heap.push(node);
}
if(heap.empty()) break;
else
{
enode=heap.top();
heap.pop();
}
}
}
int main ()
{
int v,i;
cout<<"个数：";
cin>>n;
cout<<"源点：";
cin>>v; 
for(int i=1; i<=n; i++)
for(int j=1; j<=n; j++)
{
if(i!=j){
if((a[j][i]==0)||(a[j][i]==MAX))
a[i][j]=rand()%100+1;
else a[i][j]=MAX;
if(a[i][j]>50) a[i][j]=MAX;
}   
}
cout<<"\n路径:"<<endl;
for( i=1;i<n+1;i++){
for(int j=1;j<n+1;j++)
cout<<a[i][j]<<"  ";
cout<<endl;
}
shorest(v);
cout<<endl;
for( i=2; i<n; i++) {
cout<<v<<"到"<<i<<"的最短路径为："<<dist[i]<<endl;
}
cout<<v<<"到"<<i<<"的最短路径为："<<dist[n]<<endl;
system("pause");
return 0;
}
