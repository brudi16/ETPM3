#ifndef INC_API_H_
#define INC_API_H_

#include <stdint.h>
#include <stdbool.h>

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

extern uint16_t arraySize;

#endif /* INC_API_H_ */