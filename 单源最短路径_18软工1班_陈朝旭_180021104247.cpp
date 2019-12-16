#include <iostream>
using namespace std;
const int N = 500;
const int inf = 999999999;
int e[N][N];
int book[N];
int dis[N];

int main()
{
    int n, m, s;  
    cin >> n >> m>> s;
    for(int i = 1; i <= n; i++)
    {
        dis[i] = inf;   
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
            {
                e[i][j] = 0;
            }
            else
            {
                e[i][j] = inf;
            }
        }
    }
    int x, y, w;    
    for(int i = 1; i <= m; i++) 
    {
        cin >> x >> y >> w;
        e[x][y] = e[y][x] = w;
    }
    dis[s] = 0;

    for(int i = 1; i <= n - 1; i++) 
    {
        int min = inf;   
        int u;  
        for(int j = 1; j <= n; j++) 
        {
            if(book[j] == 0 && dis[j] < min)
            {
                min = dis[j];
                u = j;
            }
        }
        book[u] = 1;    
        for(int k = 1; k <= n; k++) 
        {
            if(e[u][k] < inf)
            {
                if(dis[k] > dis[u] + e[u][k])
                {
                    dis[k] = dis[u] + e[u][k]; 
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) 
    {
        cout.width(-5);
        cout << dis[i] << " ";
    }
    cout << endl;
    return 0;
}
