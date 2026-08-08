#include<reg52.h>
sbit LSA_A=P2^2;
sbit LSA_B=P2^3;
sbit LSA_C=P2^4;
#define DIGIT_NUM 8
#define SEG_PORT P0
unsigned char code SEG_TABLE[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned char code DISPLAY_STR[]={2,0,2,5,1,0,2,7};

void delay_us(unsigned int us)
{
	while(us--);
}
void delay_ms(unsigned int ms)
{
	unsigned int i,j;
	for(i=0;i<ms;i++)
	  { 
			for(j=0;j<123;j++);
		}
}
void display_one_bit(unsigned char bit_pos,unsigned char num)
{
	SEG_PORT=0x00;
	LSA_A=0; LSA_B=0; LSA_C=0;
	LSA_A=bit_pos&0x01;
	LSA_B=bit_pos&0x02;
	LSA_C=bit_pos&0x04;
	SEG_PORT=SEG_TABLE[num];
	delay_ms(1);
}
void main(void)
{
	unsigned char i;
	while(1)
	{
		for(i=0;i<DIGIT_NUM;i++)
		{
			display_one_bit(i,DISPLAY_STR[i]);
		}
	}
}