#include <iostream>
 
template<class Type>
class Graph;
 
template<class T> 
class MinHeap 
{ 
 template<class Type>
 friend class Graph;
 public: 
  MinHeap(int maxheapsize = 10); 
  ~MinHeap(){delete []heap;} 
 
  int Size() const{return currentsize;} 
  T Max(){if(currentsize) return heap[1];} 
 
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
#include "stdafx.h"
#include "MinHeap2.h"
#include <iostream>
#include <fstream> 
using namespace std;
 
ifstream fin("6d2.txt"); 
 
template<class Type>
class Graph
{
 friend int main();
    public:
  void ShortesPaths(int);
 private:
        int  n, 
    *prev;  
      Type **c, 
    *dist; 
}; 
 
template<class Type>
class MinHeapNode
{
   friend Graph<Type>;
   public:
    operator int ()const{return length;}
   private:
       int       i; 
       Type  length; 
}; 
 
template<class Type>
void Graph<Type>::ShortesPaths(int v)
{ 
 MinHeap<MinHeapNode<Type>> H(1000);
 MinHeapNode<Type> E;
 E.i=v;
 E.length=0;
 dist[v]=0;
 
 while (true)
 {
  for (int j = 1; j <= n; j++)
   if ((c[E.i][j]!=0)&&(E.length+c[E.i][j]<dist[j])) {

     dist[j]=E.length+c[E.i][j];
     prev[j]=E.i;
     MinHeapNode<Type> N;
     N.i=j;
     N.length=dist[j];
     H.Insert(N);
   }`
  try 
  {
   H.DeleteMin(E); 
  }        
  catch (int) 
  {
   break;
  }  
  if (H.currentsize==0)
  {
   break;
  }
 }
}
 
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
 }
 
 int v=1;
    Graph<int> G;
    G.n=n;
 
    G.c=c;
    G.dist=dist;
    G.prev=prev;
    G.ShortesPaths(v);
 
    cout<<"从S到T的最短路长是："<<dist[11]<<endl;
    for (int i = 2; i <= n; i++)
 {
  cout<<"prev("<<i<<")="<<prev[i]<<"   "<<endl;
 }
 
    for (int i = 2; i <= n; i++)
 {
  cout<<"从1到"<<i<<"的最短路长是："<<dist[i]<<endl;
 }
 
 for(int i=1;i<=n;i++)
 {
  delete []c[i];
 }
 
 delete []c;
 c=0; 
 return 0;
}
