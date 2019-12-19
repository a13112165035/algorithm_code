#include <iostream> 
#include <fstream>  
#include <string> 
using namespace std; 
 
const int N = 5;//五个点 
const int maxint = 999;
 
template<class Type>
void Dijkstra(int n,int v,Type dist[],int prev[],Type c[][N+1]);
void Traceback(int v,int i,int prev[]);//输出最短路径 v源点，i终点
 
int main()
{
	int v = 1;//源点为1
	int dist[N+1],prev[N+1],c[N+1][N+1];
 
	cout<<"有向图权的矩阵为：(不可达可输入999)"<<endl;
	for(int i=1; i<=N; i++)
	{
		cout<<"请输入"<<i<<"号点到各个点的长度"<<endl; 
		for(int j=1; j<=N; j++)
		{
			cin>>c[i][j];                  
		}	
	}
 
	Dijkstra(N,v,dist,prev,c);
 
	for(int i=2; i<=N; i++)
	{
		cout<<"源点1到点"<<i<<"的最短路径长度为:"<<dist[i]<<"，其路径为";
		Traceback(1,i,prev);
		cout<<endl;
	}
 
	return 0;
}
 
 
template<class Type>
void Dijkstra(int n,int v,Type dist[],int prev[],Type c[][N+1])
{
	bool s[N+1];
	for(int i=1; i<=n; i++)
	{
		dist[i] = c[v][i];//dist[i]表示当前从源到顶点i的最短特殊路径长度
		s[i] = false;
 
		if(dist[i] == maxint)
		{
			prev[i] = 0;//无前驱 
		}
		else
		{
			prev[i] = v;//前驱 
		}
	}
 
	dist[v] = 0;
	s[v] = true;
 
	for(int i=1; i<n; i++)//每次转化一个为红点 
	{
		int temp = maxint;
		int u = v;//上一顶点
 
		//非红点中找最短的特殊路径 
		for(int j=1; j<=n; j++)
		{
			if((!s[j]) && (dist[j]<temp))
			{
				u = j;
				temp = dist[j];
			}
		}
		s[u] = true;
 
		for(int j=1; j<=n; j++)
		{
			if((!s[j]) && (c[u][j]<maxint))
			{
				Type newdist = dist[u] + c[u][j];
				if(newdist < dist[j])
				{
					dist[j] = newdist;//修改特殊路径 
					prev[j] = u;
				}
			}
		}
	}
}
 
//递归输出最短路径 v源点，i终点
void Traceback(int v,int i,int prev[])
{
	if(v == i)
	{
		cout<<i;
		return;
	}
	Traceback(v,prev[i],prev);
	cout<<"->"<<i;
} 
