#include <iostream> 
using namespace std;

const int N = 5;
const int INF = 0x3f3f3f;

template<class Type>
void Dijkstra(int n, int v, Type dist[], int prev[], Type c[][N + 1]);

void Traceback(int v, int i, int prev[]);

template<class Type>
void Dijkstra(int n, int v, Type dist[], int prev[], Type c[][N + 1])
{
	bool s[N + 1];
	for (int i = 1; i <= n; i++)
	{
		dist[i] = c[v][i];
		s[i] = false;

		if (dist[i] == INF)
		{
			prev[i] = 0;
		}
		else
		{
			prev[i] = v;
		}
	}

	dist[v] = 0;
	s[v] = true;

	for (int i = 1; i < n; i++)
	{
		int temp = INF;
		int u = v;

		for (int j = 1; j <= n; j++)
		{
			if ((!s[j]) && (dist[j] < temp))
			{
				u = j;
				temp = dist[j];
			}
		}
		s[u] = true;

		for (int j = 1; j <= n; j++)
		{
			if ((!s[j]) && (c[u][j] < INF))
			{
				Type newdist = dist[u] + c[u][j];
				if (newdist < dist[j])
				{
					dist[j] = newdist; 
					prev[j] = u;
				}
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
	int v = 1;
	int dist[N + 1], prev[N + 1], c[N + 1][N + 1];
	int tmp;
	cout << "共有5个点，请输入点到点的距离(不可达则可输入-1)" << endl;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << "" << i << "号点到" << j << "号点的距离为：" << endl;

			cin >> tmp;
			if (tmp == -1)
			{
				c[i][j] = INF;
			}
			else
			{
				c[i][j] = tmp;
			}
		}
	}

	Dijkstra(N, v, dist, prev, c);

	for (int i = 2; i <= N; i++)
	{
		cout << "1号点到" << i << "号点" << "的最短路径距离为:" << dist[i] << "，其路径为";
		Traceback(1, i, prev);
		cout << endl;
	}

	return 0;
}
