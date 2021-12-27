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
#include "stm32f429i_discovery_ts.h"
#include "led.h"
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
void ExtLedInit(void){

	// Enable clk for all ports used for LEDs
	__HAL_RCC_GPIOB_CLK_ENABLE();					// Port B
	__HAL_RCC_GPIOC_CLK_ENABLE();					// Port C
	__HAL_RCC_GPIOD_CLK_ENABLE();					// Port D
	__HAL_RCC_GPIOE_CLK_ENABLE();					// Port E
	__HAL_RCC_GPIOG_CLK_ENABLE();					// Port G

	// Configure PINS as output
	GPIOC->MODER |= GPIO_MODER_MODER13_0;			// PC13 -> RUN LED
	GPIOE->MODER |= GPIO_MODER_MODER5_0;			// PE5  -> OL Hall
	GPIOE->MODER |= GPIO_MODER_MODER3_0;			// PE3  -> OL Pad
	GPIOB->MODER |= GPIO_MODER_MODER7_0;			// PB7  -> Distance 1
	GPIOD->MODER |= GPIO_MODER_MODER4_0;			// PD4  -> Distance 2
	GPIOD->MODER |= GPIO_MODER_MODER2_0;			// PD2  -> Distance 3
	GPIOC->MODER |= GPIO_MODER_MODER11_0;			// PC11 -> Distance 4
	GPIOG->MODER |= GPIO_MODER_MODER3_0;			// PG3  -> Distance 5

}

void ExtLedSet(uint8_t ledNum, bool status){
	switch(ledNum){
	case 0:											// RUN LED
		if (status == true){
			GPIOC->BSRR |= GPIO_BSRR_BS13;			// Set
		}else{
			GPIOC->BSRR |= GPIO_BSRR_BR13;			// Reset
		}
	break;
	case 1:											// OL Hall LED
		if (status == true){
			GPIOE->BSRR |= GPIO_BSRR_BS5;			// Set
		}else{
			GPIOE->BSRR |= GPIO_BSRR_BR5;			// Reset
		}
	break;
	case 2:											// OL Pad LED
		if (status == true){
			GPIOE->BSRR |= GPIO_BSRR_BS3;			// Set
		}else{
			GPIOE->BSRR |= GPIO_BSRR_BR3;			// Reset
		}
		break;
	case 3:											//Distance 1 LED
		if (status == true){
			GPIOB->BSRR |= GPIO_BSRR_BS7;			// Set
		}else{
			GPIOB->BSRR |= GPIO_BSRR_BR7;			// Reset
		}
		break;
	case 4:											//Distance 2 LED
		if (status == true){
			GPIOD->BSRR |= GPIO_BSRR_BS4;			// Set
		}else{
			GPIOD->BSRR |= GPIO_BSRR_BR4;			// Reset
		}
		break;
	case 5:											//Distance 3 LED
		if (status == true){
			GPIOD->BSRR |= GPIO_BSRR_BS2;			// Set
		}else{
			GPIOD->BSRR |= GPIO_BSRR_BR2;			// Reset
		}
		break;
	case 6:											//Distance 4 LED
		if (status == true){
			GPIOC->BSRR |= GPIO_BSRR_BS11;			// Set
		}else{
			GPIOC->BSRR |= GPIO_BSRR_BR11;			// Reset
		}
		break;
	case 7:											//Distance 5 LED
		if (status == true){
			GPIOG->BSRR |= GPIO_BSRR_BS3;			// Set
		}else{
			GPIOG->BSRR |= GPIO_BSRR_BR3;			// Reset
		}
		break;
	default:
		// Should never ocour
	break;
	}
}

/**
 * @brief Lamptest for the cable monitor hardware
 * 
 * @param set 
 */
void ExtLedSetLamptest(bool set){
	if(set){
		for (uint8_t i=0; i<8; i++){
			ExtLedSet(i, true);
		}
	} else{
		for (uint8_t i=0; i<8; i++){
			ExtLedSet(i, false);
		}
	}
}

/**
 * @brief Logic for the distance LED's of the cable monitor
 * 
 * @param set activates the distance LED's if true
 * @param distance in mm
 */
void ExtLedSetDistance(bool set ,int32_t distance){
	if(set){
		if(distance >= 200){
			ExtLedSet(3, true);
			ExtLedSet(4, false);
			ExtLedSet(5, false);
			ExtLedSet(6, false);
			ExtLedSet(7, false);
		} else if (distance >= 150){
			ExtLedSet(3, true);
			ExtLedSet(4, true);
			ExtLedSet(5, false);
			ExtLedSet(6, false);
			ExtLedSet(7, false);
		} else if (distance >= 100){
			ExtLedSet(3, true);
			ExtLedSet(4, true);
			ExtLedSet(5, true);
			ExtLedSet(6, false);
			ExtLedSet(7, false);
		} else if (distance >= 50){
			ExtLedSet(3, true);
			ExtLedSet(4, true);
			ExtLedSet(5, true);
			ExtLedSet(6, true);
			ExtLedSet(7, false);
		} else if (distance >= 0){
			ExtLedSet(3, true);
			ExtLedSet(4, true);
			ExtLedSet(5, true);
			ExtLedSet(6, true);
			ExtLedSet(7, true);
		}
	} else{
		ExtLedSet(3, false);
		ExtLedSet(4, false);
		ExtLedSet(5, false);
		ExtLedSet(6, false);
		ExtLedSet(7, false);
	}
}
