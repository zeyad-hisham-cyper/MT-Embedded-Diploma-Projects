/*
 * LED.h
 *
 *  Created on: Oct 4, 2024
 *      Author: zeyad
 */

#ifndef LED_H_
#define LED_H_

#include "../../MCAL/std_types.h"

typedef enum {
	ACTIVE_HIGH, ACTIVE_LOW
} ACTIVE_STATE;

typedef struct {
	uint8 LED_PORT;
	uint8 LED_PIN;
	ACTIVE_STATE STATE;
} LED_ID;

extern LED_ID Green, Blue, Red;
void LED_init(LED_ID *id);
void LED_on(LED_ID *id);
void LED_off(LED_ID *id);

#endif /* LED_H_ */
