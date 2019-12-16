//¶þ·ÖËÑË÷
#include <stdio.h>

int binarySearch(int a[], const int& x, int n)
{
	int left = 0, right = n - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (x == a[middle])
		{
			return middle;
		}
		if (x > a[middle])
		{
			left = middle + 1;
		}
		else
		{
			right = middle - 1;
		}
	}
	return -1;
}

int main()
{
	int n = 5;
	int a[6] = { 1,3,5,7,11,14 };
	return binarySearch(a, n, 6);
}