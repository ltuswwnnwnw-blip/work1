#include<stdio.h>
int main()
{
	int max,x,y,X,Y;
	int a[3][4]={{11,9,33,4},{23,42,53,7},{15,6,37,8}};
	for(x=0;x<=2;x++)
	{
		for(y=0;y<=3;y++)
		{
			printf("%-4d",a[x][y]);
		}
			printf("\n"); 
		
	}
	max=a[0][0],X=0,Y=0;
	for(x=0;x<=2;x++)
	{
		for(y=0;y<=3;y++)
		{
		    if(max<a[x][y])
			max=a[x][y];
			X=x,Y=y;	
		}
	}
	printf("最大元素%d,行号%d,列号%d",max,X,Y);
	
}
