/*
 * ADC.h
 *
 *  Created on: Sep 28, 2024
 *      Author: zeyad
 */

#ifndef ADC_H_
#define ADC_H_

#include  "../std_types.h"

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

void ADC_init(void);
uint16 ADC_readChannel(uint8 ch_num);

#endif /* ADC_H_ */
