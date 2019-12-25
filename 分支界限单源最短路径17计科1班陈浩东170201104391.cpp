#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
 
struct Node{
    int i;
    int length;
    friend bool operator<(Node a, Node b) {
        return a.length > b.length;
    }
};
priority_queue < Node > q;
int c[10][10];
int n;
const  int INF = 1 << 30;
int dist[10];
int pre[10];
void graphShortestPath(int v){
    Node E;
    E.i = v;
    E.length = 0;
    dist[v] = 0;
    q.push(E);
    while (1){
        for (int j = 1; j <= n; ++j) {
            if ( (c[E.i][j] < INF ) && (E.length + c[E.i][j] < dist[j]) ){
                dist[j] = c[E.i][j] + E.length;
                pre[j] = E.i;
                Node temp;
                temp.i = j;
                temp.length = dist[j];
               
                q.push(temp);
            }
        }

        if (q.empty())break;
        q.pop();
        E = q.top();
        
    }
}
int main(){
    int m;
    n = 3;
    m = 3;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) c[i][j] = 0;
            else c[i][j] = INF;
        }
    }
    for (int k = 1; k <= m; ++k) {
        int t1,t2,t3;
        cin >> t1 >> t2 >>t3;
        c[t1][t2] = t3;
    }
    for (int l = 0; l < 10; ++l) {
        dist[l] = INF;
        pre[l] = 0;
    }
    graphShortestPath(1);
    for (int i1 = 1; i1 <= n; ++i1) {
        cout << dist[i1] <<" " ;
    }
    return 0;
}

