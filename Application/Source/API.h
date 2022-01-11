/** ***************************************************************************
 * @file API.h
 * @brief see API.c
 * @authors Pavel Müller, Röhrig Yves
 * @date 25.12.2021
 *****************************************************************************/
#ifndef INC_API_H_
#define INC_API_H_

/******************************************************************************
 * Includes
 *****************************************************************************/
#include <stdint.h>
#include <stdbool.h>

/******************************************************************************
 * Defines
 *****************************************************************************/
void cmInitAll(void);
int32_t cmGetCurrent(void);
int32_t cmGetDistance(void);
int32_t cmGetAngle(void);
int32_t cmGetDebugHall1(void);
int32_t cmGetDebugHall2(void);
int32_t cmGetDebugPad1(void);
int32_t cmGetDebugPad2(void);
void cmSetLampTest(bool set);
void adcInit(void);
void adcMeas(void);
void cmSetPrecision(bool precision);
void cmGetSelectetWire(int32_t selection);
bool cmMainsDetected(void);
int32_t cmGetStandartDeviation(void);
void cmSetDistanceLED(bool set);
void cmRunLED(void);
void cmOlLed(void);
void cmSetCalibrationValue(int32_t setArray, int32_t setPosition);
void cmSetCalibrationOn(bool on);
void cmSaveCalibration(void);
void cmResetCalibration(void);
int32_t cmGetPadPeakToPeak(void);
int32_t cmGetHallPeakToPeak(void);

extern uint16_t arraySize;

#endif /* INC_API_H_ */