#include<iostream>
using namespace std;
#define BUTONG 1000000          
#define NUM 4     
int a[NUM][NUM]={
        0,2,6,4,
        BUTONG,0,3,BUTONG,
        7,BUTONG,0,1,
        5,BUTONG,12,0
    };
#define OK 1
#define ERROR 0                 
typedef int status;

bool finish(bool *S,int n)      
{
    for(int i=0;i<n;i++)
    {
        if(!S[i])
        return false;
    }
    return true; 
}

status djs(int n,int t)
{
    int D[n];
    for(int i=0;i<n;i++)
    D[i]=a[t][i];
    D[t]=0;
    bool S[n];

    for(int i=0;i<n;i++)
    S[i]=false;

    S[t]=true;

    int j=0;
        int min=BUTONG;

    while (!finish(S,n))
    {   j=0;
        min=BUTONG;

        for(int i=0;i<n;i++)      
        {
            if(S[i]) continue;

            if(min>D[i]) 
            {min=D[i];j=i;}     
        }   

        S[j]=true;     

        for(int i=0;i<n;i++)        
        {
            if(S[i]) continue;
            if(D[i]>D[j]+a[j][i])
            D[i]=D[j]+a[j][i];      
        }


    }

    for(int i=0;i<n;i++)               
    {
        printf("最短路径是（v,%d）长度是%d\n",i,D[i]);
    }
    return OK; 
}
int main()
{

    djs(NUM,1);
    return 0;

} 

