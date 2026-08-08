#include<stdio.h>
int main()
{
	float a,b;
	char op;
	printf("输入第一个数，运算符，第二人数。");
	scanf("%2f %c %2f",&a,&op,&b);
	switch(op)
	{case'+':
		printf("%.2f+%.2f=%.2f",a,b,a+b);
		break;
		case'-':
			printf("%.2f-%2f=%.2f",a,b,a-b);
			break;
			case'*':
				printf("%.2f*%2f=%.2f",a,b,a*b);
				break;
				case'/':
					printf("%.2f/%2f=%.2f",a,b,a/b);
					break;}
				
		
	
}
