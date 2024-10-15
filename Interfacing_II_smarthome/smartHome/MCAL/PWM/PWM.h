/*
 * Module: PWM
 *
 * File Name: PWM.h
 *
 * Created on: Oct 4, 2024
 *
 * Author: Zeyad Hisham
 */
#ifndef PWM_H_
#define PWM_H_

/* Includes Standard Types */
#include "../std_types.h"

/*
 * Function to generate signal with a given duty cycle
 */
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
