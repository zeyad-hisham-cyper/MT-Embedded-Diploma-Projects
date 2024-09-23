/******************************************************************************
 * Module: Common - Macros
 * File Name: CommonMacros.h
 * Description: Commonly used Macros
 * Author: Eng. Zeyad Hisham
 *******************************************************************************/

#ifndef COMMONMACROS_H
#define COMMONMACROS_H

/* Set a specific bit in a register */
#define SET_BIT(REG, BitNum) ((REG) |= (1u << (BitNum)))

/* Clear a specific bit in a register */
#define CLEAR_BIT(REG, BitNum) ((REG) &= ~(1u << (BitNum)))

/* Toggle a specific bit in a register */
#define TOGGLE_BIT(REG, BitNum) ((REG) ^= (1u << (BitNum)))

/* Rotate bits to the right */
#define ROR(REG, NUM) (((REG) >> (NUM)) | ((REG) << ((8 - (NUM)) & 0x07)))

/* Rotate bits to the left */
#define ROL(REG, NUM) (((REG) << (NUM)) | ((REG) >> ((8 - (NUM)) & 0x07)))

/* Check if a specific bit is set */
#define BIT_IS_SET(REG, BIT) ((REG) & (1u << (BIT)))

/* Check if a specific bit is clear */
#define BIT_IS_CLEAR(REG, BIT) (!((REG) & (1u << (BIT))))

#endif
