/** ***************************************************************************
 * @file
 * @brief Process the array with measured Values
 *
 * Functions for processing signals
 * @n
 *
 * @author  Pavel Müller, muellpav@students.zhaw.ch
 * @date	10.12.2021
 *****************************************************************************/

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "stm32f4xx.h"
#include "stm32f429i_discovery.h"
#include "stm32f429i_discovery_ts.h"

#include "signalProcessing.h"
#include "calculations.h"
#include "measuring.h"
#include "LUT.h"
//#include "arm_math.h"


/******************************************************************************
 * Variables
 *****************************************************************************/
int32_t distance1 = 0;
int32_t distance2 = 0;

/******************************************************************************
 * Functions
 *****************************************************************************/

/** ***************************************************************************
 * @brief Get the Distance object
 * 
 * @param array1 Array with values from pad 1
 * @param array2 Array with values form pad 2
 * @param size   Size of the arrays
*****************************************************************************/
int32_t getDistance(uint16_t arraySize){
    // variables
    uint32_t peakToPeak1 = 0, peakToPeak2 = 0;
    uint32_t distanceAv = 0;

    // Calculate peak to peak Values of both arrays
    peakToPeak1 = calc_peakToPeak_av(pad1Values, arraySize);
    peakToPeak2 = calc_peakToPeak_av(pad2Values, arraySize);

    // get the distance from the LUT
    distance1 = getXFromY(pad1Lut, LUT_SIZE_PAD, peakToPeak1);
    distance2 = getXFromY(pad2Lut, LUT_SIZE_PAD, peakToPeak2);

    // calculate distance
    distanceAv = calc_distance(distance1,distance2);

    return (int32_t)distanceAv;
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

void removeDC(uint16_t size){
		calc_removeDc(pad1Values, size);
		calc_removeDc(pad2Values, size);
		calc_removeDc(hall1Values, size);
		calc_removeDc(hall2Values, size);
}