/** ***************************************************************************
 * @file
 * @brief access of the external LEDs
 *
 * Initializes and controls the external LEDs.
 * @n
 *
 * @author  Pavel Müller, muellpav@students.zhaw.ch
 * @date	26.11.2021
 *****************************************************************************/

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "stm32f4xx.h"
#include "stm32f429i_discovery.h"
#include "stm32f429i_discovery_lcd.h"
#include "stm32f429i_discovery_ts.h"

#include "main.h"

#include <stdbool.h>

/******************************************************************************
 * Functions
 *****************************************************************************/

/** ***************************************************************************
 * @brief Initialize all external LEDs
 *
 *
 * @n
 *****************************************************************************/
void ext_led_init(void){

	// Enable clk for all ports used for LEDs
	__HAL_RCC_GPIOB_CLK_ENABLE();					// Port B
	__HAL_RCC_GPIOC_CLK_ENABLE();					// Port C
	__HAL_RCC_GPIOD_CLK_ENABLE();					// Port D
	__HAL_RCC_GPIOE_CLK_ENABLE();					// Port E
	__HAL_RCC_GPIOG_CLK_ENABLE();					// Port G

	// Configure PINS as output
	GPIOC->MODER |= GPIO_MODER_MODER13;			// PC13 -> RUN LED
	GPIOE->MODER |= GPIO_MODER_MODER5;			// PE5  -> OL Hall
	GPIOE->MODER |= GPIO_MODER_MODER3;			// PC13 -> OL Pad
	GPIOB->MODER |= GPIO_MODER_MODER7;			// PB7  -> Distance 1
	GPIOD->MODER |= GPIO_MODER_MODER4;			// PD4  -> Distance 2
	GPIOD->MODER |= GPIO_MODER_MODER2;			// PD2  -> Distance 3
	GPIOC->MODER |= GPIO_MODER_MODER11;			// PC11 -> Distance 4
	GPIOG->MODER |= GPIO_MODER_MODER3;			// PG3  -> Distance 5

}

void ext_led_set(uint8_t ledNum, bool status){

}
