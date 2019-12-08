#include <iostream>
#include <cstdlib>
using namespace std;
class Queen{
    friend int nQueen(int);
private:
    bool Place(int k);
    void Backtrack(void);
    int n,
        * x;
    long sum;
};
bool Queen::Place(int k)
{
    for(int j=1;j<k;j++)
        if( ( abs(k-j) == abs(x[j]-x[k]) ) ||( x[j] == x[k] ) )
            return false;
    return true;
}
void Queen::Backtrack(void)
{
    x[1] = 0;
    int k = 1;
    while(k>0)
    {
        x[k]+=1;
        while( (x[k]<=n) && !(Place(k)) )
            x[k] += 1;
        if(x[k] <= n)
            if(k == n)
                sum++;
            else
            {
                k++;
                x[k] = 0;
            }
        else
            k--;
    }
}
int nQueen(int n)
{
    Queen X;
    X.n = n;
    X.sum = 0;
    int *p = new int [n+1];
    for(int i=0;i<=n;i++)
        p[i] = 0;
    X.x = p;
    X.Backtrack();
    delete [] p;
    cout<<X.sum<<endl;
    return X.sum;
}
int main()
{
	int i;
	cout<<"Please enter the number of queens:" ; 
	cin>>i;
	cout<<"N Queen's plan:"; 
    nQueen(i);
    return 0;
}
