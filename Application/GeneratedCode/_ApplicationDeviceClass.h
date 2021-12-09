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

#ifndef _ApplicationDeviceClass_H
#define _ApplicationDeviceClass_H

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

#include "_TemplatesDeviceClass.h"

/* Forward declaration of the class Application::DeviceClass */
#ifndef _ApplicationDeviceClass_
  EW_DECLARE_CLASS( ApplicationDeviceClass )
#define _ApplicationDeviceClass_
#endif


/* Deklaration of class : 'Application::DeviceClass' */
EW_DEFINE_FIELDS( ApplicationDeviceClass, TemplatesDeviceClass )
  EW_PROPERTY( Current,         XInt32 )
  EW_PROPERTY( Distance,        XInt32 )
  EW_PROPERTY( Angle,           XInt32 )
  EW_PROPERTY( DebugHall1,      XInt32 )
  EW_PROPERTY( DebugHall2,      XInt32 )
  EW_PROPERTY( DebugPad1,       XInt32 )
  EW_PROPERTY( DebugPad2,       XInt32 )
  EW_PROPERTY( Lamptest,        XBool )
EW_END_OF_FIELDS( ApplicationDeviceClass )

/* Virtual Method Table (VMT) for the class : 'Application::DeviceClass' */
EW_DEFINE_METHODS( ApplicationDeviceClass, TemplatesDeviceClass )
EW_END_OF_METHODS( ApplicationDeviceClass )

/* 'C' function for method : 'Application::DeviceClass.Done()' */
void ApplicationDeviceClass_Done( ApplicationDeviceClass _this );

/* 'C' function for method : 'Application::DeviceClass.Init()' */
void ApplicationDeviceClass_Init( ApplicationDeviceClass _this, XHandle aArg );

/* 'C' function for method : 'Application::DeviceClass.OnSetLamptest()' */
void ApplicationDeviceClass_OnSetLamptest( ApplicationDeviceClass _this, XBool value );

/* 'C' function for method : 'Application::DeviceClass.UpdateCurrent()' */
void ApplicationDeviceClass_UpdateCurrent( ApplicationDeviceClass _this, XInt32 
  aNewValue );

/* Wrapper function for the non virtual method : 'Application::DeviceClass.UpdateCurrent()' */
void ApplicationDeviceClass__UpdateCurrent( void* _this, XInt32 aNewValue );

/* The following define announces the presence of the method Application::DeviceClass.UpdateCurrent(). */
#define _ApplicationDeviceClass__UpdateCurrent_

/* 'C' function for method : 'Application::DeviceClass.UpdateDistance()' */
void ApplicationDeviceClass_UpdateDistance( ApplicationDeviceClass _this, XInt32 
  aNewValue );

/* Wrapper function for the non virtual method : 'Application::DeviceClass.UpdateDistance()' */
void ApplicationDeviceClass__UpdateDistance( void* _this, XInt32 aNewValue );

/* The following define announces the presence of the method Application::DeviceClass.UpdateDistance(). */
#define _ApplicationDeviceClass__UpdateDistance_

/* 'C' function for method : 'Application::DeviceClass.UpdateAngle()' */
void ApplicationDeviceClass_UpdateAngle( ApplicationDeviceClass _this, XInt32 aNewValue );

/* Wrapper function for the non virtual method : 'Application::DeviceClass.UpdateAngle()' */
void ApplicationDeviceClass__UpdateAngle( void* _this, XInt32 aNewValue );

/* The following define announces the presence of the method Application::DeviceClass.UpdateAngle(). */
#define _ApplicationDeviceClass__UpdateAngle_

/* 'C' function for method : 'Application::DeviceClass.UpdateDebugHall1()' */
void ApplicationDeviceClass_UpdateDebugHall1( ApplicationDeviceClass _this, XInt32 
  aNewValue );

/* Wrapper function for the non virtual method : 'Application::DeviceClass.UpdateDebugHall1()' */
void ApplicationDeviceClass__UpdateDebugHall1( void* _this, XInt32 aNewValue );

/* The following define announces the presence of the method Application::DeviceClass.UpdateDebugHall1(). */
#define _ApplicationDeviceClass__UpdateDebugHall1_

/* 'C' function for method : 'Application::DeviceClass.UpdateDebugHall2()' */
void ApplicationDeviceClass_UpdateDebugHall2( ApplicationDeviceClass _this, XInt32 
  aNewValue );

/* Wrapper function for the non virtual method : 'Application::DeviceClass.UpdateDebugHall2()' */
void ApplicationDeviceClass__UpdateDebugHall2( void* _this, XInt32 aNewValue );

/* The following define announces the presence of the method Application::DeviceClass.UpdateDebugHall2(). */
#define _ApplicationDeviceClass__UpdateDebugHall2_

/* 'C' function for method : 'Application::DeviceClass.UpdateDebugPad1()' */
void ApplicationDeviceClass_UpdateDebugPad1( ApplicationDeviceClass _this, XInt32 
  aNewValue );

/* Wrapper function for the non virtual method : 'Application::DeviceClass.UpdateDebugPad1()' */
void ApplicationDeviceClass__UpdateDebugPad1( void* _this, XInt32 aNewValue );

/* The following define announces the presence of the method Application::DeviceClass.UpdateDebugPad1(). */
#define _ApplicationDeviceClass__UpdateDebugPad1_

/* 'C' function for method : 'Application::DeviceClass.UpdateDebugPad2()' */
void ApplicationDeviceClass_UpdateDebugPad2( ApplicationDeviceClass _this, XInt32 
  aNewValue );

/* Wrapper function for the non virtual method : 'Application::DeviceClass.UpdateDebugPad2()' */
void ApplicationDeviceClass__UpdateDebugPad2( void* _this, XInt32 aNewValue );

/* The following define announces the presence of the method Application::DeviceClass.UpdateDebugPad2(). */
#define _ApplicationDeviceClass__UpdateDebugPad2_

/* Default onget method for the property 'Lamptest' */
XBool ApplicationDeviceClass_OnGetLamptest( ApplicationDeviceClass _this );

/* Default onget method for the property 'Current' */
XInt32 ApplicationDeviceClass_OnGetCurrent( ApplicationDeviceClass _this );

/* Default onset method for the property 'Current' */
void ApplicationDeviceClass_OnSetCurrent( ApplicationDeviceClass _this, XInt32 value );

/* Default onget method for the property 'Distance' */
XInt32 ApplicationDeviceClass_OnGetDistance( ApplicationDeviceClass _this );

/* Default onset method for the property 'Distance' */
void ApplicationDeviceClass_OnSetDistance( ApplicationDeviceClass _this, XInt32 
  value );

/* Default onget method for the property 'Angle' */
XInt32 ApplicationDeviceClass_OnGetAngle( ApplicationDeviceClass _this );

/* Default onset method for the property 'Angle' */
void ApplicationDeviceClass_OnSetAngle( ApplicationDeviceClass _this, XInt32 value );

/* Default onget method for the property 'DebugHall1' */
XInt32 ApplicationDeviceClass_OnGetDebugHall1( ApplicationDeviceClass _this );

/* Default onset method for the property 'DebugHall1' */
void ApplicationDeviceClass_OnSetDebugHall1( ApplicationDeviceClass _this, XInt32 
  value );

/* Default onget method for the property 'DebugHall2' */
XInt32 ApplicationDeviceClass_OnGetDebugHall2( ApplicationDeviceClass _this );

/* Default onset method for the property 'DebugHall2' */
void ApplicationDeviceClass_OnSetDebugHall2( ApplicationDeviceClass _this, XInt32 
  value );

/* Default onget method for the property 'DebugPad1' */
XInt32 ApplicationDeviceClass_OnGetDebugPad1( ApplicationDeviceClass _this );

/* Default onset method for the property 'DebugPad1' */
void ApplicationDeviceClass_OnSetDebugPad1( ApplicationDeviceClass _this, XInt32 
  value );

/* Default onget method for the property 'DebugPad2' */
XInt32 ApplicationDeviceClass_OnGetDebugPad2( ApplicationDeviceClass _this );

/* Default onset method for the property 'DebugPad2' */
void ApplicationDeviceClass_OnSetDebugPad2( ApplicationDeviceClass _this, XInt32 
  value );

#ifdef __cplusplus
  }
#endif

#endif /* _ApplicationDeviceClass_H */

/* Embedded Wizard */
