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
int32_t getDistance(uint16_t size);
int32_t getAngle(void);
void removeDC(uint16_t size);


#define PAD_TO_PAD_DISTANCE     25        ///< Distance between pads in mm

#endif