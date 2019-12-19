#include <iostream>
using namespace std;
#define maxint 10000


void Djk(int n,int v,int *dist,int *prev,int (*c)[6])
{
	bool s[maxint];
	for(int i=1;i<=n;i++)
	{
		dist[i]=c[v][i];
		s[i]=false;
		if(dist[i]==maxint)
		  prev[i]=0;
		else
		  prev[i]=v;
	}
	dist[v]=0; 
	s[v]=true;
	
	for(int i=1;i<=n;i++)
	{
		int temp=maxint;
		int u=v;
		for(int j=1;j<=n;j++)
		if((!s[j])&&(dist[j]<temp))
		{
			u=j;
			temp=dist[j];
		}
		s[u]=true;
		for(int j=1;j<=n;j++)
		if((!s[j])&&(c[u][j]<maxint))
		{
			int newdist=dist[u]+c[u][j];
			if(newdist<dist[j])
			{
				dist[j]=newdist;
				prev[j]=u;
			}
		}
	}
 } 
 
 int main()
 {
 	
	int n=7;
	int v=1;
	int dist[8] = {0};
	int prev[8] = {0};
	int c[6][6];
	c[1][2]=10; c[1][4]=30; c[1][5]=60;
	c[2][3]=40;
	c[3][5]=10;
	c[4][3]=20; c[4][5]=50;
	c[5][4]=10;
	c[6][5]=30;
	c[7][6]=40;
	Djk(n, v, dist, prev, c);
	
	for(int i=2; i<=n; i++){
		cout<<"结点1到结点"<<i<<"的最短路径是:"<<dist[i]<<"\t"<<endl;
		 
	}
	
	return 0;

 }
