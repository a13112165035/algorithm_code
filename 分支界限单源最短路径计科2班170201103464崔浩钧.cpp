#include <iostream>  
#include <fstream>  
#include<stdlib.h> 
using namespace std;  
  	
ifstream fin("intput.txt");   
template<class T>   
class MinHeap   
{   
    template<class Type>  
     friend class Graph;  
    public:   
        MinHeap(int maxheapsize = 10);   
        ~MinHeap(){delete []heap;}   
  
        int Size() const{return currentsize;}   
        T Min(){if(currentsize) return heap[1];}   
  
        MinHeap<T>& Insert(const T& x);   
        MinHeap<T>& DeleteMin(T &x);   
  
        void Initialize(T x[], int size, int ArraySize);   
        void Deactivate();   
        void output(T a[],int n);  
    private:   
        int currentsize, maxsize;   
        T *heap;   
};   
  
template <class T>   
void MinHeap<T>::output(T a[],int n)   
{   
    for(int i = 1; i <= n; i++)   
    cout << a[i] << " ";   
    cout << endl;   
}   
  
template <class T>   
MinHeap<T>::MinHeap(int maxheapsize)   
{   
    maxsize = maxheapsize;   
    heap = new T[maxsize + 1];   
    currentsize = 0;   
}   
  
template<class T>   
MinHeap<T>& MinHeap<T>::Insert(const T& x)   
{   
    if(currentsize == maxsize)   
    {   
        return *this;   
    }   
    int i = ++currentsize;   
    while(i != 1 && x < heap[i/2])   
    {   
        heap[i] = heap[i/2];   
        i /= 2;   
    }   
  
    heap[i] = x;   
    return *this;   
}   
  
template<class T>   
MinHeap<T>& MinHeap<T>::DeleteMin(T& x)   
{   
    if(currentsize == 0)   
    {   
        cout<<"Empty heap!"<<endl;   
        return *this;   
    }   
  
    x = heap[1];   
  
    T y = heap[currentsize--];   
    int i = 1, ci = 2;   
    while(ci <= currentsize)   
    {   
        if(ci < currentsize && heap[ci] > heap[ci + 1])   
        {   
            ci++;   
        }   
  
        if(y <= heap[ci])   
        {   
            break;   
        }   
        heap[i] = heap[ci];   
        i = ci;   
        ci *= 2;   
    }   
  
    heap[i] = y;   
    return *this;   
}   
  
template<class T>   
void MinHeap<T>::Initialize(T x[], int size, int ArraySize)   
{   
    delete []heap;   
    heap = x;   
    currentsize = size;   
    maxsize = ArraySize;   
  
    for(int i = currentsize / 2; i >= 1; i--)   
    {   
        T y = heap[i];   
        int c = 2 * i;   
        while(c <= currentsize)   
        {   
            if(c < currentsize && heap[c] > heap[c + 1])   
                c++;   
            if(y <= heap[c])   
                break;   
            heap[c / 2] = heap[c];   
            c *= 2;   
        }   
        heap[c / 2] = y;   
    }   
}   
  
template<class T>   
void MinHeap<T>::Deactivate()   
{   
    heap = 0;   
}
 
template<class Type>  
class Graph  
{  
   public:  
    void ShortesPaths(int v);  
    void input(int n1, Type **c1,Type *dist1,int *prev1)    	   
	  {
	  	 n=n1; 
    	 c=c1;  
    	 dist=dist1;  
    	 prev=prev1; 
	  }   
    
    private:  
        int     n,         //图G的顶点数  
                *prev;     //前驱顶点数组  
        Type    **c,       //图G的领接矩阵  
                *dist;     //最短距离数组  
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
       int       i;       //顶点编号  
       Type  length;      //当前路长  
};   
  
template<class Type>  
void Graph<Type>::ShortesPaths(int v)//单源最短路径问题的优先队列式分支限界法  
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
            if ((c[E.i][j]!=0)&&(E.length+c[E.i][j]<dist[j])) 
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
    int n=11;  
    int prev[12] = {0,0,0,0,0,0,0,0,0,0,0,0};    
  
    int dist[12]={1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};  
  
    cout<<"单源图的邻接矩阵如下："<<endl;  
    int **c = new int*[n+1];  
  
    for(int i=1;i<=n;i++)  
    {  
        c[i]=new int[n+1];  
        for(int j=1; j<=n; j++)  
        {  
            fin>>c[i][j];  
            cout<<c[i][j]<<" ";  
        }  
        cout<<endl;
	/*
	0,2,3,4,0,0,0,0,0,0,0
	0,0,3,0,7,2,0,0,0,0,0
	0,0,0,0,0,9,2,0,0,0,0
	0,0,0,0,0,0,2,0,0,0,0
	0,0,0,0,0,0,0,2,3,0,0
	0,0,0,0,0,0,1,0,3,0,0
	0,0,0,0,0,0,0,0,5,1,0
	0,0,0,0,0,0,0,0,0,0,1
	0,0,0,0,0,0,0,0,0,0,2
	0,0,0,0,0,0,0,0,2,0,2
	0,0,0,0,0,0,0,0,0,0,0
	*/  
    }
	

    int start;  
    cout<<"请输入起点（共1到11个点）：";
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
        	if(dist[i]<1000)
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
    return 0;  
} 
