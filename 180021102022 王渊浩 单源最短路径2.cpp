#define _CRT_SECURE_NO_WARNINGS

#include<math.h>
#include<stdlib.h>
#include<string>
#include<iostream>

using namespace std;

#define MAXINT 1000

// v是源 ， n是顶点数
// dist[i]表示当前从源到顶点i的最短特殊路径长度
// c[i][j]表示（i,j）的权
// s[]记录红点集
void Dijkstra(int n, int v, int dist[], int prev[], int **c) {
	bool s[MAXINT];
	for (int i = 1; i <= n; i++) {
		dist[i] = c[v][i];
		s[i] = false;
		if (dist[i] == MAXINT)
			prev[i] = 0;
		else
			prev[i] = v;
	}
	dist[v] = 0;
	s[v] = true;
	for (int i = 1; i < n; i++) {
		int temp = MAXINT;
		int u = v;
		for (int j = 1; j <= n; j++) {
			if ((!s[j]) && (dist[j] < temp)) {
				u = j;
				temp = dist[j];
			}
		}
		s[u] = true;
		for (int j = 1; j <= n; j++) {
			if ((!s[j]) && (c[u][j]<MAXINT)) {
				int newdist = dist[u] + c[u][j];
				if (newdist < dist[j]) {
					dist[j] = newdist;
					prev[j] = u;
				}
			}
		}

	}

}

//动态分配二维数组
int** get2Array(int row, int column) {
	int** array = (int **)malloc(row * sizeof(int *));
	for (int i = 0; i < row; i++)
	{
		array[i] = (int *)malloc(column * sizeof(int));
	}
	return array;
}

// 产生 带权有向图G
int** createGV() {
	int n = 5;
	int **c= get2Array(6, 6);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (i!=0 && i == j)
				c[i][j] = 0;
			else
				c[i][j] = MAXINT;
		}
	}
	c[1][2] = 10;
	c[1][4] = 30;
	c[1][5] = 100;
	c[2][3] = 50;
	c[3][5] = 10;
	c[4][3] = 20;
	c[4][5] = 60;

	return c;

}

void display(int **c,int row,int column) {
	for (int i = 0; i < row+1; i++) {
		for (int j = 0; j < column+1; j++) {
			if (i == 0) {
				if (j == 0) {
					cout << '\t';

				}
				else
					cout << j << '\t';
			}
			else {
				if (j == 0)
					cout << i << '\t';
				else {
					if (c[i][j] == MAXINT)
						cout << '*' << '\t';
					else
						cout << c[i][j] << '\t';
				}
			}
		}
		cout << endl;
	}
}

int main() {
	int n = 5, v = 1;
	int dist[6];
	int prev[6];
	int **c = createGV();
	display(c, 5, 5);
	Dijkstra(n, v, dist, prev, c);
	cout << "请输入目的地:";
	int destination=0;
	cin >> destination;
	cout << "最短路径长度为：";
	cout << dist[destination] << endl;
	system("pause");
	return 0;
}
