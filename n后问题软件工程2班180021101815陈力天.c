
#include <stdio.h>
#include <math.h>
#define N 15
 
int x[N];          //皇后放置的列数
int n;            //皇后个数
int sum=0;        //可行解个数
 
int place(int k)
{
	int i;
	for(i=1;i<k;i++)
       if(abs(k-i)==abs(x[k]-x[i])||x[k]==x[i])
		   return 0;
	   return 1;
}
int queen(int k)
{
	int i;
	if(k>n)
		sum++;
	else
	   for(i=1;i<=n;i++)
	   {
		   x[k]=i;
		   if(place(k))
			   queen(k+1);
	   }
	   return sum;
}
int main()
{
	printf("Please input n:(n<15)");
	scanf("%d",&n);
	printf("%d\n",queen(1));
	return 0;
}

