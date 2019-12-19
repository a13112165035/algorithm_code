#include<bits/stdc++.h>
using namespace std;
struct node{
 int smallCost;
 int father;
}V[110]; 
struct Node{
 int start;
 int end;
 int cost;
}a[110];
void init(int v,int s){//v个节点，对v进行初始化,s为起点 
 for(int i=1;i<=v;i++){
  V[i].smallCost=INT_MAX;
  V[i].father=-1;
 }
 V[s].smallCost=0; 
}
bool fold(int v,int e,int s){//时间复杂度为：O(VE) 
 init(v,s);
 for(int i=1;i<=v-1;i++){
  for(int j=1;j<=e;j++){
    int x=a[j].start;
    int y=a[j].end;
    int z=a[j].cost;
    if(V[x].smallCost!=INT_MAX&&V[y].smallCost>V[x].smallCost+z){
     V[y].smallCost=V[x].smallCost+z;
     V[y].father=x;
    }
  }
 }
 for(int j=1;j<=e;j++){
  int x=a[j].start;
  int y=a[j].end;
  int z=a[j].cost;
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
 int v,e,s;
 cin>>v>>e>>s;
 for(int i=1;i<=e;i++)
  cin>>a[i].start>>a[i].end>>a[i].cost;
 fold(v,e,s);
 for(int i=1;i<=v;i++){
  cout<<"from "<<s<<" to "<<i<<" smallest cost:"<<V[i].smallCost<<".path:";
  printPath(s,i);
  cout<<endl; 
 }
 
 return 0;
}

