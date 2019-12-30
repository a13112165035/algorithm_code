#include <iostream>    
#include <cmath>     
#include <time.h>
#include "RandomNumber.h"     
using namespace std;    
  
class Queen  
{  
    friend bool nQueen(int,int);  
private:  
    bool Place(int k);//测试皇后k置于第x[k]列的合法性  
    bool Backtrack(int t);//解n后问题的回溯法  
    bool QueensLV(int stopVegas);//随机放置n个皇后拉斯维加斯算法  
    int n,*x,*y,sv;  
};  
  
bool Queen::Place(int k)  
{//测试皇后k置于第x[k]列的合法性 (第k行,第x[k]列) 
    for(int j=1;j<k;j++)  
        if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k])) //同一斜线||同一列 
            return false;  
    return true;  
}  
 
bool Queen::Backtrack(int t)  
{//解n后问题的回溯法，回溯尝试皇后位置，t为第t行 
    if(t>n){  //放置皇后个数超过n时候 ，可行解个数+1 
        for(int i=1;i<=n;i++)  
            y[i]=x[i];  
        return true;  
    }  
    else  
        for(int i=1;i<=n;i++)  
        {  
            x[t]=i;  //第t个皇后放在第i列 
            if(Place(t)&&Backtrack(t+1)) //可以place，就继续放下一个 
                return true;  
        }  
        return false;  
}  
  
bool Queen::QueensLV(int stopVegas)  
{//随机放置n个皇后拉斯维加斯算法  
    RandomNumber rnd;  
    int k=1;//随机数产生器  
    int count=1;  
    //1<=stopVegas<=n表示允许随机放置的皇后数  
    while((k<=stopVegas)&&(count>0))  
    {  
        count=0;  
        for(int i=1;i<=n;i++)  
        {  
            x[k]=i;  
            if(Place(k))  
                y[count++]=i;  //记录下所有可以放置的位置 
        }  
        if(count>0)  
            x[k++]=y[rnd.Random(count)];//如果能放置，随机选择一个可以放置的位置  
    }  
    return (count>0);//count>0表示放置成功  
}  
  
bool nQueen(int n,int sv)  
{  
    //与回溯法相结合的解n后问题的拉斯维加斯算法  
    Queen X;  
    //初始化X  
    X.n=n;  
    //X.sv=sv;
    int *p=new int[n+1];  //动态分配 
    int *q=new int[n+1];  
    for(int i=0;i<=n;i++)  //初始化数组 
    {  
        p[i]=0;  
        q[i]=0;  
    }  
    X.y=p;  
    X.x=q;  
    int stop=sv;  
    if(n>15)  
        stop=n-15;  
    bool found=false;  
    while(!X.QueensLV(stop));  
    //算法的回溯搜索部分  
    if(X.Backtrack(stop+1))  
    {  
        for(int i=1;i<=n;i++)  
            cout<<p[i]<<" ";  
        found=true;  
    }  
    cout<<endl;  
    delete []p;  
    delete []q;  
    return found;  
}  