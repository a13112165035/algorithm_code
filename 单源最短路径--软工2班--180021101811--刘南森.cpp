#include<stdio.h>
#define maxsize 1000  
#define n 7  //结点的数目
void dijkstra(int C[][n],int v);
int main()
{
 printf("                           ——单元最短路径算法——\n");
 int C[n][n]={
  {maxsize,13,8,maxsize,30,maxsize,32},
  {maxsize,maxsize,maxsize,maxsize,maxsize,9,7},
  {maxsize,maxsize,maxsize,5,maxsize,maxsize,maxsize},
  {maxsize,maxsize,maxsize,maxsize,6,maxsize,maxsize},
  {maxsize,maxsize,maxsize,maxsize,maxsize,2,maxsize},
  {maxsize,maxsize,maxsize,maxsize,maxsize,maxsize,17},
  {maxsize,maxsize,maxsize,maxsize,maxsize,maxsize,maxsize}
 },v=1,i,j;
 printf("【有向图的邻接矩阵】\n");
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   printf("\t%d",C[i][j]);
  }
  printf("\n");
 }
 printf("【原点1到其他各点的最短路径及其长度】\n");
 dijkstra(C,v);
}
void dijkstra(int C[][n],int v)
{
 int D[n];
 int P[n],S[n];
 int i,j,k,v1,pre;
 int min,max=maxsize,inf=1200;
 v1=v-1;
 for(i=0;i<n;i++)
 {
  D[i]=C[v1][i];   
  if(D[i]!=max)
   P[i]=v;
  else
   P[i]=0;
 }
 for(i=0;i<n;i++)
  S[i]=0;      
 S[v1]=1;D[v1]=0;  
 for(i=0;i<n-1;i++)   
 {
  min=inf;
  for(j=0;j<n;j++)
  {
   if((!S[j])&&(D[j]<min))
   {
    min=D[j];
    k=j;
   }
  }
  S[k]=1;    
  for(j=0;j<n;j++)
  {
   if((!S[j])&&(D[j]>D[k]+C[k][j]))
   {
    D[j]=D[k]+C[k][j];  
    P[j]=k+1;    
   }
  }
 } 
 for(i=0;i<n;i++)
 {
  printf("%d到%d的最短距离为",v,i+1);
  printf("%d\n",D[i]);  
  pre=P[i];
  printf("路径：%d",i+1);
  while(pre!=0) 
  {
   printf("<——%d",pre);
   pre=P[pre-1];
  }
  printf("\n");
 }
}
