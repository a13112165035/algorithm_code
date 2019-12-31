#include <iostream>    
#include <cmath>     
#include <time.h>
#include "RandomNumber.h"     
using namespace std;    
  
class Queen  
{  
    friend bool nQueen(int,int);  
private:  
    bool Place(int k);
    bool Backtrack(int t);
    bool QueensLV(int stopVegas);
    int n,*x,*y,sv;  
};  
  
bool Queen::Place(int k)  
{
    for(int j=1;j<k;j++)  
        if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k]))
            return false;  
    return true;  
}  
 
bool Queen::Backtrack(int t)  
{
    if(t>n)
	{
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
{
    RandomNumber rnd;  
    int k=1;//随机数产生器  
    int count=1;  
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
    Queen X;  
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
int main()    
{   
    int n,sv;
    cout<<"输入皇后个数n 和 stopVrgas值"<<endl; 
	while(cin>>n>>sv){
	
	   clock_t start,end,over;
       start=clock();
       end=clock();
       over=end-start;
       start=clock();
    
       if(!nQueen(n,sv))  
       {  
           cout<<"No Answer"<<endl;  
       }  
	
      	end=clock();
      	cout<<"The time is "<<(double)(end-start-over)/CLK_TCK<<endl;    
        cout<<endl;	
		
	} 
    return 0;  
}
