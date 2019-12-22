#include<iostream>
#include<algorithm>
#include<queue>
#include<stdio.h>
#define MAX 200
#define LIMITLESS 70000
using namespace std;
int cost[MAX];                 
typedef struct{
    bool operator()(int &a,int &b){
         return cost[a]>cost[b];
    }
}cmp;
typedef struct Graph{
    int v,e;
    int vex[MAX];
    int wei[MAX][MAX];
}Graph,*graph;
void createGraph(graph g){
    cout<<"输入顶点和边数:"<<endl;
    cin>>g->v>>g->e;
    cout<<"输入顶点值:"<<endl;
    for(int i = 1;i<=g->v;i++){
         cin>>g->vex[i];
    }
    for(int i = 1;i<=g->v;i++){          
        for(int j = 1;j<=g->v;j++){
            g->wei[i][j] = LIMITLESS;
        }
    }
    cout<<"输入两连接点下标和权值:"<<endl;
    int k1,k2,weight;
    for(int i = 1;i<=g->e;i++){
        cin>>k1>>k2>>weight;
        g->wei[k1][k2] = weight;
    }
}

void  dijkstra(graph g,int sour){
      cost[sour] = 0;
      for(int i = 2;i<=g->v;i++){                   
          cost[i] = g->wei[sour][i];
      }
      priority_queue<int,vector<int>,cmp> p;      
      p.push(sour);                              
      int flag [MAX];                           
      int k = 0;
      while(!p.empty()){
          int item = p.top();
          flag[k++] = item;
          p.pop();
          
          for(int i = item;i<=g->v;i++){
             if((g->wei[item][i]!=LIMITLESS)&&(cost[item]+g->wei[item][i]<=cost[i])){
                  cost[i] = cost[item]+g->wei[item][i];
                  p.push(i);
             }
          }
      }
      for(int i = 2;i<=g->v;i++){
          cout<<"源点到"<<i<<"顶点的最短距离为:"<<cost[i]<<endl;
      }
      cout<<"顶点的出队列顺序(按源点到顶点距离短的优先):"<<endl;
      for(int i = 0;i<k;i++){
          cout<<flag[i]<<" ";
      }
}

void  printGraph(graph g){
       for(int i = 1;i<=g->v;i++){
          for(int j = 1;j<=g->v;j++){
              if(g->wei[i][j]!=LIMITLESS){
                  cout<<g->wei[i][j]<<"  ";
              }
              else{
                  cout<<"oo"<<"  ";
              }
          }
          cout<<endl;
      }
}


int main(){
     Graph g;               
     createGraph(&g);
     cout<<"构建的图:"<<endl;
     printGraph(&g);
     cout<<"単源最短路径为:"<<endl;
     dijkstra(&g,1);
}

