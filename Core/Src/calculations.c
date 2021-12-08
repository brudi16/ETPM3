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
#include "stm32f429i_discovery_ts.h"

#include "calculations.h"
#include "measuring.h"
#include "LUT.h"


/******************************************************************************
 * Defines
 *****************************************************************************/
// Signal
#define NUM_PERIODS		= ((ADC_NUMS/ADC_FS)/(1/50))	///< Number of periods
#define VALS_PER_PERIOD = (ADC_NUMS/NUM_PERIODS)		///< Number of values in a period


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
 * @brief calculate RMS value
 * Calculates the RMS value of an array of measured Data.
 * IMPORTANT!!! The DC Value first has to be removed.
 * 
 * @param ADC_samples 
 * @param size 
 * @return uint32_t 
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
/** ***************************************************************************
 * @brief Linear interpolation between 2 given points
 * 
 * With two given points and the x-value of the searched point the corresponding
 * y-value is calculated with the linear interpolation method.
 * 
 * @param x0 X-Coordinate of the first point
 * @param y0 Y-Coordinate of the first point
 * @param x1 X-Coordinate of the second point
 * @param y1 Y-Coordinate of the second point
 * @param xp X-Coordinate of the searched point
 * @return int32_t yp Y-Coordinate of the searched point 
 *****************************************************************************/

int32_t LinearInterpol(int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t xp){
    float yp = 0;
    yp = ((float)y0 - (((float)y0-(float)y1)/((float)x1-(float)x0)) * ((float)xp - (float)x0));

    return (int32_t)yp;
}
