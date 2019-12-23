//单源最短路径分支限界法
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, v;
int dist[100];
int pre[100]; 
int c[100][100];
 
class Node
{
public:
	int i, length;
};
bool operator > (const Node& a, const Node& b)
{
	return a.length > b.length;
}


void ShortestPaths(int v)
{
	priority_queue<Node, vector<Node>, greater<Node>> pq; //最小堆，用优先队列
	Node E;
	E.i = v;
	E.length = 0;
	dist[v] = 0;
	pq.push(E);
	while (pq.size())
	{
		E = pq.top();
		pq.pop();
		for (int j = 1; j <= n; j++)
		{
			if ((c[E.i][j] < INF) && (E.length + c[E.i][j] < dist[j]))
			{
				dist[j]=E.length+c[E.i][j];
				pre[j] = E.i;
				Node N;
				N.i = j;
				N.length = dist[j];
				pq.push(N);
			}
		}
	}

}
void Traceback(int v, int i, int prev[])
{
	if (v == i)
	{
		cout << i;
		return;
	}
	Traceback(v, prev[i], prev);
	cout << "->" << i;
}

int main()
{
	cout << "请输入图的点数、边数(起点默认为1)" << endl;
	cin >> n >> m ;
	v = 1;  //默认起点为1
	memset(c, INF, sizeof(c));
	memset(dist, INF, sizeof(dist));

	for(int i=1;i<=m;i++)
	{
		int a, b, l;
		cout << "请输入点到点的距离（如点1到点3有单向边距离为7则输入1 3 7）" << endl;
		cin >> a >> b >> l;
		c[a][b] = l;
	}
	ShortestPaths(v);
	for (int i = 2; i <= n; i++)
	{
		cout << "起点1到点" << i << "的最短路径距离为:" << dist[i] << "，其路径为";
		Traceback(1, i, pre);
		cout << endl;
	}
	return 0;
}