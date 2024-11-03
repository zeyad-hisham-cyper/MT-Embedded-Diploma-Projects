/*
 * timer.c
 *
 *  Created on: Oct 26, 2024
 *      Author: zeyad
 */

#include "timer.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "../GPIO/gpio.h"
#include "../common_macros.h"

TIMER_Config_Type timer_def = { .timer_initialValue = 0,
		.timer_compareMatchValue = 7813, .timer_ID = TIMER_1, . timer_clock =
				TIMER_F_CPU_1024, .timer_mode = TIMER_CTC };

/*
 * Timers Call Backs
 */
static volatile void (*g_Timer0_callBack)(void) = NULL_PTR;
static volatile void (*g_Timer1_callBack)(void) = NULL_PTR;
static volatile void (*g_Timer2_callBack)(void) = NULL_PTR;

/*
 * Description: Function to initialize the Timer driver
 *	▪ Inputs: pointer to the configuration structure with type Timer_ConfigType.
 *	▪ Return: None
 */
void Timer_init(const TIMER_Config_Type *Config_ptr) {
	switch (Config_ptr->timer_ID) {
	case (TIMER_0):
		TCNT0 = Config_ptr->timer_initialValue;
		if (Config_ptr->timer_mode == TIMER_NORMAL) {
			TCCR0 = (1 << FOC0); /* Set Normal Mode */
			TIMSK |= (1 << TOIE0); /*	Enable Over Flow Interrupt */
		} else if (Config_ptr->timer_mode == TIMER_CTC) {
			TCCR0 = (1 << FOC0) | (1 << WGM01); /* Set Compare Mode */
			OCR0 = Config_ptr->timer_compareMatchValue; /* Assign Compare Match Value */
			TIMSK |= (1 << OCIE0); /* Enable Compare interrupt */
		}
		TCCR0 = (TCCR0 & TIMER_RESET_CLK_BITS) | Config_ptr->timer_clock;
		break;
	case (TIMER_1):
		TCNT1 = Config_ptr->timer_initialValue;
		if (Config_ptr->timer_mode == TIMER_NORMAL) {
			TCCR1A = (1 << FOC1A) | (1 << FOC1B);
			TIMSK |= (1 << TOIE1);
		} else if (Config_ptr->timer_mode == TIMER_CTC) {
			TCCR1B = (1 << WGM12);
			OCR1A = Config_ptr->timer_compareMatchValue;
			TIMSK |= (1 << OCIE1A);
		}
		TCCR1B = (TCCR1B & TIMER_RESET_CLK_BITS) | Config_ptr->timer_clock;
		break;
	case (TIMER_2):
		TCNT2 = Config_ptr->timer_initialValue;
		if (Config_ptr->timer_mode == TIMER_NORMAL) {
			TCCR2 = (1 << FOC2); /* Set Normal Mode */
			TIMSK |= (1 << TOIE2); /*	Enable Over Flow Interrupt */
		} else if (Config_ptr->timer_mode == TIMER_CTC) {
			TCCR2 = (1 << FOC2) | (1 << WGM21); /* Set Compare Mode */
			OCR2 = Config_ptr->timer_compareMatchValue; /* Assign Compare Match Value */
			TIMSK |= (1 << OCIE2); /* Enable Compare interrupt */
		}
		TCCR2 = (TCCR2 & TIMER_RESET_CLK_BITS) | Config_ptr->timer_clock;
		break;
	default:
		break;
	}
}
/*
 * Description: Function to disable the Timer via Timer_ID.
 *	▪ Inputs: Timer_ID
 *	▪ Return: None
 */
void Timer_deInit(TIMER_ID_TYPE timer_id) {
	switch (timer_id) {
	case (TIMER_0):
		TCCR0 = 0;
		CLEAR_BIT(TIMSK, TOIE0);
		CLEAR_BIT(TIMSK, OCIE0);
		break;
	case (TIMER_1):
		TCCR1A = 0;
		TCCR1B = 0;
		CLEAR_BIT(TIMSK, TOIE1);
		CLEAR_BIT(TIMSK, OCIE1A);
		break;
	case (TIMER_2):
		TCCR2 = 0;
		CLEAR_BIT(TIMSK, TOIE2);
		CLEAR_BIT(TIMSK, OCIE2);
		break;
	}
}
/*
 * Description: Function to set the Call Back function address to the required Timer.
 *	▪ Inputs: pointer to Call Back function and Timer Id you want to set The Callback to it.
 *	▪ Return: None
 */
void Timer_setCallBack(void (*a_ptr)(void), TIMER_ID_TYPE timer_id) {
	switch (timer_id) {
	case (TIMER_0):
		g_Timer0_callBack = a_ptr;
		break;
	case (TIMER_1):
		g_Timer1_callBack = a_ptr;
		break;
	case (TIMER_2):
		g_Timer2_callBack = a_ptr;
		break;
	}
}
/*
 * ISR Functions
 */

/* ISR for Timer 0 over flow mode */
ISR(TIMER0_OVF_vect) {
	if (g_Timer0_callBack != NULL_PTR) {
		(*g_Timer0_callBack)();
	}
}

/* ISR for Timer 0 Compare mode */
ISR(TIMER0_COMP_vect) {
	if (g_Timer0_callBack != NULL_PTR) {
		(*g_Timer0_callBack)();
	}
}

/* ISR for Timer 1 over flow mode */
ISR(TIMER1_OVF_vect) {
	if (g_Timer1_callBack != NULL_PTR) {
		(*g_Timer1_callBack)();
	}
}

/* ISR for Timer 1 Compare mode */
ISR(TIMER1_COMPA_vect) {
	if (g_Timer1_callBack != NULL_PTR) {
		(*g_Timer1_callBack)();
	}
}

/* ISR for Timer 2 over flow mode */
ISR(TIMER2_OVF_vect) {
	if (g_Timer2_callBack != NULL_PTR) {
		(*g_Timer2_callBack)();
	}
}

/* ISR for Timer 1 Compare mode */
ISR(TIMER2_COMP_vect) {
	if (g_Timer2_callBack != NULL_PTR) {
		(*g_Timer2_callBack)();
	}
}

