#include <iostream>      
#include <string>   
using namespace std;   

const int N = 5;  
const int M = 1000;

template<class Type>  
void Dijkstra(int n,int v,Type dist[],int prev[],Type c[][N+1]);  
void Traceback(int v,int i,int prev[]);//输出最短路径 v源点，i终点  
  
int main()  
{  
	int v = 1;//源点为1  
	int dist[N+1],prev[N+1],c[N+1][N+1];
	
	c[1][1]=M;
	c[1][2]=10;
	c[1][3]=M;
	c[1][4]=30;
	c[1][5]=100;
	c[2][1]=M;
	c[2][2]=M;
	c[2][3]=50;
	c[2][4]=M;
	c[2][5]=M;
	c[3][1]=M;
	c[3][2]=M;
	c[3][3]=M;
	c[3][4]=M;
	c[3][5]=10;
	c[4][1]=M;
	c[4][2]=M;
	c[4][3]=20;
	c[4][4]=M;
	c[4][5]=60;
	for(int i=1;i<6;i++)
		c[5][i]=M;

	cout<<"有向图权的矩阵为："<<endl;  
	for(int i=1; i<=N; i++)  
	{  
		for(int j=1; j<=N; j++)  
		{     
			cout<<c[i][j]<<" ";    
		}  
		cout<<endl;  
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

		if(dist[i] == M)  
		{  
			prev[i] = 0;//记录从源到顶点i的最短路径i的前一个顶点  
		}  
		else  
		{  
			prev[i] = v;  
		}  
	}  

	dist[v] = 0;  
	s[v] = true;  

	for(int i=1; i<n; i++)  
	{  
		int temp = M;  
		int u = v;//上一顶点  

	//取出V-S中具有最短特殊路径长度的顶点u  
		for(int j=1; j<=n; j++)  
		{  
			if((!s[j]) && (dist[j]<temp))  
			{  
				u = j;  
				temp = dist[j];  
			}  
		}  
		s[u] = true;  
		
		//根据作出的贪心选择更新Dist值  
		for(int j=1; j<=n; j++)  
		{  
			if((!s[j]) && (c[u][j]<M))  
			{  
				Type newdist = dist[u] + c[u][j];  
				if(newdist < dist[j])  
				{  
					dist[j] = newdist;  
					prev[j] = u;  
				}  
			}  
		}  
	}
}  

//输出最短路径 v源点，i终点  
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
