#include<stdio.h>
int main()
{
	int a[8]={1,2,3,4,5,6,7,8};
	int b[8]={6,5,4,7,8,9,3,2};
	int c[8];
	for(int i=0;i<8;i++)
	{
		c[i]=a[i]+b[i];
		printf("%-3d",c[i]);
	}
	
} 
