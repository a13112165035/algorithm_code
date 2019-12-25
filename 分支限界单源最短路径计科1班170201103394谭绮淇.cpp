/*
	170201103394
	TanQiqi
	Graph 
*/
#include <iostream>
using namespace std;
#define MAX 9999				
class Graph{
public:
	void ShorestPaths(int);
	void ShowDist();
	Graph();
private:
	int n;					
	int *prev;				
	int **c;				
	int *dist;				
};

class MinHeapNode
{
	friend Graph;
public:
	int getI() {return i;}
	void setI(int j)
	{
		i = j;
	}
	int getLength(){return length;}
	
	void setLength(int len)
	{
		length = len;
	}
private:
	int i;					
	int length;				
};

class MinHeap
{
	friend Graph;
public:
	MinHeap();
	MinHeap(int);
	void DeleteMin(MinHeapNode &);
	void Insert(MinHeapNode);
	bool OutOfBounds();
private:
	int length;
	MinHeapNode *node;
};

Graph::Graph()
{
	int wi = 0; 
	int yi = 0;
	cout<<"input node number:";
	cin>>n;
	cout<<"input adjacent matrix:" << endl;
	c = new int*[n+1];
	dist = new int[n+1];
	prev = new int[n+1];
	for (wi = 0; wi <= n; wi++)
	{
		c[wi] = new int[n+1];	
		if (wi == 0)
		{
			for (yi = 0; yi <= n; yi++)
			{
				c[wi][yi] = 0;
			}
		}
		else
		{
			for (yi = 0; yi <= n; yi++)
			{
				if (yi == 0)
				{
					c[wi][yi] = 0;
				}
				else
				{
					cin >> c[wi][yi];
				}
			}
		}
	}
	for (wi = 0; wi <= n; wi++)
	{
		dist[wi] = MAX;
		prev[wi] = 0;
	}
}

void Graph::ShowDist()
{
	cout << "Shortest path from source to node:" << endl;
	int i = 0;
	int temp = 0;
	for (i = 1; i <= n; i++)
	{
		cout << "dist[" << i << "] = " << dist[i] << endl;
	}
	cout << "Shoretest length from source to node:" << dist[n] << endl;
	cout << "its path is£º";
	temp = n;
	while(temp != 0)
	{
		if (prev[temp] == 0)
		{
			cout << temp;
		}
		else
		{
			cout << temp << "->";
		}
		temp = prev[temp];
	}
	cout << endl;
}

void Graph::ShorestPaths(int v)
{
	MinHeap H(n);        
	MinHeapNode E;   
	E.i = v;
	E.length = 0;
	dist[v] = 0;
	while (true)
	{
		int j = 0;
		for (j = 1; j <= n; j++)
		{
			cout<<"c["<<E.i<<"]["<<j<<"]="<<c[E.i][j]<<endl;
			if ((c[E.i][j] != MAX) && (c[E.i][j] != 0))
			{				
				if (E.length + c[E.i][j] < dist[j])
				{
					dist[j] = E.length + c[E.i][j];
					prev[j] = E.i;

					if (j != n)
					{
						MinHeapNode N;
						N.i = j;
						N.length = dist[j];
						H.Insert(N);
					}	
				} 
				else
				{
					H.DeleteMin(E);
				}
				
			}
		}
		if (H.OutOfBounds())
		{
			break;
		}
	}
}

MinHeap::MinHeap()
{
	length = 10;
	node = new MinHeapNode[length+1];
	for (int i = 0; i <= length; i++)
	{
		node[i].setI(0);
		node[i].setLength(0);
	}
}

MinHeap::MinHeap(int n)
{
	length = n;
	node = new MinHeapNode[length+1];
	for (int i = 0; i <= length; i++)
	{
		node[i].setI(0);
		node[i].setLength(0);
	}
}
void MinHeap::DeleteMin(MinHeapNode &E)
{
	int i = 0;
	int j = 0;
	j = E.getI();			
	node[j].setI(0);			
	node[j].setLength(0);		
	int temp = MAX;
	for (i = 1; i <= length; i++)
	{
		if ((node[i].getLength() < temp) && (node[i].getLength() != 0))
		{
			E.setI(i);
			E.setLength(node[i].getLength());
			temp = node[i].getLength();				
		}
	}
}
void MinHeap::Insert(MinHeapNode N)
{
	node[N.getI()].setI(N.getI());
	node[N.getI()].setLength(N.getLength());
}
bool MinHeap::OutOfBounds()
{
	int i = 0;
	bool flag = true;
	for (i = 1; i <= length; i++)
	{
		if (node[i].getI() != 0)
		{
			flag = false;
		}
	}
	return flag;
}
int main()
{
	Graph graph;
	graph.ShorestPaths(1);
	graph.ShowDist();
	return 0;
}
