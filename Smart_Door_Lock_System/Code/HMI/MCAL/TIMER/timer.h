/*
 * timer.h
 *
 *  Created on: Oct 26, 2024
 *      Author: zeyad
 */

#ifndef MCAL_TIMER_TIMER_H_
#define MCAL_TIMER_TIMER_H_

#include "../std_types.h"

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
#define TIMER_RESET_CLK_BITS 0xF8
typedef enum{
	TIMER_0,
	TIMER_1,
	TIMER_2
}TIMER_ID_TYPE;

typedef enum {
	TIMER_NO_CLK,
	TIMER_F_CPU_CLK,
	TIMER_F_CPU_8,
	TIMER_F_CPU_64,
	TIMER_F_CPU_256,
	TIMER_F_CPU_1024
} TIMER_CLOCK_TYPE;

typedef enum{
	TIMER_NORMAL,
	TIMER_PWM,
	TIMER_CTC,
	TIMER_FAST_PWM
}TIMER_MODE_TYPE;

/*
 * Structure for Timer configurations
 */
typedef struct{
	uint16 timer_initialValue;
	uint16 timer_compareMatchValue;
	TIMER_ID_TYPE timer_ID;
	TIMER_CLOCK_TYPE timer_clock;
	TIMER_MODE_TYPE timer_mode;
}TIMER_Config_Type;


extern TIMER_Config_Type timer_def;
/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description: Function to initialize the Timer driver
 *	▪ Inputs: pointer to the configuration structure with type Timer_ConfigType.
 *	▪ Return: None
 */
void Timer_init(const TIMER_Config_Type *Config_ptr);
/*
 * Description: Function to disable the Timer via Timer_ID.
 *	▪ Inputs: Timer_ID
 *	▪ Return: None
 */
void Timer_deInit(TIMER_ID_TYPE timer_id);
/*
 * Description: Function to set the Call Back function address to the required Timer.
 *	▪ Inputs: pointer to Call Back function and Timer Id you want to set The Callback to it.
 *	▪ Return: None
 */
void Timer_setCallBack(void(*a_ptr)(void), TIMER_ID_TYPE timer_id);

#endif /* MCAL_TIMER_TIMER_H_ */
