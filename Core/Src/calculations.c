/** ***************************************************************************
 * @file
 * @brief Calculations of the measured values
 *
 * Functions for calculating values from measurements
 * @n
 *
 * @author  Pavel Müller, muellpav@students.zhaw.ch
 * @date	28.11.2021
 *****************************************************************************/

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "stm32f4xx.h"
#include "stm32f429i_discovery.h"
#include "stm32f429i_discovery_lcd.h"
#include "stm32f429i_discovery_ts.h"

#include "main.h"


/******************************************************************************
 * Functions
 *****************************************************************************/

/** ***************************************************************************
 * @brief
 *
 *
 * @n
 *****************************************************************************/
uint32_t calc_dcValue(uint32_t ADC_samples[], uint8_t size){
	uint32_t dcValue = 0;
	uint8_t i;

	for(i=0; i < size; i++){
		dcValue = dcValue + ADC_samples[i];
	}
	dcValue = dcValue / size;
	return dcValue;
}

/** ***************************************************************************
 * @brief
 *
 *
 * @n
 *****************************************************************************/
void calc_removeDc(uint32_t ADC_samples[], uint8_t size){
	uint32_t dcValue;
	uint8_t i;

	dcValue = calc_dcValue(ADC_samples, size);

	for(i=0; i < size; i++){
		ADC_samples[i] = ADC_samples[i] - dcValue;
	}
}

/** ***************************************************************************
 * @brief
 *
 *
 * @n
 *****************************************************************************/
void calc_peakToPeak(uint32_t ADC_samples[], uint8_t size){

}

/** ***************************************************************************
 * @brief
 *
 *
 * @n
 *****************************************************************************/
uint32_t calc_rmsValue(uint32_t ADC_samples[], uint8_t size){
	uint32_t rmsValue = 0;

	return rmsValue;
}
