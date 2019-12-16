 #include <iostream>
#include<stdlib.h>
using namespace std;

#define MaxInt 32767    
#define MVNum 100      

template<class Type>
void Dijkstra(int n,int v,Type dist[],int prev[],Type c[][MVNum])
{   
    bool s[MVNum]; 

	for(int i = 1;i<=n; i++)	
	{           						 
	    dist[i] = c[v][i];  
		s[i] = false;   
		if(dist[i]==MaxInt)  prev[i] =0;  		
		else prev[i] = v;               	
	}

   	dist[v]=0;         	 
	s[v]=true;          
 
	for(int i = 1;i < n; ++i){		
        int temp= MaxInt; 
        int u=v;
		for(int j=1;j<=n;j++) 
			if(!s[j] && dist[j] < temp){ 
				u = j;
				temp = dist[j];
			}        	
		s[u]=true;                   	 
		for(int j=1;j<=n;j++)          
			if(!s[j] && (c[u][j] < MaxInt))
			{   
			    Type newdist =dist[u]+c[u][j];
				if(newdist<dist[j])
				{
					dist[j] =newdist;   	
				    prev[j] = u;           
				}
			}
    }  
}


void DisplayPath(int prev[],int begin,int temp )
{	
	if(prev[temp]!=0){
		DisplayPath(prev,begin,prev[temp]);
		cout << prev[temp] << "-->";
	}
}
int main()
{
	cout << "***********　迪杰斯特拉算法**************" << endl;
    int n=5; 
    int start=1;
     
    int dist[MVNum];	 
    int prev[MVNum];	
   
    int c[MVNum][MVNum]={{MaxInt,MaxInt,MaxInt,MaxInt,MaxInt,MaxInt},
	                     {MaxInt,MaxInt,10,MaxInt,30,100},
						 {MaxInt,MaxInt,MaxInt,50,MaxInt,MaxInt},
						 {MaxInt,MaxInt,MaxInt,MaxInt,MaxInt,10},
						 {MaxInt,MaxInt,MaxInt,20,MaxInt,60},
						 {MaxInt,MaxInt,MaxInt,MaxInt,MaxInt,MaxInt}};
    
	//图是书中P107的图4—5 

    Dijkstra(n,start,dist,prev,c);
    
	cout << endl <<start<<"到其余点的最短路径为：\n";
	for(int i=1;i<=n;i++) 
	{
	   if(i!=start&&dist[i]<MaxInt) 
	   {
	   	 DisplayPath(prev,start,i);
	     cout <<i;
	     
	     cout <<"  最短路径长度为："<<dist[i]<<endl;
	   }
	   if(i!=start&&dist[i]==MaxInt) 
	    {
	     cout <<start<<"到"<<i<<"没有路径可以到达"<<endl;
	   }	   
	}
	system("pause");
	return 0;
}

