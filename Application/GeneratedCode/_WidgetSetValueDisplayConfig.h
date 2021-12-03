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

#ifndef _WidgetSetValueDisplayConfig_H
#define _WidgetSetValueDisplayConfig_H

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

#include "_WidgetSetWidgetConfig.h"

/* Forward declaration of the class Resources::Font */
#ifndef _ResourcesFont_
  EW_DECLARE_CLASS( ResourcesFont )
#define _ResourcesFont_
#endif

/* Forward declaration of the class WidgetSet::ValueDisplayConfig */
#ifndef _WidgetSetValueDisplayConfig_
  EW_DECLARE_CLASS( WidgetSetValueDisplayConfig )
#define _WidgetSetValueDisplayConfig_
#endif


/* This class implements the functionality permitting you to simply customize the 
   look and feel of a 'value display' widget (WidgetSet::ValueDisplay). In the practice, 
   you will create an instance of this class, configure its properties with fonts, 
   colors and other relevant attributes according to your design expectations and 
   assign such prepared configuration object to the property 'Appearance' of every 
   affected value display widget. Thereupon the widgets will use the configuration 
   information provided in the object.
   During its lifetime the value display widget remains always in one of the both 
   states: 'positive' or 'negative'. The state 'positive' is true if the value displayed 
   in the widget is greater than or equal to 0 (zero). The state 'negative' is true, 
   if the value is less than 0 (zero). With the configuration object you can specify 
   the appearance of the value display widget for every state individually. For 
   this purpose you should know from which views the widget is composed of:
   - 'Value' is a text view (Views::Text) displayed per default in the center of 
   the widget. The corresponding text is formatted from the number stored in the 
   property 'CurrentValue' in the value display widget. In the configuration object 
   you can determine the font (@ValueFont), alignment (@ValueAlignment) and margins 
   (@ValueMarginBottom, @ValueMarginLeft, @ValueMarginRight, @ValueMarginTop) to 
   use for the text view. For every widget state you can specify individual text 
   color values (@ValueColorPositive and @ValueColorNegative).
   - 'Unit' is a text view (Views::Text) displayed per default in the center of 
   the widget. The corresponding text is specified in the property 'Unit' in the 
   value display widget. In the configuration object you can determine the font 
   (@UnitFont), alignment (@UnitAlignment) and margins (@UnitMarginBottom, @UnitMarginLeft, 
   @UnitMarginRight, @UnitMarginTop) to use for the text view. For every widget 
   state you can specify individual text color values (@UnitColorPositive and @UnitColorNegative).
   Per default the both views 'Value' and 'Unit' are arranged within the widget 
   area independently. With the property @Layout you can specify other modes to 
   e.g. arrange the unit to appear appended at the right edge of the displayed value; 
   etc.
   The configuration object provides various properties to localize the format operation 
   how the number is presented. In particular, with the properties @FormatDecimalSign 
   and @FormatDigitGroupSign you can specify the signs or strings to be used as 
   decimal separator sign and digit group sign. With the properties @FormatMinusSign 
   and @FormatPlusSign you can determine which signs or strings should appear to 
   sign positive or negative numbers.
   With the properties @WidgetMinSize and @WidgetMaxSize you can configure size 
   constraints for the widget itself. You can, for example, limit the value display 
   widget to not shrink below a specified width or height. */
EW_DEFINE_FIELDS( WidgetSetValueDisplayConfig, WidgetSetWidgetConfig )
  /* The property 'ValueFont' determines the font object used to print the text 
     with the numerical value. If no font is specified (the property is 'null'), 
     no text is displayed. */
  EW_PROPERTY( ValueFont,       ResourcesFont )

  /* The property 'UnitFont' determines the font object used to print the text specified 
     in the property 'Unit' of the value display widget. If no font is specified 
     (the property is 'null'), no text is displayed. */
  EW_PROPERTY( UnitFont,        ResourcesFont )

  /* The property 'FormatPlusSign' determines the string to prefix the displayed 
     value if the value is greater than or equal to 0 (zero). If this property is 
     initialized with an empty string "", no signs are shown in front of a positive 
     number. */
  EW_PROPERTY( FormatPlusSign,  XString )

  /* The property 'ValueMarginRight' determines the gap on the right of the area 
     destined to display the value text relative to the right edge of the widget 
     itself.
     Please note, if @Layout is configured with 'AlignValueLeftToUnit', the property 
     'ValueMarginRight' determines the gap relative to the left end of the content 
     displayed actually in the unit view. */
  EW_PROPERTY( ValueMarginRight, XInt32 )

  /* The property 'ValueColorNegative' determines the color to display the numerical 
     value if the value is less than 0 (zero). */
  EW_PROPERTY( ValueColorNegative, XColor )

  /* The property 'ValueColorPositive' determines the color to display the numerical 
     value if the value is greater than or equal to 0 (zero). */
  EW_PROPERTY( ValueColorPositive, XColor )

  /* The property 'ValueAlignment' determines how the text showing the numerical 
     value should be aligned.
     Per default, the value is aligned within the entire widget area. By using the 
     properties @ValueMarginLeft, @ValueMarginRight, @ValueMarginTop and @valueMarginBottom 
     you can limit the area as desired. */
  EW_PROPERTY( ValueAlignment,  XSet )

  /* The property 'UnitColorNegative' determines the color value to display the 
     text specified in the property 'Unit' if the actually displayed value is less 
     than 0 (zero). */
  EW_PROPERTY( UnitColorNegative, XColor )

  /* The property 'UnitColorPositive' determines the color value to display the 
     text specified in the property 'Unit' if the actually displayed value is greater 
     than or equal to 0 (zero). */
  EW_PROPERTY( UnitColorPositive, XColor )

  /* The property 'UnitAlignment' determines how the text specified in the property 
     'Unit' of the value display widget should be aligned.
     Per default, the text is aligned within the entire widget area. By using the 
     properties @UnitMarginLeft, @UnitMarginRight, @UnitMarginTop and @UnitMarginBottom 
     you can limit the area as desired. */
  EW_PROPERTY( UnitAlignment,   XSet )

  /* The property 'WidgetMinSize' determines the minimal allowed size of the widget. 
     Accordingly, the value display widget can't become smaller than the value specified 
     in this property. By using this property you can configure the size constraints 
     for the widget. */
  EW_PROPERTY( WidgetMinSize,   XPoint )

  /* The property 'Layout' determines whether and how the both text views (value 
     and unit) should be arranged within the area of the widget. Following options 
     exist:
     - UnitAndValueAreIndependent: the views are arranged independently within the 
     area of a widget.
     - AlignUnitRightToValue: the view intended to display the unit should be aligned 
     at the right end of the text displayed in the value view. Accordingly, when 
     the value text changes, the unit view is moved automatically. With the property 
     @UnitMarginLeft you can additionally specify a margin between the right end 
     of the value text and the left edge of the unit view.
     - AlignUnitLeftToValue: the view intended to display the unit should be aligned 
     at the left end of the text displayed in the value view. Accordingly, when 
     the value text changes, the unit view is moved automatically. With the property 
     @UnitMarginRight you can additionally specify a margin between the right edge 
     of the unit view and the left end of the value text.
     - AlignValueRightToUnit: the view intended to display the value should be aligned 
     at the right end of the text displayed in the unit view. Accordingly, when 
     the unit text changes, the value view is moved automatically. With the property 
     @ValueMarginLeft you can additionally specify a margin between the right end 
     of the unit text and the left edge of the value view.
     - AlignValueLeftToUnit: the view intended to display the value should be aligned 
     at the left end of the text displayed in the unit view. Accordingly, when the 
     unit text changes, the value view is moved automatically. With the property 
     @ValueMarginRight you can additionally specify a margin between the right edge 
     of the value view and the left end of the unit text. */
  EW_PROPERTY( Layout,          XEnum )
EW_END_OF_FIELDS( WidgetSetValueDisplayConfig )

/* Virtual Method Table (VMT) for the class : 'WidgetSet::ValueDisplayConfig' */
EW_DEFINE_METHODS( WidgetSetValueDisplayConfig, WidgetSetWidgetConfig )
EW_END_OF_METHODS( WidgetSetValueDisplayConfig )

/* 'C' function for method : 'WidgetSet::ValueDisplayConfig.OnSetValueMarginRight()' */
void WidgetSetValueDisplayConfig_OnSetValueMarginRight( WidgetSetValueDisplayConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::ValueDisplayConfig.OnSetValueColorNegative()' */
void WidgetSetValueDisplayConfig_OnSetValueColorNegative( WidgetSetValueDisplayConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ValueDisplayConfig.OnSetValueColorPositive()' */
void WidgetSetValueDisplayConfig_OnSetValueColorPositive( WidgetSetValueDisplayConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ValueDisplayConfig.OnSetValueAlignment()' */
void WidgetSetValueDisplayConfig_OnSetValueAlignment( WidgetSetValueDisplayConfig _this, 
  XSet value );

/* 'C' function for method : 'WidgetSet::ValueDisplayConfig.OnSetValueFont()' */
void WidgetSetValueDisplayConfig_OnSetValueFont( WidgetSetValueDisplayConfig _this, 
  ResourcesFont value );

/* 'C' function for method : 'WidgetSet::ValueDisplayConfig.OnSetUnitColorNegative()' */
void WidgetSetValueDisplayConfig_OnSetUnitColorNegative( WidgetSetValueDisplayConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ValueDisplayConfig.OnSetUnitColorPositive()' */
void WidgetSetValueDisplayConfig_OnSetUnitColorPositive( WidgetSetValueDisplayConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ValueDisplayConfig.OnSetUnitAlignment()' */
void WidgetSetValueDisplayConfig_OnSetUnitAlignment( WidgetSetValueDisplayConfig _this, 
  XSet value );

/* 'C' function for method : 'WidgetSet::ValueDisplayConfig.OnSetUnitFont()' */
void WidgetSetValueDisplayConfig_OnSetUnitFont( WidgetSetValueDisplayConfig _this, 
  ResourcesFont value );

/* 'C' function for method : 'WidgetSet::ValueDisplayConfig.OnSetFormatPlusSign()' */
void WidgetSetValueDisplayConfig_OnSetFormatPlusSign( WidgetSetValueDisplayConfig _this, 
  XString value );

/* 'C' function for method : 'WidgetSet::ValueDisplayConfig.OnSetLayout()' */
void WidgetSetValueDisplayConfig_OnSetLayout( WidgetSetValueDisplayConfig _this, 
  XEnum value );

/* 'C' function for method : 'WidgetSet::ValueDisplayConfig.OnSetWidgetMinSize()' */
void WidgetSetValueDisplayConfig_OnSetWidgetMinSize( WidgetSetValueDisplayConfig _this, 
  XPoint value );

#ifdef __cplusplus
  }
#endif

#endif /* _WidgetSetValueDisplayConfig_H */

/* Embedded Wizard */
