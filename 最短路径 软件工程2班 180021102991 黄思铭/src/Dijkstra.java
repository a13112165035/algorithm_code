public class Dijkstra {

static int MAX_SIZE=6;

public static void dijkstra(int v,float[][]a,float[]dist,int[]prev){

int n=dist.length-1;
	
if(v<1||v>n)return;
	
	boolean []s=new boolean[n+1];
	for(int i=1;i<=n;i++) {

	dist[i]=a[v][i];
	
	s[i]=false;
	
		if(dist[i]==Float.MAX_VALUE)
		
		prev[i]=0;
		
		else
		
		prev[i]=v;
		
		}
	
	dist[v]=0;s[v]=true;

	for(int i=1;i<n;i++) {
	
			float temp=Float.MAX_VALUE;
			
			int u=v;
			
			for(int j=1;j<=n;j++)

				if((!s[j])&&(dist[j]<temp)){
				
				u=j;
				
				temp=dist[j];
		
		}

	s[u]=true;
	
	for(int j=1;j<=n;j++)

if((!s[j])&&(a[u][j]<Float.MAX_VALUE)) {

				float newdist=dist[u]+a[u][j];
				
				if(newdist<dist[j]) {
				
				dist[j]=newdist;
				
				prev[j]=u;

			}

		}

	}

}

public static void main(String args[]){

		float a[][]=new float[MAX_SIZE][MAX_SIZE];float[]dist=new float[MAX_SIZE];int
		[]prev=new int[MAX_SIZE];
		
		for(int i=0;i<6;i++)
		
		for(int j=0;j<6;j++)
		
		a[i][j]=Float.MAX_VALUE;
		
		a[1][2]=10;
		
		a[1][4]=30;
        a[1][5]=100; a[2][3]=50; a[3][5]=10; a[4][3]=20; a[4][5]=60; int v=1;
 //假设从顶点1处出发
        dijkstra(v,a,dist,prev); 
        System.out.println("从1出发到2、3、4、5的最短路径依次是:"); 
        for(int j=2;j<6;j++)
        { System.out.println(dist[j]); } 
        int z=prev[5],y=prev[z],x=prev[y];
        System.out.println("从1到5最短路径经过的点为："); 
        System.out.print(x+" "+y+" "+z+" "+"5");

} }


