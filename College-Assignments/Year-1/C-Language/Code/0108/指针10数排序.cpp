#include<stdio.h>
int main()
{
	int arr[10];
	int i,j;
	int temp;
	int *p=arr;
	printf("输入十个数；\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",p+1);
	} 
	for(i=0;i<9;i++)
	{
		for(j=0;j<9-i;j++)
		{
			if(*(p+j)>*(p+j+1))
			{
				temp=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=temp;
			}
		}
	}
	printf("排序后；\n");
	for(i=0;i<10;i++)
	{
		printf("%d",*(p+i));
	}
	printf("\n");
}
