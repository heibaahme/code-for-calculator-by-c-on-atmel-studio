/*
 * keypad.c
 *
 * Created: 27/05/2023 05:47:15
 *  Author: emada
 */ 
#define F_CPU 16000000
#include "KEYPAD.h"
#include <util/delay.h>

const uint8 keypad[4][4] = { '7','8','9','/',
							 '4','5','6','*',
							 '1','2','3','-',
							 'c','0','=','+' };

#define keypad_coulm_init	0
#define keypad_coulm_final	3
#define keypad_row_init		4
#define keypad_row_final	7


void KEYPAD_INIT()
{
	DIO_Setpindir(KEYPAD_PORT,col_0,DIO_PIN_OUTPUT);
	DIO_Setpindir(KEYPAD_PORT,col_1,DIO_PIN_OUTPUT);
	DIO_Setpindir(KEYPAD_PORT,col_2,DIO_PIN_OUTPUT);
	DIO_Setpindir(KEYPAD_PORT,col_3,DIO_PIN_OUTPUT);
	
	
	
	DIO_Setpindir(KEYPAD_PORT,row_0,DIO_PIN_INPUT);
	DIO_Setpindir(KEYPAD_PORT,row_1,DIO_PIN_INPUT);
	DIO_Setpindir(KEYPAD_PORT,row_2,DIO_PIN_INPUT);
	DIO_Setpindir(KEYPAD_PORT,row_3,DIO_PIN_INPUT);
	
				  
	lcd_pull_up(KEYPAD_PORT,row_0);
	lcd_pull_up(KEYPAD_PORT,row_1);
	lcd_pull_up(KEYPAD_PORT,row_2);
	lcd_pull_up(KEYPAD_PORT,row_3);
	
	
	DIO_Setpinval(KEYPAD_PORT,col_0,DIO_PIN_HIGH);
	DIO_Setpinval(KEYPAD_PORT,col_1,DIO_PIN_HIGH);
	DIO_Setpinval(KEYPAD_PORT,col_2,DIO_PIN_HIGH);
	DIO_Setpinval(KEYPAD_PORT,col_3,DIO_PIN_HIGH);
	
}
uint8 keypad_get_pressed_buttom()
{
	uint8 loc_col = 0;
	uint8 loc_row = 0;
	uint8 pressed_buttom = 0;
	uint8 temp = 0;
	for (loc_col = keypad_coulm_init ;loc_col<= keypad_coulm_final; loc_col++)
	{
		DIO_Setpinval(KEYPAD_PORT,loc_col,DIO_PIN_LOW);
		
		for (loc_row = keypad_row_init ; loc_row <= keypad_row_final ; loc_row++)
		{
			//if(GET_BIT(loc_col,loc_row) == 0)
			//{
				//return keypad[loc_col][loc_row];
			//}
			DIO_Readpin(KEYPAD_PORT,loc_row,&temp);
			
			if (!temp)
			{
				pressed_buttom = keypad[loc_row - keypad_row_init][loc_col - keypad_coulm_init];
				while(!temp)
				{
					DIO_Readpin(KEYPAD_PORT,loc_row,&temp);
				}
				_delay_ms(10);
				
				
			}
			
		}
		DIO_Setpinval(KEYPAD_PORT,loc_col,DIO_PIN_HIGH);
	}
	return pressed_buttom;
}

uint8 keypad_write_intger(uint8 val)
{
	uint8 intger = 0;
	
	if (val <= '9')
	{
		intger = val - 48 ;
	}
	return intger ;
}