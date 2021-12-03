#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define ARRAYSIZE   60

int32_t arrayMean(int32_t array[], uint16_t size);
void printArray(int32_t array[], uint16_t size);
void removeMean(int32_t array[], uint16_t size);
void rectify(int32_t array[], uint16_t size);
void forTestLoops(uint8_t pram1, uint8_t param2);
uint32_t calc_peakToPeak_av(int32_t ADC_samples[], uint16_t size);

int main(){
    int32_t sum, mean, peakPeak;

    int32_t array[] = {1000,1259,1447,1511,1433,1236,973,718,540,491,582,789,1054,1305,1471,1506,1402,1186,919,674,519,498,615,840,1108,1347,1489,1496,1366,1134,866,634,504,511,653,892,1160,1385,1502,1481,1326,1081,814,598,494,529,695,946,1211,1418,1509,1460,1282,1027,764,567,489,553,741,1000};
    printArray(array, ARRAYSIZE);
    printf("Adress: %p\n", array);

    mean = arrayMean(array, ARRAYSIZE);
    printf("Mean: %d\n", mean);
    printf("Adress: %p\n", array);

    removeMean(array, ARRAYSIZE);
    printf("\nMean removed:\n");
    printArray(array, ARRAYSIZE);
    printf("Adress: %p\n", array);

    rectify(array, ARRAYSIZE);
    printf("\nRectified:\n");
    printArray(array, ARRAYSIZE);
    printf("Adress: %p\n", array);

    //forTestLoops(4,5);

    peakPeak = calc_peakToPeak_av(array, (sizeof(array)/(sizeof(uint32_t))));
    printf("\nPeak to Peak Value in average: %d\n",peakPeak);
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
	

    max = max / ((uint32_t)nPeriods);
    min = min / ((uint32_t)nPeriods);

	peakToPeakValue = (uint32_t)(max - min);

    return peakToPeakValue;
}
