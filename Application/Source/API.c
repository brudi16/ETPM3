/** ***************************************************************************
 * @file API.c
 * @brief API functions for interacting with the Hardware
 *
 * Cable Monitor Application Programm Interface
 * ============================================
 * 
 * This file contains the API and serves as an interface between the hardware 
 * functions and the Graphical User Interface.
 * 
 * @warning It is important to note that called functions do not have integrated
 * waiting times. Otherwise, the user interface is only updated sporadically
 * and usability is affected.
 *
 * @authors Pavel Müller, Röhrig Yves
 * @date 25.12.2021
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
#include "calibration.h"
#include "stm32f4xx.h"
#include "stm32f429i_discovery.h"

/******************************************************************************
 * Variables
 *****************************************************************************/
uint8_t measCase = 0;               ///< Value of the actual measuring Case
uint16_t arraySize = ADC_NUMS;      ///< Value of the actual numbers of measuring values
int32_t selectetWire = 1;           ///< Number of wires that are measured
bool calibrationOn = false;

/******************************************************************************
 * Functions
 *****************************************************************************/

/** ***************************************************************************
 * @brief Initialisation functions
 * 
 * This function is used to call all initialisation functions in one.
 *
 *****************************************************************************/
void cmInitAll(void){
    // Function call of all initialisation functions...

    ExtLedInit(); // initialize all GPIOs for lamptest
    initLUT();
}

/** ***************************************************************************
 * @brief Current meassurement funktion
 * @return Currend in mA
 * 
 * When this function is called, the current measured el. current is returned in mA.
 *
 *****************************************************************************/
int32_t cmGetCurrent(void){
    // Function call of all required functions to return the current value...
    int32_t current = selectetWire; // This variable represense the meassured current in ampere
    return current;
}

/** ***************************************************************************
 * @brief Distance meassurement funktion
 * @return Distance in mm
 * 
 * When this function is called, the current measured distance in mm is returned.
 *
 *****************************************************************************/
int32_t cmGetDistance(void){
    // Function call of all required functions to return the distance value...
    int32_t distance; // Distance in mm
	distance = getDistance(arraySize);
    return distance;
}

/** ***************************************************************************
 * @brief Angle meassurement funktion
 * @return Angle in grade
 * 
 * When this function is called, the current measured angle is returned in degrees.
 *
 *****************************************************************************/
int32_t cmGetAngle(void){
    // Function call of all required functions to return the angle value...
    int32_t angle; // Angle in degree
    angle = getAngle();
    return angle;
}

/** ***************************************************************************
 * @brief Debug funktion for the HALL1 Sensor
 * @return Debug value for Hall1
 * 
 * This function returns a debug value for testing purposes.
 *
 *****************************************************************************/
int32_t cmGetDebugHall1(void){
    // Function call of all required functions to return a debug value...
    int32_t hall = (int32_t)calc_peakToPeak_av(hall1Values, arraySize, peakToPeakArrayHall1); // Debug hall value
    return hall;
}

/** ***************************************************************************
 * @brief Debug funktion for the HALL2 Sensor
 * @return Debug value for Hall2
 * 
 * This function returns a debug value for testing purposes.
 *
 *****************************************************************************/
int32_t cmGetDebugHall2(void){
    // Function call of all required functions to return a debug value...
    int32_t hall = (int32_t)calc_peakToPeak_av(hall2Values, arraySize, peakToPeakArrayHall2); // Debug hall value
    return hall;
}

/** ***************************************************************************
 * @brief Debug funktion for PAD1
 * @return Debug value for PAD1
 * 
 * This function returns a debug value for testing purposes.
 *
 *****************************************************************************/
int32_t cmGetDebugPad1(void){
    // Function call of all required functions to return a debug value...
    int32_t pad = (int32_t)calc_peakToPeak_av(pad1Values, arraySize, peakToPeakArrayPad1); // Debug pad value

    return pad;
}

/** ***************************************************************************
 * @brief Debug funktion for PAD2
 * @return Debug value for PAD2
 * 
 * This function returns a debug value for testing purposes.
 *
 *****************************************************************************/
int32_t cmGetDebugPad2(void){
    // Function call of all required functions to return a debug value...
    int32_t pad = (int32_t)calc_peakToPeak_av(pad2Values, arraySize, peakToPeakArrayPad2); // Debug pad value
    return pad;
}

/** ***************************************************************************
 * @brief Test all LED's of the cable monitor hardware
 * @param set Set and reset the lamptest
 * 
 * This function controls the lamptest
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
			removeDC(arraySize);
			//filter_hall();
			measCase = 0;
			break;
		default:
			break;
		}
	}
}

/** ***************************************************************************
 * @brief Set Precision
 * @param precision Set if more samples needed
 * 
 * Switch between to differend ADC sample lenght.
 *
 *****************************************************************************/
void cmSetPrecision(bool precision){
    if((precision) || (calibrationOn)){
        arraySize = ADC_NUMS_ACU;
    } else{
        arraySize = ADC_NUMS;
    }
}

/** ***************************************************************************
 * @brief Get selectet Wire
 * @param selection Represents the set wire arrangement in the cable to be measured.
 * 
 * A global variable is overwritten with the transfer value of the function. 
 *
 *****************************************************************************/
void cmGetSelectetWire(int32_t selection){
    if(selection <= 2){
        selectetWire = selection;    
    }
}

/** ***************************************************************************
 * @brief Mains Detected
 * @return True if a mains cable is detected
 * 
 * The ADC value of the pads is compared with a set reference value and if this
 * value is exceeded or not reached, the return value is changed. 
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
 * @return Standart deviation in mm
 * 
 * This function returns the standard deviation in mm. 
 *
 *****************************************************************************/
int32_t cmGetStandartDeviation(void){
    int32_t stdDev = 0;
    stdDev = (int32_t)calcStdDev(peakToPeakArrayPad1,peakToPeakArrayPad2, arraySize);
    return stdDev;
}

/** ***************************************************************************
 * @brief Enable Distance LED
 * @param set Turn on and off the Distance LED's. 
 *
 *****************************************************************************/
void cmSetDistanceLED(bool set){
    ExtLedSetDistance(true, getDistance(arraySize));
}

/** ***************************************************************************
 * @brief Enable run LED 
 *
 *****************************************************************************/
void cmRunLED(void){
    ExtLetRun();
}

/** ***************************************************************************
 * @brief Enable overload LED
 *
 *****************************************************************************/
void cmOlLed(void){
    ExtLedOl(1, ADC_PAD1_samples, ADC_PAD2_samples, arraySize, 15);
    ExtLedOl(2, ADC_HALL1_samples, ADC_HALL2_samples, arraySize, 15);
}


/** ***************************************************************************
 * @brief set value to calibration array
 * 
 * @param[in] setArray 
 * @param[in] setPosition 
 *****************************************************************************/
void cmSetCalibrationValue(int32_t setArray, int32_t setPosition){
    calibrateSingleValue(setArray,setPosition);
}

/** ***************************************************************************
 * @brief Set calibration on
 * @param on Set during the calibration process
 * 
 * Set the calibrationOn variable true during the calibration process.
 *
 *****************************************************************************/
void cmSetCalibrationOn(bool on){
    calibrationOn = on;
}

/** ***************************************************************************
 * @brief Save calibration
 * 
 * Calculate the calibration values.
 *
 *****************************************************************************/
void cmSaveCalibration(void){
    calibration();
}

/** ***************************************************************************
 * @brief Reset calibration
 * 
 * Reset the calibration values.
 *
 *****************************************************************************/
void cmResetCalibration(void){
    initLUT();
}

/** ***************************************************************************
 * @brief Display peak to peapk avarage of both pads
 * @return Peak to peak avarage of both pads
 * 
 * This function returns the avarage peak to peak value of both pads.
 *
 *****************************************************************************/
int32_t cmGetPadPeakToPeak(void){
    // Function call of all required functions to return a debug value...
    int32_t padPeakToPeak = 0;

    padPeakToPeak = (int32_t)peakToPeakPadAv;

    return padPeakToPeak;
}

/** ***************************************************************************
 * @brief Display peak to peapk avarage of both hall sensors
 * @return Peak to peak avarage of both hall sensors
 * 
 * This function returns the avarage peak to peak value of both hall sensors.
 *
 *****************************************************************************/
int32_t cmGetHallPeakToPeak(void){
    // Function call of all required functions to return a debug value...
    int32_t hallPeakToPeak = 55;
    return hallPeakToPeak;
}