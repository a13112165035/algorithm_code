#include<iostream>
#include<climits>
const int M=100;
using namespace std;
struct vertex{
	int smallCost;
	int father;
}; 
struct edge{
	int start;
	int end;
	int cost;
};
vertex V[M];
edge arr[M];
void init(int v,int s){//v个节点，对v进行初始化,s为起点 
	for(int i=1;i<=v;i++){
		V[i].smallCost=INT_MAX;
		V[i].father=-1;
	}
	V[s].smallCost=0;	
}
bool bell_fold(int v,int e,int s){//时间复杂度为：O(VE) 
	init(v,s);
	for(int i=1;i<=v-1;i++){
		for(int j=1;j<=e;j++){
				int x=arr[j].start;
				int y=arr[j].end;
				int z=arr[j].cost;
				if(V[x].smallCost!=INT_MAX&&V[y].smallCost>V[x].smallCost+z){
					V[y].smallCost=V[x].smallCost+z;
					V[y].father=x;
				}
		}
	}
	for(int j=1;j<=e;j++){
		int x=arr[j].start;
		int y=arr[j].end;
		int z=arr[j].cost;
		if(V[x].smallCost!=INT_MAX&&V[y].smallCost>V[x].smallCost+z)
			return false;			
	}
	return true;
}
void printPath(int src,int des){
	if(des==src)
		cout<<des;
	else{
		printPath(src,V[des].father);
		cout<<"-->"<<des;
	}
	
}
int main(){
	int v,e,s;//v个顶点e条边 s为起始点
	cin>>v>>e>>s;
	for(int i=1;i<=e;i++)
		cin>>arr[i].start>>arr[i].end>>arr[i].cost;
	bell_fold(v,e,s);
	for(int i=1;i<=v;i++){
		cout<<"from "<<s<<" to "<<i<<" smallest cost:"<<V[i].smallCost<<".path:";
		printPath(s,i);
		cout<<endl;	
	}
	
	return 0;
}
