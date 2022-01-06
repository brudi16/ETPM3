/** ***************************************************************************
 * @file
 * @brief Functions for calibration process
 * In this file the calibration functions will be included
 * 
 * 
 * @note This file is prepared for later functions regarding calibration
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
/******************************************************************************
 * Defines
 *****************************************************************************/


/******************************************************************************
 * Variables
 *****************************************************************************/
// Constant Arrays
const int16_t calDist[NUM_CALB_POINTS] = {2, 5, 10, 20, 50, 100, 200};      ///< Distances for calibration of the pads
const int16_t calCurDist[NUM_CALB_POINTS] = {1, 2, 5, 7, 10, 15, 20};       ///< Distances for calibration of the Hall Sensors

// Pads
int16_t calPad1[NUM_CALB_POINTS];                                           ///< Measured calibraiton Points of pad 1
int16_t calPad2[NUM_CALB_POINTS];                                           ///< Measured calibraiton Points of pad 2

// Hall Sensors
int16_t calHall1_1A2[NUM_CALB_POINTS];                                      ///< Measured calibraiton points of hall 1 with 1.2 A
int16_t calHall2_1A2[NUM_CALB_POINTS];                                      ///< Measured calibration points of hall 2 with 1.2 A
int16_t calHall1_5A[NUM_CALB_POINTS];                                       ///< Measured calibration points of hall 1 with 5 A
int16_t calHall2_5A[NUM_CALB_POINTS];                                       ///< Measured calibration points of hall 2 with 5 A

/******************************************************************************
 * Functions
 *****************************************************************************/

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

void calibrate(int32_t type,int32_t pointNum){
    
}