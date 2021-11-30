/** ***************************************************************************
 * @file
 * @brief See calculations.h
 *
 * @author  Pavel Müller, muellpav@students.zhaw.ch
 * @date	28.11.2021
 *****************************************************************************/

#ifndef SRC_CALCULATIONS_H_
#define SRC_CALCULATIONS_H_

/******************************************************************************
 * Functions
 *****************************************************************************/

// Basic calculations
uint32_t calc_dcValue(uint32_t ADC_samples[], uint8_t size);
void calc_removeDc(uint32_t ADC_samples[], uint8_t size);
void calc_peakToPeak(uint32_t ADC_samples[], uint8_t size);
uint32_t calc_rmsValue(uint32_t ADC_samples[], uint8_t size);

// Advanced calculations


#endif /* SRC_CALCULATIONS_H_ */

