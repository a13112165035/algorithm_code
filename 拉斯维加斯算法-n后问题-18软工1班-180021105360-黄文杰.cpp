//������㷨 ��˹ά��˹�㷨 n������  

//#include "RandomNumber.h"  
#include <cmath>  
#include <iostream>  
#include<stdlib.h>
using namespace std;


// "RandomNumber.h"
#include"time.h"
//�������  
const unsigned long maxshort = 65536L;  
const unsigned long multiplier = 1194211693L;  
const unsigned long adder = 12345L;  
	  
class RandomNumber  
{  
	private:  
	    //��ǰ����  
	    unsigned long randSeed;  
	public:  
	    RandomNumber(unsigned long s = 0);//���캯����Ĭ��ֵ0��ʾ��ϵͳ�Զ���������  
	    unsigned short Random(unsigned long n);//����0��n-1֮����������  
	    double fRandom(void);//����[0,1)֮������ʵ��  
};  
	  
RandomNumber::RandomNumber(unsigned long s)//��������  
{  
	if(s == 0)  
	{  
	    randSeed = time(0);//��ϵͳʱ���������  
	}  
	else  
	{  
	    randSeed = s;//���û��ṩ����  
	}  
}  
	  
unsigned short RandomNumber::Random(unsigned long n)//����0��n-1֮����������  
{  
	randSeed = multiplier * randSeed + adder;//����ͬ��ʽ  
	return (unsigned short)((randSeed>>16)%n);  
}  
	  
double RandomNumber::fRandom(void)//����[0,1)֮������ʵ��  
{  
	return Random(maxshort)/double(maxshort);  
} 
  


	  
class Queen  
{  
	friend void nQueen(int);  
	private:  
	    bool Place(int k);      //���Իʺ�k���ڵ�x[k]�еĺϷ���  
	    bool QueensLv(void);    //�������n���ʺ���˹ά��˹�㷨  
	    int n;                  //�ʺ����  
	    int *x,*y;              //������  
};  
	  
//���Իʺ�k���ڵ�x[k]�еĺϷ���  
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
	  
	//�������n���ʺ����˹ά��˹�㷨  
bool Queen::QueensLv(void)  
{  
	RandomNumber rnd;       //�����������  
	int k = 1;              //��һ���ʺ�ı��  
	int count = 1;          //��һ���У����Է��ûʺ�ĸ���  
	  
	while((k<=n)&&(count>0))  
	{  
	    count = 0;  
	    for(int i=1; i<=n; i++)  
	    {  
	        x[k] = i;//λ��  
	        if(Place(k))  
	        {  
	            y[count++] = i;  
	        }  
	    }  
	    if(count>0)  
	    {  
	        x[k++] = y[rnd.Random(count)];      //���λ��  
	    }  
	}  
	  
	return (count>0);        //count>0 ��ʾ���óɹ�  
}  
	  
	//��n���������˹ά��˹�㷨  
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
	  
	//���������������n���ʺ����˹ά��˹�㷨��ֱ�����óɹ�  
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
	cout<<"������ʺ�ĸ���n:"<<endl; 
	cin>>n;
	cout<<n<<"�ʺ�����Ľ�Ϊ:"<<endl;
	nQueen(n);     
	system("pause");   
	return 0;    
}  

