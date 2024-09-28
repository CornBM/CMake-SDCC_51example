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

#define LCD P00
#define LCD_GND P10

// control the contrast ratio of LCD1602 by PWM
void handle_timer0()
{
    static unsigned char time = 0;
    static unsigned char pwm_time = 35;
    time++;
    if (time >= 100) // 1khz
        time = 0;
    if (time <= pwm_time) // 占空比%30,可改
        LCD_V0 = 1;
    else
        LCD_V0 = 0;
}

void handle_timer1()
{
    static int count = 1000;
    if (--count)
        return;

    count = 1000;
    LCD = !LCD;
}

void main()
{
    LCD_A = 1;
    LCD_K = 0;
    LCD_GND = 0;

    LCD_V0 = 0;

    // timer init
    timer0_init(TIM_10US, handle_timer0);
    timer1_init(TIM_1MS, handle_timer1);
    // LCD1602 init
    LCD_Init();
    LCD_ShowString(1, 1, "8052 Blink Demo");
    while (1)
    {

    }
}


