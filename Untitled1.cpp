#include <iostream>
 using namespace std;
 int main() {
 	bool s[100];
 	int c[4][4] = { {100,10,100,30}, {100,100,50.100}, {100,100,100,10}, {100.100,20,100} };
 	int n = 4;
 	int v = 1;
 	int dist[6];
 	int prev[6];
 	for (int i = 1; i <= n; i++) {
 		dist[i] = c[v][i];
 		s[i] = false;
 		if (dist[i] == 100) {
 			prev[i] = 0;

 		}
 		else
 			prev[i] = v;
 	}
 		dist[v] = 0; s[v] = true;
 		for (int i = 1; i < n; i++)
 		{
 			int temp = 100;
 			int u = v;
 			for (int j = 1; j < n; j++)
 			{
 				if ((!s[j]) && (dist[j] < temp)) {
 					u = j;
 					temp = dist[j];
 				}
 			}
 			s[u] = true;
 			for (int j = 1; j < n; j++)
 			{
 				if ((!s[j]) && (c[u][j] < 100))
 				{
 					int newdist = dist[u] + c[u][j];
 					if (newdist < dist[j]) {
 						dist[j] = newdist;
 						prev[j] = u;
 					}
 				}
 			}
 		}for(int i = 1; i < n; i++){
 		cout << prev[i];}
 		return 0;
 	}
