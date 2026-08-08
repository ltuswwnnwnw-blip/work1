#include<stdio.h>
#include<string.h>
int main()
{
	char c1[]="123456789";
	strcpy(c1+5,"hello");
	puts(c1);
}
