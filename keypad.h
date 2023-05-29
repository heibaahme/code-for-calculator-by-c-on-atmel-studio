/*
 * keypad.h
 *
 * Created: 27/05/2023 05:46:57
 *  Author: emada
 */ 
#include "keypad_cfg.h"



#ifndef KEYPAD_H_
#define KEYPAD_H_

void KEYPAD_INIT(void);

uint8 keypad_get_pressed_buttom(void);

uint8 keypad_write_intger(uint8 val);

#endif /* KEYPAD_H_ */