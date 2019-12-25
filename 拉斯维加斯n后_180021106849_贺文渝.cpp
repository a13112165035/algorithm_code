#include <iostream>
#include <cstdlib>
using namespace std;

bool Place(int k,int *x,int *y){
	for(int j=1; j<k; j++)
		if((abs(k-j) == abs(x[j]-x[k])) || (x[j] == x[k]))
			return false;
	return true;
}

bool QueensLV(int n,int *x,int *y){
	int k = 1;
	int count = 1;
	while ((k <= n) && (count > 0)){
		count = 0;
		for (int i=1; i <= n; i++){
			x[k]=i;
			if(Place(k,x,y))
				y[count++] = i;
		}
		if(count>0)
			x[k++] = y[rand()%count];
	}
	return (count>0); 
}
bool nQueen(int n,int *x,int *y){
	int *p = new int [n+1];
	for (int i=0; i<=n; i++)
		p[i] = 0;
	x = p;
	while(!QueensLV(n,x,y)) ;
	for (int i=1; i<=n; i++)
		cout<<p[i]<<" ";
	cout<<endl;
	
}
int main(){
	int *x,*y;
	int n;
	cout<<"n:";
	cin>>n;
	nQueen(n,x,y);
	
	
}
