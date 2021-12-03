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

#include "calculations.h"
#include "measuring.h"


/******************************************************************************
 * Functions
 *****************************************************************************/

/** ***************************************************************************
 * @brief
 *
 *
 * @n
 *****************************************************************************/
int32_t calc_dcValue(int32_t ADC_samples[], uint16_t size){
	int32_t dcValue = 0;
	uint16_t i;

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
void calc_removeDc(int32_t ADC_samples[], uint16_t size){
	int32_t dcValue;
	uint16_t i;

	dcValue = calc_dcValue(ADC_samples, size);

	for(i=0; i < size; i++){
		ADC_samples[i] = ADC_samples[i] - dcValue;
	}
}

/** ***************************************************************************
 * @brief calculate average peak to peak value
 *
 *
 * @n
 *****************************************************************************/
uint32_t calc_peakToPeak_av(int32_t ADC_samples[], uint16_t size){
	uint16_t i1, i2;
	uint8_t nPeriods = size / 60;
	int32_t max_Array[NPeriods], minArray[NPeriods], max, min;

	for(i1=0; i1 = nPeriods; i1++){
		for(i2=0; i2 < 60; i2++){
			if(ADC_samples[((nPeriods * i1)+i2)] > maxArray[i1]){
				maxArray[i1] = ADC_samples[((nPeriods * i1)+i2)];
			}else if((ADC_samples[((nPeriods * i1)+i2)] < minArray[i1])){
				minArray[i1] = ADC_samples[((nPeriods * i1)+i2)];
			}
		}
	}


}

/** ***************************************************************************
 * @brief
 *
 *
 * @n
 *****************************************************************************/
int32_t calc_rmsValue(int32_t ADC_samples[], uint16_t size){
	int32_t rmsValue = 0;

	return rmsValue;
}
