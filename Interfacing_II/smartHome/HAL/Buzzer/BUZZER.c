/****************************
 *	Module: Buzzer
 *
 *	File Name: Buzzer.c
 *
 *  Created on: Oct 4, 2024
 *
 *  Author: zeyad
 ****************************/

#include "BUZZER.h"

#include "../../MCAL/GPIO/gpio.h"

BUZZER Alarm = { .PORT = PORTD_ID, .PIN = PIN3_ID, .state = BUZZER_ACTIVE_HIGH };

void Buzzer_init(BUZZER *buzz) {
	GPIO_setupPinDirection(buzz->PORT, buzz->PIN, PIN_OUTPUT);
}
void Buzzer_on(BUZZER *buzz) {
	GPIO_writePin(buzz->PORT, buzz->PIN,(LOGIC_HIGH ^ buzz->state));
}
void Buzzer_off(BUZZER *buzz) {
	GPIO_writePin(buzz->PORT, buzz->PIN,(LOGIC_LOW ^ buzz->state));
}

