#include<stdio.h>
int main()
{
	int a[4][4]={{88,99,56,27},{52,64,21,33},{51,57,98,32},{63,21,58,65}};
	printf("¶Ô½ÇÔªËØÎª£º\n");
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(i==j||i+j==3)
			{
				printf("%-4d",a[i][j]);
			}
		}
	}
} 
