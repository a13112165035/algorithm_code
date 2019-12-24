#include <iostream>
#include <iomanip>

using namespace std;

#define inf 1000000

template<class T>
class MinHeap   //最小堆类
{
	template<class Type>
	friend class Graph;
public:
	MinHeap(int maxheapsize=10);  //构造函数，堆的大小是10
	~MinHeap(){delete[] heap;}     //最小堆的析构函数
	int Size() const{return currentsize;}  //Size()返回最小堆的个数
	T Max(){if(currentsize) return heap[1];}   //第一个元素出堆
	MinHeap<T>& Insert(const T& x);   //最小堆的插入函数
	MinHeap<T>& DeleteMin(T& x);    //最小堆的删除函数
	void Initialize(T x[],int size,int ArraySize);  //堆的初始化
	void Deactivate();
//	void output(T a[],int n);
private:
	int currentsize,maxsize;  
	T *heap;   
};

/*
template<class T>
void MinHeap<T>::output(T a[],int n)    //输出函数，输出a[]数组的元素
{
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
		cout<<endl;
}
*/

template<class T>
MinHeap<T>::MinHeap(int maxheapsize)
{
	maxsize=maxheapsize;
	heap=new T[maxsize+1];  //创建堆
	currentsize=0;
}

template<class T>
MinHeap<T>& MinHeap<T>::Insert(const T& x)
{
	if(currentsize==maxsize)   //如果堆中的元素已经等于堆的最大大小
		return *this;     //那么不能在加入元素进入堆中
	int i= ++currentsize;
	while(i!=1 && x<heap[i/2])
	{
		heap[i]=heap[i/2];
		i/=2;
	}
	heap[i]=x;
	return *this;
}

template<class T>
MinHeap<T>& MinHeap<T>::DeleteMin(T& x)  //删除堆顶元素
{
	if(currentsize==0) 
	{
		cout<<"Empty heap!"<<endl;
		return *this;
	}
	x=heap[1];  

	T y=heap[currentsize--];
	int i=1,ci=2;
	while(ci<=currentsize)
	{
		if(ci<currentsize && heap[ci]>heap[ci+1])
			ci++;
		if(y<=heap[ci])
			break;
		heap[i]=heap[ci];
		i=ci;
		ci*=2;
	}
	heap[i]=y;
	return *this;
}

template<class T>
void MinHeap<T>::Initialize(T x[],int size,int ArraySize)  //堆的初始化
{
	delete[] heap;
	heap=x;
	currentsize=size;
	maxsize=ArraySize;
	for(int i=currentsize/2;i>=1;i--)
	{
		T y=heap[i];
		int c=2*i;
		while(c<=currentsize)
		{
			if(c<currentsize && heap[c]>heap[c+1])
				c++;
			if(y<=heap[c])
				break;
			heap[c/2]=heap[c];
			c*=2;
		}
		heap[c/2]=y;
	}
}

template<class T>
void MinHeap<T>::Deactivate()
{
	heap=0;
}



template <class Type>
class Graph
{
	friend int main(void);
public:
    void ShortestPaths(int);
private:
    int n,//顶点数 
	*prev;	//前驱
	Type **c;//邻接矩阵
	*dist;//最短距离 
};

template <class Type>
class MinHeapNode
{
	friend Graph<Type>;
public:
	operator int () const{return length;}
private:
	int i;          //顶点编号 
	Type length;    //当前路长 
};

template <class Type>
void Graph<Type>::ShortestPaths(int v)
{
	MinHeap < MinHeapNode<Type> > H(1000);   //最小堆容量 
	MinHeapNode<Type> E;//定义源为初始扩展结点
	E.i=v;
	E.length=0;
	dist[v]=0;
	while(true){
		for(int j=1;j<=n;j++)
			if((c[E.i][j]<inf)&&(E.length+c[E.i][j]<dist[j]))
			{
				dist[j]=E.length+c[E.i][j];
				prev[j]=E.i;
				MinHeapNode<Type> N;
				N.i=j;
				N.length=dist[j];
				H.Insert(N);
			}
		
		try{ H.DeleteMin(E);}
		catch(int) {break;}
		if(H.currentsize==0) {break;}
	
	} 
}

int main()
{
    
    int n,v,*dist,*prev,**c;
    
    do
    {
    cout<<"请输入图G顶点数量n(n>0)：";
    cin>>n;
    }while(n<=0||n==NULL) ;   
    
    dist=new int[n+1];
    prev=new int[n+1];
    c=new int*[n+1];
    
    for(int i=0;i<=n;i++)
    {
    	dist[i]=inf;
    	prev[i]=0;
	}
	
	cout<<"下面输入单源图的邻接矩阵："<<endl;
	for(int i=1;i<=n;i++)  //输入图的邻接矩阵
	{
		c[i]=new int[n+1];
		for(int j=1;j<=n;j++)
		{
			cin>>c[i][j];
			if(c[i][j]==0) c[i][j]=inf;
		}
	}


	Graph<int> G;
	G.n=n;
	G.c=c;
	G.dist=dist;
	G.prev=prev;

    do
	{
		cout<<endl<<"请输入源v: ";
        cin>>v;		
	}while(v<=0||v>n);

	G.ShortestPaths(v);//调用图的最短路径查找算法

/*
	for(int i=1;i<=n;i++)//输出每个结点的前驱结点
	{
		cout<<"prev["<<i<<"]="<<prev[i]<<" "<<endl;
	}
*/	
    cout<<endl;
	for(int i=1;i<=n;i++)  //输出从源结点到其他结点的最短路径长度
	{
		if(i!=v) 
		{
			if(dist[i]>=inf) cout<<"从"<<v<<"无法到达"<<i<<endl<<endl;
			else 
			{
			   cout<<"从"<<v<<"到"<<i<<"的最短路长是："<<dist[i]<<endl;
			   cout<<"最短路径为："<<i;
			   int k=prev[i];
			   while(true)
			   {			   	     			   				   	   	
					cout<<"<=="<<k;	
					k=prev[k];
					if(k==0) break;		   	   					    			   	   	
			   }
			   cout<<endl<<endl;
			}			
		}
	}	

	for(int i=1;i<=n;i++)    //删除动态分配时的内存
	{
		delete[] c[i];
	}

	delete[] c;
	c=0;

    
	
	return 0;
}
