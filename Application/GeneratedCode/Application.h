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

#ifndef Application_H
#define Application_H

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

#include "_ApplicationApplication.h"
#include "_ApplicationCalibration.h"
#include "_ApplicationCurrentMeasurement.h"
#include "_ApplicationDebug.h"
#include "_ApplicationDetectorScreen.h"
#include "_ApplicationDeviceClass.h"
#include "_ApplicationDistanceMeasurement.h"
#include "_ApplicationMenu.h"
#include "_ApplicationSettings.h"
#include "_ApplicationWelcomeScreen.h"

/* This is a font resource. */
EW_DECLARE_FONT_RES( ApplicationFont )

/* Font resource : 'Application::TitelFont' */
EW_DECLARE_FONT_RES( ApplicationTitelFont )

/* Bitmap resource : 'Application::ZhawLogo' */
EW_DECLARE_BITMAP_RES( ApplicationZhawLogo )

/* User defined auto object: 'Application::Device' */
EW_DECLARE_AUTOOBJECT( ApplicationDevice, ApplicationDeviceClass )

#ifdef __cplusplus
  }
#endif

#endif /* Application_H */

/* Embedded Wizard */
