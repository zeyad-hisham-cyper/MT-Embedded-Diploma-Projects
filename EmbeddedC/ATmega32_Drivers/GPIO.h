/******************************************************************************
 * Module: GPIO
 * File Name: GPIO.h
 * Description: GPIO Driver's header file
 * Author: Eng. Zeyad Hisham
 *******************************************************************************/

#ifndef GPIO_H
#define GPIO_H

#include "stdTypes.h"

/*************************************************************************
 *                              Definitions                              *
 *************************************************************************/
#define NUMBER_OF_PORT 4
#define NUMBER_OF_PINS 8

#define PORTA_ID 0
#define PORTB_ID 1
#define PORTC_ID 2
#define PORTD_ID 3

#define PIN0_ID 0
#define PIN1_ID 1
#define PIN2_ID 2
#define PIN3_ID 3
#define PIN4_ID 4
#define PIN5_ID 5
#define PIN6_ID 6
#define PIN7_ID 7
/***************************************************************************
 *                              Types Declerations                         *
 ***************************************************************************/
typedef enum
{
    PIN_INPUT,
    PIN_OUTPUT
} GPIO_PinDirectionType;

typedef enum
{
    PORT_INPUT,
    PORT_OUTPUT = 0xFF
} GPIO_PortDirectionType;



#endif