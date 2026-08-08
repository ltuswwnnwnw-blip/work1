#include<stdio.h>
#include<math.h>
#define PI 3.1415
main()
{
	float r,v;
	printf("输入半径:");
	scanf("%f",&r);
	v=4*PI*pow(r,3)/3;
	printf("球体体积为,%.1f\n",v);
}
