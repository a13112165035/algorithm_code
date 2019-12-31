#include<bits/stdc++.h>
using namespace std;

int random(int n)// 产生0 ~ n-1 之间的随机整数
{
	int ret = rand()*rand();
	return ret%n;
}

class Queen
{	
	public:
	int n,*x,y[1005];//皇后个数、解向量 

	bool place(int k)//测试皇后k放在第x[k]列的合法性 
	{
		for(int j=1;j<k;j++)//行
			if((abs(k-j)==abs(x[j]-x[k]) ) || (x[j]==x[k])) //斜线或同一列 
				return 0;
		return 1;
	}
	
	bool QueenLV()//随机放置n个皇后的拉斯维加斯算法 
	{
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
				x[k++]=y[random(count)];//产生从0到count-1的随机数 
				//就从所有合理性的列中随机拿出一个给x 
		}
		return (count>0);//大于0放置成功 
	}
};

void nQueen(int n)
{
	Queen X;//初始化X
	X.n=n;
	int p[n+1];
	memset(p,0,sizeof p);//清空p数组 
	X.x=p;//x指针指向p
	
	while(!X.QueenLV());//反复调用拉斯维加斯算法，直至出现一种解法
	for(int i=1;i<=n;i++)
		cout << p[i] << " ";
	cout << endl;
}

int main()
{
	srand(time(NULL));						//置随机数种子 
	cout << "请输入n皇后个数：" << endl;
	int n;
	cin >> n;
	nQueen(n);
	return 0;
}
