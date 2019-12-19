#include <iostream>

using namespace std;

class Dijkstra{
public:
	Dijkstra(int n, int v, int* dist, int* prev, int** c);
	Dijkstra();
	friend void findDijkstraAnswer();
	friend void findDijkstraAnswer(int n, int v, int* dist, int* prev, int** c);
	void dijkstra();

private:
	int n;	//点的个数
	int v;	//出发点
	int* dist;	//距离
	int* prev;	//后继存储
	int** c;	//图邻接矩阵
};

Dijkstra::Dijkstra() {
	int** ppc = new int*[5];
	ppc[0] = new int[5]{ 0, 10, MAXINT, 30, 100 };
	ppc[1] = new int[5]{ MAXINT, 0, 50, MAXINT, MAXINT };
	ppc[2] = new int[5]{ MAXINT, MAXINT, 0, MAXINT, 10 };
	ppc[3] = new int[5]{ MAXINT, MAXINT, 20, 0, 60 };
	ppc[4] = new int[5]{ MAXINT, MAXINT, MAXINT, MAXINT, 0 };
	this->c = ppc;
	this->dist = new int[5];
	this->n = 5;
	this->prev = new int[5];
	this->v = 0;
}

Dijkstra::Dijkstra(int n, int v, int* dist, int* prev, int** c) {
	this->c = c;
	this->dist = dist;
	this->n = n;
	this->prev = prev;
	this->v = v;
}

void Dijkstra::dijkstra() {
	bool* s = new bool[n];
	for (int i = 0; i < n; i++) {
		dist[i] = c[v][i];
		s[i] = false;
		if (dist[i] == MAXINT) {
			prev[i] = 0;
		}
		else{
			prev[i] = v;
		}
	}
	dist[v] = 0; s[v] = true;
	for (int i = 0; i < n; i++) {
		int temp = MAXINT;
		int u = v;
		for (int j = 1; j < n; j++) {
			if ((!s[j]) && (dist[j] < temp)) {
				u = j;
				temp = dist[j];
			}
			s[u] = true;
			for (int j = 0; j < n; j++) {
				if ((!s[j]) && (c[u][j] < MAXINT)) {
					int newDist = dist[u] + c[u][j];
					if (newDist < dist[j]) {
						dist[j] = newDist;
						prev[j] = u;
					}
				}
			}
		}
	}
}

void findDijkstraAnswer() {
	cout << "算法4（Dijkstra）单源最短路径问题:" << endl;
	Dijkstra* d = new Dijkstra();
	d->dijkstra();
	cout << "到点5的最短长度为：" << d->dist[4] << endl;
}

void findDijkstraAnswer(int n, int v, int* dist, int* prev, int** c) {
	cout << "算法4（Dijkstra）单源最短路径问题:" << endl;
	Dijkstra* d = new Dijkstra(n, v, dist, prev, c);
	d->dijkstra();
	cout << "到点" << d->v << "的最短长度为：" << d->dist[d->v-1] << endl;
}

int main(){
	
	findDijkstraAnswer();
	return 0;
}

