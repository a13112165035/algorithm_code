	#include <cmath>  
	#include <iostream>  
	#include <stdlib.h>
	#include "time.h"
	using namespace std;  
	const unsigned long maxshort = 65536L;  
	const unsigned long multiplier = 1194211693L;  
	const unsigned long adder = 12345L;  
	  
	class RandomNumber  
	{  
	    private:  
	          
	        unsigned long randSeed;  
	    public:  
	        RandomNumber(unsigned long s = 0); 
	        unsigned short Random(unsigned long n);//产生0：n-1之间的随机整数  
	        double fRandom(void);
	};  
	  
	RandomNumber::RandomNumber(unsigned long s)//产生种子  
	{  
	    if(s == 0)  
	    {  
	        randSeed = time(0);
	    }  
	    else  
	    {  
	        randSeed = s;
	    }  
	}  
	  
	unsigned short RandomNumber::Random(unsigned long n)
	{  
	    randSeed = multiplier * randSeed + adder;
	    return (unsigned short)((randSeed>>16)%n);  
	}  
	  
	double RandomNumber::fRandom(void) 
	{  
	    return Random(maxshort)/double(maxshort);  
	} 
	
	class Queen  
	{  
	    friend void nQueen(int);  
	    private:  
	        bool Place(int k);      //判断皇后k合法性  
	        bool QueensLv(void);    //拉斯维加斯算法  
	        int n;                  //皇后数  
	        int *x,*y; 
	};  
	  
	//测试皇后k合法性  
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
	    RandomNumber rnd;       
	    int k = 1;              
	    int count = 1;            
	  
	    while((k<=n)&&(count>0))  
	    {  
	        count = 0;  
	        for(int i=1; i<=n; i++)  
	        {  
	            x[k] = i; 
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
	  
	    return (count>0);
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
	    int n=8;    
	    cout<<n<<"皇后问题的解为："<<endl;    
	    nQueen(n);   
	    return 0;    
	}  
