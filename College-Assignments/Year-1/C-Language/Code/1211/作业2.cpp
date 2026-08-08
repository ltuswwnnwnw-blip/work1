#include<stdio.h>
int main()
{
	int x,y,sum;
	int a[3][3]={{9,4,7},{5,6,1},{8,3,2}};
	for(x=0;x<=2;x++)
	{
		for(y=0;y<=2;y++)
		{
			printf("%-4d",a[x][y]);
		}
		printf("\n");
	}
	sum=a[0][0]+a[0][2]+a[1][1]+a[2][0]+a[2][2];
	printf("对角元素之和为%d",sum);
}
