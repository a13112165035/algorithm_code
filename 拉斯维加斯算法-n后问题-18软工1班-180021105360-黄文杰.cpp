//随机化算法 拉斯维加斯算法 n后问题  

//#include "RandomNumber.h"  
#include <cmath>  
#include <iostream>  
#include<stdlib.h>
using namespace std;


// "RandomNumber.h"
#include"time.h"
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
	    RandomNumber(unsigned long s = 0);//构造函数，默认值0表示由系统自动产生种子  
	    unsigned short Random(unsigned long n);//产生0：n-1之间的随机整数  
	    double fRandom(void);//产生[0,1)之间的随机实数  
};  
	  
RandomNumber::RandomNumber(unsigned long s)//产生种子  
{  
	if(s == 0)  
	{  
	    randSeed = time(0);//用系统时间产生种子  
	}  
	else  
	{  
	    randSeed = s;//由用户提供种子  
	}  
}  
	  
unsigned short RandomNumber::Random(unsigned long n)//产生0：n-1之间的随机整数  
{  
	randSeed = multiplier * randSeed + adder;//线性同余式  
	return (unsigned short)((randSeed>>16)%n);  
}  
	  
double RandomNumber::fRandom(void)//产生[0,1)之间的随机实数  
{  
	return Random(maxshort)/double(maxshort);  
} 
  


	  
class Queen  
{  
	friend void nQueen(int);  
	private:  
	    bool Place(int k);      //测试皇后k置于第x[k]列的合法性  
	    bool QueensLv(void);    //随机放置n个皇后拉斯维加斯算法  
	    int n;                  //皇后个数  
	    int *x,*y;              //解向量  
};  
	  
//测试皇后k置于第x[k]列的合法性  
bool Queen::Place(int k)  
{  
	for(int j=1; j<k; j++)  
	{  
	    if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k]))  
	    {  
	        return false;  
	    }  
	}  
	return true;  
}  
	  
	//随机放置n个皇后的拉斯维加斯算法  
bool Queen::QueensLv(void)  
{  
	RandomNumber rnd;       //随机数产生器  
	int k = 1;              //下一个皇后的编号  
	int count = 1;          //在一列中，可以放置皇后的个数  
	  
	while((k<=n)&&(count>0))  
	{  
	    count = 0;  
	    for(int i=1; i<=n; i++)  
	    {  
	        x[k] = i;//位置  
	        if(Place(k))  
	        {  
	            y[count++] = i;  
	        }  
	    }  
	    if(count>0)  
	    {  
	        x[k++] = y[rnd.Random(count)];      //随机位置  
	    }  
	}  
	  
	return (count>0);        //count>0 表示放置成功  
}  
	  
	//解n后问题的拉斯维加斯算法  
void nQueen(int n)  
{  
	Queen X;  
	X.n = n;  
	  
	int *p = new int[n+1];  
	for(int i=0; i<=n; i++)  
	{  
	    p[i] = 0;  
	}  
	X.x = p;  
	X.y = new int[n+1];  
	  
	//反复调用随机放置n个皇后的拉斯维加斯算法，直到放置成功  
	while(!X.QueensLv());  
	  
	for(int i=1; i<=n; i++)  
	{  
	    cout<<p[i]<<" "; 	 
	}  
	cout<<endl;  
	delete []p;  
}  
	  
int main()  
{  
	int n;
	cout<<"请输入皇后的个数n:"<<endl; 
	cin>>n;
	cout<<n<<"皇后问题的解为:"<<endl;
	nQueen(n);     
	system("pause");   
	return 0;    
}  

