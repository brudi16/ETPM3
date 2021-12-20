/** ***************************************************************************
 * @file
 * @brief See LUT.c
 *
 *
 *****************************************************************************/
#ifndef SRC_LUT_H
#define SRC_LUT_H

#include <stdint.h>
/******************************************************************************
 * Defines
 *****************************************************************************/
#define LUT_SIZE_PAD    200          ///< Length of the LUT for the Pads
//#define LUT_X_SIZE_HALL   200          ///< Length of the LUT for the Hall Sensor
//#define LUT_Y_SIZE_HALL   200          ///< Length of the LUT for the Hall Sensor

extern uint16_t pad1Lut[LUT_SIZE_PAD];
extern uint16_t pad2Lut[LUT_SIZE_PAD];
//extern int16_t hall1Lut[LUT_SIZE];
//extern int16_t hall2Lut[LUT_SIZE];

/******************************************************************************
 * Functions
 *****************************************************************************/
 void initLUT(void);
 void interpolCalDistance(int16_t x1[], int16_t y1[], int16_t x2[], int16_t y2[], int32_t xySize);


 #endif