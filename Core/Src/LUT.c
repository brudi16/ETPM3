/** ***************************************************************************
 * @file
 * @brief LUT for the PAD and Hallsensor
 *
 *
 * @n
 *
 * @author  Pavel Müller, muellpav@students.zhaw.ch
 * @date	06.12.2021
 *****************************************************************************/

/******************************************************************************
 * Includes
 *****************************************************************************/
#include <stdint.h>
#include <stdbool.h>

#include "../Inc/LUT.h"


const int16_t padLutStartValues[] = {
    #include "lutPad.csv"
};

//const int16_t hallLutStartValues[] = {
    //#include "lutHall.csv"
//};

int16_t padLut[LUT_SIZE_Pad];
//int16_t hallLut[LUT_SIZE];

void initLUT(void){
    #ifdef LUT_SIZE_PAD
        uint16_t i;
        for(i=0;i<LUT_SIZE_Pad;i++){
            padLut[i] = padLutStartValues[i];
        }
    #endif

    #ifdef LUT_SIZE_HALL
        for(i=0;i<LUT_SIZE_Hall;i++){
            hallLut[i] = hallLutStartValues[i];
        }
    #endif
}

/**
 * @brief interpolate Calibration values
 * 
 * @param x Array with calibration Distances
 * @param y Array with measured calibration values
 * @param xySize Size of the calibration array
 */
void interpolCalDistance(int16_t x[], int16_t y[], int32_t xySize){
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
        }
    }
}
