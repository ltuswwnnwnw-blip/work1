#include<stdio.h>
int main()
{
	int i=1,n;
	long long sum=1;
	printf("输入一个值");
	scanf("%d",&n);
	while(i<=n)
	{sum=sum*i;i++;}
	printf("%d!=%d",n,sum);
	
	
}
