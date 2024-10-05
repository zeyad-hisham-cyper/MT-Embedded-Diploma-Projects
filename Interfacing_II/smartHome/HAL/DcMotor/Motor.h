/*
 * Motor.h
 *
 *  Created on: Oct 4, 2024
 *      Author: zeyad
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "../../MCAL/std_types.h"

#define DCMOTOR_ENABLE_EN TRUE

typedef enum {
	Clock_Wise, Anti_Clock_Wise
} DcMotor_State;

typedef struct {
	uint8 DcMotor_DIR_PORT :2;
	uint8 DcMotor_DIR_PINA :3;
	uint8 DcMotor_DIR_PINB :3;
#if(DCMOTOR_ENABLE_EN == TRUE)
	uint8 DCMotor_EN_PORT :2;
	uint8 DcMotor_EN_PIN :3;
#endif
} DcMotor;

extern DcMotor Fan;
void DcMotor_init(DcMotor *Motor);
void DcMotor_Rotate(DcMotor *Motor, DcMotor_State state, uint8 speed);
void DcMotor_STOP(DcMotor *Motor);

#endif /* MOTOR_H_ */
