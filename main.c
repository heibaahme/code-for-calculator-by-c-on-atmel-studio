/*
 * lcd_reviwe_Ali.c
 *
 * Created: 26/05/2023 06:39:45
 * Author : emada
 */ 
#include "lcd.h"
#include "keypad.h"

int main(void)
{
	uint8 num1 = 0 ;
	uint8 num2 = 0 ;
	uint8 result = 0;
	uint8 op = '\0';
	uint8 buffer[7] ;
	uint8 buffer_index = 0;
	
	
	KEYPAD_INIT();
    lcd_init();
	//lcd_write_string("Ahmed");
    while (1) 
    {
		
		
		uint8 buttom = keypad_get_pressed_buttom();
		if (buttom >= '0' && buttom <= '9')
		{
			buffer[buffer_index] = buttom;
			buffer[buffer_index + 1] = '\0' ;
			buffer_index++ ;
			lcd_write_data(buttom) ;
		}else if (buttom == '+' || buttom == '*' || buttom == '-' || buttom == '/' )
		{
			num1 = atoi(buffer);
			op = buttom ;
			buffer_index = 0 ;
			buffer[buffer_index + 1] = '\0' ;
			//lcd_goto(0, 0);
			//lcd_write_string(buffer);
			//lcd_goto(0,7);
			lcd_write_data(buttom);
		}else if (buttom == '=')
		{
			num2 = atoi(buffer);
			buffer_index = 0;
			buffer[buffer_index + 1] = '\0';
			
			// Perform calculation
			switch (op) {
			    case '+':
			    result = num1 + num2;
			    break;
			    case '-':
			    result = num1 - num2;
			    break;
			    case '*':
			    result = num1 * num2;
			    break;
			    case '/':
			    result = num1 / num2;
				break;
				default:
				break;
		}
		lcd_clear();
		lcd_goto(0, 0);
		int_to_string(num1, buffer);
		lcd_write_string(buffer);
		//lcd_goto(0, 7);
		lcd_write_data(op);
		//lcd_goto(0, 8);
		int_to_string(num2, buffer);
		lcd_write_string(buffer);
		//lcd_goto(1, 8);
		lcd_write_string("=");
		int_to_string(result, buffer);
		lcd_write_string(buffer);
    }else if (buttom == 'c')
	{
    // Clear key
    //buffer_index = 0;
    //buffer[buffer_index + 1] = '\0';
    lcd_clear();
    }
}
		}
