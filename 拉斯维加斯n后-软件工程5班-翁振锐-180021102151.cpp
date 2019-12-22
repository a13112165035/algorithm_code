#include <iostream>
#include <cmath>
#include <ctime>
#include "RandomNumber.h"  
#include <cstdlib>
using namespace std;

int maxcount=10;
int maxindex=0;
class Queen
{
public:

    friend void nQueen(int i);
private:
    bool Place(int k);
    bool QueenLV(void);
    bool QueenLV1(void);
    int n,*x,*y;

};

bool Queen::Place(int k)
{
    for(int j=1; j<k; j++)
    {
        if((abs(k-j)==abs(x[j]-x[k]))|| (x[j]==x[k]))
        {

            return false;
        }

    }

    return true;
}

bool Queen::QueenLV()
{
    RandomNumber rnd;

    int k=1;
    int count =1;
    while((k<=n)&&(count>0))
    {
        count = 0;
        for(int i=1; i<=n; i++)
        {
            x[k]=i;
            if(Place(k))
            {
                y[count++] = i;
            }

        }
         if(count>0)
         {
             x[k++] = y[rnd.Random(count)];
         }


    }
    maxindex++;
    if(maxindex>=maxcount)
    {
      return 0;
    }
    if(count==0)
    {
        return 0;
    }
    else return 1;
   //
}

void nQueen(int n)
{
    Queen X;
    X.n = n;
    int *p = new int[n+1];
    int * q = new int[n];
    for(int i=0; i<=n; i++)
    {
        p[i] = 0;
        q[i]=0;

    }
    X.x = p;
    X.y = q;

    while(X.QueenLV())
    {

       for(int i=1; i<=n; i++)
        {
            cout<<i<<" "<<p[i]<<endl;
        }
        cout<<endl;
    }



}
bool Queen::QueenLV1()
{
    RandomNumber rnd;
    int k=1;
    int maxcout = 100;
    int count = maxcout;
    while(k<=n)
    {
        int i=0;
        for(i=1; i<count; i++)
        {
            x[k] = rnd.Random(n)+1;
            if(Place(k))
            {
                break;
            }
        }
        if(i<=count)
        {
            k++;
        }
        else break;
    }
    return (k>0);

}
int main()
{
   // Queen Q;
   // Queen Q;
    int n;
    int maxcount;
    cout << "N皇后问题（拉斯维加斯算法）" << endl;
     cout << "输入皇后个数" << endl;
    cin>>n;
     cout << "输入猜测次数" << endl;
     cin>>maxcount;
   nQueen(n);

    cout << "结束" << endl;
    return 0;
}
