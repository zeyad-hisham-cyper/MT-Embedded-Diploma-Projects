/******************************************************************************
 * Module: Common - Macros
 * File Name: CommonMacros.h
 * Description: Commonly used Macros
 * Author: Eng. Zeyad Hisham
 *******************************************************************************/
#ifndef COMMONMACROS_H
#define COMMONMACROS_H

/* Set-Bit */
#define SET_BIT(REG, BitNum) ((REG |= (1u << BitNum)))

/* Clear-Bit */
#define CLEAR_BIT(REG, BitNum) ((REG &= ~(1u << BitNum)))

/* Toggle-Bit*/
#define TOGGLE_BIT(REG, BitNum) ((REG ^= (1u << BitNum)))

/* Rotate Right */
#define ROR(REG, NUM) ((REG >> NUM) | (REG << (8 - NUM)))

/* Rotate Left*/
#define ROL(REG, NUM) ((REG << NUM) | (REG >> (8 - NUM)))

/* Bit is Set */
#define BIT_IS_SET(REG, BIT) ((REG & (1u << BIT)))

/* Bit is Clear */
#define BIT_IS_CLEAR(REG, BIT) (!(REG & (1u << BIT)))

#endif