#include <iostream>    
#include <cmath>     
#include <ctime>
#include <cstdlib>    
using namespace std;

class Queen
{
    friend bool nQueen(int);
private:
    bool Place(int k);  
    bool Backtrack(int t);
    bool QueensLV(int stopVegas); 
    int n, *x, *y;
};

class RandomNumber
{
public:
	int Random(int);
};

int RandomNumber::Random(int count)
{	
    int x=rand()%count;
    return x;
}

bool Queen::Place(int k)
{
    for (int j = 1; j<k; j++)
        if ((abs(k - j) == abs(x[j] - x[k])) || (x[j] == x[k]))
            return false;
    return true;
}

bool Queen::Backtrack(int t)
{ 
    if (t>n){
        for (int i = 1; i <= n; i++)
            y[i] = x[i];
        return true;
    }
    else
        for (int i = 1; i <= n; i++)
        {
            x[t] = i;
            if (Place(t) && Backtrack(t + 1))
                return true;
        }
    return false;
}

bool Queen::QueensLV(int stopVegas)
{ 
    RandomNumber rnd;
    int k = 1;
    int count = 1;
     
    while ((k <= stopVegas) && (count>0))
    {
        count = 0;
        for (int i = 1; i <= n; i++)
        {
            x[k] = i;
            if (Place(k))
                y[count++] = i;
        }
        if (count>0)
            x[k++] = y[rnd.Random(count)]; 
    }
    return (count>0);
}

bool nQueen(int n)
{
    
    Queen X;    
    X.n = n;
    int *p = new int[n + 1];
    int *q = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        p[i] = 0;
        q[i] = 0;
    }
    X.y = p;
    X.x = q;
    int stop = 2;
    if (n>15)
        stop = n - 15;
    bool found = false;
    while (!X.QueensLV(stop));
      
    if (X.Backtrack(stop + 1))
    {
        for (int i = 1; i <= n; i++)
            cout << p[i] << " ";
        found = true;
    }
    cout << endl;
    delete[]p;
    delete[]q;
    return found;
}

int main()
{
    int n;
	cout<<"请输入几个皇后(大于等于4)："<<endl;
	cin>>n;

	nQueen(n);
	return 0;
}
