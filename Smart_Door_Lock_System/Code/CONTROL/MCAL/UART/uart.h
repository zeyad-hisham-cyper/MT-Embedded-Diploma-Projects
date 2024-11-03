 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.h
 *
 * Description: Header file for the UART AVR driver
 *
 * Author: Zeyad Hisham Elsayed
 *
 *******************************************************************************/

#ifndef UART_H_
#define UART_H_

#include "../std_types.h"

/*******************************************************************************
 *                         Types Decleration                                   *
 *******************************************************************************/
typedef uint32 UART_BaudRateT;
typedef uint8 UART_StopBitT;
typedef enum {
	UART_PARITY_DISABLE,
	Reserved,
	UART_Parity_Even,
	UART_Parity_Odd
}UART_ParityMode;
typedef enum {
	UART_Size5Bit,
	UART_Size6Bit,
	UART_Size7Bit,
	UART_Size8Bit,
	UART_Size9Bit = 7
} UART_BitDataT;

typedef struct {
	UART_BaudRateT baud_rate;
	UART_BitDataT bit_data :3;
	UART_ParityMode mode :2;
	UART_StopBitT stop_bit :1;
}UART_ConfigType;

extern UART_ConfigType uart_config;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Functional responsible for Initialize the UART device by:
 * 1. Setup the Frame format like number of data bits, parity bit type and number of stop bits.
 * 2. Enable the UART.
 * 3. Setup the UART baud rate.
 */
void UART_init(const UART_ConfigType * Config_Ptr);

/*
 * Description :
 * Functional responsible for send byte to another UART device.
 */
void UART_sendByte(const uint8 data);

/*
 * Description :
 * Functional responsible for receive byte from another UART device.
 */
uint8 UART_recieveByte(void);

/*
 * Description :
 * Send the required string through UART to the other UART device.
 */
void UART_sendString(const uint8 *Str);

/*
 * Description :
 * Receive the required string until the '#' symbol through UART from the other UART device.
 */
void UART_receiveString(uint8 *Str); // Receive until #

#endif /* UART_H_ */
