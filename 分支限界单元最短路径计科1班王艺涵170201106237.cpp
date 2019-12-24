#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
 
class MinNode
{
public :
	int id;//顶点编号
	int length;//当前路长
	friend bool operator<(MinNode A, MinNode B)
	{
		return  (A.length >  B.length);//不能带等于号
	}
};
class Graph
{
public:
	Graph()
	{
		cin >> n>>m;
		vector<int> ie1;
		edges.push_back(ie1);
		for (int i = 1; i <= n; i++)
		{
			vector<int> ie2(n + 1, 100000);
			edges.push_back(ie2);
		}
		for (int i = 1; i <= m; i++)
		{
			int in1, in2 ,w;
			cin >> in1 >> in2>>w;
			edges[in1][in2] = w;
		}
		prev.assign(n + 1, -1);
		dist.assign(n + 1, 100000);
 
		cin >> v >> u;
	}
	void ShortPath()
	{
		priority_queue<MinNode> Q;
		MinNode E = { v , 0 };
		dist[v] = 0;
		prev[v] = 0;//源点的前驱设为0
		while (1)
		{
			for (int i = 1; i <= n; i++)
			{
				if (edges[E.id][i] != 100000)//检查所有从顶点E.id可达的顶点i
				{
					int temp = E.length + edges[E.id][i];
					if (temp < dist[i])//如果比当前最短距离小,作为活结点加入优先级队列
					{
						MinNode active = { i , temp };
						prev[i] = E.id;
						dist[i] = temp;
						Q.push(active);
					}
				}
			}
			if (!Q.empty())
			{
				E = Q.top();
				Q.pop();
			}
			else
			{
				break;
			}
		}
	}
	
	void print()
	{
		int p = u;
		vector<int> path;
		while (prev[p] != 0)
		{
			path.push_back(p);
			p = prev[p];
		}
		path.push_back(v);
		reverse(path.begin(), path.end());
		cout << "dist array : " << endl;
		for (int i = 1; i < dist.size(); i++)
		{
			cout <<setw(4)<< dist[i] << " ";
		}
		cout << endl;
		cout << "prev array : " << endl;
		for (int i = 1; i < prev.size(); i++)
		{
			cout << setw(4) << prev[i] << " ";
		}
		cout << endl;
		cout << v << "-->" << u << "的最短路径 :" << endl;
		cout << v;
		for (int i = 1; i < path.size(); i++)
		{
			cout << "->" << path[i];
		}
		cout << endl;
	}
public:
	int n , m ;//顶点数,边数
	vector<int> prev;//路径上的前驱数组；
	vector<int> dist;//最短距离数组，记录从源到各顶点当前最短距离
	vector<vector<int> > edges;//邻接矩阵
	int v, u;
};
 
 
Graph G;
 
int main()
{
	G.ShortPath();
	G.print();
	
	return 0;
}


