#include<stdio.h>
main()
{
	float a,b,c,temp;
	printf("Èý¸öÊý:");
	scanf("%f %f %f",&a,&b,&c);
	if(a>b&&a>c)
	{
		if(b>c)
		printf("%f,%f,%f",c,b,a);
		else
		printf("%f,%f,%f",b,c,a);
	}
	if(b>c&&b>a)
	{
	    if(c>a)
	    printf("%f,%f,%f",a,c,b);
	    else
	    printf("%f,%f,%f",c,a,b);
	}
	if(c>a&&c>b)
	{
		if(a>b)
		printf("%f,%f,%f",b,a,c);
		else
		printf("%f,%f,%f",a,b,c);
	}
}
