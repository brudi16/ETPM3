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
void cmSetLampTest(void);
void cmDisableLampTest(void);

#endif /* INC_API_H_ */