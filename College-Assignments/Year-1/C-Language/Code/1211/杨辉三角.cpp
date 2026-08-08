#include<stdio.h>
#define n 10
int main()
{
	int t[n][n];
	for(int i=0;i<n;i++)
	{
		t[i][0]=1;
		t[i][i]=1;
	}
	for(int i=2;i<n;i++)
	{
		for(int j=1;j<i;j++)
		{
			t[i][j]=t[i-1][j-1]+t[i-1][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			printf("%-6d",t[i][j]);
		}
		printf("\n");
	}
}
