#include<stdio.h>
#include<math.h>
main()
{
	float x,y,z;
	printf("输入一个数:");
	scanf("%f",&x);
	z=pow(x,2);
	y=sqrt(z);
	printf("绝对值为:%f",y); 
}
