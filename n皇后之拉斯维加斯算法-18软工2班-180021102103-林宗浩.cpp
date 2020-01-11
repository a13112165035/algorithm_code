#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
const unsigned long maxshort=65536L;
const unsigned long multiplier=1194211693L;
const unsigned long adder=12345L;

//���鿴�α�208ҳ 
class RandomNumber
{
private:
	unsigned long randSeed;//��ǰ���� 
public:
	RandomNumber(unsigned long s=0);//���캯����Ĭ��ֵ0��ʾ��ϵͳ�Զ��������� 
	unsigned short Random(unsigned long n);//����0��n-1֮���������� 
	double fRandom(void);//����(0,1)֮������ʵ�� 
};

// ��������
RandomNumber::RandomNumber(unsigned long s)
{
    if(s == 0)
        randSeed = time(0);    //��ϵͳʱ���������
    else
        randSeed = s;
}

// ����0 ~ n-1 ֮����������
unsigned short RandomNumber::Random(unsigned long n)
{
    randSeed = multiplier * randSeed + adder;
    return (unsigned short)((randSeed >> 16) % n);
}

// ����[0, 1)֮������ʵ��
double RandomNumber::fRandom()
{
    return Random(maxshort) / double(maxshort);
}

class Queen
{
	friend void nQueen(int);
private:
	bool place(int k);//���Իʺ�k���ڵ�x[k]�еĺϷ��� 
//	bool Backtrack(int t);
	bool QueenLV();//�������n���ʺ����˹ά��˹�㷨 
	int n,*x,y[1005];//�ʺ������������ 
};

bool Queen::place(int k)
{
	for(int j=1;j<k;j++)//��
	{
		if(( abs(k-j)==abs(x[j]-x[k]) ) || (x[j]==x[k]))
		{//б�߻�ͬһ�� 
			return false;
		}
	}
	return true;
}

bool Queen::QueenLV()
{
	RandomNumber rnd;//�����������
	int k=1;//��һ�� 
	int count=1;
	while((k<=n) && (count>0))//���������һ�� 
	{
		count=0;
		for(int i=1;i<=n;i++)//�� 
		{
			x[k]=i;
			if(place(k))
				y[count++]=i;//����һ�У�k�е����к������м���y�� 
		}
		if(count>0)//����к����Ե��� 
			x[k++]=y[rnd.Random(count)];//������0��count-1������� 
			//�ʹ����к����Ե���������ó�һ����x 
	}
	return (count>0);//����0���óɹ� 
}

void nQueen(int n)
{
	Queen X;
	//��ʼ��X
	X.n=n;
	int *p=new int[n+1];
	//��ʼ��p 
	for(int i=0;i<=n;i++)
		p[i]=0; 
	X.x=p;//xָ��ָ��p
	//����������˹ά��˹�㷨��ֱ������һ�ֽⷨ
	while(!X.QueenLV());
	for(int i=1;i<=n;i++)
		cout << p[i] << " ";
	cout << endl;
	delete[] p;
}

int main()
{
	cout << "������ʺ������" << endl;
	int num;
	cin >> num;
	nQueen(num);
	return 0;
}
