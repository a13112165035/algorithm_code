#include<iostream>
#include<cstdlib>
using namespace std;

class Queen 
{
	friend void nQueen(int);
private:
	bool Place(int k);   	//���Իʺ�k���ڵ�x[k]�еĺϷ���
	bool QueensLV(void);	//�������n���ʺ���˹ά��˹�㷨 
	int n;                  //�ʺ����
	int	*x, * y;            //������
};

class RandomNumber 
{
public:
	int Random(int count);
};

int RandomNumber::Random(int count)
{
	return rand() % count;
}

bool Queen::Place(int k)     //���Իʺ�k���ڵ�x[k]�еĺϷ���
{
	for (int j = 1; j < k; j++)
	{
		if ((abs(k - j) == abs(x[j] - x[k])) || (x[j] == x[k]))
		{
			return false;
		}
	}
	return true;
}

bool Queen::QueensLV(void)        //�������n���ʺ����˹ά��˹�㷨  
{     
	RandomNumber rnd;            //�����������
	int k = 1;                   //��һ�����õĻʺ���
	int count = 1;
	while ((k <= n) && (count > 0)) 
	{
		count = 0;
		for (int i = 1; i <= n; i++) 
		{
			x[k] = i;
			if (Place(k))
			{
				y[count++] = i;
			}
		}
		if (count > 0)
		{
			x[k++] = y[rnd.Random(count)];  //���λ�� 
		}
	}
	return (count > 0);		//count>0��ʾ���óɹ� 
}

void nQueen(int n)                 //��n���������˹ά��˹�㷨
{        
	Queen X;
	//��ʼ��x
	X.n = n;
	int* p = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		p[i] = 0;
	}
	X.x = p;
	X.y = p;
	//��������������õ�n���ʺ����˵ά��˹�㷨��ֱ�����óɹ�
	while (!X.QueensLV());
	for (int i = 1; i <= n; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
	delete[] p;
}

int main() 
{
	int n;
	cout << "������n���n��" << endl;
	cin >> n;
	cout << n << "�ʺ�Ľ�Ϊ��" << endl;
	nQueen(n);
	return 0;
} 

