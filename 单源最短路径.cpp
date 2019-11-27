#include<stdio.h>
void Dijkstra(int n,int v,int dist[],int prev[],int **c){
	int maxint=10000;
	bool s[maxint];
	for(int i=1;i<=n;i++){
		dist[i]=c[v][i];
		s[i]=false;
		if(dist[i]==maxint)
		    prev[i]=0;
		else
		    prev[i]=v;
	}
    for(int i=1;i<6;i++)
	printf("%d\t",dist[i]);
	printf("\n");
    dist[v]=0;
    s[v]=true;
    for(int i=1;i<n;i++){
    	int temp=maxint;
    	int u=v;
    	for(int j=1;j<=n;j++)
    		if((!s[j])&&(dist[j]<temp)){
    			u=j;
    			temp=dist[j];
			}
			s[u]=true;
			for(int j=1;j<=n;j++){
				if((!s[j])&&(c[u][j]<maxint)){
					int newdist=dist[u]+c[u][j];
					if(newdist<dist[j]){
						dist[j]=newdist;
						prev[j]=u;
					}
				}
			
		}
    for(int i=1;i<6;i++)
	printf("%d\t",dist[i]);
	printf("\n");	
	}
} 
int main(){
	int n=5,v=1;
	int dist[n+1];
	int prev[n+1];
	int **c=new int *[n+1];
	for(int i=0;i<6;i++)
	     c[i]=new int[6]();
	for(int i=0;i<6;i++)
	for(int j=0;j<6;j++)
	c[i][j]=10000;
	for(int i=0;i<6;i++)
	c[i][i]=0;
	c[1][2]=10;
	c[2][3]=50;
	c[4][3]=20;
	c[4][5]=60;
	c[1][5]=100;
	c[1][4]=30;
	c[3][5]=10; 
	Dijkstra(n,v,dist,prev,c);
	return 0;
}
