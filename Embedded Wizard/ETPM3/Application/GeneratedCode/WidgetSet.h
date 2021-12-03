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

#ifndef WidgetSet_H
#define WidgetSet_H

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

#include "_WidgetSetGauge.h"
#include "_WidgetSetGaugeConfig.h"
#include "_WidgetSetHorizontalValueBar.h"
#include "_WidgetSetHorizontalValueBarConfig.h"
#include "_WidgetSetPushButton.h"
#include "_WidgetSetPushButtonConfig.h"
#include "_WidgetSetToggleButton.h"
#include "_WidgetSetToggleButtonConfig.h"
#include "_WidgetSetValueDisplay.h"
#include "_WidgetSetValueDisplayConfig.h"
#include "_WidgetSetWidgetConfig.h"

/* Bitmap resource used per default by the Widgets customized for the medium size. */
EW_DECLARE_BITMAP_RES( WidgetSetGaugeNeedleMedium )

/* Bitmap resource used per default by the Widgets customized for the medium size. */
EW_DECLARE_BITMAP_RES( WidgetSetGaugeTrackMedium )

/* Bitmap resource used per default by the Widgets customized for the medium size. */
EW_DECLARE_BITMAP_RES( WidgetSetHorizontalValueBarMedium )

/* Bitmap resource used per default by the Widgets customized for the medium size. */
EW_DECLARE_BITMAP_RES( WidgetSetPushButtonMedium )

/* Bitmap resource used per default by the Widgets customized for the medium size. */
EW_DECLARE_BITMAP_RES( WidgetSetSwitchMedium )

/* This autoobject provides the default customization for the 'horizontal value 
   bar' widget (WidgetSet::HorizontalValueBar) in its medium size variant. */
EW_DECLARE_AUTOOBJECT( WidgetSetHorizontalValueBar_Medium, WidgetSetHorizontalValueBarConfig )

/* This autoobject provides the default customization for the 'value display' widget 
   (WidgetSet::ValueDisplay) in its medium size variant. Widgets using this configuration 
   display the value and unit aligned at the right widget edge. */
EW_DECLARE_AUTOOBJECT( WidgetSetValueDisplay_Medium, WidgetSetValueDisplayConfig )

/* This autoobject provides the default customization for the 'analog gauge' widget 
   (WidgetSet::Gauge) in its medium size variant. */
EW_DECLARE_AUTOOBJECT( WidgetSetGauge_Medium, WidgetSetGaugeConfig )

/* This autoobject provides one of the default customizations for the 'toggle' widget 
   (WidgetSet::ToggleButton) in its medium size variant. With this customization 
   the toggle button appears as a 'switch'. */
EW_DECLARE_AUTOOBJECT( WidgetSetSwitch_Medium, WidgetSetToggleButtonConfig )

/* This autoobject provides the default customization for the 'push button' widget 
   (WidgetSet::PushButton) in its medium size variant. */
EW_DECLARE_AUTOOBJECT( WidgetSetPushButton_Medium, WidgetSetPushButtonConfig )

/* The definition WidgetSet::ValueDisplayLayout determines the available arrangement 
   modes to apply on the views within a WidgetSet::ValueDisplay widget. Depending 
   on the mode, the views will be treated independently or one view will be arranged 
   at the left/right end of the content displayed in the other view. */
typedef enum
{

  /* The mode 'UnitAndValueAreIndependent' determines, that the text views to display 
     the value and the unit parts are arranged independently within the area of 
     a WidgetSet::ValueDisplay widget. */
  WidgetSetValueDisplayLayoutUnitAndValueAreIndependent = 0,

  /* The mode 'AlignUnitRightToValue' determines, that the text view intended to 
     display the unit within a WidgetSet::ValueDisplay widget should be aligned 
     at the right end of the text displayed in the value text view. Accordingly, 
     when the value text changes, the unit text view is moved automatically.
     With the property 'UnitMarginLeft' of the WidgetSet::ValueDisplayConfig object 
     you can additionally specify a margin between the right end of the value text 
     and the left edge of the unit text view. */
  WidgetSetValueDisplayLayoutAlignUnitRightToValue = 1,

  /* The mode 'AlignUnitLeftToValue' determines, that the text view intended to 
     display the unit within a WidgetSet::ValueDisplay widget should be aligned 
     at the left end of the text displayed in the value text view. Accordingly, 
     when the value text changes, the unit text view is moved automatically.
     With the property 'UnitMarginRight' of the WidgetSet::ValueDisplayConfig object 
     you can additionally specify a margin between the right edge of the unit text 
     view and the left end of the value text. */
  WidgetSetValueDisplayLayoutAlignUnitLeftToValue = 2,

  /* The mode 'AlignValueRightToUnit' determines, that the text view intended to 
     display the value within a WidgetSet::ValueDisplay widget should be aligned 
     at the right end of the text displayed in the Unit text view. Accordingly, 
     when the unit text changes, the value text view is moved automatically.
     With the property 'ValueMarginLeft' of the WidgetSet::ValueDisplayConfig object 
     you can additionally specify a margin between the right end of the unit text 
     and the left edge of the value text view. */
  WidgetSetValueDisplayLayoutAlignValueRightToUnit = 3,

  /* The mode 'AlignValueLeftToUnit' determines, that the text view intended to 
     display the value within a WidgetSet::ValueDisplay widget should be aligned 
     at the left end of the text displayed in the unit text view. Accordingly, when 
     the unit text changes, the value text view is moved automatically.
     With the property 'ValueMarginRight' of the WidgetSet::ValueDisplayConfig object 
     you can additionally specify a margin between the right edge of the value text 
     view and the left end of the unit text. */
  WidgetSetValueDisplayLayoutAlignValueLeftToUnit = 4
} WidgetSetValueDisplayLayout;

#ifdef __cplusplus
  }
#endif

#endif /* WidgetSet_H */

/* Embedded Wizard */
