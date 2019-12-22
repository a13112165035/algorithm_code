 
#include <iostream>  
#include <stdlib.h> 
#define  MaxInt 65535

using namespace std;  

  
template<class Type>  
class Graph  			//定义类Graph
{  
   public:  
    void ShortesPaths(int);  
    void initiate(int n1, Type **c1,Type *dist1,int *prev1)  	//初始化有向图  	   
	  {
	  	 n=n1; 
    	 c=c1;  
    	 dist=dist1;  
    	 prev=prev1; 
	  }   
    
    private:  
        int    n,*prev;    
        Type   **c,*dist;      
};   
  
template<class Type>  
class MinHeapNode  			//定义最小堆结点 
{  
   friend Graph<Type>;  
   public:  
       operator int ()const
	   {
	      return length;
	   } 
	    
   private:  
       int   i;        
       Type  length;     
};   

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
void Graph<Type>::ShortesPaths(int v)		//计算最短路径 
{   
    MinHeap< MinHeapNode<Type> > H(1000);  
    MinHeapNode<Type> E;  
  
    E.i=v;  								//初始化结点 
    E.length=0;  
    dist[v]=0;  
  
    while (true)
    {  
    for (int j = 1; j <= n; j++)  
    	if ((c[E.i][j]!=0)&&(E.length+c[E.i][j]<dist[j])) 
        {                   
            dist[j]=E.length+c[E.i][j];  
            prev[j]=E.i;  
  
            MinHeapNode<Type> N;  
            N.i=j;  
            N.length=dist[j];  
        	H.Insert(N);  
        }  

        if (H.currentsize!=0) 
        {  
          H.DeleteMin(E);  			//取出扩展结点 
        }  
        else 
          { 
          	break; 
          }                     
    }  
} 

void ShowPath(int prev[],int begin,int temp )
{
	if(prev[temp]!=0){								//若前置结点不为空，则递归取出前置结点 
	 ShowPath(prev,begin,prev[temp]);
	 cout << prev[temp] << "->";
	}
}
  
int main()  
{    
    int n=8;  																//初始化结点个数，前置结点数组，路径长度数组 
    int prev[8] = {0,0,0,0,0,0,0,0};    
    int dist[8]={MaxInt,MaxInt,MaxInt,MaxInt,MaxInt,MaxInt,MaxInt,MaxInt};  
  
    cout<<"邻接矩阵："<<endl;  
    int **c = new int*[n+1];  
  
    for(int i=1;i<=n;i++)  						//使用随机数初始化邻接矩阵 
    {  
        c[i]=new int[n+1];  
        for(int j=1; j<=n; j++)  
        {  
            c[i][j]=rand()%9;  
            cout<<c[i][j]<<" ";  
        }  
        cout<<endl;  
    }  
    cout<<"\n";
  	
    int start;  								//输入源头 
    cout<<"input start point：";
    cin>>start;
    
    Graph<int> G;  
    G.initiate(n, c,dist,prev);    
    G.ShortesPaths(start);  					//计算最短路径 
	
	cout<<"\n";
	
    for (int i = 1; i <= n; i++)  				//展示到各点最短路径 
    {  
        if(i!=start)
        {
        	if(dist[i]<1000)
        	{
				cout<<start<<"到"<<i<<"的最短路长是："<<dist[i]<<", 最短路径为：";
				ShowPath(prev,start,i);
	    		cout <<i<<endl;  
        	}
        	else
        	 	cout<<start<<"到"<<i<<"不可达"<<endl;			
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


