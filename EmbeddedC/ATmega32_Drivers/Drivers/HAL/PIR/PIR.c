/*
 * PIR.c
 *
 *  Created on: Oct 25, 2024
 *      Author: zeyad
 */
#include "PIR.h"
#include "../../MCAL/GPIO/gpio.h"

PIR_t pir_config = { .PIN = PIN2_ID, .PORT = PORTC_ID };

/*
 * Function to Initialize the PIR Sensor
 */
void PIR_init(PIR_t *Config_sens) {
	GPIO_setupPinDirection(Config_sens->PORT, Config_sens->PIN, PIN_INPUT);
}

/*
 * Function to return if there is motion or not
 */
uint8 PIR_IsMotionDetected(PIR_t *Config_sens) {
	return (GPIO_readPin(Config_sens->PORT, Config_sens->PIN));
}
