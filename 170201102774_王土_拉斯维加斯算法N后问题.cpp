//拉斯维加斯算法解决 n后问题

#include<iostream>

using namespace std;

//随机数函数
int randomInt(int end) {
	return rand() % end;
}

class Queen{
public:
	Queen(int n, int* p);
	~Queen();

	bool place(int k);	//判断该位置是否合法(会不会被吃掉)
	bool QueensLV(void);	//是否有一个最优位置并加入xy

	int n;	//n后问题的棋盘阶数
	int *x, *y;	//解向量
};

Queen::Queen(int n, int *p){
	this->n = n;
	x = p;
	y = new int[n + 1];
}

Queen::~Queen(){
	delete[] x;
	delete[] y;
}

//判断该位置是否合法(会不会被吃掉)
bool Queen::place(int k){
	for (int j = 0; j < k; j++) {
		if ((abs(x[k] - x[j]) == abs(k - j)) || (x[k] == x[j])) {
			return false;
		}
	}
	return true;
}

bool Queen::QueensLV(void){
	int k = 1;
	int count = 1;
	while ((k < n) && (count > 0)) {
		count = 0;
		for (int i = 0; i < n; i++) {
			x[k] = i;
			if (place(k)) {
				y[count++] = i;
			}
		}
		if (count > 0) {
			x[k++] = y[randomInt(count)];
		}
	}
	return (count > 0);
}

//解决n后问题函数
void SolveNQueenAnswer(int n) {
	int* p = new int[n + 1];
	for (int i = 0; i < n + 1; i++) {
		p[i] = 0;
	}
	Queen q = Queen(n, p);
	q.x = p;
	while (!q.QueensLV());
	for (int i = 0; i < n; i++) {
		cout << p[i] << " ";
	}
	cout << endl;
}


int main(){
    
	int i = 5;
	cout << "算法1(拉斯维加斯)：" << endl;
	while (i--){
		SolveNQueenAnswer(10);
	}
	cout  << endl;
	return 0;
}