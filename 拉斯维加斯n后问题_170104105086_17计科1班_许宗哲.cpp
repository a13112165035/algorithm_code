#include<bits/stdc++.h>
using namespace std;
int n,x[1005];
bool place(int k){
    for(int j=1;j<k;j++)
        if(x[j]==x[k]||(abs(k-j)==abs(x[k]-x[j])))
            return false;
    return true;
}
int random_create(){
    return (rand()%n)+1;
}
int main(){
    cin>>n;
    if(n<4){
        cout<<"No solution"<<endl;
        return 0;
    }
    srand(time(0));
    int i,j,k,flag=1,countn=1;
    while(flag==1){
        countn++;
        for(i=1;i<=n;i++){
            x[i]=random_create();
            if(!place(i)){
                break;
            }
        }
        if(i==n+1){
            for(j=1;j<=n;j++){
                for(k=1;k<=n;k++){
                    if(k==x[j])
                        cout<<"* ";
                    else
                        cout<<"0 ";
                }
                cout<<endl;
            }
            flag=0;
        }
    }
    cout<<"\nposition: ";
    for(i=1;i<=n;i++)
        cout<<x[i]<<" ";
    cout<<"\n共运行了"<<countn<<"次"<<endl;
    return 0;
}
