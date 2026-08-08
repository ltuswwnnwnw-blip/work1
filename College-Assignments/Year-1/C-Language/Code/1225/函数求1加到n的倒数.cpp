#include<stdio.h>
double sum1(int n)
{
	double sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=1.0/i; 
	}
	return sum;
}
int main()
{
	int n;
	printf("ÊäÈënÖµ:");
	scanf("%d",&n);
//	double result=sum(n);
	printf("sumÎª%f\n",sum1(n)); 
} 
