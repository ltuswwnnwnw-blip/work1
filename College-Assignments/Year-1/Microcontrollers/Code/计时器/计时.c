#include <REGX51.H>
sbit KEY_HOUR = P3^5;
sbit KEY_MIN =P3^6;
sbit KEY_SEC = P3^7;
unsigned char hour=0;
unsigned char min=0;
unsigned char sec=0;
unsigned char timer_count=0;
unsigned char scan_index=0;
unsigned char code SEG_CODE[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
unsigned char code WEI_CODE[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
unsigned char display_buf[8];
void delay_ms(unsigned int ms)
{
	unsigned int i,j;
	for(i=0;i<ms;i++)
	{
		for(j=0;j<120;j++);
	}
}
void Update_Display_Buf()
{
	display_buf[0]=SEG_CODE[hour/10];
	display_buf[1]=SEG_CODE[hour%10];
	display_buf[2]=0x40;
	display_buf[3]=SEG_CODE[min/10];
	display_buf[4]=SEG_CODE[min%10];
	display_buf[5]=0x40;
	display_buf[6]=SEG_CODE[sec/10];
	display_buf[7]=SEG_CODE[sec%10];
}
void Display_Scan()
{
	P2=0x00;
	P0=display_buf[scan_index];
	P2=WEI_CODE[scan_index];
	scan_index++;
	if(scan_index>=8)
	{
		scan_index=0;
	}
}
void Key_Scan()
{
	if(KEY_HOUR==0)
	{
		delay_ms(10);
		if(KEY_HOUR==0)
		{
			hour++;
			if(hour>=24)
			{
				hour=0;
	  	}
		  while(KEY_HOUR==0);
	  }
  }
	if(KEY_MIN==0)
	{
		delay_ms(10);
		if(KEY_MIN==0)
		{
			min++;
			if(min>=60)
			{
				min=0;
	  	}
		  while(KEY_MIN==0);
	  }
  }
	if(KEY_SEC==0)
	{
		delay_ms(10);
		if(KEY_SEC==0)
		{
			sec++;
			if(sec>=60)
			{
				sec=0;
	  	}
		  while(KEY_SEC==0);
	  }
  }
}
void Timer0_Init()
{
	TMOD=0x01;
	TH0=0x3C;
	TL0=0xB0;
	ET0=1;
	EA=1;
	TR0=1;
}
void Timer0_ISR() interrupt 1
{
	TH0=0x3C;
	TL0=0xB0;
	timer_count++;
	if(timer_count>=20)
	{
		timer_count=0;
		sec++;
		if(sec>=60)
		{
			sec=0;
			min++;
		}
		if(min>=60)
		{
			min=0;
			hour++;
		}
		if(hour>=24)
		{
			hour=0;
		}
	}
}
void main()
{
	P0=0x00;
	P2=0x00;
	P3=0xFF;
	Timer0_Init();
	while(1)
	{
		Key_Scan();
		Update_Display_Buf();
		Display_Scan();
		delay_ms(1);
	}
}