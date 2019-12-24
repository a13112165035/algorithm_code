/* 单源点最短路劲
/* 优先队列式分支限界法                                                 */
/* author:yel_hb
/************************************************************************/

#include <iostream>
using namespace std;
#define MAX 9999				//定义无穷大

/*
**Graph类，用以存放有关图的所有信息
*/
class Graph 
{
public:
	//---------------------------
	//param int 初始节点编号
	//--------------------------
	void ShorestPaths(int);
	void ShowDist();
	Graph();
private:
	int n;					//图的节点个数
	int *prev;				//存放顶点的前驱节点
	int **c;				//存放图的邻接矩阵
	int *dist;				//存放源点到各个顶点的距离
};

/*
**节点
*/
class MinHeapNode
{
	friend Graph;
public:
	int getI() {return i;}
	void setI(int ii)
	{
		i = ii;
	}
	int getLength(){return length;}
	void setLength(int len)
	{
		length = len;
	}
private:
	int i;					//顶点编号
	int length;				//当前路长
};

/*
**最小堆
*/
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
	cout<<"请输入图的节点个数：";
	cin>>n;
	cout<<"请输入图的邻接矩阵：(无穷大请以9999代替)" << endl;
	c = new int*[n+1];
	dist = new int[n+1];
	prev = new int[n+1];
	//------------------------------
	//初始化邻接矩阵
	//------------------------------
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
	//----------------------------------
	//初始化数组
	//----------------------------------
	for (wi = 0; wi <= n; wi++)
	{
		dist[wi] = MAX;
		prev[wi] = 0;
	}
}

void Graph::ShowDist()
{
	cout << "从源点到该节点的最短路径:" << endl;
	int i = 0;
	int temp = 0;
	for (i = 1; i <= n; i++)
	{
		cout << "dist[" << i << "] = " << dist[i] << endl;
	}
	cout << "从源点到终点的最短路径长度为:" << dist[n] << endl;
	cout << "其路径为：";
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
	MinHeap H(n);        //最小堆
	MinHeapNode E;    //扩展节点
	E.i = v;
	E.length = 0;
	dist[v] = 0;
	//搜索问题的解空间树
	while (true)
	{
		int j = 0;
		for (j = 1; j <= n; j++)
		{
			cout<<"c["<<E.i<<"]["<<j<<"]="<<c[E.i][j]<<endl;
			if ((c[E.i][j] != MAX) && (c[E.i][j] != 0))
			{
				//节点控制关系
				if (E.length + c[E.i][j] < dist[j])
				{
					dist[j] = E.length + c[E.i][j];
					prev[j] = E.i;
					//加入活结点优先队列
					//若节点为叶子节点，则不加入活结点队列
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
		cout<<"上一个扩展节点"<<E.i<<" "<<E.length<<endl;
		H.DeleteMin(E);
		cout<<"下一个扩展节点"<<E.i<<" "<<E.length<<endl;
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

/*
**取下一个扩展结点，并删除此节点
**算法实现其实是用下一个节点的信息替代现有节点的数据
**首先在现有的节点中，找出length最短的节点
**然后将此节点的数据替换原有的数据
*/
void MinHeap::DeleteMin(MinHeapNode &E)
{
	int i = 0;
	int j = 0;
	j = E.getI();			//用来删除原来的扩展节点
	node[j].setI(0);			//置零
	node[j].setLength(0);		//置零
	int temp = MAX;
	//-------------------------------------
	//选择可扩展节点中length域最小的可扩展节点
	//将所选择的扩展节点的数值替换原有的扩展节
	//点的值，最后在可扩展节点队列中删除原扩展
	//节点，删除方式为：所有域置零
	//-------------------------------------
	for (i = 1; i <= length; i++)
	{
		if ((node[i].getLength() < temp) && (node[i].getLength() != 0))
		{
			E.setI(i);
			E.setLength(node[i].getLength());
			temp = node[i].getLength();				//temp中始终为最小值
		}
	}
}

/*
**加入最小堆
**此处添加按节点编号添加，即对应的节点编号添加时
**对应队列中相应的编号，即节点5则添加到队列中5号
**位置
*/
void MinHeap::Insert(MinHeapNode N)
{
	node[N.getI()].setI(N.getI());
	node[N.getI()].setLength(N.getLength());
}

/*
**判断最小堆是否为空
*/
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
