#include<stdio.h>
int main()
{
	int n,sum=0;
	printf("输入一个数");
	scanf("%d",&n); 
	for(int i=1;i<=n;i++){
	sum+=i;
    }
	printf("由1到%d的和为%d\n",n,sum);
}
