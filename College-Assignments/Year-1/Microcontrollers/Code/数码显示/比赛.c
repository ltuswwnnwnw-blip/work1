#include <REG52.H>

typedef unsigned char u8;
typedef unsigned int  u16;
typedef unsigned long u32;

/* ===============================
   ????
   Proteus ??? 11.0592MHz,??????
   ???? 12MHz,?? 12000000UL
   =============================== */
#define FOSC 11059200UL

#define TIMER0_RELOAD (65536UL - FOSC / 12 / 1000)
#define T0RH ((u8)(TIMER0_RELOAD >> 8))
#define T0RL ((u8)(TIMER0_RELOAD))

/* ===============================
   ?????
   ???? 7SEG-MPX-CC,???
   ???:COMMON_CATHODE = 1
   ????????,? 1 ?? 0
   =============================== */
#define COMMON_CATHODE 1

/* ===============================
   ????:????????,??? 0
   =============================== */
sbit KEY_SCORE_A  = P1^0;
sbit KEY_SCORE_B  = P1^1;
sbit KEY_START    = P1^2;
sbit KEY_STOP     = P1^3;
sbit KEY_SET      = P1^4;
sbit KEY_TIME_ADD = P1^5;
sbit KEY_TIME_DEC = P1^6;
sbit KEY_EXTRA    = P1^7;

sbit KEY_24_RUN   = P3^1;
sbit KEY_24_STOP  = P3^2;

sbit ALARM_IO     = P3^0;

/* ===============================
   ??????
   =============================== */
#define K_SCORE_A   0x0001
#define K_SCORE_B   0x0002
#define K_START     0x0004
#define K_STOP      0x0008
#define K_SET       0x0010
#define K_TIME_ADD  0x0020
#define K_TIME_DEC  0x0040
#define K_EXTRA     0x0080
#define K_24_RUN    0x0100
#define K_24_STOP   0x0200

/* ===============================
   ?????:P0.0~P0.7 = A B C D E F G DP
   =============================== */
u8 code SEG_TAB[17] = {
    0x3F,   /* 0 */
    0x06,   /* 1 */
    0x5B,   /* 2 */
    0x4F,   /* 3 */
    0x66,   /* 4 */
    0x6D,   /* 5 */
    0x7D,   /* 6 */
    0x07,   /* 7 */
    0x7F,   /* 8 */
    0x6F,   /* 9 */
    0x77,   /* A */
    0x7C,   /* b */
    0x39,   /* C */
    0x5E,   /* d */
    0x79,   /* E */
    0x71,   /* F */
    0x00    /* blank */
};

#define SEG_BLANK 16
#define SEG_DP    0x80

/* 74HC154 ? 14 ???,?? 14 ???? */
u8 code DIG_MAP[14] = {
    0, 1, 2, 3, 4, 5, 6, 7,
    8, 9, 10, 11,
    12, 13
};

/* ===============================
   ????
   =============================== */
volatile u16 sys_ms = 0;
volatile u16 one_second_cnt = 0;

volatile u8 scan_pos = 0;
volatile u8 display_buf[14];

volatile u16 game_time_sec = 10 * 60;   /* ?? 10 ??,??????? */
volatile u8  attack_24_sec = 24;

volatile u16 score_a = 0;
volatile u16 score_b = 0;

volatile bit game_running = 0;
volatile bit attack_running = 0;

volatile u16 alarm_ms = 0;

/* 0 = ????,1 = ?????? */
u8 set_mode = 0;

/* ===============================
   ????
   =============================== */
u8 ToSeg(u8 num)
{
    u8 code_value;

    if (num > 16) {
        num = SEG_BLANK;
    }

    code_value = SEG_TAB[num];

#if COMMON_CATHODE
    return code_value;
#else
    return ~code_value;
#endif
}

u8 AddDp(u8 seg)
{
#if COMMON_CATHODE
    return seg | SEG_DP;
#else
    return seg & (~SEG_DP);
#endif
}

/* ===============================
   ?? 4 ???,???
   leading_blank = 1 ?,?? 0 ??
   =============================== */
void PutNumber4(u8 *buf, u8 pos, u16 num, bit leading_blank)
{
    u8 qian, bai, shi, ge;

    if (num > 9999) {
        num = 9999;
    }

    qian = num / 1000;
    bai  = num / 100 % 10;
    shi  = num / 10 % 10;
    ge   = num % 10;

    if (leading_blank && qian == 0) {
        buf[pos] = ToSeg(SEG_BLANK);
    } else {
        buf[pos] = ToSeg(qian);
    }

    if (leading_blank && qian == 0 && bai == 0) {
        buf[pos + 1] = ToSeg(SEG_BLANK);
    } else {
        buf[pos + 1] = ToSeg(bai);
    }

    if (leading_blank && qian == 0 && bai == 0 && shi == 0) {
        buf[pos + 2] = ToSeg(SEG_BLANK);
    } else {
        buf[pos + 2] = ToSeg(shi);
    }

    buf[pos + 3] = ToSeg(ge);
}

/* ===============================
   ??????
   ? 8 ?:A ? 4 ? + B ? 4 ?
   ? 4 ?:MM.SS
   ? 2 ?:24 ?
   =============================== */
void UpdateDisplayBuffer(void)
{
    u8 temp[14];
    u8 i;
    u16 t;
    u16 a;
    u16 b;
    u8 shot;
    u8 min;
    u8 sec;

    EA = 0;
    t = game_time_sec;
    a = score_a;
    b = score_b;
    shot = attack_24_sec;
    EA = 1;

    PutNumber4(temp, 0, a, 1);
    PutNumber4(temp, 4, b, 1);

    min = t / 60;
    sec = t % 60;

    if (min > 99) {
        min = 99;
    }

    temp[8]  = ToSeg(min / 10);
    temp[9]  = AddDp(ToSeg(min % 10));
    temp[10] = ToSeg(sec / 10);
    temp[11] = ToSeg(sec % 10);

    temp[12] = ToSeg(shot / 10);
    temp[13] = ToSeg(shot % 10);

    EA = 0;
    for (i = 0; i < 14; i++) {
        display_buf[i] = temp[i];
    }
    EA = 1;
}

/* ===============================
   ????
   P0:??
   P2.0~P2.3:?? 74HC154,?????
   74HC154 ?????
   =============================== */
void DisplayScan(void)
{
#if COMMON_CATHODE
    P0 = 0x00;
#else
    P0 = 0xFF;
#endif

    P2 = (P2 & 0xF0) | DIG_MAP[scan_pos];

    P0 = display_buf[scan_pos];

    scan_pos++;

    if (scan_pos >= 14) {
        scan_pos = 0;
    }
}

/* ===============================
   ????,??? 1
   =============================== */
u16 ReadKeysRaw(void)
{
    u16 key = 0;

    if (KEY_SCORE_A  == 0) key |= K_SCORE_A;
    if (KEY_SCORE_B  == 0) key |= K_SCORE_B;
    if (KEY_START    == 0) key |= K_START;
    if (KEY_STOP     == 0) key |= K_STOP;
    if (KEY_SET      == 0) key |= K_SET;
    if (KEY_TIME_ADD == 0) key |= K_TIME_ADD;
    if (KEY_TIME_DEC == 0) key |= K_TIME_DEC;
    if (KEY_EXTRA    == 0) key |= K_EXTRA;
    if (KEY_24_RUN   == 0) key |= K_24_RUN;
    if (KEY_24_STOP  == 0) key |= K_24_STOP;

    return key;
}

/* ===============================
   ????,??“???”???
   =============================== */
u16 KeyScan(void)
{
    static u16 last_raw = 0;
    static u16 stable_key = 0;
    static u8 stable_count = 0;

    u16 raw;
    u16 event;

    raw = ReadKeysRaw();
    event = 0;

    if (raw == last_raw) {
        if (stable_count < 3) {
            stable_count++;
        } else {
            if (raw != stable_key) {
                event = raw & (~stable_key);
                stable_key = raw;
            }
        }
    } else {
        stable_count = 0;
        last_raw = raw;
    }

    return event;
}

/* ===============================
   ??????
   ???????“???”,??????????????
   =============================== */
void ResetAll(void)
{
    EA = 0;

    game_time_sec = 10 * 60;
    attack_24_sec = 24;

    score_a = 0;
    score_b = 0;

    game_running = 0;
    attack_running = 0;

    alarm_ms = 0;
    ALARM_IO = 0;

    EA = 1;
}

/* ===============================
   ??????
   =============================== */
void HandleKeyEvent(u16 key)
{
    if (key & K_SCORE_A) {
        if (score_a < 9999) {
            score_a++;
        }
    }

    if (key & K_SCORE_B) {
        if (score_b < 9999) {
            score_b++;
        }
    }

    if (key & K_START) {
        set_mode = 0;
        if (game_time_sec > 0) {
            game_running = 1;
        }
    }

    if (key & K_STOP) {
        game_running = 0;
    }

    if (key & K_SET) {
        game_running = 0;
        attack_running = 0;

        if (set_mode == 0) {
            set_mode = 1;
        } else {
            set_mode = 0;
        }
    }

    if (key & K_TIME_ADD) {
        if (set_mode) {
            if (game_time_sec <= 99 * 60 - 60) {
                game_time_sec += 60;
            }
        }
    }

    if (key & K_TIME_DEC) {
        if (set_mode) {
            if (game_time_sec >= 60) {
                game_time_sec -= 60;
            }
        }
    }

    if (key & K_EXTRA) {
        /*
           ???:
           ?????? 5 ???
           ??????? P1.7 ?“???”,
           ????? ResetAll();
        */
        if (game_time_sec <= 99 * 60 - 5 * 60) {
            game_time_sec += 5 * 60;
        }
        game_running = 0;
        attack_running = 0;
        set_mode = 0;
    }

    if (key & K_24_RUN) {
        /*
           24S ???:
           ???????? 24 ????????
           ???????????????????
        */
        attack_24_sec = 24;
        attack_running = 1;
    }

    if (key & K_24_STOP) {
        attack_running = 0;
    }
}

/* ===============================
   Timer0 ???:1ms ??
   =============================== */
void Timer0Init(void)
{
    TMOD &= 0xF0;
    TMOD |= 0x01;

    TH0 = T0RH;
    TL0 = T0RL;

    ET0 = 1;
    TR0 = 1;
    EA  = 1;
}

/* ===============================
   Timer0 ??
   1ms:
   1. ??????
   2. ??
   3. ????
   =============================== */
void Timer0_ISR(void) interrupt 1
{
    TH0 = T0RH;
    TL0 = T0RL;

    sys_ms++;

    DisplayScan();

    one_second_cnt++;

    if (one_second_cnt >= 1000) {
        one_second_cnt = 0;

        if (game_running) {
            if (game_time_sec > 0) {
                game_time_sec--;

                if (game_time_sec == 0) {
                    game_running = 0;
                    attack_running = 0;
                    alarm_ms = 3000;
                }
            }
        }

        if (attack_running) {
            if (attack_24_sec > 0) {
                attack_24_sec--;

                if (attack_24_sec == 0) {
                    attack_running = 0;
                    alarm_ms = 1500;
                }
            }
        }
    }

    if (alarm_ms > 0) {
        alarm_ms--;

        if ((alarm_ms / 100) % 2) {
            ALARM_IO = 1;
        } else {
            ALARM_IO = 0;
        }
    } else {
        ALARM_IO = 0;
    }
}

/* ===============================
   ???
   =============================== */
void main(void)
{
    u16 last_key_ms = 0;
    u16 key_event;

    P0 = 0x00;
    P1 = 0xFF;
    P2 = 0x00;
    P3 = 0xFF;

    ALARM_IO = 0;

    ResetAll();
    UpdateDisplayBuffer();
    Timer0Init();

    while (1) {
        if ((u16)(sys_ms - last_key_ms) >= 5) {
            last_key_ms = sys_ms;

            key_event = KeyScan();

            if (key_event) {
                HandleKeyEvent(key_event);
            }

            UpdateDisplayBuffer();
        }
    }
}