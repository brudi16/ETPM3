/** ***************************************************************************
 * @file
 * @brief Measuring voltages with the ADC(s) in different configurations
 *
 *
 * Demonstrates different ADC (Analog to Digital Converter) modes
 * ==============================================================
 *
 * - ADC in single conversion mode
 * - ADC triggered by a timer and with interrupt after end of conversion
 * - ADC combined with DMA (Direct Memory Access) to fill a buffer
 * - Dual mode = simultaneous sampling of two inputs by two ADCs
 * - Scan mode = sequential sampling of two inputs by one ADC
 * - Analog mode configuration for GPIOs
 * - Display recorded data on the graphics display
 *
 * Peripherals @ref HowTo
 *
 * @image html demo_screenshot_board.jpg
 *
 *
 * HW used for the demonstrations
 * ==============================
 * A simple HW was used for testing the code.
 * It is connected to the pins marked in red in the above image.
 *
 * @image html demo_board_schematic.png
 *
 * Of course the code runs also without this HW.
 * Simply connect a signal or waveform generator to the input(s).
 *
 *
 * @anchor HowTo
 * How to Configure the Peripherals: ADC, TIMER and DMA
 * ====================================================
 *
 * All the peripherals are accessed by writing to or reading from registers.
 * From the programmer’s point of view this is done exactly as
 * writing or reading the value of a variable.
 * @n Writing to a register configures the HW of the associated peripheral
 * to do what is required.
 * @n Reading from a registers gets status and data from the HW peripheral.
 *
 * The information on which bits have to be set to get a specific behavior
 * is documented in the <b>reference manual</b> of the mikrocontroller.
 *
 *
 * ----------------------------------------------------------------------------
 * @author Hanspeter Hochreutener, hhrt@zhaw.ch
 * @date 17.06.2021
 *****************************************************************************/


/******************************************************************************
 * Includes
 *****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx.h"
#include "stm32f429xx.h"
#include "stm32f429i_discovery.h"
#include "stm32f429i_discovery_ts.h"

#include "measuring.h"


/******************************************************************************
 * Variables
 *****************************************************************************/

bool MEAS_data_ready = true;			///< New data is ready

//static uint32_t ADC_sample_count = 0;	///< Index for buffer
int32_t ADC_PAD1_samples[ADC_NUMS_ACU];
int32_t ADC_PAD2_samples[ADC_NUMS_ACU];
int32_t ADC_PAD_samples[ADC_NUMS_ACU];
int32_t ADC_HALL1_samples[ADC_NUMS_ACU];
int32_t ADC_HALL2_samples[ADC_NUMS_ACU];



/******************************************************************************
 * Functions
 *****************************************************************************/


void gyro_disable(void)
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

void SystemClock_Config(void){
	/* Set clock prescaler for ADCs */
	ADC->CCR |= ADC_CCR_ADCPRE_0;
}

/** ***************************************************************************
 * @brief Configure GPIOs in analog mode.
 *
 * @note The input number for the ADCs is not equal to the GPIO pin number!
 * - ADC3_IN4 = GPIO PF6 (HALL Sensor 1)
 * - ADC3_IN6 = GPIO PF8 (HALL Sensor 2)
 * - ADC123_IN11 = GPIO PC1 (PAD 1)
 * - ADC123_IN13 = GPIO PC3 (PAD 2)
 *****************************************************************************/
void MEAS_GPIO_analog_init(void){
	__HAL_RCC_GPIOF_CLK_ENABLE();				// Enable Clock for GPIO port F
	GPIOF->MODER |= (GPIO_MODER_MODER6_Msk);	// Analog mode for PF6 = ADC3_IN4
	GPIOF->MODER |= (GPIO_MODER_MODER8_Msk);	// Analog mode for PF8 = ADC3_IN6
	__HAL_RCC_GPIOC_CLK_ENABLE();				// Enable Clock for GPIO port C
	GPIOC->MODER |= (GPIO_MODER_MODER1_Msk);	// Analog mode for PC1 = ADC123_IN11
	GPIOC->MODER |= (GPIO_MODER_MODER3_Msk);	// Analog mode for PC3 = ADC123_IN13
}



/** ***************************************************************************
 * @brief Resets the ADCs and the timer
 *
 * to make sure the different demos do not interfere.
 *****************************************************************************/
void ADC_reset(void) {
	RCC->APB2RSTR |= RCC_APB2RSTR_ADCRST;	// Reset ADCs
	RCC->APB2RSTR &= ~RCC_APB2RSTR_ADCRST;	// Release reset of ADCs
	TIM2->CR1 &= ~TIM_CR1_CEN;				// Disable timer
}


/** ***************************************************************************
 * @brief Configure the timer to trigger the ADC(s)
 *
 * @note For debugging purposes the timer interrupt might be useful.
 *****************************************************************************/
void MEAS_timer_init(void)
{
	__HAL_RCC_TIM2_CLK_ENABLE();		// Enable Clock for TIM2
	TIM2->PSC = TIM_PRESCALE;			// Prescaler for clock freq. = 1MHz
	TIM2->ARR = TIM_TOP;				// Auto reload = counter top value
	TIM2->CR2 |= TIM_CR2_MMS_1; 		// TRGO on update
}


/** ***************************************************************************
 * @brief Initialize ADC, timer and DMA for data acquisition in the background
 *
 * Uses ADC3 and DMA2_Stream1 Channel2
 * @n The ADC3 trigger is set to TIM2 TRGO event
 * and the timer starts the ADC directly without CPU intervention.
 * @ The ADC3 triggers the DMA2_Stream1 to transfer the new data directly
 * to memory without CPU intervention.
 * @n The DMA triggers the transfer complete interrupt when all data is ready.
 * @n The input is ADC3_IN4 = GPIO PF6
 *****************************************************************************/
void ADC3_IN4_DMA_init(uint8_t arraySize)
{
	MEAS_data_ready = false;
	__HAL_RCC_ADC3_CLK_ENABLE();					// Enable Clock for ADC3
	ADC3->SQR3 |= (4UL << ADC_SQR3_SQ1_Pos);		// Input 4 = first conversion
	ADC3->CR2 |= (1UL << ADC_CR2_EXTEN_Pos);		// En. ext. trigger on rising e.
	ADC3->CR2 |= (6UL << ADC_CR2_EXTSEL_Pos);		// Timer 2 TRGO event
	ADC3->CR2 |= ADC_CR2_DMA;						// Enable DMA mode
	__HAL_RCC_DMA2_CLK_ENABLE();					// Enable Clock for DMA2
	DMA2_Stream1->CR &= ~DMA_SxCR_EN;				// Disable the DMA stream 1
	while (DMA2_Stream1->CR & DMA_SxCR_EN) { ; }	// Wait for DMA to finish
	DMA2->LIFCR |= DMA_LIFCR_CTCIF1;				// Clear transfer complete interrupt fl.
	DMA2_Stream1->CR |= (2UL << DMA_SxCR_CHSEL_Pos);// Select channel 2
	DMA2_Stream1->CR |= DMA_SxCR_PL_1;				// Priority high
	DMA2_Stream1->CR |= DMA_SxCR_MSIZE_1;			// Memory data size = 32 bit
	DMA2_Stream1->CR |= DMA_SxCR_PSIZE_1;			// Peripheral data size = 32 bit
	DMA2_Stream1->CR |= DMA_SxCR_MINC;				// Increment memory address pointer
	DMA2_Stream1->CR |= DMA_SxCR_TCIE;				// Transfer complete interrupt enable
	DMA2_Stream1->NDTR = arraySize;					// Number of data items to transfer
	DMA2_Stream1->PAR = (uint32_t)&ADC3->DR;		// Peripheral register address
	DMA2_Stream1->M0AR = (int32_t)ADC_HALL1_samples;	// Buffer memory loc. address
}


/** ***************************************************************************
 * @brief Start DMA, ADC and timer
 *
 *****************************************************************************/
void ADC3_IN4_DMA_start(void)
{
	DMA2_Stream1->CR |= DMA_SxCR_EN;	// Enable DMA
	NVIC_ClearPendingIRQ(DMA2_Stream1_IRQn);	// Clear pending DMA interrupt
	NVIC_EnableIRQ(DMA2_Stream1_IRQn);	// Enable DMA interrupt in the NVIC
	ADC3->CR2 |= ADC_CR2_ADON;			// Enable ADC3
	TIM2->CR1 |= TIM_CR1_CEN;			// Enable timer
}



/** ***************************************************************************
 * @brief Initialize ADC, timer and DMA for data acquisition in the background
 *
 * Uses ADC3 and DMA2_Stream1 Channel2
 * @n The ADC3 trigger is set to TIM2 TRGO event
 * and the timer starts the ADC directly without CPU intervention.
 * @ The ADC3 triggers the DMA2_Stream1 to transfer the new data directly
 * to memory without CPU intervention.
 * @n The DMA triggers the transfer complete interrupt when all data is ready.
 * @n The input is ADC3_IN4 = GPIO PF6
 *****************************************************************************/
void ADC3_IN6_DMA_init(uint8_t arraySize)
{
	MEAS_data_ready = false;
	__HAL_RCC_ADC3_CLK_ENABLE();					// Enable Clock for ADC3
	ADC3->SQR3 |= (6UL << ADC_SQR3_SQ1_Pos);		// Input 4 = first conversion
	ADC3->CR2 |= (1UL << ADC_CR2_EXTEN_Pos);		// En. ext. trigger on rising e.
	ADC3->CR2 |= (6UL << ADC_CR2_EXTSEL_Pos);		// Timer 2 TRGO event
	ADC3->CR2 |= ADC_CR2_DMA;						// Enable DMA mode
	__HAL_RCC_DMA2_CLK_ENABLE();					// Enable Clock for DMA2
	DMA2_Stream1->CR &= ~DMA_SxCR_EN;				// Disable the DMA stream 1
	while (DMA2_Stream1->CR & DMA_SxCR_EN) { ; }	// Wait for DMA to finish
	DMA2->LIFCR |= DMA_LIFCR_CTCIF1;				// Clear transfer complete interrupt fl.
	DMA2_Stream1->CR |= (2UL << DMA_SxCR_CHSEL_Pos);// Select channel 2
	DMA2_Stream1->CR |= DMA_SxCR_PL_1;				// Priority high
	DMA2_Stream1->CR |= DMA_SxCR_MSIZE_1;			// Memory data size = 32 bit
	DMA2_Stream1->CR |= DMA_SxCR_PSIZE_1;			// Peripheral data size = 32 bit
	DMA2_Stream1->CR |= DMA_SxCR_MINC;				// Increment memory address pointer
	DMA2_Stream1->CR |= DMA_SxCR_TCIE;				// Transfer complete interrupt enable
	DMA2_Stream1->NDTR = arraySize;					// Number of data items to transfer
	DMA2_Stream1->PAR = (uint32_t)&ADC3->DR;		// Peripheral register address
	DMA2_Stream1->M0AR = (int32_t)ADC_HALL2_samples;	// Buffer memory loc. address
}


/** ***************************************************************************
 * @brief Start DMA, ADC and timer
 *
 *****************************************************************************/
void ADC3_IN6_DMA_start(void)
{
	DMA2_Stream1->CR |= DMA_SxCR_EN;	// Enable DMA
	NVIC_ClearPendingIRQ(DMA2_Stream1_IRQn);	// Clear pending DMA interrupt
	NVIC_EnableIRQ(DMA2_Stream1_IRQn);	// Enable DMA interrupt in the NVIC
	ADC3->CR2 |= ADC_CR2_ADON;			// Enable ADC3
	TIM2->CR1 |= TIM_CR1_CEN;			// Enable timer
}


/** ***************************************************************************
 * @brief Initialize ADCs, timer and DMA for simultaneous dual ADC acquisition
 *
 * Uses ADC1 and ADC2 in dual mode and DMA2_Stream4 Channel0
 * @n The ADC1 trigger is set to TIM2 TRGO event
 * @n ADC1 is the master and simultaneously triggers ADC2.
 * @n Both converted data from ADC1 and ADC2 are packed into a 32-bit register
 * in this way: <b> ADC_CDR[31:0] = ADC2_DR[15:0] | ADC1_DR[15:0] </b>
 * and are transfered with the DMA in one single step.
 * @n The ADC1 triggers the DMA2_Stream4 to transfer the new data directly
 * to memory without CPU intervention.
 * @n The DMA triggers the transfer complete interrupt when all data is ready.
 * @n The input used with ADC1 is ADC123_IN13 = GPIO PC3
 * @n The input used with ADC2 is ADC12_IN5 = GPIO PA5
 *****************************************************************************/
void ADC1_IN11_ADC2_IN13_dual_init(uint8_t arraySize)
{
	MEAS_data_ready = false;
	__HAL_RCC_ADC1_CLK_ENABLE();		// Enable Clock for ADC1
	__HAL_RCC_ADC2_CLK_ENABLE();		// Enable Clock for ADC2
	ADC->CCR |= ADC_CCR_DMA_1;			// Enable DMA mode 2 = dual DMA
	ADC->CCR |= ADC_CCR_MULTI_1 | ADC_CCR_MULTI_2; // ADC1 and ADC2
	ADC1->CR2 |= (1UL << ADC_CR2_EXTEN_Pos);	// En. ext. trigger on rising e.
	ADC1->CR2 |= (6UL << ADC_CR2_EXTSEL_Pos);	// Timer 2 TRGO event
	ADC1->SQR3 |= (11UL << ADC_SQR3_SQ1_Pos);	// Input 11 = first conversion
	ADC2->SQR3 |= (13UL << ADC_SQR3_SQ1_Pos);	// Input 13 = first conversion
	__HAL_RCC_DMA2_CLK_ENABLE();		// Enable Clock for DMA2
	DMA2_Stream4->CR &= ~DMA_SxCR_EN;	// Disable the DMA stream 4
	while (DMA2_Stream4->CR & DMA_SxCR_EN) { ; }	// Wait for DMA to finish
	DMA2->HIFCR |= DMA_HIFCR_CTCIF4;	// Clear transfer complete interrupt fl.
	DMA2_Stream4->CR |= (0UL << DMA_SxCR_CHSEL_Pos);	// Select channel 0
	DMA2_Stream4->CR |= DMA_SxCR_PL_1;		// Priority high
	DMA2_Stream4->CR |= DMA_SxCR_MSIZE_1;	// Memory data size = 32 bit
	DMA2_Stream4->CR |= DMA_SxCR_PSIZE_1;	// Peripheral data size = 32 bit
	DMA2_Stream4->CR |= DMA_SxCR_MINC;	// Increment memory address pointer
	DMA2_Stream4->CR |= DMA_SxCR_TCIE;	// Transfer complete interrupt enable
	DMA2_Stream4->NDTR = arraySize;		// Number of data items to transfer
	DMA2_Stream4->PAR = (uint32_t)&ADC->CDR;	// Peripheral register address
	DMA2_Stream4->M0AR = (int32_t)ADC_PAD_samples;	// Buffer memory loc. address
}

/** ***************************************************************************
 * @brief Start DMA, ADC and timer
 *
 *****************************************************************************/

void ADC1_IN11_ADC2_IN13_dual_start(void)
{
	DMA2_Stream4->CR |= DMA_SxCR_EN;	// Enable DMA
	NVIC_ClearPendingIRQ(DMA2_Stream4_IRQn);	// Clear pending DMA interrupt
	NVIC_EnableIRQ(DMA2_Stream4_IRQn);	// Enable DMA interrupt in the NVIC
	ADC1->CR2 |= ADC_CR2_ADON;			// Enable ADC1
	ADC2->CR2 |= ADC_CR2_ADON;			// Enable ADC3
	TIM2->CR1 |= TIM_CR1_CEN;			// Enable timer
}


/** ***************************************************************************
 * @brief Interrupt handler for DMA2 Stream1
 *
 * The samples from the ADC3 have been transfered to memory by the DMA2 Stream1
 * and are ready for processing.
 *****************************************************************************/
void DMA2_Stream1_IRQHandler(void)
{
	if (DMA2->LISR & DMA_LISR_TCIF1) {					// Stream1 transfer compl. interrupt f.
		NVIC_DisableIRQ(DMA2_Stream1_IRQn);				// Disable DMA interrupt in the NVIC
		NVIC_ClearPendingIRQ(DMA2_Stream1_IRQn);		// Clear pending DMA interrupt
		DMA2_Stream1->CR &= ~DMA_SxCR_EN;				// Disable the DMA
		while (DMA2_Stream1->CR & DMA_SxCR_EN) { ; }	// Wait for DMA to finish
		DMA2->LIFCR |= DMA_LIFCR_CTCIF1;				// Clear transfer complete interrupt fl.
		TIM2->CR1 &= ~TIM_CR1_CEN;						// Disable timer
		ADC3->CR2 &= ~ADC_CR2_ADON;						// Disable ADC3
		ADC3->CR2 &= ~ADC_CR2_DMA;						// Disable DMA mode
		ADC_reset();
		MEAS_data_ready = true;
	}
}


/** ***************************************************************************
 * @brief Interrupt handler for DMA2 Stream4
 *
 * Here the interrupt handler is used together with ADC1 and ADC2
 * in dual mode where they sample simultaneously.
 * @n The samples from both ADCs packed in a 32 bit word have been transfered
 * to memory by the DMA2 and are ready for unpacking.
 * @note In dual ADC mode two values are combined (packed) in a single uint32_t
 * ADC_CDR[31:0] = ADC2_DR[15:0] | ADC1_DR[15:0]
 * and are therefore extracted before further processing.
 *****************************************************************************/
void DMA2_Stream4_IRQHandler(void)
{
	if (DMA2->HISR & DMA_HISR_TCIF4) {	// Stream4 transfer compl. interrupt f.
		NVIC_DisableIRQ(DMA2_Stream4_IRQn);	// Disable DMA interrupt in the NVIC
		NVIC_ClearPendingIRQ(DMA2_Stream4_IRQn);// Clear pending DMA interrupt
		DMA2_Stream4->CR &= ~DMA_SxCR_EN;	// Disable the DMA
		while (DMA2_Stream4->CR & DMA_SxCR_EN) { ; }	// Wait for DMA to finish
		DMA2->HIFCR |= DMA_HIFCR_CTCIF4;// Clear transfer complete interrupt fl.
		TIM2->CR1 &= ~TIM_CR1_CEN;		// Disable timer
		ADC1->CR2 &= ~ADC_CR2_ADON;		// Disable ADC1
		ADC2->CR2 &= ~ADC_CR2_ADON;		// Disable ADC2
		ADC->CCR &= ~ADC_CCR_DMA_1;		// Disable DMA mode
		/* Extract combined samples */
		for (int32_t i = ADC_NUMS_ACU-1; i >= 0; i--){
			ADC_PAD1_samples[i] = (ADC_PAD_samples[i] >> 16);
			ADC_PAD2_samples[i]   = (ADC_PAD_samples[i] & 0xffff);
		}
		ADC_reset();
		MEAS_data_ready = true;
	}
}
