#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
static int m[6][6];
static int s[6][6];
 

static int p[7]={30,35,15,5,10,20,25};
 
static void matrix()
{
 
 int i;
 for(i=0;i<6;i++)
  m[i][i]=0;
 

 int j;
 for(i=2;i<=6;i++)
  for(j=0;j<6-i+1;j++){
   m[j][j+i-1]=INT_MAX;
   int k;
   for(k=0;k<i-1;k++){
    if(m[j][j+i-1]>m[j][j+k]+m[j+k+1][j+i-1]+p[j]*p[j+k+1]*p[j+i]){
     m[j][j+i-1]=m[j][j+k]+m[j+k+1][j+i-1]+p[j]*p[j+k+1]*p[j+i];
     s[j][j+i-1]=k;
    }
   }
  }
}
 
static void print_matrix(int left_index,int right_index)
{
 if(left_index==right_index)
  printf("A%d",left_index);
 else{
  printf("(");
  print_matrix(left_index,left_index+s[left_index][right_index]);
  print_matrix(left_index+s[left_index][right_index]+1,right_index);
  printf(")");
 }
}
int main(int argc,char *argv[])
{
 matrix();
 printf("min total cost:\t%d\n",m[0][5]);
 print_matrix(0,5);
 printf("\n");
 return 0;
}
