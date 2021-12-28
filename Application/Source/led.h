/** ***************************************************************************
 * @file led.h
 * @brief see led.c
 * @authors Pavel Müller, Yves Röhrig
 * @date 26.11.2021
 *****************************************************************************/

#ifndef INC_LED_H_
#define INC_LED_H_

/******************************************************************************
 * Includes
 *****************************************************************************/
#include <stdbool.h>
#include <stdint.h>

/******************************************************************************
 * Defines
 *****************************************************************************/
void ExtLedInit(void);
void ExtLedSet(uint8_t ledNum, bool status);
void ExtLedSetLamptest(bool set);
void ExtLedSetDistance(bool set ,int32_t distance);
void ExtLetRun(void);
void ExtLedOl(int8_t led, int32_t data1[], int32_t data2[], int16_t size, int8_t sensitivity);

#endif /* INC_LED_H_ */
