const unsigned long maxshort = 65535L;
const unsigned long multiplier = 1194211693L;
const unsigned long adder = 12345L;
#define RANDOMNUMBER_H
#define QUEEN_H 
#include"time.h"
#include "stdlib.h"

#include <iostream>
using namespace std;

class RandomNumber{
public:    // ��ǰ����    
	unsigned long randSeed;
public:    // ���캯��,Ĭ��ֵ0��ʾ��ϵͳ�Զ���������    
	RandomNumber(unsigned long s = 0);    // ����0 ~ n-1֮����������    
	unsigned short Random(unsigned long n);    // ����[0, 1) ֮������ʵ��    
	double fRandom();
};

RandomNumber::RandomNumber(unsigned long s)//��������??
{
	if(s==0)
	{	
	randSeed=time(0);//��ϵͳʱ���������
	}
	else
	{
	randSeed=s;//���û��ṩ����
	}
}

unsigned short RandomNumber::Random(unsigned long n)//����0��n-1֮����������??
{
	randSeed=multiplier*randSeed+adder;//����ͬ��ʽ
	return (unsigned short)((randSeed>>16)%n);
}
double RandomNumber::fRandom(void)//����[0,1)֮������ʵ��??
{
	return Random(maxshort)/double(maxshort);
}

class Queen
{	
	friend bool nQueen(int);
	private:	
		bool Place(int k);             
		// ���Իʺ�k���ڵ�x[k]�еĺϷ���	
		bool Backtrack(int t);         
		// ��n������Ļ��ݷ�	
		bool QueensLV(int stopVegas);  
		// �������n���ʺ���˹ά��˹�㷨	
		int n, *x, *y;
}; 

bool Queen::Place(int k){    
	// ���Իʺ�k���ڵ�x[k]�еĺϷ���    
	for(int j = 1; j < k; ++ j)        
	if((abs(k-j) == abs(x[j]-x[k])) || (x[j]==x[k]))
		return false;    
		return true;
} 

bool Queen::Backtrack(int t)
{     // ��n������Ļ��ݷ�    
	if(t > n)
	{        
		for(int i=1; i<=n; ++i)            
		y[i] = x[i];        
		return true;    
		}
	else       
		for(int i=1; i<=n; ++i)
		{           
			x[t] = i;           
			if(Place(t) && Backtrack(t+1))                
			return true;       
			}    
		return false;
}

bool Queen::QueensLV(int stopVegas){     
	// �������n���ʺ����˹ά��˹�㷨     
	RandomNumber rnd;    // �����������     
	int k = 1;           // ��һ�����õĻʺ���     
	int count = 1;     // 1 <= stopVegas <= n ��ʾ����������õĻʺ���     
	while((k <= stopVegas) && (count > 0)){         
		count = 0;         
		for(int i = 1; i<=n; ++i)      // ----------- ��         
		{             
			x[k] = i;             
			if(Place(k))                
				y[count++] = i;         
		}         
		if(count > 0)                   // -------------��             
			x[k++] = y[rnd.Random(count)];   // ���λ��     
	}     
	return (count > 0);   // count > 0��ʾ����λ�óɹ�
}


bool nQueen(int n){     
	// ����ݷ���ϵĽ�n���������˹ά��˹�㷨     
	Queen X;    // ��ʼ��X    
	X.n = n;    
	int *p = new int[n+1];    
	int *q = new int[n+1];    
	for(int i=0; i<=n; ++i)
	{       
		p[i] = 0;       
		q[i] = 0;    
	}   
	X.y = q;    
	X.x = p;   // ����������ûʺ�ĸ���    
	int stop = 8;    
	if(n > 15)      
		stop = n-15;    
	bool found = false;    
	while(! X.QueensLV(stop));     // �㷨�Ļ�����������   
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

int main(){    
	nQueen(8);
	return 0; 
}
