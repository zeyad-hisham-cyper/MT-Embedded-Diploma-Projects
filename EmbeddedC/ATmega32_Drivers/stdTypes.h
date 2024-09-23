/******************************************************************************
 * Module: Standard Types
 * File Name: stdTypes.h
 * Description: Types and Basic definitions for AVR microcontrollers and general
 *              use in embedded systems.
 * Author: Eng. Zeyad Hisham
 *******************************************************************************/

#ifndef STDTYPES_H
#define STDTYPES_H

/*------------------------------------------------------------------------------
 * Boolean Values
 *------------------------------------------------------------------------------
 * These macros define the values for true and false logic, and logical high/low 
 * signals, which are commonly used in embedded systems.
 *----------------------------------------------------------------------------*/

#ifndef FALSE
#define FALSE       (0u)  /* False value as 0 (unsigned) */
#endif

#ifndef TRUE
#define TRUE        (1u)  /* True value as 1 (unsigned) */
#endif

#define LOGIC_HIGH  (1u)  /* Logical High (1) */
#define LOGIC_LOW   (0u)  /* Logical Low (0) */


/*------------------------------------------------------------------------------
 * Data Types
 *------------------------------------------------------------------------------
 * These typedefs define the standard integer and floating point data types
 * for AVR microcontrollers and embedded systems.
 *----------------------------------------------------------------------------*/

/* Boolean type: typically used for flags */
typedef unsigned char boolean;  /* 1 byte, used to store TRUE (1) or FALSE (0) */

/* Unsigned 8-bit integer */
typedef unsigned char uint8;    /* Range: 0 to 255 */

/* Signed 8-bit integer */
typedef signed char sint8;      /* Range: -128 to 127 */

/* Unsigned 16-bit integer */
typedef unsigned short uint16;  /* Range: 0 to 65535 */

/* Signed 16-bit integer */
typedef signed short sint16;    /* Range: -32768 to 32767 */

/* Unsigned 32-bit integer */
typedef unsigned long uint32;   /* Range: 0 to 4294967295 */

/* Signed 32-bit integer */
typedef signed long sint32;     /* Range: -2147483648 to 2147483647 */

/* Unsigned 64-bit integer */
typedef unsigned long long uint64; /* Range: 0 to 18446744073709551615 */

/* Signed 64-bit integer */
typedef signed long long sint64;   /* Range: -9223372036854775808 to 9223372036854775807 */

/* 32-bit floating-point */
typedef float float32;           /* Typically 4 bytes, used for decimal numbers */

/* 64-bit floating-point */
typedef double float64;          /* Typically 8 bytes, used for high-precision decimal numbers */


/*------------------------------------------------------------------------------
 * Optional: Volatile Data Types for Hardware Registers
 *------------------------------------------------------------------------------
 * Declaring variables as volatile ensures the compiler will not 
 * optimize access to these variables, allowing correct and up-to-date values 
 * to be used.
 *----------------------------------------------------------------------------*/

typedef volatile unsigned char vuint8;    /* Volatile unsigned 8-bit integer */
typedef volatile signed char vsint8;      /* Volatile signed 8-bit integer */
typedef volatile unsigned short vuint16;  /* Volatile unsigned 16-bit integer */
typedef volatile signed short vsint16;    /* Volatile signed 16-bit integer */
typedef volatile unsigned long vuint32;   /* Volatile unsigned 32-bit integer */
typedef volatile signed long vsint32;     /* Volatile signed 32-bit integer */
typedef volatile unsigned long long vuint64; /* Volatile unsigned 64-bit integer */
typedef volatile signed long long vsint64;   /* Volatile signed 64-bit integer */

#endif /* STDTYPES_H */
