#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
class Queen{
	friend void nQueen(int);
private:
	bool check(int t);
	bool QueenLV(void);
	int n,*x,*y;
};
bool Queen::check(int t)
{
	for(int i=1;i<t;++i)
		if(x[i]==x[t]||abs(t-i)==abs(x[t]-x[i]))
			return false;
	return true;
}
bool Queen::QueenLV()
{
	srand(time(0));
	int k=1,count=1;
	while(k<=n&&count>0)
	{
		count=0;
		for(int i=1;i<=n;++i)
		{
			x[k]=i;
			if(check(k))y[count++]=i;
		}
		if(count>0)
			x[k++]=y[rand()%count];
	}
	return count>0;
}
void nQueen(int n)
{
	Queen q;
	q.n=n;
	q.y=new int[n+1];
	int*a=new int[n+1];
	for(int i=0;i<=n;++i)
		q.y[i]=a[i]=0;
	q.x=a;
	while(!q.QueenLV());
	for(int i=1;i<=n;++i)
		cout<<a[i]<<" ";
	cout<<endl;
	delete[]a;
}
int main()
{
	int n;
	cout<<"请输入皇后个数"<<endl;
	cin>>n;
	nQueen(n);
	return 0;
}
