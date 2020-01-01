#include "Queen.h"
#include "RandomNumber.h"
#include <iostream>
using namespace std;
bool nQueen(int n){
     // 与回溯法结合的解n后问题的拉斯维加斯算法
     Queen X;
    // 初始化X
    X.n = n;
    int *p = new int[n+1];
    int *q = new int[n+1];
    for(int i=0; i<=n; ++i){
       p[i] = 0;
       q[i] = 0;
    }
    X.y = q;
    X.x = p;
   // 设置随机放置皇后的个数
    int stop = 8;
    if(n > 15)
      stop = n-15;
    bool found = false;
    while(! X.QueensLV(stop));
     // 算法的回溯搜索部分
   if(X.Backtrack(stop+1)){
       for(int i=1; i<=n; ++i)
       cout << p[i] << " ";
       found = true;
    }
    cout << endl;
    delete [] p;
    delete [] q;
    return found;
}
int main()
{
    nQueen(8);
}

