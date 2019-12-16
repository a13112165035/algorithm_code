#include <vector>
#include <iostream> 
using namespace std; 
struct edge{	
	int to, 
	cost;}; 
const int MAX = 10001;
const int INF = 0x3f3f3f3f; // 假设这是无法到达的话的距离 

vector<edge> G[MAX]; // 图
int d[MAX];
int used[MAX];
int V; // 顶点数
int E; // 边数
int s; // 出发的点 
void creat(){	
		// 因为只是支持顶点 0 ~ n， 如果顶点是 1 ~ n, 自行更改 只要把顶点的值减 1 就行了	
		// 这里假设是 0 ~ n	
		cin >> V >> E >> s;	
		for(int i = 0; i < E; ++i){	    
			int from, to, cost;	    
			cin >> from >> to >> cost;	    
			edge e;	    
			e.to = to;	    
			e.cost = cost;	    
			G[from].push_back(e);	
			}
		} 
void Dijkstra(int s){	
		fill(d, d + V, INF);	
		fill(used, used + V, false);	
		d[s] = 0;	
		while(true){	    
			int v = -1;	    
		for(int i = 0; i < V; ++i){		
			if(!used[i] && (v == -1 || d[v] > d[i])){ // 寻找到达某一点的最短距离			
				v = i;		
				}	    
			}	    
		if(v == -1) break;	    
		used[v] = true;	    
		for(int i = 0; i < (int)G[v].size(); ++i){	        
			edge e = G[v][i];		
			if(d[v] != INF) // 如果存在不能到达的点的话，则不予考虑                
			d[e.to] = min(d[e.to], d[v] + e.cost); // v -> i 从v到 e.to顶点的距离	    
			}	
		}
	} 
void solve(){	
		creat();	
		Dijkstra(s);	
		for(int i = 0; i < V; ++i) 
		cout << d[i] << ' '; // 输出到达各个顶点的最短距离， 如果无法到达结果为 INF
	}
int main(){	
	solve();	
	return 0;
}


