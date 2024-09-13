/*
 * main.c
 *
 *  Created on: Sep 10, 2024
 *      Author: Zeyad Hisham Elsayed
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define count_up 0
#define count_down 1

typedef unsigned char uint8;


void TIMER1_COMP_init(void);
void init_io(void);
void display_on_segment(void);
void handle_parameters(void);
void INT0_init(void);
void INT1_init(void);
void INT2_init(void);
void check_mode(void);
void handle_adjustment_buttons(void);

uint8 seconds = 0, minutes = 0, hours = 0, seconds_units = 0, seconds_tenth = 0,
		minutes_units = 0, minutes_tenth = 0, hours_units = 0, hours_tenth = 0;
uint8 mode = count_up;

int main(void) {
	init_io();
	SREG |= (1 << 7); /* Enable I Bit */
	TIMER1_COMP_init();
	INT0_init();
	INT1_init();
	INT2_init();
	while (1) {
		check_mode();
		display_on_segment();
		handle_adjustment_buttons();
	}
}

void TIMER1_COMP_init(void) {
	/* Timer 1 initialization */
	TCNT1 = 0; /* Initial Value set to 0 */
	TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10); /* choose the CTC Mode with pre-scaler 1024*/
	OCR1A = 15624; /* Set compare value */
	TIMSK |= (1 << OCIE1A); /* Enable output compare interrupt */
}

ISR(TIMER1_COMPA_vect) {
	if (mode == count_up) {
		seconds++;
		if (seconds == 60) {
			seconds = 0;
			minutes++;
		}
		if (minutes == 60) {
			minutes = 0;
			hours++;
		}
		if (hours == 24) {
			hours = 0;
		}
	} else if (mode == count_down) {
		if (seconds == 0) {
			if (minutes > 0) {
				seconds = 59;
				minutes--;
			} else if (minutes == 0 && hours > 0) {
				seconds = 59;
				minutes = 59;
				hours--;
			}
		} else {
			seconds--;
		}
	}
	if ((hours == 0) && (minutes == 0) && (seconds == 0)) {
		PORTD |= (1 << PD0); /* Turn on Alarm */
	} else {
		PORTD &= ~(1 << PD0); /* Turn off Alarm */
	}

}
void check_mode(void) {
	/* Function to check and handle the mode of the stop watch
	 * */
	if (mode == count_up) {
		PORTD |= (1 << PD4);
		PORTD &= ~(1 << PD5);
	} else if (mode == count_down) {
		PORTD |= (1 << PD5);
		PORTD &= ~(1 << PD4);
	}
	if (!(PINB & (1 << PB7))) {
		mode = !mode;  // Toggle mode
		while (!(PINB & (1 << PB7)))
			display_on_segment();
	}
}

void handle_parameters(void) {
	/* Function to calculate the tenth and units digit for each parameter (Hours , Minutes, Seconds); */
	seconds_units = seconds % 10;
	seconds_tenth = seconds / 10;
	minutes_units = minutes % 10;
	minutes_tenth = minutes / 10;
	hours_units = hours % 10;
	hours_tenth = hours / 10;
}
void init_io(void) {
	/* Function to initialize all ports as input or output */
	DDRA |= 0x3F; /* Initialize PORTA Pins (0 to 5) as output for 7 segments enable */
	DDRB = 0x00; /* Initialize PORTB Pins as Input for the Push Buttons */
	DDRC |= 0x0F; /* Initialize first 4 pins in PORTC as output for the decoder */
	DDRD |= (1 << PD4) | (1 << PD5) | (1 << PD0);
	DDRD &= ~(1 << PD2) & ~(1 << PD3);
	PORTB = 0xFF; /* Initialize all buttons connected to port B with the internal Pullup resistance */
	PORTA |= (1 << PA7);
}

void display_on_segment(void) {
	handle_parameters();
	PORTA = (1 << PA5);
	PORTC = (PORTC & 0xF0) | (seconds_units & 0x0F);
	_delay_ms(2);
	PORTA = (1 << PA4);
	PORTC = (PORTC & 0xF0) | (seconds_tenth & 0x0F);
	_delay_ms(2);
	PORTA = (1 << PA3);
	PORTC = (PORTC & 0xF0) | (minutes_units & 0x0F);
	_delay_ms(2);
	PORTA = (1 << PA2);
	PORTC = (PORTC & 0xF0) | (minutes_tenth & 0x0F);
	_delay_ms(2);
	PORTA = (1 << PA1);
	PORTC = (PORTC & 0xF0) | (hours_units & 0x0F);
	_delay_ms(2);
	PORTA = (1 << PA0);
	PORTC = (PORTC & 0xF0) | (hours_tenth & 0x0F);
	_delay_ms(2);
}

void INT0_init(void) {
	/* Initialize Interrupt 0 to reset the stop watch */
	PORTD |= (1 << PD2); /* Make the push button connected with the internal pull up resistance in the MC */
	MCUCR |= (1 << ISC01); /* Define the interrupt sense control with the falling edge */
	GICR |= (1 << INT0); /* Enable External Interrupt Request 0 */
}

ISR(INT0_vect) {
	PORTD &= ~(1 << PD0); /* Turn of Alarm while resetting */
	/* Reseting the stop watch by set all variables to zeros */
	seconds = 0, minutes = 0, hours = 0, seconds_units = 0, seconds_tenth = 0, minutes_units =
			0, minutes_tenth = 0, hours_units = 0, hours_tenth = 0;

}

void INT1_init(void) {
	/* Initialize Interrupt 1 to Pause the stop watch */
	MCUCR |= (1 << ISC11) | (1 << ISC10); /* Define the interrupt sense control with the raising edge */
	GICR |= (1 << INT1); /* Enable External Interrupt Request 1 */
}
ISR(INT1_vect) {
	/* Disabling the clock by clear the CS12 CS11 CS10 bits from TCCR1B Register */
	/* CS11 is already cleared */
	TCCR1B &= ~(1 << CS12) & ~(1 << CS10); /* Disable Clock for the TIMER 1 to stop the timer*/

}
void INT2_init(void) {
	/* Initialize Interrupt 2 to Resume the stop watch */
	MCUCSR &= ~(1 << ISC2); /* Define the interrupt sense control with the falling edge */
	GICR |= (1 << INT2); /* Enable External Interrupt Request 2 */
}
ISR(INT2_vect) {
	TCCR1B |= (1 << CS12) | (1 << CS10); /* Enabling the clock again by identifying the prescaler */
}
void handle_adjustment_buttons(void) {
	/* This function is to handle increment and decrement buttons */
	/* Increment Hours */
	if (!(PINB & (1 << PB1))) {
		if (hours < 24) {
			hours++;
		}
		while (!(PINB & (1 << PB1)))
			display_on_segment();
	}
	/* Decrement Hours */
	if (!(PINB & (1 << PB0))) {
		if (hours > 0) {
			hours--;
		}
		while (!(PINB & (1 << PB0)))
			display_on_segment();
	}

	/* Increment Minutes */
	if (!(PINB & (1 << PB4))) {
		if (minutes < 60) {
			minutes++;
		}
		while (!(PINB & (1 << PB4)))
			display_on_segment();
	}
	/* Decrement Minutes */
	if (!(PINB & (1 << PB3))) {
		if (minutes > 0) {
			minutes--;
		}
		while (!(PINB & (1 << PB3)))
			display_on_segment();
	}
	/* Increment Seconds */
	if (!(PINB & (1 << PB6))) {
		if (seconds < 60) {
			seconds++;
		}
		while (!(PINB & (1 << PB6)))
			display_on_segment();
	}
	/* Decrement Seconds */
	if (!(PINB & (1 << PB5))) {
		if (seconds > 0) {
			seconds--;
		}
		while (!(PINB & (1 << PB5)))
			display_on_segment();
	}
}
