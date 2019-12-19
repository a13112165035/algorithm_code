#include<iostream>

#define maxint 10000

using namespace std;

template<class Type>

void Dijkstra(int n,int v,Type dist[],int prev[],Type **c){
	bool s[n];
	for(int i=1;i<=n;i++){
		dist[i]=c[v][i];//邻接矩阵
		s[i] =false;
		if(dist[i]==maxint){
			prev[i]=0;
		}
		else{
			prev[i]=v;//前驱 
		}
	}
	dist[v]=0;s[v]=true;
	for(int i=1;i<n;i++){
		int temp=maxint;
		int u=v;
		for(int j=1;j<=n;j++)
			if((!s[j])&&(dist[j]<temp)){
				u=j;
				temp=dist[j];
			}
			s[u]=true;
			for(int j=1;j<=n;j++){
				if((!s[j])&&(c[u][j]<maxint)){
					Type newdist=dist[u]+c[u][j];
					if(newdist<dist[j]){
						dist[j]=newdist;
						prev[j]=u;
					}
				}
			}	
	}
}

void traceback(int v,int i,int prev[]){
	cout<<i<<"<--";
	i=prev[i];
	if(i!=v)traceback(v,i,prev);
	if(i==v)cout<<i<<endl;
}

int main(){
	int n;
	cout<<"请输入顶点数目n：";cin>>n;
	int v;
	cout<<"请输入源的顶点v：";cin>>v;
	
	int *dist=new int[n+1];
	int *prev=new int[n+1];
	int **c=new int*[n+1];
	
	for(int i=0;i<=n;i++){
		c[i]=new int[n+1];
	}
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i==0||j==0){
				c[i][j]=0;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			c[i][j]=maxint;
		}
	}
	int l;
	cout<<"请输入边的数目l：";cin>>l;
	for(int i=1;i<=l;i++){
		int j,k,q;
		cout<<"输入起点";cin>>j;
		cout<<"输入终点";cin>>k;
		cout<<"输入权值";cin>>q;
		c[j][k]=q;
	}
	
	cout<<"邻接矩阵输入结果："<<endl;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			cout<<c[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	Dijkstra(n,v,dist,prev,c);
	
	for(int i=1;i<=n;i++){
		cout<<dist[i]<<"\t";
	}
	cout<<endl;
	
	traceback(v,5,prev);
	
	
	return 0;
}
