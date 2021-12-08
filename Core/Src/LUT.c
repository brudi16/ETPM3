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
