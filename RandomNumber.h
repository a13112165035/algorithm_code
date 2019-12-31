#include <iostream> 
#include "time.h" 
using namespace std;

//随机数类 
const unsigned long maxshort=65536L; 
const unsigned long multiplier=1194211693L; 
const unsigned long adder=12345L;
class RandomNumber 
{ 
private: 
	//当前种子 
	unsigned long randSeed; 
public: 
	//构造函数，默认值 0 表示由系统自动产生种子 
	RandomNumber(unsigned long s=0); 
	//产生 0:n-1 之间的随机整数 
	unsigned short Random(unsigned long n); 
	//产生[0,1)之间的随机实数 
	double fRandom(void); 
};

//产生种子 
RandomNumber::RandomNumber(unsigned long s) 
{ 
	if(s==0) randSeed=time(0); //用系统时间产生种子 
	else randSeed=s; //由用户提供种子 
}

//产生 0:n-1 之间的随机整数 
unsigned short RandomNumber::Random(unsigned long n) 
{ 
	randSeed=multiplier*randSeed+adder; 
	return (unsigned short) ((randSeed>>16)%n); 
}

//产生[0,1)之间的随机实数 
double RandomNumber::fRandom(void) 
{ 
	return Random(maxshort)/double(maxshort);
}
