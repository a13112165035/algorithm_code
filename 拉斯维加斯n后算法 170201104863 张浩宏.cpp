#include <cmath>  
#include <iostream>  
#include<stdlib.h>
#include"time.h" 
using namespace std;  
	 
	//随机数类  
	const unsigned long maxshort = 65536L;  
	const unsigned long multiplier = 1194211693L;  
	const unsigned long adder = 12345L;  
	  
	class RandomNumber  
	{  
	    private:  
	        
	        unsigned long randSeed;  
	    public:  
	        RandomNumber(unsigned long s = 0);
	        unsigned short Random(unsigned long n);
	        double fRandom(void);
	};  
	  
	RandomNumber::RandomNumber(unsigned long s)
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
	
class Queen{
	friend void nQueen(int);
private:
	bool Place(int k);
	bool QueensLV(void);
	int n,
		*x,*y;
};

bool Queen::Place(int k){
	for(int j=1;j<k;j++){
		if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k]))
		return false;
	}
	return true;
}

bool Queen::QueensLV(void){
	RandomNumber rnd;
	int k=1;
	int count=1;
	while((k<=n)&&(count>0)){
		count=0;
		for(int i=1;i<=n;i++){
			x[k]=i;
			if(Place(k))
				y[count++]=i;
		}
			if(count>0)
				x[k++]=y[rnd.Random(count)];
		}
			return (count>0);	
	
}

void nQueen(int n){
	Queen X;
	X.n=n;
	int *p=new int [n+1];
	for(int i=1;i<=n;i++)
		p[i]=0;
	X.x=p;
	
	while(!X.QueensLV());
	for(int i=1;i<=n;i++)
		cout<<p[i]<<"";
	cout<<endl;
	delete[] p; 
}

int main(){
		int n=5;    
	    cout<<n<<"皇后问题的解为："<<endl;    
	    nQueen(n);
	    return 0;
}
