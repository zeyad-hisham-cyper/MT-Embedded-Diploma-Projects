/*
 * LDR.h
 *
 *  Created on: Oct 4, 2024
 *      Author: zeyad
 */

#ifndef LDR_H_
#define LDR_H_

#include "../../MCAL/std_types.h"

#define LDR_SENSOR_CHANNEL_ID 0
#define LDR_SENSOR_MAX_VOLT_VALUE 2.56
#define LDR_SENSOR_MAX_LIGHT_INTENSITY 100

typedef uint8 LDR;

extern LDR LDR_sensor;
uint8 LDR_getLightIntensity(LDR LDR_Channel);

#endif /* LDR_H_ */
