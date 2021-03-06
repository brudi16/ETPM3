/** ***************************************************************************
 * @file
 * @brief See LUT.c
 *
 *
 *****************************************************************************/
#ifndef SRC_LUT_H
#define SRC_LUT_H

/******************************************************************************
 * Includes
 *****************************************************************************/

/******************************************************************************
 * Defines
 *****************************************************************************/
#define LUT_SIZE_Pad    200          ///< Length of the LUT for the Pads
//#define LUT_SIZE_Pad  200          ///< Length of the LUT for the Hall Sensor  

/******************************************************************************
 * Functions
 *****************************************************************************/
 void initLUT(void);
 void interpolCalDistance(int16_t x[], int16_t y[], int32_t xySize);


 #endif