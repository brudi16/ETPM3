/**
 * @file API.c
 * @author Yves Röhrig, roehryve@students.zhaw.ch
 * @brief 
 * @version 0.1
 * @date 2021-12-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdint.h>
#include <stdbool.h>
#include "API.h"
#include "led.h"
#include "measuring.h"
#include "stm32f4xx.h"
#include "stm32f429i_discovery.h"

static void gyro_disable(void);

/**
 * @brief Main initialisation funtkion
 * 
 * This funktion calls all initialisation funktion for the cabel monitor hardware.
 * 
 */
void cmInitAll(void){
    // Function call of all initialisation functions...

    ExtLedInit(); // initialize all GPIOs for lamptest
}

/**
 * @brief Current meassurement funktion
 * 
 * This funktion calls all initialisation funktion for the cabel monitor hardware.
 * 
 */
int32_t cmGetCurrent(void){
    // Function call of all required functions to return the current value...
    int32_t current = 7; // This variable represense the meassured current in ampere
    return current;
}

/**
 * @brief Distance meassurement funktion
 * 
 * This funktion calls all initialisation funktion for the cabel monitor hardware.
 * 
 */
int32_t cmGetDistance(void){
    // Function call of all required functions to return the distance value...
    int32_t distance = 155; // Distance in mm
    return distance;
}

/**
 * @brief Angle meassurement funktion
 * 
 * This funktion calls all initialisation funktion for the cabel monitor hardware.
 * 
 */
int32_t cmGetAngle(void){
    // Function call of all required functions to return the angle value...
    int32_t angle = 52; // Angle in degree
    return angle;
}

/**
 * @brief Debug funktion
 * 
 * This funktion calls a debug funktion for the cabel monitor hardware.
 * 
 */
int32_t cmGetDebugHall1(void){
    // Function call of all required functions to return a debug value...
    int32_t hall = 2436; // Debug hall value
    return hall;
}

/**
 * @brief Debug funktion
 * 
 * This funktion calls a debug funktion for the cabel monitor hardware.
 * 
 */
int32_t cmGetDebugHall2(void){
    // Function call of all required functions to return a debug value...
    int32_t hall = 666; // Debug hall value
    return hall;
}

/**
 * @brief Debug funktion
 * 
 * This funktion calls a debug funktion for the cabel monitor hardware.
 * 
 */
int32_t cmGetDebugPad1(void){
    // Function call of all required functions to return a debug value...
    int32_t pad = 4567; // Debug pad value
    return pad;
}

/**
 * @brief Debug funktion
 * 
 * This funktion calls a debug funktion for the cabel monitor hardware.
 * 
 */
int32_t cmGetDebugPad2(void){
    // Function call of all required functions to return a debug value...
    int32_t pad = 123; // Debug pad value
    return pad;
}

/**
 * @brief Lamptest on funktion
 * 
 * This funktion calls all initialisation funktion for the cabel monitor hardware.
 * 
 */
void cmSetLampTest(void){
    ExtLedSetLamptest(); // Switch all LEDs on
}

/**
 * @brief Lamptest off funktion
 * 
 * This funktion calls all initialisation funktion for the cabel monitor hardware.
 * 
 */
void cmDisableLampTest(void){
    ExtLedDisableLamptest(); // Switch all LEDs off
}

/**
 * @brief ADC initialisation
 * 
 */
void adcInit(void){
    gyro_disable();						// Disable gyro, use those analog inputs
    MEAS_GPIO_analog_init();			// Configure GPIOs in analog mode
	MEAS_timer_init();					// Configure the timer
}

/**
 * @brief ADC Measuring
 * 
 */
void adcMeas(void){
    ADC3_IN4_DMA_init();                // Initialize ADC1 IN13 & ADC3 IN6
    //ADC3_IN4_DMA_start();    // Start measurement with ADC1 IN13 & ADC3 IN6
}

static void gyro_disable(void)
{
	__HAL_RCC_GPIOC_CLK_ENABLE();		// Enable Clock for GPIO port C
	/* Disable PC1 and PF8 first */
	GPIOC->MODER &= ~GPIO_MODER_MODER1; // Reset mode for PC1
	GPIOC->MODER |= GPIO_MODER_MODER1_0;	// Set PC1 as output
	GPIOC->BSRR |= GPIO_BSRR_BR1;		// Set GYRO (CS) to 0 for a short time
	HAL_Delay(10);						// Wait some time
	GPIOC->MODER |= GPIO_MODER_MODER1_Msk; // Analog mode PC1 = ADC123_IN11
	__HAL_RCC_GPIOF_CLK_ENABLE();		// Enable Clock for GPIO port F
	GPIOF->OSPEEDR &= ~GPIO_OSPEEDR_OSPEED8;	// Reset speed of PF8
	GPIOF->AFR[1] &= ~GPIO_AFRH_AFSEL8;			// Reset alternate func. of PF8
	GPIOF->PUPDR &= ~GPIO_PUPDR_PUPD8;			// Reset pulup/down of PF8
	HAL_Delay(10);						// Wait some time
	GPIOF->MODER |= GPIO_MODER_MODER8_Msk; // Analog mode for PF6 = ADC3_IN4
}