#include<stdio.h>
int main()
{
	int i,r; 
	for(int i=1;i<=8;i++)
	{
		for(int j=9;j>i;j--)
		{
			printf(" ");
		}
		for(int r=1;r<=i;r++)
		{
			printf("-");
		}
		for(int b=1;b<i;b++)
		{
			printf("*");
		}
        printf("\n");
    } 
    for(int i=1;i<=9;i++)
    {
    	for(int b=1;b<i;b++)
    	{
    		printf(" ");
		}
		for(int j=9;j>i;j--)
		{
			printf("#");
		}
		for(int r=10;r>i;r--)
		{
			printf("+");
		}
	
	printf("\n");
	}
} 
