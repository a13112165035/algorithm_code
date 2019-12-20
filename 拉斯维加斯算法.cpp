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
	unsigned long randSeed; // 当前种子
public:
	RandomNumber(unsigned long s = 0) {
		if (s == 0) randSeed = time(0); // 用系统时间产生种子
		else randSeed = s; // 用户提供种子
	}
	unsigned short Random(unsigned long n) { // 产生0:n-1之间的随机整数
		randSeed = multiplier * randSeed + adder;
		return (unsigned short)((randSeed >> 16) % n);
	}
	double fRandom() { // 产生[0,1)之间的随机实数
		return Random(maxshort) / double(maxshort);
	}
};

class Queen {
	friend bool nQueen(int);

	int n, *x, *y;
	bool Place(int k) { //测试皇后k置于第x[k]列的合法性
		for (int j = 1; j < k; ++j)
			if ((abs(k-j) == abs(x[j] - x[k])) || (x[j] == x[k]))
				return false;
		return true;
	}
	bool Backtrack(int t) { // 解n后问题的回溯法
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
	bool QueensLV(int stopVegas) { // 随机放置n个皇后的拉算法
		RandomNumber rnd;
		int k = 1, count = 1; // k下一个放置的皇后编号
		while ((k <= stopVegas) && (count > 0)) { // 1 <= stopVegas 表示允许随机放置的皇后数
			count = 0;
			for (int i = 1; i <= n; ++i) { // 统计并记录所有本行合法位置
				x[k] = i;
				if (Place(k)) y[count++] = i;
			}
			if (count > 0)
				x[k++] = y[rnd.Random(count)]; //从合法位置中随机选一个
		}
		return count > 0; // count>0表示放置成功
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
	while (!X.QueensLV(stop)) ;// 反复调用随机放置n个皇后的拉斯维加斯算法，直至放置成功
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
	cin >> n; // 输入n后
	cout << nQueen(n); // 输出解数
	return 0;
}