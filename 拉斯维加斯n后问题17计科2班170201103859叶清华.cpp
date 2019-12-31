#include<iostream> 
#include <cmath>
#include "math.h" 
#include "randomnumber.h" 
using namespace std;
class Queen 
{ 
	friend void nQueen(int); 
private: 
	bool Place(int k); //测试皇后 k 置于第 x[k]列的合法性 
	bool QueensLV(void); //随机放置 n 个皇后拉斯维加斯算法 
	int n, //皇后个数 
	*x,y[1000]; //解向量 
};
bool Queen::Place(int k) //Place(k)用于测试将皇后 k 置于第 x[k]列的合法性 
{ 
	for(int j=1;j<k;j++) 
		if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k])) 
			return false; 
		return true; 
}
bool Queen::QueensLV(void) //QueensLV(void)实现在棋盘上随机放置 n 个皇后拉 斯维加斯算法 
{ 
	RandomNumber rnd; //随机数产生器 
	int k=1; //下一个放置的皇后编号 
	int count=1; 
	while((k<=n)&&(count>0)) 
	{ 
		count=0; 
		for(int i=1;i<=n;i++) 
		{ 
			x[k]=i; 
			if(Place(k)) 
				y[count++]=i; 
		} 
		if(count>0) x[k++]=y[rnd.Random(count)];//随机位置 
	} 
	return (count>0); //count>0 表示放置成功
}
void nQueen(int n) //解 n 后问题的拉斯维加斯算法 
{ 
	Queen X; //初始化 
	X.n=n; 
	int * p=new int[n+1]; 
	for(int i=0;i<=n;i++) 
		p[i]=0; 
	X.x=p; //反复调用随机放置 n 个皇后拉斯维加斯算法，直至放置成功 
	while(X.QueensLV()) 
	{ 
		cout<<"结果是："<<endl; 
		for(int i=1;i<=n;i++) 
		{ 
			for(int j=1;j<=n;j++) 
			{ 
				if(j==p[i]) 
					cout<<"Q"<<" "; 
				if(j!=p[i]) 
					cout<<"*"<<" "; 
			} 
			cout<<endl; 
		} 
		break; 
	} 
	delete []p; 
}
int main() 
{ 
	int n; 
	cout<<"输入皇后个数:"<<endl; 
	cin>>n; 
	nQueen(n); 
	
	return 0; 
}
