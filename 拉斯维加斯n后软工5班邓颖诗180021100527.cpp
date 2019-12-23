#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
class Queen{
	friend void nQueen(int);
	private:
		bool Place(int k);//Test the legitimacy of queen k in column x [k]
		bool QueensLV(void);//Place n Queens Las Vegas algorithm randomly
		int n;//the number of queens
		int x[100],y[100];//x[i] is the position of i queen,
		//y is a feasible placement for the bank
}; 
bool Queen::Place(int k){
	for(int j=1;j<k;j++){//Check for conflict with the previous queen
		if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k]))
			return false;
	}
	return true;
}
class RandomNumber{
	public:
		int Random(int t);
};
int RandomNumber::Random(int t){//produce random number
	srand((unsigned)time(NULL));
	return rand()%t;
}
bool Queen::QueensLV(void){
	RandomNumber rnd;
	int k=1;//the NO of the next queen
	int count=1;
	while((k<=n)&&(count>0)){
		count=0;
		for(int i=1;i<=n;i++){//count the number of feasible placements
			x[k]=i;
			if(Place(k))
				y[count++]=i;
		}
		if(count>0)//Random placement
			x[k++]=y[rnd.Random(count)];
	}
	return (count>0);
}
void nQueen(int n){
	Queen X;
	X.n=n;
	int p[100];
	for(int i=0;i<=n;i++)
		X.x[i]=0;//initialization
	while(!X.QueensLV());//Run until find the solution
	cout<<"The positions of the queens:"
	for(int i=1;i<=n;i++)
		cout<<X.x[i]<<" ";
	cout<<endl;
}
int main()
{
	int n;
	cout<<"Please enter the size of board:"<<endl;
	cin>>n;
	nQueen(n);
	return 0;
} 
