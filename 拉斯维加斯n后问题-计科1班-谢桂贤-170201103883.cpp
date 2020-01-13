#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;

class Queen{
	friend void nQueen(int);
private:
	bool Place(int k);   	//���Իʺ�k���ڵ�x[k]�еĺϷ���
	bool QueensLV(void);	//�������n���ʺ���˹ά��˹�㷨 
	int n,*x,*y;
}; 

class RandomNumber{
	public:
		int RanDom(int count);
};

int RandomNumber::RanDom(int count){
	int a=rand()%count;
	return a;
}

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
		count =0;
		for(int i=1;i<=n;i++){
			x[k]=i;
			if(Place(k))
				y[count++]=i;								
		}
		if(count>0)
				x[k++]=y[rnd.RanDom(count)];  //���λ�� 
	}
	return (count>0);		//��ʾ���óɹ� 
}


void nQueen(int n){
	Queen X;
	X.n=n;
	int *p=new int[n+1];
	for(int i=0;i<=n;i++)
		p[i]=0;
	X.x=p;
	X.y=new int[n+1];
	
	while(!X.QueensLV());
	
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";
	cout<<endl;
	delete[] p;		
}

int main(){
	int n;
	cout<<"�����뼸���ʺ�"<<endl;
	cin>>n;
	cout<<n<<"�ʺ�Ľ�Ϊ��"<<endl;
	nQueen(n);
	return 0;
}
