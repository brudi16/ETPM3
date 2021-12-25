/**
 * @file API.c
 * @author Yves Röhrig, roehryve@students.zhaw.ch
 * @brief This file contains the API and serves as an interface between the hardware functions and the Graphical User Interface.
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
#include "calculations.h"
#include "signalProcessing.h"
#include "stm32f4xx.h"
#include "stm32f429i_discovery.h"


uint8_t measCase = 0;
uint8_t arraySize = ADC_NUMS;
int32_t selectetWire = 1;


/**
 * @brief Initialisation call for all hardware functions
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
    int32_t current = selectetWire; // This variable represense the meassured current in ampere
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
    int32_t distance = 152; // Distance in mm
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
		calc_removeDc(ADC_HALL1_samples,ADC_NUMS);
    int32_t hall = (int32_t)calc_peakToPeak_av(ADC_HALL1_samples, ADC_NUMS); // Debug hall value

    

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
    calc_removeDc(ADC_HALL2_samples,ADC_NUMS);
    int32_t hall = (int32_t)calc_peakToPeak_av(ADC_HALL2_samples, ADC_NUMS); // Debug hall value

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
    calc_removeDc(ADC_PAD1_samples,ADC_NUMS);
    int32_t pad = (int32_t)calc_peakToPeak_av(ADC_PAD1_samples, ADC_NUMS); // Debug pad value

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
    calc_removeDc(ADC_PAD2_samples,ADC_NUMS);
    int32_t pad = (int32_t)calc_peakToPeak_av(ADC_PAD2_samples, ADC_NUMS); // Debug pad value
    return pad;
}

/**
 * @brief Lamptest on funktion
 * 
 * This funktion calls all initialisation funktion for the cabel monitor hardware.
 * 
 */
void cmSetLampTest(bool set){
    ExtLedSetLamptest(set); // Switch all LEDs on
}

/**
 * @brief ADC initialisation
 * 
 */
void adcInit(void){
    SystemClock_Config();				// Configure system clocks
    gyro_disable();						// Disable gyro, use those analog inputs
    MEAS_GPIO_analog_init();			// Configure GPIOs in analog mode
	MEAS_timer_init();					// Configure the timer
}

/**
 * @brief ADC Measuring
 * 
 */
void adcMeas(void){
	if(MEAS_data_ready){
		switch (measCase){
		case 0:
			ADC3_IN4_DMA_init(arraySize);	// Initialize ADC3 IN4
			ADC3_IN4_DMA_start();   // Start measurement with ADC3 IN4
			measCase = 1;
			break;

		case 1:
			ADC3_IN6_DMA_init(arraySize);	// Initialize ADC3 IN6
			ADC3_IN6_DMA_start();	// Start measurement with ADC3 IN6
			measCase = 2;
			break;
			
		case 2:
			ADC1_IN11_ADC2_IN13_dual_init(arraySize);	// Initialize ADC1 IN11 & ADC2 IN13
			ADC1_IN11_ADC2_IN13_dual_start();	// Start measurement with ADC1 IN11 & ADC2 IN13
			measCase = 0;
			break;

		default:
			break;
		}
	}
}

/**
 * @brief Set Precision
 * 
 */
void cmSetPrecision(bool precision){
    if(precision){
        arraySize = ADC_NUMS_ACU;
    } else{
        arraySize = ADC_NUMS;
    }
}

/**
 * @brief Get selectet Wire
 * 
 * @param selection 
 */
void cmGetSelectetWire(int32_t selection){
    if(selection <= 2){
        selectetWire = selection;    
    }
}

/**
 * @brief 
 * 
 * @return true 
 */
bool cmMainsDetected(void){
    int32_t distance = 50;
    if(distance <= 100){
        return 1;
    } else{
        return 0;
    }
}

/**
 * @brief Get Standart Deviation
 * 
 */
int32_t cmGetStandartDeviation(void){
    return 57;
}

void cmSetDistanceLED(bool set){
    ExtLedSetDistance(true, 123);
}