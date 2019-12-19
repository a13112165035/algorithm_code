#include<iostream>
#include<climits>
#include<vector>
const int M=100;
using namespace std;
struct node{ 
	int father; 
	int cost; 
}; 
struct edge{ 
	int dest; 
	int cost;
};
node vertex[M];
bool isVisited[M]={0}; 
vector<edge> graph[M];
void printVertex(int v){ 
	for(int i=1;i<=v;i++)
	cout<<i<<":"<<vertex[i].cost<<"   "<<vertex[i].father<<endl;
} 
void init(int v,int s){ 
	for(int i=1;i<=v;i++){
		vertex[i].cost=INT_MAX; 
		vertex[i].father=i; 
	}
	vertex[s].cost=0; 
}
int getMin(int v){ 
	int res=INT_MAX;
	int index=-1;
	for(int i=1;i<=v;i++){
		if((isVisited[i]==0)&&(res>=vertex[i].cost)){
			res=vertex[i].cost;
			index=i;
		}
	}
	isVisited[index]=1;
	return index;
}
void relax(int u){ 
	int len=graph[u].size();
	for(int i=0;i<len;i++){
		int des=(graph[u][i]).dest;
		if((vertex[u].cost!=INT_MAX)&&(vertex[des].cost>vertex[u].cost+(graph[u][i]).cost)){
			vertex[des].cost=vertex[u].cost+(graph[u][i]).cost;
			vertex[des].father=u;
		}
	}
}
void dijkstra(int v,int e,int s){
	init(v,s);
	for(int i=1;i<=v;i++){ 
		int u=getMin(v);
		relax(u);
	}
}
void printPath(int startPoint,int destination){
	if(destination==startPoint)
		cout<<destination;
	else{
		printPath(startPoint,vertex[destination].father);
		cout<<"-->"<<destination;
	}
}
 
void printRoad(int v,int s){
	for(int i=1;i<=v;i++){
		cout<<"from "<<s<<" to "<<i<<" smallest cost:"<<vertex[i].cost<<".path:";
		printPath(s,i);
		cout<<endl;	
	}
}
int main(){
	int v,e,s;
	cin>>v>>e>>s;
	int a,b,c;
	edge temp;
	for(int i=1;i<=e;i++){
		cin>>a>>b>>c;
		temp.dest=b;
		temp.cost=c;
		graph[a].push_back(temp);
	}
	dijkstra(v,e,s);
	printRoad(v,s);
}
