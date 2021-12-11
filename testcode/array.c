#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>



#define ARRAYSIZE           60
#define ACCURATE_ARRAYSIZE  240
#define LUT_SIZE            200
#define CAL_SIZE            7
#define PAD_TO_PAD_DISTANCE 25

// Prototypes
int32_t arrayMean(int32_t array[], uint16_t size);
void printArray(int32_t array[], uint16_t size);
void removeMean(int32_t array[], uint16_t size);
void rectify(int32_t array[], uint16_t size);
void forTestLoops(uint8_t pram1, uint8_t param2);
uint32_t calc_peakToPeak_av(int32_t ADC_samples[], uint16_t size);
uint32_t calc_RMSValue (int32_t ADC_samples[], uint16_t size);
float calc_distance (int32_t ADC_samples[], uint16_t size);
float calc_current(int32_t ADC_samples[], uint16_t size);
int32_t LinearInterpol(int32_t x0, int32_t x1, int32_t y0, int32_t y1, int32_t xp);
void interpolCalValuesDistance(int16_t x[], int16_t y[], int16_t xySize);
void init_LUT(void);
float calcStdDev(int32_t array[], int32_t size);
int32_t getXFromY(int32_t array[], int32_t size, int32_t yValue);
int32_t getAngle(void);

// Global variables
const int32_t padLutStartValues[LUT_SIZE] = {
    #include "lutPad.csv"
    };
const int32_t hallLutStartValues[LUT_SIZE] = {
    //#include "lutHall.csv"
};

int32_t padLut[LUT_SIZE];

int16_t measCalDistance[] = {2,       5,   10,   20,  50, 100, 200};
int16_t testInterpol[]    = {3972, 2048, 1517, 1204, 946, 814, 715};

int32_t distance1 = 0, distance2 = 0, angle = 720;

int main(){
    int32_t sum, mean, peakPeak, rmsValue, interpol, x;
    float stdDev;

    int32_t array[] = {
        #include "testarray.txt"
    };

    int32_t acurateArray[] ={
        #include "extendedTestarray.txt"
    };
    // printArray(array, ARRAYSIZE);
    // printf("Adress: %p\n", array);

    // mean = arrayMean(array, ARRAYSIZE);
    // printf("Mean: %d\n", mean);
    // printf("Adress: %p\n", array);

    // removeMean(array, ARRAYSIZE);
    // printf("\nMean removed:\n");
    // printArray(array, ARRAYSIZE);
    // printf("Adress: %p\n", array);

    // //rectify(array, ARRAYSIZE);
    // //printf("\nRectified:\n");
    // //printArray(array, ARRAYSIZE);
    // //printf("Adress: %p\n", array);

    // //forTestLoops(4,5);

    // peakPeak = calc_peakToPeak_av(array, (sizeof(array)/(sizeof(uint32_t))));
    // printf("\nPeak to Peak Value in average: %d\n",peakPeak);

    // stdDev = calcStdDev(array, ARRAYSIZE);
    // printf("\nStandart deviation: %.6f",stdDev);

    // rmsValue = calc_RMSValue(array, (sizeof(array)/(sizeof(uint32_t))));
    // printf("\nRMS-Value: %d\n", rmsValue);

    // init_LUT();
    // printArray(padLut, LUT_SIZE);

    // printf("\nCalibration:\n");

    // interpol = LinearInterpol(100, 814, 200, 715, 150);
    // //printf("\nInterpolated Value for 150: %d\n", interpol);
    
    // interpolCalValuesDistance(measCalDistance,testInterpol, CAL_SIZE);

    // x = getXFromY(padLut, LUT_SIZE, 1200);
    // printf("\nDistance: %d\n",x);

    // stdDev = calcStdDev(array, ARRAYSIZE);
    // printf("Standart deviation: %.6f",stdDev);

    // printf("\nExtendet Array:");
    // removeMean(acurateArray, 240);
    // printArray(acurateArray, ACCURATE_ARRAYSIZE);
    
    // printf("\nPeak to Peak Value in average: %d\n",peakPeak);

    distance1 = 1200;
    distance2 = 1212;

    angle = getAngle();

    printf("Angle: %d Grad", angle);

    return 0;
}

int32_t arrayMean(int32_t array[], uint16_t size){
    uint32_t mean = 0;
    int i;

    for(i=0; i<size; i++){
        mean = mean + array[i];
    }

    mean = mean / size;
    return mean;
}

void printArray(int32_t array[], uint16_t size){
    int i;

    printf("Array: ");
    
    for(i=0; i<size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void removeMean(int32_t array[], uint16_t size){
    int i;
    uint32_t mean = arrayMean(array, size);

    for(i=0; i<size; i++){
        array[i] = array[i] - mean;
    }
}

void rectify(int32_t array[], uint16_t size){
    int i;
    uint32_t cmpVal = 0;
    
    for(i=0; i<size; i++){
        if(array[i] < 0)
            array[i] = array[i] *-1;
    }

}

void forTestLoops(uint8_t param1, uint8_t param2){
    uint8_t i1, i2;
    uint16_t tot;

    for(i1=0; i1<param1; i1++){
        printf("Param 1 = %d\n", i1);
        for(i2=0; i2<param2; i2++){
            printf("Param 2 = %d\n", i2);
            tot = (i1*param2)+i2;
            printf("Param 1 * Param 2 = %d\n", tot);
        }
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

float calc_distance (int32_t ADC_samples[], uint16_t size){
    return 0;
}

float calc_current(int32_t ADC_samples[], uint16_t size){
    return 0;
}

void init_LUT(void){
    uint16_t i;
    for(i=0;i<LUT_SIZE;i++){
        padLut[i] = padLutStartValues[i];
    }
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

/**
 * @brief interpolate Calibration values
 * 
 * @param x 
 * @param y 
 * @param xySize 
 */
void interpolCalValuesDistance(int16_t x[], int16_t y[], int16_t xySize){
    int16_t i,j;
    bool l;
    
    // loop for the different distances
    for(i=0;i<xySize;i++){
        l = false;
        // loop for Values
        for(j=0;j<x[i];j++){
            // set start value of j to value from last loop
            if(i>0 && l == false){
                j = x[i-1];
                l = true;
            }
            if(j == 0){
                // do nothing
            }else if(j< x[0]){
                // for first intervall of distance
                padLut[j] = LinearInterpol(1,padLutStartValues[0],x[0],y[0],(j+1));
            }else{
                padLut[j] = LinearInterpol(x[(i-1)],y[(i-1)],x[(i)],y[(i)],(j+1));
            }
            printf("i: %d\tj: %d\tdefault: %d\tnew: %d\tx: %d\ty: %d\n",i,j,padLutStartValues[j],padLut[j],x[i],y[i]);
            
        }
    }
}

/** ***************************************************************************
 * @brief Search the corresponding x-value to a given y-value
 * 
 * @param array     Array with y-values
 * @param size      Size of the array
 * @param yValue    y-value of the searched x-value
 * @return int32_t 
 *****************************************************************************/
int32_t getXFromY(int32_t array[], int32_t size, int32_t yValue){
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

    // make an array with peak to peak values for all periods
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
    return sqrt(SD / nPeriods);
}

/** ***************************************************************************
 * @brief Get the Angle to the main cable
 * 
 * calculates the angle by the difference from the two distances
 * 
 * @return int32_t 
 *****************************************************************************/
int32_t getAngle(void){
    int32_t y = 0, diff;

    diff = distance1 - distance2;

    // -90° from -90° to -67°
    if(diff >= (-25) && diff < ((-25)*3/4)){
        y = -90;
    // -45° from -67 to -23° 
    }else if(diff >= ((-25)*3/4) && diff < ((-25)*1/4)){
        y = -45;
    // 0° from -23 to 23°
    }else if(diff >= ((-25)*1/4) && diff < ((25)*1/4)){
        y = 0;
    // 45° from 23° to 68°
    }else if(diff >= ((25)*1/4) && diff < ((25)*3/4)){
        y = 45;
    // -90° from -68° to -90°
    }else if(diff >= ((25)*3/4) && diff <= (25)){
        y = 90;
    // should never happen
    }else{
        y = 360;    // for debugging
    }


    return y;
}
