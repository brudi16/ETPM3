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
#define PAD_TO_PAD_DISTANCE     25        ///< Distance between pads in mm

/******************************************************************************
 * Functions
 *****************************************************************************/
int32_t getDistance(uint16_t size);
int32_t getAngle(void);
void removeDC(uint16_t size);

/******************************************************************************
 * variables
 *****************************************************************************/
extern uint32_t peakToPeakAv;      ///< global variable for the average peak to peak value
extern uint32_t peakToPeakPad1;       ///< global variable for the peak to peak value of pad 1
extern uint32_t peakToPeakPad2;       ///< global variable for the peak to peak value of pad 2

#endif