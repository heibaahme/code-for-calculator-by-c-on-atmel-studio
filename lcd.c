/*
 * lcd.c
 *
 * Created: 26/05/2023 06:40:19
 *  Author: emada
 */ 
#define F_CPU 16000000
#include <util/delay.h>

#include "lcd.h"

void lcd_init(void)
{
	#if (LCD_MOOD == 8)
	{
		DIO_Setpindir(lcd_8_bit_CMD_mood,LCD_RS,DIO_PIN_OUTPUT);
		DIO_Setpindir(lcd_8_bit_CMD_mood,LCD_Rw,DIO_PIN_OUTPUT);
		DIO_Setpindir(lcd_8_bit_CMD_mood,LCD_E,DIO_PIN_OUTPUT);
		
		DIO_Setportdir(lcd_8_bit_DATA_mood,DIO_PORT_OUTPUT);
		_delay_ms(100);
		
		lcd_write_cmd(0x38);
		lcd_write_cmd(0x0E);
		lcd_write_cmd(0x01);
		
	}
	#elif (LCD_MOOD == 4)
	{
		DIO_Setpindir(lcd_4_bit_CMD_mood,LCD_RS,DIO_PIN_OUTPUT);
		DIO_Setpindir(lcd_4_bit_CMD_mood,LCD_Rw,DIO_PIN_OUTPUT);
		DIO_Setpindir(lcd_4_bit_CMD_mood,LCD_E,DIO_PIN_OUTPUT);
	
		DIO_Setpindir(lcd_4_bit_DATA_mood,DIO_PIN4,DIO_PIN_OUTPUT);
		DIO_Setpindir(lcd_4_bit_DATA_mood,DIO_PIN5,DIO_PIN_OUTPUT);
		DIO_Setpindir(lcd_4_bit_DATA_mood,DIO_PIN6,DIO_PIN_OUTPUT);
		DIO_Setpindir(lcd_4_bit_DATA_mood,DIO_PIN7,DIO_PIN_OUTPUT);
		_delay_ms(100);
		
		lcd_write_cmd(0x33);
		lcd_write_cmd(0x32);
		lcd_write_cmd(0x28);
		
		lcd_write_cmd(0x0C);
		lcd_write_cmd(0x01);
		lcd_write_cmd(0x06);
		lcd_write_cmd(0x02);
		
	}
	
	
	#endif	
}
void lcd_write_string(uint8* string)
{
	uint8 i =0;
	while(string[i] != '\0')
	{
		lcd_write_data(string[i]);
		i++;
	}
}
void lcd_write_cmd(uint8 cmd)
{
	DIO_Setpinval(lcd_4_bit_CMD_mood,LCD_RS,DIO_PIN_LOW);
	DIO_Setpinval(lcd_4_bit_CMD_mood,LCD_Rw,DIO_PIN_LOW);
	DIO_Setpinval(lcd_4_bit_CMD_mood,LCD_E,DIO_PIN_LOW);
	
	PORTA = (cmd & 0xF0) | (PORTA & 0x0F);
	DIO_Setpinval(lcd_4_bit_CMD_mood,LCD_E,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_Setpinval(lcd_4_bit_CMD_mood,LCD_E,DIO_PIN_LOW);
	
	PORTA = (cmd << 4) | (PORTA & 0x0F);
	DIO_Setpinval(lcd_4_bit_CMD_mood,LCD_E,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_Setpinval(lcd_4_bit_CMD_mood,LCD_E,DIO_PIN_LOW);
	_delay_ms(5);
	
}
void lcd_write_data(uint8 data)
{
	DIO_Setpinval(lcd_4_bit_CMD_mood,LCD_RS,DIO_PIN_HIGH);
	DIO_Setpinval(lcd_4_bit_CMD_mood,LCD_Rw,DIO_PIN_LOW); 
	DIO_Setpinval(lcd_4_bit_CMD_mood,LCD_E,DIO_PIN_LOW);
	
	PORTA = (data & 0xF0) | (PORTA & 0x0F);
	DIO_Setpinval(lcd_4_bit_CMD_mood,LCD_E,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_Setpinval(lcd_4_bit_CMD_mood,LCD_E,DIO_PIN_LOW);
	
	PORTA = (data << 4) | (PORTA & 0x0F);
	DIO_Setpinval(lcd_4_bit_CMD_mood,LCD_E,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_Setpinval(lcd_4_bit_CMD_mood,LCD_E,DIO_PIN_LOW);
	_delay_ms(5);
}
void lcd_goto(uint8 row,uint8 col)
{
	uint8 pos[2]= {0x80,0xc0};
	lcd_write_cmd(pos[row+col]);	
}
void lcd_clear(void)
{
	lcd_write_cmd(0x01); 
}
void lcd_pull_up(uint8 port,uint8 pin)
{
	switch(port)
	{
		case DIO_PORTA :
			SET_BIT(PORTA,pin);
			break;
		case DIO_PORTB :
			SET_BIT(PORTB,pin);
			break;
		case DIO_PORTC :
			SET_BIT(PORTC,pin);
			break;
		case DIO_PORTD :
			SET_BIT(PORTD,pin);
			break;
		default :
		break;
	}
}

void int_to_string(int num, char* str)
 {
	sprintf(str, "%d", num);
}