#include <iostream>
using namespace std;
class Graph
{

	friend void main(void);
public:
	void Short(int);
private:
	int n,
		* prev;
	int **c,
		* dist;
};
class Min {
	friend Graph;
public:
	operator int()const { return length; }
private:
	int i;
	int length;
};

void Graph::Short(int v) {
	
	Min E;
	E.i = v;
	E.length = 0;
	dist[v] = 0;
	while (true)
	{
		for (int j = 1; j <= n; j++) {
if((c[E.i][j]<100)&&(E.length+c[E.i][j]<dist[j])){
	dist[j] = E.length + c[E.i][j];
	prev[j] = E.i;
	Min N;
	N.i = j;
	N.length = dist[j];
	
	
}

	}

	}

}
