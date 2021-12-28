/** ***************************************************************************
 * @file
 * @brief See led.c
 *
 *
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

#endif /* INC_LED_H_ */
