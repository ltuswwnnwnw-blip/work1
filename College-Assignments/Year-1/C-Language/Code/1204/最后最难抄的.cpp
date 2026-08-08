#include<stdio.h>
int main()
{
	int a[6]={1,3,5,7,9};
	int n;
	int i,pos=5;
	printf("插入前数组:");
	for(i=0;i<5;i++)
	{
		printf("%d",a[i]);
	}
	printf("\n");
	printf("输入插数:");
	scanf("%d",&n);
	for(i=0;i<5;i++)
	{
		if(n<a[i])
		{
			pos=i;
			break;
		}
	}
	for(i=4;i>=pos;i--)
	{
		a[i+1]=a[i];
	}
	a[pos]=n;
	printf("插入后数组");
	for(i=0;i<6;i++)
	{
		printf("%d",a[i]);
	}
	printf("\n");
}
