#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define ARRAYSIZE   20

int32_t arrayMean(int32_t array[], uint16_t size);
void printArray(int32_t array[], uint16_t size);
void removeMean(int32_t array[], uint16_t size);
void rectify(int32_t array[], uint16_t size);
void forTestLoops(uint8_t pram1, uint8_t param2);

int main(){
    int32_t sum, mean;

    int32_t array[ARRAYSIZE] = {1000, 1166, 1314, 1428, 1495, 1509, 1468, 1376, 1243, 1084, 916, 757, 624, 523, 491, 504, 572, 686, 834, 1000};
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

    forTestLoops(4,5);
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