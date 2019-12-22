#include <iostream>    
#include <cmath>     
#include <time.h>
    
using namespace std;    
 

#include <iostream> 
#include <ctime>
#include "time.h" 
using namespace std;
 
//随机数类  
const unsigned long maxshort = 65536L;  
const unsigned long multiplier = 1194211693L;  
const unsigned long adder = 12345L;  
class RandomNumber  
{  
private:  
    //当前种子  
    unsigned long randSeed;  
public:  
    RandomNumber(unsigned long s=0);//构造函数，默认值0表示由系统自动产生种子  
    unsigned short Random(unsigned long n);//产生0：n-1之间的随机整数  
    double fRandom(void);//产生[0,1)之间的随机实数  
};  
  
RandomNumber::RandomNumber(unsigned long s)//产生种子  
{  
    if(s==0)  
        randSeed = time(0);//用系统时间产生种子  
    else  
        randSeed = s;//由用户提供种子  
}  
unsigned short RandomNumber::Random(unsigned long n)//产生0：n-1之间的随机整数  
{  
    randSeed=multiplier*randSeed+adder;  
    return (unsigned short)((randSeed>>16) % n);  
}  
double RandomNumber::fRandom(void)//产生[0,1)之间的随机实数  
{  
    return Random(maxshort) / double(maxshort);  
}  
 
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
{
    RandomNumber rnd;  
    int k=1; 
    int count=1;  

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
            x[k++]=y[rnd.Random(count)];
    }  
    return (count>0); 
}  
  
bool nQueen(int n,int sv)  
{  
    
    Queen X;  
    //初始化X  
    X.n=n;  
    //X.sv=sv;
    int *p=new int[n+1]; 
    int *q=new int[n+1];  
    for(int i=0;i<=n;i++)   
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
 
//    system("pause");  
    return 0;  
}  
