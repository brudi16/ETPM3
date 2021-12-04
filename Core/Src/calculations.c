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
	uint8_t nPeriods = size / 12;
	int32_t maxTmp, minTmp, max = 0, min = 0, peakToPeakValue, tmpVal;

	for(i1=0; i1 < nPeriods; i1++){
        maxTmp = 0;
        minTmp = 0;
		for(i2=0; i2 < 12; i2++){
            tmpVal = ADC_samples[((nPeriods * i1)+i2)];
			if(tmpVal > maxTmp){
				maxTmp = tmpVal;
			}else if((tmpVal < minTmp)){
				minTmp = tmpVal;
			}
		}
        max = max + maxTmp;
        min = min + minTmp;
	}
	

    max = max / ((int32_t)nPeriods);
    min = min / ((int32_t)nPeriods);

	peakToPeakValue = (uint32_t)(max - min);

    return peakToPeakValue;
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

/** ***************************************************************************
 * @brief calculate RMS value
 * Calculates the RMS value of an array of measured Data.
 * IMPORTANT!!! The DC Value first has to be removed.
 * @n
 *****************************************************************************/
uint32_t calc_RMSValue (int32_t ADC_samples[], uint16_t size){
    uint32_t rmsValue = 0;
    uint16_t i;
    int32_t tmp;
    float tmpfloat = 0;

    for(i=0;i<size; i++){
        tmp = ADC_samples[i];
        tmpfloat = tmpfloat + (tmp * tmp);
    }
    tmpfloat = tmpfloat / size;
    tmpfloat = sqrtf(tmpfloat);
    rmsValue = (uint32_t)tmpfloat;
    return rmsValue;
}
