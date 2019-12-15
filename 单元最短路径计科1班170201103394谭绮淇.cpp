/*
	170201103394
	TanQiqi
	Dijkstra
*/

#include <iostream>
using namespace std;

const int N = 5; 
const int Maxint = 65535; 

template<class Type>
void Dijkstra(int n,int v,Type dist[],int prev[],Type c[][N])
{
    bool s[Maxint];
    for(int i=0;i<=n;i++)
    {
        dist[i]=c[v][i]; 
        s[i]=false; 
        if(dist[i]==Maxint) 
        	prev[i]=-1; 
        else
        	prev[i]=v; 
    }
    dist[v]=0;
    s[v]=true;
    for(int i=0;i<n;i++)
    {
        int temp = Maxint;
        int u =v;
        for(int j=1;j<=n;j++) 
        {
            if((!s[j])&&(dist[j]<temp)) 
            {
            	u=j;
                temp=dist[j];
            }
        
	        s[u]=true;
	        for(int j=1;j<=n;j++) 
	        {
	        
	            if((!s[j])&&(c[u][j]<Maxint)) {
	            	Type newdist=dist[u]+c[u][j];
	            	if(newdist<dist[j]){
	            		dist[j]=newdist;
	            		prev[j]=u;
	            	}
	            }
	        }
        }
    }
}

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
 
int main()
{
 
    int c[N][N]={ 0,8,32,Maxint,Maxint,
                  12,0,16,15,Maxint,
                  Maxint ,29 ,0,Maxint,13,
                  Maxint,21,Maxint,0,7,
                  Maxint,Maxint,27,19,0 };
	int dist[N];
	int prev[N];
	int v = 1;//Ô´µãÎª1
	Dijkstra(N,v,dist,prev,c);   
	                              
	for(int i=2; i<=N; i++)
	{	cout<<"From top 1 to top"<<i<<",the shortest path is£º";
		Traceback(1,i,prev);
		cout<<" "<<",and the length is "<<dist[i]<<endl;
	}
	
	return 0;
} 
