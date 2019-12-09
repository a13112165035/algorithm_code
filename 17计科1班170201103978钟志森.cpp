#include<iostream>
using namespace std;


int MatrixChain(int *p, int n, int **m, int **s)
{
	for (int i = 1; i <= n;i++)
	
		m[i][i] = 0;
	
	for (int r = 2; r <= n; r++)
	
		for (int i = 1; i <= n - r + 1; i++)
		{
			int j = i + r - 1;
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
			s[i][j] = i;
			for (int k =i+1; k < j; k++)
			{
				int t = m[i][k] + m[k + 1][j] + p[i - 1]*p[k] * p[j];
				if (t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	
	return m[1][n];
}



void Traceback(int i, int j, int **s)
{
	if (i == j)
	{
		return;
	}
	Traceback(i, s[i][j], s);
	Traceback(s[i][j] + 1, j, s);
	cout << "Multiply A" << i << "," << s[i][j];
	cout << " and A" << (s[i][j] + 1) << "," << j << endl;
}



int main()
{
	int num,statues;
	int length=0;
	
	cout << "请输入您要连乘的矩阵的个数:"; cin >> num;
	int row[num], col[num];
	for (length=0; length < num;length++)
	{
		cout << "请输入第"<<length+1<<"个矩阵的行和列" << endl;
		cout << "row:"; cin >> row[length];
		cout << "col:"; cin >> col[length];	
		statues=length-1;
		while(length>0 && row[length] != col[statues])
			{
				cout << "error:输入的第" << length+1 << "个矩阵的行与上一个矩阵的列不相等" << endl;
				cout << "请重新输入" << endl;
				cout << "请输入第"<<length+1<<"个矩阵的行和列" << endl;
				cout << "row:"; cin >> row[length];
				cout << "col:"; cin >> col[length];	
			}
		
		
	}
	int p[num+1];
	int **s = new int *[num+1];
	int **m = new int *[num+1];
	for(int i=0;i<num;i++)
	{
		p[i]=row[i];
		cout<<p[i]<<endl;
	}
	p[num]=col[num-1];
	for(int i=0;i<=num;i++)  
    {  
		s[i] = new int[num+1];
		m[i] = new int[num+1];
    } cout<<"最佳计算如下:"<<endl;
	 
	cout<<MatrixChain(p, num, m, s)<<endl;
	cout<<"最佳计算如下:"<<endl;
	Traceback(1,num,s);
	return 0;
}




