#include <iostream>
#include<stdlib.h>
using namespace std;

#define MaxInt 65535    
#define MNum 6       

void Dijkstra(int n,int v,int dist[],int prev[],int c[][MNum]){
	 bool s[MaxInt];
	 for(int i=1;i<=n;i++){
	 	dist[i]=c[v][i];
	 	s[i]=false;
	 	if(dist[i]==MaxInt)
	 		prev[i]=0;
	 	else
	 		prev[i]=v;
	 }
	 dist[v]=0;
	 s[v]=true;
	 for(int i=1;i<n;i++)
	{
		int temp=MaxInt;
		int u=v;
		for(int j=1;j<=n;j++){
			if((!s[j])&&(dist[j]<temp)){
				u=j;
				temp=dist[j];
			}
			s[u]=true;
			for(int j=1;j<=n;j++){
				if((!s[j])&&(c[u][j]<MaxInt)){
					int newdist=dist[u]+c[u][j];
					if(newdist<dist[j]){
						dist[j]=newdist;
						prev[j]=u;
					}
				}
			}
		}
	}
}

void Printprev(int prev[],int begin,int temp)
{
	if(prev[temp]!=0){
		Printprev(prev,begin,prev[temp]);
		cout << prev[temp] << "-->";
	}
}

int main()
{
	cout <<"单源最短路径"<< endl;
    int n=5;
    int begin=2; 	//源头
    int dist[MNum];	 //记录最短路的长度
    int prev[MNum];	//记录前驱节点
   
    int c[MNum][MNum]={{MaxInt,15,MaxInt,MaxInt,60,MaxInt},
	                     {MaxInt,MaxInt,10,MaxInt,30,100},
						 {20,MaxInt,MaxInt,40,MaxInt,MaxInt},
						 {MaxInt,MaxInt,MaxInt,MaxInt,MaxInt,10},
						 {MaxInt,30,20,20,MaxInt,80}};
    
	

    Dijkstra(n,begin,dist,prev,c);
    
	cout << endl <<begin<<"到其余点的最短路径为：\n";
	for(int i=1;i<=n;i++) 
	{
	   if(i!=begin&&dist[i]<MaxInt) 
	   {
	   	 Printprev(prev,begin,i);
	     cout <<i;
	     
	     cout <<"最短路径长度为："<<dist[i]<<endl;
	   }
	   if(i!=begin&&dist[i]==MaxInt) 
	    {
	     cout <<begin<<"到"<<i<<"无可达路径"<<endl;
	   }	   
	}
	return 0;
}

