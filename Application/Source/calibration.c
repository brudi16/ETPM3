/** ***************************************************************************
 * @file
 * @brief Functions for calibration process
 * 
 * Functions of calibration
 * ============================================================================
 * - Fill the calibration points into the calibration array
 * - Calibration of single points
 * - Function to call the interpolation process with measured calibration values
 * 
 * Array numbers
 * ============================================================================
 * The following list shows the number of the arrays used in this files and the
 * corresponding calibration arrray. @n
 * - 0: Pad 1
 * - 1: Pad 2
 * - 2: Hall Sensor 1, 1.2A
 * - 3: Hall Sensor 2, 1.2A
 * - 4: Hall Sensor 1, 5A
 * - 5: Hall Sensor 2, 5A  
 * @n
 * 
 * Calibration type
 * ==========================================================================
 * The following list shows the calibration types and their corresponding numbers.
 * - 0: Distance calibration
 * - 1: Current calibration 1.2A
 * - 2: Current calibration 5A
 * @n
 * 
 * @author  Pavel Müller, Yves Röhrig
 * @date	25.12.2021
 *****************************************************************************/

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "stm32f4xx.h"
#include "stm32f429i_discovery.h"
#include "calibration.h"
#include "calculations.h"
#include "signalProcessing.h"
#include "API.h"
#include "LUT.h"
/******************************************************************************
 * Defines
 *****************************************************************************/


/******************************************************************************
 * Variables
 *****************************************************************************/
// Constant Arrays
int16_t calDist[NUM_CALB_POINTS] = {2, 5, 10, 20, 50, 100, 200};      ///< Distances for calibration of the pads
int16_t calCurDist[NUM_CALB_POINTS] = {1, 2, 5, 7, 10, 15, 20};       ///< Distances for calibration of the Hall Sensors

// Pads
int16_t calPad1[NUM_CALB_POINTS];                                     ///< Measured calibraiton Points of pad 1
int16_t calPad2[NUM_CALB_POINTS];                                     ///< Measured calibraiton Points of pad 2

// Hall Sensors
int16_t calHall1_1A2[NUM_CALB_POINTS];                                ///< Measured calibraiton points of hall 1 with 1.2 A
int16_t calHall2_1A2[NUM_CALB_POINTS];                                ///< Measured calibration points of hall 2 with 1.2 A
int16_t calHall1_5A[NUM_CALB_POINTS];                                 ///< Measured calibration points of hall 1 with 5 A
int16_t calHall2_5A[NUM_CALB_POINTS];                                 ///< Measured calibration points of hall 2 with 5 A

/******************************************************************************
 * Functions
 *****************************************************************************/

/** ****************************************************************************
 * @brief Set the calibration points to the correspondet calibration array
 * 
 * @param[in] arrayNum  Number of the array to fill in (see filedescription)
 * @param[in] pointNum  Number of the point in the array to fill in
 * @param[in] value     Value to be filled in
 * 
 * This function fills in the measured calibration points in the corresponding array.
 * 
 ******************************************************************************/
void setCalPnt(int32_t arrayNum, int32_t pointNum, int32_t value){
    
    switch (arrayNum)
    {
    case 0: calPad1[pointNum] = value;
        break;
    case 1: calPad2[pointNum] = value;
        break;
    case 2: calHall1_1A2[pointNum] = value;
        break;
    case 3: calHall2_1A2[pointNum] = value;
        break;
    case 4: calHall1_5A[pointNum] = value;
        break;
    case 5: calHall2_5A[pointNum] = value;
        break;
    default: // this should nerver happen
        break;
    }

}

/** ****************************************************************************
 * @brief Calibration
 * 
 * @param[in] type 
 * @param[in] pointNum 
 ******************************************************************************/
void calibrateSingleValue(int32_t type,int32_t pointNum){
    uint32_t peakToPeak1 = 0, peakToPeak2 = 0;

    switch(type){
    case 0: // Distance calibration
        // fill peak values in the array
        setCalPnt(0,pointNum,peakToPeak1);
        setCalPnt(1,pointNum,peakToPeak2);
        break;
    case 1: // 1.2A calibration
        break;
    case 2: // 5A calibration
        break;
    default: // this should nerver happen
        break;
    }
}

/** ****************************************************************************
 * @brief 
 * 
 * @param[in] type 
 ******************************************************************************/
void calibration(void){
    if(calPad1[0] > 0 && calPad2[0] > 0){
        interpolCalDistance(calDist, calPad1, calDist, calPad2,  NUM_CALB_POINTS);
    }
    if(calHall1_1A2[0] > 0 && calHall1_5A[0] > 0 && calHall2_1A2 > 0 && calHall2_5A > 0){
        // Calibration process for hall sensors tbd
    }
}