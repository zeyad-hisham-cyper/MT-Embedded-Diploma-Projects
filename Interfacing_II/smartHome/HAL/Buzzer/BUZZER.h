/****************************
 *	Module: Buzzer
 *
 *	File Name: Buzzer.h
 *
 *  Created on: Oct 4, 2024
 *
 *  Author: zeyad
 ****************************/

#ifndef BUZZER_H_
#define BUZZER_H_

/* Include Standard Types */
#include "../../MCAL/std_types.h"

typedef enum {
	BUZZER_ACTIVE_HIGH, BUZZER_ACTIVE_LOW
} BUZZER_state;

typedef struct {
	uint8 PORT :2;
	uint8 PIN :3;
	BUZZER_state state :1;
} BUZZER;

extern BUZZER Alarm;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void Buzzer_init(BUZZER *buzz);
void Buzzer_on(BUZZER *buzz);
void Buzzer_off(BUZZER *buzz);
void Buzzer_toggle(BUZZER *buzz);

#endif /* BUZZER_H_ */
