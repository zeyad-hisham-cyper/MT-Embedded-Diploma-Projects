/*
 * HMI_main.c
 *
 *  Created on: Oct 27, 2024
 *      Author: zeyad
 */

#include "MCAL/GPIO/gpio.h"
#include "MCAL/TIMER/timer.h"
#include "MCAL/UART/uart.h"
#include "HAL/KEYPAD/keypad.h"
#include "HAL/LCD/LCD.h"
#include "util/delay.h"

/* Macros */
#define MAX_PASS_SIZE 5              /* Maximum password size */
#define UART_WAITING_KEY 0x0A        /* Key for UART waiting status */
#define ENTER_BUTTON '='             /* Key to confirm password entry */
#define DOOR_OPEN_KEY 0x0F           /* Key to open door */
#define DOOR_WAIT_KEY 0xFF           /* Key to wait for door */
#define DOOR_CLOSE_KEY 0xF0          /* Key to close door */
#define LOCK_SYSTEM 0xAA             /* Key to lock system */
#define LOCK_WATING_TIME 60          /* Time in seconds to wait for lock */

/* LCD String Macro */
#define LCD_STR(s) ((const uint8 *)s)

/* Function Prototypes */
uint8 check_pass(uint8 *pass1, uint8 *pass2);
uint8 GetPasswordInput(uint8 *password, const uint8 *msg);
uint8 validateTwoPass(void);
void createSystemPass(void);
void handle_door(void);
uint8 checkPasswordAttempts(uint8 *pass, uint8 *msg);
void handleLockScreen(void);
void timer_callBack(void);

/* Global Variables */
uint8 pass_flag = 0;                /* Flag indicating password setup status */
uint8 pass[MAX_PASS_SIZE] = "";     /* Current password */
uint8 repass[MAX_PASS_SIZE] = "";   /* Re-entered password for confirmation */
uint8 attempt_counter = 0;          /* Counter for password attempts */
uint8 sec = 0;                      /* Timer counter in seconds */

/* Main Function */
int main(void) {
    /* Initialize LCD, UART, and Timer */
    LCD_init();
    UART_init(&uart_config);
    Timer_init(&timer_def);
    Timer_setCallBack(timer_callBack, timer_def.timer_ID);

    /* Enable global interrupts */
    __asm__("SEI");

    /* Setup the initial system password */
    createSystemPass();

    for (;;) {
        /* Display main menu options */
        LCD_clearScreen();
        LCD_DisplayStringRowColumn(0, 0, LCD_STR("+ : Open Door"));
        LCD_DisplayStringRowColumn(1, 0, LCD_STR("- : Change Pass"));

        /* Get user command from keypad */
        uint8 command = KEYPAD_getPressedKey();
        UART_sendByte(UART_WAITING_KEY);
        UART_sendByte(command);

        if (command == '+') {  /* Command to open door */
            if (checkPasswordAttempts(pass, "Enter Pass")) {
                handle_door();
            } else {
                handleLockScreen();
            }
        } else if (command == '-') {  /* Command to change password */
            GetPasswordInput(pass, LCD_STR("Enter old Pass: "));
            UART_sendByte(UART_WAITING_KEY);
            UART_sendString(pass);

            while (UART_recieveByte() != UART_WAITING_KEY)
                ;
            if (UART_recieveByte() == TRUE) {
                createSystemPass();
            } else {
                LCD_clearScreen();
                LCD_DisplayStringRowColumn(0, 0, LCD_STR("Password Mismatch"));
            }
        }
    }
    return 0;
}

/*
 * checkPasswordAttempts
 * Verifies password with a maximum of 3 attempts.
 * Parameters:
 *   pass - Password to validate.
 *   msg - Message displayed on LCD.
 * Returns:
 *   TRUE if password matches, otherwise FALSE after 3 failed attempts.
 */
uint8 checkPasswordAttempts(uint8 *pass, uint8 *msg) {
    for (attempt_counter = 0; attempt_counter < 3; attempt_counter++) {
        GetPasswordInput(pass, msg);
        UART_sendByte(UART_WAITING_KEY);
        UART_sendString(pass);

        while (UART_recieveByte() != UART_WAITING_KEY);

        if (UART_recieveByte() == TRUE) {
            return TRUE;
        }
    }
    return FALSE;
}

/*
 * handleLockScreen
 * Displays access denied message and locks the system for a set time.
 */
void handleLockScreen(void) {
    LCD_clearScreen();
    LCD_DisplayStringRowColumn(0, 0, LCD_STR("access denied"));
    UART_sendByte(UART_WAITING_KEY);
    UART_sendByte(LOCK_SYSTEM);
    sec = 0;

    /* Wait for lock timeout */
    while (sec < LOCK_WATING_TIME);
}

/*
 * createSystemPass
 * Prompts user to enter and confirm a new password, saving it if matched.
 */
void createSystemPass(void) {
    while (!pass_flag) {
        if (validateTwoPass()) {
            LCD_clearScreen();
            pass_flag = 1;
            LCD_DisplayStringRowColumn(0, 0, LCD_STR("Pass Set"));
            _delay_ms(250);
        } else {
            LCD_clearScreen();
            LCD_DisplayStringRowColumn(0, 0, LCD_STR("Pass Mismatch"));
            _delay_ms(250);
        }
    }
    pass_flag = 0;
    UART_sendByte(UART_WAITING_KEY);
    UART_sendString(pass);
}

/*
 * handle_door
 * Manages door opening, waiting for people to enter, and closing.
 */
void handle_door(void) {
    uint8 state = 1;

    while (state != 0) {
        while (UART_recieveByte() != UART_WAITING_KEY)
            ;
        state = UART_recieveByte();
        LCD_clearScreen();

        switch (state) {
        case (DOOR_OPEN_KEY):
            LCD_DisplayStringRowColumn(0, 0, LCD_STR("Door is"));
            LCD_DisplayStringRowColumn(1, 0, LCD_STR("Unlocking"));
            break;
        case (DOOR_WAIT_KEY):
            LCD_DisplayStringRowColumn(0, 0, LCD_STR("Wait for people"));
            LCD_DisplayStringRowColumn(1, 3, LCD_STR("To Enter"));
            break;
        case (DOOR_CLOSE_KEY):
            LCD_DisplayStringRowColumn(0, 0, LCD_STR("Door is Locking"));
            break;
        }
    }
}

/*
 * validateTwoPass
 * Validates that the entered password and re-entered password match.
 * Returns:
 *   TRUE if passwords match, otherwise FALSE.
 */
uint8 validateTwoPass(void) {
    if (!GetPasswordInput(pass, LCD_STR("Enter Pass: "))) {
        return FALSE;
    }
    if (!GetPasswordInput(repass, LCD_STR("RE-Enter Pass: "))) {
        return FALSE;
    }
    return check_pass(pass, repass);
}

/*
 * GetPasswordInput
 * Prompts user to input a password and masks input with '*'.
 * Parameters:
 *   password - Array to store the entered password.
 *   msg - Message to display before taking input.
 * Returns:
 *   TRUE if password input is valid, otherwise FALSE.
 */
uint8 GetPasswordInput(uint8 *password, const uint8 *msg) {
    LCD_clearScreen();
    LCD_DisplayStringRowColumn(0, 0, msg);
    LCD_MoveCursor(1, 0);

    uint8 i = 0;
    while (i < MAX_PASS_SIZE) {
        uint8 num = KEYPAD_getPressedKey();

        if (num >= '0' && num <= '9') {
            password[i++] = num;
            LCD_DisplayCharacter('*');
            _delay_ms(250); /* De-bouncing delay */
        } else if (num == ENTER_BUTTON && i == MAX_PASS_SIZE) {
            break;
        }
    }
    password[MAX_PASS_SIZE] = '#';

    /* Wait for the Enter button if all digits are entered */
    while (KEYPAD_getPressedKey() != ENTER_BUTTON) {
        //_delay_ms(5);
    }
    return TRUE;
}

/*
 * check_pass
 * Compares two passwords for equality.
 * Parameters:
 *   pass1 - First password to compare.
 *   pass2 - Second password to compare.
 * Returns:
 *   TRUE if passwords match, otherwise FALSE.
 */
uint8 check_pass(uint8 *pass1, uint8 *pass2) {
    for (uint8 i = 0; i < MAX_PASS_SIZE; i++) {
        if (pass1[i] != pass2[i]) {
            return FALSE;
        }
    }
    return TRUE;
}

/*
 * timer_callBack
 * Timer callback function to increment second variable every second.
 */
void timer_callBack(void) {
    sec++;
}
