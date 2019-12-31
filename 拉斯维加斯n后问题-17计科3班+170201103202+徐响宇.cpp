//P226随机化算法 拉斯维加斯算法 n后问题
#include<bits/stdc++.h>
#include "RandomNumber.h"
#include <cmath>
#include <iostream>
using namespace std;

class Queen
{
	friend void nQueen(int);
	private:
		bool Place(int k);		//测试皇后k置于第x[k]列的合法性
		bool QueensLv(void);	//随机放置n个皇后拉斯维加斯算法
		int n;					//皇后个数
		int *x,*y;				//解向量
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
	RandomNumber rnd;		//随机数产生器
	int k = 1;				//下一个皇后的编号
	int count = 1;			//在一列中，可以放置皇后的个数
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
		}		if(count>0)
		{
			x[k++] = y[rnd.Random(count)];		//随机位置
		}
	}
	return (count>0);		//count>0 表示放置成功
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
	int n=8;  
    cout<<n<<"皇后问题的解为："<<endl;  
    nQueen(n);  
    return 0;  
}

