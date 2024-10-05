/*
 * PWM.c
 *
 *  Created on: Oct 4, 2024
 *      Author: zeyad
 */

#include "PWM.h"
#include <avr/io.h>
void PWM_Timer0_Start(uint8 duty_cycle) {
	DDRB |= (1 << PB3);
	TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01);
	TCCR0 |= (1 << CS00) | (1 << CS02);
	OCR0 = OCR0 = (uint8) (((uint16) duty_cycle * 255) / 100);
}
