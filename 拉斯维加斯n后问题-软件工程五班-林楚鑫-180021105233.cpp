#include<iostream>
#include<time.h>
#include<cstdlib>
#include<cstring>
#define MAXSIZE 100
using namespace std;
int n;
int x[MAXSIZE];
bool place(int count);
void nQueue();
bool nQueueLV();
int main(void)
{
    srand((int)time(0));
    while(cin>>n)
    {
        nQueue();
    }
    return 0;
}
bool place(int count)
{
    for(int i=1;i<count;i++)
    {
        if(abs(x[count]-x[i])==abs(count-i)||x[count]==x[i])
        {
            return false;
        }
    }
    return true;
}
void nQueue()
{
    while(!nQueueLV())
    {
        ;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<x[i]<<' ';
    }
    cout<<endl;
}
bool nQueueLV()
{
    memset(x,0,sizeof(x));
    int count=1;
    bool state=true;
    while(count<=n&&state)
    {
        state=false;
        for(int i=1;i<=n;i++)
        {
            int lie=0;
            while(lie==0)
            {
                lie=(int)((n+1)*rand()/(RAND_MAX+1.0));
            }
            x[count]=lie;
            if(place(count))
            {
                count++;
                state=true;
                break;
            }
        }
    }
    return state;
}

