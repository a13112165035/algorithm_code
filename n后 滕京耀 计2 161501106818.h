#ifndef QUEEN_H
#define QUEEN_H
 
class Queen
{
	friend bool nQueen(int);
private:
	bool Place(int k);             // ���Իʺ�k���ڵ�x[k]�еĺϷ���
	bool Backtrack(int t);         // ��n������Ļ��ݷ�
	bool QueensLV(int stopVegas);  // �������n���ʺ���˹ά��˹�㷨
	int n, *x, *y;
};
 
#endif
 
Queen.cpp�ļ�(�㷨�Ĺؼ�λ��)
 
#include <iostream>
#include "Queen.h"
#include "RandomNumber.h"
using namespace std;
bool Queen::Place(int k){
    // ���Իʺ�k���ڵ�x[k]�еĺϷ���
    for(int j = 1; j < k; ++ j)
        if((abs(k-j) == abs(x[j]-x[k])) || (x[j]==x[k]))
            return false;
    return true;
}
 
bool Queen::Backtrack(int t){
     // ��n������Ļ��ݷ�
    if(t > n){
        for(int i=1; i<=n; ++i)
            y[i] = x[i];
        return true;
    }else
       for(int i=1; i<=n; ++i){
           x[t] = i;
           if(Place(t) && Backtrack(t+1))
                return true;
       }
    return false;
}
/*
* QueensLV������Las Vegas��n�ʺ�ľ��衣�����������������⣬���������������¡�
* k�ǵ�k�У�x[k]��ʾ��k�еĻʺ����x[k]��
* ������������������濴�ˣ��Ҹ��˾��ǿ�����������ˣ���������ܼ򵥡�
* ��Ţٴ��������Ǳ�����k�����п��Է��õ��кţ���y��������������count��¼�ж��ٸ�λ�ÿ��Է���
* ��Ţڴ��������������汣��Ŀ��Է��õ��У�Ȼ�����ȡ����һ�������õ�k�еĻʺ������Las Vegas�ľ��裡
*/
bool Queen::QueensLV(int stopVegas){
     // �������n���ʺ����˹ά��˹�㷨
     RandomNumber rnd;    // �����������
     int k = 1;           // ��һ�����õĻʺ���
     int count = 1;
     // 1 <= stopVegas <= n ��ʾ����������õĻʺ���
     while((k <= stopVegas) && (count > 0)){
         count = 0;
         for(int i = 1; i<=n; ++i)      // ----------- ��
         {
             x[k] = i;
             if(Place(k))
                y[count++] = i;
         }
         if(count > 0)                   // -------------��
             x[k++] = y[rnd.Random(count)];   // ���λ��
     }
     return (count > 0);   // count > 0��ʾ����λ�óɹ�
}

