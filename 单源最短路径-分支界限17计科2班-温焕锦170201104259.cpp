#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
 
class MinNode
{
public :
	int id;//������
	int length;//��ǰ·��
	friend bool operator<(MinNode A, MinNode B)
	{
		return  (A.length >  B.length);//���ܴ����ں�
	}
};
class Graph
{
public:
	Graph()
	{
		cout<<"�����붥�����ͻ�����"<<endl;
		cin >>n>>m;
		vector<int> ie1;
		edges.push_back(ie1);
		for (int i = 1; i <= n; i++)
		{
			vector<int> ie2(n + 1, 100000);
			edges.push_back(ie2);
		}
		cout<<"���������������֮���Ȩֵ(��1  2  4)��"<<endl;
		for (int i = 1; i <= m; i++)
		{
			int in1, in2 ,w;
			cin >> in1 >> in2>>w;
			edges[in1][in2] = w;
		}
		prev.assign(n + 1, -1);
		dist.assign(n + 1, 100000);
		cout<<"������Դ�������յ�����"<<endl; 
 
		cin >> v >> u;
	}
	void ShortPath()
	{
		priority_queue<MinNode> Q;
		MinNode E = { v , 0 };
		dist[v] = 0;
		prev[v] = 0;//Դ���ǰ����Ϊ0
		while (1)
		{
			for (int i = 1; i <= n; i++)
			{
				if (edges[E.id][i] != 100000)//������дӶ���E.id�ɴ�Ķ���i
				{
					int temp = E.length + edges[E.id][i];
					if (temp < dist[i])//����ȵ�ǰ��̾���С,��Ϊ����������ȼ�����
					{
						MinNode active = { i , temp };
						prev[i] = E.id;
						dist[i] = temp;
						Q.push(active);
					}
				}
			}
			if (!Q.empty())
			{
				E = Q.top();
				Q.pop();
			}
			else
			{
				break;
			}
		}
	}
	
	void print()
	{
		int p = u;
		vector<int> path;
		while (prev[p] != 0)
		{
			path.push_back(p);
			p = prev[p];
		}
		path.push_back(v);
		reverse(path.begin(), path.end());
		cout << "dist array : " << endl;
		for (int i = 1; i < dist.size(); i++)
		{
			cout <<setw(4)<< dist[i] << " ";
		}
		cout << endl;
		cout << "prev array : " << endl;
		for (int i = 1; i < prev.size(); i++)
		{
			cout << setw(4) << prev[i] << " ";
		}
		cout << endl;
		cout << v << "-->" << u << "�����·�� :" << endl;
		cout << v;
		for (int i = 1; i < path.size(); i++)
		{
			cout << "->" << path[i];
		}
		cout << endl;
	}
public:
	int n , m ;//������,����
	vector<int> prev;//·���ϵ�ǰ�����飻
	vector<int> dist;//��̾������飬��¼��Դ�������㵱ǰ��̾���
	vector<vector<int> > edges;//�ڽӾ���
	int v, u;
};
 
 
Graph G;
 
int main()
{
	G.ShortPath();
	G.print();
	
	return 0;
}

