
#include "MCAL/GPIO/gpio.h"
#include "MCAL/ADC/ADC.h"
#include "MCAL/PWM/PWM.h"
#include "MCAL/common_macros.h"
#include "HAL/LCD/LCD.h"
#include "HAL/LM35/lm35_sensor.h"
#include "HAL/LDR/LDR.h"
#include "HAL/LED/LED.h"
#include "HAL/FlameSensor/Flame_Sensor.h"
#include "HAL/Buzzer/BUZZER.h"
#include "HAL/DcMotor/Motor.h"
#include <util/delay.h>

static inline void handle_lighting_control(void);
static inline void display_control(uint8 temperature, uint8 intensity);
static inline void automatic_Fan_speed_control(void);

#define TEMP_THRESHOLD_LOW 25
#define TEMP_THRESHOLD_MEDIUM 30
#define TEMP_THRESHOLD_HIGH 35
#define TEMP_THRESHOLD_MAX 40

#define LIGHT_HIGH_INTENSITY 70
#define LIGHT_MEDIUM_INTENSITY 51
#define LIGHT_LOW_INTENSITY 16
#define LIGHT_MIN_INTENSITY 15

static uint8 Temprature = 0;
static uint8 Light_intensity = 0;
static uint8 Flame = 0;

int main(void) {
	LED_init(&Green);
	LED_init(&Blue);
	LED_init(&Red);
	DcMotor_init(&Fan);
	Buzzer_init(&Alarm);
	FlameSensor_init(&flame_sensor1);
	ADC_init();
	LCD_init();

	while (TRUE) {
		Flame = FlameSensor_getValue(&flame_sensor1);
		if (Flame) {
			Buzzer_on(&Alarm);
			LCD_DisplayStringRowColumn(0, 0, "Critical alert!     ");
			LCD_DisplayStringRowColumn(1, 0, "                    ");
		} else {
			Buzzer_off(&Alarm);
			handle_lighting_control();
			automatic_Fan_speed_control();
			display_control(Temprature, Light_intensity);
		}
	}
	return 0;
}

static inline void display_control(uint8 temperature, uint8 intensity) {
	LCD_DisplayString("   FAN is ");
	if (temperature >= TEMP_THRESHOLD_LOW) {
		LCD_DisplayString("ON ");
	} else {
		LCD_DisplayString("OFF");
	}

	LCD_MoveCursor(1, 0);
	LCD_DisplayString("TEMP=");
	LCD_intgerToString(temperature);
	if (temperature < 100) {
		LCD_DisplayString("  ");
	}

	LCD_DisplayString("LDR=");
	LCD_intgerToString(intensity);
	LCD_DisplayCharacter('%');
	if (intensity < 100) {
		LCD_DisplayString("  ");
	}
}

static inline void handle_lighting_control(void) {
	Light_intensity = LDR_getLightIntensity(LDR_sensor);

	if (Light_intensity > LIGHT_HIGH_INTENSITY) {
		LED_off(&Green);
		LED_off(&Blue);
		LED_off(&Red);
	} else if (Light_intensity >= LIGHT_MEDIUM_INTENSITY) {
		LED_off(&Green);
		LED_off(&Blue);
		LED_on(&Red);
	} else if (Light_intensity >= LIGHT_LOW_INTENSITY) {
		LED_on(&Green);
		LED_off(&Blue);
		LED_on(&Red);
	} else {
		LED_on(&Green);
		LED_on(&Blue);
		LED_on(&Red);
	}
}

static inline void automatic_Fan_speed_control(void) {
	Temprature = LM35_getTemperature(temp_sensor);

	uint8 speed = 0;
	DcMotor_State state = Clock_Wise;

	if (Temprature >= TEMP_THRESHOLD_MAX) {
		speed = 100;
	} else if (Temprature >= TEMP_THRESHOLD_HIGH) {
		speed = 75;
	} else if (Temprature >= TEMP_THRESHOLD_MEDIUM) {
		speed = 50;
	} else if (Temprature >= TEMP_THRESHOLD_LOW) {
		speed = 25;
	} else {
		DcMotor_STOP(&Fan);
	}

	DcMotor_Rotate(&Fan, state, speed);
}
