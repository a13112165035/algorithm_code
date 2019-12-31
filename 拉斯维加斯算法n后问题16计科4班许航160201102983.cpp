//拉斯维加斯算法n后问题
//xuhang 

#include <iostream>
using namespace std;
const unsigned long maxshort = 65535L;
const unsigned long multiplier = 1194211693L;
const unsigned long adder = 12345L;
#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H
class RandomNumber{
private:
    // 当前种子
    unsigned long randSeed;
public:
    // 构造函数,默认值0表示由系统自动产生种子
    RandomNumber(unsigned long s = 0);
    // 产生0 ~ n-1之间的随机整数
    unsigned short Random(unsigned long n);
    // 产生[0, 1) 之间的随机实数
    double fRandom();
};

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

bool Queen::QueensLV(int stopVegas){
    
     RandomNumber rnd;    
     int k = 1;           
     int count = 1;

     while((k <= stopVegas) && (count > 0)){
         count = 0;
         for(int i = 1; i<=n; ++i)      
         {
             x[k] = i;
             if(Place(k))
                y[count++] = i;
         }
         if(count > 0)                   
             x[k++] = y[rnd.Random(count)];   
     }
     return (count > 0);   
}


bool nQueen(int n){
     
     Queen X;
   
    X.n = n;
    int *p = new int[n+1];
    int *q = new int[n+1];
    for(int i=0; i<=n; ++i){
       p[i] = 0;
       q[i] = 0;
    }
    X.y = q;
    X.x = p;
   
    int stop = 8;
    if(n > 15)
      stop = n-15;
    bool found = false;
    while(! X.QueensLV(stop));
 
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