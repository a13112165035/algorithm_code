#include<iostream>
using namespace std;
const int size = 100;
const int inf = 5000;

const int n = 5;
int prev[n];
int dist[] = {0,0,5000,5000,5000};
int c[][n]={{0,0,0,0,0},{0,0,2,3,5000},{0,5000,0,1,2},{0,5000,5000,0,9},{0,5000,5000,5000,0}
};

 
class MinHeapNode
{
public:
	int i;
	int length;
};

class CirQueue
{
private:
	int front,rear;
	MinHeapNode data[size];
public:
	CirQueue()
	{
		front = rear = 0;
	}
 
  void queryIn(MinHeapNode e)
  {
	  if((rear +1)%size != front)
	  {
		  rear = (rear+1)%size;
		  data[rear] = e;
	  }
  }

  MinHeapNode queryOut()
  {
	  if(rear != front)
	  {
		  front = (front+1)%size; 
		  return data[front];
	  }
  }
  
  MinHeapNode getQuery()
  {
	  if(rear != front)
	  {
		  return data[(front+1)%size];
	  }
  }
  
  bool empty()
  {
	  return front == rear;
  }
  
  bool full()
  {
	  return (rear +1)%size == front;
  }
 };


class Graph
{
public:

 void shortestPath(int v)
 {
  CirQueue qq;

  MinHeapNode e;
  e.i = v;
  e.length = 0;
  dist[v] = 0;
  qq.queryIn(e);
  while(true)
  {
	  for(int j = 1;j<n;j++)
	  {
		  if(j>=n)
		  {
			  break;
		  }
		  MinHeapNode m = qq.getQuery();
		  if((c[m.i][j]<inf)&&(m.length + c[m.i][j] < dist[j]))
		  {
			  dist[j] = m.length + c[m.i][j];
			  prev[j] = m.i;
			  MinHeapNode mi;
			  mi.i = j;
			  mi.length  = dist[j];
			  if(qq.full())
			  {
				  break;
			  }
			  qq.queryIn(mi);
		  }
	  }
   
	  if(qq.empty())
	  {
		  break;
	  }
	  qq.queryOut();
  }
 }
};

int main()
{
  Graph g;
  g.shortestPath(1);
  cout<<"最短路径长为 "<<dist[n-1]<<endl;
  cout<<"中间路径为： ";
  for(int i =3;i<n;i++)
  {
	  cout<<prev[i]<<" ";
  }
return 0;
}

