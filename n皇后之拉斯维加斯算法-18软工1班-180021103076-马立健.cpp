#include<iostream>
#include<time.h>
#include<string.h>
using namespace std;

int n;

int random(int n)
{
	int ret = rand()*rand();
	return ret%n;
}

class Queen
{
	public:
	int n,*x,y[10005];
	
	bool place(int k)
	{
		for(int j=1;j<k;j++)
		{
			if((abs(k-j)==abs(x[j]-x[k]) ) || (x[j]==x[k]))
			{
				return false;
			}
		}
		return true;
	}

	bool QueenLV()
	{
		int k=1;
		int count=1;//count:Number of legal positions in the previous line
		while((k<=n) && (count>0))
		{
			count=0;
			for(int i=1;i<=n;i++)
			{
				x[k]=i;
				if(place(k))
				{
					y[count++]=i;
				}
			}
			if(count>0)
			{
				x[k++]=y[random(count)];
			}
		}
		return (count>0);
	}
};

void NQueen(int n)
{
	Queen X;
	X.n=n;
	int p[n+1];
	memset(p,0,sizeof p);
	X.x=p;
	while(!X.QueenLV());
	for(int i=1;i<=n;i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
}

int main()
{
	srand(time(NULL));	
	cout << "Please enter the number of queens:" << endl;
	cin >> n;
	NQueen(n);
	return 0;
}
