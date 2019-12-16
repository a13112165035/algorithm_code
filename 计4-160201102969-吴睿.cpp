#include<iostream>
#include<cstring> 
using namespace std;

const int N=100;
int p[N],m[N][N];

void MatrixChan(int p[],int n,int m[][N])
{
	for(int i=1;i<=n;++i)
		m[i][i]=0;
	for(int r=2;r<=n;++r)
		for(int i=1;i<=n-r+1;++i)
		{
			int j=i+r-1;
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
			for(int k=i+1;k<j;++k)
			{
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(t<m[i][j])
					m[i][j]=t;
			} 
		}
}
int main()
{
	int n,h,l;
	while(1)
	{
		memset(p,0,sizeof p);
		memset(m,0,sizeof m);
		cout<<"请输入矩阵数量"<<endl;
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			cout<<"请分别输入第"<<i<<"个矩阵的行和列"<<endl;
			cin>>h>>l;
			if(i==1)p[0]=h;
			p[i]=l; 
		} 
		MatrixChan(p,n,m);
		cout<<"矩阵最小连乘数为?"<<m[1][n]<<endl;
		cout<<"继续计算？是：1，否：0"<<endl;
		cin>>n;
		if(n==0)break; 
	}
	return 0;
} 
