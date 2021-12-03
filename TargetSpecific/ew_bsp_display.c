/*******************************************************************************
*
* E M B E D D E D   W I Z A R D   P R O J E C T
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This software is delivered "as is" and shows the usage of other software
* components. It is provided as an example software which is intended to be
* modified and extended according to particular requirements.
*
* TARA Systems hereby disclaims all warranties and conditions with regard to the
* software, including all implied warranties and conditions of merchantability
* and non-infringement of any third party IPR or other rights which may result
* from the use or the inability to use the software.
*
********************************************************************************
*
* DESCRIPTION:
*   This file is part of the interface (glue layer) between an Embedded Wizard
*   generated UI application and the board support package (BSP) of a dedicated
*   target.
*   Please note: The implementation of this module is partially based on
*   examples that are provided within the STM32 cube firmware. In case you want
*   to adapt this module to your custom specific hardware, please adapt the
*   hardware initialization code according your needs or integrate the generated
*   initialization code created by using the tool CubeMX.
*   This template is responsible to initialize the display hardware of the board
*   and to provide the necessary access to update the display content.
*   The color format of the framebuffer has to correspond to the color format
*   of the Graphics Engine.
*
*   Important: This file is intended to be used as a template. Please adapt the
*   implementation according your particular hardware.
*
*******************************************************************************/

#include "ewconfig.h"
#include "stm32f4xx_hal.h"
#include "stm32f429i_discovery.h"
#include "stm32f429i_discovery_io.h"
#include "../Components/ili9341/ili9341.h"

#include <string.h>

#include "ewrte.h"

#include "ew_bsp_display.h"
#include "ew_bsp_clock.h"

#if EW_USE_FREE_RTOS == 1

  #include "cmsis_os.h"

  static osSemaphoreId        LcdUpdateSemaphoreId = 0;

#endif

#define LAYER_INDEX           0

LTDC_HandleTypeDef            LtdcHandle;
LTDC_LayerCfgTypeDef          LayerConfig;

#if EW_USE_DOUBLE_BUFFER == 1

  static volatile uint32_t    CurrentFramebuffer = 0;
  static volatile uint32_t    PendingFramebuffer = 0;

#else

  static volatile int         CurrentLine = -1;
  static volatile int         PendingLine = -1;

#endif


/**
  * @brief LTDC MSP Initialization
  *        This function configures the hardware resources used in this example:
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration
  * @param hltdc: LTDC handle pointer
  * @retval None
  */
void HAL_LTDC_MspInit(LTDC_HandleTypeDef *hltdc)
{
  GPIO_InitTypeDef GPIO_InitStructure;

/*
*+------------------------+-----------------------+----------------------------+
*+                       LCD pins assignment                                   +
*+------------------------+-----------------------+----------------------------+
*|  LCD_TFT R2 <-> PC.10  |  LCD_TFT G2 <-> PA.06 |  LCD_TFT B2 <-> PD.06      |
*|  LCD_TFT R3 <-> PB.00  |  LCD_TFT G3 <-> PG.10 |  LCD_TFT B3 <-> PG.11      |
*|  LCD_TFT R4 <-> PA.11  |  LCD_TFT G4 <-> PB.10 |  LCD_TFT B4 <-> PG.12      |
*|  LCD_TFT R5 <-> PA.12  |  LCD_TFT G5 <-> PB.11 |  LCD_TFT B5 <-> PA.03      |
*|  LCD_TFT R6 <-> PB.01  |  LCD_TFT G6 <-> PC.07 |  LCD_TFT B6 <-> PB.08      |
*|  LCD_TFT R7 <-> PG.06  |  LCD_TFT G7 <-> PD.03 |  LCD_TFT B7 <-> PB.09      |
*-------------------------------------------------------------------------------
*         |  LCD_TFT HSYNC <-> PC.06  | LCDTFT VSYNC <->  PA.04 |
*         |  LCD_TFT CLK   <-> PG.07  | LCD_TFT DE   <->  PF.10 |
*          -----------------------------------------------------
*/

  /* Enable the LTDC and DMA2D Clock */
  __LTDC_CLK_ENABLE();
  __DMA2D_CLK_ENABLE();

  /* Enable GPIOs clock */
  __GPIOA_CLK_ENABLE();
  __GPIOB_CLK_ENABLE();
  __GPIOC_CLK_ENABLE();
  __GPIOD_CLK_ENABLE();
  __GPIOF_CLK_ENABLE();
  __GPIOG_CLK_ENABLE();

  /* GPIOA configuration */
  GPIO_InitStructure.Pin = GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_6 |
                           GPIO_PIN_11 | GPIO_PIN_12;
  GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStructure.Pull = GPIO_NOPULL;
  GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
  GPIO_InitStructure.Alternate= GPIO_AF14_LTDC;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);

 /* GPIOB configuration */
  GPIO_InitStructure.Pin = GPIO_PIN_8 | \
                           GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);

 /* GPIOC configuration */
  GPIO_InitStructure.Pin = GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_10;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStructure);

 /* GPIOD configuration */
  GPIO_InitStructure.Pin = GPIO_PIN_3 | GPIO_PIN_6;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);

 /* GPIOF configuration */
  GPIO_InitStructure.Pin = GPIO_PIN_10;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStructure);

 /* GPIOG configuration */
  GPIO_InitStructure.Pin = GPIO_PIN_6 | GPIO_PIN_7 | \
                           GPIO_PIN_11;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStructure);

  /* GPIOB configuration */
  GPIO_InitStructure.Pin = GPIO_PIN_0 | GPIO_PIN_1;
  GPIO_InitStructure.Alternate= GPIO_AF9_LTDC;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);

  /* GPIOG configuration */
  GPIO_InitStructure.Pin = GPIO_PIN_10 | GPIO_PIN_12;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStructure);

  /* Enable Interrupts for V-sync */
  HAL_NVIC_SetPriority( LTDC_IRQn, 8, 0 );
  HAL_NVIC_EnableIRQ( LTDC_IRQn );
}

/**
  * @brief LTDC MSP De-Initialization
  *        This function frees the hardware resources used in this example:
  *          - Disable the Peripheral's clock
  * @param hltdc: LTDC handle pointer
  * @retval None
  */
void HAL_LTDC_MspDeInit(LTDC_HandleTypeDef *hltdc)
{
  /*##-1- Reset peripherals ##################################################*/
  /* Enable LTDC reset state */
  __HAL_RCC_LTDC_FORCE_RESET();

  /* Release LTDC from reset state */
  __HAL_RCC_LTDC_RELEASE_RESET();
}

void LTDC_IRQHandler( void )
{
  HAL_LTDC_IRQHandler( &LtdcHandle );
}


void HAL_LTDC_LineEventCallback( LTDC_HandleTypeDef* aLtdc )
{
  #if EW_USE_DOUBLE_BUFFER == 1

    register uint32_t pendingBuffer = PendingFramebuffer;
    if ( CurrentFramebuffer != pendingBuffer )
    {
      /* change address within layer configuration structure */
      LayerConfig.FBStartAdress = pendingBuffer;

      /* change layer configuration */
      if ( HAL_LTDC_ConfigLayer( &LtdcHandle, &LayerConfig, LAYER_INDEX ) != HAL_OK )
        EwPrint( "HAL_LTDC_LineEventCallback: Could not change layer configuration!\n" );

      #if EW_USE_FREE_RTOS == 1

        osSemaphoreRelease( LcdUpdateSemaphoreId );

      #else

        /* save new address */
        CurrentFramebuffer = pendingBuffer;

      #endif
    }

    /* program next V-sync */
    HAL_LTDC_ProgramLineEvent( aLtdc, 0 );

  #else

    /* update current line number */
    CurrentLine = PendingLine;

    #if EW_USE_FREE_RTOS == 1

      osSemaphoreRelease( LcdUpdateSemaphoreId );

    #endif

  #endif
}


/* Helper function to sync on a certain line number updated by the display.
   This function is necessary when the system is used in single framebuffer mode. */
#if EW_USE_DOUBLE_BUFFER == 0
static void SyncOnLine( int aLine )
{
  /* either take line 0 or add the vertical back porch */
  if ( aLine <= 0 )
    aLine = 0;
  else
    aLine = aLine + LtdcHandle.Init.AccumulatedVBP;

  CurrentLine = -1;
  PendingLine = aLine;

  CPU_LOAD_SET_IDLE();

  /* program line number of next field */
  HAL_LTDC_ProgramLineEvent( &LtdcHandle, aLine );

  #if EW_USE_FREE_RTOS == 1

    osSemaphoreWait( LcdUpdateSemaphoreId, 1000 );

  #else

    while( aLine != CurrentLine )
      ;

  #endif

  CPU_LOAD_SET_ACTIVE();
}
#endif


/*******************************************************************************
* FUNCTION:
*   EwBspDisplayInit
*
* DESCRIPTION:
*   The function EwBspDisplayInit initializes the display hardware and returns
*   the display parameter.
*
* ARGUMENTS:
*   aGuiWidth,
*   aGuiHeight   - Size of the GUI in pixel.
*   aDisplayInfo - Display info data structure.
*
* RETURN VALUE:
*   Returns 1 if successful, 0 otherwise.
*
*******************************************************************************/
int EwBspDisplayInit( int aGuiWidth, int aGuiHeight, XDisplayInfo* aDisplayInfo )
{
  EW_UNUSED_ARG( aGuiWidth );
  EW_UNUSED_ARG( aGuiHeight );

  /* check and clean display info structure */
  if ( !aDisplayInfo )
    return 0;
  memset( aDisplayInfo, 0, sizeof( XDisplayInfo ));

  /* Initialization of ILI9341 component*/
  ili9341_Init();

  /* initialize given framebuffer */
  memset((void*)EW_FRAME_BUFFER_ADDR, 0, EW_FRAME_BUFFER_WIDTH * EW_FRAME_BUFFER_HEIGHT * EW_FRAME_BUFFER_DEPTH );

  #if EW_USE_FREE_RTOS == 1

    /* create the LCD update semaphore */
    osSemaphoreDef( LcdUpdateSemaphore );
    LcdUpdateSemaphoreId = osSemaphoreCreate( osSemaphore( LcdUpdateSemaphore ), 1 );

  #endif

  /* Polarity configuration */
  /* Initialize the horizontal synchronization polarity as active low */
  LtdcHandle.Init.HSPolarity = LTDC_HSPOLARITY_AL;
  /* Initialize the vertical synchronization polarity as active low */
  LtdcHandle.Init.VSPolarity = LTDC_VSPOLARITY_AL;
  /* Initialize the data enable polarity as active low */
  LtdcHandle.Init.DEPolarity = LTDC_DEPOLARITY_AL;
  /* Initialize the pixel clock polarity as input pixel clock */
  LtdcHandle.Init.PCPolarity = LTDC_PCPOLARITY_IPC;

  /* Timing configuration */
  /* Horizontal synchronization width = Hsync - 1 */
  LtdcHandle.Init.HorizontalSync = 9;
  /* Vertical synchronization height = Vsync - 1 */
  LtdcHandle.Init.VerticalSync = 1;
  /* Accumulated horizontal back porch = Hsync + HBP - 1 */
  LtdcHandle.Init.AccumulatedHBP = 29;
  /* Accumulated vertical back porch = Vsync + VBP - 1 */
  LtdcHandle.Init.AccumulatedVBP = 3;
  /* Accumulated active width = Hsync + HBP + Active Width - 1 */
  LtdcHandle.Init.AccumulatedActiveW = 269;
  /* Accumulated active height = Vsync + VBP + Active Heigh - 1 */
  LtdcHandle.Init.AccumulatedActiveH = 323;
  /* Total width = Hsync + HBP + Active Width + HFP - 1 */
  LtdcHandle.Init.TotalWidth = 279;
  /* Total height = Vsync + VBP + Active Heigh + VFP - 1 */
  LtdcHandle.Init.TotalHeigh = 327;


  /* Configure R,G,B component values for LCD background color */
  LtdcHandle.Init.Backcolor.Blue  = 0;
  LtdcHandle.Init.Backcolor.Green = 0;
  LtdcHandle.Init.Backcolor.Red   = 0;

  LtdcHandle.Instance = LTDC;

  /* Layer1 Configuration */
  LayerConfig.WindowX0 = 0;
  LayerConfig.WindowX1 = EW_FRAME_BUFFER_WIDTH;
  LayerConfig.WindowY0 = 0;
  LayerConfig.WindowY1 = EW_FRAME_BUFFER_HEIGHT;

  /* Pixel Format configuration: translate framebuffer color format into LTDC mode */
  #if ( EW_FRAME_BUFFER_COLOR_FORMAT == EW_FRAME_BUFFER_COLOR_FORMAT_RGBA8888 )
    LayerConfig.PixelFormat = LTDC_PIXEL_FORMAT_ARGB8888;
  #elif ( EW_FRAME_BUFFER_COLOR_FORMAT == EW_FRAME_BUFFER_COLOR_FORMAT_RGB888 )
    LayerConfig.PixelFormat = LTDC_PIXEL_FORMAT_RGB888;
  #elif ( EW_FRAME_BUFFER_COLOR_FORMAT == EW_FRAME_BUFFER_COLOR_FORMAT_RGBA4444 )
    LayerConfig.PixelFormat = LTDC_PIXEL_FORMAT_ARGB4444;
  #elif ( EW_FRAME_BUFFER_COLOR_FORMAT == EW_FRAME_BUFFER_COLOR_FORMAT_RGB565 )
    LayerConfig.PixelFormat = LTDC_PIXEL_FORMAT_RGB565;
  #elif ( EW_FRAME_BUFFER_COLOR_FORMAT == EW_FRAME_BUFFER_COLOR_FORMAT_Index8 )
    LayerConfig.PixelFormat = LTDC_PIXEL_FORMAT_L8;
  #elif ( EW_FRAME_BUFFER_COLOR_FORMAT == EW_FRAME_BUFFER_COLOR_FORMAT_LumA44 )
    LayerConfig.PixelFormat = LTDC_PIXEL_FORMAT_AL44;
  #endif

  /* Start Address will be set by Graphics Engine */
  LayerConfig.FBStartAdress = (uint32_t)EW_FRAME_BUFFER_ADDR;

  /* Alpha constant (255 totally opaque) */
  LayerConfig.Alpha = 255;

  /* Default Color configuration (configure A,R,G,B component values) */
  LayerConfig.Alpha0          = 0;
  LayerConfig.Backcolor.Blue  = 0;
  LayerConfig.Backcolor.Green = 0;
  LayerConfig.Backcolor.Red   = 0;

  /* Configure blending factors */
  LayerConfig.BlendingFactor1 = LTDC_BLENDING_FACTOR1_CA;
  LayerConfig.BlendingFactor2 = LTDC_BLENDING_FACTOR2_CA;

  /* Configure the number of lines and number of pixels per line */
  LayerConfig.ImageWidth  = EW_FRAME_BUFFER_WIDTH;
  LayerConfig.ImageHeight = EW_FRAME_BUFFER_HEIGHT;

  /* Configure the LTDC */
  if ( HAL_LTDC_Init( &LtdcHandle ) != HAL_OK )
    EwPrint( "EwBspDisplayInit: Could not configure LTDC!\n" );

  /* Configure the Layer */
  if ( HAL_LTDC_ConfigLayer( &LtdcHandle, &LayerConfig, LAYER_INDEX ) != HAL_OK )
    EwPrint( "EwBspDisplayInit: Could not configure layer!\n" );

  #if EW_USE_FREE_RTOS == 1

    /* initially take the LcdUpdate token for the first LCD update */
    osSemaphoreWait( LcdUpdateSemaphoreId , 1000 );

  #endif

  #if EW_USE_DOUBLE_BUFFER == 1

    /* Configure the vsync */
    if ( HAL_LTDC_ProgramLineEvent( &LtdcHandle, 0 ) != HAL_OK )
      EwPrint( "EwBspDisplayInit: Could not configure interrupt for vsync!\n" );

  #endif

  /* return the current display configuration */
  aDisplayInfo->FrameBuffer    = (void*)EW_FRAME_BUFFER_ADDR;
  aDisplayInfo->DoubleBuffer   = (void*)EW_DOUBLE_BUFFER_ADDR;
  aDisplayInfo->BufferWidth    = EW_FRAME_BUFFER_WIDTH;
  aDisplayInfo->BufferHeight   = EW_FRAME_BUFFER_HEIGHT;
  aDisplayInfo->DisplayWidth   = EW_DISPLAY_WIDTH;
  aDisplayInfo->DisplayHeight  = EW_DISPLAY_HEIGHT;

  #if EW_USE_DOUBLE_BUFFER == 1
    aDisplayInfo->UpdateMode   = EW_BSP_DISPLAY_UPDATE_NORMAL;
  #else
    aDisplayInfo->UpdateMode   = EW_BSP_DISPLAY_UPDATE_PARTIAL;
  #endif

  return 1;
}


/*******************************************************************************
* FUNCTION:
*   EwBspDisplayDone
*
* DESCRIPTION:
*   The function EwBspDisplayDone deinitializes the display hardware.
*
* ARGUMENTS:
*   aDisplayInfo - Display info data structure.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspDisplayDone( XDisplayInfo* aDisplayInfo )
{
  EW_UNUSED_ARG( aDisplayInfo );
}


/*******************************************************************************
* FUNCTION:
*   EwBspDisplayGetUpdateArea
*
* DESCRIPTION:
*   The function EwBspDisplayGetUpdateArea returns the next update area
*   depending on the selected display mode:
*   In case of a synchroneous single-buffer, the function has to return the
*   the rectangular areas that correspond to the horizontal stripes (fields)
*   of the framebuffer.
*   In case of a scratch-pad buffer, the function has to return the subareas
*   that fit into the provided update rectangle.
*   During each display update, this function is called until it returns 0.
*
* ARGUMENTS:
*   aUpdateRect - Rectangular area which should be updated (redrawn).
*
* RETURN VALUE:
*   Returns 1 if a further update area can be provided, 0 otherwise.
*
*******************************************************************************/
int EwBspDisplayGetUpdateArea( XRect* aUpdateRect )
{
  #if EW_USE_DOUBLE_BUFFER == 0

    static int field = 0;

    /* determine rectangular area of current field */
    #if EW_SURFACE_ROTATION == 0
      *aUpdateRect = EwNewRect( 0, field * EW_FRAME_BUFFER_HEIGHT / EW_NUMBER_OF_FIELDS,
        EW_FRAME_BUFFER_WIDTH, ( field + 1 ) * EW_FRAME_BUFFER_HEIGHT / EW_NUMBER_OF_FIELDS );
    #endif

    #if EW_SURFACE_ROTATION == 90
      *aUpdateRect = EwNewRect( field * EW_FRAME_BUFFER_HEIGHT / EW_NUMBER_OF_FIELDS, 0,
        ( field + 1 ) * EW_FRAME_BUFFER_HEIGHT / EW_NUMBER_OF_FIELDS, EW_FRAME_BUFFER_WIDTH );
    #endif

    #if EW_SURFACE_ROTATION == 180
      *aUpdateRect = EwNewRect( 0, EW_FRAME_BUFFER_HEIGHT - ( field + 1 ) * EW_FRAME_BUFFER_HEIGHT / EW_NUMBER_OF_FIELDS,
        EW_FRAME_BUFFER_WIDTH, EW_FRAME_BUFFER_HEIGHT - field * EW_FRAME_BUFFER_HEIGHT / EW_NUMBER_OF_FIELDS );
    #endif

    #if EW_SURFACE_ROTATION == 270
      *aUpdateRect = EwNewRect( EW_FRAME_BUFFER_HEIGHT - ( field + 1 ) * EW_FRAME_BUFFER_HEIGHT / EW_NUMBER_OF_FIELDS,
        0, EW_FRAME_BUFFER_HEIGHT - field * EW_FRAME_BUFFER_HEIGHT / EW_NUMBER_OF_FIELDS, EW_FRAME_BUFFER_WIDTH );
    #endif

    /* next field */
    field++;

    /* sync on start line of next field to ensure save drawing operation */
    SyncOnLine(( field % EW_NUMBER_OF_FIELDS ) * EW_FRAME_BUFFER_HEIGHT / EW_NUMBER_OF_FIELDS );

    if ( field <= EW_NUMBER_OF_FIELDS )
      return 1;

    field = 0;

  #endif

  return 0;
}


/*******************************************************************************
* FUNCTION:
*   EwBspDisplayWaitForCompletion
*
* DESCRIPTION:
*   The function EwBspDisplayWaitForCompletion is called from the Graphics Engine
*   to ensure that all pending activities of the display system are completed, so
*   that the rendering of the next frame can start.
*   In case of a double-buffering system, the function has to wait until the
*   V-sync has occured and the pending buffer is used by the display controller.
*   In case of an external display controller, the function has to wait until
*   the transfer (update) of the graphics data has been completed and there are
*   no pending buffers.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspDisplayWaitForCompletion( void )
{
  #if EW_USE_DOUBLE_BUFFER == 1

    register uint32_t pendingBuffer = PendingFramebuffer;
    if ( CurrentFramebuffer == pendingBuffer )
      return;

    CPU_LOAD_SET_IDLE();

    #if EW_USE_FREE_RTOS == 1

      /* wait until pending framebuffer is used as current framebuffer and
         use CPU time for other tasks */
      osSemaphoreWait( LcdUpdateSemaphoreId, 1000 );
      CurrentFramebuffer = pendingBuffer;

    #else

      /* wait until pending framebuffer is used as current framebuffer */
      while( CurrentFramebuffer != pendingBuffer )
        ;

    #endif

    CPU_LOAD_SET_ACTIVE();

  #endif
}


/*******************************************************************************
* FUNCTION:
*   EwBspDisplayCommitBuffer
*
* DESCRIPTION:
*   The function EwBspDisplayCommitBuffer is called from the Graphics Engine
*   when the rendering of a certain buffer has been completed.
*   The type of buffer depends on the selected framebuffer concept.
*   If the display is running in a double-buffering mode, the function is called
*   after each buffer update in order to change the currently active framebuffer
*   address. Changing the framebuffer address should be synchronized with V-sync.
*   If the system is using an external graphics controller, this function is
*   responsible to start the transfer of the framebuffer content.
*
* ARGUMENTS:
*   aAddress - Address of the framebuffer to be shown on the display.
*   aX,
*   aY       - Origin of the area which has been updated by the Graphics Engine.
*   aWidth,
*   aHeight  - Size of the area which has been updated by the Graphics Engine.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspDisplayCommitBuffer( void* aAddress, int aX, int aY, int aWidth, int aHeight )
{
  #if EW_USE_DOUBLE_BUFFER == 1

    /* set pending framebuffer address to be used on next V-sync */
    PendingFramebuffer = (uint32_t)aAddress;

  #endif
}


/*******************************************************************************
* FUNCTION:
*   EwBspDisplaySetClut
*
* DESCRIPTION:
*   The function EwBspDisplaySetClut is called from the Graphics Engine
*   in order to update the hardware CLUT of the current framebuffer.
*   The function is only called when the color format of the framebuffer is
*   Index8 or LumA44.
*
* ARGUMENTS:
*   aClut - Pointer to a color lookup table with 256 entries.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspDisplaySetClut( unsigned long* aClut )
{
  if ( HAL_LTDC_ConfigCLUT( &LtdcHandle, (uint32_t*)aClut, 256, LAYER_INDEX ) != HAL_OK )
    EwPrint( "EwBspDisplaySetClut: Could not configure layer CLUT!\n" );
  if ( HAL_LTDC_EnableCLUT( &LtdcHandle, LAYER_INDEX ) != HAL_OK )
    EwPrint( "EwBspDisplaySetClut: Could not enable layer CLUT!\n" );
}


/* msy */
