/*
 * App1.h
 *
 * Created: 25/08/2022 16:44:21
 *  Author: emada
 */ 


#ifndef APP1_H_
#define APP1_H_

#include "BIT_MATH.h"
#include "atnega_regester.h"


#define  DIO_PORTA		0
#define  DIO_PORTB		1
#define  DIO_PORTC		2
#define  DIO_PORTD		3

#define  DIO_PIN0		0
#define  DIO_PIN1		1
#define  DIO_PIN2		2
#define  DIO_PIN3		3
#define  DIO_PIN4		4
#define  DIO_PIN5		5
#define  DIO_PIN6		6
#define  DIO_PIN7		7

#define  DIO_PIN_HIGH	1
#define  DIO_PIN_LOW	0

#define  DIO_PORT_HIGH	0XFF
#define  DIO_PORT_LOW	0X00

#define  DIO_PIN_OUTPUT	1
#define  DIO_PIN_INPUT	0

#define  DIO_PORT_OUTPUT	0XFF
#define  DIO_PORT_LOINPUT	0X00

void DIO_Setportdir(uint8 port , uint8 dir);
void DIO_Setpindir(uint8 port , uint8 pin , uint8 dir);

void DIO_Setportval(uint8 port , uint8 value);
void DIO_Setpinval(uint8 port , uint8 pin , uint8 val);

void DIO_Readport(uint8 port , uint8* value);
void DIO_Readpin(uint8 port , uint8 pin , uint8* val);

void DIO_TOGGLEPin(uint8 port , uint8 pin);

#endif /* APP1_H_ */