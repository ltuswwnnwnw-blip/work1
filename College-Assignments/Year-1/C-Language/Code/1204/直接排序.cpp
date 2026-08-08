#include<stdio.h>
int main()
{
	int a[10],i,j,t;
	printf("输入10个整数:\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<10;i++)
	{
		t=a[i];
		j=i-1;
		while(j>=0&&a[j]>t)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=t;
	}
	printf("排序后:\n");
	for(i=0;i<10;i++)
	{
		printf("%-4d",a[i]);
	}
	printf("\n");
}
