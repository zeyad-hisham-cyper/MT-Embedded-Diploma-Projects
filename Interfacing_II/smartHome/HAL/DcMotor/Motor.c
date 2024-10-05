/*
 * Motor.c
 *
 *  Created on: Oct 4, 2024
 *      Author: zeyad
 */

#include "Motor.h"
#include "../../MCAL/GPIO/gpio.h"
#include "../../MCAL/PWM/PWM.h"
DcMotor Fan = { .DcMotor_DIR_PORT = PORTB_ID, .DcMotor_DIR_PINA = PIN0_ID,
		.DcMotor_DIR_PINB = PIN1_ID, .DCMotor_EN_PORT = PORTB_ID,
		.DcMotor_EN_PIN = PIN3_ID };

void DcMotor_init(DcMotor *Motor) {
	GPIO_setupPinDirection(Motor->DcMotor_DIR_PORT, Motor->DcMotor_DIR_PINA,
			PIN_OUTPUT);
	GPIO_setupPinDirection(Motor->DcMotor_DIR_PORT, Motor->DcMotor_DIR_PINB,
			PIN_OUTPUT);
#if(DCMOTOR_ENABLE_EN == TRUE)
	GPIO_setupPinDirection(Motor->DCMotor_EN_PORT, Motor->DcMotor_EN_PIN,
			PIN_OUTPUT);
#endif
}

void DcMotor_Rotate(DcMotor *Motor, DcMotor_State state, uint8 speed) {
	PWM_Timer0_Start(speed);

	switch (state) {
	case Clock_Wise:
		GPIO_writePin(Motor->DcMotor_DIR_PORT, Motor->DcMotor_DIR_PINA,
		LOGIC_HIGH);
		GPIO_writePin(Motor->DcMotor_DIR_PORT, Motor->DcMotor_DIR_PINB,
		LOGIC_LOW);
		break;
	case Anti_Clock_Wise:
		GPIO_writePin(Motor->DcMotor_DIR_PORT, Motor->DcMotor_DIR_PINA,
		LOGIC_LOW);
		GPIO_writePin(Motor->DcMotor_DIR_PORT, Motor->DcMotor_DIR_PINB,
		LOGIC_HIGH);
		break;
	default:
		DcMotor_STOP(Motor);
		break;
	}
}
void DcMotor_STOP(DcMotor *Motor) {
	GPIO_writePin(Motor->DcMotor_DIR_PORT, Motor->DcMotor_DIR_PINA, LOGIC_LOW);
	GPIO_writePin(Motor->DcMotor_DIR_PORT, Motor->DcMotor_DIR_PINB, LOGIC_LOW);
}
