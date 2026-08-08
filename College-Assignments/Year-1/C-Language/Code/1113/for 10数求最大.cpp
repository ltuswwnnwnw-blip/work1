#include<stdio.h>
int main()
{
	float n,max;
	printf("输入第1个数");
	scanf("%f",&n);
	max=n;
	for(int i=2;i<=10;i++)
	{
		printf("输入第%d个数",i);
		scanf("%f",&n);
		if(n>max)
		{
			max=n;
		}
	}
	printf("最大值为%f",max);
}
