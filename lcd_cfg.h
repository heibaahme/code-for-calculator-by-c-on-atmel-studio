/*
 * lcd_cfg.h
 *
 * Created: 26/05/2023 07:00:37
 *  Author: emada
 */ 

#include "App1.h"


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define lcd_8_bit_CMD_mood		DIO_PORTB
#define lcd_8_bit_DATA_mood		DIO_PORTA


#define lcd_4_bit_CMD_mood		DIO_PORTB
#define lcd_4_bit_DATA_mood		DIO_PORTA

#define LCD_RS					DIO_PIN1
#define LCD_Rw					DIO_PIN2
#define LCD_E					DIO_PIN3

#define LCD_D0					DIO_PIN0
#define LCD_D1					DIO_PIN1
#define LCD_D2					DIO_PIN2
#define LCD_D3					DIO_PIN3
#define LCD_D4					DIO_PIN4
#define LCD_D5					DIO_PIN5
#define LCD_D6					DIO_PIN6
#define LCD_D7					DIO_PIN7


#define LCD_MOOD				4



#endif /* LCD_CFG_H_ */