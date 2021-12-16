/** ***************************************************************************
 * @file
 * @brief See measuring.c
 *
 * Prefixes MEAS, ADC, DAC
 *
 *****************************************************************************/

#ifndef MEAS_H_
#define MEAS_H_


/******************************************************************************
 * Includes
 *****************************************************************************/
#include <stdbool.h>


/******************************************************************************
 * Defines
 *****************************************************************************/
extern bool MEAS_data_ready;
extern bool DAC_active;

#define ADC_NUMS		240			    ///< Number of samples for standart measurement
#define ADC_NUMS_ACU	(4*ADC_NUMS)	///< Number of samples for acurate measurement
#define ADC_DAC_RES		12			    ///< Resolution
#define ADC_FS			600			    ///< Sampling freq. => 12 samples for a 50Hz period
#define ADC_CLOCK		84000000	    ///< APB2 peripheral clock frequency
#define ADC_CLOCKS_PS	15			    ///< Clocks/sample: 3 hold + 12 conversion
#define TIM_CLOCK		84000000	    ///< APB1 timer clock frequency
#define TIM_TOP			9			    ///< Timer top value
#define TIM_PRESCALE	(TIM_CLOCK/ADC_FS/(TIM_TOP+1)-1) ///< Clock prescaler

extern int32_t ADC_PAD1_samples[ADC_NUMS_ACU];
extern int32_t ADC_PAD2_samples[ADC_NUMS_ACU];
extern int32_t ADC_HALL1_samples[ADC_NUMS_ACU];
extern int32_t ADC_HALL2_samples[ADC_NUMS_ACU];

/******************************************************************************
 * Functions
 *****************************************************************************/
void gyro_disable(void);
void SystemClock_Config(void);
void MEAS_GPIO_analog_init(void);
void MEAS_timer_init(void);
void ADC_reset(void);
void ADC3_IN4_DMA_init(void);
void ADC3_IN4_DMA_start(void);
void ADC3_IN6_DMA_init(void);
void ADC3_IN6_DMA_start(void);
void ADC1_IN11_ADC2_IN11_dual_init(void);
void ADC1_IN11_ADC2_IN11_dual_start(void);

#endif
