#include <iostream>

using namespace std;

class MatrixChain
{
public:
	MatrixChain(int* p, int n);
	void matrixChain();//矩阵最小次数求解函数
	friend int findMatrixChainAnswer(int* p, int n);//类调用

private:
	int** m; //动态规划矩阵
	int** s; //切割结果矩阵
	int* p; //矩阵列数存储矩阵
	int n; //矩阵数
};

MatrixChain::MatrixChain(int* p, int n) {
	this->p = p;
	this->n = n;
	int** ppm = new int* [n+1];
	for (int i = 0; i < n + 1; i++) {
		ppm[i] = new int[n + 1];
	}
	int** pps = new int* [n + 1];
	for (int i = 0; i < n + 1; i++) {
		pps[i] = new int[n + 1];
	}
	this->m = ppm;
	this->s = pps;
}

void MatrixChain::matrixChain() {
	for (int i = 1; i <= n; i++) {
		m[i][i] = 0; //矩阵填零
	}
	for (int r = 2; r <= n; r++) {//首循环：矩阵连乘段长
		//当前子问题：从段首1到段尾i+r-1的乘积次数
		for (int i = 1; i <= n - r + 1; i++) {
			int j = i + r - 1;//段尾
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];//公式
			s[i][j] = i;
			//子问题所有情况循环，求解当前子问题的最优解
			for (int k = i + 1; k < j; k++) {
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];//公式
				if (t < m[i][j]) {//更优则更新迭代
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
}

int findMatrixChainAnswer(int* p, int n) {
	MatrixChain mat(p, n);
	mat.matrixChain();
	return mat.m[1][n];
}

int main(){
	int* p = new int[7] {1, 2, 3, 4, 5, 6, 7};
	int n = 6;
	cout << "当前问题需要计算最少次数为：" << findMatrixChainAnswer(p, n) << endl;
	return 0;
}

