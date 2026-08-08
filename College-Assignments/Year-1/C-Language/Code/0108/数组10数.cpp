#include<stdio.h>
int main()
{
	int a[10];
	int i,temp;
	printf("输入10个数\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("原");
	for(i=0;i<10;i++)
	{
		printf("%3d",a[i]);
	}
	printf("\n");
	for(i=0;i<5;i++)
	{
		temp=a[i];
		a[i]=a[9-i];
		a[9-i]=temp;
	}
	printf("变");
	for(i=0;i<10;i++)
	{
		printf("%3d",a[i]);
	}
	
}
