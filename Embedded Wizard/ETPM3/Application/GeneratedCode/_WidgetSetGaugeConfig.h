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

#ifndef _WidgetSetGaugeConfig_H
#define _WidgetSetGaugeConfig_H

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

/* Forward declaration of the class WidgetSet::GaugeConfig */
#ifndef _WidgetSetGaugeConfig_
  EW_DECLARE_CLASS( WidgetSetGaugeConfig )
#define _WidgetSetGaugeConfig_
#endif


/* This class implements the functionality permitting you to simply customize the 
   look and feel of a 'gauge' widget (WidgetSet::Gauge). In the practice, you will 
   create an instance of this class, configure its properties with bitmaps, colors 
   and other relevant attributes according to your design expectations and assign 
   such prepared configuration object to the property 'Appearance' of every affected 
   gauge widget. Thereupon the widgets will use the configuration information provided 
   in the object.
   Since with the configuration object you determine the appearance of the gauge 
   you should know from which views the gauge is composed of:
   - 'Scale' is an image view (Views::Image) displayed centered in the background 
   within the widget area. In the configuration object you can specify the desired 
   bitmap (@Scale), the frame number within the bitmap (@ScaleFrame) and opacity 
   or color to tint the bitmap (@ScaleTint). The gauge widget can automatically 
   play animated bitmaps if the specified frame number is -1.
   - 'TrackLeft' is a vector graphic view (Views::FillPath) displaying a circle 
   segment between the needle's leftmost position (clockwise) and its actual position. 
   From this results the effect of a track behind the needle. You can configure 
   the track radius (@TrackLeftRadius), its thickness (@TrackLeftThickness), color 
   (@TrackLeftColor) and the appearance of its caps (@TrackLeftRoundedStart and 
   @TrackLeftRoundedEnd).
   - 'TrackRight' is a vector graphic view (Views::FillPath) displaying a circle 
   segment between the actual position of the needle and its rightmost position 
   (clockwise). From this results the effect of a track behind the needle. You can 
   configure the track radius (@TrackRightRadius), its thickness (@TrackRightThickness), 
   color (@TrackRightColor) and the appearance of its caps (@TrackRightRoundedStart 
   and @TrackRightRoundedEnd).
   - 'Needle' is a warp image view (Views::WarpImage) displayed and rotated around 
   predetermined pivot position and along a circle segment with given radius. In 
   the configuration object you can specify the desired bitmap (@Needle), the frame 
   number within the bitmap (@NeedleFrame) and opacity or color to tint the bitmap 
   (@NeedleTint). The desired rotation range (the angles corresponding to 'MinValue' 
   and 'MaxValue' specified in the gauge widget) are determined in the properties 
   @NeedleMinAngle and @NeedleMaxAngle. The position around it the needle is rotated 
   is determined in the properties @CenterOffset, @NeedleRadius and @NeedlePivot. 
   With the property @NeedleRotate you control whether the bitmap should appear 
   rotated or only moved along the circle segment. The gauge widget can automatically 
   play animated bitmaps if the specified frame number is -1.
   - 'Cover' is an image view (Views::Image) displayed centered within the widget 
   area and covering so eventually the scale and needle images. In the configuration 
   object you can specify the desired bitmap (@Cover), the frame number within the 
   bitmap (@CoverFrame) and opacity or color to tint the bitmap (@CoverTint). The 
   gauge widget can automatically play animated bitmaps if the specified frame number 
   is -1.
   The gauge widget can rotate the needle with a smooth animation. This can be configured 
   in the properties @SwingDuration and @SwingElastic.
   With the properties @WidgetMinSize and @WidgetMaxSize you can configure size 
   constraints for the widget itself. You can, for example, limit the gauge to not 
   shrink below a specified width or height. */
EW_DEFINE_FIELDS( WidgetSetGaugeConfig, WidgetSetWidgetConfig )
  /* The property 'Needle' determines the bitmap to display rotated around the center 
     of the gauge widget. It serves as the pointer in the analog display.
     If the specified bitmap contains more than one frame (multi-frame bitmap), 
     the desired frame number can be selected in the property @NeedleFrame. If the 
     selected bitmap is intended to be animated, ensure that the property @NeedleFrame 
     is -1.
     If the specified bitmap contains opacity information only (Alpha8 bitmap), 
     you can tint the bitmap by specifying the desired color in the property @NeedleTint. 
     With the property @NeedleTint you can also modulate the opacity of a regular 
     bitmap.
     With the properties @CenterOffset, @NeedleRadius and @NeedlePivot you adjust 
     the position around it the needle bitmap should rotate. The possible rotation 
     range is determined by the properties @NeedleMinAngle and @NeedleMaxAngle. 
     To simplify the configuration of @NeedleMinAngle and @NeedleMaxAngle we recommend 
     to design the needle bitmap for 0 degrees rotation relative to the positive 
     X-axis. */
  EW_PROPERTY( Needle,          ResourcesBitmap )

  /* The property 'Scale' determines the bitmap to display centered in the background 
     of the gauge widget.
     If the specified bitmap contains more than one frame (multi-frame bitmap), 
     the desired frame number can be selected in the property @ScaleFrame. If the 
     selected bitmap is intended to be animated, ensure that the property @ScaleFrame 
     is -1.
     If the specified bitmap contains opacity information only (Alpha8 bitmap), 
     you can tint the bitmap by specifying the desired color in the property @ScaleTint. 
     With the property @ScaleTint you can also modulate the opacity of a regular 
     bitmap. */
  EW_PROPERTY( Scale,           ResourcesBitmap )

  /* The property 'SwingDuration' determines the time in milliseconds the gauge 
     widget should take when repositioning the needle between the both end positions 
     @NeedleMinAngle and @NeedleMaxAngle. At the runtime, when the needle is rotated, 
     the rotation is performed with a smooth animation.
     Initializing this property with the value 0 (zero) deactivates the animation 
     effect so that the rotation angle of the needle is adapted immediately when 
     the corresponding value in the gauge widget changes.
     If enabled, the animation is performed with the FastIn_EasyOut or BackOut timing 
     (see Effects::Timing) depending on the configuration of the property @SwingElastic. */
  EW_PROPERTY( SwingDuration,   XInt32 )

  /* The property 'TrackLeftColor' determines the color of the circle segment displayed 
     on the left (clockwise) of the actual needle position. See also @TrackLeftRadius, 
     @TrackLeftThickness, @TrackLeftRoundedEnd and @TrackLeftRoundedStart. */
  EW_PROPERTY( TrackLeftColor,  XColor )

  /* The property 'TrackLeftThickness' specifies the thickness of the circle segment 
     displayed on the left (clockwise) of the actual needle position. The radius 
     of the track is determined in the property @TrackLeftRadius.
     The center of the circle segment corresponds to the position around which the 
     needle is rotated (@CenterOffset). See also @TrackLeftColor, @TrackLeftRoundedEnd 
     and @TrackLeftRoundedStart. */
  EW_PROPERTY( TrackLeftThickness, XFloat )

  /* The property 'TrackLeftRadius' specifies the radius of the circle segment displayed 
     on the left (clockwise) of the actual needle position. The thickness of the 
     track is determined in the property @TrackLeftThickness.
     The center of the circle segment corresponds to the position around which the 
     needle is rotated (@CenterOffset). See also @TrackLeftColor, @TrackLeftRoundedEnd 
     and @TrackLeftRoundedStart. */
  EW_PROPERTY( TrackLeftRadius, XFloat )

  /* The property 'NeedleMaxAngle' determines the rotation angle for the needle 
     bitmap (@Needle) corresponding to 'MaxValue' specified in the gauge widget. 
     The angle is expressed in degree, counted counterclockwise with 0 degree at 
     the positive X-axis.
     Please note, the value specified in 'NeedleMaxAngle' has to be less than the 
     value specified in @NeedleMinAngle. */
  EW_PROPERTY( NeedleMaxAngle,  XFloat )

  /* The property 'NeedleMinAngle' determines the rotation angle for the needle 
     bitmap (@Needle) corresponding to 'MinValue' specified in the gauge widget. 
     The angle is expressed in degree, counted counterclockwise with 0 degree at 
     the positive X-axis.
     Please note, the value specified in 'NeedleMinAngle' has to be greater than 
     the value specified in @NeedleMaxAngle. */
  EW_PROPERTY( NeedleMinAngle,  XFloat )

  /* The property 'NeedlePivot' specifies the pivot position (the anchor) in the 
     needle bitmap (@Needle) around it the bitmap should be rotated. The position 
     is expressed in pixel relative to the top-left corner of the needle bitmap.
     Please note, we recommend to design the needle bitmap for 0 degrees rotation 
     relative to the positive X-axis. See also @NeedleRadius, @NeedleRotate and 
     @CenterOffset. */
  EW_PROPERTY( NeedlePivot,     XPoint )

  /* The property 'CenterOffset' determines the displacement in pixel for the position 
     around it the needle bitmap (@Needle) should rotate. Per default, the needle 
     is rotated around the center of widget. By specifying a value for the property 
     'CenterOffset' this position moves accordingly - always relative to center 
     of the widget. */
  EW_PROPERTY( CenterOffset,    XPoint )

  /* The property 'WidgetMinSize' determines the minimal allowed size of the gauge 
     widget. Accordingly, the widget can't become smaller than the value specified 
     in this property. By using this property you can configure the size constraints 
     for the gauge widget. */
  EW_PROPERTY( WidgetMinSize,   XPoint )

  /* The property 'TrackLeftRoundedStart' determines the appearance at the beginning 
     of the left track (corresponding to the leftmost rotation position (clockwise) 
     of the needle). If this property is 'true', the cap at the track begin is rounded 
     otherwise it is straight. See also @TrackLeftRadius, @TrackLeftThickness, @TrackLeftColor, 
     @TrackLeftRoundedEnd. */
  EW_PROPERTY( TrackLeftRoundedStart, XBool )

  /* The property 'SwingElastic' controls the timing of the animation effect used 
     to smoothly rotate the needle when the value in the gauge widget changes. This 
     animation is enabled when the property @SwingDuration is greater than 0 (zero).
     Initializing the property 'SwingElastic' with the value 'false' causes the 
     animation to be performed with the FastIn_EaseOut timing. If the property is 
     'true', the animation is performed with the BackOut timing resulting in the 
     animation to be more elastic. See also Effects::Timing. */
  EW_PROPERTY( SwingElastic,    XBool )
EW_END_OF_FIELDS( WidgetSetGaugeConfig )

/* Virtual Method Table (VMT) for the class : 'WidgetSet::GaugeConfig' */
EW_DEFINE_METHODS( WidgetSetGaugeConfig, WidgetSetWidgetConfig )
EW_END_OF_METHODS( WidgetSetGaugeConfig )

/* 'C' function for method : 'WidgetSet::GaugeConfig.OnSetSwingElastic()' */
void WidgetSetGaugeConfig_OnSetSwingElastic( WidgetSetGaugeConfig _this, XBool value );

/* 'C' function for method : 'WidgetSet::GaugeConfig.OnSetSwingDuration()' */
void WidgetSetGaugeConfig_OnSetSwingDuration( WidgetSetGaugeConfig _this, XInt32 
  value );

/* 'C' function for method : 'WidgetSet::GaugeConfig.OnSetTrackLeftRoundedStart()' */
void WidgetSetGaugeConfig_OnSetTrackLeftRoundedStart( WidgetSetGaugeConfig _this, 
  XBool value );

/* 'C' function for method : 'WidgetSet::GaugeConfig.OnSetTrackLeftColor()' */
void WidgetSetGaugeConfig_OnSetTrackLeftColor( WidgetSetGaugeConfig _this, XColor 
  value );

/* 'C' function for method : 'WidgetSet::GaugeConfig.OnSetTrackLeftThickness()' */
void WidgetSetGaugeConfig_OnSetTrackLeftThickness( WidgetSetGaugeConfig _this, XFloat 
  value );

/* 'C' function for method : 'WidgetSet::GaugeConfig.OnSetTrackLeftRadius()' */
void WidgetSetGaugeConfig_OnSetTrackLeftRadius( WidgetSetGaugeConfig _this, XFloat 
  value );

/* 'C' function for method : 'WidgetSet::GaugeConfig.OnSetNeedleMaxAngle()' */
void WidgetSetGaugeConfig_OnSetNeedleMaxAngle( WidgetSetGaugeConfig _this, XFloat 
  value );

/* 'C' function for method : 'WidgetSet::GaugeConfig.OnSetNeedleMinAngle()' */
void WidgetSetGaugeConfig_OnSetNeedleMinAngle( WidgetSetGaugeConfig _this, XFloat 
  value );

/* 'C' function for method : 'WidgetSet::GaugeConfig.OnSetNeedlePivot()' */
void WidgetSetGaugeConfig_OnSetNeedlePivot( WidgetSetGaugeConfig _this, XPoint value );

/* 'C' function for method : 'WidgetSet::GaugeConfig.OnSetNeedle()' */
void WidgetSetGaugeConfig_OnSetNeedle( WidgetSetGaugeConfig _this, ResourcesBitmap 
  value );

/* 'C' function for method : 'WidgetSet::GaugeConfig.OnSetCenterOffset()' */
void WidgetSetGaugeConfig_OnSetCenterOffset( WidgetSetGaugeConfig _this, XPoint 
  value );

/* 'C' function for method : 'WidgetSet::GaugeConfig.OnSetScale()' */
void WidgetSetGaugeConfig_OnSetScale( WidgetSetGaugeConfig _this, ResourcesBitmap 
  value );

/* 'C' function for method : 'WidgetSet::GaugeConfig.OnSetWidgetMinSize()' */
void WidgetSetGaugeConfig_OnSetWidgetMinSize( WidgetSetGaugeConfig _this, XPoint 
  value );

#ifdef __cplusplus
  }
#endif

#endif /* _WidgetSetGaugeConfig_H */

/* Embedded Wizard */
