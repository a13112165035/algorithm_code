//P226������㷨 ��˹ά��˹�㷨 n������
#include<bits/stdc++.h>
#include "RandomNumber.h"
#include <cmath>
#include <iostream>
using namespace std;

class Queen
{
	friend void nQueen(int);
	private:
		bool Place(int k);		//���Իʺ�k���ڵ�x[k]�еĺϷ���
		bool QueensLv(void);	//�������n���ʺ���˹ά��˹�㷨
		int n;					//�ʺ����
		int *x,*y;				//������
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
	RandomNumber rnd;		//�����������
	int k = 1;				//��һ���ʺ�ı��
	int count = 1;			//��һ���У����Է��ûʺ�ĸ���
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
		}		if(count>0)
		{
			x[k++] = y[rnd.Random(count)];		//���λ��
		}
	}
	return (count>0);		//count>0 ��ʾ���óɹ�
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
	int n=8;  
    cout<<n<<"�ʺ�����Ľ�Ϊ��"<<endl;  
    nQueen(n);  
    return 0;  
}

