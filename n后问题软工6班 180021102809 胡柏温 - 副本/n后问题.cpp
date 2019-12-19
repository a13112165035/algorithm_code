#include<stdio.h>
#include<math.h>
class Queen{
	friend int nQueen(int);
	public:
		bool Place(int k);
		void Backtrack(int t);
		int n,*x;
		int sum;
};
bool Queen::Place(int k){
	for(int j=1;j<k;j++)
		    if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k]))
	    return false;
	return true;
} 
void Queen::Backtrack(int t){
	if(t>n)
	    sum++;
	else{
		for(int i=1;i<=n;i++){
			x[t]=i;
			if(Place(t))
			Backtrack(t+1);
		}
	}
}
int nQueen(int n){
	Queen X;
	X.n=n;
	X.sum=0;
	int *p=new int [n+1];
	for(int i=0;i<=n;i++)
	    p[i]=0;
	X.x=p;
	X.Backtrack(1);
	delete[] p;
	return X.sum;
}
int main(){
	int n=4;
	printf("%d",nQueen(n));	
}
