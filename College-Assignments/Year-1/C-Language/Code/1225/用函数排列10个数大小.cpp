#include<stdio.h>
void sortarray(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
} 
void printarray(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d",arr[i]);
	}
	printf("\n");
}
int main()
{
	int n;
	printf("输入n:");
	scanf("%d",&n);
	if(n>=10||n<=0)
	{
		printf("输入错误!");
		return 1;
	}
	int num[9];
	printf("输入%d个正整数:",n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	sortarray(num,n);
	printf("从小到大排序结果为:");
	printarray(num,n);
}
