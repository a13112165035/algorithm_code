#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

class RandomNumber
{
public:
	int Random(int);
};

int RandomNumber::Random(int count)
{	
    srand(time(NULL)+count);
	return (rand()%(count));
}

class Queen
{
	friend void nQueen(int);
private:
	bool Place(int k); //合法性检测
	bool QueensLV(); //随机放置n个皇后的拉斯维加斯算法
	int n,*x,*y;//皇后个数n，解向量xy 
};

bool Queen::Place(int k)
{
	for(int j=1;j<k;j++)
       if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k])) return false;
    
	return true;     
}

bool Queen::QueensLV()
{
	RandomNumber rnd;
	int k=1,count=1;
	while((k<=n)&&(count>0))
	{
		count=0;
		for(int i=1;i<=n;i++) //第一列到第n列 
		{
			x[k]=i;//k表示第k行，x[k]表示第x[k]列 
			if(Place(k)) y[count++]=i;
		}
		if(count>0) x[k++]=y[rnd.Random(count)];
	}
	return (count>0);    //表示放置成功 
}

void nQueen(int n)
{
	Queen X;
	X.n=n;
	int *p= new int[n+1];
	for(int i=0;i<=n;i++) p[i]=0;
	X.x=p;
	while(!X.QueensLV());//反复调用直到成功跳出循环
	//for(int i=1;i<=n;i++) cout<<p[i]<<" ";
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			cout<<" ";
		    for(int j=1;j<=n;j++) cout<<"     "<<j;
		}	        	       
	    cout<<endl<<endl<<i<<"     "; 
	    {
	    	for(int j=1;j<=n;j++)
	    	{
	    		if(p[i]==j) cout<<"O"<<endl;
	    		else if(p[i]==0) 
				{
				   cout<<endl;
				   break;
				}
	    		else cout<<"      ";
	    		
			}	    	
		}	   
	}
	cout<<endl;
	delete[] p;	
}

int main()
{
/*	int n;
    do
	{
	   cout<<"请输入n=";
	   cin>>n;
	   cout<<"对于"<<n<<"后问题其中一个解如下(没做随机优化4~6最好)"<<endl; 
	   
	   cout<<endl;
	}while(n>0);*/
	cout<<"对于5后问题其中一个解如下"<<endl;
    nQueen(5);
	return 0;
}
