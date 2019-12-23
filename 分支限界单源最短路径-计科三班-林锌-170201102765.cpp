#include<iostream>
using namespace std;
const int size = 100;
const int inf = 5000;   //两点距离上界

const int n = 6;    //图顶点个数加1
int prev[n];     //图的前驱顶点
int dist[] = {0,0,5000,5000,5000,5000};       //最短距离数组
int c[n][n] = {{0,0,0,0,0,0},{0,0,2,3,5000,5000},    //图的邻接矩阵
    {0,5000,0,1,2,5000},{0,5000,5000,0,9,2},
   {0,5000,5000,5000,0,2},{0,5000,5000,5000,5000,0}};


class MinHeapNode{

public :
 int i;    //顶点编号
 int length;   //当前路长

};

//循环队列
class CirQueue{
private:
  int front,rear;
  MinHeapNode data[size];
public:
   CirQueue(){
   front = rear = 0;
  }
  
  //元素入队操作
  void queryIn(MinHeapNode e){
   
   if((rear +1)%size != front){
    rear = (rear+1)%size; //队尾指针在循环意义下加1
    data[rear] = e;   //在队尾插入元素
   }
  }
  
  //元素出队操作
  MinHeapNode queryOut(){
   if(rear != front){
    front = (front+1)%size;  //队列在循环意义下加1
    return data[front];
   }
  }
  //读取队头元素，但不出队
  MinHeapNode getQuery(){
   if(rear != front){
    return data[(front+1)%size];
   }
  }
  
  //判断队列是否为空
  bool empty(){
   return front == rear;
   
  }
  //判断队列是否为满
  bool full(){
   return (rear +1)%size == front;
  }
 };//CirQueue结束

//图的表示 
class Graph{

public:
 /**
  * 单源最短路径问题的优先队列式分支限界法
  */
 void shortestPath(int v){
  //创建队列
  CirQueue qq;
  
  //定义源为初始扩展结点
  MinHeapNode e;
  e.i = v;
  e.length = 0;
  dist[v] = 0;
  qq.queryIn(e);
  //搜索问题的解空间
  while(true){
   for(int j = 1;j<n;j++){
    if(j>=n){
     break;
    }
    MinHeapNode m = qq.getQuery();
    if((c[m.i][j]<inf)&&(m.length + c[m.i][j] < dist[j])){
     
     //顶点i到顶点j可达，且满足控制约束
     dist[j] = m.length + c[m.i][j];
     prev[j] = m.i;
    //加入活结点优先队列
    MinHeapNode mi;
    mi.i = j;
    mi.length  = dist[j];
    if(qq.full()){
     break;
    }
    qq.queryIn(mi);   //元素入队
    }
   }//for循环结束
   if(qq.empty()){
     break;
    }
   qq.queryOut();    //当该结点的孩子结点全部入队后，删除该结点
  }//while循环结束
 }//方法结束
};//类结束

int main(){

  Graph g;
  g.shortestPath(1);
  cout<<"最短路径长为 "<<dist[n-1]<<endl;

  cout<<"中间路径为： ";
  for(int i =3;i<n;i++){
   cout<<prev[i]<<" ";
  }
 return 0;
}
