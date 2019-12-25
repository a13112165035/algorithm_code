#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;

const int N=1000;
const int INF=1e9+7;

int c[N][N];
int dist[N];
int n,m,v;

struct Node
{
	int id;
	int length;
};

bool operator > (const Node &a, const Node &b)
{
    return a.length > b.length;
}

//bool operator < (const Node &a, const Node &b)
//{
//    return a.length < b.length;
//}


void ShortestPaths()
{
    priority_queue<Node, vector<Node>, greater<Node> > q; 
    dist[v] = 0; 										
    Node E;										
    E.id = v;
    E.length = 0;
    q.push(E);
    while(!q.empty())
    {
        E = q.top(); 									
        q.pop();
		for(int i = 1; i <= n; i ++)					
        {
            if(c[E.id][i]!=INF && (E.length + c[E.id][i] < dist[i]))
            {
                dist[i] = E.length + c[E.id][i];
                Node N;
                N.id = i;
                N.length = dist[i];
                q.push(N);
            }
        }
    }
}

int main()
{
    int a,b,lens;
	cout<<"Please enter the number of points, sides and start point of the graph:";
	cin>>n>>m>>v;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			c[i][j]=INF;
		}
	}
	for (int i=0;i<=n;i++)
	{
		dist[i]=INF;
	}
	cout<<"Please input each side and weight:"<<endl;
	for(int i=1;i<=m;i++)
	{

		cin>>a>>b>>lens;
		c[a][b]=lens;
	}
	
    ShortestPaths();
    
    for(int i=1;i<=n;i++)
	{
		if(i!=v)
		{
			cout<<"point "<<v<<" to "<<"point "<<i<< " shortest distance is: " <<dist[i];
			cout<<endl;
		}
	}
    return 0;
}
