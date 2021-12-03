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

#ifndef _WidgetSetToggleButtonConfig_H
#define _WidgetSetToggleButtonConfig_H

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

/* Forward declaration of the class WidgetSet::ToggleButtonConfig */
#ifndef _WidgetSetToggleButtonConfig_
  EW_DECLARE_CLASS( WidgetSetToggleButtonConfig )
#define _WidgetSetToggleButtonConfig_
#endif


/* This class implements the functionality permitting you to simply customize the 
   look and feel of a bistable 'toggle button' widget (WidgetSet::ToggleButton). 
   In the practice, you will create an instance of this class, configure its properties 
   with bitmaps, colors and other relevant attributes according to your design expectations 
   and assign such prepared configuration object to the property 'Appearance' of 
   every affected toggle button widget. Thereupon the widgets will use the configuration 
   information provided in the object.
   During its lifetime the button remains always in one of the four states: 'disabled', 
   'default', 'focused' and 'active'. The state 'disabled' is true for every not 
   available button (the property 'Enabled' of the button is 'false'). Such buttons 
   will ignore all user inputs. The state 'default' determines a button, which is 
   ready to be touched by the user or ready to become focused. As soon as the button 
   becomes focused, it switches in the state 'focused'. In this state the user can 
   activate the button by pressing a key on the keyboard. Finally, the state 'active' 
   is true, if the user actually interacts with the button (the button is pressed). 
   At the same time, the toggle button distinguishes between two further states: 
   'on' (checked) and 'off' (unchecked). With the configuration object you can specify 
   the appearance of the button for every state combination individually. For this 
   purpose you should know from which views the button is composed of:
   - 'Face' is a bitmap frame view (Views::Frame) filling per default the entire 
   background of the button. In the configuration object you can individually specify 
   for every button state combination the desired bitmap (@FaceOffActive, @FaceOffDefault, 
   @FaceOffDisabled, @FaceOffFocused, @FaceOnActive, @FaceOnDefault, @FaceOnDisabled, 
   @FaceOnFocused), the frame number within the bitmap (@FaceOffFrameActive, @FaceOffFrameDefault, 
   @FaceOffFrameDisabled, @FaceOffFrameFocused, @FaceOnFrameActive, @FaceOnFrameDefault, 
   @FaceOnFrameDisabled, @FaceOnFrameFocused) and opacity or color to tint the bitmap 
   (@FaceOffTintActive, @FaceOffTintDefault, @FaceOffTintDisabled, @FaceOffTintFocused, 
   @FaceOnTintActive, @FaceOnTintDefault, @FaceOnTintDisabled, @FaceOnTintFocused). 
   The button can automatically play animated bitmaps if the corresponding frame 
   number is -1. If desired, with the property @FaceLayout you can also configure 
   the bitmap to be arranged horizontally and vertically instead of filling the 
   entire widget area.
   - 'Icon' is an image view (Views::Image) displayed per default in the center 
   of the button. The corresponding bitmap is determined in the property 'Icon' 
   in the toggle button widget. In the configuration object you can specify the 
   alignment (@IconAlignment) and margins (@IconMarginBottom, @IconMarginLeft, @IconMarginRight, 
   @IconMarginTop) how to arrange the 'Icon' bitmap within the button area. Furthermore, 
   for every button state combination the opacity or color to tint the bitmap can 
   be determined (@IconOffTintActive, @IconOffTintDefault, @IconOffTintDisabled, 
   @IconOffTintFocused, @IconOnTintActive, @IconOnTintDefault, @IconOnTintDisabled, 
   @IconOnTintFocused).
   - 'Label' is a text view (Views::Text) displayed per default in the center of 
   the button. The corresponding text is determined in the property 'LabelOff' or 
   'LabelOn' in the toggle button widget. In the configuration object you can specify 
   the font (@LabelOffFont, @LabelOnFont), alignment (@LabelAlignment) and margins 
   (@LabelMarginBottom, @LabelMarginLeft, @LabelMarginRight, @LabelMarginTop) to 
   use for the text view. For every button state combination you can specify individual 
   text color values (@LabelOffColorActive, @LabelOffColorDefault, @LabelOffColorDisabled, 
   @LabelOffColorFocused, @LabelOnColorActive, @LabelOnColorDefault, @LabelOnColorDisabled, 
   @LabelOnColorFocused).
   If the button is actually focused, it can also be activated by pressing the keyboard 
   key specified in the property @KeyCode. To prevent the button from being able 
   to be focused, initialize this property with the value Core::KeyCode.NoKey. The 
   property @PressedFeedbackDuration configures the duration how long the button 
   should appear active (pressed) even if it has been taped for a very short time.
   With the properties @WidgetMinSize and @WidgetMaxSize you can configure size 
   constraints for the widget itself. You can, for example, limit the button to 
   not shrink below a specified width or height. */
EW_DEFINE_FIELDS( WidgetSetToggleButtonConfig, WidgetSetWidgetConfig )
  /* The property 'LabelOnFont' determines the font object used to print the text 
     specified in the property 'LabelOn' of the button widget. This text appears 
     only when the button is in the switched-on state. If no font is specified (the 
     property is 'null'), no text is displayed. */
  EW_PROPERTY( LabelOnFont,     ResourcesFont )

  /* The property 'LabelOffFont' determines the font object used to print the text 
     specified in the property 'LabelOff' of the button widget. This text appears 
     only when the button is in the switched-off state. If no font is specified 
     (the property is 'null'), no text is displayed. */
  EW_PROPERTY( LabelOffFont,    ResourcesFont )

  /* The property 'FaceOnActive' determines the bitmap to fill the background of 
     the toggle button when the button is switched-on and it is in the 'active' 
     state (the user is actually touching the button or pressing a key on the keyboard 
     the toggle button should react on).
     If the specified bitmap contains more than one frame (multi-frame bitmap), 
     the desired frame number can be selected in the property @FaceOnFrameActive. 
     If the selected bitmap is intended to be animated, ensure that the property 
     @FaceOnFrameActive is -1.
     If the specified bitmap contains opacity information only (Alpha8 bitmap), 
     you can tint the bitmap by specifying the desired color in the property @FaceOnTintActive. 
     With the property @FaceOnTintActive you can also modulate the opacity of a 
     regular bitmap.
     Per default, the actually visible face bitmap fills the entire background area 
     of the button. With the property @FaceLayout you can modify this behavior and 
     configure the bitmap to retain its original width and/or height. You can also 
     determine how the bitmap should be aligned vertically and horizontally within 
     the button area. */
  EW_PROPERTY( FaceOnActive,    ResourcesBitmap )

  /* The property 'FaceOnFocused' determines the bitmap to fill the background of 
     the toggle button when the button is switched-on and it is in the 'focused' 
     state (the button can react to keyboard events).
     If the specified bitmap contains more than one frame (multi-frame bitmap), 
     the desired frame number can be selected in the property @FaceOnFrameFocused. 
     If the selected bitmap is intended to be animated, ensure that the property 
     @FaceOnFrameFocused is -1.
     If the specified bitmap contains opacity information only (Alpha8 bitmap), 
     you can tint the bitmap by specifying the desired color in the property @FaceOnTintFocused. 
     With the property @FaceOnTintFocused you can also modulate the opacity of a 
     regular bitmap.
     Per default, the actually visible face bitmap fills the entire background area 
     of the button. With the property @FaceLayout you can modify this behavior and 
     configure the bitmap to retain its original width and/or height. You can also 
     determine how the bitmap should be aligned vertically and horizontally within 
     the button area. */
  EW_PROPERTY( FaceOnFocused,   ResourcesBitmap )

  /* The property 'FaceOnDisabled' determines the bitmap to fill the background 
     of the toggle button when the button is switched-on and it is in the 'disabled' 
     state (property 'Enabled' of the button is 'false').
     If the specified bitmap contains more than one frame (multi-frame bitmap), 
     the desired frame number can be selected in the property @FaceOnFrameDisabled. 
     If the selected bitmap is intended to be animated, ensure that the property 
     @FaceOnFrameDisabled is -1.
     If the specified bitmap contains opacity information only (Alpha8 bitmap), 
     you can tint the bitmap by specifying the desired color in the property @FaceOnTintDisabled. 
     With the property @FaceOnTintDisabled you can also modulate the opacity of 
     a regular bitmap.
     Per default, the actually visible face bitmap fills the entire background area 
     of the button. With the property @FaceLayout you can modify this behavior and 
     configure the bitmap to retain its original width and/or height. You can also 
     determine how the bitmap should be aligned vertically and horizontally within 
     the button area. */
  EW_PROPERTY( FaceOnDisabled,  ResourcesBitmap )

  /* The property 'FaceOnDefault' determines the bitmap to fill the background of 
     the toggle button when the button is switched-on and it is in the 'default' 
     state.
     If the specified bitmap contains more than one frame (multi-frame bitmap), 
     the desired frame number can be selected in the property @FaceOnFrameDefault. 
     If the selected bitmap is intended to be animated, ensure that the property 
     @FaceOnFrameDefault is -1.
     If the specified bitmap contains opacity information only (Alpha8 bitmap), 
     you can tint the bitmap by specifying the desired color in the property @FaceOnTintDefault. 
     With the property @FaceOnTintDefault you can also modulate the opacity of a 
     regular bitmap.
     Per default, the actually visible face bitmap fills the entire background area 
     of the button. With the property @FaceLayout you can modify this behavior and 
     configure the bitmap to retain its original width and/or height. You can also 
     determine how the bitmap should be aligned vertically and horizontally within 
     the button area. */
  EW_PROPERTY( FaceOnDefault,   ResourcesBitmap )

  /* The property 'FaceOffActive' determines the bitmap to fill the background of 
     the toggle button when the button is switched-off and it is in the 'active' 
     state (the user is actually touching the button or pressing a key on the keyboard 
     the toggle button should react on).
     If the specified bitmap contains more than one frame (multi-frame bitmap), 
     the desired frame number can be selected in the property @FaceOffFrameActive. 
     If the selected bitmap is intended to be animated, ensure that the property 
     @FaceOffFrameActive is -1.
     If the specified bitmap contains opacity information only (Alpha8 bitmap), 
     you can tint the bitmap by specifying the desired color in the property @FaceOffTintActive. 
     With the property @FaceOffTintActive you can also modulate the opacity of a 
     regular bitmap.
     Per default, the actually visible face bitmap fills the entire background area 
     of the button. With the property @FaceLayout you can modify this behavior and 
     configure the bitmap to retain its original width and/or height. You can also 
     determine how the bitmap should be aligned vertically and horizontally within 
     the button area. */
  EW_PROPERTY( FaceOffActive,   ResourcesBitmap )

  /* The property 'FaceOffFocused' determines the bitmap to fill the background 
     of the toggle button when the button is switched-off and it is in the 'focused' 
     state (the button can react to keyboard events).
     If the specified bitmap contains more than one frame (multi-frame bitmap), 
     the desired frame number can be selected in the property @FaceOffFrameFocused. 
     If the selected bitmap is intended to be animated, ensure that the property 
     @FaceOffFrameFocused is -1.
     If the specified bitmap contains opacity information only (Alpha8 bitmap), 
     you can tint the bitmap by specifying the desired color in the property @FaceOffTintFocused. 
     With the property @FaceOffTintFocused you can also modulate the opacity of 
     a regular bitmap.
     Per default, the actually visible face bitmap fills the entire background area 
     of the button. With the property @FaceLayout you can modify this behavior and 
     configure the bitmap to retain its original width and/or height. You can also 
     determine how the bitmap should be aligned vertically and horizontally within 
     the button area. */
  EW_PROPERTY( FaceOffFocused,  ResourcesBitmap )

  /* The property 'FaceOffDisabled' determines the bitmap to fill the background 
     of the toggle button when the button is switched-off and it is in the 'disabled' 
     state (property 'Enabled' of the button is 'false').
     If the specified bitmap contains more than one frame (multi-frame bitmap), 
     the desired frame number can be selected in the property @FaceOffFrameDisabled. 
     If the selected bitmap is intended to be animated, ensure that the property 
     @FaceOffFrameDisabled is -1.
     If the specified bitmap contains opacity information only (Alpha8 bitmap), 
     you can tint the bitmap by specifying the desired color in the property @FaceOffTintDisabled. 
     With the property @FaceOffTintDisabled you can also modulate the opacity of 
     a regular bitmap.
     Per default, the actually visible face bitmap fills the entire background area 
     of the button. With the property @FaceLayout you can modify this behavior and 
     configure the bitmap to retain its original width and/or height. You can also 
     determine how the bitmap should be aligned vertically and horizontally within 
     the button area. */
  EW_PROPERTY( FaceOffDisabled, ResourcesBitmap )

  /* The property 'FaceOffDefault' determines the bitmap to fill the background 
     of the toggle button when the button is switched-off and it is in the 'default' 
     state.
     If the specified bitmap contains more than one frame (multi-frame bitmap), 
     the desired frame number can be selected in the property @FaceOffFrameDefault. 
     If the selected bitmap is intended to be animated, ensure that the property 
     @FaceOffFrameDefault is -1.
     If the specified bitmap contains opacity information only (Alpha8 bitmap), 
     you can tint the bitmap by specifying the desired color in the property @FaceOffTintDefault. 
     With the property @FaceOffTintDefault you can also modulate the opacity of 
     a regular bitmap.
     Per default, the actually visible face bitmap fills the entire background area 
     of the button. With the property @FaceLayout you can modify this behavior and 
     configure the bitmap to retain its original width and/or height. You can also 
     determine how the bitmap should be aligned vertically and horizontally within 
     the button area. */
  EW_PROPERTY( FaceOffDefault,  ResourcesBitmap )

  /* The property 'LabelOnColorActive' determines the color value to use when the 
     text specified in the property 'LabelOn' of the button widget is displayed 
     and the button is switched-on and it is in the 'active' state (the user is 
     actually touching the button or pressing a key on the keyboard the toggle button 
     should react on). */
  EW_PROPERTY( LabelOnColorActive, XColor )

  /* The property 'LabelOnColorFocused' determines the color value to use when the 
     text specified in the property 'LabelOn' of the button widget is displayed 
     and the button is switched-on and it is in the 'focused' state (the button 
     can react to keyboard events). */
  EW_PROPERTY( LabelOnColorFocused, XColor )

  /* The property 'LabelOnColorDisabled' determines the color value to use when 
     the text specified in the property 'LabelOn' of the button widget is displayed 
     and the button is switched-on and it is in the 'disabled' state (property 'Enabled' 
     of the button is 'false'). */
  EW_PROPERTY( LabelOnColorDisabled, XColor )

  /* The property 'LabelOnColorDefault' determines the color value to use when the 
     text specified in the property 'LabelOn' of the button widget is displayed 
     and the button is switched-on and it is in the 'default' state. */
  EW_PROPERTY( LabelOnColorDefault, XColor )

  /* The property 'LabelOffColorActive' determines the color value to use when the 
     text specified in the property 'LabelOff' of the button widget is displayed 
     and the button is switched-off and it is in the 'active' state (the user is 
     actually touching the button or pressing a key on the keyboard the toggle button 
     should react on). */
  EW_PROPERTY( LabelOffColorActive, XColor )

  /* The property 'LabelOffColorFocused' determines the color value to use when 
     the text specified in the property 'LabelOff' of the button widget is displayed 
     and the button is switched-off and it is in the 'focused' state (the button 
     can react to keyboard events). */
  EW_PROPERTY( LabelOffColorFocused, XColor )

  /* The property 'LabelOffColorDisabled' determines the color value to use when 
     the text specified in the property 'LabelOff' of the button widget is displayed 
     and the button is switched-off and it is in the 'disabled' state (property 
     'Enabled' of the button is 'false'). */
  EW_PROPERTY( LabelOffColorDisabled, XColor )

  /* The property 'LabelOffColorDefault' determines the color value to use when 
     the text specified in the property 'LabelOff' of the button widget is displayed 
     and the button is switched-off and it is in the 'default' state. */
  EW_PROPERTY( LabelOffColorDefault, XColor )

  /* The property 'LabelMarginRight' determines the gap on the right of the area 
     destined to display the label text relative to the right edge of the button 
     itself. */
  EW_PROPERTY( LabelMarginRight, XInt32 )

  /* The property 'IconOnTintActive' determines the color value to tint or modulate 
     the bitmap specified in the property 'Icon' of the button widget if the button 
     is switched-on and it is in the 'active' state (the user is actually touching 
     the button or pressing a key on the keyboard the toggle button should react 
     on). The effect of this color value depends on the type of the bitmap:
     - Alpha8 bitmaps will be tinted with the given color due to the fact that they 
     don't provide their own color information. This allows one and the same Alpha8 
     bitmap to be shown with different colors.
     - In case of Native, Index8 or RGB565 bitmaps the opacity of the bitmap is 
     modulated by the color's alpha value. The original RGB information stored in 
     the bitmap is not affected. This allows one and the same bitmap to be shown 
     with different transparencies. */
  EW_PROPERTY( IconOnTintActive, XColor )

  /* The property 'IconOnTintFocused' determines the color value to tint or modulate 
     the bitmap specified in the property 'Icon' of the button widget if the button 
     is switched-on and it is in the 'focused' state (the button can react to keyboard 
     events). The effect of this color value depends on the type of the bitmap:
     - Alpha8 bitmaps will be tinted with the given color due to the fact that they 
     don't provide their own color information. This allows one and the same Alpha8 
     bitmap to be shown with different colors.
     - In case of Native, Index8 or RGB565 bitmaps the opacity of the bitmap is 
     modulated by the color's alpha value. The original RGB information stored in 
     the bitmap is not affected. This allows one and the same bitmap to be shown 
     with different transparencies. */
  EW_PROPERTY( IconOnTintFocused, XColor )

  /* The property 'IconOnTintDisabled' determines the color value to tint or modulate 
     the bitmap specified in the property 'Icon' of the button widget if the button 
     is switched-on and it is in the 'disabled' state (property 'Enabled' of the 
     button is 'false'). The effect of this color value depends on the type of the 
     bitmap:
     - Alpha8 bitmaps will be tinted with the given color due to the fact that they 
     don't provide their own color information. This allows one and the same Alpha8 
     bitmap to be shown with different colors.
     - In case of Native, Index8 or RGB565 bitmaps the opacity of the bitmap is 
     modulated by the color's alpha value. The original RGB information stored in 
     the bitmap is not affected. This allows one and the same bitmap to be shown 
     with different transparencies. */
  EW_PROPERTY( IconOnTintDisabled, XColor )

  /* The property 'IconOnTintDefault' determines the color value to tint or modulate 
     the bitmap specified in the property 'Icon' of the button widget if the button 
     is switched-on and it is in the 'default' state. The effect of this color value 
     depends on the type of the bitmap:
     - Alpha8 bitmaps will be tinted with the given color due to the fact that they 
     don't provide their own color information. This allows one and the same Alpha8 
     bitmap to be shown with different colors.
     - In case of Native, Index8 or RGB565 bitmaps the opacity of the bitmap is 
     modulated by the color's alpha value. The original RGB information stored in 
     the bitmap is not affected. This allows one and the same bitmap to be shown 
     with different transparencies. */
  EW_PROPERTY( IconOnTintDefault, XColor )

  /* The property 'IconOffTintActive' determines the color value to tint or modulate 
     the bitmap specified in the property 'Icon' of the button widget if the button 
     is switched-off and it is in the 'active' state (the user is actually touching 
     the button or pressing a key on the keyboard the toggle button should react 
     on). The effect of this color value depends on the type of the bitmap:
     - Alpha8 bitmaps will be tinted with the given color due to the fact that they 
     don't provide their own color information. This allows one and the same Alpha8 
     bitmap to be shown with different colors.
     - In case of Native, Index8 or RGB565 bitmaps the opacity of the bitmap is 
     modulated by the color's alpha value. The original RGB information stored in 
     the bitmap is not affected. This allows one and the same bitmap to be shown 
     with different transparencies. */
  EW_PROPERTY( IconOffTintActive, XColor )

  /* The property 'IconOffTintFocused' determines the color value to tint or modulate 
     the bitmap specified in the property 'Icon' of the button widget if the button 
     is switched-off and it is in the 'focused' state (the button can react to keyboard 
     events). The effect of this color value depends on the type of the bitmap:
     - Alpha8 bitmaps will be tinted with the given color due to the fact that they 
     don't provide their own color information. This allows one and the same Alpha8 
     bitmap to be shown with different colors.
     - In case of Native, Index8 or RGB565 bitmaps the opacity of the bitmap is 
     modulated by the color's alpha value. The original RGB information stored in 
     the bitmap is not affected. This allows one and the same bitmap to be shown 
     with different transparencies. */
  EW_PROPERTY( IconOffTintFocused, XColor )

  /* The property 'IconOffTintDisabled' determines the color value to tint or modulate 
     the bitmap specified in the property 'Icon' of the button widget if the button 
     is switched-off and it is in the 'disabled' state (property 'Enabled' of the 
     button is 'false'). The effect of this color value depends on the type of the 
     bitmap:
     - Alpha8 bitmaps will be tinted with the given color due to the fact that they 
     don't provide their own color information. This allows one and the same Alpha8 
     bitmap to be shown with different colors.
     - In case of Native, Index8 or RGB565 bitmaps the opacity of the bitmap is 
     modulated by the color's alpha value. The original RGB information stored in 
     the bitmap is not affected. This allows one and the same bitmap to be shown 
     with different transparencies. */
  EW_PROPERTY( IconOffTintDisabled, XColor )

  /* The property 'IconOffTintDefault' determines the color value to tint or modulate 
     the bitmap specified in the property 'Icon' of the button widget if the button 
     is switched-off and it is in the 'default' state. The effect of this color 
     value depends on the type of the bitmap:
     - Alpha8 bitmaps will be tinted with the given color due to the fact that they 
     don't provide their own color information. This allows one and the same Alpha8 
     bitmap to be shown with different colors.
     - In case of Native, Index8 or RGB565 bitmaps the opacity of the bitmap is 
     modulated by the color's alpha value. The original RGB information stored in 
     the bitmap is not affected. This allows one and the same bitmap to be shown 
     with different transparencies. */
  EW_PROPERTY( IconOffTintDefault, XColor )

  /* The property 'IconMarginRight' determines the gap on the right of the area 
     destined to display the icon bitmap relative to the right edge of the button 
     itself. */
  EW_PROPERTY( IconMarginRight, XInt32 )

  /* The property 'LabelAlignment' determines how the text specified in the properties 
     'LabelOff' and 'LabelOn' of the button widget should be aligned.
     Per default, the label is aligned within the entire button area. By using the 
     properties @LabelMarginLeft, @LabelMarginRight, @LabelMarginTop and @LabelMarginBottom 
     you can limit the area as desired. */
  EW_PROPERTY( LabelAlignment,  XSet )

  /* The property 'IconAlignment' determines how the bitmap specified in the property 
     'Icon' of the button widget should be aligned.
     Per default, the icon is aligned within the entire button area. By using the 
     properties @IconMarginLeft, @IconMarginRight, @IconMarginTop and @IconMarginBottom 
     you can limit the area as desired. */
  EW_PROPERTY( IconAlignment,   XSet )

  /* The property 'FaceLayout' determines the constraints how the actually displayed 
     face bitmap (@FaceOffActive, @FaceOffDefault, @FaceOffDisabled, @FaceOffFocused, 
     @FaceOnActive, @FaceOnDefault, @FaceOnDisabled or @FaceOnFocused) should be 
     aligned within the button area. Per default the bitmap fills the button widget 
     entirely.
     The constraints 'ResizeVert' and 'ResizeHorz' determine whether the bitmap 
     should be resized to fill the button vertically and/or horizontally. Deactivating 
     the constraint causes the button to display the bitmap with its original height 
     and/or width. In such case you can configure with the constraints 'AlignToTop', 
     'AlignToBottom', 'AlignToLeft' and 'AlignToRight' how the bitmap should be 
     aligned within the button area. */
  EW_PROPERTY( FaceLayout,      XSet )

  /* The property 'FaceOnFrameActive' determines the frame number within the bitmap 
     @FaceOnActive. This property is applicable for multi-frame bitmaps only (see 
     also Resources::Bitmap). If the desired frame is not available in the bitmap, 
     no bitmap is shown.
     If the property is initialized with the value -1 and the @FaceOnActive bitmap 
     is animated, the animation is automatically started as soon as the button enters 
     the 'active' state. If the bitmap is not animated and the property is -1, the 
     frame with number 0 is displayed. */
  EW_PROPERTY( FaceOnFrameActive, XInt32 )

  /* The property 'FaceOnFrameFocused' determines the frame number within the bitmap 
     @FaceOnFocused. This property is applicable for multi-frame bitmaps only (see 
     also Resources::Bitmap). If the desired frame is not available in the bitmap, 
     no bitmap is shown.
     If the property is initialized with the value -1 and the @FaceOnFocused bitmap 
     is animated, the animation is automatically started as soon as the button enters 
     the 'focused' state. If the bitmap is not animated and the property is -1, 
     the frame with number 0 is displayed. */
  EW_PROPERTY( FaceOnFrameFocused, XInt32 )

  /* The property 'FaceOnFrameDisabled' determines the frame number within the bitmap 
     @FaceOnDisabled. This property is applicable for multi-frame bitmaps only (see 
     also Resources::Bitmap). If the desired frame is not available in the bitmap, 
     no bitmap is shown.
     If the property is initialized with the value -1 and the @FaceOnDisabled bitmap 
     is animated, the animation is automatically started as soon as the button enters 
     the 'disabled' state. If the bitmap is not animated and the property is -1, 
     the frame with number 0 is displayed. */
  EW_PROPERTY( FaceOnFrameDisabled, XInt32 )

  /* The property 'FaceOnFrameDefault' determines the frame number within the bitmap 
     @FaceOnDefault. This property is applicable for multi-frame bitmaps only (see 
     also Resources::Bitmap). If the desired frame is not available in the bitmap, 
     no bitmap is shown.
     If the property is initialized with the value -1 and the @FaceOnDefault bitmap 
     is animated, the animation is automatically started as soon as the button enters 
     the 'default' state. If the bitmap is not animated and the property is -1, 
     the frame with number 0 is displayed. */
  EW_PROPERTY( FaceOnFrameDefault, XInt32 )

  /* The property 'FaceOffFrameActive' determines the frame number within the bitmap 
     @FaceOffActive. This property is applicable for multi-frame bitmaps only (see 
     also Resources::Bitmap). If the desired frame is not available in the bitmap, 
     no bitmap is shown.
     If the property is initialized with the value -1 and the @FaceOffActive bitmap 
     is animated, the animation is automatically started as soon as the button enters 
     the 'active' state. If the bitmap is not animated and the property is -1, the 
     frame with number 0 is displayed. */
  EW_PROPERTY( FaceOffFrameActive, XInt32 )

  /* The property 'FaceOffFrameFocused' determines the frame number within the bitmap 
     @FaceOffFocused. This property is applicable for multi-frame bitmaps only (see 
     also Resources::Bitmap). If the desired frame is not available in the bitmap, 
     no bitmap is shown.
     If the property is initialized with the value -1 and the @FaceOffFocused bitmap 
     is animated, the animation is automatically started as soon as the button enters 
     the 'focused' state. If the bitmap is not animated and the property is -1, 
     the frame with number 0 is displayed. */
  EW_PROPERTY( FaceOffFrameFocused, XInt32 )

  /* The property 'FaceOffFrameDisabled' determines the frame number within the 
     bitmap @FaceOffDisabled. This property is applicable for multi-frame bitmaps 
     only (see also Resources::Bitmap). If the desired frame is not available in 
     the bitmap, no bitmap is shown.
     If the property is initialized with the value -1 and the @FaceOffDisabled bitmap 
     is animated, the animation is automatically started as soon as the button enters 
     the 'disabled' state. If the bitmap is not animated and the property is -1, 
     the frame with number 0 is displayed. */
  EW_PROPERTY( FaceOffFrameDisabled, XInt32 )

  /* The property 'FaceOffFrameDefault' determines the frame number within the bitmap 
     @FaceOffDefault. This property is applicable for multi-frame bitmaps only (see 
     also Resources::Bitmap). If the desired frame is not available in the bitmap, 
     no bitmap is shown.
     If the property is initialized with the value -1 and the @FaceOffDefault bitmap 
     is animated, the animation is automatically started as soon as the button enters 
     the 'default' state. If the bitmap is not animated and the property is -1, 
     the frame with number 0 is displayed. */
  EW_PROPERTY( FaceOffFrameDefault, XInt32 )

  /* The property 'WidgetMinSize' determines the minimal allowed size of the widget. 
     Accordingly, the button can't become smaller than the value specified in this 
     property. By using this property you can configure the size constraints for 
     the button. */
  EW_PROPERTY( WidgetMinSize,   XPoint )
EW_END_OF_FIELDS( WidgetSetToggleButtonConfig )

/* Virtual Method Table (VMT) for the class : 'WidgetSet::ToggleButtonConfig' */
EW_DEFINE_METHODS( WidgetSetToggleButtonConfig, WidgetSetWidgetConfig )
EW_END_OF_METHODS( WidgetSetToggleButtonConfig )

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOnColorActive()' */
void WidgetSetToggleButtonConfig_OnSetLabelOnColorActive( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOnColorFocused()' */
void WidgetSetToggleButtonConfig_OnSetLabelOnColorFocused( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOnColorDisabled()' */
void WidgetSetToggleButtonConfig_OnSetLabelOnColorDisabled( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOnColorDefault()' */
void WidgetSetToggleButtonConfig_OnSetLabelOnColorDefault( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOffColorActive()' */
void WidgetSetToggleButtonConfig_OnSetLabelOffColorActive( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOffColorFocused()' */
void WidgetSetToggleButtonConfig_OnSetLabelOffColorFocused( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOffColorDisabled()' */
void WidgetSetToggleButtonConfig_OnSetLabelOffColorDisabled( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOffColorDefault()' */
void WidgetSetToggleButtonConfig_OnSetLabelOffColorDefault( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelMarginRight()' */
void WidgetSetToggleButtonConfig_OnSetLabelMarginRight( WidgetSetToggleButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconOnTintActive()' */
void WidgetSetToggleButtonConfig_OnSetIconOnTintActive( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconOnTintFocused()' */
void WidgetSetToggleButtonConfig_OnSetIconOnTintFocused( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconOnTintDisabled()' */
void WidgetSetToggleButtonConfig_OnSetIconOnTintDisabled( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconOnTintDefault()' */
void WidgetSetToggleButtonConfig_OnSetIconOnTintDefault( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconOffTintActive()' */
void WidgetSetToggleButtonConfig_OnSetIconOffTintActive( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconOffTintFocused()' */
void WidgetSetToggleButtonConfig_OnSetIconOffTintFocused( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconOffTintDisabled()' */
void WidgetSetToggleButtonConfig_OnSetIconOffTintDisabled( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconOffTintDefault()' */
void WidgetSetToggleButtonConfig_OnSetIconOffTintDefault( WidgetSetToggleButtonConfig _this, 
  XColor value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconMarginRight()' */
void WidgetSetToggleButtonConfig_OnSetIconMarginRight( WidgetSetToggleButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelAlignment()' */
void WidgetSetToggleButtonConfig_OnSetLabelAlignment( WidgetSetToggleButtonConfig _this, 
  XSet value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOnFont()' */
void WidgetSetToggleButtonConfig_OnSetLabelOnFont( WidgetSetToggleButtonConfig _this, 
  ResourcesFont value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOffFont()' */
void WidgetSetToggleButtonConfig_OnSetLabelOffFont( WidgetSetToggleButtonConfig _this, 
  ResourcesFont value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconAlignment()' */
void WidgetSetToggleButtonConfig_OnSetIconAlignment( WidgetSetToggleButtonConfig _this, 
  XSet value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceLayout()' */
void WidgetSetToggleButtonConfig_OnSetFaceLayout( WidgetSetToggleButtonConfig _this, 
  XSet value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOnFrameActive()' */
void WidgetSetToggleButtonConfig_OnSetFaceOnFrameActive( WidgetSetToggleButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOnFrameFocused()' */
void WidgetSetToggleButtonConfig_OnSetFaceOnFrameFocused( WidgetSetToggleButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOnFrameDisabled()' */
void WidgetSetToggleButtonConfig_OnSetFaceOnFrameDisabled( WidgetSetToggleButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOnFrameDefault()' */
void WidgetSetToggleButtonConfig_OnSetFaceOnFrameDefault( WidgetSetToggleButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOnActive()' */
void WidgetSetToggleButtonConfig_OnSetFaceOnActive( WidgetSetToggleButtonConfig _this, 
  ResourcesBitmap value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOnFocused()' */
void WidgetSetToggleButtonConfig_OnSetFaceOnFocused( WidgetSetToggleButtonConfig _this, 
  ResourcesBitmap value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOnDisabled()' */
void WidgetSetToggleButtonConfig_OnSetFaceOnDisabled( WidgetSetToggleButtonConfig _this, 
  ResourcesBitmap value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOnDefault()' */
void WidgetSetToggleButtonConfig_OnSetFaceOnDefault( WidgetSetToggleButtonConfig _this, 
  ResourcesBitmap value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOffFrameActive()' */
void WidgetSetToggleButtonConfig_OnSetFaceOffFrameActive( WidgetSetToggleButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOffFrameFocused()' */
void WidgetSetToggleButtonConfig_OnSetFaceOffFrameFocused( WidgetSetToggleButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOffFrameDisabled()' */
void WidgetSetToggleButtonConfig_OnSetFaceOffFrameDisabled( WidgetSetToggleButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOffFrameDefault()' */
void WidgetSetToggleButtonConfig_OnSetFaceOffFrameDefault( WidgetSetToggleButtonConfig _this, 
  XInt32 value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOffActive()' */
void WidgetSetToggleButtonConfig_OnSetFaceOffActive( WidgetSetToggleButtonConfig _this, 
  ResourcesBitmap value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOffFocused()' */
void WidgetSetToggleButtonConfig_OnSetFaceOffFocused( WidgetSetToggleButtonConfig _this, 
  ResourcesBitmap value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOffDisabled()' */
void WidgetSetToggleButtonConfig_OnSetFaceOffDisabled( WidgetSetToggleButtonConfig _this, 
  ResourcesBitmap value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOffDefault()' */
void WidgetSetToggleButtonConfig_OnSetFaceOffDefault( WidgetSetToggleButtonConfig _this, 
  ResourcesBitmap value );

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetWidgetMinSize()' */
void WidgetSetToggleButtonConfig_OnSetWidgetMinSize( WidgetSetToggleButtonConfig _this, 
  XPoint value );

#ifdef __cplusplus
  }
#endif

#endif /* _WidgetSetToggleButtonConfig_H */

/* Embedded Wizard */
