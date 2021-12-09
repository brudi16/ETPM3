#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>



#define ARRAYSIZE   60
#define LUT_SIZE    200
#define CAL_SIZE    7

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

int main(){
    int32_t sum, mean, peakPeak, rmsValue, interpol, x;

    int32_t array[] = {1000,1259,1447,1511,1433,1236,973,718,540,491,582,789,1054,1305,1471,1506,1402,1186,919,674,519,498,615,840,1108,1347,1489,1496,1366,1134,866,634,504,511,653,892,1160,1385,1502,1481,1326,1081,814,598,494,529,695,946,1211,1418,1509,1460,1282,1027,764,567,489,553,741,1000};
    // printArray(array, ARRAYSIZE);
    // printf("Adress: %p\n", array);

    // mean = arrayMean(array, ARRAYSIZE);
    // printf("Mean: %d\n", mean);
    // printf("Adress: %p\n", array);

    // removeMean(array, ARRAYSIZE);
    // printf("\nMean removed:\n");
    // printArray(array, ARRAYSIZE);
    // printf("Adress: %p\n", array);

    //rectify(array, ARRAYSIZE);
    //printf("\nRectified:\n");
    //printArray(array, ARRAYSIZE);
    //printf("Adress: %p\n", array);

    //forTestLoops(4,5);

    // peakPeak = calc_peakToPeak_av(array, (sizeof(array)/(sizeof(uint32_t))));
    // printf("\nPeak to Peak Value in average: %d\n",peakPeak);

    // rmsValue = calc_RMSValue(array, (sizeof(array)/(sizeof(uint32_t))));
    // printf("\nRMS-Value: %d\n", rmsValue);

    //printArray(padLutStartValues,LUT_SIZE);
    //init_LUT();
    //printArray(padLut, LUT_SIZE);
    init_LUT();

    interpol = LinearInterpol(100, 814, 200, 715, 150);
    printf("\nInterpolated Value for 150: %d\n", interpol);
    
    interpolCalValuesDistance(measCalDistance,testInterpol, CAL_SIZE);

    x = getXFromY(padLut, LUT_SIZE, 1200);
    printf("\nDistance: %d\n",x);
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
    //rmsValue = (uint32_t)(sqrt(((double)tmp)/size));
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
/**
 * @brief Linear Interpolation between 2 points
 * 
 * @param x0 
 * @param x1 
 * @param y0 
 * @param y1 
 * @param xp Searched Value
 * @return int32_t 
 */

int32_t LinearInterpol(int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t xp){
    float yp = 0;
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
            //printf("i: %d\tj: %d\tdefault: %d\tnew: %d\tx: %d\ty: %d\n",i,j,padLutStartValues[j],padLut[j],x[i],y[i]);
            
        }
    }
}
/**
 * @brief Search the corresponding x-value to a given y-value
 * 
 * @param array     Array with y-values
 * @param size      Size of the array
 * @param yValue    y-value of the searched x-value
 * @return int32_t 
 */
int32_t getXFromY(int32_t array[], int32_t size, int32_t yValue){
    int32_t xValue = 0; // Output variable
    int16_t i;      // Loop variable

    // Loop for all values of the array
    for(i=0; i<(size - 1); i++){
        printf("\ni: %d\t array[i]: %d\tarray[i+1]: %d",i, array[i], array[i+1]);
        // Check if the value is lower than lowest or higher than highes value
        if(yValue > array[0] || yValue < array[(size+1)]){
            return 0;
        
        }else if(yValue == array[i]){
            xValue = i+1;
        // Check if y value is higher than next value and lower than actual value from array
        }else if(yValue > array[(i+1)] && yValue < array[i]){
            // Check if difference to next value from array is higher than difference to actual array element
            if((yValue - array[(i+1)]) > (array[i] - yValue)){
                xValue = i+1;
            }else{
                xValue = i+2;
            }
        }
    }
    
    return xValue;
}

float calcStdDev(int32_t array[], int32_t size) {
    float mean, SD = 0.0;
    int i;
    mean = calc_peakToPeak_av(array, size);
    for (i = 0; i < size; ++i) {
        SD += pow(array[i] - mean, 2);
    }
    return sqrt(SD / 10);
}
