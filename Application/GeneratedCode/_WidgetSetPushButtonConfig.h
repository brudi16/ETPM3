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

#ifndef _WidgetSetPushButtonConfig_H
#define _WidgetSetPushButtonConfig_H

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

/* Forward declaration of the class Resources::Bitmap */
#ifndef _ResourcesBitmap_
  EW_DECLARE_CLASS( ResourcesBitmap )
#define _ResourcesBitmap_
#endif

/* Forward declaration of the class Resources::Font */
#ifndef _ResourcesFont_
  EW_DECLARE_CLASS( ResourcesFont )
#define _ResourcesFont_
#endif

/* Forward declaration of the class WidgetSet::PushButtonConfig */
#ifndef _WidgetSetPushButtonConfig_
  EW_DECLARE_CLASS( WidgetSetPushButtonConfig )
#define _WidgetSetPushButtonConfig_
#endif


/* This class implements the functionality permitting you to simply customize the 
   look and feel of a monostable 'push button' widget (WidgetSet::PushButton). In 
   the practice, you will create an instance of this class, configure its properties 
   with bitmaps, colors and other relevant attributes according to your design expectations 
   and assign such prepared configuration object to the property 'Appearance' of 
   every affected push button widget. Thereupon the widgets will use the configuration 
   information provided in the object.
   During its lifetime the button remains always in one of the four states: 'disabled', 
   'default', 'focused' and 'active'. The state 'disabled' is true for every not 
   available button (the property 'Enabled' of the button is 'false'). Such buttons 
   will ignore all user inputs. The state 'default' determines a button, which is 
   ready to be touched by the user or ready to become focused. As soon as the button 
   becomes focused, it switches in the state 'focused'. In this state the user can 
   activate the button by pressing a key on the keyboard. Finally, the state 'active' 
   is true, if the user actually interacts with the button (the button is pressed). 
   With the configuration object you can specify the appearance of the button for 
   every state individually. For this purpose you should know from which views the 
   button is composed of:
   - 'Face' is a bitmap frame view (Views::Frame) filling per default the entire 
   background of the button. In the configuration object you can individually specify 
   for every button state the desired bitmap (@FaceActive, @FaceDefault, @FaceDisabled, 
   @FaceFocused), the frame number within the bitmap (@FaceFrameActive, @FaceFrameDefault, 
   @FaceFrameDisabled, @FaceFrameFocused) and opacity or color to tint the bitmap 
   (@FaceTintActive, @FaceTintDefault, @FaceTintDisabled, @FaceTintFocused). The 
   button can automatically play animated bitmaps if the corresponding frame number 
   is -1. If desired, with the property @FaceLayout you can also configure the bitmap 
   to be arranged horizontally and vertically instead of filling the entire widget 
   area.
   - 'Icon' is an image view (Views::Image) displayed per default in the center 
   of the button. The corresponding bitmap is determined in the property 'Icon' 
   in the push button widget. In the configuration object you can specify the alignment 
   (@IconAlignment) and margins (@IconMarginBottom, @IconMarginLeft, @IconMarginRight, 
   @IconMarginTop) how to arrange the 'Icon' bitmap within the button area. Furthermore, 
   for every button state the opacity or color to tint the bitmap can be determined 
   (@IconTintActive, @IconTintDefault, @IconTintDisabled, @IconTintFocused).
   - 'Label' is a text view (Views::Text) displayed per default in the center of 
   the button. The corresponding text is determined in the property 'Label' in the 
   push button widget. In the configuration object you can specify the font (@LabelFont), 
   alignment (@LabelAlignment) and margins (@LabelMarginBottom, @LabelMarginLeft, 
   @LabelMarginRight, @LabelMarginTop) to use for the text view. For every button 
   state you can specify individual text color values (@LabelColorActive, @LabelColorDefault, 
   @LabelColorDisabled, @LabelColorFocused).
   If the button is actually focused, it can also be activated by pressing the keyboard 
   key specified in the property @KeyCode. To prevent the button from being able 
   to be focused, initialize this property with the value Core::KeyCode.NoKey. The 
   property @PressedFeedbackDuration configures the duration how long the button 
   should appear active (pressed) even if it has been taped for a very short time.
   With the properties @WidgetMinSize and @WidgetMaxSize you can configure size 
   constraints for the widget itself. You can, for example, limit the button to 
   not shrink below a specified width or height. */
EW_DEFINE_FIELDS( WidgetSetPushButtonConfig, WidgetSetWidgetConfig )
  /* The property 'LabelFont' determines the font object used to print the text 
     specified in the property 'Label' of the button widget. If no font is specified 
     (the property is 'null'), no text is displayed. */
  EW_PROPERTY( LabelFont,       ResourcesFont )

  /* The property 'FaceActive' determines the bitmap to fill the background of the 
     push button when the button is in the 'active' state (the user is actually 
     touching the button or pressing a key on the keyboard the push button should 
     react on).
     If the specified bitmap contains more than one frame (multi-frame bitmap), 
     the desired frame number can be selected in the property @FaceFrameActive. 
     If the selected bitmap is intended to be animated, ensure that the property 
     @FaceFrameActive is -1.
     If the specified bitmap contains opacity information only (Alpha8 bitmap), 
     you can tint the bitmap by specifying the desired color in the property @FaceTintActive. 
     With the property @FaceTintActive you can also modulate the opacity of a regular 
     bitmap.
     Per default, the actually visible face bitmap fills the entire background area 
     of the button. With the property @FaceLayout you can modify this behavior and 
     configure the bitmap to retain its original width and/or height. You can also 
     determine how the bitmap should be aligned vertically and horizontally within 
     the button area. */
  EW_PROPERTY( FaceActive,      ResourcesBitmap )

  /* The property 'FaceFocused' determines the bitmap to fill the background of 
     the push button when the button is in the 'focused' state (the button can react 
     to keyboard events).
     If the specified bitmap contains more than one frame (multi-frame bitmap), 
     the desired frame number can be selected in the property @FaceFrameFocused. 
     If the selected bitmap is intended to be animated, ensure that the property 
     @FaceFrameFocused is -1.
     If the specified bitmap contains opacity information only (Alpha8 bitmap), 
     you can tint the bitmap by specifying the desired color in the property @FaceTintFocused. 
     With the property @FaceTintFocused you can also modulate the opacity of a regular 
     bitmap.
     Per default, the actually visible face bitmap fills the entire background area 
     of the button. With the property @FaceLayout you can modify this behavior and 
     configure the bitmap to retain its original width and/or height. You can also 
     determine how the bitmap should be aligned vertically and horizontally within 
     the button area. */
  EW_PROPERTY( FaceFocused,     ResourcesBitmap )

  /* The property 'FaceDisabled' determines the bitmap to fill the background of 
     the push button when the button is in the 'disabled' state (property 'Enabled' 
     of the button is 'false').
     If the specified bitmap contains more than one frame (multi-frame bitmap), 
     the desired frame number can be selected in the property @FaceFrameDisabled. 
     If the selected bitmap is intended to be animated, ensure that the property 
     @FaceFrameDisabled is -1.
     If the specified bitmap contains opacity information only (Alpha8 bitmap), 
     you can tint the bitmap by specifying the desired color in the property @FaceTintDisabled. 
     With the property @FaceTintDisabled you can also modulate the opacity of a 
     regular bitmap.
     Per default, the actually visible face bitmap fills the entire background area 
     of the button. With the property @FaceLayout you can modify this behavior and 
     configure the bitmap to retain its original width and/or height. You can also 
     determine how the bitmap should be aligned vertically and horizontally within 
     the button area. */
  EW_PROPERTY( FaceDisabled,    ResourcesBitmap )

  /* The property 'FaceDefault' determines the bitmap to fill the background of 
     the push button when the button is in the 'default' state.
     If the specified bitmap contains more than one frame (multi-frame bitmap), 
     the desired frame number can be selected in the property @FaceFrameDefault. 
     If the selected bitmap is intended to be animated, ensure that the property 
     @FaceFrameDefault is -1.
     If the specified bitmap contains opacity information only (Alpha8 bitmap), 
     you can tint the bitmap by specifying the desired color in the property @FaceTintDefault. 
     With the property @FaceTintDefault you can also modulate the opacity of a regular 
     bitmap.
     Per default, the actually visible face bitmap fills the entire background area 
     of the button. With the property @FaceLayout you can modify this behavior and 
     configure the bitmap to retain its original width and/or height. You can also 
     determine how the bitmap should be aligned vertically and horizontally within 
     the button area. */
  EW_PROPERTY( FaceDefault,     ResourcesBitmap )

  /* The property 'LabelColorActive' determines the color value to use when the 
     text specified in the property 'Label' of the button widget is displayed and 
     the button is in the 'active' state (the user is actually touching the button 
     or pressing a key on the keyboard the push button should react on). */
  EW_PROPERTY( LabelColorActive, XColor )

  /* The property 'LabelColorFocused' determines the color value to use when the 
     text specified in the property 'Label' of the button widget is displayed and 
     the button is in the 'focused' state (the button can react to keyboard events). */
  EW_PROPERTY( LabelColorFocused, XColor )

  /* The property 'LabelColorDisabled' determines the color value to use when the 
     text specified in the property 'Label' of the button widget is displayed and 
     the button is in the 'disabled' state (property 'Enabled' of the button is 
     'false'). */
  EW_PROPERTY( LabelColorDisabled, XColor )

  /* The property 'LabelColorDefault' determines the color value to use when the 
     text specified in the property 'Label' of the button widget is displayed and 
     the button is in the 'default' state. */
  EW_PROPERTY( LabelColorDefault, XColor )

  /* The property 'LabelMarginBottom' determines the gap below the area destined 
     to display the label text relative to the bottom edge of the button itself. */
  EW_PROPERTY( LabelMarginBottom, XInt32 )

  /* The property 'LabelMarginTop' determines the gap above the area destined to 
     display the label text relative to the top edge of the button itself. */
  EW_PROPERTY( LabelMarginTop,  XInt32 )

  /* The property 'LabelMarginRight' determines the gap on the right of the area 
     destined to display the label text relative to the right edge of the button 
     itself. */
  EW_PROPERTY( LabelMarginRight, XInt32 )

  /* The property 'LabelMarginLeft' determines the gap on the left of the area destined 
     to display the label text relative to the left edge of the button itself. */
  EW_PROPERTY( LabelMarginLeft, XInt32 )

  /* The property 'IconTintDisabled' determines the color value to tint or modulate 
     the bitmap specified in the property 'Icon' of the button widget if the button 
     is in the 'disabled' state (property 'Enabled' of the button is 'false'). The 
     effect of this color value depends on the type of the bitmap:
     - Alpha8 bitmaps will be tinted with the given color due to the fact that they 
     don't provide their own color information. This allows one and the same Alpha8 
     bitmap to be shown with different colors.
     - In case of Native, Index8 or RGB565 bitmaps the opacity of the bitmap is 
     modulated by the color's alpha value. The original RGB information stored in 
     the bitmap is not affected. This allows one and the same bitmap to be shown 
     with different transparencies. */
  EW_PROPERTY( IconTintDisabled, XColor )

  /* The property 'IconTintDefault' determines the color value to tint or modulate 
     the bitmap specified in the property 'Icon' of the button widget if the button 
     is in the 'default' state. The effect of this color value depends on the type 
     of the bitmap:
     - Alpha8 bitmaps will be tinted with the given color due to the fact that they 
     don't provide their own color information. This allows one and the same Alpha8 
     bitmap to be shown with different colors.
     - In case of Native, Index8 or RGB565 bitmaps the opacity of the bitmap is 
     modulated by the color's alpha value. The original RGB information stored in 
     the bitmap is not affected. This allows one and the same bitmap to be shown 
     with different transparencies. */
  EW_PROPERTY( IconTintDefault, XColor )

  /* The property 'IconMarginBottom' determines the gap below the area destined 
     to display the icon bitmap relative to the bottom edge of the button itself. */
  EW_PROPERTY( IconMarginBottom, XInt32 )

  /* The property 'IconMarginTop' determines the gap above the area destined to 
     display the icon bitmap relative to the top edge of the button itself. */
  EW_PROPERTY( IconMarginTop,   XInt32 )

  /* The property 'IconMarginRight' determines the gap on the right of the area 
     destined to display the icon bitmap relative to the right edge of the button 
     itself. */
  EW_PROPERTY( IconMarginRight, XInt32 )

  /* The property 'IconMarginLeft' determines the gap on the left of the area destined 
     to display the icon bitmap relative to the left edge of the button itself. */
  EW_PROPERTY( IconMarginLeft,  XInt32 )

  /* The property 'FaceFrameActive' determines the frame number within the bitmap 
     @FaceActive. This property is applicable for multi-frame bitmaps only (see 
     also Resources::Bitmap). If the desired frame is not available in the bitmap, 
     no bitmap is shown.
     If the property is initialized with the value -1 and the @FaceActive bitmap 
     is animated, the animation is automatically started as soon as the button enters 
     the 'active' state. If the bitmap is not animated and the property is -1, the 
     frame with number 0 is displayed. */
  EW_PROPERTY( FaceFrameActive, XInt32 )

  /* The property 'FaceFrameFocused' determines the frame number within the bitmap 
     @FaceFocused. This property is applicable for multi-frame bitmaps only (see 
     also Resources::Bitmap). If the desired frame is not available in the bitmap, 
     no bitmap is shown.
     If the property is initialized with the value -1 and the @FaceFocused bitmap 
     is animated, the animation is automatically started as soon as the button enters 
     the 'focused' state. If the bitmap is not animated and the property is -1, 
     the frame with number 0 is displayed. */
  EW_PROPERTY( FaceFrameFocused, XInt32 )

  /* The property 'FaceFrameDisabled' determines the frame number within the bitmap 
     @FaceDisabled. This property is applicable for multi-frame bitmaps only (see 
     also Resources::Bitmap). If the desired frame is not available in the bitmap, 
     no bitmap is shown.
     If the property is initialized with the value -1 and the @FaceDisabled bitmap 
     is animated, the animation is automatically started as soon as the button enters 
     the 'disabled' state. If the bitmap is not animated and the property is -1, 
     the frame with number 0 is displayed. */
  EW_PROPERTY( FaceFrameDisabled, XInt32 )

  /* The property 'FaceFrameDefault' determines the frame number within the bitmap 
     @FaceDefault. This property is applicable for multi-frame bitmaps only (see 
     also Resources::Bitmap). If the desired frame is not available in the bitmap, 
     no bitmap is shown.
     If the property is initialized with the value -1 and the @FaceDefault bitmap 
     is animated, the animation is automatically started as soon as the button enters 
     the 'default' state. If the bitmap is not animated and the property is -1, 
     the frame with number 0 is displayed. */
  EW_PROPERTY( FaceFrameDefault, XInt32 )

  /* The property 'WidgetMinSize' determines the minimal allowed size of the widget. 
     Accordingly, the button can't become smaller than the value specified in this 
     property. By using this property you can configure the size constraints for 
     the button. */
  EW_PROPERTY( WidgetMinSize,   XPoint )
EW_END_OF_FIELDS( WidgetSetPushButtonConfig )

/* Virtual Method Table (VMT) for the class : 'WidgetSet::PushButtonConfig' */
EW_DEFINE_METHODS( WidgetSetPushButtonConfig, WidgetSetWidgetConfig )
EW_END_OF_METHODS( WidgetSetPushButtonConfig )

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelColorActive()' */
void WidgetSetPushButtonConfig_OnSetLabelColorActive( WidgetSetPushButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelColorFocused()' */
void WidgetSetPushButtonConfig_OnSetLabelColorFocused( WidgetSetPushButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelColorDisabled()' */
void WidgetSetPushButtonConfig_OnSetLabelColorDisabled( WidgetSetPushButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelColorDefault()' */
void WidgetSetPushButtonConfig_OnSetLabelColorDefault( WidgetSetPushButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelMarginBottom()' */
void WidgetSetPushButtonConfig_OnSetLabelMarginBottom( WidgetSetPushButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelMarginTop()' */
void WidgetSetPushButtonConfig_OnSetLabelMarginTop( WidgetSetPushButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelMarginRight()' */
void WidgetSetPushButtonConfig_OnSetLabelMarginRight( WidgetSetPushButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelMarginLeft()' */
void WidgetSetPushButtonConfig_OnSetLabelMarginLeft( WidgetSetPushButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetIconTintDisabled()' */
void WidgetSetPushButtonConfig_OnSetIconTintDisabled( WidgetSetPushButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetIconTintDefault()' */
void WidgetSetPushButtonConfig_OnSetIconTintDefault( WidgetSetPushButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetIconMarginBottom()' */
void WidgetSetPushButtonConfig_OnSetIconMarginBottom( WidgetSetPushButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetIconMarginTop()' */
void WidgetSetPushButtonConfig_OnSetIconMarginTop( WidgetSetPushButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetIconMarginRight()' */
void WidgetSetPushButtonConfig_OnSetIconMarginRight( WidgetSetPushButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetIconMarginLeft()' */
void WidgetSetPushButtonConfig_OnSetIconMarginLeft( WidgetSetPushButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelFont()' */
void WidgetSetPushButtonConfig_OnSetLabelFont( WidgetSetPushButtonConfig _this, 
  ResourcesFont value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetFaceFrameActive()' */
void WidgetSetPushButtonConfig_OnSetFaceFrameActive( WidgetSetPushButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetFaceFrameFocused()' */
void WidgetSetPushButtonConfig_OnSetFaceFrameFocused( WidgetSetPushButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetFaceFrameDisabled()' */
void WidgetSetPushButtonConfig_OnSetFaceFrameDisabled( WidgetSetPushButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetFaceFrameDefault()' */
void WidgetSetPushButtonConfig_OnSetFaceFrameDefault( WidgetSetPushButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetFaceActive()' */
void WidgetSetPushButtonConfig_OnSetFaceActive( WidgetSetPushButtonConfig _this, 
  ResourcesBitmap value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetFaceFocused()' */
void WidgetSetPushButtonConfig_OnSetFaceFocused( WidgetSetPushButtonConfig _this, 
  ResourcesBitmap value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetFaceDisabled()' */
void WidgetSetPushButtonConfig_OnSetFaceDisabled( WidgetSetPushButtonConfig _this, 
  ResourcesBitmap value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetFaceDefault()' */
void WidgetSetPushButtonConfig_OnSetFaceDefault( WidgetSetPushButtonConfig _this, 
  ResourcesBitmap value );

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetWidgetMinSize()' */
void WidgetSetPushButtonConfig_OnSetWidgetMinSize( WidgetSetPushButtonConfig _this, 
  XPoint value );

#ifdef __cplusplus
  }
#endif

#endif /* _WidgetSetPushButtonConfig_H */

/* Embedded Wizard */
