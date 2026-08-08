#include<stdio.h>
int main()
{
	int n;
	printf("输入一个正整数：");
	scanf("%d",&n);
	if(n==1)
	{printf("%d不是素数",n);}
	if(n==2)
	{printf("%d是素数",n);}
	int y=1;
	for(int z=2;z<=n/2;z++)
	{
		if(n%z==0){
		printf("%d不是素数",n);
		break;
	}
	if(z==n/2)
	{
		printf("%d为素数",n);
	}
}
} 
