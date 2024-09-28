#include "timer.h"
#include "STC89xx.h"

uint16_t interval_0 = TIM_1MS;
handler timer0_handler;
void timer0_init(uint16_t interval, handler handler)
{
    interval_0 = interval;
    timer0_handler = handler;
    TMOD &= 0xF0; // set timer0 as 16-bit mode
    TMOD |= 0x01; // set timer0 as mode 1

    TL0 = interval_0;
    TH0 = interval_0 >> 8;

    ET0 = 1;// enable timer0 interrupt
    EA = 1;// enable global interrupt

    TF0 = 0;// clear timer0 interrupt flag
    TR0 = 1;// start timer0
}


void timer0_isr(void) __interrupt(TIM0_VECTOR) __using(TIM0_VECTOR) 
{
    TL0 = interval_0;
    TH0 = interval_0 >> 8;
    timer0_handler();
}

uint16_t interval_1 = TIM_1MS;
handler timer1_handler;
void timer1_init(uint16_t interval, handler handler)
{
    interval_1 = interval;
    timer1_handler = handler;
    TMOD &= 0x0F; // set timer1 as 8-bit mode
    TMOD |= 0x10; // set timer1 as mode 2

    TL1 = interval;
    TH1 = interval >> 8;

    ET1 = 1;// enable timer1 interrupt
    EA = 1;// enable global interrupt

    TF1 = 0;// clear timer1 interrupt flag
    TR1 = 1;// start timer1
}

void timer1_isr(void) __interrupt(TIM1_VECTOR) __using(TIM1_VECTOR) 
{
    TL1 = interval_1;
    TH1 = interval_1 >> 8;
    timer1_handler();
}