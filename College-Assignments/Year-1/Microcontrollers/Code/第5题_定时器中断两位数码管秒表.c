/*
 * 第5题：编程题
 * 功能：使用T0定时中断实现两位共阴极数码管动态显示秒表，显示范围00~99秒。
 * 硬件：
 *   1. 两位共阴极数码管段选端连接P0口，高电平点亮对应段。
 *   2. 位选端十位连接P2.0，个位连接P2.1，按共阴极直接连接处理为低电平选通。
 *   3. 晶振频率12MHz，T0每1ms中断一次。
 */

#include <reg51.h>

sbit dig_tens = P2^0;
sbit dig_ones = P2^1;

unsigned char code seg_table[10] =
{
    0x3f,   /* 0 */
    0x06,   /* 1 */
    0x5b,   /* 2 */
    0x4f,   /* 3 */
    0x66,   /* 4 */
    0x6d,   /* 5 */
    0x7d,   /* 6 */
    0x07,   /* 7 */
    0x7f,   /* 8 */
    0x6f    /* 9 */
};

unsigned int ms_count = 0;
unsigned char second = 0;
unsigned char scan_flag = 0;

void timer0_init(void)
{
    TMOD &= 0xf0;       /* 清除T0控制位，保留T1设置 */
    TMOD |= 0x01;       /* T0方式1，16位定时器 */

    /*
     * 12MHz晶振下，机器周期为1us。
     * 1ms需要1000次计数，初值 = 65536 - 1000 = 64536 = 0xFC18。
     */
    TH0 = 0xfc;
    TL0 = 0x18;

    ET0 = 1;            /* 允许T0中断 */
    EA = 1;             /* 开总中断 */
    TR0 = 1;            /* 启动T0 */
}

void display_scan(void)
{
    unsigned char tens;
    unsigned char ones;

    tens = second / 10;
    ones = second % 10;

    dig_tens = 1;       /* 先关闭两位，防止重影 */
    dig_ones = 1;

    if(scan_flag == 0)
    {
        P0 = seg_table[tens];
        dig_tens = 0;   /* 选通十位，共阴极低电平有效 */
        scan_flag = 1;
    }
    else
    {
        P0 = seg_table[ones];
        dig_ones = 0;   /* 选通个位，共阴极低电平有效 */
        scan_flag = 0;
    }
}

void timer0_isr(void) interrupt 1
{
    TH0 = 0xfc;         /* 重装1ms定时初值 */
    TL0 = 0x18;

    display_scan();     /* 每1ms刷新一位数码管 */

    ms_count++;
    if(ms_count >= 1000)
    {
        ms_count = 0;
        second++;

        if(second >= 100)
        {
            second = 0; /* 00~99秒循环 */
        }
    }
}

void main(void)
{
    P0 = 0x00;
    dig_tens = 1;
    dig_ones = 1;

    timer0_init();

    while(1)
    {
        /* 主程序可在此处理其他任务，显示和计时由中断完成 */
    }
}
