/** ***************************************************************************
 * @file
 * @brief See LUT.c
 *
 *
 *****************************************************************************/
#ifndef SRC_LUT_H
#define SRC_LUT_H

/******************************************************************************
 * Defines
 *****************************************************************************/
#define LUT_SIZE_PAD    200          ///< Length of the LUT for the Pads
//#define LUT_SIZE_HALL  200          ///< Length of the LUT for the Hall Sensor  

extern int16_t padLut[LUT_SIZE_PAD];
//extern int16_t hallLut[LUT_SIZE];

/******************************************************************************
 * Functions
 *****************************************************************************/
 void initLUT(void);
 void interpolCalDistance(int16_t x[], int16_t y[], int32_t xySize);


 #endif