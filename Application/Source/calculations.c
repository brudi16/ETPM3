/** ***************************************************************************
 * @file
 * @brief Calculations of the measured values
 *
 * Functions for calculations
 * ============================================================================
 * 
 * DC-Value
 * ----------------------------------------------------------------------------
 * - Calculate DC-value of the signal
 * - Remove the DC-value of the signal
 * 
 * Calculations of Amplitude
 * ----------------------------------------------------------------------------
 * - Calculate peak to peak value of the signal
 * - Calculate RMS-value of the signal
 * 
 * Interpolation
 * ----------------------------------------------------------------------------
 * - Linear interpolation
 * 
 * Array
 * ----------------------------------------------------------------------------
 * - Search function for an array
 * - Copy function
 * 
 * Distance
 * ----------------------------------------------------------------------------
 * - Function for distance output
 * 
 * Statistic
 * ----------------------------------------------------------------------------
 * - Calculation of the standart deviation
 * 
 * Filter
 * ----------------------------------------------------------------------------
 * - FIR filtering function
 * 
 * 
 * @n
 *
 * @authors Pavel Müller, Röhrig Yves
 * @date	28.11.2021
 *****************************************************************************/

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "stm32f4xx.h"
#include "stm32f429i_discovery.h"
#include "stm32f429i_discovery_ts.h"
#include "arm_math.h"

#include "calculations.h"
#include "measuring.h"
#include "API.h"
#include "LUT.h"


/******************************************************************************
 * Defines
 *****************************************************************************/
// Activate for debugging of calculations
//#define DEBUG

/******************************************************************************
 * Variables
 *****************************************************************************/
//Arrays from measured Signal
int32_t pad1Values[ADC_NUMS_ACU];					    ///< Copied values from pad 1
int32_t pad2Values[ADC_NUMS_ACU];					    ///< Copied values from pad 2
int32_t hall1Values[ADC_NUMS_ACU];					    ///< Copied values from Hall Sensor 1
int32_t hall2Values[ADC_NUMS_ACU];					    ///< Copied values from Hall Sensor 2

uint32_t peakToPeakArrayPad1[NUM_PERIODS_MAX];		    ///< Pad 1 array with peak to peak values for every period of the signal
uint32_t peakToPeakArrayPad2[NUM_PERIODS_MAX];		    ///< Pad 2 array with peak to peak values for every period of the signal
uint32_t peakToPeakArrayHall1[NUM_PERIODS_MAX];		    ///< Hall Sensor 1 array with peak to peak values for every period of the signal
uint32_t peakToPeakArrayHall2[NUM_PERIODS_MAX];		    ///< Hall Sensor 2 array with peak to peak values for every period of the signal

int32_t debugArray[ADC_NUMS_ACU] = {				    ///< Array for debugging purpose
	#include "debugArray.csv"
};

// Arrays with filter coefficients
const float32_t aiir[] = {0.0023, 0, -0.0045, 0, 0.0023};   ///< A coefficients of the iir filter
const float32_t biir[] = {1.0, -3.4095, 4.7708, -3.1806};   ///< B coefficients of the iir filter

const float32_t bfir[] = {                              ///< coefficients of the fir filter
    #include "bfir.csv"
};


/******************************************************************************
 * Functions
 *****************************************************************************/

/** ***************************************************************************
 * @brief Calculate the DC-Value of the signal
 *
 * @param[in] ADC_samples   Array with measured values
 * @param[in] size          Size of the Array
 * @return int32_t      DC-Value of the signal
 * 
 * This funciton calculates the DC-Value of the signal by calculating its mean.
 * The mean is calculted by summ up all values and divide by the number of values.
 * 
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
 * @param[in] ADC_samples 	Array with measured values
 * @param[in] size 			Size of the Array
 * 
 * Goes through every value of the Array and removes its DC-Value. The number
 * of array elements is set by the parameter size.
 *****************************************************************************/
void calc_removeDc(int32_t ADC_samples[], uint16_t size){
	int32_t dcValue;
	uint16_t i;
	// Calculate DC value of the Array
	dcValue = calc_dcValue(ADC_samples, size);

	// Subtract Dc-value from array
	for(i=0; i < size; i++){
		ADC_samples[i] = ADC_samples[i] - dcValue;
	}
}

/** ***************************************************************************
 * @brief calculate average peak to peak value
 * 
 * @param[in] ADC_samples 	Array with measured values
 * @param[in] size 			Size of the Array
 * @param[out] peakPeakArray Array with peak to peaks values
 * @return peak to peak value
 * 
 * Peak to Peak calucation
 * -----------------------
 * With to for-loops the array is processed. The first loop, loops the periods
 * and the second loop ist for the values in the period.
 * @n
 * The loop for the values searches the maximum and minimum values of the actual 
 * period. This max and min values are summed up in two variables. For calculation
 * of the standart deviation the peak to peak values per period are stored in the
 * peakPeakArray. After the loop the summed up values are devided by the number of 
 * periods to get the average peak to peak value over all periods of the signal.
 * The averaging is done to get a filter effect.
 * 
 * @warning
 * Before using this function the dc-value has to bee removed from the array
 * passed to this function. Without previously removing the dc-value the peak
 * to peak value will be incorrect.
 *****************************************************************************/
uint32_t calc_peakToPeak_av(int32_t ADC_samples[], uint16_t size, uint32_t peakPeakArray[]){
	uint16_t i1, i2;
	uint8_t nPeriods = size / ADC_SPP;
	int32_t maxTmp, minTmp, max = 0, min = 0, peakToPeakValue, tmpVal;

	// Loop for periods
	for(i1=0; i1 < nPeriods; i1++){
        maxTmp = 0;
        minTmp = 0;
		// Loop for values in periods
		for(i2=0; i2 < ADC_SPP; i2++){
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
        // Store peak to peak values per period for other calculations
        peakPeakArray[i1] = (uint32_t)(maxTmp - minTmp);
	}
	
	// Calculate the average max and mins
    max = max / ((int32_t)nPeriods);
    min = min / ((int32_t)nPeriods);

	// Claculate peak to peak
	peakToPeakValue = (uint32_t)(max - min);

    return peakToPeakValue;
}

/** ***************************************************************************
 * @brief Linear interpolation between 2 given points
 * 
 * @param[in] x0 X-Coordinate of the first point
 * @param[in] y0 Y-Coordinate of the first point
 * @param[in] x1 X-Coordinate of the second point
 * @param[in] y1 Y-Coordinate of the second point
 * @param[in] xp X-Coordinate of the searched point
 * @return Y-Coordinate of the searched point 
 * 
 * With two given points and the x-value of the searched point the corresponding
 * y-value is calculated with the linear interpolation method. This function is used
 * for the calibration process (see LUT.c) to calculate the LUT values between 
 * calibration points.
 * 
 *****************************************************************************/
int32_t LinearInterpol(int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t xp){
    float32_t yp = 0;
	// Linear Interpolation between 2 points
    yp = ((float32_t)y0 - (((float32_t)y0-(float32_t)y1)/((float32_t)x1-(float32_t)x0)) * ((float32_t)xp - (float32_t)x0));

    return (int32_t)yp;
}

/** ***************************************************************************
 * @brief Search the corresponding x-value to a given y-value
 * 
 * @param[in] array     Array with y-values
 * @param[in] size      Size of the array
 * @param[in] yValue    y-value of the searched x-value
 * @return int32_t 
 * 
 * @if
 * 
 *****************************************************************************/
uint32_t getXFromY(uint16_t array[], int32_t size, uint32_t yValue){
    uint32_t xValue = 0;    // Output variable
    int16_t i;              // Loop variable

    // Loop for all values of the array
    for(i=0; i<(size - 1); i++){
        // Check if the value is lower than lowest or higher than highes value
        if(yValue > array[0] || yValue < array[(size-1)]){
            xValue = 999;
						break;
        
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
 * @param peakPeakArray1 Array with peak to peak values
 * @param peakPeakArray2
 * @param size  Size of the array
 * @return float32_t 
 *****************************************************************************/
uint32_t calcStdDev(uint32_t peakPeakArray1[], uint32_t peakPeakArray2[], int32_t size) {
    float32_t mean1 = 0, mean2 = 0;
    float32_t SD = 0.0, SD1 = 0.0, SD2 = 0.0;
    uint16_t i;
    uint32_t distanceArray1[NUM_PERIODS_MAX] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    uint32_t distanceArray2[NUM_PERIODS_MAX] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	uint8_t nPeriods = size / ADC_SPP;

    // get distance for every value of the array
    for (i = 0; i < nPeriods; i++){
        distanceArray1[i] = getXFromY(pad1Lut, LUT_SIZE_PAD, peakPeakArray1[i]);
        distanceArray2[i] = getXFromY(pad2Lut, LUT_SIZE_PAD, peakPeakArray2[i]);
    }
    
    // calculate the mean of the peak to peak values
    for(i = 0; i < nPeriods; i++){
        // Sum up the Array
        mean1 = mean1 + distanceArray1[i];
        mean2 = mean2 + distanceArray2[i];
    }
    // calculate mean by deviding with number of Periods
    mean1 = mean1 / nPeriods;
    mean2 = mean2 / nPeriods;

    // calculate the variance
    for (i = 0; i < (nPeriods); ++i){
        SD1 += pow((distanceArray1[i] - mean1), 2);
        SD2 += pow((distanceArray2[i] - mean2), 2);
    }

    // calculate the standart deviation from the variance
    SD1 = sqrt(SD1 / nPeriods);
    SD1 = sqrt(SD1 / nPeriods);

    // 
    if(SD1 > SD2){
        SD = SD1;
    }else if (SD1 < SD2){
        SD = SD2;
    }else{
        SD = 999;
    }

    return (uint32_t)SD;
}

/** ***************************************************************************
 * @brief Copy Arrays from measuring array to calculations array
 * 
 * The measured values are copied from measuring array to an array for the
 * calculations. This prevents that the values are processed and overwritten
 * by DAC on the same time.
 * When debug is activated the arrays are initilized with a matlab generated
 * array with a peak to peak value of 4095. 
 *
 * @param size Size of the array 
 *****************************************************************************/
void cpyArrays(uint16_t size){
    uint16_t i;

    for(i=0;i<size; i++){
        // Copy all values from measuring array to processing array
	    #ifndef DEBUG
            pad1Values[i]    = ADC_PAD1_samples[i];
            pad2Values[i]    = ADC_PAD2_samples[i];
            hall1Values[i]   = ADC_HALL1_samples[i];
            hall2Values[i]   = ADC_HALL2_samples[i];
		#endif
        
        // initialize all processing array with a predefined debugging array
		#ifdef DEBUG
            pad1Values[i]    = debugArray[i];
            pad2Values[i]    = debugArray[i];
            hall1Values[i]   = debugArray[i];
            hall2Values[i]   = debugArray[i];
		#endif
    }
}

/** ***************************************************************************
 * @brief filter values from Hall Sensors
 *
 * The measured Values from the Sensors are filtered used the fir filtering
 * method.
 * 
 *****************************************************************************/
void filter_hall(void){
    // Variables
    arm_fir_instance_f32 h1, h2;        // filter instances
    arm_status status_h1, status_h2;    // status of filter
    static float32_t state_h1[NUM_TAPS], state_h2[NUM_TAPS];
    static float32_t tmpArray[ADC_NUMS_ACU];
    int32_t i;

    // initialisaiton for filtering values of the hallsensor 1
    arm_fir_init_f32(&h1, NUM_TAPS, (float32_t *)&bfir[0],&state_h1[0],arraySize);
		
    // filter the array
    arm_fir_f32(&h1,(float32_t *)&hall1Values[0], &tmpArray[0], (uint32_t)arraySize);

    for(i=0; i<arraySize; i++){
        hall1Values[i] = tmpArray[i];
    }
		
		// initialisaiton for filtering values of the hallsensor 2
    arm_fir_init_f32(&h1, NUM_TAPS, (float32_t *)&bfir[0],&state_h2[0],arraySize);
		
    // filter the array
    arm_fir_f32(&h1,(float32_t *)&hall2Values[0], &tmpArray[0], (uint32_t)arraySize);

    for(i=0; i<arraySize; i++){
        hall2Values[i] = tmpArray[i];
    }
}
/**
 * @brief 
 * 
 * @param distance1 
 * @param distance2 
 * @return uint32_t 
 */
uint32_t calc_distance(uint32_t distance1, uint32_t distance2){
    uint32_t distance;
    int32_t difference;

    difference = ((int32_t)distance1) - ((int32_t)distance2);
	
		if(distance1 == 999 && distance2 == 999){
				distance = 999;
		}else if(distance1 == 999){
				distance = distance2;
		}else if(distance2 == 999){
				distance = distance1;
		}else if(difference > 50){
        distance = distance1;
    }else if(difference < -50){
        distance = distance2;
    }else{
        distance = ((distance1 + distance2)/2);
    }

    return distance;
}
