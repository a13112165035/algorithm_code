#include <bits/stdc++.h>
using namespace std;
class MinHeapNode
{
public:
	int id;
	 int length; //从起始点 v 到点 id 的距离
public:
	friend bool operator < (const MinHeapNode &a, const MinHeapNode &b)
	{
		return a.length < b.length;
	}
	 friend bool operator > (const MinHeapNode &a, const MinHeapNode &b)
	 {
		 return a.length > b.length;
	 }
};
const int max_ = 0x3f3f3f;
int Graph[100][100];
int dist[100];
int pre[100];
int n, m, v;
void OutPutPath(int i)
{
	if(i == pre[i])
	{
		 printf("%d", i);
		return;
	 }
	 else
	{
		 OutPutPath(pre[i]);
		 printf(" %d", i);
	 }
}
void OutPut()
{
	 for(int i = 1; i <= n; ++i)
	{
		 if(i != v)
		{
			printf("点 %d 到 %d 的最短距离是 %d\n", v, i, dist[i]);
			printf("路径为：");
			OutPutPath(i);
			printf("\n");
		}
	 }
}
void ShortestPaths()
{
	 priority_queue<MinHeapNode, vector<MinHeapNode>, greater<MinHeapNode> > q; // 小顶堆
	memset(dist, max_, sizeof(dist));
	dist[v] = 0; //不要忘了这里的初始化
	 pre[v] = v;
	 MinHeapNode cur_p;
	 cur_p.id = v;
	 cur_p.length = 0;
	 q.push(cur_p);
	 while(true)
	{
		if(q.empty() == 1)
			 break;
		cur_p = q.top(); //取出堆顶的点
		q.pop(); // 在优先队列中删除刚取出的点
		for(int i = 1; i <= n; ++i)
		{
			if(Graph[cur_p.id][i] != max_ && (cur_p.length + Graph[cur_p.id][i] < dist[i]))
			{
				dist[i] = cur_p.length + Graph[cur_p.id][i];
				pre[i] = cur_p.id;
				MinHeapNode temp;
				temp.id = i;
				temp.length = dist[i];
				q.push(temp);
			 }
		}
	}
 
 
}
void InPut()
{
	int x, y, len;
	scanf("%d %d %d", &v, &n, &m);
	memset(Graph, max_, sizeof(Graph));
	for(int i = 1; i <= m; ++i)
	{
		scanf("%d %d %d", &x, &y, &len);
		Graph[x][y] = Graph[y][x] = len;
	}
}
int main()
{
	InPut();
	ShortestPaths();
	OutPut();
}
