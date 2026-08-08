#include<stdio.h>
int main()
{
	int a[3][4]={{2,5,7,9},{6,14,20,8},{15,0,12,3}};
	int x,y,X,Y,b[4][3];
	printf("数组a\n");
	for(x=0;x<3;x++)
	{
		for(y=0;y<4;y++)
		{
			printf("%-5d",a[x][y]);
			b[y][x]=a[x][y];
		}
		printf("\n");
	}
	printf("数组b\n");
	for(y=0;y<4;y++)
	{
		for(x=0;x<3;x++)
		{
			printf("%-5d",b[y][x]);
		}
		printf("\n");
	}
}
