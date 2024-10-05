/*
 * Flame_Sensor.c
 *
 *  Created on: Oct 4, 2024
 *      Author: zeyad
 */

#include "../../MCAL/GPIO/gpio.h"
#include "Flame_Sensor.h"

FlameSensor flame_sensor1 = { .PORT = PORTD_ID, .PIN = PIN2_ID };
void FlameSensor_init(FlameSensor *flame) {
	GPIO_setupPinDirection(flame->PORT, flame->PIN, PIN_INPUT);
}
uint8 FlameSensor_getValue(FlameSensor *flame) {
	return (GPIO_readPin(flame->PORT, flame->PIN));
}
