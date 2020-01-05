#ifndef QUEEN_H
#define QUEEN_H
 
class Queen
{
	friend bool nQueen(int);
private:
	bool Place(int k);             // 测试皇后k置于第x[k]列的合法性
	bool Backtrack(int t);         // 解n后问题的回溯法
	bool QueensLV(int stopVegas);  // 随机放置n个皇后拉斯维加斯算法
	int n, *x, *y;
};
 
#endif
 
Queen.cpp文件(算法的关键位置)
 
#include <iostream>
#include "Queen.h"
#include "RandomNumber.h"
using namespace std;
bool Queen::Place(int k){
    // 测试皇后k置于第x[k]列的合法性
    for(int j = 1; j < k; ++ j)
        if((abs(k-j) == abs(x[j]-x[k])) || (x[j]==x[k]))
            return false;
    return true;
}
 
bool Queen::Backtrack(int t){
     // 解n后问题的回溯法
    if(t > n){
        for(int i=1; i<=n; ++i)
            y[i] = x[i];
        return true;
    }else
       for(int i=1; i<=n; ++i){
           x[t] = i;
           if(Place(t) && Backtrack(t+1))
                return true;
       }
    return false;
}
/*
* QueensLV是整个Las Vegas解n皇后的精髓。而且这个函数不好理解，我在这里具体分析下。
* k是第k行，x[k]表示第k行的皇后放在x[k]列
* 下面这两点解析请认真看了，我个人就是卡在这里半天了，但是理解后很简单。
* 标号①处：这里是遍历第k行所有可以放置的列号，用y保存下来，并用count记录有多少个位置可以放置
* 标号②处：这里利用上面保存的可以放置的列，然后随机取其中一列来放置第k行的皇后。这就是Las Vegas的精髓！
*/
bool Queen::QueensLV(int stopVegas){
     // 随机放置n个皇后的拉斯维加斯算法
     RandomNumber rnd;    // 随机数产生器
     int k = 1;           // 下一个放置的皇后编号
     int count = 1;
     // 1 <= stopVegas <= n 表示允许随机放置的皇后数
     while((k <= stopVegas) && (count > 0)){
         count = 0;
         for(int i = 1; i<=n; ++i)      // ----------- ①
         {
             x[k] = i;
             if(Place(k))
                y[count++] = i;
         }
         if(count > 0)                   // -------------②
             x[k++] = y[rnd.Random(count)];   // 随机位置
     }
     return (count > 0);   // count > 0表示放置位置成功
}

