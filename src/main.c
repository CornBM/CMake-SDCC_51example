/*************************************
 * 
 *        89c52 sdcc blink demo
 * 
 * CPU: 89C52
 * FREQ: 11.0592MHz
 * PIN: P00
 * 
 * ***********************************
*/

#include "STC89xx.h"
#include "LCD1602.h"
#include "timer.h"

#define LED P00

void main()
{
    // timer0 init
    timer0_init();

    LCD_ShowString(0, 0, "89C52 Blink Demo");
    while (1)
    {

    }
}


void timer0_isr(void) __interrupt(TIM0_VECTOR) __using(TIM0_VECTOR) 
{
    static uint16_t count = MS_COUNT;
    TL0 = TIM_1MS;
    TH0 = TIM_1MS >> 8;

    if (--count)
        return;

    count = MS_COUNT;
    LED = !LED;
}
