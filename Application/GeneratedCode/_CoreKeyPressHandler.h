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

#ifndef _CoreKeyPressHandler_H
#define _CoreKeyPressHandler_H

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

/* Forward declaration of the class Core::KeyEvent */
#ifndef _CoreKeyEvent_
  EW_DECLARE_CLASS( CoreKeyEvent )
#define _CoreKeyEvent_
#endif

/* Forward declaration of the class Core::KeyPressHandler */
#ifndef _CoreKeyPressHandler_
  EW_DECLARE_CLASS( CoreKeyPressHandler )
#define _CoreKeyPressHandler_
#endif


/* The class Core::KeyPressHandler provides a universal keyboard event handler able 
   to process key press and release events. It compares the received key codes with 
   the value of the property @Filter and if the codes do match the filter condition, 
   sends signals to the slot methods stored in the @OnPress, @OnHold and @OnRelease 
   properties.
   Keyboard handlers can be created at the design time only. You can simply drag-and-drop 
   them from the Embedded Wizard Gallery into the Composer window where you are 
   editing the GUI component. If necessary several keyboard handlers can be added 
   to the component. For example, one handler can react to the 'Enter' key and the 
   other to the 'Exit' key. The order in which the handlers will process the events 
   corresponds to their Z-order. You can verify and modify this Z-order in the Embedded 
   Wizard Inspector. Please note, keyboard handlers created at the runtime with 
   the Chora 'new' operator will not work!
   The handler provides several variables with details of the received keyboard 
   event, like the key code (@Code or @CharCode), whether the user has pressed or 
   released the key (@Down), etc. These variables can be evaluated in the implementation 
   of the slot method.
   The property @Enabled can be used to activate/deactivate the keyboard handler. 
   Disabled handler will not react to the events. */
EW_DEFINE_FIELDS( CoreKeyPressHandler, XObject )
  EW_VARIABLE( next,            CoreKeyPressHandler )

  /* The property 'OnRelease' can refer to a slot method, which should be invoked 
     by the handler when the user has released the previously pressed key with the 
     code matching the filter condition @Filter.
     Within the slot method the current state of the handler variables like @Code, 
     @CharCode, @Down, @Repetition, etc. can be evaluated. */
  EW_PROPERTY( OnRelease,       XSlot )

  /* The property 'OnPress' can refer to a slot method, which should be invoked 
     by the handler when the user has pressed a key with a code matching the filter 
     condition @Filter.
     Within the slot method the current state of the handler variables like @Code, 
     @CharCode, @Down, @Repetition, etc. can be evaluated.
     If the slot method decides to ignore the event, it can assign 'true' to the 
     variable @Continue. This causes the framework to pass the event to the next 
     following handler or GUI component. With it, however, the handler will not 
     receive any corresponding @OnHold nor @OnRelease events. */
  EW_PROPERTY( OnPress,         XSlot )
  EW_VARIABLE( pressCounter,    XInt32 )

  /* The variable 'Time' stores the time in milliseconds when the user has triggered 
     the event. */
  EW_VARIABLE( Time,            XUInt32 )

  /* The variable 'RepetitionCount' stores the number of key down repetition events 
     received by this handler after the user has pressed a key.
     Just after pressing a key the variable RepetitionCount is 0. Later every repetition 
     event causes the variable to be incremented. In this manner the implementation 
     of the @OnHold or @OnRelease slot method can determine how long the user presses 
     the key.
     Please note, the frequency with it the repetition events are delivered does 
     depend on the target system and its particular keyboard drivers. If the keyboard 
     driver doesn't support the repetition events, the handler will receive only 
     the @OnPress and @OnRelease events without any @OnHold. */
  EW_VARIABLE( RepetitionCount, XInt32 )

  /* The property 'Filter' stores the key code or the category of key codes to process 
     by this handler. Keyboard events with key codes not matching this filter will 
     be ignored. */
  EW_PROPERTY( Filter,          XEnum )

  /* The variable 'Code' stores the code of the pressed or released key. For UNICODE 
     characters the character code is stored in the @CharCode variable and the variable 
     Code is initialized with the value Core::KeyCode.NoKey. */
  EW_VARIABLE( Code,            XEnum )

  /* The variable 'CharCode' stores the UNICODE character code of the pressed or 
     released character. For key codes the variable is initialized with '\x0000' 
     and the key code is stored in the variable @Code. */
  EW_VARIABLE( CharCode,        XChar )

  /* The property 'Enabled' determines whether the handler is able to react to user 
     inputs. Disabled handlers will ignore any user interactions and will not send 
     any signals to the assigned slot methods. */
  EW_PROPERTY( Enabled,         XBool )

  /* The variable 'Down' determines whether the user has pressed or released the 
     key. If this variable == 'true' the key has been pressed. */
  EW_VARIABLE( Down,            XBool )

  /* The variable 'Repetition' determines whether the user continues pressing the 
     key. */
  EW_VARIABLE( Repetition,      XBool )
EW_END_OF_FIELDS( CoreKeyPressHandler )

/* Virtual Method Table (VMT) for the class : 'Core::KeyPressHandler' */
EW_DEFINE_METHODS( CoreKeyPressHandler, XObject )
EW_END_OF_METHODS( CoreKeyPressHandler )

/* 'C' function for method : 'Core::KeyPressHandler.Init()' */
void CoreKeyPressHandler_Init( CoreKeyPressHandler _this, XHandle aArg );

/* 'C' function for method : 'Core::KeyPressHandler.HandleEvent()' */
XBool CoreKeyPressHandler_HandleEvent( CoreKeyPressHandler _this, CoreKeyEvent aEvent );

#ifdef __cplusplus
  }
#endif

#endif /* _CoreKeyPressHandler_H */

/* Embedded Wizard */
