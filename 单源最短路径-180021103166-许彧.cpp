#include <iostream> 
using namespace std; 
 
const int N = 5;
const int maxint = 1000;

template<class Type>
void Dijkstra(int n,int v,Type dist[],int prev[],Type c[][N+1]);
void Traceback(int v,int i,int prev[]);
 
int main()
{
	int v = 1;
	int dist[N+1],prev[N+1],c[N+1][N+1];
	cout<<"insert Directed Matrix:"<<endl;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin>>c[i][j];     
		}
	}
 
	Dijkstra(N,v,dist,prev,c);
 
	for(int i=2; i<=N; i++){
		cout<<"point 1 to "<<i<<" the short length:"<<dist[i]<<" the road:";
		Traceback(1,i,prev);
		cout<<endl;
	}
	return 0;
}

template<class Type>
void Dijkstra(int n,int v,Type dist[],int prev[],Type c[][N+1])
{
	bool s[maxint];
	for(int i=1; i<=n; i++){
		dist[i] = c[v][i];
		s[i] = false;
 
		if(dist[i] == maxint){
			prev[i] = 0;
		}
		else{
			prev[i] = v;
		}
	}
	dist[v] = 0;
	s[v] = true;
	for(int i=1; i<n; i++){
		int temp = maxint;
		int u = v;
		for(int j=1; j<=n; j++){
			if((!s[j]) && (dist[j]<temp)){
				u = j;
				temp = dist[j];
			}
		}
		s[u] = true;
 
		for(int j=1; j<=n; j++){
			if((!s[j]) && (c[u][j]<maxint)){
				Type newdist = dist[u] + c[u][j];
				if(newdist < dist[j]){
					dist[j] = newdist;
					prev[j] = u;
				}
			}
		}
	}
}
 
void Traceback(int v,int i,int prev[]){
	if(v == i){
		cout<<i;
		return;
	}
	Traceback(v,prev[i],prev);
	cout<<"->"<<i;
}
