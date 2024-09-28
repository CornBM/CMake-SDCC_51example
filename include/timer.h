#pragma once

#ifndef __TIMER_H__
#define __TIMER_H__

// 配置
#define F_CPU 11059200L // 11.0592MHz
#define TIM_1MS (65536-F_CPU/12000)   // 1ms
#define TIM_10US (65536-F_CPU/120000) // 10us 0.01ms
#define MS_COUNT 500 // 200x1ms

#define EXT0_VECTOR 0  /* 0x03 external interrupt 0 */
#define TIM0_VECTOR 1  /* 0x0b timer 0 */
#define EXT1_VECTOR 2  /* 0x13 external interrupt 1 */
#define TIM1_VECTOR 3  /* 0x1b timer 1 */
#define UART0_VECTOR 4 /* 0x23 serial port 0 */

typedef void (*handler)(void);

void timer0_init(unsigned int interval, handler handler);
void timer0_isr(void) __interrupt(TIM0_VECTOR) __using(TIM0_VECTOR);

void timer1_init(unsigned int interval, handler handler);
void timer1_isr(void) __interrupt(TIM1_VECTOR) __using(TIM1_VECTOR);

#endif
