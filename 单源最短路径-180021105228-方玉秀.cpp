//#include "stdafx.h"
#include<stdio.h> 
//#include "MinHeap2.h"
#include <iostream>
#include <fstream> 
using namespace std;
 
ifstream fin("6d2.txt"); 
 
template<class Type>
class Graph
{
 friend int main();
    public:
  void ShortesPaths(int);
 private:
        int  n,     //图G的顶点数
    *prev;     //前驱顶点数组
      Type **c,       //图G的领接矩阵
    *dist;     //最短距离数组
}; 
 
template<class Type>
class MinHeapNode
{
   friend Graph<Type>;
   public:
    operator int ()const{return length;}
   private:
       int       i;    //顶点编号
       Type  length;   //当前路长
}; 
 
template<class Type>
void Graph<Type>::ShortesPaths(int v)//单源最短路径问题的优先队列式分支限界法
{ 
  MinHeap<MinHeapNode<Type>> H(1000);
 MinHeapNode<Type> E;
 
 //定义源为初始扩展节点
 E.i=v;
 E.length=0;
 dist[v]=0;
 
 while (true)//搜索问题的解空间
 {
  for (int j = 1; j <= n; j++)
   if ((c[E.i][j]!=0)&&(E.length+c[E.i][j]<dist[j])) {
 
     // 顶点i到顶点j可达，且满足控制约束
     dist[j]=E.length+c[E.i][j];
     prev[j]=E.i;
 
     // 加入活结点优先队列
     MinHeapNode<Type> N;
     N.i=j;
     N.length=dist[j];
     H.Insert(N);
   }
  try 
  {
   H.DeleteMin(E); // 取下一扩展结点
  }        
  catch (int) 
  {
   break;
  }  
  if (H.currentsize==0)// 优先队列空
  {
   break;
  }
 }
}
 
int main()
{  
 int n=11;
 int prev[12] = {0,0,0,0,0,0,0,0,0,0,0,0};  
 
 int dist[12]={1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};
 
 cout<<"单源图的邻接矩阵如下："<<endl;
 int **c = new int*[n+1];
 
 for(int i=1;i<=n;i++)
 {
  c[i]=new int[n+1];
  for(int j=1; j<=n; j++)
  {
   fin>>c[i][j];
   cout<<c[i][j]<<" ";
  }
  cout<<endl;
 }
 
 int v=1;
    Graph<int> G;
    G.n=n;
 
    G.c=c;
    G.dist=dist;
    G.prev=prev;
    G.ShortesPaths(v);
 
    cout<<"从S到T的最短路长是："<<dist[11]<<endl;
    for (int i = 2; i <= n; i++)
 {
  cout<<"prev("<<i<<")="<<prev[i]<<"   "<<endl;
 }
 
    for (int i = 2; i <= n; i++)
 {
  cout<<"从1到"<<i<<"的最短路长是："<<dist[i]<<endl;
 }
 
 for(int i=1;i<=n;i++)
 {
  delete []c[i];
 }
 
 delete []c;
 c=0; 
 return 0;
}
