#include<stdio.h>
int main()
{
	int a[5];
	for(int i=0;i<5;i++)
	{
		printf("输入第%d个数",i+1);
		scanf("%d",&a[i]);
	}
	int max=a[0];
	for(int i=0;i<5;i++)
	{
		if(max<a[i])
		{
			max=a[i];
		}
	}
	printf("最大值为:%d",max);
}
