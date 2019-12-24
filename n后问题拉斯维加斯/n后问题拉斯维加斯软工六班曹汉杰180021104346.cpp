#include <cstdlib>
#include <iostream>

using namespace std;

bool place(int x[],int k); 
void queen(int n,int x[]);
void Output(int n,int x[]); 
int main(int argc, char *argv[]){
    cout<<"请输入皇后的个数\n";
    int n;
    cin>>n;
    int x[n+1];
    x[0]=0;
    cout<<"解向量是\n";
    queen(n,x);
    system("PAUSE");
    return EXIT_SUCCESS;
}
bool place(int x[],int k){
    for(int i=1;i<k;i++)
        if((x[i]==x[k])||(abs(x[i]-x[k])==abs(i-k)))
            return 0;
    return 1;
}
void queen(int n,int x[]){
    int k=1;
    long num=0;
    x[1]=0;
    while(k>0){
        x[k]+=1;
        while((x[k]<=n)&&(!place(x,k)))
            x[k]+=1;
        if(x[k]<=n)
            if(k==n)
                {
                    num++;
                    Output(n,x);
                }
            else
                x[++k]=0;
        else
            x[k--]=0;
    }
    system("PAUSE");
    cout<<"一共有"<<num<<"种情况\n"; 
    return;
}
void Output(int n,int x[]){          
    cout<<"[";
    for(int i=1;i<n;i++)
        cout<<x[i]<<",";
    cout<<x[n]<<"]"<<endl;
    return;
}
