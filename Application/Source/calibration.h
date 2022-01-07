/** ***************************************************************************
 * @file
 * @brief see calibration.c
 * 
 * 
 * @note This file is prepared for later functions regarding calibration
 * @author  Pavel Müller, Yves Röhrig
 * @date	25.12.2021
 *****************************************************************************/

/******************************************************************************
 * Includes
 *****************************************************************************/

/******************************************************************************
 * Defines
 *****************************************************************************/
#define NUM_CALB_POINTS 7		///< Number of points in calibration process
/******************************************************************************
 * Variables
 *****************************************************************************/

/******************************************************************************
 * Functions
 *****************************************************************************/
void setCalPnt(int32_t arrayNum, int32_t pointNum, int32_t value);
void calibrateSingleValue(int32_t type,int32_t pointNum);
void calibration(int32_t type);