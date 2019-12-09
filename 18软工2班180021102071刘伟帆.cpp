#include<iostream>

#define LEN 6 // 连乘的矩阵个数

using namespace std;

//矩阵的维数分别是 30x35,35x15,15x5,5x10,10x20,20x25

int p[LEN + 1] ={ 30,35,15,5,10,20,25};

int m[LEN + 1][LEN + 1] = { 0,0,0};

int s[LEN + 1][LEN + 1] = { 0,0,0};

void MatrixChain(int *p,int m[][LEN + 1], int s[][LEN + 1]){

    for(int i = 0; i <= LEN; ++i){
        m[i][i] = 0;
    }//初始化，即链长为1
    for(int r = 2; r <= LEN; ++r){//链长从2到LEN

        for(int i = 1; i <= LEN - r + 1; ++i){//对i位置的矩阵计算链长为r的最优解

            int j = i + r - 1;

            m[i][j] = m[i + 1][j] + p[i-1]*p[i]*p[j];  //直接计算矩阵所需要计算的次数

            s[i][j] = i;

            for(int k = i + 1; k < j; ++k){//k 是i,j 之间的断点

                int t = m[i][k] + m[k + 1][j] + p[i-1]*p[k]*p[j];//m[i][k] + m[k + 1][j]链长短于当前链，因此已经计算出

                if(m[i][j] > t){

                    s[i][j] = k;//断开点

                    m[i][j] = t;//最小计算量

                }
            }
        }
    }
}

void TrackBack(int i, int j,int s[][LEN + 1]){

    if(i == j || i == LEN){

        cout<<"A"<<i;

        return;

    } 

    cout<<"(";

    TrackBack(i,s[i][j],s);

    cout<<")(";

    TrackBack(s[i][j] + 1,j,s);

    cout<<")";

}

int main()
{
    MatrixChain(p,m,s); 

    TrackBack(1,LEN,s);

    cout<<endl;
}
