/** ***************************************************************************
 * @file
 * @brief See signalProcessing.c
 *
 *
 *****************************************************************************/
#ifndef SRC_SIGNALPROCESSING_H
#define SRC_SIGNALPROCESSING_H

/******************************************************************************
 * Defines
 *****************************************************************************/
int32_t getDistance(int32_t array1[], int32_t array2[], int32_t size);
int32_t getAngle(void);



#define PAD_TO_PAD_DISTANCE     25        ///< Distance between pads in mm

#endif