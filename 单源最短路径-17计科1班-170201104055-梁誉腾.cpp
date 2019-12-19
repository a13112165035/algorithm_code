#include <iostream>
#include<iomanip>
using namespace std;

//#define maxint 2147483647   //真实maxint 
#define maxint 10000


template<class Type>
void Dijkstra(int n,int v,Type dist[],int prev[],Type **c)   //v是源 
{
	bool s[maxint];
	for(int i=1;i<=n;i++)
	{
		dist[i]=c[v][i]; //c[][]邻接矩阵，表示两条边之间的权，dist[]被赋值为边的权 
		s[i]=false;
		if(dist[i]==maxint) prev[i]=0;     //prev[]表示前驱，dist为maxint指没有边 
		else prev[i]=v;                    //表示i的前驱是源v 
	}
	dist[v]=0;s[v]=true;      //dist[v]=0表示源点到自身最短距离为0，s[v]=true表示v为红点集（已确定的点） 
	for(int i=1;i<n;i++)
	{
		int temp=maxint;
		int u=v;                    
		for(int j=1;j<=n;j++)
			if((!s[j])&&(dist[j]<temp))    //j和v有边且在红点集中 
			{
				u=j;                     
				temp=dist[j];
			}
			s[u]=true;                     //u变成红点 
			for(int j=1;j<=n;j++)
			{
				if((!s[j])&&(c[u][j]<maxint))
				{
					Type newdist=dist[u]+c[u][j];
					if(newdist<dist[j])    //修改特殊路径 
					{
						dist[j]=newdist;   //修改距离 
						prev[j]=u;         //修改前驱 
					}
				}
			}
		
	}	
}

int main() 
{
    int n,v,*dist,*prev,**c;
    
    while(n<=0||n==NULL)
    {
    cout<<"请输入图G顶点数量n(n>0)：";
    cin>>n;
    }    
    
    dist=new int[n+1];
    prev=new int[n+1];
    c=new int*[n+1];
    
    for(int i=1;i<=n;i++)   //初始化邻接矩阵 
    {
    	c[i]=new int[n+1];
    	for(int j=1;j<=n;j++)
		   c[i][j]=maxint;      
	}
	
	cout<<endl<<"下面开始输入有向图图G边的权："<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) continue;
			while(c[i][j]<0||c[i][j]==maxint)      
			{
				cout<<"顶点"<<i<<"到顶点"<<j<<"的距离为(非负数，0表示无边)：";  
			    cin>>c[i][j];
			}
			if(c[i][j]==0) c[i][j]=maxint;
		}
	}
	
/*	for(int i=1;i<=n;i++)
	{
		if(i==1)  
		for(int k=1;k<=n;k++) 
		{   
		   if(k==1) cout<<" ";
		   cout<<setw(8)<<k;
		}  
		cout<<endl; 
		for(int j=1;j<=n;j++)
		{
           if(j==1) cout<<i<<setw(2);
		   cout<<setw(8)<<c[i][j];
		}
		cout<<endl;
	}	
*/
    cout<<"请确定源v：";
    cin>>v;
    while(v>n||v<1)
    {
       cout<<"请确定源v：";
       cin>>v;   	
	}
    
    Dijkstra(n,v,dist,prev,c);
    for(int i=1;i<=n;i++)
    {
    	cout<<"dist["<<i<<"]="<<dist[i]<<endl;
	}
    
	return 0;
}
