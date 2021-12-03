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
*   This template is responsible to initialize the touch driver of the display
*   hardware and to receive the touch events for the UI application.
*   Important: This file is intended to be used as a template. Please adapt the
*   implementation according your particular hardware.
*
*******************************************************************************/

#include "ewconfig.h"
#include "string.h"
#include "stm32f4xx_hal.h"
#include "stm32f429i_discovery.h"
#include "stm32f429i_discovery_ts.h"

#include "ewrte.h"

#include "ew_bsp_clock.h"
#include "ew_bsp_display.h"
#include "ew_bsp_touch.h"

#define NO_OF_FINGERS                   1

/* additional touch flag to indicate idle state */
#define EW_BSP_TOUCH_IDLE               0

/* additional touch flag to indicate hold state */
#define EW_BSP_TOUCH_HOLD               4


static int           TouchAreaMinX  =  0; /* raw touch value of the leftmost position on the touch screen */
static int           TouchAreaMinY  =  0; /* raw touch value of the topmost position on the touch screen */
static int           TouchAreaMaxX  =  0; /* raw touch value of the rightmost position on the touch screen */
static int           TouchAreaMaxY  =  0; /* raw touch value of the bottommost position on the touch screen */
static int           DisplayWidth   =  0; /* width of the display */
static int           DisplayHeight  =  0; /* height of the display */
static unsigned char TouchState      = EW_BSP_TOUCH_IDLE;
static XTouchEvent   TouchEvent[ NO_OF_FINGERS ];


/*******************************************************************************
* FUNCTION:
*   EwBspTouchInit
*
* DESCRIPTION:
*   Initalizes the touch driver interface. The provided display information is
*   used to configure the touch driver interface so that a proper mapping of
*   touch coordinates to GUI coordinates can be done.
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
int EwBspTouchInit( int aGuiWidth, int aGuiHeight, XDisplayInfo* aDisplayInfo )
{
  EW_UNUSED_ARG( aGuiWidth );
  EW_UNUSED_ARG( aGuiHeight );

  /* clear all touch state variables */
  memset( TouchEvent, 0, sizeof( TouchEvent ));

  /* check display info structure */
  if ( !aDisplayInfo )
    return 0;

  /* take physical size of display from provided display info structure */
  DisplayWidth   = aDisplayInfo->DisplayWidth;
  DisplayHeight  = aDisplayInfo->DisplayHeight;

  /* take touch calibration values */
  TouchAreaMinX = EW_TOUCH_AREA_MIN_X;
  TouchAreaMinY = EW_TOUCH_AREA_MIN_Y;
  TouchAreaMaxX = EW_TOUCH_AREA_MAX_X;
  TouchAreaMaxY = EW_TOUCH_AREA_MAX_Y;

  /* check touch calibration and configuration to avoid division by zero */
  if (( TouchAreaMaxX == TouchAreaMinX ) || ( TouchAreaMaxY == TouchAreaMinY ))
    return 0;

  #ifdef EW_PRINT_TOUCH_DATA

    EwPrint( "\n" );
    EwPrint( "EwBspTouchInit: Using TouchArea %d, %d - %d, %d\n", TouchAreaMinX, TouchAreaMinY, TouchAreaMaxX, TouchAreaMaxY );

  #endif

  BSP_TS_Init( DisplayWidth, DisplayHeight );

  return 1;
}


/*******************************************************************************
* FUNCTION:
*   EwBspTouchDone
*
* DESCRIPTION:
*   Terminates the touch driver.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspTouchDone( void )
{
}


/*******************************************************************************
* FUNCTION:
*   EwBspTouchGetEvents
*
* DESCRIPTION:
*   The function EwBspTouchGetEvents reads the current touch positions from the
*   touch driver and returns the current touch position and touch status of the
*   different fingers. The returned number of touch events indicates the number
*   of XTouchEvent that contain position and status information.
*   The orientation of the touch positions is adjusted to match GUI coordinates.
*   If the hardware supports only single touch, the finger number is always 0.
*
* ARGUMENTS:
*   aTouchEvent - Pointer to return array of XTouchEvent.
*
* RETURN VALUE:
*   Returns the number of detected touch events, otherwise 0.
*
*******************************************************************************/
int EwBspTouchGetEvents( XTouchEvent** aTouchEvent )
{
  static TS_StateTypeDef touchPadState;
  int                    touchX;
  int                    touchY;
  int                    x, y;
  int                    noOfEvents     = 0;
  unsigned long          ticks;
  static unsigned long   ticksLastDown  = 0;
  static unsigned long   ticksLastUp    = 0;

  /* access touch driver to receive current touch status and position */
  touchPadState.TouchDetected = 0;

  CPU_LOAD_SET_IDLE();
  BSP_TS_GetState( &touchPadState );
  CPU_LOAD_SET_ACTIVE();

  /* get current time in ms */
  ticks = EwGetTicks();

  if ( touchPadState.TouchDetected )
  {
    #ifdef EW_PRINT_TOUCH_DATA

      EwPrint( "Raw touch data: x %d, y %d\n", touchPadState.X, touchPadState.Y );

    #endif

    /* apply swapping of raw touch coordinates if required */
    #if ( EW_TOUCH_SWAP_XY )

      touchX = touchPadState.Y;
      touchY = touchPadState.X;

    #else

      touchX = touchPadState.X;
      touchY = touchPadState.Y;

    #endif

    /* convert raw touch coordinates into display coordinates */
    touchX = (( touchX - TouchAreaMinX ) * DisplayWidth ) / ( TouchAreaMaxX - TouchAreaMinX );
    touchY = (( touchY - TouchAreaMinY ) * DisplayHeight ) / ( TouchAreaMaxY - TouchAreaMinY );

    if (( touchX > 0 ) && ( touchX < DisplayWidth  - 1 ) &&
        ( touchY > 0 ) && ( touchY < DisplayHeight - 1 ))
    {
      /* convert display coordinates into GUI coordinates */
      #if ( EW_SURFACE_ROTATION == 90 )

        x = touchY;
        y = DisplayWidth - touchX;

      #elif ( EW_SURFACE_ROTATION == 270 )

        x = DisplayHeight - touchY;
        y = touchX;

      #elif ( EW_SURFACE_ROTATION == 180 )

        x = DisplayWidth - touchX;
        y = DisplayHeight - touchY;

      #else

        x = touchX;
        y = touchY;

      #endif

      #ifdef EW_PRINT_TOUCH_DATA

        EwPrint( "GUI coordinates: x %d, y %d\n", x, y );

      #endif

      ticksLastDown = ticks;

      if (( x == TouchEvent[ 0 ].XPos ) && ( y == TouchEvent[ 0 ].YPos ))
        return 0;

      if ( ticks - ticksLastUp < 40 )
        return 0;

      if ( TouchState == EW_BSP_TOUCH_IDLE )
        TouchState = EW_BSP_TOUCH_DOWN;
      else
        TouchState = EW_BSP_TOUCH_MOVE;

      TouchEvent[ 0 ].XPos   = x;
      TouchEvent[ 0 ].YPos   = y;
      TouchEvent[ 0 ].State  = TouchState;
      noOfEvents = 1;
    }
  }
  else
  {
    /* touch driver provides permanently 'up' events while finger is pressed - in order
       to avoid that a touch sequence is interrupted by unwished 'up' events we have to
       filter over a certain time period until a real 'up' event is detected */
    if (( TouchState != EW_BSP_TOUCH_IDLE ) && ( ticks - ticksLastDown > 40 ))
    {
      TouchEvent[ 0 ].State  = EW_BSP_TOUCH_UP;
      TouchState = EW_BSP_TOUCH_IDLE;
      noOfEvents = 1;
      ticksLastUp = ticks;
    }
  }

  #ifdef EW_PRINT_TOUCH_EVENTS

    if ( noOfEvents == 1 )
      EwPrint( "Touch event for finger 0 with state %d ( %4d, %4d )\n", TouchEvent[ 0 ].State, TouchEvent[ 0 ].XPos, TouchEvent[ 0 ].YPos );

  #endif

  /* return the prepared touch events and the number of prepared touch events */
  if ( aTouchEvent )
    *aTouchEvent = TouchEvent;

  return noOfEvents;
}


/* mli, msy */
