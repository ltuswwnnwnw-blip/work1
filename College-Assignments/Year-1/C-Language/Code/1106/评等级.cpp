#include<stdio.h>
int main()
{
	float s;
	printf("输入成绩");
	scanf("%f",&s);
	if(s<0&&s>100)
	printf("有问题，重新输入!",s);
	else if(s>=90&&s<=100)
	printf("等级为A");
	else if(s>=80&&s<90)
	printf("等级为B");
	else if(s>=70&s<80)
	printf("等级为C");
	else if(s>=60&&s<70)
	printf("等级为D");
	else if(s<60)
	printf("等级为E");
	 
}
