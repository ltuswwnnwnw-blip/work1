#include<stdio.h>
long long factorial(int n)
{
	if(n==0||n==1)
	{
		return 1;
	}
	else
	{
		return n*factorial(n-1);
	}
}
int main()
{
	int n;
	printf("输入非负整数n:");
	scanf("%d",&n);
	if(n<0)
	{
		printf("输入错误\n");
		return 1;
	}
	long long result=factorial(n);
	printf("%d!=%-11d\n",n,result);
	return 0;
}
