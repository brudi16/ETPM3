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
int32_t calc_dcValue(int32_t ADC_samples[], uint16_t size);
void calc_removeDc(int32_t ADC_samples[], uint16_t size);
uint32_t calc_peakToPeak_av(int32_t ADC_samples[], uint16_t size);
int32_t calc_rmsValue(int32_t ADC_samples[], uint16_t size);

// Advanced calculations


#endif /* SRC_CALCULATIONS_H_ */

