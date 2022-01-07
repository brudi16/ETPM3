/** ***************************************************************************
 * @file
 * @brief Process the array with measured Values
 *
 * Functions for processing measured Values:
 * - Calculation of distance 
 * - Calculate angle to the main Cable with distances
 * - Copy Arrays from measurement array to processing array
 * @n
 *
 * @author  Pavel Müller, Yves Röhrig
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

/******************************************************************************
 * Variables
 *****************************************************************************/
int32_t distance1 = 0;          ///< global variable for the distance of pad 1
int32_t distance2 = 0;          ///< global variable for the distance of pad 2

uint32_t peakToPeakAv = 0;      ///< global variable for the average peak to peak value
uint32_t peakToPeakPad1 = 0;       ///< global variable for the peak to peak value of pad 1
uint32_t peakToPeakPad2 = 0;       ///< global variable for the peak to peak value of pad 2

/******************************************************************************
 * Functions
 *****************************************************************************/

/** ***************************************************************************
 * @brief Get the Distance
 * 
 * @param[in] size   Size of the arrays
 * 
 * This function calculates the distance from the two global arrays with the 
 * measured pad values. The following steps are done:
 * - The peak to peak Value of both arrays is calculated
 * - The distance is calculated from the LUT with the peak to peak values
 * - The average distance is calculated
 * 
*****************************************************************************/
int32_t getDistance(uint16_t arraySize){
    // variables

    uint32_t distanceAv = 0;

    // Calculate peak to peak Values of both arrays
    peakToPeakPad1 = calc_peakToPeak_av(pad1Values, arraySize, peakToPeakArrayHall1);
    peakToPeakPad2 = calc_peakToPeak_av(pad2Values, arraySize, peakToPeakArrayHall2);

    // Calculate average peak to peak value
    peakToPeakAv = ((peakToPeakPad1 + peakToPeakPad2)/2);
    // get the distance from the LUT
    distance1 = getXFromY(pad1Lut, LUT_SIZE_PAD, peakToPeakPad1);
    distance2 = getXFromY(pad2Lut, LUT_SIZE_PAD, peakToPeakPad2);

    // calculate distance
    distanceAv = calc_distance(distance1,distance2);

    return (int32_t)distanceAv;
}

/** ***************************************************************************
 * @brief Get the Angle to the main cable
 * 
 * @return int32_t 
 * 
 * calculates the angle by the difference from the two distances of the pads.
 * As the Distance between the center of the two pads is 25mm this physical
 * information is used to calculate the angle to the main cable. For this the
 * difference between the distances is calculated. With the difference the
 * following cases are possible:
 * - difference is between -25 and -18  -> -90°
 * - difference is between -18 and -6   -> -45°
 * - difference is between -6 and 6     ->   0°
 * - difference is between 6 and 18     ->  45°
 * - difference is between 18 and 25    ->  90°
 * - In all other cases the angle is set to 999°
 * 
 * @warning For correct function the LUT for the pads must be calibrated well.
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
/** ***************************************************************************
 * @brief Remove the DC-value from all arrays
 * 
 * @param[in] size Size of the arrays
 * 
 * The DC-Value is removed from all arrays with the function calc_removeDC from
 * calculations.c.
 *****************************************************************************/
void removeDC(uint16_t size){
		calc_removeDc(pad1Values, size);
		calc_removeDc(pad2Values, size);
		calc_removeDc(hall1Values, size);
		calc_removeDc(hall2Values, size);
}