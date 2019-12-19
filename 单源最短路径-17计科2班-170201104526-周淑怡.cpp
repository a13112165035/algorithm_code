#include <iostream>
#define MAX 1000
#define LEN 100
int k=0, b[LEN]; 
using namespace std; 
void Dijkstra(int n, int v, int dist[], int prev[], int c[][LEN])
{
	bool s[LEN];		
	for (int i = 1; i <= n; i++)
	{
		dist[i] = c[v][i];
		s[i] = false;	
		if (dist[i] == MAX)
			prev[i] = 0;	
		else
			prev[i] = v;
	}
	dist[v] = 0;
	s[v] = true;
	for (int i = 1; i < n; i++)
	{
		int temp = MAX;
		int u = v;	
		for (int j = 1; j <= n; j++)
			if ((!s[j]) && (dist[j] < temp))  
			{
				u = j;							   	 
				temp = dist[j];	
			}
		s[u] = true;
		k++;
		b[k] = u;
		cout << "----------------------------------------------------------" << endl;
		cout << "迭代次数：" << i << endl;
		cout << "顶点为：";
		cout << v << "\t";
		for (int i = 1; i <= k; i++)
			cout << b[i] << "\t";
		cout << endl;

		for (int j = 1; j <= n; j++)
			if ((!s[j]) && c[u][j] < MAX)
			{
				int newdist = dist[u] + c[u][j];
				if (newdist < dist[j])
				{
					dist[j] = newdist;		
					prev[j] = u;			
				}
			}
		cout << "单源路径分别为：" << endl;
		for (int i = 2; i <= n; i++)
			if (dist[i] != MAX)
				cout << dist[i] << "     ";
		cout << endl;
	 }
	cout << "----------------------------------------------------------" << endl;

	int p[LEN];
	for (int i = 2; i <= n; i++)
	{
		cout << "dist[" << i << "]=" << dist[i] << "              ";
		cout << "路径为：" << v << "\t";

		int m = prev[i];
		int k=0;
		while (m != v)
		{
			k++;
			p[k] = m;
			m = prev[m];
		}
		for (int x = k; x >= 1; x--)
			cout << p[x] << "\t";
		cout << i;
		cout << endl;
	}
}

int main()
{
	int i, j,k, m,n, v=1;
	int dist[LEN], prev[LEN], c[LEN][LEN];
	cout << "请输入顶点个数:" << endl;
	cin >> n;
	cout << "请输入边的个数:" << endl;
	cin >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			if (i == j)
				c[i][j] = 0;
			else
				c[i][j] = MAX;
		}
	cout << "请输入每条边的权_格式为： i j 权" << endl;
	for (k = 1; k <= m; k++)
	{
		cin >> i;
		cin >> j;
		cin >> c[i][j];
	}
	Dijkstra(n, v, dist, prev, c);
	cout << "----------------------------------------------------------" << endl;
	system("pause");
	return 0;
}

