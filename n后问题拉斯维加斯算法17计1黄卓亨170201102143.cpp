#include<iostream>
#include<cstdlib>
using namespace std;

class Queen {
	friend void nQueen(int);
private:
	bool Place(int k);
	bool QueensLV(void);
	int n;
	int	*x,*y;
};

class RandomNumber {
public:
	int Random(int count);
};

int RandomNumber::Random(int count)
{
	return rand()%count;
}

bool Queen::Place(int k){
	for (int j=1;j<k;j++)
	{
		if ((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k]))
		{
			return false;
		}
	}
	return true;
}

bool Queen::QueensLV(void) {     
	RandomNumber rnd;
	int k=1;
	int count=1;
	while ((k<=n) && (count>0)) {
		count=0;
		for (int i=1; i<=n;i++) {
			x[k]=i;
			if (Place(k))
			{
				y[count++]=i;
			}
		}
		if (count > 0){
			x[k++]=y[rnd.Random(count)];
		}
	}
	return (count>0);
}

void nQueen(int n){        
	Queen X;
	X.n=n;
	int *p=new int[n + 1];
	for (int i=0;i<=n;i++){
		p[i] = 0;
	}
	X.x=p;
	X.y=p;
	while (!X.QueensLV());
	for (int i=1;i<=n;i++){
		cout<<p[i]<<" ";
	}
	cout<<endl;
	delete[] p;
}

int main(){
	int n;
	cout<<"请输入n后的n："<<endl;
	cin>>n;
	cout<<n<<"皇后的解为："<<endl;
	nQueen(n);
	return 0;
} 
