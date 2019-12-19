template<class Type>
void Dijkstra(int n,int v,Type dist[],int prev[],Type ** c){
	bool s[maxint];
	for (int i=1;i <=n;i++){
		dist[i] = c[v][i];
		s[i] = false;
		if (dist[i] == maxint)
		  prev[i] = 0;
		else
		  prev[i] = v;
	}
	dist[v]=0; s[v]=true;
	for (int i=1;i < n; i++){
		int temp=maxint;
		int u=v;
		for (int j=1; j <=n;j++)
		   if ((!s[j]) && (dist[j]<temp)){
		   	 u = j;
		   	 temp = dist[j];
		   }
		   s[u] = true;
		   for (int j=1; j<=n; j++){
		   	 if ((!s[j]) && (c[u][j] < maxint)){
		   	    Type newdist = dist[u] + c[u][j];
		   	    if (newdist < dist[j]) {
		   	 	   dist[j] = newdist;
		   	 	   prev[j] = u;
		        } 
	         }
           }
        } 
    }
}
