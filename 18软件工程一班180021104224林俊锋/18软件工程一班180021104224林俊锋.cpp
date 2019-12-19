#include "MinHeap2.h"  
#include <iostream> 
#include<iomanip>  
#include <fstream>  
#include<stdlib.h> 
using namespace std;  
#define MaxInt 32767    
ifstream fin("intput6-2-(1).txt"); 
//ifstream fin("intput6-2-(2).txt");   
  
template<class Type>  
class Graph  
{  
   public:  
    void ShortesPaths(int);  
    void input(int n1, Type **c1,Type *dist1,int *prev1)    	   
	  {
	  	 n=n1; 
    	 c=c1;  
    	 dist=dist1;  
    	 prev=prev1; 
	  }   
    
    private:  
        int     n,         
                *prev;     
        Type    **c,       
                *dist;      
};   
  
template<class Type>  
class MinHeapNode  
{  
   friend Graph<Type>;  
   public:  
       operator int ()const
	   {
	      return length;
	   } 
	    
   private:  
       int       i;       
       Type  length;       
};   
  
template<class Type>  
void Graph<Type>::ShortesPaths(int v)  
{   
    MinHeap< MinHeapNode<Type> > H(1000);  
    MinHeapNode<Type> E;  
  
    //定义源为初始扩展节点  
    E.i=v;  
    E.length=0;  
    dist[v]=0;  
  
    while (true)//搜索问题的解空间  
    {  
       for (int j = 1; j <= n; j++)  
            if ((c[E.i][j]<MaxInt)&&(E.length+c[E.i][j]<dist[j])) 
            {                  
				 // 顶点i到顶点j可达，且满足控制约束  
                 dist[j]=E.length+c[E.i][j];  
                 prev[j]=E.i;  
  
                 // 加入活结点优先队列  
                 MinHeapNode<Type> N;  
                 N.i=j;  
                 N.length=dist[j];  
                 H.Insert(N);  
            }  

        if (H.currentsize==0)// 优先队列空  
        {  
            break;  
        }  
        else 
          {
          	H.DeleteMin(E); // 取下一扩展结点 
          }                     
    }  
} 

void DisplayPath(int prev[],int begin,int temp )
{	//显示最短路
	if(prev[temp]!=0){
		DisplayPath(prev,begin,prev[temp]);
		cout << prev[temp] << "-->";
	}
}//DisplayPath 
  
int main()  
{    
    int n=11; //图的顶点数 
    int *prev=new int[n+1]; //0号单元不使用  
    int *dist=new int[n+1];  //0号单元不使用 
	
	//初始化prev[]都为0，dist[]都为极大值 
	for(int i=1;i<=n;i++) //0号单元不使用 
	 {
	 	prev[i]=0;
	 	dist[i]=MaxInt;
	 } 
    cout<<"图的邻接矩阵如下："<<endl;  
    int **c = new int*[n+1];  
  
    for(int i=1;i<=n;i++)  
    {  
        c[i]=new int[n+1];  
        for(int j=1; j<=n; j++)  
        {  
            fin>>c[i][j];  
            cout<< setw(6)<<c[i][j]<<" ";  
        }  
        cout<<endl;  
    }  
    
	cout<<"图的顶点编号为:";
    for(int i=1;i<=n;i++)
      cout<<i<<" ";
    cout<<endl;
    
	int start;  
    cout<<"请输入起点：";
    cin>>start;
    Graph<int> G;  
    G.input(n, c,dist,prev);
    
    G.ShortesPaths(start);  
	 
    for (int i = 1; i <= n; i++)  
    {          
		cout<<"prev("<<i<<")="<<prev[i]<<"   "<<endl;  
    }  
  
    for (int i = 1; i <= n; i++)  
    {  
        if(i!=start)
        {
        	if(dist[i]<MaxInt)
        	{
				cout<<"从"<<start<<"到"<<i<<"的最短路长是："<<dist[i]<<",  路径为：";
				DisplayPath(prev,start,i);
	    		cout <<i<<endl;  
        	}
        	else
        	 	cout<<"从"<<start<<"到"<<i<<"没有路径到达！"<<endl;			
        }
		
    }  
 
    for(int i=1;i<=n;i++)  
    {  
        delete []c[i];  
    }  
  
    delete []c;  
    c=0; 
	system("pause");     
    return 0;  
} 


