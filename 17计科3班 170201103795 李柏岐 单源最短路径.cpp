#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#include<time.h>
#define maxint 1000
int c[200][2000]={0};

void Dijkstra(int n,int v,int dist[],int prev[]){
	bool s[maxint];
	for(int i=1;i<=n;i++){
		dist[i]=c[v][i];
		s[i]=false;
		if(dist[i]==maxint) prev[i]=0;
		else prev[i]=v;
	}
	dist[v]=0;
	s[v]=true;
	for(int i=1;i<n;i++){
		int temp=maxint;
		int u=v;
		for(int j=1;j<=n;j++){
			if((!s[j])&&(dist[j]<temp)){
				u=j;
				temp=dist[j];
			}
		}
		s[u]=true;
		for(int j=1;j<=n;j++){
			int newdist=dist[u]+c[u][j];
			if(newdist<dist[j]){
				dist[j]=newdist;
				prev[j]=u;
			}
		}
	}
}

int main(){
	int n,v;
	cout<<"请输入顶点数："<<endl;
	cin>>n;
	//cout<<"路径："<<endl;
	srand(time(0));
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			//cin>>c[i][j];手动输入 
			if(i!=j){
				if((c[j][i]==0)||(c[j][i]==1000))
				c[i][j]=rand()%100+1;
				else c[i][j]=1000;
				if(c[i][j]>50) c[i][j]=1000;
			}
		}
	}
	cout<<"请输入源点："<<endl;
	cin>>v;
	int dist[n+1],prev[n+1];
	cout<<"路径："<<endl;
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++)
		cin>>c[i][j];
		cout<<endl;
	}
	Dijkstra(n,v,dist,prev);
	for(int i=1;i<n+1;i++){
		cout<<endl<<v<<"到"<<i<<"的最短路径为："<<dist[i];
	}

}
