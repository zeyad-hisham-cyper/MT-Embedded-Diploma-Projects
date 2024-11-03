/*
 * PIR.h
 *
 *  Created on: Oct 25, 2024
 *      Author: zeyad
 */

#ifndef HAL_PIR_PIR_H_
#define HAL_PIR_PIR_H_
#include "../../MCAL/std_types.h"

typedef struct{
	uint8 PIN :3;
	uint8 PORT :2;
}PIR_t;
extern PIR_t pir_config;
/*
 * Function to Initialize the PIR Sensor
 */
void PIR_init(PIR_t *Config_sens);
/*
 * Function to return if there is motion or not
 */
uint8 PIR_IsMotionDetected(PIR_t *Config_sens);

#endif /* HAL_PIR_PIR_H_ */
