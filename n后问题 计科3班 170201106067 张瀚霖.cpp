#include <iostream>
#include "math.h"
#include "randomnumber.h"
using namespace std;

class Queen{
	friend void nQueen(int);
private:
	bool Place(int k);
	bool QueensLV(void);
	int n,
	  *x,y[1000];
}; 

bool Queen::Place(int k){
	for(int j=1;j<k;j++)
		if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k]))
			return false;
		return true;
}

bool Queen::QueensLV(void){
	RandomNumber rnd;
	int k=1;
	int count=1;
	while((k<=n)&&(count>0)){
		count=0;
		for(int i=1;i<=n;i++){
			x[k]=i;
			if(Place(k)){
				y[count++]=i;
			}
	    }
	    if(count>0){
	    	x[k++]=y[rnd.Random(count)];
		}
	}
	return (count>0);
}


void nQueen(int n){
	Queen X;
	X.n=n;
	int * p=new int[n+1];
	for(int i=0;i<=n;i++){
		p[i]=0;
	}
	X.x=p;
	while(X.QueensLV()){
		cont <<"result is:"<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==p[i]){
					cout<<"Q"<<" ";
				}
				if(j!=p[i]){
					cout<<"*"<<" ";
				}
			}
			cout<<endl;
		}
		break;
	}
	delete []p;
}

void main(){
	int n;
	cout<<"输入皇后个数："<<endl;
	cin>>n;
	nQueen(n);
}
