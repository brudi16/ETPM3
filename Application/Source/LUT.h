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
#define LUT_HALL_ROWS   50          ///< Rows of the LUT for the Hall Sensor
#define LUT_HALL_COLUMNS   20          ///< Columns of the LUT for the Hall Sensor

/******************************************************************************
 * Variables
 *****************************************************************************/
extern uint16_t pad1Lut[LUT_SIZE_PAD];  ///< LUT for the pad 1
extern uint16_t pad2Lut[LUT_SIZE_PAD];  ///< LUT for the pad 2
extern int16_t hall1Lut[LUT_HALL_ROWS][LUT_HALL_COLUMNS]; ///< LUT for the Hall Sensor 1
extern int16_t hall2Lut[LUT_HALL_ROWS][LUT_HALL_COLUMNS]; ///< LUT for the Hall Sensor 2

/******************************************************************************
 * Functions
 *****************************************************************************/
 void initLUT(void);
 void interpolCalDistance(int16_t x1[], int16_t y1[], int16_t x2[], int16_t y2[], int32_t xySize);


 #endif