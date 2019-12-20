#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <cstring>
#include <ctime>
using std::cout;
using std::endl;
using std::cin;

class RandomNumber {
	const unsigned long maxshort = 65536L;
	const unsigned long multiplier = 1194211693L;
	const unsigned long adder = 12345L;
	unsigned long randSeed; // ��ǰ����
public:
	RandomNumber(unsigned long s = 0) {
		if (s == 0) randSeed = time(0); // ��ϵͳʱ���������
		else randSeed = s; // �û��ṩ����
	}
	unsigned short Random(unsigned long n) { // ����0:n-1֮����������
		randSeed = multiplier * randSeed + adder;
		return (unsigned short)((randSeed >> 16) % n);
	}
	double fRandom() { // ����[0,1)֮������ʵ��
		return Random(maxshort) / double(maxshort);
	}
};

class Queen {
	friend bool nQueen(int);

	int n, *x, *y;
	bool Place(int k) { //���Իʺ�k���ڵ�x[k]�еĺϷ���
		for (int j = 1; j < k; ++j)
			if ((abs(k-j) == abs(x[j] - x[k])) || (x[j] == x[k]))
				return false;
		return true;
	}
	bool Backtrack(int t) { // ��n������Ļ��ݷ�
		if (t > n) {
			for (int i = 1; i <= n; ++i)
				y[i] = x[i];
			return true;
		} else {
			for (int i = 1; i <= n; ++i) {
				x[t] = i;
				if (Place(t) && Backtrack(t + 1)) return true;
			}
		}
		return false;
	}
	bool QueensLV(int stopVegas) { // �������n���ʺ�����㷨
		RandomNumber rnd;
		int k = 1, count = 1; // k��һ�����õĻʺ���
		while ((k <= stopVegas) && (count > 0)) { // 1 <= stopVegas ��ʾ����������õĻʺ���
			count = 0;
			for (int i = 1; i <= n; ++i) { // ͳ�Ʋ���¼���б��кϷ�λ��
				x[k] = i;
				if (Place(k)) y[count++] = i;
			}
			if (count > 0)
				x[k++] = y[rnd.Random(count)]; //�ӺϷ�λ�������ѡһ��
		}
		return count > 0; // count>0��ʾ���óɹ�
	}
};
bool nQueen(int n) {
	Queen X;
	X.n = n;
	int *p = new int[n+1], *q = new int[n+1];
	for (int i = 0; i <= n; ++i) p[i] = 0, q[i] = 0;
	X.y = p, X.x = q;
	int stop = 5;
	if (n > 15) stop = n - 15;
	bool found = false;
	while (!X.QueensLV(stop)) ;// ���������������n���ʺ����˹ά��˹�㷨��ֱ�����óɹ�
	if (X.Backtrack(stop + 1)) {
		for (int i = 1; i <= n; ++i)
			cout << p[i] << " ";
		found = true;
	}
	cout << endl;
	delete[] p;
	delete[] q;
	return found;
}

int main() {
	int n;
	cin >> n; // ����n��
	cout << nQueen(n); // �������
	return 0;
}