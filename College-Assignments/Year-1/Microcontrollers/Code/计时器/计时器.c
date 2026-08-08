#include<reg51.h>
#define SEGMENT_PORT P0
sbit LSA=P2^0;
sbit LSB=P2^1;
unsigned char code smgduan[10]={
	0x3F,
	0x06,
	0x5B,
	0x4F,
	0x66,
	0x6D,
	0x7D,
	0x7F,
	0x6f
}
unsigned char Time=60;
unsigned char sec,min;
unsigned int cout=0;
void Timer0Init();
void Display(unsigned char num);
void Delay_ms(unsigned int ms);
void main()
{
	Timer0_Init();
	while(1)
	{
		Display(Time);
		if(Time==0)
		{
			Time=60;
		}
	}
}
	void Timer0_Init()
	{
		TMOD|=0x01;
		THO=0x3C;
		TL0=0xB0;
		count++;
		if(count>=20)
		{
			count=0;
			if(Time>0)
			{
				Time--;
			}
		}
	}
	void Display(unsigned char num)
	{
		unsigned char shi,ge;
		shi=num/10;
		ge=num%10;
		SEGMENT_PORT=0x00;
		LSA=0;LSB=1;
		SEGMENT_PORT=smgduan[shi];
		Delay_ms(5);
	}
	void Delay_ms(unsigned int ms)
	{
		unsigned int i,j;
		for(i=ms,i>0,i--)
			for(j=110;j>0;j--)
	}
			