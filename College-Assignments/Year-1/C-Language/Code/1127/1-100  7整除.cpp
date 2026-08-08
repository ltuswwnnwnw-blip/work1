#include<stdio.h>
int main()
{
	int n;
	for(n=1;n<=100;n++)
	{
		if(n%7!=0)
		continue;
		printf("%5d",n);
	}
}
