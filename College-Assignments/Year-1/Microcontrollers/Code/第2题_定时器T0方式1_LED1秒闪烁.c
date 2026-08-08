/*
 * 第2题：程序填空题
 * 功能：定时器T0方式1实现50ms定时，利用中断使P1.0连接的LED每隔1秒翻转一次。
 * 条件：晶振频率12MHz，MCS-51一个机器周期为1us。
 * 计算：50ms需要50000次计数，初值 = 65536 - 50000 = 15536 = 0x3CB0。
 */

#include <reg51.h>

sbit led = P1^0;

unsigned char count = 0;

void timer0_init(void)
{
    TMOD &= 0xf0;       /* 清除T0控制位，保留T1设置 */
    TMOD |= 0x01;       /* T0工作方式1，16位定时器模式 */
    TH0 = 0x3c;         /* 50ms定时初值高8位 */
    TL0 = 0xb0;         /* 50ms定时初值低8位 */
    ET0 = 1;            /* 允许T0中断 */
    EA = 1;             /* 开总中断 */
    TR0 = 1;            /* 启动T0 */
}

void timer0_isr(void) interrupt 1
{
    TH0 = 0x3c;         /* 重装50ms定时初值 */
    TL0 = 0xb0;

    count++;
    if(count >= 20)     /* 20 * 50ms = 1s */
    {
        count = 0;
        led = ~led;     /* LED状态翻转 */
    }
}

void main(void)
{
    led = 1;            /* 初始熄灭，若LED低电平点亮则1为灭 */
    timer0_init();

    while(1)
    {
        /* 主循环空转，LED闪烁由T0中断完成 */
    }
}
