/** ***************************************************************************
 * @file
 * @brief Function for LUTs
 * This file contains the following functionality:
 * @n
 * Operations with the LUT
 * -----------------------
 * - Initialisation of LUT arrays with the start Values
 * 
 * Calibration of the LUT
 * ----------------------
 * - Interpolation of measured calibration values
 *
 * @author  Pavel Müller, muellpav@students.zhaw.ch
 * @date	06.12.2021
 *****************************************************************************/

/******************************************************************************
 * Includes
 *****************************************************************************/
#include <stdint.h>
#include <stdbool.h>

#include "calculations.h"
#include "LUT.h"

/******************************************************************************
 * Variables
 *****************************************************************************/
const uint16_t padLutStartValues[] = {          ///< Start values for the LUT of the Pads (included with a .csv)
    #include "lutPad.csv"
};

const uint16_t pad1LutStartValues[] = {
    #include "lutPad1.csv"
};

const uint16_t pad2LutStartValues[] = {
    #include "lutPad1.csv"
};

// const int16_t hallLutStartValues[50][20] = {          ///< Start values for the LUT of the Hall Sensors (included with a .csv)
//    #include "lutHall.csv"
// };

uint16_t pad1Lut[LUT_SIZE_PAD];                 ///< LUT for the pad 1
uint16_t pad2Lut[LUT_SIZE_PAD];                 ///< LUT for the pad 2


// uint16_t hall1Lut[LUT_HALL_ROWS][LUT_HALL_COLUMNS];             ///< LUT for the Hall Sensor 1
// uint16_t hall2Lut[LUT_HALL_ROWS][LUT_HALL_COLUMNS];             ///< LUT for the Hall Sensor 2

/******************************************************************************
 * Functions
 *****************************************************************************/

/** ****************************************************************************
 * @brief Initialisation of the LUTs
 * 
 * All LUTs are initialised with the start values. 
 * 
 ******************************************************************************/
void initLUT(void){
    #ifdef LUT_SIZE_PAD
        for(uint16_t i=0;i<LUT_SIZE_PAD;i++){
            pad1Lut[i] = pad1LutStartValues[i];
            pad2Lut[i] = pad2LutStartValues[i];
        }
    #endif

    // #ifdef LUT_HALL_ROWS
    //     for(uint16_t c=0;c<LUT_HALL_ROWS;c++){
    //         for(uint16_t i=0;i<LUT_HALL_ROWS;i++){
    //             hall1Lut[c][i] = hallLutStartValues[c][i];
    //             hall2Lut[c][i] = hallLutStartValues[c][i];
    //         }
    //     }
    // #endif
}

/** ****************************************************************************
 * @brief interpolate Calibration values
 * 
 * @param[in] x1 Array with calibration Distances for pad 1
 * @param[in] y1 Array with measured calibration values for pad 1
 * @param[in] x2 Array with calibration Distances for pad 2
 * @param[in] y2 Array with measured calibration values for pad 2
 * @param[in] xSize Size of the calibration array
 * 
 * The LUT for the distances is filled with interpolated values. These values are
 * calculated form the interpolated calibration array.
 * 
 ******************************************************************************/
void interpolCalDistance(int16_t x1[], int16_t y1[], int16_t x2[], int16_t y2[], int32_t xSize){
    int16_t i,j;
    bool l;
    
    // Pad 1
    // loop for the different distances
    for(i=0;i<xSize;i++){
        l = false;
        // loop for Values
        for(j=0;j<x1[i];j++){
            // set start value of j to value from last loop
            if(i>0 && l == false){
                j = x1[i-1];
                l = true;
            }
            if(j == 0){
                // do nothing
            }else if(j< x1[0]){
                // for first intervall of distance
                pad1Lut[j] = LinearInterpol(1,padLutStartValues[0],x1[0],y1[0],(j+1));
            }else{
                pad1Lut[j] = LinearInterpol(x1[(i-1)],y1[(i-1)],x1[(i)],y1[(i)],(j+1));
            }
        }
    }

    // Pad 2
    // loop for the different distances
    for(i=0;i<xSize;i++){
        l = false;
        // loop for Values
        for(j=0;j<x2[i];j++){
            // set start value of j to value from last loop
            if(i>0 && l == false){
                j = x2[i-1];
                l = true;
            }
            if(j == 0){
                // do nothing
            }else if(j< x2[0]){
                // for first intervall of distance
                pad2Lut[j] = LinearInterpol(1,padLutStartValues[0],x2[0],y2[0],(j+1));
            }else{
                pad2Lut[j] = LinearInterpol(x2[(i-1)],y2[(i-1)],x2[(i)],y2[(i)],(j+1));
            }
        }
    }
}
