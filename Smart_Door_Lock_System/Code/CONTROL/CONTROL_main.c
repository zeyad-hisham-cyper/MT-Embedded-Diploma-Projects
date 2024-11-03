/*
 * CONTROL_main.c
 *
 *  Created on: Oct 27, 2024
 *      Author: zeyad
 */

#include "MCAL/GPIO/gpio.h"
#include "MCAL/PWM/PWM.h"
#include "MCAL/TIMER/timer.h"
#include "MCAL/TWI/twi.h"
#include "MCAL/UART/uart.h"
#include "HAL/Buzzer/BUZZER.h"
#include "HAL/DcMotor/Motor.h"
#include "HAL/EEPROM/external_eeprom.h"
#include "HAL/PIR/PIR.h"
#include <util/delay.h>

/* Macros */
#define MAX_PASS_SIZE 5              /* Maximum password size */
#define UART_WAITING_KEY 0x0A        /* Key for UART waiting status */
#define DOOR_OPEN_KEY 0x0F           /* Key to open door */
#define DOOR_WAIT_KEY 0xFF           /* Key for door waiting */
#define DOOR_CLOSE_KEY 0xF0          /* Key to close door */
#define DOOR_WAITING_TIME 15         /* Time to wait for door operation */
#define LOCK_SYSTEM 0xAA             /* Key to lock system */
#define LOCK_WATING_TIME 60          /* Time to wait for lock */
#define EEPROM_PASS_ADDRESS 0x0311   /* EEPROM address to store password */

/* Variables */
uint8 recived_pass[MAX_PASS_SIZE];   /* Password received from UART */
uint8 saved_pass[MAX_PASS_SIZE] = ""; /* Stored password from EEPROM */
uint8 sec = 0;                       /* Timer counter in seconds */
uint8 isLocked = FALSE;              /* System lock status */

/* Function Prototypes */
uint8 compare_pass(uint8 *ref_pass, uint8 *entered_pass, uint8 size);
void timer_callBack(void);
void save_password(uint8 *pass);
void waitForMotion(void);
void handleDoorMotor(uint8 key, DcMotor_State state);
void openDoor(void);
void lockSystem(void);
void unlockSystem(void);
void controlHardwareInit(void);

/* Main function */
int main(void) {
    /* Initialize hardware */
    controlHardwareInit();

    uint8 command, i;

    /* Wait for a key from UART to indicate readiness */
    while (UART_recieveByte() != UART_WAITING_KEY)
        ;

    /* Receive and save the initial password */
    UART_receiveString(recived_pass);
    save_password(recived_pass);

    for (;;) {
        /* Check if system is locked and unlock if time exceeded */
        if (isLocked) {
            if (sec >= 60) {
                unlockSystem();
            }
        }

        /* Wait for a command from UART */
        while (UART_recieveByte() != UART_WAITING_KEY)
            ;
        command = UART_recieveByte();

        if (command == LOCK_SYSTEM) {
            lockSystem();
        }

        unlockSystem();

        if (command == '+') { /* Command to open door */
            for (i = 0; i < 3; i++) {
                while (UART_recieveByte() != UART_WAITING_KEY)
                    ;
                UART_receiveString(recived_pass);

                /* Check password and open door if matched */
                if (compare_pass(saved_pass, recived_pass, MAX_PASS_SIZE)) {
                    openDoor();
                    break;
                } else {
                    UART_sendByte(UART_WAITING_KEY);
                    UART_sendByte(FALSE); /* Indicate failed attempt */
                }
            }
        } else if (command == '-') { /* Command to change password */
            while (UART_recieveByte() != UART_WAITING_KEY)
                ;
            UART_receiveString(recived_pass);

            if (compare_pass(saved_pass, recived_pass, MAX_PASS_SIZE)) {
                UART_sendByte(UART_WAITING_KEY);
                UART_sendByte(TRUE); /* Indicate password match */
                while (UART_recieveByte() != UART_WAITING_KEY)
                    ;
                UART_receiveString(recived_pass);
                save_password(recived_pass); /* Save new password */
            } else {
                UART_sendByte(UART_WAITING_KEY);
                UART_sendByte(FALSE); /* Indicate failed match */
            }
        }
    }
    return 0;
}

/*
 * controlHardwareInit
 * Initializes all hardware components.
 */
void controlHardwareInit(void) {
    UART_init(&uart_config);
    TWI_init(&TWI_Config);
    Timer_init(&timer_def);
    Timer_setCallBack(timer_callBack, timer_def.timer_ID);
    DcMotor_init(&door_motor);
    PIR_init(&pir_config);
    Buzzer_init(&Alarm);
    LCD_init();
    __asm__("SEI");
}

/*
 * compare_pass
 * Compares two passwords for equality.
 * Parameters:
 *   ref_pass - Reference password.
 *   entered_pass - Entered password to compare.
 *   size - Size of the passwords.
 * Returns:
 *   TRUE if passwords match, otherwise FALSE.
 */
uint8 compare_pass(uint8 *ref_pass, uint8 *entered_pass, uint8 size) {
    for (uint8 i = 0; i < size; i++) {
        if (ref_pass[i] != entered_pass[i]) {
            return FALSE;
        }
    }
    return TRUE;
}

/*
 * save_password
 * Saves password to EEPROM and updates saved_pass variable.
 * Parameters:
 *   pass - Password to save.
 */
void save_password(uint8 *pass) {
    EEPROM_writeString(EEPROM_PASS_ADDRESS, pass);
    _delay_ms(10);
    EEPROM_readString(EEPROM_PASS_ADDRESS, saved_pass, MAX_PASS_SIZE);
}

/*
 * timer_callBack
 * Timer callback function to increment second variable every second.
 */
void timer_callBack(void) {
    sec++;
}

/*
 * openDoor
 * Opens the door if motion is detected and then closes it.
 */
void openDoor(void) {
    UART_sendByte(UART_WAITING_KEY);
    UART_sendByte(TRUE);
    handleDoorMotor(DOOR_OPEN_KEY, Clock_Wise);

    if (PIR_IsMotionDetected(&pir_config)) {
        waitForMotion();
    }

    handleDoorMotor(DOOR_CLOSE_KEY, Anti_Clock_Wise);
    UART_sendByte(UART_WAITING_KEY);
    UART_sendByte(0);
}

/*
 * handleDoorMotor
 * Controls door motor to open or close based on key and state.
 * Parameters:
 *   key - Key indicating door operation (open or close).
 *   state - Motor state (Clock_Wise or Anti_Clock_Wise).
 */
void handleDoorMotor(uint8 key, DcMotor_State state) {
    UART_sendByte(UART_WAITING_KEY);
    UART_sendByte(key);
    sec = 0;

    while (sec <= DOOR_WAITING_TIME) {
        DcMotor_Rotate(&door_motor, state, 100);
        if (sec >= DOOR_WAITING_TIME) {
            DcMotor_STOP(&door_motor);
            break;
        }
    }
}

/*
 * waitForMotion
 * Waits until motion is no longer detected by the PIR sensor.
 */
void waitForMotion(void) {
    UART_sendByte(UART_WAITING_KEY);
    UART_sendByte(DOOR_WAIT_KEY);

    while (PIR_IsMotionDetected(&pir_config)) {
        /* Wait until no motion is detected */
    }
}

/*
 * lockSystem
 * Locks the system, activates buzzer, and waits for lock timeout.
 */
void lockSystem(void) {
    Buzzer_on(&Alarm);
    sec = 0;
    isLocked = TRUE;

    while (sec < LOCK_WATING_TIME)
        ; /* Wait until lock timeout */
}

/*
 * unlockSystem
 * Unlocks the system and deactivates the buzzer.
 */
void unlockSystem(void) {
    Buzzer_off(&Alarm);
    isLocked = FALSE;
}
