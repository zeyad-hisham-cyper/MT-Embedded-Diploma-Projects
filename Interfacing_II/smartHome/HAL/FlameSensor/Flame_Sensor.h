/*
 * Flame_Sensor.h
 *
 *  Created on: Oct 4, 2024
 *      Author: zeyad
 */

#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_

#include "../../MCAL/std_types.h"

#define FLAME_SENSOR_PORT_ID PORTD_ID
#define FLAME_SENSOR_PIN_ID	 PIN2_ID

typedef struct {
	uint8 PORT :2;
	uint8 PIN :3;
} FlameSensor;

extern FlameSensor flame_sensor1;
void FlameSensor_init(FlameSensor *flame);
uint8 FlameSensor_getValue(FlameSensor *flame);

#endif /* FLAME_SENSOR_H_ */
