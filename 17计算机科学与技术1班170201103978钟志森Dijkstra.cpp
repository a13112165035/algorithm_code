#include<iostream>
using namespace std;

const int maxint = 65535;
template<class Type>
void Dijkstra(int n, int v, Type dist[], int prev[], Type** c)
{
	bool s[n];
	for (int i = 1; i <= n; i++)
	{
		dist[i] = c[v][i];
		s[i] = false;
		if (dist[i] == maxint)
		{
			prev[i] = 0;
		}
		else {
			prev[i] = v;
		}
	}

	dist[v] = 0;
	s[v] = true;
	for (int i = 1; i < n;i++)
	{
		int temp = maxint;
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
					if ((!s[j] )&& (c[u][j] < maxint))
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


int main()
{
	int peakNum, sideNum,begin;
	double weight;
	int peak1;
	int peak2;
	cout << "请输入顶点的个数"; cin >> peakNum;
	cout << "请输入边的个数"; cin >> sideNum;
	cout << "请输入每条边的起点、终点以及权重" << endl;
	double** c = new double *[peakNum+1];
	double dist[peakNum+1];
	int prev[peakNum+1];
	for (int i = 0; i <= peakNum; i++)
	{
		c[i] = new double[peakNum+1];
	}
	for (int i = 0; i <=peakNum; i++)
	{
		for (int j = 0; j <=peakNum; j++)
		{
			c[i][j] = maxint;
		}
	}



	for (int i = 0; i < sideNum; i++)
	{
		cout << "请输入第" << i +1<< "条边的起点、终点、权重（用逗号或者回车键隔开）"; cin >> peak1>>peak2>>weight;
		c[peak1][peak2] = weight;
	}
	
	cout<<"请输入开始的顶点";cin>>begin;
	
		Dijkstra(peakNum, begin, dist, prev, c);
		for(int i=1;i<=peakNum;i++)
		{
			cout<<"顶点"<<begin<<"到顶点"<<i<<"的最小距离为"<<dist[i]<<endl;
		}
			for(int i=1;i<=peakNum;i++)
		{
			cout<<"prev["<<i<<"]="<<prev[i]<<endl;
		}
		
	return 0;

}


