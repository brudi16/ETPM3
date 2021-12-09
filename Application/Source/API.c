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