#include <iostream> 
#include <stdlib.h>
using namespace std;
const int L = 7;
void MatrixChain(int* p,int n,int **m,int** s){
	for(int i=1;i<=n;i++)
		m[i][i]=0;
	for(int r=2;r<=n;r++){
		for(int i=1;i<=n-r+1;i++){
			int j=i+r-1;
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j]=i;
			for(int k=i+1;k<j;k++){
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(t<m[i][j]){
					m[i][j]=t;s[i][j]=k;
				}
			}
		}
	}
	
}
void Traceback(int i,int j,int **s){
	if(i==j)return;
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	cout<<"Multiply A"<<i<<","<<s[i][j];
	cout<<"and A"<<(s[i][j]+1)<<","<<j<<endl; 
}
int main()
{
	int p[L]={30,35,15,5,10,20,25};

    int **s = new int *[L];
	int **m = new int *[L];
	for(int i=0;i<L;i++)  
    {  
		s[i] = new int[L];
		m[i] = new int[L];
    } 
	MatrixChain(p,6,m,s);
	cout<<"矩阵的最少计算次数为："<<m[1][L-1]<<endl;
	cout<<"矩阵最优计算次序为："<<endl;
	Traceback(1,6,s);
	system("pause");
	return 0;
}
