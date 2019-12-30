#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
const unsigned long maxshort=65536L;
const unsigned long multiplier=1194211693L;
const unsigned long adder=12345L;

//详情看课本208页 
class RandomNumber
{
private:
	unsigned long randSeed;//当前种子 
public:
	RandomNumber(unsigned long s=0);//构造函数，默认值0表示由系统自动产生种子 
	unsigned short Random(unsigned long n);//产生0：n-1之间的随机整数 
	double fRandom(void);//产生(0,1)之间的随机实数 
};

// 产生种子
RandomNumber::RandomNumber(unsigned long s)
{
    if(s == 0)
        randSeed = time(0);    //用系统时间产生种子
    else
        randSeed = s;
}

// 产生0 ~ n-1 之间的随机整数
unsigned short RandomNumber::Random(unsigned long n)
{
    randSeed = multiplier * randSeed + adder;
    return (unsigned short)((randSeed >> 16) % n);
}

// 产生[0, 1)之间的随机实数
double RandomNumber::fRandom()
{
    return Random(maxshort) / double(maxshort);
}

class Queen
{
	friend void nQueen(int);
private:
	bool place(int k);//测试皇后k放在第x[k]列的合法性 
//	bool Backtrack(int t);
	bool QueenLV();//随机放置n个皇后的拉斯维加斯算法 
	int n,*x,y[1005];//皇后个数、解向量 
};

bool Queen::place(int k)
{
	for(int j=1;j<k;j++)//行
	{
		if(( abs(k-j)==abs(x[j]-x[k]) ) || (x[j]==x[k]))
		{//斜线或同一列 
			return false;
		}
	}
	return true;
}

bool Queen::QueenLV()
{
	RandomNumber rnd;//随机数产生器
	int k=1;//第一行 
	int count=1;
	while((k<=n) && (count>0))//不超过最后一行 
	{
		count=0;
		for(int i=1;i<=n;i++)//列 
		{
			x[k]=i;
			if(place(k))
				y[count++]=i;//将这一行，k行的所有合理性列记在y中 
		}
		if(count>0)//如果有合理性的列 
			x[k++]=y[rnd.Random(count)];//产生从0到count-1的随机数 
			//就从所有合理性的列中随机拿出一个给x 
	}
	return (count>0);//大于0放置成功 
}

void nQueen(int n)
{
	Queen X;
	//初始化X
	X.n=n;
	int *p=new int[n+1];
	//初始化p 
	for(int i=0;i<=n;i++)
		p[i]=0; 
	X.x=p;//x指针指向p
	//反复调用拉斯维加斯算法，直至出现一种解法
	while(!X.QueenLV());
	for(int i=1;i<=n;i++)
		cout << p[i] << " ";
	cout << endl;
	delete[] p;
}

int main()
{
	cout << "请输入皇后个数：" << endl;
	int num;
	cin >> num;
	nQueen(num);
	return 0;
}
