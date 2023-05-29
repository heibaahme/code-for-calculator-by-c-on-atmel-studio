/*
 * lcd.h
 *
 * Created: 26/05/2023 06:40:36
 *  Author: emada
 */ 

#include "lcd_cfg.h"

#ifndef LCD_H_
#define LCD_H_


void lcd_init(void);
void lcd_write_string(uint8*string);
void lcd_write_cmd(uint8 cmd);
void lcd_write_data(uint8 data);
void lcd_goto(uint8 row,uint8 col);
void lcd_pull_up(uint8 port,uint8 pin);
void lcd_clear(void);
void int_to_string(int num, char* str);

#endif /* LCD_H_ */