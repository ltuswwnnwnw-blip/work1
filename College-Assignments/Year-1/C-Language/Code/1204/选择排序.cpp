#include<stdio.h>
int main()
{
	int a[10];
	int i,j,min,t;
	printf("输入10个整数:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<9;i++)
	{
		min=i;
		for(j=i+1;j<10;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		t=a[i];
		a[i]=a[min];
		a[min]=t;
	}
	printf("排序后：\n");
	for(i=0;i<10;i++)
	{
		printf("%-3d",a[i]);
	}
	printf("\n");
}
