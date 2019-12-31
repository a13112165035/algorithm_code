#include<bits/stdc++.h>
using namespace std;

int random(int n)// ����0 ~ n-1 ֮����������
{
	int ret = rand()*rand();
	return ret%n;
}

class Queen
{	
	public:
	int n,*x,y[1005];//�ʺ������������ 

	bool place(int k)//���Իʺ�k���ڵ�x[k]�еĺϷ��� 
	{
		for(int j=1;j<k;j++)//��
			if((abs(k-j)==abs(x[j]-x[k]) ) || (x[j]==x[k])) //б�߻�ͬһ�� 
				return 0;
		return 1;
	}
	
	bool QueenLV()//�������n���ʺ����˹ά��˹�㷨 
	{
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
				x[k++]=y[random(count)];//������0��count-1������� 
				//�ʹ����к����Ե���������ó�һ����x 
		}
		return (count>0);//����0���óɹ� 
	}
};

void nQueen(int n)
{
	Queen X;//��ʼ��X
	X.n=n;
	int p[n+1];
	memset(p,0,sizeof p);//���p���� 
	X.x=p;//xָ��ָ��p
	
	while(!X.QueenLV());//����������˹ά��˹�㷨��ֱ������һ�ֽⷨ
	for(int i=1;i<=n;i++)
		cout << p[i] << " ";
	cout << endl;
}

int main()
{
	srand(time(NULL));						//����������� 
	cout << "������n�ʺ������" << endl;
	int n;
	cin >> n;
	nQueen(n);
	return 0;
}
