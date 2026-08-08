#include<stdio.h>
int main()
{
	int a[6];
	int i,j,t;
	printf("输入6个整数:\n");
	for(i=0;i<6;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<5-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	printf("排序后:\n");
	for(i=0;i<6;i++)
	{
		printf("%-5d",a[i]);
	}
	printf("\n");
}
