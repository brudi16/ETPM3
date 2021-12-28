/** ***************************************************************************
 * @file
 * @brief See calculations.h
 *
 * @authors  Pavel Müller, Yves Röhrig
 * @date	28.11.2021
 *****************************************************************************/

#ifndef SRC_CALCULATIONS_H_
#define SRC_CALCULATIONS_H_

#include "stdint.h"
#include "measuring.h"

/******************************************************************************
 * Defines
 *****************************************************************************/
#define NUM_TAPS 63             ///< Number of filter coefficients for the FIR filter
#define NUM_PERIODS_MAX 20      ///< Maximal number of periods of the measuring signal

/******************************************************************************
 * Functions
 *****************************************************************************/

// Basic calculations
int32_t calc_dcValue(int32_t ADC_samples[], uint16_t size);
void calc_removeDc(int32_t ADC_samples[], uint16_t size);
uint32_t calc_peakToPeak_av(int32_t ADC_samples[], uint16_t size, uint32_t peakPeakArray[]);
int32_t calc_rmsValue(int32_t ADC_samples[], uint16_t size);
int32_t LinearInterpol(int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t xp);
uint32_t calc_distance(uint32_t distance1, uint32_t distance2);

// Advanced calculations
uint32_t calcStdDev(uint32_t peakPeakArray1[], uint32_t peakPeakArray2[], int32_t size);
int32_t LinearInterpol(int32_t x0, int32_t y0, int32_t x1, int32_t y1, int32_t xp);

// Search function
uint32_t getXFromY(uint16_t array[], int32_t size, uint32_t yValue);

// Copy function
void cpyArrays(uint16_t size);

// Filter
void filter_hall(void);

/******************************************************************************
 * external variables
 *****************************************************************************/

extern int32_t pad1Values[ADC_NUMS_ACU];                //< Pad 1 array with copied values from measurement data
extern int32_t pad2Values[ADC_NUMS_ACU];                //< Pad 2 array with copied values from measurement data
extern int32_t hall1Values[ADC_NUMS_ACU];               //< Hall Sensor 1 array with copied values from measurement data
extern int32_t hall2Values[ADC_NUMS_ACU];               //< Hall Sensor 2 array with copied values from measurement data

extern uint32_t peakToPeakArrayPad1[NUM_PERIODS_MAX];	///< Pad 1 array with peak to peak values for every period of the signal
extern uint32_t peakToPeakArrayPad2[NUM_PERIODS_MAX];	///< Pad 2 array with peak to peak values for every period of the signal
extern uint32_t peakToPeakArrayHall1[NUM_PERIODS_MAX];	///< Hall Sensor 1 array with peak to peak values for every period of the signal
extern uint32_t peakToPeakArrayHall2[NUM_PERIODS_MAX];  ///< Hall Sensor 2 array with peak to peak values for every period of the signal

#endif /* SRC_CALCULATIONS_H_ */

