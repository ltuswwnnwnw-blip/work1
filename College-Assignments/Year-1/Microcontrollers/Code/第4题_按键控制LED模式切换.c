/*
 * 第4题：编程题
 * 功能：按键S1控制P2口8个LED在4种显示模式之间循环切换。
 * 硬件：
 *   1. 8个LED通过限流电阻连接到P2口，低电平点亮。
 *   2. 按键S1连接到P1.0，按下为低电平。
 */

#include <reg51.h>

sbit key_s1 = P1^0;

unsigned char mode = 0;

void delay_ms(unsigned int ms)
{
    unsigned int i;
    unsigned char j;

    while(ms--)
    {
        for(i = 0; i < 120; i++)
        {
            for(j = 0; j < 2; j++)
            {
                ;
            }
        }
    }
}

void show_led_mode(unsigned char current_mode)
{
    switch(current_mode)
    {
        case 1:
            P2 = 0x00;      /* 模式1：全亮，低电平点亮 */
            break;

        case 2:
            P2 = 0xaa;      /* 模式2：P2.0、P2.2、P2.4、P2.6亮 */
            break;

        case 3:
            P2 = 0x55;      /* 模式3：P2.1、P2.3、P2.5、P2.7亮 */
            break;

        case 4:
        default:
            P2 = 0xff;      /* 模式4：全灭 */
            break;
    }
}

void main(void)
{
    P2 = 0xff;              /* 初始状态：8个LED全灭 */
    key_s1 = 1;             /* P1.0置1，作为按键输入 */

    while(1)
    {
        if(key_s1 == 0)     /* 检测到按键按下 */
        {
            delay_ms(20);   /* 按键消抖 */

            if(key_s1 == 0)
            {
                mode++;
                if(mode > 4)
                {
                    mode = 1;
                }

                show_led_mode(mode);

                while(key_s1 == 0)
                {
                    ;       /* 等待按键释放，避免一次按下重复切换 */
                }

                delay_ms(20); /* 释放消抖 */
            }
        }
    }
}
