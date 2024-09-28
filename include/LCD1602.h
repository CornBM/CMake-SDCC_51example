#pragma once

#ifndef __LCD1602_H__
#define __LCD1602_H__

//引脚配置：
#define LCD_RS P36
#define LCD_RW P35
#define LCD_EN P34
#define LCD_DataPort P2
// set if you use pin to control LCD backlight and contrast ratio
#define LCD_V0 P37
#define LCD_A P07
#define LCD_K P06

//用户调用函数：
void LCD_Init();
void LCD_ShowChar(unsigned char Line,unsigned char Column,char Char);
void LCD_ShowString(unsigned char Line,unsigned char Column,char *String);
void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);
void LCD_ShowSignedNum(unsigned char Line,unsigned char Column,int Number,unsigned char Length);
void LCD_ShowHexNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);
void LCD_ShowBinNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);

#endif
