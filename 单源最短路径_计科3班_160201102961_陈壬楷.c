#include <bits/stdc++.h>
 
using namespace std;
 
const int N=1e5+5;
const int MAX=2147483647;
typedef long long LL;
 
struct node{        //建图部分还是一样的
    int from;
    int to;
    int value;
    int next;
}edge[2*N];
int head[N];
 
LL dis[N];
int visited[N];
 
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >vis;    //优先队列
 
int main()
{
    int n,m,s;
    int cnt=0;
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) dis[i]=MAX;
    for(int i=1;i<=m;i++)
    {
        cnt++;
        scanf("%d%d%d",&edge[cnt].from,&edge[cnt].to,&edge[cnt].value);
        edge[cnt].next=head[edge[cnt].from];
        head[edge[cnt].from]=cnt;
    }
 
 
    dis[s]=0;
    vis.push(make_pair(0,s));    //储存某点距离和该点
                                 //make_pair是c++自带的二元组定义方式,可以通过first、second访问第一个，
				//第二个元素(小根堆以第一个值排序)
 
    while(!vis.empty())        //判断所有点是否都查找过一遍
    {
        int start=vis.top().second;    //优先队列队首即最小的元素
        vis.pop();
 
        if(visited[start]==1) continue;    //如果该点查找过，跳过
        visited[start]=1;
 
        for(int i=head[start];i!=0;i=edge[i].next)
        {
            if(dis[edge[i].to]>dis[start]+edge[i].value)
            {
                dis[edge[i].to]=dis[start]+edge[i].value;
                vis.push(make_pair(dis[edge[i].to],edge[i].to));     
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i==n) printf("%d\n",dis[i]);
        else printf("%d ",dis[i]);
    }
}

