/*
 * LED.c
 *
 *  Created on: Oct 4, 2024
 *      Author: zeyad
 */

#include "LED.h"
#include "../../MCAL/GPIO/gpio.h"

LED_ID Green = { .LED_PORT = PORTB_ID, .LED_PIN = PIN6_ID, ACTIVE_HIGH };
LED_ID Blue = { .LED_PORT = PORTB_ID, .LED_PIN = PIN7_ID, ACTIVE_HIGH };
LED_ID Red = { .LED_PORT = PORTB_ID, .LED_PIN = PIN5_ID, ACTIVE_HIGH };

void LED_init(LED_ID *id) {
	GPIO_setupPinDirection(id->LED_PORT, id->LED_PIN, PIN_OUTPUT);
	LED_off(id);
}
void LED_on(LED_ID *id) {
	GPIO_writePin(id->LED_PORT, id->LED_PIN, (LOGIC_HIGH ^ id->STATE));
}
void LED_off(LED_ID *id) {
	GPIO_writePin(id->LED_PORT, id->LED_PIN, (LOGIC_LOW ^ id->STATE));
}
