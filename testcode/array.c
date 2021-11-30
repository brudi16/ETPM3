#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define ARRAYSIZE   20

uint32_t arrayMean(uint32_t array[], uint8_t size);
void printArray(uint32_t array[], uint8_t size);
void removeMean(uint32_t array[], uint8_t size);
void rectify(uint32_t array[], uint8_t size);
void convertToSigned(uint32_t **array[], uint8_t);

int main(){
    uint32_t sum, mean;

    uint32_t array[ARRAYSIZE] = {1000, 1166, 1314, 1428, 1495, 1509, 1468, 1376, 1243, 1084, 916, 757, 624, 523, 491, 504, 572, 686, 834, 1000};
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

    return 0;
}

uint32_t arrayMean(uint32_t array[], uint8_t size){
    uint32_t mean = 0;
    int i;

    for(i=0; i<size; i++){
        mean = mean + array[i];
    }

    mean = mean / size;
    return mean;
}

void printArray(uint32_t array[], uint8_t size){
    int i;

    printf("Array: ");
    
    for(i=0; i<size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

void removeMean(uint32_t array[], uint8_t size){
    int i;
    uint32_t mean = arrayMean(array, size);

    for(i=0; i<size; i++){
        array[i] = array[i] - mean;
    }
}

void rectify(uint32_t array[], uint8_t size){
    int i;
    uint32_t cmpVal = 0;
    
    for(i=0; i<size; i++){
        if(array[i] < 0)
            array[i] = array[i] *-1;
    }

}

void convertToSigned (uint32_t **array[], uint8_t size){
    int32_t *tmp = calloc(size, sizeof(int32_t));
    int i;

    for(i=0; i<size; i++){
        *(tmp+i) = (int32_t)array[i];
    }

    free(*array);
    *array = tmp;
}