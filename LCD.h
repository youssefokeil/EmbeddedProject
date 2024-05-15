#ifndef LCD_H
#define LCD_H
#include "tm4c123gh6pm.h"
#include "STD_TYPES.h"
#include <stdio.h>

#define lcd_Clear           0x01          // replace all characters with ASCII 'space'
#define lcd_Home            0x02          // return cursor to first position on first line                   
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_SetCursor_2     0xC0          // set cursor position 2nd line
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor_1     0x80          // set cursor position 1st line
#define lcd_Turnondisplay   0x0F          // Turn on display
#define lcd_Wakeup          0x30          // Wake up LCD



void LCD_Init(void);
void LCD_Command(u8 cmd);
void LCD_Char(u8 data);
void _delay_ms(u8 mill_sec);
void LCD_String(u8* String, u8 Index,float distance);
#endif
