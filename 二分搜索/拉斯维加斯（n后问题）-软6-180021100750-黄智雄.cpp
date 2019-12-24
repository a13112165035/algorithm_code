#include<iostream>
 #include"time.h"
 using namespace std;
 const unsigned long maxshort=65536L;
 const unsigned long multiplier=1194211693L;
 const unsigned long adder=12345L;
 class RandomNumber{
 	private:
 		unsigned long randSeed;
 	public:
 		RandomNumber(unsigned long s=0);
 		unsigned short Random(unsigned long n);
 		double fRandom(void);
 };
 RandomNumber::RandomNumber(unsigned long s){
 	if(s==0)randSeed=time(0);
 	else randSeed=s;
 }
 unsigned short RandomNumber::Random(unsigned long n){
 	randSeed=multiplier*randSeed+adder;
 	return (unsigned short)((randSeed>>16)%n);
 }
 double RandomNumber::fRandom(void){
 	return Random(maxshort)/double(maxshort);
 }



 #include<iostream>
 #include<math.h>
 #define false 0
 #define true 1
 using namespace std; 
  class Queen{
  	friend void nQueen(int);
  	private:bool Place(int k);//测试皇后K置于第x[k]列的合法性 
  	bool QueensLV(void);//随机放置n个皇后拉斯维加斯算法 
  	int n,//皇后个数 
  		*x,y[1000];//解向量 
  };
  bool Queen::Place(int k){//测试皇后K置于第x[k]列的合法性 
  	for(int j=1;j<k;j++){
  		if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k]))
  			return false;
  	}
  	return true;
  } 
  bool Queen::QueensLV(void){//随机放置n个皇后拉斯维加斯算法
  	RandomNumber rnd;//随机数产生器 
  	int k=1;//下一个皇后放置的编号 
  	int count=3;
  	while((k<=n)&&(count>0)){//上行有解且未到最后一行 
  		count=0;
  		for(int i=1;i<=n;i++){
  			x[k]=i;
  			if(Place(k))//第k行是否合法 
  				y[count++]=i;//发现每一个合法的位置 
  		}
  		if(count>0)
  			x[k++]=y[rnd.Random(count)];//随机放置 
  	}
  	return (count>0);//count>0表示放置成功 
  }
  void nQueen(int n){
  	Queen X;
  	X.n=n;
  	int *p=new int[n+1];
  	for(int i=0;i<=n;i++)
  		p[i]=0;	
  	X.x=p;//反复调用随机放置n个皇后的拉斯维加斯算法，直至放置成功 
  	while(X.QueensLV()){//不成功就运行到散架为止
  		cout<<"结果为"<<endl;
  		for(int i=1;i<=n;i++){
  			for(int j=1;j<=n;j++){
  				if(j==p[i])
  					cout<<"Q"<<"";
  				else
  					cout<<"*"<<"";
  			}
  			cout<<endl;
 		}//输出找到合法的方案 
 		break;
  	} 
 	delete[] p; 
  } 
  int main(){
  	int n;
  	cout<<"请输入皇后个数"<<endl;
  	cin>>n;
  	nQueen(n);
  	system("pause");
  }
