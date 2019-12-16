#include <iostream>
#include <stdlib.h>
using namespace std;
#define maxint 32767
#define point 50

template<class Type>
void Dijkstra(int n,int v,Type dist[],int prev[],Type c[][point]){
	bool s[maxint];
	for(int i=1;i<=n;i++){
		dist[i]=c[v][i];
		s[i]=false;
		if(dist[i]==maxint) prev[i]=0;
		else prev[i]=v;
	}
	dist[v]=0;s[v]=true;
	for(int i=1;i<n;i++){
		int temp=maxint;
		int u=v;
		for(int j=1;j<=n;j++){
			if((!s[j])&&(dist[j]<temp)) {u=j;temp=dist[j];}
			}	
		
		s[u]=true;
		for(int j=1;j<=n;j++){
			if((!s[j])&&(c[u][j]<maxint)){
				Type newdist=dist[u]+c[u][j];
				if(newdist<dist[j]){dist[j]=newdist;prev[j]=u;}
			}
		}
	}
}
void DisplayPath(int prev[],int begin,int temp )
{	//显示最短路
	if(prev[temp]!=0){
		DisplayPath(prev,begin,prev[temp]);
		cout << prev[temp] << "-->";
	}
}
int main(){
	int n=5;
	int v=1;
	int dist[point];
	int prev[point];
	int c[point][point]={{maxint,maxint,maxint,maxint,maxint,maxint},
	                     {maxint,maxint,10,maxint,30,100},
						 {maxint,maxint,maxint,50,maxint,maxint},
						 {maxint,maxint,maxint,maxint,maxint,10},
						 {maxint,maxint,maxint,20,maxint,60},
						 {maxint,maxint,maxint,maxint,maxint,maxint}};
	Dijkstra(n,v,dist,prev,c);
	cout << endl <<v<<"到其余点的最短路径为：\n";
	for(int i=1;i<=n;i++) 
	{
	   if(i!=v&&dist[i]<maxint) 
	   {
	   	 DisplayPath(prev,v,i);
	     cout <<i;
	     
	     cout <<"  路径长度为："<<dist[i]<<endl;
	   }
	   if(i!=v&&dist[i]==maxint) 
	    {
	     cout <<v<<"到"<<i<<"没有路径可以到达"<<endl;
	   }	   
	}
	return 0;
} 
