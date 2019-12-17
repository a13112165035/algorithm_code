#include <iostream>
#include <queue>
using namespace std;
#define MAX 9999
#define N 60
int n,dist[N],a[N][N];
class HeapNode
{
public:
    int i,length;
    HeapNode() { }
    HeapNode(int ii,int l)
    {
        i=ii;
        length=l;
    }
    bool operator<(const HeapNode& node)const
    {
        return length<node.length;
    }
};
void shorest(int v)
{
    priority_queue<HeapNode>  heap;
    HeapNode enode(v,0);
    for(int i=1; i<=n; i++)  dist[i]=MAX;
    dist[v]=0;
    while(1)
    {
        for(int j=1; j<=n; j++)
            if(a[enode.i][j]<MAX && enode.length+a[enode.i][j]<dist[j])
            {
                dist[j]=enode.length+a[enode.i][j];
                HeapNode node(j,dist[j]);
                heap.push(node);
            }
        if(heap.empty()) break;
        else
        {
            enode=heap.top();
            heap.pop();
        }
    }
}
int main ()
{
    cout<<"请输入顶点个数:";
	cin>>n;
	cout<<"请输入顶点到各条边的权值:";
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            cin>>a[i][j];
            if(a[i][j]==-1)  a[i][j]=MAX;
        }
    shorest(1);
    for(int i=2; i<n; i++) cout<<dist[i]<<" ";
    cout<<dist[n]<<endl;
    return 0;
}

