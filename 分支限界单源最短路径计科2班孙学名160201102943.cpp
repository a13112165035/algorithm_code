#include"stdlib.h"
#include <iostream>
using namespace std;

//各个城市之间的路径长度
int CityVal[4][4] = {
					{0 ,30,6,4},
					{30,0 ,5,10},
					{6,5,0 ,20 },
					{4,10,20 ,0} };

struct CityNum {
	int MinVal[2];       //最短路径长度
	int PastCity[2][4]; //走过的路径
}city[4];

int find(int j, int k, int boolnum)
{
	int i;
	for (i = 0; i < 4; i++)
		if (j == city[k].PastCity[boolnum][i])
			return 1;
	return 0;
}
void copy(int k, int boolnum1, int j, int boolnum2)
{
	int i = 0;
	while (city[k].PastCity[boolnum1][i] != 0)
	{
		city[j].PastCity[boolnum2][i] = city[k].PastCity[boolnum1][i];
		i++;
	}
	city[j].PastCity[boolnum2][i] = k;
}



int main()
{
	int i, j, k;
	int boolnum = 0;
	int TempMinVal;
	int TempCity;
	int TempVal;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 4; j++)
			for (k = 0; k < 4; k++)
				city[k].PastCity[i][j] = 0;
	for (i = 1; i < 4; i++)
		city[i].MinVal[boolnum] = CityVal[i][0];
	for (i = 0; i < 2; i++)
	{
		for (j = 1; j < 4; j++)
		{
			TempMinVal = 32767;
			for (k = 1; k < 4; k++)
			{
				if (j != k && !find(j, k, boolnum))
				{
					TempVal = CityVal[j][k] + city[k].MinVal[boolnum];
					if (TempMinVal > TempVal)
					{
						TempMinVal = TempVal;
						TempCity = k;
					}
				}
			}
			city[j].MinVal[(boolnum + 1) % 2] = TempMinVal;
			copy(TempCity, boolnum, j, (boolnum + 1) % 2);
		}
		boolnum = (boolnum + 1) % 2;
	}
	TempMinVal = 32767;
	for (i = 1; i < 4; i++)
	{
		TempVal = CityVal[0][i] + city[i].MinVal[boolnum];
		if (TempMinVal > TempVal)
		{
			TempMinVal = TempVal;
			TempCity = i;
		}
	}
	cout << "最小费用为:" << TempMinVal << endl;
	cout << "最佳周游路径为:";
	cout << 1 << ' ';
	cout << TempCity + 1 << ' ';
	for (i = 1; i >= 0; i--)
		cout << city[TempCity].PastCity[boolnum][i] + 1 << ' ';
	cout << 1 << endl;
}