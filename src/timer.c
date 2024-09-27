#include "timer.h"
#include "STC89xx.h"

unsigned char count;
void timer0_init()
{
    TMOD = 0x01;
    TL0 = TIM_1MS;
    TH0 = TIM_1MS >> 8;

    TR0 = 1;
    ET0 = 1;
    EA = 1;
    count = MS_COUNT;   // 200ms
}