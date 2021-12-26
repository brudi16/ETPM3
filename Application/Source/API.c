/** ***************************************************************************
 * @file API.c
 * @brief API functions for interacting with the Hardware
 *
 * This file contains the API and serves as an interface between the hardware functions and the Graphical User Interface.
 * @n
 *
 * @author  Yves Röhrig, roehryve@students.zhaw.ch
 * @date	25.12.2021
 *****************************************************************************/

/******************************************************************************
 * Includes
 *****************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "API.h"
#include "led.h"
#include "measuring.h"
#include "calculations.h"
#include "signalProcessing.h"
#include "LUT.h"
#include "stm32f4xx.h"
#include "stm32f429i_discovery.h"

/******************************************************************************
 * Variables
 *****************************************************************************/
uint8_t measCase = 0;
uint16_t arraySize = ADC_NUMS;
int32_t selectetWire = 1;

/******************************************************************************
 * Functions
 *****************************************************************************/

/** ***************************************************************************
 * @brief Initialisation call for all hardware functions
 * 
 * This funktion calls all initialisation funktion for the cabel monitor hardware.
 *
 *****************************************************************************/
void cmInitAll(void){
    // Function call of all initialisation functions...

    ExtLedInit(); // initialize all GPIOs for lamptest
    initLUT();
}

/** ***************************************************************************
 * @brief Current meassurement funktion
 * 
 * Get the calculated Currend.
 *
 * @return Currend in mA
 *****************************************************************************/
int32_t cmGetCurrent(void){
    // Function call of all required functions to return the current value...
    int32_t current = selectetWire; // This variable represense the meassured current in ampere
    return current;
}

/** ***************************************************************************
 * @brief Distance meassurement funktion
 * 
 * Get the calculated Distance.
 *
 * @return Distance in mm
 *****************************************************************************/
int32_t cmGetDistance(void){
    // Function call of all required functions to return the distance value...
    int32_t distance; // Distance in mm
	
		distance = getDistance(arraySize);
    return distance;
}

/** ***************************************************************************
 * @brief Angle meassurement funktion
 * 
 * Get the calculated Angle.
 *
 * @return Angle in grade
 *****************************************************************************/
int32_t cmGetAngle(void){
    // Function call of all required functions to return the angle value...
    int32_t angle; // Angle in degree
    angle = getAngle();
    return angle;
}

/** ***************************************************************************
 * @brief Debug funktion for the HALL1 Sensor
 * 
 * This function returns a debug value for testing purposes.
 *
 * @return Debug value for Hall1
 *****************************************************************************/
int32_t cmGetDebugHall1(void){
    // Function call of all required functions to return a debug value...
    int32_t hall = (int32_t)calc_peakToPeak_av(hall1Values, arraySize); // Debug hall value
    return hall;
}

/** ***************************************************************************
 * @brief Debug funktion for the HALL2 Sensor
 * 
 * This function returns a debug value for testing purposes.
 *
 * @return Debug value for Hall2
 *****************************************************************************/
int32_t cmGetDebugHall2(void){
    // Function call of all required functions to return a debug value...
    int32_t hall = (int32_t)calc_peakToPeak_av(hall2Values, arraySize); // Debug hall value
    return hall;
}

/** ***************************************************************************
 * @brief Debug funktion for PAD1
 * 
 * This function returns a debug value for testing purposes.
 *
 * @return Debug value for PAD1
 *****************************************************************************/
int32_t cmGetDebugPad1(void){
    // Function call of all required functions to return a debug value...
    int32_t pad = (int32_t)calc_peakToPeak_av(pad1Values, arraySize); // Debug pad value

    return pad;
}

/** ***************************************************************************
 * @brief Debug funktion for PAD2
 * 
 * This function returns a debug value for testing purposes.
 *
 * @return Debug value for PAD2
 *****************************************************************************/
int32_t cmGetDebugPad2(void){
    // Function call of all required functions to return a debug value...
    int32_t pad = (int32_t)calc_peakToPeak_av(pad2Values, arraySize); // Debug pad value
    return pad;
}

/** ***************************************************************************
 * @brief Test LED's off the cable monitor hardware
 * 
 * This function returns a debug value for testing purposes.
 * 
 * @param set Set and reset the Lamptest
 *
 *****************************************************************************/
void cmSetLampTest(bool set){
    ExtLedSetLamptest(set); // Switch all LEDs on
}

/** ***************************************************************************
 * @brief ADC initialisation
 * 
 * Initialisation of the ADC's to read analog values from the cable monitor hardware.
 *
 *****************************************************************************/
void adcInit(void){
    SystemClock_Config();				// Configure system clocks
    gyro_disable();						// Disable gyro, use those analog inputs
    MEAS_GPIO_analog_init();			// Configure GPIOs in analog mode
	MEAS_timer_init();					// Configure the timer
}

/** ***************************************************************************
 * @brief Performe analog measurement
 * 
 * This function prepares the ADCs and then starts the measurement.
 * Each ADC measurement is taken after the previous measurement is completed.
 * The results in the DMA's target array are copied before the calculation
 * functions change them.
 *
 *****************************************************************************/
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
			measCase = 3;
			break;
     case 3:
      cpyArrays(arraySize);
      measCase = 0;
			removeDC(arraySize);
			break;
		default:
			break;
		}
	}
}

/** ***************************************************************************
 * @brief Set Precision
 * 
 * Switch between to differend ADC sample lenght.
 * 
 * @param precision Set if more samples needed
 *
 *****************************************************************************/
void cmSetPrecision(bool precision){
    if(precision){
        arraySize = ADC_NUMS_ACU;
    } else{
        arraySize = ADC_NUMS;
    }
}

/** ***************************************************************************
 * @brief Get selectet Wire
 * 
 * A global variable is overwritten with the transfer value of the function.
 * 
 * @param selection Represents the set wire arrangement in the cable to be measured. 
 *
 *****************************************************************************/
void cmGetSelectetWire(int32_t selection){
    if(selection <= 2){
        selectetWire = selection;    
    }
}

/** ***************************************************************************
 * @brief Mains Detected
 * 
 * The ADC value of the pads is compared with a set reference value and if this
 * value is exceeded or not reached, the return value is changed.
 * 
 * @return True if a mains cable is detected 
 *
 *****************************************************************************/
bool cmMainsDetected(void){
    int32_t distance = cmGetDebugPad1();
    if(distance <= 100){
        return 0;
    } else{
        return 1;
    }
}

/** ***************************************************************************
 * @brief Standart Deviation
 * 
 * This function returns the standard deviation in mm.
 * 
 * @return Standart deviation in mm 
 *
 *****************************************************************************/
int32_t cmGetStandartDeviation(void){
    return 57;
}

/** ***************************************************************************
 * @brief Enable Distance LED
 * 
 * @param set Turn on and off the Distance LED's. 
 *
 *****************************************************************************/
void cmSetDistanceLED(bool set){
    ExtLedSetDistance(true, 123);
}