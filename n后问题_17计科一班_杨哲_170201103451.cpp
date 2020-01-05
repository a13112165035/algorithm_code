#include<iostream>
#include<cstdlib>
using namespace std;

class Queen 
{
	friend void nQueen(int);
private:
	bool Place(int k);   	//测试皇后k置于第x[k]列的合法性
	bool QueensLV(void);	//随机放置n个皇后拉斯维加斯算法 
	int n;                  //皇后个数
	int	*x, * y;            //解向量
};

class RandomNumber 
{
public:
	int Random(int count);
};

int RandomNumber::Random(int count)
{
	return rand() % count;
}

bool Queen::Place(int k)     //测试皇后k置于第x[k]列的合法性
{
	for (int j = 1; j < k; j++)
	{
		if ((abs(k - j) == abs(x[j] - x[k])) || (x[j] == x[k]))
		{
			return false;
		}
	}
	return true;
}

bool Queen::QueensLV(void)        //随机放置n个皇后的拉斯维加斯算法  
{     
	RandomNumber rnd;            //随机数产生器
	int k = 1;                   //下一个放置的皇后编号
	int count = 1;
	while ((k <= n) && (count > 0)) 
	{
		count = 0;
		for (int i = 1; i <= n; i++) 
		{
			x[k] = i;
			if (Place(k))
			{
				y[count++] = i;
			}
		}
		if (count > 0)
		{
			x[k++] = y[rnd.Random(count)];  //随机位置 
		}
	}
	return (count > 0);		//count>0表示放置成功 
}

void nQueen(int n)                 //解n后问题的拉斯维加斯算法
{        
	Queen X;
	//初始化x
	X.n = n;
	int* p = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		p[i] = 0;
	}
	X.x = p;
	X.y = p;
	//反复调用随机放置的n个皇后的来说维加斯算法，直至放置成功
	while (!X.QueensLV());
	for (int i = 1; i <= n; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
	delete[] p;
}

int main() 
{
	int n;
	cout << "请输入n后的n：" << endl;
	cin >> n;
	cout << n << "皇后的解为：" << endl;
	nQueen(n);
	return 0;
} 

