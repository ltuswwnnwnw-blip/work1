#include<stdio.h>
int main()
{
	int a[5];
	int i; 
	for(i=0;i<5;i++)
	{
		printf("输入第%d个元素",i+1);
		scanf("%d",&a[i]);
    }
	printf("输入的五个元素为：");
	for(i=0;i<5;i++)
	{
		printf("%-4d",a[i]);
	}
	printf("\n");
} 
