/*
 * APP1.c
 *
 * Created: 25/08/2022 16:43:50
 *  Author: emada
 */ 
#include "App1.h"
/****************************************************DIO_Setportdir ********************************************/


void DIO_Setportdir(uint8 port , uint8 dir)
{
	switch(port)
	{
		case DIO_PORTA:
		DDRA = dir ;
		break;
		
		case DIO_PORTB:
		DDRB = dir ;
		break;
		
		case DIO_PORTC:
		DDRC = dir ;
		break;
		
		case DIO_PORTD:
		DDRD = dir ;
		break;
		
		default:
		break;
	}
}

/********************************************* DIO_Setpindir *****************************************************/


void DIO_Setpindir(uint8 port , uint8 pin , uint8 dir)
{
	switch(dir)
	{
		case DIO_PIN_OUTPUT:
		switch(port)
		{
			case DIO_PORTA:
			SET_BIT(DDRA,pin);
			break;
			case DIO_PORTB:
			SET_BIT(DDRB,pin);
			break;
			case DIO_PORTC:
			SET_BIT(DDRC,pin);
			break;
			case DIO_PORTD:
			SET_BIT(DDRD,pin);
			break;
			default:
			break;
		}
		break;
		case DIO_PIN_INPUT:
		switch(port)
		{
			case DIO_PORTA:
			CLR_BIT(DDRA,pin);
			break;
			case DIO_PORTB:
			CLR_BIT(DDRB,pin);
			break;
			case DIO_PORTC:
			CLR_BIT(DDRC,pin);
			break;
			case DIO_PORTD:
			CLR_BIT(DDRD,pin);
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}
}
/********************************************* DIO_Setportval *****************************************************/

void DIO_Setportval(uint8 port , uint8 value)
{
	switch(port)
	{
		case DIO_PORTA:
		PORTA = value ;
		case DIO_PORTB:
		PORTB = value ;
		case DIO_PORTC:
		PORTC = value ;
		case DIO_PORTD:
		PORTD = value ;
		default:
		break;
	}
}

/********************************************* DIO_Setpinval *****************************************************/

void DIO_Setpinval(uint8 port , uint8 pin , uint8 val)
{
	switch(val)
	{
		case DIO_PIN_HIGH:
		switch(port)
		{
			case DIO_PORTA:
			SET_BIT(PORTA,pin);
			break;
			case DIO_PORTB:
			SET_BIT(PORTB,pin);
			break;
			case DIO_PORTC:
			SET_BIT(PORTC,pin);
			break;
			case DIO_PORTD:
			SET_BIT(PORTD,pin);
			break;
			default:
			break;
		}
		break;
		case DIO_PIN_LOW:
		switch(port)
		{
			case DIO_PORTA:
			CLR_BIT(PORTA,pin);
			break;
			case DIO_PORTB:
			CLR_BIT(PORTB,pin);
			break;
			case DIO_PORTC:
			CLR_BIT(PORTC,pin);
			break;
			case DIO_PORTD:
			CLR_BIT(PORTD,pin);
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}
}

/********************************************* DIO_Readport *****************************************************/
void DIO_Readport(uint8 port , uint8* value)
{
	switch(port)
	{
		case DIO_PORTA:
		*value = PINA;
		break;
		case DIO_PORTB:
		*value = PINB;
		break;
		case DIO_PORTC:
		*value = PINC;
		break;
		case DIO_PORTD:
		*value = PIND;
		break;
	}
}

/********************************************* DIO_Readpin *****************************************************/

void DIO_Readpin(uint8 port , uint8 pin , uint8* val)
{
	switch(port)
	{
		case DIO_PORTA:
		*val = GET_BIT(PINA,pin);
		break;
		case DIO_PORTB:
		*val = GET_BIT(PINB,pin);
		break;
		case DIO_PORTC:
		*val = GET_BIT(PINC,pin);
		break;
		case DIO_PORTD:
		*val = GET_BIT(PIND,pin);
		break;
	}
}

/********************************************* DIO_TOGGLE_PIN *****************************************************/

void DIO_TOGGLEPin(uint8 port , uint8 pin)
{
	switch(port)
	{
		case DIO_PORTA:
		TOGGLE_BIT(PORTA,pin);
		break;
		case DIO_PORTB:
		TOGGLE_BIT(PORTB,pin);
		break;
		case DIO_PORTC:
		TOGGLE_BIT(PORTC,pin);
		break;
		case DIO_PORTD:
		TOGGLE_BIT(PORTD,pin);
		break;
		default:
		break;
	}
}