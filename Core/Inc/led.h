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


/******************************************************************************
 * Defines
 *****************************************************************************/
void ext_led_init(void);
void ext_led_set(uint8_t ledNum, bool status);
void ext_led_lamptest(uint16_t time);

#endif /* INC_LED_H_ */
