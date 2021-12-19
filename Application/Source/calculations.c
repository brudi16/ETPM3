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
//#include "measuring.h"
#include "LUT.h"
#include "math.h"


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
 * @brief removes DC value form the array
 * 
 * @param ADC_samples 	Array with measured values
 * @param size 			Size of the Array
 *****************************************************************************/
void calc_removeDc(int32_t ADC_samples[], uint16_t size){
	int32_t dcValue;
	uint16_t i;
	// Calculate DC value of the Array
	dcValue = calc_dcValue(ADC_samples, size);

	// Subtract Dc value from Array
	for(i=0; i < size; i++){
		ADC_samples[i] = ADC_samples[i] - dcValue;
	}
}

/** ***************************************************************************
 * @brief calculate average peak to peak value
 * 
 * Calculate the peak to peak value for every period and average it for filtering.
 * 
 * @param ADC_samples 	Array with measured values
 * @param size 			Size of the Array
 * @return uint32_t 
 *****************************************************************************/
uint32_t calc_peakToPeak_av(int32_t ADC_samples[], uint16_t size){
	uint16_t i1, i2;
	uint8_t nPeriods = size / 12;
	int32_t maxTmp, minTmp, max = 0, min = 0, peakToPeakValue, tmpVal;

	// Loop for periods
	for(i1=0; i1 < nPeriods; i1++){
        maxTmp = 0;
        minTmp = 0;
		// Loop for values in periods
		for(i2=0; i2 < 12; i2++){
			// get actual value from Array
            tmpVal = ADC_samples[((nPeriods * i1)+i2)];
			if(tmpVal > maxTmp){
				maxTmp = tmpVal;
			}else if((tmpVal < minTmp)){
				minTmp = tmpVal;
			}
		}
		// Sum up all max and mins of periods
        max = max + maxTmp;
        min = min + minTmp;
	}
	
	// Calculate the average max and mins
    max = max / ((int32_t)nPeriods);
    min = min / ((int32_t)nPeriods);

	// Claculate peak to peak
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

	// Sum up all squared Values from the Array
    for(i=0;i<size; i++){
        tmp = ADC_samples[i];
        tmpfloat = tmpfloat + (tmp * tmp);
    }

	// Divide by size of the Array
    tmpfloat = tmpfloat / size;
	// Make square root of the value
    tmpfloat = sqrtf(tmpfloat);
	// convert it to uint32_t
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
	// Linear Interpolation between 2 points
    yp = ((float)y0 - (((float)y0-(float)y1)/((float)x1-(float)x0)) * ((float)xp - (float)x0));

    return (int32_t)yp;
}

/** ***************************************************************************
 * @brief Search the corresponding x-value to a given y-value
 * 
 * @param array     Array with y-values
 * @param size      Size of the array
 * @param yValue    y-value of the searched x-value
 * @return int32_t 
 *****************************************************************************/
int32_t getXFromY(uint16_t array[], int32_t size, int32_t yValue){
    int32_t xValue = 0; // Output variable
    int16_t i;      // Loop variable

    // Loop for all values of the array
    for(i=0; i<(size - 1); i++){
        // Check if the value is lower than lowest or higher than highes value
        if(yValue > array[0] || yValue < array[(size+1)]){
            return 0;
        
        }else if(yValue == array[i]){
            xValue = i+1;
        // Check if y value is higher than next value and lower than actual value from array
        }else if(yValue > array[(i+1)] && yValue < array[i]){
            // Check if difference to next value from array is higher than difference to actual array element
            if((yValue - array[(i+1)]) > (array[i] - yValue)){
				// higher Value
                xValue = i+1;
            }else{
				// lower value
                xValue = i+2;
            }
        }
    }  
    return xValue;
}
/** ***************************************************************************
 * @brief Calculate the standart deviation
 * 
 * This function calculates the standart deviation of the peak to peak Values
 * of an anrray with measured values.
 * 
 * @param array Array with measured values
 * @param size Size of the array
 * @return float 
 *****************************************************************************/
float calcStdDev(int32_t array[], int32_t size) {
    float mean = 0, SD = 0.0;
    uint16_t i, peakPeakArray[10] = {0,0,0,0,0,0,0,0,0,0};

    uint16_t i1, i2;
	uint8_t nPeriods = size / 12;
	int32_t maxTmp, minTmp, peakToPeakValue, tmpVal;

	for(i1=0; i1 < nPeriods; i1++){
        maxTmp = 0;
        minTmp = 0;
		for(i2=0; i2 < 12; i2++){
            tmpVal = array[((nPeriods * i1)+i2)];
			if(tmpVal > maxTmp){
				maxTmp = tmpVal;
			}else if((tmpVal < minTmp)){
				minTmp = tmpVal;
			}
		}
        peakPeakArray[i1] = (maxTmp - minTmp);
	}

    mean = calc_peakToPeak_av(array, size);
    for (i = 0; i < (nPeriods); ++i){
        SD += pow(peakPeakArray[i] - mean, 2);
    }
    return sqrt(SD / 10);
}
// int8_t Calc_Angle()