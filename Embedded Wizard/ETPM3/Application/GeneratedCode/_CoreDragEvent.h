/*******************************************************************************
*
* E M B E D D E D   W I Z A R D   P R O J E C T
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This file was generated automatically by Embedded Wizard Studio.
*
* Please do not make any modifications of this file! The modifications are lost
* when the file is generated again by Embedded Wizard Studio!
*
* The template of this heading text can be found in the file 'head.ewt' in the
* directory 'Platforms' of your Embedded Wizard installation directory. If you
* wish to adapt this text, please copy the template file 'head.ewt' into your
* project directory and edit the copy only. Please avoid any modifications of
* the original template file!
*
* Version  : 11.00
* Profile  : STM32F429
* Platform : STM.STM32.RGB565
*
*******************************************************************************/

#ifndef _CoreDragEvent_H
#define _CoreDragEvent_H

#ifdef __cplusplus
  extern "C"
  {
#endif

#include "ewrte.h"
#if EW_RTE_VERSION != 0x000B0000
  #error Wrong version of Embedded Wizard Runtime Environment.
#endif

#include "ewgfx.h"
#if EW_GFX_VERSION != 0x000B0000
  #error Wrong version of Embedded Wizard Graphics Engine.
#endif

#include "_CoreEvent.h"

/* Forward declaration of the class Core::DragEvent */
#ifndef _CoreDragEvent_
  EW_DECLARE_CLASS( CoreDragEvent )
#define _CoreDragEvent_
#endif


/* The class Core::DragEvent provides a specialized event object able to deliver 
   drag events. These events are sent when the user has touched the screen and then 
   moved the finger. See the method DriveCursorMovement() of the class Core::Root.
   The event contains information about the position where the user has tapped (@HittingPos), 
   the current position after the drag operation (@CurrentPos), the displacement 
   since the last drag event (@Offset), etc.
   The drag events are sent together with the cursor events Core::CursorEvent. */
EW_DEFINE_FIELDS( CoreDragEvent, CoreEvent )
  /* The variable 'GlobalHittingPos' stores the position where the user has touched 
     the screen. This is the origin position at the beginning of the grab cycle. 
     This position is expressed in the global (screen) coordinate space. */
  EW_VARIABLE( GlobalHittingPos, XPoint )

  /* The variable 'GlobalCurrentPos' stores the current cursor position expressed 
     in the global (screen) coordinate space. */
  EW_VARIABLE( GlobalCurrentPos, XPoint )

  /* The variable 'StrikeCount' stores how often the user has tapped the screen 
     in succession. It is one, if the user has single tapped it. It is two if a 
     double tap took place, and so far.
     Such series of taps are recognized only when the taps are performed very quickly 
     and the user doesn't move the finger very much. The appropriate time delay 
     and the valid range for the movement are determined by the properties CursorDragLimit 
     and CursorSequelDelay of the class Core::Root. */
  EW_VARIABLE( StrikeCount,     XInt32 )

  /* The variable 'HoldPeriod' stores the time in milliseconds how long the user 
     is pressing the finger on the screen. This variable is very useful if the view 
     needs to perform an operation after some time is elapsed. At the begin of the 
     grab cycle the HoldPeriod == 0. */
  EW_VARIABLE( HoldPeriod,      XInt32 )

  /* The variable 'Offset' stores the displacement since the last drag event. */
  EW_VARIABLE( Offset,          XPoint )

  /* The variable 'HittingPos' stores the position where the user has touched the 
     screen. This is the origin position at the beginning of the grab cycle. This 
     position is valid in the coordinate space of the owner of the target view. 
     In this manner the position can be compared directly with the coordinates of 
     the view. */
  EW_VARIABLE( HittingPos,      XPoint )

  /* The variable 'CurrentPos' stores the current cursor position. This position 
     is valid in the coordinate space of the owner of the target view. In this manner 
     the position can be compared directly with the coordinates of the view. */
  EW_VARIABLE( CurrentPos,      XPoint )

  /* The variable 'Finger' identifies the finger as an event source within a multi-touch 
     environment. The fingers are numbered with values lying in the range 0 .. 9. */
  EW_VARIABLE( Finger,          XInt32 )
EW_END_OF_FIELDS( CoreDragEvent )

/* Virtual Method Table (VMT) for the class : 'Core::DragEvent' */
EW_DEFINE_METHODS( CoreDragEvent, CoreEvent )
EW_END_OF_METHODS( CoreDragEvent )

/* The method Initialize() simplifies the initialization of this Core::DragEvent 
   object. This method stores the given parameters in the variables of this event 
   object and returns this event object to the caller. */
CoreDragEvent CoreDragEvent_Initialize( CoreDragEvent _this, XInt32 aFinger, XPoint 
  aCurrentPos, XPoint aHittingPos, XPoint aOffset, XInt32 aHoldPeriod, XInt32 aSequelCount, 
  XPoint aHitOffset, XPoint aGlobalCurrentPos, XPoint aGlobalHittingPos );

/* Wrapper function for the non virtual method : 'Core::DragEvent.Initialize()' */
CoreDragEvent CoreDragEvent__Initialize( void* _this, XInt32 aFinger, XPoint aCurrentPos, 
  XPoint aHittingPos, XPoint aOffset, XInt32 aHoldPeriod, XInt32 aSequelCount, XPoint 
  aHitOffset, XPoint aGlobalCurrentPos, XPoint aGlobalHittingPos );

/* The following define announces the presence of the method Core::DragEvent.Initialize(). */
#define _CoreDragEvent__Initialize_

#ifdef __cplusplus
  }
#endif

#endif /* _CoreDragEvent_H */

/* Embedded Wizard */
