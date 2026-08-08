#include<stdio.h>
int main()
{
	int month;
	printf("月份");
	scanf("%d",&month);
	switch((month-1)/3)
	{
		case 0:
	    printf("%d为第一季度",month);break;
	    case 1:
	    printf("%d为第二季度",month);break;
	    case 2:
	    printf("%d为第三季度",month);break;
	    case 3:
	    printf("%d为第四季度",month);break; 
	
	 
	}
}
