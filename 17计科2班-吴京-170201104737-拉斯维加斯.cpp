#include<iostream>
#include <random>
#include "RandomNumber.h" 
using namespace std;
int random(int end) {
	return rand() % end;
}
class  Queen{
	
public:
	bool Place(int k);
	bool QueensLV(void);
	Queen(int n, int* p);
	int n,
	 *x, *y;

};
bool Queen::Place(int k) {
	for (int j = 1; j < k; j++) {
		if (abs(k - j) == abs(x[j] - x[k] )|| (x[j] == x[k]))
			return false;
		return true;
	}
	
}
Queen::Queen(int n, int* p) {
	this->n = n;
	x = p;
	y = new int[n + 1];
}
bool Queen::QueensLV(void){
	int k = 1;
	int count = 1;

	while ((k <= n) && (count > 0)) {
		count = 0;
		for (int i = 1; i <= n; i++) {
			if (Place(k))
				y[count++] = i;
		}
		if (count > 0)
			x[k++] = y[random(count)];
	}
	return (count > 0);
}
void jie(int n) {
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

int main() {

	int i = 4;
	cout << "拉斯维加斯" << endl;
	while (i--) {
		jie(20);
	}
	cout << endl;

}