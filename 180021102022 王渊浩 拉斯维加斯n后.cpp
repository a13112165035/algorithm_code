#include <iostream>  
#include <cmath>   
#include "RandomNumber.h"   
using namespace std;  

class Queen
{
    friend bool nQueen(int);
private:
    bool Place(int k);//测试皇后k置于第x[k]列的合法性
    bool Backtrack(int t);//解n后问题的回溯法
    bool QueensLV(int stopVegas);//随机放置n个皇后拉斯维加斯算法
    int n,*x,*y;
};

bool Queen::Place(int k)
{//测试皇后k置于第x[k]列的合法性
    for(int j=1;j<k;j++)
        if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k]))
            return false;
    return true;
}

bool Queen::Backtrack(int t)
{//解n后问题的回溯法
    if(t>n){
        for(int i=1;i<=n;i++)
            y[i]=x[i];
        return true;
    }
    else
        for(int i=1;i<=n;i++)
        {
            x[t]=i;
            if(Place(t)&&Backtrack(t+1))
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
                y[count++]=i;
        }
        if(count>0)
            x[k++]=y[rnd.Random(count)];//随机位置
    }
    return (count>0);//count>0表示放置成功
}

bool nQueen(int n)
{
    //与回溯法相结合的解n后问题的拉斯维加斯算法
    Queen X;
    //初始化X
    X.n=n;
    int *p=new int[n+1];
    int *q=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        p[i]=0;
        q[i]=0;
    }
    X.y=p;
    X.x=q;
    int stop=2;
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

int main()  
{   
    if(!nQueen(8))
    {
        cout<<"搜索不成功！！"<<endl;
    }
    system("pause");
    return 0;
}  
