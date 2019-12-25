#include<stdio.h>
#include<math.h>
#include<stdlib.h> 
#include<time.h>
class Queen{
	friend void nQuenn(int n);
	public:
		bool Place(int k);
		bool QueensLV(void);
	int n,*x,*y;
};

bool Queen::Place(int k){
	for(int j=1;j<k;j++)
	    if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k]))
	    return false;
	return true;
}

bool Queen::QueensLV(void){
	int k=1;
	int count=1;
	while((k<=n)&&(count>0)){
		count=0;
		for(int i=1;i<=n;i++){
			x[k]=i;
			if(Place(k))
			y[count++]=i;
		}
		srand(time(NULL));
		if(count>0)
		x[k++]=y[rand()%count];
	}
	return (count>0);
}

void nQueen(int n){
	Queen X;
	X.n=n;
	int *p=new int[n+1];
	int *p1=new int[n+1];
	for(int i=0;i<=n;i++)
	    p[i]=0;
	X.x=p;
	X.y=p1;
	while(!X.QueensLV());
	for(int i=1;i<=n;i++)
	    printf("%d ",p[i]);
	printf("\n");
	delete[] p;
}

int main(){
	int n=5;
	nQueen(n);
	return 0;
}
