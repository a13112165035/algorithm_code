#include<iostream> 
#include<stdlib.h>

using namespace std;

class Queen
{
	friend void nQueen(int);
private:

	bool Place(int k);//�жϻʺ�λ���Ƿ�Ϸ� 

	
	bool QueensLV(void);
	int n, 
		*x, *y; 
};

bool Queen::Place(int k)
{
	for(int j=1; j<k; j++)
		if((abs(k-j) == abs(x[j]-x[k])) || (x[j] == x[k]))  
			return false;
	
	return true;
} 

bool Queen::QueensLV(void)
{
	int k = 1;  
	int count = 1;   
	
	while((k<=n) && (count>0)) 
	{
		count = 0; 
		
		for(int i=1; i<=n; i++) 
		{
			x[k] = i; 
			if(Place(k))
				y[count++] = i;
		}
		
		if(count>0)
			x[k++] = y[rand()%count]; //�ӺϷ�λ�����ѡȡһ�� 
	} 
	
	return (count>0);  
}

void nQueen(int n)
{
	Queen X;
	X.n = n;
	int *x = new int[n+1];
	int *y = new int[n+1];
	
	for(int i=0; i<=n; i++)
	{
		x[i] = 0;
		y[i] = 0;
	} 
	
	X.x = x;
	X.y = y;
	
	while(!X.QueensLV());
	
	for(int i=1; i<=n; i++)
	    
		cout<<"��"<<i<<"�е�"<<X.x[i]<<"��"<<endl;
	
	delete[] x;
	delete[] y;
}

int main()
{
	int n = 5; 
	cout<<"�ʺ��ܷ��ڣ�"<<endl;
	nQueen(n);
	
	return 0; 
}

