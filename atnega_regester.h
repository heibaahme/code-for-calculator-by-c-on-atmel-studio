/*
 * atnega_regester.h
 *
 * Created: 23/08/2022 09:06:29
 *  Author: emada
 */ 

#include "STD_TYPES.h"
#ifndef ATNEGA_REGESTER_H_
#define ATNEGA_REGESTER_H_

/*********************** DIO_PORTA ***********************/
#define		DDRA (*(volatile uint8*)(0x3A))
#define		PORTA (*(volatile uint8*)(0x3B))
#define		PINA (*(volatile uint8*)(0x39))

/*********************** DIO_PORTB ***********************/

#define		DDRB (*(volatile uint8*)(0x37))
#define		PORTB (*(volatile uint8*)(0x38))
#define		PINB (*(volatile uint8*)(0x36))

/*********************** DIO_PORTC ***********************/

#define		DDRC (*(volatile uint8*)(0x34))
#define		PORTC (*(volatile uint8*)(0x35))
#define		PINC (*(volatile uint8*)(0x33))

/*********************** DIO_PORTD***********************/

#define		DDRD (*(volatile uint8*)(0x31))
#define		PORTD (*(volatile uint8*)(0x32))
#define		PIND (*(volatile uint8*)(0x30))

#endif /* ATNEGA_REGESTER_H_ */