/** ***************************************************************************
 * @file led.c
 * @brief access of the external LEDs
 *
 * Initializes and controls the external LEDs.
 *
 * @author  Pavel Müller, Yves Röhrig
 * @date	26.11.2021
 *****************************************************************************/

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "stm32f429i_discovery_ts.h"
#include "stm32f4xx_hal.h"
#include "led.h"
#include <stdbool.h>
/******************************************************************************
 * Variables
 *****************************************************************************/
bool lamptestOn = false;


/******************************************************************************
 * Functions
 *****************************************************************************/

/** ***************************************************************************
 * @brief Initialize all external LEDs
 *
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

/** ***************************************************************************
 * @brief Set all LEDs of the cable monitor hardware
 * @param ledNum Number of the LED
 * @param status Set to true or false to turn the LED on or off
 *
 * This function enables easy control of the LEDs
 * 
 *****************************************************************************/
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

/** ***************************************************************************
 * @brief Lamptest for the cable monitor hardware
 * @param set Set this parameter true or false to turn all LEDs on or off
 * 
 *****************************************************************************/
void ExtLedSetLamptest(bool set){
	if(set){
		for (uint8_t i=0; i<8; i++){	// switch on all LEDs
			ExtLedSet(i, true);
		}
		lamptestOn = true;
	} else{
		for (uint8_t i=0; i<8; i++){	// switch off all LEDs
			ExtLedSet(i, false);
		}
		lamptestOn = false;
	}
}

/** ***************************************************************************
 * @brief Logic for the distance LED's of the cable monitor
 * @param set activates the distance LED's if true
 * @param distance in mm
 * 
 *****************************************************************************/
void ExtLedSetDistance(bool set ,int32_t distance){
	if(!lamptestOn){
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
}


/** ***************************************************************************
 * @brief ExtLetRun
 *
 * This function controls the run LED on the cable monitor hardware
 *
 *****************************************************************************/
void ExtLetRun(void){
	static uint32_t tickstart = 0;
	uint32_t wait = 500;
	static uint8_t state = 0;

	switch(state){
	case 0:
		if((tickstart + wait) < HAL_GetTick()){
			ExtLedSet(0, true);
			tickstart = HAL_GetTick();
			state = 1;
		}
		break;

	case 1:
		if((tickstart + wait) < HAL_GetTick()){
			ExtLedSet(0, false);
			tickstart = HAL_GetTick();
			state = 0;
		}
		break;
	
	default:
		break;
	}
}

/** ***************************************************************************
 * @brief ExtLetOl
 * @param led select OL led
 * @param data1 first adc data array
 * @param data2 second adc data array
 * @param size size of arrays
 * @param sensitivity set a value greater then one to change the sensitivity of the ol led
 *
 * This function controls the overload LED on the cable monitor hardware.
 *
 *****************************************************************************/
void ExtLedOl(int8_t led, int32_t data1[], int32_t data2[], int16_t size, int8_t sensitivity){
	int8_t zeroCounter1 = 0;
	int8_t maxCounter1 = 0;
	int8_t zeroCounter2 = 0;
	int8_t maxCounter2 = 0;

	for(int16_t i=0; i<size; i++){
		if(data1[i] <= 20){
			zeroCounter1++;
		}
		if(data1[i] >= 4075){
			maxCounter1++;
		}
		if(data2[i] <= 20){
			zeroCounter2++;
		}
		if(data2[i] >= 4075){
			maxCounter2++;
		}
	}

	if ((zeroCounter1 >= sensitivity)||(maxCounter1 >= sensitivity)){
		ExtLedSet(led, true);
	} else if ((zeroCounter2 >= sensitivity)||(maxCounter2 >= sensitivity)){
		ExtLedSet(led, true);
	} else{
		ExtLedSet(led, false);
	}
}