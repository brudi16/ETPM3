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

#include "ewlocale.h"
#include "_CoreKeyPressHandler.h"
#include "_CoreSimpleTouchHandler.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_EffectsFloatEffect.h"
#include "_GraphicsArcPath.h"
#include "_GraphicsPath.h"
#include "_GraphicsWarpMatrix.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsFillPath.h"
#include "_ViewsFrame.h"
#include "_ViewsImage.h"
#include "_ViewsText.h"
#include "_ViewsWarpImage.h"
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
#include "Core.h"
#include "Effects.h"
#include "Graphics.h"
#include "Resources.h"
#include "Views.h"
#include "WidgetSet.h"

/* Compressed strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned int _StringsDefault0[] =
{
  0x0000000C, /* ratio 166.67 % */
  0xB8000900, 0x8005A452, 0x04010883, 0x00000004, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XPoint _Const0000 = { 45, 30 };
static const XColor _Const0001 = { 0xA7, 0xA9, 0xAC, 0xFF };
static const XColor _Const0002 = { 0xC4, 0xC6, 0xC9, 0xFF };
static const XPoint _Const0003 = { 60, 32 };
static const XColor _Const0004 = { 0x6C, 0x6E, 0x70, 0xFF };
static const XColor _Const0005 = { 0xA8, 0xAB, 0xAB, 0xFF };
static const XColor _Const0006 = { 0xA8, 0xAB, 0xAB, 0xAA };
static const XPoint _Const0007 = { 70, 39 };
static const XColor _Const0008 = { 0xFF, 0xFF, 0xFF, 0xFF };
static const XPoint _Const0009 = { 34, 34 };
static const XColor _Const000A = { 0x00, 0x00, 0x00, 0xFF };
static const XRect _Const000B = {{ 0, 0 }, { 200, 30 }};
static const XStringRes _Const000C = { _StringsDefault0, 0x0002 };
static const XRect _Const000D = {{ 0, 0 }, { 200, 50 }};
static const XRect _Const000E = {{ 0, 0 }, { 120, 120 }};
static const XRect _Const000F = {{ 0, 0 }, { 150, 50 }};
static const XPoint _Const0010 = { 0, 50 };
static const XPoint _Const0011 = { 150, 50 };
static const XPoint _Const0012 = { 150, 0 };
static const XPoint _Const0013 = { 0, 0 };

/* Include a file containing the bitmap resource : 'WidgetSet::GaugeTrackMedium' */
#include "_WidgetSetGaugeTrackMedium.h"

/* Table with links to derived variants of the bitmap resource : 'WidgetSet::GaugeTrackMedium' */
EW_RES_WITHOUT_VARIANTS( WidgetSetGaugeTrackMedium )

/* Include a file containing the bitmap resource : 'WidgetSet::HorizontalValueBarMedium' */
#include "_WidgetSetHorizontalValueBarMedium.h"

/* Table with links to derived variants of the bitmap resource : 'WidgetSet::HorizontalValueBarMedium' */
EW_RES_WITHOUT_VARIANTS( WidgetSetHorizontalValueBarMedium )

/* Include a file containing the bitmap resource : 'WidgetSet::PushButtonMedium' */
#include "_WidgetSetPushButtonMedium.h"

/* Table with links to derived variants of the bitmap resource : 'WidgetSet::PushButtonMedium' */
EW_RES_WITHOUT_VARIANTS( WidgetSetPushButtonMedium )

/* Include a file containing the bitmap resource : 'WidgetSet::SwitchMedium' */
#include "_WidgetSetSwitchMedium.h"

/* Table with links to derived variants of the bitmap resource : 'WidgetSet::SwitchMedium' */
EW_RES_WITHOUT_VARIANTS( WidgetSetSwitchMedium )

/* This autoobject provides the default customization for the 'horizontal value 
   bar' widget (WidgetSet::HorizontalValueBar) in its medium size variant. */
EW_DEFINE_AUTOOBJECT( WidgetSetHorizontalValueBar_Medium, WidgetSetHorizontalValueBarConfig )

/* Initializer for the auto object 'WidgetSet::HorizontalValueBar_Medium' */
void WidgetSetHorizontalValueBar_Medium__Init( WidgetSetHorizontalValueBarConfig _this )
{
  WidgetSetHorizontalValueBarConfig_OnSetTrackRightFrame( _this, 0 );
  WidgetSetHorizontalValueBarConfig_OnSetTrackRight( _this, EwLoadResource( &WidgetSetHorizontalValueBarMedium, 
  ResourcesBitmap ));
  WidgetSetHorizontalValueBarConfig_OnSetTrackLeftFrame( _this, 1 );
  WidgetSetHorizontalValueBarConfig_OnSetTrackLeft( _this, EwLoadResource( &WidgetSetHorizontalValueBarMedium, 
  ResourcesBitmap ));
  WidgetSetHorizontalValueBarConfig_OnSetWidgetMinSize( _this, _Const0000 );
}

/* Table with links to derived variants of the auto object : 'WidgetSet::HorizontalValueBar_Medium' */
EW_DEFINE_AUTOOBJECT_VARIANTS( WidgetSetHorizontalValueBar_Medium )
EW_END_OF_AUTOOBJECT_VARIANTS( WidgetSetHorizontalValueBar_Medium )

/* This autoobject provides the default customization for the 'value display' widget 
   (WidgetSet::ValueDisplay) in its medium size variant. Widgets using this configuration 
   display the value and unit aligned at the right widget edge. */
EW_DEFINE_AUTOOBJECT( WidgetSetValueDisplay_Medium, WidgetSetValueDisplayConfig )

/* Initializer for the auto object 'WidgetSet::ValueDisplay_Medium' */
void WidgetSetValueDisplay_Medium__Init( WidgetSetValueDisplayConfig _this )
{
  WidgetSetValueDisplayConfig_OnSetValueMarginRight( _this, 10 );
  WidgetSetValueDisplayConfig_OnSetValueColorNegative( _this, _Const0001 );
  WidgetSetValueDisplayConfig_OnSetValueColorPositive( _this, _Const0001 );
  WidgetSetValueDisplayConfig_OnSetValueAlignment( _this, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  WidgetSetValueDisplayConfig_OnSetValueFont( _this, EwLoadResource( &ResourcesFontLarge, 
  ResourcesFont ));
  WidgetSetValueDisplayConfig_OnSetUnitColorNegative( _this, _Const0002 );
  WidgetSetValueDisplayConfig_OnSetUnitColorPositive( _this, _Const0002 );
  WidgetSetValueDisplayConfig_OnSetUnitAlignment( _this, ViewsTextAlignmentAlignHorzRight 
  | ViewsTextAlignmentAlignVertCenter );
  WidgetSetValueDisplayConfig_OnSetUnitFont( _this, EwLoadResource( &ResourcesFontLarge, 
  ResourcesFont ));
  WidgetSetValueDisplayConfig_OnSetFormatPlusSign( _this, 0 );
  WidgetSetValueDisplayConfig_OnSetLayout( _this, WidgetSetValueDisplayLayoutAlignValueLeftToUnit );
  WidgetSetValueDisplayConfig_OnSetWidgetMinSize( _this, _Const0003 );
}

/* Table with links to derived variants of the auto object : 'WidgetSet::ValueDisplay_Medium' */
EW_DEFINE_AUTOOBJECT_VARIANTS( WidgetSetValueDisplay_Medium )
EW_END_OF_AUTOOBJECT_VARIANTS( WidgetSetValueDisplay_Medium )

/* This autoobject provides one of the default customizations for the 'toggle' widget 
   (WidgetSet::ToggleButton) in its medium size variant. With this customization 
   the toggle button appears as a 'switch'. */
EW_DEFINE_AUTOOBJECT( WidgetSetSwitch_Medium, WidgetSetToggleButtonConfig )

/* Initializer for the auto object 'WidgetSet::Switch_Medium' */
void WidgetSetSwitch_Medium__Init( WidgetSetToggleButtonConfig _this )
{
  WidgetSetToggleButtonConfig_OnSetLabelOnColorActive( _this, _Const0004 );
  WidgetSetToggleButtonConfig_OnSetLabelOnColorFocused( _this, _Const0004 );
  WidgetSetToggleButtonConfig_OnSetLabelOnColorDisabled( _this, _Const0005 );
  WidgetSetToggleButtonConfig_OnSetLabelOnColorDefault( _this, _Const0004 );
  WidgetSetToggleButtonConfig_OnSetLabelOffColorActive( _this, _Const0004 );
  WidgetSetToggleButtonConfig_OnSetLabelOffColorFocused( _this, _Const0004 );
  WidgetSetToggleButtonConfig_OnSetLabelOffColorDisabled( _this, _Const0005 );
  WidgetSetToggleButtonConfig_OnSetLabelOffColorDefault( _this, _Const0004 );
  WidgetSetToggleButtonConfig_OnSetLabelMarginRight( _this, 75 );
  WidgetSetToggleButtonConfig_OnSetIconOnTintActive( _this, _Const0004 );
  WidgetSetToggleButtonConfig_OnSetIconOnTintFocused( _this, _Const0004 );
  WidgetSetToggleButtonConfig_OnSetIconOnTintDisabled( _this, _Const0006 );
  WidgetSetToggleButtonConfig_OnSetIconOnTintDefault( _this, _Const0004 );
  WidgetSetToggleButtonConfig_OnSetIconOffTintActive( _this, _Const0004 );
  WidgetSetToggleButtonConfig_OnSetIconOffTintFocused( _this, _Const0004 );
  WidgetSetToggleButtonConfig_OnSetIconOffTintDisabled( _this, _Const0006 );
  WidgetSetToggleButtonConfig_OnSetIconOffTintDefault( _this, _Const0004 );
  WidgetSetToggleButtonConfig_OnSetIconMarginRight( _this, 75 );
  WidgetSetToggleButtonConfig_OnSetLabelAlignment( _this, ViewsTextAlignmentAlignHorzLeft 
  | ViewsTextAlignmentAlignVertCenter );
  WidgetSetToggleButtonConfig_OnSetLabelOnFont( _this, EwLoadResource( &ResourcesFontMedium, 
  ResourcesFont ));
  WidgetSetToggleButtonConfig_OnSetLabelOffFont( _this, EwLoadResource( &ResourcesFontMedium, 
  ResourcesFont ));
  WidgetSetToggleButtonConfig_OnSetIconAlignment( _this, ViewsImageAlignmentAlignHorzLeft 
  | ViewsImageAlignmentAlignVertCenter );
  WidgetSetToggleButtonConfig_OnSetFaceLayout( _this, CoreLayoutAlignToRight );
  WidgetSetToggleButtonConfig_OnSetFaceOnFrameActive( _this, 7 );
  WidgetSetToggleButtonConfig_OnSetFaceOnFrameFocused( _this, 5 );
  WidgetSetToggleButtonConfig_OnSetFaceOnFrameDisabled( _this, 1 );
  WidgetSetToggleButtonConfig_OnSetFaceOnFrameDefault( _this, 3 );
  WidgetSetToggleButtonConfig_OnSetFaceOnActive( _this, EwLoadResource( &WidgetSetSwitchMedium, 
  ResourcesBitmap ));
  WidgetSetToggleButtonConfig_OnSetFaceOnFocused( _this, EwLoadResource( &WidgetSetSwitchMedium, 
  ResourcesBitmap ));
  WidgetSetToggleButtonConfig_OnSetFaceOnDisabled( _this, EwLoadResource( &WidgetSetSwitchMedium, 
  ResourcesBitmap ));
  WidgetSetToggleButtonConfig_OnSetFaceOnDefault( _this, EwLoadResource( &WidgetSetSwitchMedium, 
  ResourcesBitmap ));
  WidgetSetToggleButtonConfig_OnSetFaceOffFrameActive( _this, 6 );
  WidgetSetToggleButtonConfig_OnSetFaceOffFrameFocused( _this, 4 );
  WidgetSetToggleButtonConfig_OnSetFaceOffFrameDisabled( _this, 0 );
  WidgetSetToggleButtonConfig_OnSetFaceOffFrameDefault( _this, 2 );
  WidgetSetToggleButtonConfig_OnSetFaceOffActive( _this, EwLoadResource( &WidgetSetSwitchMedium, 
  ResourcesBitmap ));
  WidgetSetToggleButtonConfig_OnSetFaceOffFocused( _this, EwLoadResource( &WidgetSetSwitchMedium, 
  ResourcesBitmap ));
  WidgetSetToggleButtonConfig_OnSetFaceOffDisabled( _this, EwLoadResource( &WidgetSetSwitchMedium, 
  ResourcesBitmap ));
  WidgetSetToggleButtonConfig_OnSetFaceOffDefault( _this, EwLoadResource( &WidgetSetSwitchMedium, 
  ResourcesBitmap ));
  WidgetSetToggleButtonConfig_OnSetWidgetMinSize( _this, _Const0007 );
}

/* Table with links to derived variants of the auto object : 'WidgetSet::Switch_Medium' */
EW_DEFINE_AUTOOBJECT_VARIANTS( WidgetSetSwitch_Medium )
EW_END_OF_AUTOOBJECT_VARIANTS( WidgetSetSwitch_Medium )

/* This autoobject provides the default customization for the 'push button' widget 
   (WidgetSet::PushButton) in its medium size variant. */
EW_DEFINE_AUTOOBJECT( WidgetSetPushButton_Medium, WidgetSetPushButtonConfig )

/* Initializer for the auto object 'WidgetSet::PushButton_Medium' */
void WidgetSetPushButton_Medium__Init( WidgetSetPushButtonConfig _this )
{
  WidgetSetPushButtonConfig_OnSetLabelColorActive( _this, _Const0008 );
  WidgetSetPushButtonConfig_OnSetLabelColorFocused( _this, _Const0008 );
  WidgetSetPushButtonConfig_OnSetLabelColorDisabled( _this, _Const0005 );
  WidgetSetPushButtonConfig_OnSetLabelColorDefault( _this, _Const0004 );
  WidgetSetPushButtonConfig_OnSetLabelMarginBottom( _this, 6 );
  WidgetSetPushButtonConfig_OnSetLabelMarginTop( _this, 6 );
  WidgetSetPushButtonConfig_OnSetLabelMarginRight( _this, 6 );
  WidgetSetPushButtonConfig_OnSetLabelMarginLeft( _this, 6 );
  WidgetSetPushButtonConfig_OnSetIconTintDisabled( _this, _Const0006 );
  WidgetSetPushButtonConfig_OnSetIconTintDefault( _this, _Const0004 );
  WidgetSetPushButtonConfig_OnSetIconMarginBottom( _this, 6 );
  WidgetSetPushButtonConfig_OnSetIconMarginTop( _this, 6 );
  WidgetSetPushButtonConfig_OnSetIconMarginRight( _this, 6 );
  WidgetSetPushButtonConfig_OnSetIconMarginLeft( _this, 6 );
  WidgetSetPushButtonConfig_OnSetLabelFont( _this, EwLoadResource( &ResourcesFontMedium, 
  ResourcesFont ));
  WidgetSetPushButtonConfig_OnSetFaceFrameActive( _this, 3 );
  WidgetSetPushButtonConfig_OnSetFaceFrameFocused( _this, 2 );
  WidgetSetPushButtonConfig_OnSetFaceFrameDisabled( _this, 0 );
  WidgetSetPushButtonConfig_OnSetFaceFrameDefault( _this, 1 );
  WidgetSetPushButtonConfig_OnSetFaceActive( _this, EwLoadResource( &WidgetSetPushButtonMedium, 
  ResourcesBitmap ));
  WidgetSetPushButtonConfig_OnSetFaceFocused( _this, EwLoadResource( &WidgetSetPushButtonMedium, 
  ResourcesBitmap ));
  WidgetSetPushButtonConfig_OnSetFaceDisabled( _this, EwLoadResource( &WidgetSetPushButtonMedium, 
  ResourcesBitmap ));
  WidgetSetPushButtonConfig_OnSetFaceDefault( _this, EwLoadResource( &WidgetSetPushButtonMedium, 
  ResourcesBitmap ));
  WidgetSetPushButtonConfig_OnSetWidgetMinSize( _this, _Const0009 );
}

/* Table with links to derived variants of the auto object : 'WidgetSet::PushButton_Medium' */
EW_DEFINE_AUTOOBJECT_VARIANTS( WidgetSetPushButton_Medium )
EW_END_OF_AUTOOBJECT_VARIANTS( WidgetSetPushButton_Medium )

/* Initializer for the class 'WidgetSet::ValueDisplayConfig' */
void WidgetSetValueDisplayConfig__Init( WidgetSetValueDisplayConfig _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  WidgetSetWidgetConfig__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( WidgetSetValueDisplayConfig );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( WidgetSetValueDisplayConfig );

  /* ... and initialize objects, variables, properties, etc. */
  _this->ValueColorNegative = _Const000A;
  _this->ValueColorPositive = _Const000A;
  _this->ValueAlignment = ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertCenter;
  _this->UnitColorNegative = _Const000A;
  _this->UnitColorPositive = _Const000A;
  _this->UnitAlignment = ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertCenter;
  _this->Layout = WidgetSetValueDisplayLayoutUnitAndValueAreIndependent;
}

/* Re-Initializer for the class 'WidgetSet::ValueDisplayConfig' */
void WidgetSetValueDisplayConfig__ReInit( WidgetSetValueDisplayConfig _this )
{
  /* At first re-initialize the super class ... */
  WidgetSetWidgetConfig__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'WidgetSet::ValueDisplayConfig' */
void WidgetSetValueDisplayConfig__Done( WidgetSetValueDisplayConfig _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( WidgetSetWidgetConfig );

  /* Don't forget to deinitialize the super class ... */
  WidgetSetWidgetConfig__Done( &_this->_.Super );
}

/* 'C' function for method : 'WidgetSet::ValueDisplayConfig.OnSetValueMarginRight()' */
void WidgetSetValueDisplayConfig_OnSetValueMarginRight( WidgetSetValueDisplayConfig _this, 
  XInt32 value )
{
  if ( _this->ValueMarginRight == value )
    return;

  _this->ValueMarginRight = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ValueDisplayConfig.OnSetValueColorNegative()' */
void WidgetSetValueDisplayConfig_OnSetValueColorNegative( WidgetSetValueDisplayConfig _this, 
  XColor value )
{
  if ( !EwCompColor( _this->ValueColorNegative, value ))
    return;

  _this->ValueColorNegative = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ValueDisplayConfig.OnSetValueColorPositive()' */
void WidgetSetValueDisplayConfig_OnSetValueColorPositive( WidgetSetValueDisplayConfig _this, 
  XColor value )
{
  if ( !EwCompColor( _this->ValueColorPositive, value ))
    return;

  _this->ValueColorPositive = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ValueDisplayConfig.OnSetValueAlignment()' */
void WidgetSetValueDisplayConfig_OnSetValueAlignment( WidgetSetValueDisplayConfig _this, 
  XSet value )
{
  if ( _this->ValueAlignment == value )
    return;

  _this->ValueAlignment = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ValueDisplayConfig.OnSetValueFont()' */
void WidgetSetValueDisplayConfig_OnSetValueFont( WidgetSetValueDisplayConfig _this, 
  ResourcesFont value )
{
  if ( _this->ValueFont == value )
    return;

  _this->ValueFont = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ValueDisplayConfig.OnSetUnitColorNegative()' */
void WidgetSetValueDisplayConfig_OnSetUnitColorNegative( WidgetSetValueDisplayConfig _this, 
  XColor value )
{
  if ( !EwCompColor( _this->UnitColorNegative, value ))
    return;

  _this->UnitColorNegative = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ValueDisplayConfig.OnSetUnitColorPositive()' */
void WidgetSetValueDisplayConfig_OnSetUnitColorPositive( WidgetSetValueDisplayConfig _this, 
  XColor value )
{
  if ( !EwCompColor( _this->UnitColorPositive, value ))
    return;

  _this->UnitColorPositive = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ValueDisplayConfig.OnSetUnitAlignment()' */
void WidgetSetValueDisplayConfig_OnSetUnitAlignment( WidgetSetValueDisplayConfig _this, 
  XSet value )
{
  if ( _this->UnitAlignment == value )
    return;

  _this->UnitAlignment = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ValueDisplayConfig.OnSetUnitFont()' */
void WidgetSetValueDisplayConfig_OnSetUnitFont( WidgetSetValueDisplayConfig _this, 
  ResourcesFont value )
{
  if ( _this->UnitFont == value )
    return;

  _this->UnitFont = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ValueDisplayConfig.OnSetFormatPlusSign()' */
void WidgetSetValueDisplayConfig_OnSetFormatPlusSign( WidgetSetValueDisplayConfig _this, 
  XString value )
{
  if ( !EwCompString( _this->FormatPlusSign, value ))
    return;

  _this->FormatPlusSign = EwShareString( value );
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ValueDisplayConfig.OnSetLayout()' */
void WidgetSetValueDisplayConfig_OnSetLayout( WidgetSetValueDisplayConfig _this, 
  XEnum value )
{
  if ( _this->Layout == value )
    return;

  _this->Layout = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ValueDisplayConfig.OnSetWidgetMinSize()' */
void WidgetSetValueDisplayConfig_OnSetWidgetMinSize( WidgetSetValueDisplayConfig _this, 
  XPoint value )
{
  if ( !EwCompPoint( _this->WidgetMinSize, value ))
    return;

  _this->WidgetMinSize = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* Variants derived from the class : 'WidgetSet::ValueDisplayConfig' */
EW_DEFINE_CLASS_VARIANTS( WidgetSetValueDisplayConfig )
EW_END_OF_CLASS_VARIANTS( WidgetSetValueDisplayConfig )

/* Virtual Method Table (VMT) for the class : 'WidgetSet::ValueDisplayConfig' */
EW_DEFINE_CLASS( WidgetSetValueDisplayConfig, WidgetSetWidgetConfig, ValueFont, 
                 FormatPlusSign, FormatPlusSign, FormatPlusSign, FormatPlusSign, 
                 ValueMarginRight, "WidgetSet::ValueDisplayConfig" )
EW_END_OF_CLASS( WidgetSetValueDisplayConfig )

/* Initializer for the class 'WidgetSet::HorizontalValueBarConfig' */
void WidgetSetHorizontalValueBarConfig__Init( WidgetSetHorizontalValueBarConfig _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  WidgetSetWidgetConfig__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( WidgetSetHorizontalValueBarConfig );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( WidgetSetHorizontalValueBarConfig );

  /* ... and initialize objects, variables, properties, etc. */
  _this->TrackRightFrame = -1;
  _this->TrackLeftFrame = -1;
}

/* Re-Initializer for the class 'WidgetSet::HorizontalValueBarConfig' */
void WidgetSetHorizontalValueBarConfig__ReInit( WidgetSetHorizontalValueBarConfig _this )
{
  /* At first re-initialize the super class ... */
  WidgetSetWidgetConfig__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'WidgetSet::HorizontalValueBarConfig' */
void WidgetSetHorizontalValueBarConfig__Done( WidgetSetHorizontalValueBarConfig _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( WidgetSetWidgetConfig );

  /* Don't forget to deinitialize the super class ... */
  WidgetSetWidgetConfig__Done( &_this->_.Super );
}

/* 'C' function for method : 'WidgetSet::HorizontalValueBarConfig.OnSetTrackRightFrame()' */
void WidgetSetHorizontalValueBarConfig_OnSetTrackRightFrame( WidgetSetHorizontalValueBarConfig _this, 
  XInt32 value )
{
  if ( _this->TrackRightFrame == value )
    return;

  _this->TrackRightFrame = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::HorizontalValueBarConfig.OnSetTrackRight()' */
void WidgetSetHorizontalValueBarConfig_OnSetTrackRight( WidgetSetHorizontalValueBarConfig _this, 
  ResourcesBitmap value )
{
  if ( _this->TrackRight == value )
    return;

  _this->TrackRight = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::HorizontalValueBarConfig.OnSetTrackLeftFrame()' */
void WidgetSetHorizontalValueBarConfig_OnSetTrackLeftFrame( WidgetSetHorizontalValueBarConfig _this, 
  XInt32 value )
{
  if ( _this->TrackLeftFrame == value )
    return;

  _this->TrackLeftFrame = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::HorizontalValueBarConfig.OnSetTrackLeft()' */
void WidgetSetHorizontalValueBarConfig_OnSetTrackLeft( WidgetSetHorizontalValueBarConfig _this, 
  ResourcesBitmap value )
{
  if ( _this->TrackLeft == value )
    return;

  _this->TrackLeft = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::HorizontalValueBarConfig.OnSetWidgetMinSize()' */
void WidgetSetHorizontalValueBarConfig_OnSetWidgetMinSize( WidgetSetHorizontalValueBarConfig _this, 
  XPoint value )
{
  if ( !EwCompPoint( _this->WidgetMinSize, value ))
    return;

  _this->WidgetMinSize = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* Variants derived from the class : 'WidgetSet::HorizontalValueBarConfig' */
EW_DEFINE_CLASS_VARIANTS( WidgetSetHorizontalValueBarConfig )
EW_END_OF_CLASS_VARIANTS( WidgetSetHorizontalValueBarConfig )

/* Virtual Method Table (VMT) for the class : 'WidgetSet::HorizontalValueBarConfig' */
EW_DEFINE_CLASS( WidgetSetHorizontalValueBarConfig, WidgetSetWidgetConfig, TrackRight, 
                 TrackRightFrame, TrackRightFrame, TrackRightFrame, TrackRightFrame, 
                 TrackRightFrame, "WidgetSet::HorizontalValueBarConfig" )
EW_END_OF_CLASS( WidgetSetHorizontalValueBarConfig )

/* Initializer for the class 'WidgetSet::GaugeConfig' */
void WidgetSetGaugeConfig__Init( WidgetSetGaugeConfig _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  WidgetSetWidgetConfig__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( WidgetSetGaugeConfig );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( WidgetSetGaugeConfig );

  /* ... and initialize objects, variables, properties, etc. */
  _this->SwingElastic = 1;
  _this->SwingDuration = 500;
  _this->TrackLeftColor = _Const0008;
  _this->NeedleMaxAngle = 45.000000f;
  _this->NeedleMinAngle = 135.000000f;
}

/* Re-Initializer for the class 'WidgetSet::GaugeConfig' */
void WidgetSetGaugeConfig__ReInit( WidgetSetGaugeConfig _this )
{
  /* At first re-initialize the super class ... */
  WidgetSetWidgetConfig__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'WidgetSet::GaugeConfig' */
void WidgetSetGaugeConfig__Done( WidgetSetGaugeConfig _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( WidgetSetWidgetConfig );

  /* Don't forget to deinitialize the super class ... */
  WidgetSetWidgetConfig__Done( &_this->_.Super );
}

/* 'C' function for method : 'WidgetSet::GaugeConfig.OnSetSwingElastic()' */
void WidgetSetGaugeConfig_OnSetSwingElastic( WidgetSetGaugeConfig _this, XBool value )
{
  if ( _this->SwingElastic == value )
    return;

  _this->SwingElastic = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::GaugeConfig.OnSetSwingDuration()' */
void WidgetSetGaugeConfig_OnSetSwingDuration( WidgetSetGaugeConfig _this, XInt32 
  value )
{
  if ( _this->SwingDuration == value )
    return;

  _this->SwingDuration = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::GaugeConfig.OnSetTrackLeftRoundedStart()' */
void WidgetSetGaugeConfig_OnSetTrackLeftRoundedStart( WidgetSetGaugeConfig _this, 
  XBool value )
{
  if ( _this->TrackLeftRoundedStart == value )
    return;

  _this->TrackLeftRoundedStart = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::GaugeConfig.OnSetTrackLeftColor()' */
void WidgetSetGaugeConfig_OnSetTrackLeftColor( WidgetSetGaugeConfig _this, XColor 
  value )
{
  if ( !EwCompColor( _this->TrackLeftColor, value ))
    return;

  _this->TrackLeftColor = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::GaugeConfig.OnSetTrackLeftThickness()' */
void WidgetSetGaugeConfig_OnSetTrackLeftThickness( WidgetSetGaugeConfig _this, XFloat 
  value )
{
  if ( _this->TrackLeftThickness == value )
    return;

  _this->TrackLeftThickness = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::GaugeConfig.OnSetTrackLeftRadius()' */
void WidgetSetGaugeConfig_OnSetTrackLeftRadius( WidgetSetGaugeConfig _this, XFloat 
  value )
{
  if ( _this->TrackLeftRadius == value )
    return;

  _this->TrackLeftRadius = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::GaugeConfig.OnSetNeedleMaxAngle()' */
void WidgetSetGaugeConfig_OnSetNeedleMaxAngle( WidgetSetGaugeConfig _this, XFloat 
  value )
{
  if ( _this->NeedleMaxAngle == value )
    return;

  _this->NeedleMaxAngle = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::GaugeConfig.OnSetNeedleMinAngle()' */
void WidgetSetGaugeConfig_OnSetNeedleMinAngle( WidgetSetGaugeConfig _this, XFloat 
  value )
{
  if ( _this->NeedleMinAngle == value )
    return;

  _this->NeedleMinAngle = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::GaugeConfig.OnSetNeedlePivot()' */
void WidgetSetGaugeConfig_OnSetNeedlePivot( WidgetSetGaugeConfig _this, XPoint value )
{
  if ( !EwCompPoint( _this->NeedlePivot, value ))
    return;

  _this->NeedlePivot = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::GaugeConfig.OnSetNeedle()' */
void WidgetSetGaugeConfig_OnSetNeedle( WidgetSetGaugeConfig _this, ResourcesBitmap 
  value )
{
  if ( _this->Needle == value )
    return;

  _this->Needle = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::GaugeConfig.OnSetCenterOffset()' */
void WidgetSetGaugeConfig_OnSetCenterOffset( WidgetSetGaugeConfig _this, XPoint 
  value )
{
  if ( !EwCompPoint( _this->CenterOffset, value ))
    return;

  _this->CenterOffset = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::GaugeConfig.OnSetScale()' */
void WidgetSetGaugeConfig_OnSetScale( WidgetSetGaugeConfig _this, ResourcesBitmap 
  value )
{
  if ( _this->Scale == value )
    return;

  _this->Scale = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::GaugeConfig.OnSetWidgetMinSize()' */
void WidgetSetGaugeConfig_OnSetWidgetMinSize( WidgetSetGaugeConfig _this, XPoint 
  value )
{
  if ( !EwCompPoint( _this->WidgetMinSize, value ))
    return;

  _this->WidgetMinSize = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* Variants derived from the class : 'WidgetSet::GaugeConfig' */
EW_DEFINE_CLASS_VARIANTS( WidgetSetGaugeConfig )
EW_END_OF_CLASS_VARIANTS( WidgetSetGaugeConfig )

/* Virtual Method Table (VMT) for the class : 'WidgetSet::GaugeConfig' */
EW_DEFINE_CLASS( WidgetSetGaugeConfig, WidgetSetWidgetConfig, Needle, SwingDuration, 
                 SwingDuration, SwingDuration, SwingDuration, SwingDuration, "WidgetSet::GaugeConfig" )
EW_END_OF_CLASS( WidgetSetGaugeConfig )

/* Initializer for the class 'WidgetSet::ToggleButtonConfig' */
void WidgetSetToggleButtonConfig__Init( WidgetSetToggleButtonConfig _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  WidgetSetWidgetConfig__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( WidgetSetToggleButtonConfig );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( WidgetSetToggleButtonConfig );

  /* ... and initialize objects, variables, properties, etc. */
  _this->LabelOnColorActive = _Const000A;
  _this->LabelOnColorFocused = _Const000A;
  _this->LabelOnColorDisabled = _Const000A;
  _this->LabelOnColorDefault = _Const000A;
  _this->LabelOffColorActive = _Const000A;
  _this->LabelOffColorFocused = _Const000A;
  _this->LabelOffColorDisabled = _Const000A;
  _this->LabelOffColorDefault = _Const000A;
  _this->IconOnTintActive = _Const0008;
  _this->IconOnTintFocused = _Const0008;
  _this->IconOnTintDisabled = _Const0008;
  _this->IconOnTintDefault = _Const0008;
  _this->IconOffTintActive = _Const0008;
  _this->IconOffTintFocused = _Const0008;
  _this->IconOffTintDisabled = _Const0008;
  _this->IconOffTintDefault = _Const0008;
  _this->LabelAlignment = ViewsTextAlignmentAlignHorzCenter | ViewsTextAlignmentAlignVertCenter;
  _this->IconAlignment = ViewsImageAlignmentAlignHorzCenter | ViewsImageAlignmentAlignVertCenter;
  _this->FaceLayout = CoreLayoutAlignToBottom | CoreLayoutAlignToLeft | CoreLayoutAlignToRight 
  | CoreLayoutAlignToTop | CoreLayoutResizeHorz | CoreLayoutResizeVert;
  _this->FaceOnFrameActive = -1;
  _this->FaceOnFrameFocused = -1;
  _this->FaceOnFrameDisabled = -1;
  _this->FaceOnFrameDefault = -1;
  _this->FaceOffFrameActive = -1;
  _this->FaceOffFrameFocused = -1;
  _this->FaceOffFrameDisabled = -1;
  _this->FaceOffFrameDefault = -1;
}

/* Re-Initializer for the class 'WidgetSet::ToggleButtonConfig' */
void WidgetSetToggleButtonConfig__ReInit( WidgetSetToggleButtonConfig _this )
{
  /* At first re-initialize the super class ... */
  WidgetSetWidgetConfig__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'WidgetSet::ToggleButtonConfig' */
void WidgetSetToggleButtonConfig__Done( WidgetSetToggleButtonConfig _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( WidgetSetWidgetConfig );

  /* Don't forget to deinitialize the super class ... */
  WidgetSetWidgetConfig__Done( &_this->_.Super );
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOnColorActive()' */
void WidgetSetToggleButtonConfig_OnSetLabelOnColorActive( WidgetSetToggleButtonConfig _this, 
  XColor value )
{
  if ( !EwCompColor( _this->LabelOnColorActive, value ))
    return;

  _this->LabelOnColorActive = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOnColorFocused()' */
void WidgetSetToggleButtonConfig_OnSetLabelOnColorFocused( WidgetSetToggleButtonConfig _this, 
  XColor value )
{
  if ( !EwCompColor( _this->LabelOnColorFocused, value ))
    return;

  _this->LabelOnColorFocused = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOnColorDisabled()' */
void WidgetSetToggleButtonConfig_OnSetLabelOnColorDisabled( WidgetSetToggleButtonConfig _this, 
  XColor value )
{
  if ( !EwCompColor( _this->LabelOnColorDisabled, value ))
    return;

  _this->LabelOnColorDisabled = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOnColorDefault()' */
void WidgetSetToggleButtonConfig_OnSetLabelOnColorDefault( WidgetSetToggleButtonConfig _this, 
  XColor value )
{
  if ( !EwCompColor( _this->LabelOnColorDefault, value ))
    return;

  _this->LabelOnColorDefault = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOffColorActive()' */
void WidgetSetToggleButtonConfig_OnSetLabelOffColorActive( WidgetSetToggleButtonConfig _this, 
  XColor value )
{
  if ( !EwCompColor( _this->LabelOffColorActive, value ))
    return;

  _this->LabelOffColorActive = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOffColorFocused()' */
void WidgetSetToggleButtonConfig_OnSetLabelOffColorFocused( WidgetSetToggleButtonConfig _this, 
  XColor value )
{
  if ( !EwCompColor( _this->LabelOffColorFocused, value ))
    return;

  _this->LabelOffColorFocused = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOffColorDisabled()' */
void WidgetSetToggleButtonConfig_OnSetLabelOffColorDisabled( WidgetSetToggleButtonConfig _this, 
  XColor value )
{
  if ( !EwCompColor( _this->LabelOffColorDisabled, value ))
    return;

  _this->LabelOffColorDisabled = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOffColorDefault()' */
void WidgetSetToggleButtonConfig_OnSetLabelOffColorDefault( WidgetSetToggleButtonConfig _this, 
  XColor value )
{
  if ( !EwCompColor( _this->LabelOffColorDefault, value ))
    return;

  _this->LabelOffColorDefault = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelMarginRight()' */
void WidgetSetToggleButtonConfig_OnSetLabelMarginRight( WidgetSetToggleButtonConfig _this, 
  XInt32 value )
{
  if ( _this->LabelMarginRight == value )
    return;

  _this->LabelMarginRight = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconOnTintActive()' */
void WidgetSetToggleButtonConfig_OnSetIconOnTintActive( WidgetSetToggleButtonConfig _this, 
  XColor value )
{
  if ( !EwCompColor( _this->IconOnTintActive, value ))
    return;

  _this->IconOnTintActive = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconOnTintFocused()' */
void WidgetSetToggleButtonConfig_OnSetIconOnTintFocused( WidgetSetToggleButtonConfig _this, 
  XColor value )
{
  if ( !EwCompColor( _this->IconOnTintFocused, value ))
    return;

  _this->IconOnTintFocused = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconOnTintDisabled()' */
void WidgetSetToggleButtonConfig_OnSetIconOnTintDisabled( WidgetSetToggleButtonConfig _this, 
  XColor value )
{
  if ( !EwCompColor( _this->IconOnTintDisabled, value ))
    return;

  _this->IconOnTintDisabled = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconOnTintDefault()' */
void WidgetSetToggleButtonConfig_OnSetIconOnTintDefault( WidgetSetToggleButtonConfig _this, 
  XColor value )
{
  if ( !EwCompColor( _this->IconOnTintDefault, value ))
    return;

  _this->IconOnTintDefault = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconOffTintActive()' */
void WidgetSetToggleButtonConfig_OnSetIconOffTintActive( WidgetSetToggleButtonConfig _this, 
  XColor value )
{
  if ( !EwCompColor( _this->IconOffTintActive, value ))
    return;

  _this->IconOffTintActive = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconOffTintFocused()' */
void WidgetSetToggleButtonConfig_OnSetIconOffTintFocused( WidgetSetToggleButtonConfig _this, 
  XColor value )
{
  if ( !EwCompColor( _this->IconOffTintFocused, value ))
    return;

  _this->IconOffTintFocused = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconOffTintDisabled()' */
void WidgetSetToggleButtonConfig_OnSetIconOffTintDisabled( WidgetSetToggleButtonConfig _this, 
  XColor value )
{
  if ( !EwCompColor( _this->IconOffTintDisabled, value ))
    return;

  _this->IconOffTintDisabled = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconOffTintDefault()' */
void WidgetSetToggleButtonConfig_OnSetIconOffTintDefault( WidgetSetToggleButtonConfig _this, 
  XColor value )
{
  if ( !EwCompColor( _this->IconOffTintDefault, value ))
    return;

  _this->IconOffTintDefault = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconMarginRight()' */
void WidgetSetToggleButtonConfig_OnSetIconMarginRight( WidgetSetToggleButtonConfig _this, 
  XInt32 value )
{
  if ( _this->IconMarginRight == value )
    return;

  _this->IconMarginRight = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelAlignment()' */
void WidgetSetToggleButtonConfig_OnSetLabelAlignment( WidgetSetToggleButtonConfig _this, 
  XSet value )
{
  if ( _this->LabelAlignment == value )
    return;

  _this->LabelAlignment = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOnFont()' */
void WidgetSetToggleButtonConfig_OnSetLabelOnFont( WidgetSetToggleButtonConfig _this, 
  ResourcesFont value )
{
  if ( _this->LabelOnFont == value )
    return;

  _this->LabelOnFont = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetLabelOffFont()' */
void WidgetSetToggleButtonConfig_OnSetLabelOffFont( WidgetSetToggleButtonConfig _this, 
  ResourcesFont value )
{
  if ( _this->LabelOffFont == value )
    return;

  _this->LabelOffFont = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetIconAlignment()' */
void WidgetSetToggleButtonConfig_OnSetIconAlignment( WidgetSetToggleButtonConfig _this, 
  XSet value )
{
  if ( _this->IconAlignment == value )
    return;

  _this->IconAlignment = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceLayout()' */
void WidgetSetToggleButtonConfig_OnSetFaceLayout( WidgetSetToggleButtonConfig _this, 
  XSet value )
{
  if ( _this->FaceLayout == value )
    return;

  _this->FaceLayout = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOnFrameActive()' */
void WidgetSetToggleButtonConfig_OnSetFaceOnFrameActive( WidgetSetToggleButtonConfig _this, 
  XInt32 value )
{
  if ( _this->FaceOnFrameActive == value )
    return;

  _this->FaceOnFrameActive = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOnFrameFocused()' */
void WidgetSetToggleButtonConfig_OnSetFaceOnFrameFocused( WidgetSetToggleButtonConfig _this, 
  XInt32 value )
{
  if ( _this->FaceOnFrameFocused == value )
    return;

  _this->FaceOnFrameFocused = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOnFrameDisabled()' */
void WidgetSetToggleButtonConfig_OnSetFaceOnFrameDisabled( WidgetSetToggleButtonConfig _this, 
  XInt32 value )
{
  if ( _this->FaceOnFrameDisabled == value )
    return;

  _this->FaceOnFrameDisabled = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOnFrameDefault()' */
void WidgetSetToggleButtonConfig_OnSetFaceOnFrameDefault( WidgetSetToggleButtonConfig _this, 
  XInt32 value )
{
  if ( _this->FaceOnFrameDefault == value )
    return;

  _this->FaceOnFrameDefault = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOnActive()' */
void WidgetSetToggleButtonConfig_OnSetFaceOnActive( WidgetSetToggleButtonConfig _this, 
  ResourcesBitmap value )
{
  if ( _this->FaceOnActive == value )
    return;

  _this->FaceOnActive = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOnFocused()' */
void WidgetSetToggleButtonConfig_OnSetFaceOnFocused( WidgetSetToggleButtonConfig _this, 
  ResourcesBitmap value )
{
  if ( _this->FaceOnFocused == value )
    return;

  _this->FaceOnFocused = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOnDisabled()' */
void WidgetSetToggleButtonConfig_OnSetFaceOnDisabled( WidgetSetToggleButtonConfig _this, 
  ResourcesBitmap value )
{
  if ( _this->FaceOnDisabled == value )
    return;

  _this->FaceOnDisabled = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOnDefault()' */
void WidgetSetToggleButtonConfig_OnSetFaceOnDefault( WidgetSetToggleButtonConfig _this, 
  ResourcesBitmap value )
{
  if ( _this->FaceOnDefault == value )
    return;

  _this->FaceOnDefault = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOffFrameActive()' */
void WidgetSetToggleButtonConfig_OnSetFaceOffFrameActive( WidgetSetToggleButtonConfig _this, 
  XInt32 value )
{
  if ( _this->FaceOffFrameActive == value )
    return;

  _this->FaceOffFrameActive = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOffFrameFocused()' */
void WidgetSetToggleButtonConfig_OnSetFaceOffFrameFocused( WidgetSetToggleButtonConfig _this, 
  XInt32 value )
{
  if ( _this->FaceOffFrameFocused == value )
    return;

  _this->FaceOffFrameFocused = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOffFrameDisabled()' */
void WidgetSetToggleButtonConfig_OnSetFaceOffFrameDisabled( WidgetSetToggleButtonConfig _this, 
  XInt32 value )
{
  if ( _this->FaceOffFrameDisabled == value )
    return;

  _this->FaceOffFrameDisabled = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOffFrameDefault()' */
void WidgetSetToggleButtonConfig_OnSetFaceOffFrameDefault( WidgetSetToggleButtonConfig _this, 
  XInt32 value )
{
  if ( _this->FaceOffFrameDefault == value )
    return;

  _this->FaceOffFrameDefault = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOffActive()' */
void WidgetSetToggleButtonConfig_OnSetFaceOffActive( WidgetSetToggleButtonConfig _this, 
  ResourcesBitmap value )
{
  if ( _this->FaceOffActive == value )
    return;

  _this->FaceOffActive = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOffFocused()' */
void WidgetSetToggleButtonConfig_OnSetFaceOffFocused( WidgetSetToggleButtonConfig _this, 
  ResourcesBitmap value )
{
  if ( _this->FaceOffFocused == value )
    return;

  _this->FaceOffFocused = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOffDisabled()' */
void WidgetSetToggleButtonConfig_OnSetFaceOffDisabled( WidgetSetToggleButtonConfig _this, 
  ResourcesBitmap value )
{
  if ( _this->FaceOffDisabled == value )
    return;

  _this->FaceOffDisabled = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetFaceOffDefault()' */
void WidgetSetToggleButtonConfig_OnSetFaceOffDefault( WidgetSetToggleButtonConfig _this, 
  ResourcesBitmap value )
{
  if ( _this->FaceOffDefault == value )
    return;

  _this->FaceOffDefault = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButtonConfig.OnSetWidgetMinSize()' */
void WidgetSetToggleButtonConfig_OnSetWidgetMinSize( WidgetSetToggleButtonConfig _this, 
  XPoint value )
{
  if ( !EwCompPoint( _this->WidgetMinSize, value ))
    return;

  _this->WidgetMinSize = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* Variants derived from the class : 'WidgetSet::ToggleButtonConfig' */
EW_DEFINE_CLASS_VARIANTS( WidgetSetToggleButtonConfig )
EW_END_OF_CLASS_VARIANTS( WidgetSetToggleButtonConfig )

/* Virtual Method Table (VMT) for the class : 'WidgetSet::ToggleButtonConfig' */
EW_DEFINE_CLASS( WidgetSetToggleButtonConfig, WidgetSetWidgetConfig, LabelOnFont, 
                 LabelOnColorActive, LabelOnColorActive, LabelOnColorActive, LabelOnColorActive, 
                 LabelOnColorActive, "WidgetSet::ToggleButtonConfig" )
EW_END_OF_CLASS( WidgetSetToggleButtonConfig )

/* Initializer for the class 'WidgetSet::PushButtonConfig' */
void WidgetSetPushButtonConfig__Init( WidgetSetPushButtonConfig _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  WidgetSetWidgetConfig__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( WidgetSetPushButtonConfig );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( WidgetSetPushButtonConfig );

  /* ... and initialize objects, variables, properties, etc. */
  _this->LabelColorActive = _Const000A;
  _this->LabelColorFocused = _Const000A;
  _this->LabelColorDisabled = _Const000A;
  _this->LabelColorDefault = _Const000A;
  _this->IconTintDisabled = _Const0008;
  _this->IconTintDefault = _Const0008;
  _this->FaceFrameActive = -1;
  _this->FaceFrameFocused = -1;
  _this->FaceFrameDisabled = -1;
  _this->FaceFrameDefault = -1;
}

/* Re-Initializer for the class 'WidgetSet::PushButtonConfig' */
void WidgetSetPushButtonConfig__ReInit( WidgetSetPushButtonConfig _this )
{
  /* At first re-initialize the super class ... */
  WidgetSetWidgetConfig__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'WidgetSet::PushButtonConfig' */
void WidgetSetPushButtonConfig__Done( WidgetSetPushButtonConfig _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( WidgetSetWidgetConfig );

  /* Don't forget to deinitialize the super class ... */
  WidgetSetWidgetConfig__Done( &_this->_.Super );
}

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelColorActive()' */
void WidgetSetPushButtonConfig_OnSetLabelColorActive( WidgetSetPushButtonConfig _this, 
  XColor value )
{
  if ( !EwCompColor( _this->LabelColorActive, value ))
    return;

  _this->LabelColorActive = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelColorFocused()' */
void WidgetSetPushButtonConfig_OnSetLabelColorFocused( WidgetSetPushButtonConfig _this, 
  XColor value )
{
  if ( !EwCompColor( _this->LabelColorFocused, value ))
    return;

  _this->LabelColorFocused = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelColorDisabled()' */
void WidgetSetPushButtonConfig_OnSetLabelColorDisabled( WidgetSetPushButtonConfig _this, 
  XColor value )
{
  if ( !EwCompColor( _this->LabelColorDisabled, value ))
    return;

  _this->LabelColorDisabled = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelColorDefault()' */
void WidgetSetPushButtonConfig_OnSetLabelColorDefault( WidgetSetPushButtonConfig _this, 
  XColor value )
{
  if ( !EwCompColor( _this->LabelColorDefault, value ))
    return;

  _this->LabelColorDefault = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelMarginBottom()' */
void WidgetSetPushButtonConfig_OnSetLabelMarginBottom( WidgetSetPushButtonConfig _this, 
  XInt32 value )
{
  if ( _this->LabelMarginBottom == value )
    return;

  _this->LabelMarginBottom = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelMarginTop()' */
void WidgetSetPushButtonConfig_OnSetLabelMarginTop( WidgetSetPushButtonConfig _this, 
  XInt32 value )
{
  if ( _this->LabelMarginTop == value )
    return;

  _this->LabelMarginTop = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelMarginRight()' */
void WidgetSetPushButtonConfig_OnSetLabelMarginRight( WidgetSetPushButtonConfig _this, 
  XInt32 value )
{
  if ( _this->LabelMarginRight == value )
    return;

  _this->LabelMarginRight = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelMarginLeft()' */
void WidgetSetPushButtonConfig_OnSetLabelMarginLeft( WidgetSetPushButtonConfig _this, 
  XInt32 value )
{
  if ( _this->LabelMarginLeft == value )
    return;

  _this->LabelMarginLeft = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetIconTintDisabled()' */
void WidgetSetPushButtonConfig_OnSetIconTintDisabled( WidgetSetPushButtonConfig _this, 
  XColor value )
{
  if ( !EwCompColor( _this->IconTintDisabled, value ))
    return;

  _this->IconTintDisabled = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetIconTintDefault()' */
void WidgetSetPushButtonConfig_OnSetIconTintDefault( WidgetSetPushButtonConfig _this, 
  XColor value )
{
  if ( !EwCompColor( _this->IconTintDefault, value ))
    return;

  _this->IconTintDefault = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetIconMarginBottom()' */
void WidgetSetPushButtonConfig_OnSetIconMarginBottom( WidgetSetPushButtonConfig _this, 
  XInt32 value )
{
  if ( _this->IconMarginBottom == value )
    return;

  _this->IconMarginBottom = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetIconMarginTop()' */
void WidgetSetPushButtonConfig_OnSetIconMarginTop( WidgetSetPushButtonConfig _this, 
  XInt32 value )
{
  if ( _this->IconMarginTop == value )
    return;

  _this->IconMarginTop = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetIconMarginRight()' */
void WidgetSetPushButtonConfig_OnSetIconMarginRight( WidgetSetPushButtonConfig _this, 
  XInt32 value )
{
  if ( _this->IconMarginRight == value )
    return;

  _this->IconMarginRight = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetIconMarginLeft()' */
void WidgetSetPushButtonConfig_OnSetIconMarginLeft( WidgetSetPushButtonConfig _this, 
  XInt32 value )
{
  if ( _this->IconMarginLeft == value )
    return;

  _this->IconMarginLeft = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetLabelFont()' */
void WidgetSetPushButtonConfig_OnSetLabelFont( WidgetSetPushButtonConfig _this, 
  ResourcesFont value )
{
  if ( _this->LabelFont == value )
    return;

  _this->LabelFont = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetFaceFrameActive()' */
void WidgetSetPushButtonConfig_OnSetFaceFrameActive( WidgetSetPushButtonConfig _this, 
  XInt32 value )
{
  if ( _this->FaceFrameActive == value )
    return;

  _this->FaceFrameActive = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetFaceFrameFocused()' */
void WidgetSetPushButtonConfig_OnSetFaceFrameFocused( WidgetSetPushButtonConfig _this, 
  XInt32 value )
{
  if ( _this->FaceFrameFocused == value )
    return;

  _this->FaceFrameFocused = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetFaceFrameDisabled()' */
void WidgetSetPushButtonConfig_OnSetFaceFrameDisabled( WidgetSetPushButtonConfig _this, 
  XInt32 value )
{
  if ( _this->FaceFrameDisabled == value )
    return;

  _this->FaceFrameDisabled = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetFaceFrameDefault()' */
void WidgetSetPushButtonConfig_OnSetFaceFrameDefault( WidgetSetPushButtonConfig _this, 
  XInt32 value )
{
  if ( _this->FaceFrameDefault == value )
    return;

  _this->FaceFrameDefault = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetFaceActive()' */
void WidgetSetPushButtonConfig_OnSetFaceActive( WidgetSetPushButtonConfig _this, 
  ResourcesBitmap value )
{
  if ( _this->FaceActive == value )
    return;

  _this->FaceActive = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetFaceFocused()' */
void WidgetSetPushButtonConfig_OnSetFaceFocused( WidgetSetPushButtonConfig _this, 
  ResourcesBitmap value )
{
  if ( _this->FaceFocused == value )
    return;

  _this->FaceFocused = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetFaceDisabled()' */
void WidgetSetPushButtonConfig_OnSetFaceDisabled( WidgetSetPushButtonConfig _this, 
  ResourcesBitmap value )
{
  if ( _this->FaceDisabled == value )
    return;

  _this->FaceDisabled = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetFaceDefault()' */
void WidgetSetPushButtonConfig_OnSetFaceDefault( WidgetSetPushButtonConfig _this, 
  ResourcesBitmap value )
{
  if ( _this->FaceDefault == value )
    return;

  _this->FaceDefault = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::PushButtonConfig.OnSetWidgetMinSize()' */
void WidgetSetPushButtonConfig_OnSetWidgetMinSize( WidgetSetPushButtonConfig _this, 
  XPoint value )
{
  if ( !EwCompPoint( _this->WidgetMinSize, value ))
    return;

  _this->WidgetMinSize = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetWidgetConfig_onInvalidate ), ((XObject)_this ));
}

/* Variants derived from the class : 'WidgetSet::PushButtonConfig' */
EW_DEFINE_CLASS_VARIANTS( WidgetSetPushButtonConfig )
EW_END_OF_CLASS_VARIANTS( WidgetSetPushButtonConfig )

/* Virtual Method Table (VMT) for the class : 'WidgetSet::PushButtonConfig' */
EW_DEFINE_CLASS( WidgetSetPushButtonConfig, WidgetSetWidgetConfig, LabelFont, LabelColorActive, 
                 LabelColorActive, LabelColorActive, LabelColorActive, LabelColorActive, 
                 "WidgetSet::PushButtonConfig" )
EW_END_OF_CLASS( WidgetSetPushButtonConfig )

/* Initializer for the class 'WidgetSet::WidgetConfig' */
void WidgetSetWidgetConfig__Init( WidgetSetWidgetConfig _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( WidgetSetWidgetConfig );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( WidgetSetWidgetConfig );
}

/* Re-Initializer for the class 'WidgetSet::WidgetConfig' */
void WidgetSetWidgetConfig__ReInit( WidgetSetWidgetConfig _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'WidgetSet::WidgetConfig' */
void WidgetSetWidgetConfig__Done( WidgetSetWidgetConfig _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( XObject );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_.Super );
}

/* 'C' function for method : 'WidgetSet::WidgetConfig.onInvalidate()' */
void WidgetSetWidgetConfig_onInvalidate( WidgetSetWidgetConfig _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwNotifyObjObservers((XObject)_this, 0 );
}

/* Variants derived from the class : 'WidgetSet::WidgetConfig' */
EW_DEFINE_CLASS_VARIANTS( WidgetSetWidgetConfig )
EW_END_OF_CLASS_VARIANTS( WidgetSetWidgetConfig )

/* Virtual Method Table (VMT) for the class : 'WidgetSet::WidgetConfig' */
EW_DEFINE_CLASS( WidgetSetWidgetConfig, XObject, _.VMT, _.VMT, _.VMT, _.VMT, _.VMT, 
                 _.VMT, "WidgetSet::WidgetConfig" )
EW_END_OF_CLASS( WidgetSetWidgetConfig )

/* Initializer for the class 'WidgetSet::ValueDisplay' */
void WidgetSetValueDisplay__Init( WidgetSetValueDisplay _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( WidgetSetValueDisplay );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( WidgetSetValueDisplay );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Super3.viewState = CoreViewStateAlphaBlended | CoreViewStateEnabled | CoreViewStateTouchable 
  | CoreViewStateVisible;
  CoreRectView__OnSetBounds( _this, _Const000B );
}

/* Re-Initializer for the class 'WidgetSet::ValueDisplay' */
void WidgetSetValueDisplay__ReInit( WidgetSetValueDisplay _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'WidgetSet::ValueDisplay' */
void WidgetSetValueDisplay__Done( WidgetSetValueDisplay _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* 'C' function for method : 'WidgetSet::ValueDisplay.OnSetBounds()' */
void WidgetSetValueDisplay_OnSetBounds( WidgetSetValueDisplay _this, XRect value )
{
  if ( _this->Appearance != 0 )
  {
    XPoint cs = EwGetRectSize( value );
    XPoint ns = cs;
    XPoint delta;

    if ( ns.X < _this->Appearance->WidgetMinSize.X )
      ns.X = _this->Appearance->WidgetMinSize.X;

    if ( ns.Y < _this->Appearance->WidgetMinSize.Y )
      ns.Y = _this->Appearance->WidgetMinSize.Y;

    delta = EwMovePointNeg( ns, cs );

    if ( delta.X != 0 )
    {
      XBool alignToLeft = (( _this->Super3.Layout & CoreLayoutAlignToLeft ) == CoreLayoutAlignToLeft );
      XBool alignToRight = (( _this->Super3.Layout & CoreLayoutAlignToRight ) == 
        CoreLayoutAlignToRight );

      if ( alignToLeft && !alignToRight )
        value.Point2.X = ( value.Point2.X + delta.X );
      else
        if ( !alignToLeft && alignToRight )
          value.Point1.X = ( value.Point1.X - delta.X );
        else
        {
          value.Point1.X = ( value.Point1.X - ( delta.X / 2 ));
          value.Point2.X = ( value.Point1.X + ns.X );
        }
    }

    if ( delta.Y != 0 )
    {
      XBool alignToTop = (( _this->Super3.Layout & CoreLayoutAlignToTop ) == CoreLayoutAlignToTop );
      XBool alignToBottom = (( _this->Super3.Layout & CoreLayoutAlignToBottom ) 
        == CoreLayoutAlignToBottom );

      if ( alignToTop && !alignToBottom )
        value.Point2.Y = ( value.Point2.Y + delta.Y );
      else
        if ( !alignToTop && alignToBottom )
          value.Point1.Y = ( value.Point1.Y - delta.Y );
        else
        {
          value.Point1.Y = ( value.Point1.Y - ( delta.Y / 2 ));
          value.Point2.Y = ( value.Point1.Y + ns.Y );
        }
    }
  }

  CoreGroup_OnSetBounds((CoreGroup)_this, value );
}

/* The method UpdateViewState() is invoked automatically after the state of the 
   component has been changed. This method can be overridden and filled with logic 
   to ensure the visual aspect of the component does reflect its current state. 
   For example, the 'enabled' state of the component can affect its colors (disabled 
   components may appear pale). In this case the logic of the method should modify 
   the respective color properties accordingly to the current 'enabled' state. 
   The current state of the component is passed as a set in the parameter aState. 
   It reflects the very basic component state like its visibility or the ability 
   to react to user inputs. Beside this common state, the method can also involve 
   any other variables used in the component as long as they reflect its current 
   state. For example, the toggle switch component can take in account its toggle 
   state 'on' or 'off' and change accordingly the location of the slider, etc.
   Usually, this method will be invoked automatically by the framework. Optionally 
   you can request its invocation by using the method @InvalidateViewState(). */
void WidgetSetValueDisplay_UpdateViewState( WidgetSetValueDisplay _this, XSet aState )
{
  XBool needsValue;
  XBool needsUnit;
  XRect area;

  CoreGroup_UpdateViewState((CoreGroup)_this, aState );
  needsValue = (XBool)(( _this->Appearance != 0 ) && ( _this->Appearance->ValueFont 
  != 0 ));
  needsUnit = (XBool)(( _this->Appearance != 0 ) && ( _this->Appearance->UnitFont 
  != 0 ));
  area = EwGetRectORect( _this->Super2.Bounds );

  if ( needsValue && ( _this->textView1 == 0 ))
  {
    _this->textView1 = EwNewObject( ViewsText, 0 );
    CoreGroup_Add((CoreGroup)_this, ((CoreView)_this->textView1 ), 0 );
  }
  else
    if ( !needsValue && ( _this->textView1 != 0 ))
    {
      CoreGroup_Remove((CoreGroup)_this, ((CoreView)_this->textView1 ));
      _this->textView1 = 0;
    }

  if ( needsUnit && ( _this->textView2 == 0 ))
  {
    _this->textView2 = EwNewObject( ViewsText, 0 );
    CoreGroup_Add((CoreGroup)_this, ((CoreView)_this->textView2 ), 0 );
    ViewsText_OnSetEnableBidiText( _this->textView2, 1 );
  }
  else
    if ( !needsUnit && ( _this->textView2 != 0 ))
    {
      CoreGroup_Remove((CoreGroup)_this, ((CoreView)_this->textView2 ));
      _this->textView2 = 0;
    }

  if ( _this->textView1 != 0 )
  {
    XColor clr;
    XRect r = area;

    if ( _this->isNegative )
      clr = _this->Appearance->ValueColorNegative;
    else
      clr = _this->Appearance->ValueColorPositive;

    if (( _this->Appearance->Layout == WidgetSetValueDisplayLayoutAlignUnitLeftToValue ) 
        || ( _this->Appearance->Layout == WidgetSetValueDisplayLayoutAlignUnitRightToValue ))
      ViewsText_OnSetOnUpdate( _this->textView1, EwNewSlot( _this, WidgetSetValueDisplay_onLayoutViews ));
    else
      ViewsText_OnSetOnUpdate( _this->textView1, EwNullSlot );

    if ((( _this->textView2 != 0 ) && ( EwCompString( _this->Unit, 0 ) != 0 )) && 
        !EwIsRectEmpty( ViewsText_GetContentArea( _this->textView2 )))
    {
      if ( _this->Appearance->Layout == WidgetSetValueDisplayLayoutAlignValueLeftToUnit )
        r.Point2.X = ViewsText_GetContentArea( _this->textView2 ).Point1.X;

      if ( _this->Appearance->Layout == WidgetSetValueDisplayLayoutAlignValueRightToUnit )
        r.Point1.X = ViewsText_GetContentArea( _this->textView2 ).Point2.X;
    }

    CoreRectView__OnSetBounds( _this->textView1, EwNewRect( r.Point1.X, r.Point1.Y, 
    r.Point2.X - _this->Appearance->ValueMarginRight, r.Point2.Y ));
    ViewsText_OnSetFont( _this->textView1, _this->Appearance->ValueFont );
    ViewsText_OnSetAlignment( _this->textView1, _this->Appearance->ValueAlignment );
    ViewsText_OnSetString( _this->textView1, _this->valueString );
    ViewsText_OnSetColor( _this->textView1, clr );
  }

  if ( _this->textView2 != 0 )
  {
    XColor clr;
    XRect r = area;

    if ( _this->isNegative )
      clr = _this->Appearance->UnitColorNegative;
    else
      clr = _this->Appearance->UnitColorPositive;

    if (( _this->Appearance->Layout == WidgetSetValueDisplayLayoutAlignValueLeftToUnit ) 
        || ( _this->Appearance->Layout == WidgetSetValueDisplayLayoutAlignValueRightToUnit ))
      ViewsText_OnSetOnUpdate( _this->textView2, EwNewSlot( _this, WidgetSetValueDisplay_onLayoutViews ));
    else
      ViewsText_OnSetOnUpdate( _this->textView2, EwNullSlot );

    if (( _this->textView1 != 0 ) && ( EwCompString( _this->valueString, 0 ) != 
        0 ))
    {
      if ( _this->Appearance->Layout == WidgetSetValueDisplayLayoutAlignUnitLeftToValue )
        r.Point2.X = ViewsText_GetContentArea( _this->textView1 ).Point1.X;

      if ( _this->Appearance->Layout == WidgetSetValueDisplayLayoutAlignUnitRightToValue )
        r.Point1.X = ViewsText_GetContentArea( _this->textView1 ).Point2.X;
    }

    CoreRectView__OnSetBounds( _this->textView2, EwNewRect( r.Point1.X, r.Point1.Y, 
    r.Point2.X, r.Point2.Y ));
    ViewsText_OnSetFont( _this->textView2, _this->Appearance->UnitFont );
    ViewsText_OnSetAlignment( _this->textView2, _this->Appearance->UnitAlignment );
    ViewsText_OnSetString( _this->textView2, _this->Unit );
    ViewsText_OnSetColor( _this->textView2, clr );
  }
}

/* 'C' function for method : 'WidgetSet::ValueDisplay.onLayoutViews()' */
void WidgetSetValueDisplay_onLayoutViews( WidgetSetValueDisplay _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if (( _this->Appearance != 0 ) && ( _this->Appearance->Layout != WidgetSetValueDisplayLayoutUnitAndValueAreIndependent ))
    CoreGroup_InvalidateViewState((CoreGroup)_this );
}

/* 'C' function for method : 'WidgetSet::ValueDisplay.onFormatValue()' */
void WidgetSetValueDisplay_onFormatValue( WidgetSetValueDisplay _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->Appearance != 0 )
  {
    XFloat theValue = (XFloat)_this->CurrentValue;
    XInt32 noOfDigits = 0;
    XString newValueString;

    if ( _this->Precision > 0 )
      noOfDigits = 1;

    if ( theValue < 0.000000f )
      noOfDigits = noOfDigits + 1;

    newValueString = EwNewStringFloat( theValue, noOfDigits, _this->Precision );

    if ( theValue < 0.000000f )
      newValueString = EwStringRemove( newValueString, 0, 1 );

    if ( theValue >= 0.000000f )
      newValueString = EwConcatString( _this->Appearance->FormatPlusSign, newValueString );
    else
      newValueString = EwConcatString( EwLoadString( &_Const000C ), newValueString );

    if ( EwCompString( newValueString, _this->valueString ) != 0 )
    {
      _this->valueString = EwShareString( newValueString );
      _this->isNegative = (XBool)( theValue < 0.000000f );
      CoreGroup_InvalidateViewState((CoreGroup)_this );
    }
  }
  else
    if ( EwCompString( _this->valueString, 0 ) != 0 )
    {
      _this->valueString = 0;
      CoreGroup_InvalidateViewState((CoreGroup)_this );
    }
}

/* 'C' function for method : 'WidgetSet::ValueDisplay.onConfigChanged()' */
void WidgetSetValueDisplay_onConfigChanged( WidgetSetValueDisplay _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->Appearance != 0 )
    CoreRectView__OnSetBounds( _this, _this->Super2.Bounds );

  EwPostSignal( EwNewSlot( _this, WidgetSetValueDisplay_onFormatValue ), ((XObject)_this ));
  CoreGroup_InvalidateViewState((CoreGroup)_this );
}

/* 'C' function for method : 'WidgetSet::ValueDisplay.onOutlet()' */
void WidgetSetValueDisplay_onOutlet( WidgetSetValueDisplay _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->Outlet.Object != 0 )
    WidgetSetValueDisplay_OnSetCurrentValue( _this, EwOnGetInt32( _this->Outlet ));
}

/* 'C' function for method : 'WidgetSet::ValueDisplay.OnSetOutlet()' */
void WidgetSetValueDisplay_OnSetOutlet( WidgetSetValueDisplay _this, XRef value )
{
  if ( !EwCompRef( _this->Outlet, value ))
    return;

  if ( _this->Outlet.Object != 0 )
    EwDetachRefObserver( EwNewSlot( _this, WidgetSetValueDisplay_onOutlet ), _this->Outlet, 
      0 );

  _this->Outlet = value;

  if ( value.Object != 0 )
    EwAttachRefObserver( EwNewSlot( _this, WidgetSetValueDisplay_onOutlet ), value, 
      0 );

  if ( value.Object != 0 )
    EwPostSignal( EwNewSlot( _this, WidgetSetValueDisplay_onOutlet ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ValueDisplay.OnSetUnit()' */
void WidgetSetValueDisplay_OnSetUnit( WidgetSetValueDisplay _this, XString value )
{
  if ( !EwCompString( _this->Unit, value ))
    return;

  _this->Unit = EwShareString( value );
  CoreGroup_InvalidateViewState((CoreGroup)_this );
}

/* 'C' function for method : 'WidgetSet::ValueDisplay.OnSetPrecision()' */
void WidgetSetValueDisplay_OnSetPrecision( WidgetSetValueDisplay _this, XInt32 value )
{
  if ( _this->Precision == value )
    return;

  _this->Precision = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetValueDisplay_onFormatValue ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ValueDisplay.OnSetCurrentValue()' */
void WidgetSetValueDisplay_OnSetCurrentValue( WidgetSetValueDisplay _this, XInt32 
  value )
{
  if ( _this->CurrentValue == value )
    return;

  _this->CurrentValue = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetValueDisplay_onFormatValue ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ValueDisplay.OnSetAppearance()' */
void WidgetSetValueDisplay_OnSetAppearance( WidgetSetValueDisplay _this, WidgetSetValueDisplayConfig 
  value )
{
  if ( _this->Appearance == value )
    return;

  if ( _this->Appearance != 0 )
    EwDetachObjObserver( EwNewSlot( _this, WidgetSetValueDisplay_onConfigChanged ), 
      (XObject)_this->Appearance, 0 );

  _this->Appearance = value;

  if ( value != 0 )
    EwAttachObjObserver( EwNewSlot( _this, WidgetSetValueDisplay_onConfigChanged ), 
      (XObject)value, 0 );

  EwPostSignal( EwNewSlot( _this, WidgetSetValueDisplay_onConfigChanged ), ((XObject)_this ));
}

/* Variants derived from the class : 'WidgetSet::ValueDisplay' */
EW_DEFINE_CLASS_VARIANTS( WidgetSetValueDisplay )
EW_END_OF_CLASS_VARIANTS( WidgetSetValueDisplay )

/* Virtual Method Table (VMT) for the class : 'WidgetSet::ValueDisplay' */
EW_DEFINE_CLASS( WidgetSetValueDisplay, CoreGroup, textView2, Outlet, Outlet, valueString, 
                 valueString, Precision, "WidgetSet::ValueDisplay" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  WidgetSetValueDisplay_OnSetBounds,
  CoreGroup_OnSetFocus,
  CoreGroup_OnSetOpacity,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  WidgetSetValueDisplay_UpdateViewState,
  CoreGroup_InvalidateArea,
EW_END_OF_CLASS( WidgetSetValueDisplay )

/* Initializer for the class 'WidgetSet::HorizontalValueBar' */
void WidgetSetHorizontalValueBar__Init( WidgetSetHorizontalValueBar _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( WidgetSetHorizontalValueBar );

  /* ... then construct all embedded objects */
  EffectsFloatEffect__Init( &_this->FloatEffect, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( WidgetSetHorizontalValueBar );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const000D );
  _this->setupCurrentPos = 1;
  EffectsEffect_OnSetTiming((EffectsEffect)&_this->FloatEffect, EffectsTimingBack_Out );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->FloatEffect, 1 );
  _this->MaxValue = 100;
  _this->CurrentValue = 50;
  _this->FloatEffect.Super1.OnFinished = EwNewSlot( _this, WidgetSetHorizontalValueBar_onEndFloatEffect );
  _this->FloatEffect.Super1.OnAnimate = EwNewSlot( _this, WidgetSetHorizontalValueBar_onFloatEffect );
}

/* Re-Initializer for the class 'WidgetSet::HorizontalValueBar' */
void WidgetSetHorizontalValueBar__ReInit( WidgetSetHorizontalValueBar _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  EffectsFloatEffect__ReInit( &_this->FloatEffect );
}

/* Finalizer method for the class 'WidgetSet::HorizontalValueBar' */
void WidgetSetHorizontalValueBar__Done( WidgetSetHorizontalValueBar _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  EffectsFloatEffect__Done( &_this->FloatEffect );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* 'C' function for method : 'WidgetSet::HorizontalValueBar.OnSetBounds()' */
void WidgetSetHorizontalValueBar_OnSetBounds( WidgetSetHorizontalValueBar _this, 
  XRect value )
{
  if ( _this->Appearance != 0 )
  {
    XPoint cs = EwGetRectSize( value );
    XPoint ns = cs;
    XPoint delta;

    if ( ns.X < _this->Appearance->WidgetMinSize.X )
      ns.X = _this->Appearance->WidgetMinSize.X;

    if ( ns.Y < _this->Appearance->WidgetMinSize.Y )
      ns.Y = _this->Appearance->WidgetMinSize.Y;

    delta = EwMovePointNeg( ns, cs );

    if ( delta.X != 0 )
    {
      XBool alignToLeft = (( _this->Super3.Layout & CoreLayoutAlignToLeft ) == CoreLayoutAlignToLeft );
      XBool alignToRight = (( _this->Super3.Layout & CoreLayoutAlignToRight ) == 
        CoreLayoutAlignToRight );

      if ( alignToLeft && !alignToRight )
        value.Point2.X = ( value.Point2.X + delta.X );
      else
        if ( !alignToLeft && alignToRight )
          value.Point1.X = ( value.Point1.X - delta.X );
        else
        {
          value.Point1.X = ( value.Point1.X - ( delta.X / 2 ));
          value.Point2.X = ( value.Point1.X + ns.X );
        }
    }

    if ( delta.Y != 0 )
    {
      XBool alignToTop = (( _this->Super3.Layout & CoreLayoutAlignToTop ) == CoreLayoutAlignToTop );
      XBool alignToBottom = (( _this->Super3.Layout & CoreLayoutAlignToBottom ) 
        == CoreLayoutAlignToBottom );

      if ( alignToTop && !alignToBottom )
        value.Point2.Y = ( value.Point2.Y + delta.Y );
      else
        if ( !alignToTop && alignToBottom )
          value.Point1.Y = ( value.Point1.Y - delta.Y );
        else
        {
          value.Point1.Y = ( value.Point1.Y - ( delta.Y / 2 ));
          value.Point2.Y = ( value.Point1.Y + ns.Y );
        }
    }
  }

  CoreGroup_OnSetBounds((CoreGroup)_this, value );
}

/* The method UpdateViewState() is invoked automatically after the state of the 
   component has been changed. This method can be overridden and filled with logic 
   to ensure the visual aspect of the component does reflect its current state. 
   For example, the 'enabled' state of the component can affect its colors (disabled 
   components may appear pale). In this case the logic of the method should modify 
   the respective color properties accordingly to the current 'enabled' state. 
   The current state of the component is passed as a set in the parameter aState. 
   It reflects the very basic component state like its visibility or the ability 
   to react to user inputs. Beside this common state, the method can also involve 
   any other variables used in the component as long as they reflect its current 
   state. For example, the toggle switch component can take in account its toggle 
   state 'on' or 'off' and change accordingly the location of the slider, etc.
   Usually, this method will be invoked automatically by the framework. Optionally 
   you can request its invocation by using the method @InvalidateViewState(). */
void WidgetSetHorizontalValueBar_UpdateViewState( WidgetSetHorizontalValueBar _this, 
  XSet aState )
{
  XBool needsTrackLeft;
  XBool needsTrackRight;
  XBool restack;
  XRect area;
  XInt32 pos;

  CoreGroup_UpdateViewState((CoreGroup)_this, aState );
  needsTrackLeft = (XBool)(( _this->Appearance != 0 ) && ( _this->Appearance->TrackLeft 
  != 0 ));
  needsTrackRight = (XBool)(( _this->Appearance != 0 ) && ( _this->Appearance->TrackRight 
  != 0 ));
  restack = 0;
  area = EwGetRectORect( _this->Super2.Bounds );

  if ( needsTrackLeft && ( _this->frameView2 == 0 ))
  {
    _this->frameView2 = EwNewObject( ViewsFrame, 0 );
    CoreGroup_Add((CoreGroup)_this, ((CoreView)_this->frameView2 ), 0 );
    restack = 1;
  }
  else
    if ( !needsTrackLeft && ( _this->frameView2 != 0 ))
    {
      CoreGroup_Remove((CoreGroup)_this, ((CoreView)_this->frameView2 ));
      _this->frameView2 = 0;
    }

  if ( needsTrackRight && ( _this->frameView3 == 0 ))
  {
    _this->frameView3 = EwNewObject( ViewsFrame, 0 );
    CoreGroup_Add((CoreGroup)_this, ((CoreView)_this->frameView3 ), 0 );
    restack = 1;
  }
  else
    if ( !needsTrackRight && ( _this->frameView3 != 0 ))
    {
      CoreGroup_Remove((CoreGroup)_this, ((CoreView)_this->frameView3 ));
      _this->frameView3 = 0;
    }

  if ( restack )
  {
    if ( _this->frameView2 != 0 )
      CoreGroup_RestackTop((CoreGroup)_this, ((CoreView)_this->frameView2 ));

    if ( _this->frameView3 != 0 )
      CoreGroup_RestackTop((CoreGroup)_this, ((CoreView)_this->frameView3 ));
  }

  if ( _this->frameView2 != 0 )
  {
    ViewsFrame_OnSetBitmap( _this->frameView2, _this->Appearance->TrackLeft );
    ViewsFrame_OnSetColor( _this->frameView2, _Const0008 );
    ViewsFrame_OnSetEdges( _this->frameView2, GraphicsEdgesBottom | GraphicsEdgesInterior 
    | GraphicsEdgesLeft | GraphicsEdgesTop );

    if ( _this->Appearance->TrackLeftFrame < 0 )
    {
      ViewsFrame_OnSetAnimated( _this->frameView2, 1 );
      ViewsFrame_OnSetFrameNumber( _this->frameView2, 0 );
    }
    else
    {
      ViewsFrame_OnSetAnimated( _this->frameView2, 0 );
      ViewsFrame_OnSetFrameNumber( _this->frameView2, _this->Appearance->TrackLeftFrame );
    }
  }

  if ( _this->frameView3 != 0 )
  {
    ViewsFrame_OnSetBitmap( _this->frameView3, _this->Appearance->TrackRight );
    ViewsFrame_OnSetColor( _this->frameView3, _Const0008 );
    ViewsFrame_OnSetEdges( _this->frameView3, GraphicsEdgesBottom | GraphicsEdgesInterior 
    | GraphicsEdgesRight | GraphicsEdgesTop );

    if ( _this->Appearance->TrackRightFrame < 0 )
    {
      ViewsFrame_OnSetAnimated( _this->frameView3, 1 );
      ViewsFrame_OnSetFrameNumber( _this->frameView3, 0 );
    }
    else
    {
      ViewsFrame_OnSetAnimated( _this->frameView3, 0 );
      ViewsFrame_OnSetFrameNumber( _this->frameView3, _this->Appearance->TrackRightFrame );
    }
  }

  pos = (XInt32)((XFloat)EwGetRectW( area ) * _this->currentPos );

  if ( pos < 0 )
    pos = 0;

  if ( pos > EwGetRectW( area ))
    pos = EwGetRectW( area );

  if (( _this->frameView2 != 0 ) && ( _this->frameView2->Bitmap != 0 ))
  {
    XPoint s = _this->frameView2->Bitmap->FrameSize;
    CoreRectView__OnSetBounds( _this->frameView2, EwNewRect( 0, ( EwGetRectH( area ) 
    / 2 ) - ( s.Y / 2 ), pos, (( EwGetRectH( area ) / 2 ) - ( s.Y / 2 )) + s.Y ));
    ViewsFrame_OnSetNoEdgesLimit( _this->frameView2, EwSetPointX( _this->frameView2->NoEdgesLimit, 
    EwGetRectW( area ) - ( s.X / 3 )));
    ViewsFrame_OnSetVisible( _this->frameView2, 1 );
  }

  if (( _this->frameView3 != 0 ) && ( _this->frameView3->Bitmap != 0 ))
  {
    XPoint s = _this->frameView3->Bitmap->FrameSize;
    CoreRectView__OnSetBounds( _this->frameView3, EwNewRect( pos, ( EwGetRectH( 
    area ) / 2 ) - ( s.Y / 2 ), EwGetRectW( area ), (( EwGetRectH( area ) / 2 ) 
    - ( s.Y / 2 )) + s.Y ));
    ViewsFrame_OnSetNoEdgesLimit( _this->frameView3, EwSetPointX( _this->frameView3->NoEdgesLimit, 
    EwGetRectW( area ) - ( s.X / 3 )));
    ViewsFrame_OnSetVisible( _this->frameView3, 1 );
  }
}

/* 'C' function for method : 'WidgetSet::HorizontalValueBar.onUpdatePos()' */
void WidgetSetHorizontalValueBar_onUpdatePos( WidgetSetHorizontalValueBar _this, 
  XObject sender )
{
  XFloat newPos;
  XInt32 swingDuration;
  XFloat ratio;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  newPos = _this->currentPos;
  swingDuration = 0;

  if ( _this->Appearance != 0 )
    swingDuration = 500;

  if ( _this->setupCurrentPos && ( _this->MaxValue != 0 ))
  {
    _this->currentPos = 0.000000f;
    newPos = _this->currentPos;
    _this->setupCurrentPos = 0;
  }

  if ( _this->MaxValue != 0 )
    newPos = (XFloat)WidgetSetHorizontalValueBar_OnGetCurrentValue( _this ) / (XFloat)_this->MaxValue;

  if ( newPos == _this->currentPos )
    return;

  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->FloatEffect, 0 );

  if ( swingDuration <= 0 )
  {
    _this->currentPos = newPos;
    CoreGroup_InvalidateViewState((CoreGroup)_this );
    return;
  }

  ratio = newPos - _this->currentPos;

  if ( ratio < 0.000000f )
    ratio = -ratio;

  EffectsEffect_OnSetTiming((EffectsEffect)&_this->FloatEffect, EffectsTimingBack_Out );
  _this->FloatEffect.Value1 = _this->currentPos;
  _this->FloatEffect.Value2 = newPos;
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->FloatEffect, ( 10 + ( 
  swingDuration / 2 )) + ((XInt32)((XFloat)swingDuration * ratio ) / 2 ));
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->FloatEffect, 1 );
}

/* 'C' function for method : 'WidgetSet::HorizontalValueBar.onEndFloatEffect()' */
void WidgetSetHorizontalValueBar_onEndFloatEffect( WidgetSetHorizontalValueBar _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( sender );
}

/* 'C' function for method : 'WidgetSet::HorizontalValueBar.onFloatEffect()' */
void WidgetSetHorizontalValueBar_onFloatEffect( WidgetSetHorizontalValueBar _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  _this->currentPos = _this->FloatEffect.Value;
  CoreGroup_InvalidateViewState((CoreGroup)_this );
}

/* 'C' function for method : 'WidgetSet::HorizontalValueBar.onConfigChanged()' */
void WidgetSetHorizontalValueBar_onConfigChanged( WidgetSetHorizontalValueBar _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwPostSignal( EwNewSlot( _this, WidgetSetHorizontalValueBar_onUpdatePos ), ((XObject)_this ));

  if ( _this->Appearance != 0 )
    CoreRectView__OnSetBounds( _this, _this->Super2.Bounds );

  CoreGroup_InvalidateViewState((CoreGroup)_this );
}

/* 'C' function for method : 'WidgetSet::HorizontalValueBar.onOutlet()' */
void WidgetSetHorizontalValueBar_onOutlet( WidgetSetHorizontalValueBar _this, XObject 
  sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->Outlet.Object != 0 )
    WidgetSetHorizontalValueBar_OnSetCurrentValue( _this, EwOnGetInt32( _this->Outlet ));
}

/* 'C' function for method : 'WidgetSet::HorizontalValueBar.OnSetOutlet()' */
void WidgetSetHorizontalValueBar_OnSetOutlet( WidgetSetHorizontalValueBar _this, 
  XRef value )
{
  if ( !EwCompRef( _this->Outlet, value ))
    return;

  if ( _this->Outlet.Object != 0 )
    EwDetachRefObserver( EwNewSlot( _this, WidgetSetHorizontalValueBar_onOutlet ), 
      _this->Outlet, 0 );

  _this->Outlet = value;

  if ( value.Object != 0 )
    EwAttachRefObserver( EwNewSlot( _this, WidgetSetHorizontalValueBar_onOutlet ), 
      value, 0 );

  if ( value.Object != 0 )
    EwPostSignal( EwNewSlot( _this, WidgetSetHorizontalValueBar_onOutlet ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::HorizontalValueBar.OnSetMaxValue()' */
void WidgetSetHorizontalValueBar_OnSetMaxValue( WidgetSetHorizontalValueBar _this, 
  XInt32 value )
{
  if ( _this->MaxValue == value )
    return;

  _this->MaxValue = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetHorizontalValueBar_onUpdatePos ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::HorizontalValueBar.OnGetCurrentValue()' */
XInt32 WidgetSetHorizontalValueBar_OnGetCurrentValue( WidgetSetHorizontalValueBar _this )
{
  XInt32 value = _this->CurrentValue;

  if ( 0 > _this->MaxValue )
  {
    if ( value < _this->MaxValue )
      value = _this->MaxValue;

    if ( value > 0 )
      value = 0;
  }
  else
  {
    if ( value < 0 )
      value = 0;

    if ( value > _this->MaxValue )
      value = _this->MaxValue;
  }

  return value;
}

/* 'C' function for method : 'WidgetSet::HorizontalValueBar.OnSetCurrentValue()' */
void WidgetSetHorizontalValueBar_OnSetCurrentValue( WidgetSetHorizontalValueBar _this, 
  XInt32 value )
{
  if ( _this->CurrentValue == value )
    return;

  _this->CurrentValue = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetHorizontalValueBar_onUpdatePos ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::HorizontalValueBar.OnSetAppearance()' */
void WidgetSetHorizontalValueBar_OnSetAppearance( WidgetSetHorizontalValueBar _this, 
  WidgetSetHorizontalValueBarConfig value )
{
  if ( _this->Appearance == value )
    return;

  if ( _this->Appearance != 0 )
    EwDetachObjObserver( EwNewSlot( _this, WidgetSetHorizontalValueBar_onConfigChanged ), 
      (XObject)_this->Appearance, 0 );

  _this->Appearance = value;

  if ( value != 0 )
    EwAttachObjObserver( EwNewSlot( _this, WidgetSetHorizontalValueBar_onConfigChanged ), 
      (XObject)value, 0 );

  EwPostSignal( EwNewSlot( _this, WidgetSetHorizontalValueBar_onConfigChanged ), 
    ((XObject)_this ));
}

/* Variants derived from the class : 'WidgetSet::HorizontalValueBar' */
EW_DEFINE_CLASS_VARIANTS( WidgetSetHorizontalValueBar )
EW_END_OF_CLASS_VARIANTS( WidgetSetHorizontalValueBar )

/* Virtual Method Table (VMT) for the class : 'WidgetSet::HorizontalValueBar' */
EW_DEFINE_CLASS( WidgetSetHorizontalValueBar, CoreGroup, frameView3, Outlet, Outlet, 
                 FloatEffect, currentPos, currentPos, "WidgetSet::HorizontalValueBar" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  WidgetSetHorizontalValueBar_OnSetBounds,
  CoreGroup_OnSetFocus,
  CoreGroup_OnSetOpacity,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  WidgetSetHorizontalValueBar_UpdateViewState,
  CoreGroup_InvalidateArea,
EW_END_OF_CLASS( WidgetSetHorizontalValueBar )

/* Initializer for the class 'WidgetSet::Gauge' */
void WidgetSetGauge__Init( WidgetSetGauge _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( WidgetSetGauge );

  /* ... then construct all embedded objects */
  EffectsFloatEffect__Init( &_this->FloatEffect, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( WidgetSetGauge );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const000E );
  CoreGroup_OnSetEnabled((CoreGroup)_this, 0 );
  _this->setupCurrentAngle = 1;
  EffectsEffect_OnSetTiming((EffectsEffect)&_this->FloatEffect, EffectsTimingBack_Out );
  EffectsEffect_OnSetNoOfCycles((EffectsEffect)&_this->FloatEffect, 1 );
  _this->MaxValue = 100;
  _this->CurrentValue = 50;
  _this->FloatEffect.Super1.OnFinished = EwNewSlot( _this, WidgetSetGauge_onEndFloatEffect );
  _this->FloatEffect.Super1.OnAnimate = EwNewSlot( _this, WidgetSetGauge_onFloatEffect );
}

/* Re-Initializer for the class 'WidgetSet::Gauge' */
void WidgetSetGauge__ReInit( WidgetSetGauge _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  EffectsFloatEffect__ReInit( &_this->FloatEffect );
}

/* Finalizer method for the class 'WidgetSet::Gauge' */
void WidgetSetGauge__Done( WidgetSetGauge _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  EffectsFloatEffect__Done( &_this->FloatEffect );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* 'C' function for method : 'WidgetSet::Gauge.OnSetBounds()' */
void WidgetSetGauge_OnSetBounds( WidgetSetGauge _this, XRect value )
{
  if ( _this->Appearance != 0 )
  {
    XPoint cs = EwGetRectSize( value );
    XPoint ns = cs;
    XPoint delta;

    if ( ns.X < _this->Appearance->WidgetMinSize.X )
      ns.X = _this->Appearance->WidgetMinSize.X;

    if ( ns.Y < _this->Appearance->WidgetMinSize.Y )
      ns.Y = _this->Appearance->WidgetMinSize.Y;

    delta = EwMovePointNeg( ns, cs );

    if ( delta.X != 0 )
    {
      XBool alignToLeft = (( _this->Super3.Layout & CoreLayoutAlignToLeft ) == CoreLayoutAlignToLeft );
      XBool alignToRight = (( _this->Super3.Layout & CoreLayoutAlignToRight ) == 
        CoreLayoutAlignToRight );

      if ( alignToLeft && !alignToRight )
        value.Point2.X = ( value.Point2.X + delta.X );
      else
        if ( !alignToLeft && alignToRight )
          value.Point1.X = ( value.Point1.X - delta.X );
        else
        {
          value.Point1.X = ( value.Point1.X - ( delta.X / 2 ));
          value.Point2.X = ( value.Point1.X + ns.X );
        }
    }

    if ( delta.Y != 0 )
    {
      XBool alignToTop = (( _this->Super3.Layout & CoreLayoutAlignToTop ) == CoreLayoutAlignToTop );
      XBool alignToBottom = (( _this->Super3.Layout & CoreLayoutAlignToBottom ) 
        == CoreLayoutAlignToBottom );

      if ( alignToTop && !alignToBottom )
        value.Point2.Y = ( value.Point2.Y + delta.Y );
      else
        if ( !alignToTop && alignToBottom )
          value.Point1.Y = ( value.Point1.Y - delta.Y );
        else
        {
          value.Point1.Y = ( value.Point1.Y - ( delta.Y / 2 ));
          value.Point2.Y = ( value.Point1.Y + ns.Y );
        }
    }
  }

  CoreGroup_OnSetBounds((CoreGroup)_this, value );
}

/* The method UpdateViewState() is invoked automatically after the state of the 
   component has been changed. This method can be overridden and filled with logic 
   to ensure the visual aspect of the component does reflect its current state. 
   For example, the 'enabled' state of the component can affect its colors (disabled 
   components may appear pale). In this case the logic of the method should modify 
   the respective color properties accordingly to the current 'enabled' state. 
   The current state of the component is passed as a set in the parameter aState. 
   It reflects the very basic component state like its visibility or the ability 
   to react to user inputs. Beside this common state, the method can also involve 
   any other variables used in the component as long as they reflect its current 
   state. For example, the toggle switch component can take in account its toggle 
   state 'on' or 'off' and change accordingly the location of the slider, etc.
   Usually, this method will be invoked automatically by the framework. Optionally 
   you can request its invocation by using the method @InvalidateViewState(). */
void WidgetSetGauge_UpdateViewState( WidgetSetGauge _this, XSet aState )
{
  XBool needsScale;
  XBool needsNeedle;
  XBool needsPath1;
  XBool restack;
  XRect area;

  CoreGroup_UpdateViewState((CoreGroup)_this, aState );
  needsScale = (XBool)(( _this->Appearance != 0 ) && ( _this->Appearance->Scale 
  != 0 ));
  needsNeedle = (XBool)(( _this->Appearance != 0 ) && ( _this->Appearance->Needle 
  != 0 ));
  needsPath1 = (XBool)(( _this->Appearance != 0 ) && ( _this->Appearance->TrackLeftThickness 
  > 0.000000f ));
  restack = 0;
  area = EwGetRectORect( _this->Super2.Bounds );

  if ( needsScale && ( _this->imageView1 == 0 ))
  {
    _this->imageView1 = EwNewObject( ViewsImage, 0 );
    CoreGroup_Add((CoreGroup)_this, ((CoreView)_this->imageView1 ), 0 );
    restack = 1;
  }
  else
    if ( !needsScale && ( _this->imageView1 != 0 ))
    {
      CoreGroup_Remove((CoreGroup)_this, ((CoreView)_this->imageView1 ));
      _this->imageView1 = 0;
    }

  if ( needsNeedle && ( _this->warpView == 0 ))
  {
    _this->warpView = EwNewObject( ViewsWarpImage, 0 );
    CoreGroup_Add((CoreGroup)_this, ((CoreView)_this->warpView ), 0 );
    restack = 1;
  }
  else
    if ( !needsNeedle && ( _this->warpView != 0 ))
    {
      CoreGroup_Remove((CoreGroup)_this, ((CoreView)_this->warpView ));
      _this->warpView = 0;
    }

  if ( needsPath1 && ( _this->path1 == 0 ))
  {
    _this->path1 = EwNewObject( GraphicsArcPath, 0 );
    _this->pathView1 = EwNewObject( ViewsFillPath, 0 );
    CoreGroup_Add((CoreGroup)_this, ((CoreView)_this->pathView1 ), 0 );
    ViewsFillPath_OnSetPath( _this->pathView1, ((GraphicsPath)_this->path1 ));
    ViewsFillPath_OnSetFillRule( _this->pathView1, GraphicsFillRuleNonZero );
    restack = 1;
  }
  else
    if ( !needsPath1 && ( _this->path1 != 0 ))
    {
      CoreGroup_Remove((CoreGroup)_this, ((CoreView)_this->pathView1 ));
      _this->pathView1 = 0;
      _this->path1 = 0;
    }

  if ( restack )
  {
    if ( _this->imageView1 != 0 )
      CoreGroup_RestackTop((CoreGroup)_this, ((CoreView)_this->imageView1 ));

    if ( _this->pathView1 != 0 )
      CoreGroup_RestackTop((CoreGroup)_this, ((CoreView)_this->pathView1 ));

    if ( _this->warpView != 0 )
      CoreGroup_RestackTop((CoreGroup)_this, ((CoreView)_this->warpView ));
  }

  if ( _this->imageView1 != 0 )
  {
    ViewsImage_OnSetBitmap( _this->imageView1, _this->Appearance->Scale );
    ViewsImage_OnSetColor( _this->imageView1, _Const0008 );
    CoreRectView__OnSetBounds( _this->imageView1, area );
    ViewsImage_OnSetAnimated( _this->imageView1, 1 );
    ViewsImage_OnSetFrameNumber( _this->imageView1, 0 );
  }

  if ( _this->warpView != 0 )
  {
    GraphicsWarpMatrix matrix = EwNewObject( GraphicsWarpMatrix, 0 );
    GraphicsWarpMatrix_Rotate( matrix, 0.000000f, 0.000000f, -_this->currentAngle );
    ViewsWarpView_OnSetSourceAnchor((ViewsWarpView)_this->warpView, _this->Appearance->NeedlePivot );
    ViewsWarpImage_OnSetBitmap( _this->warpView, _this->Appearance->Needle );
    ViewsWarpImage_OnSetColor( _this->warpView, _Const0008 );
    ViewsWarpImage_OnSetAnimated( _this->warpView, 1 );
    ViewsWarpImage_OnSetFrameNumber( _this->warpView, 0 );
    ViewsWarpView_Warp3D((ViewsWarpView)_this->warpView, EwMovePointPos( EwGetRectCenter( 
    area ), _this->Appearance->CenterOffset ), matrix );
  }

  if ( _this->pathView1 != 0 )
  {
    CoreRectView__OnSetBounds( _this->pathView1, area );
    ViewsFillPath_OnSetOffset( _this->pathView1, EwMovePointPos( EwGetRectCenter( 
    area ), _this->Appearance->CenterOffset ));
    ViewsFillPath_OnSetColor( _this->pathView1, _this->Appearance->TrackLeftColor );
  }

  if ( _this->path1 != 0 )
  {
    GraphicsArcPath_OnSetStyle( _this->path1, GraphicsArcStylePie );
    GraphicsArcPath_OnSetInnerRadius( _this->path1, _this->Appearance->TrackLeftRadius 
    - ( _this->Appearance->TrackLeftThickness * 0.500000f ));
    GraphicsArcPath_OnSetRadius( _this->path1, GraphicsArcPath_OnGetInnerRadius( 
    _this->path1 ) + _this->Appearance->TrackLeftThickness );
    GraphicsArcPath_OnSetStartAngle( _this->path1, -_this->Appearance->NeedleMinAngle );
    GraphicsArcPath_OnSetEndAngle( _this->path1, -_this->currentAngle );

    if ( _this->Appearance->TrackLeftRoundedStart )
      GraphicsArcPath_OnSetStyle( _this->path1, GraphicsArcStylePieRoundedStart );
    else
      GraphicsArcPath_OnSetStyle( _this->path1, GraphicsArcStylePie );
  }
}

/* 'C' function for method : 'WidgetSet::Gauge.onUpdateAngle()' */
void WidgetSetGauge_onUpdateAngle( WidgetSetGauge _this, XObject sender )
{
  XFloat angleMin;
  XFloat angleMax;
  XFloat newAngle;
  XInt32 swingDuration;
  XFloat ratio;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  angleMin = 135.000000f;
  angleMax = 45.000000f;
  newAngle = _this->currentAngle;
  swingDuration = 0;

  if ( _this->Appearance != 0 )
  {
    angleMin = _this->Appearance->NeedleMinAngle;
    angleMax = _this->Appearance->NeedleMaxAngle;
    swingDuration = _this->Appearance->SwingDuration;
  }

  if ( _this->setupCurrentAngle && ( _this->MaxValue != 0 ))
  {
    _this->currentAngle = angleMin;
    newAngle = _this->currentAngle;
    _this->setupCurrentAngle = 0;
  }

  if ( _this->MaxValue != 0 )
    newAngle = (((XFloat)WidgetSetGauge_OnGetCurrentValue( _this ) * ( angleMax 
    - angleMin )) / (XFloat)_this->MaxValue ) + angleMin;

  if ( newAngle == _this->currentAngle )
    return;

  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->FloatEffect, 0 );

  if (( swingDuration <= 0 ) || ( angleMax == angleMin ))
  {
    _this->currentAngle = newAngle;
    CoreGroup_InvalidateViewState((CoreGroup)_this );
    return;
  }

  ratio = ( newAngle - _this->currentAngle ) / ( angleMax - angleMin );

  if ( ratio < 0.000000f )
    ratio = -ratio;

  if ( _this->Appearance->SwingElastic )
    EffectsEffect_OnSetTiming((EffectsEffect)&_this->FloatEffect, EffectsTimingBack_Out );
  else
    EffectsEffect_OnSetTiming((EffectsEffect)&_this->FloatEffect, EffectsTimingFastIn_EaseOut );

  _this->FloatEffect.Value1 = _this->currentAngle;
  _this->FloatEffect.Value2 = newAngle;
  EffectsEffect_OnSetCycleDuration((EffectsEffect)&_this->FloatEffect, ( 10 + ( 
  swingDuration / 2 )) + ((XInt32)((XFloat)swingDuration * ratio ) / 2 ));
  EffectsEffect_OnSetEnabled((EffectsEffect)&_this->FloatEffect, 1 );
}

/* 'C' function for method : 'WidgetSet::Gauge.onEndFloatEffect()' */
void WidgetSetGauge_onEndFloatEffect( WidgetSetGauge _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( sender );
}

/* 'C' function for method : 'WidgetSet::Gauge.onFloatEffect()' */
void WidgetSetGauge_onFloatEffect( WidgetSetGauge _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  _this->currentAngle = _this->FloatEffect.Value;
  CoreGroup_InvalidateViewState((CoreGroup)_this );
}

/* 'C' function for method : 'WidgetSet::Gauge.onConfigChanged()' */
void WidgetSetGauge_onConfigChanged( WidgetSetGauge _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  EwPostSignal( EwNewSlot( _this, WidgetSetGauge_onUpdateAngle ), ((XObject)_this ));

  if ( _this->Appearance != 0 )
    CoreRectView__OnSetBounds( _this, _this->Super2.Bounds );

  CoreGroup_InvalidateViewState((CoreGroup)_this );
}

/* 'C' function for method : 'WidgetSet::Gauge.onOutlet()' */
void WidgetSetGauge_onOutlet( WidgetSetGauge _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->Outlet.Object != 0 )
    WidgetSetGauge_OnSetCurrentValue( _this, EwOnGetInt32( _this->Outlet ));
}

/* 'C' function for method : 'WidgetSet::Gauge.OnSetOutlet()' */
void WidgetSetGauge_OnSetOutlet( WidgetSetGauge _this, XRef value )
{
  if ( !EwCompRef( _this->Outlet, value ))
    return;

  if ( _this->Outlet.Object != 0 )
    EwDetachRefObserver( EwNewSlot( _this, WidgetSetGauge_onOutlet ), _this->Outlet, 
      0 );

  _this->Outlet = value;

  if ( value.Object != 0 )
    EwAttachRefObserver( EwNewSlot( _this, WidgetSetGauge_onOutlet ), value, 0 );

  if ( value.Object != 0 )
    EwPostSignal( EwNewSlot( _this, WidgetSetGauge_onOutlet ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::Gauge.OnSetMaxValue()' */
void WidgetSetGauge_OnSetMaxValue( WidgetSetGauge _this, XInt32 value )
{
  if ( _this->MaxValue == value )
    return;

  _this->MaxValue = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetGauge_onUpdateAngle ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::Gauge.OnGetCurrentValue()' */
XInt32 WidgetSetGauge_OnGetCurrentValue( WidgetSetGauge _this )
{
  XInt32 value = _this->CurrentValue;

  if ( 0 > _this->MaxValue )
  {
    if ( value < _this->MaxValue )
      value = _this->MaxValue;

    if ( value > 0 )
      value = 0;
  }
  else
  {
    if ( value < 0 )
      value = 0;

    if ( value > _this->MaxValue )
      value = _this->MaxValue;
  }

  return value;
}

/* 'C' function for method : 'WidgetSet::Gauge.OnSetCurrentValue()' */
void WidgetSetGauge_OnSetCurrentValue( WidgetSetGauge _this, XInt32 value )
{
  if ( _this->CurrentValue == value )
    return;

  _this->CurrentValue = value;
  EwPostSignal( EwNewSlot( _this, WidgetSetGauge_onUpdateAngle ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::Gauge.OnSetAppearance()' */
void WidgetSetGauge_OnSetAppearance( WidgetSetGauge _this, WidgetSetGaugeConfig 
  value )
{
  if ( _this->Appearance == value )
    return;

  if ( _this->Appearance != 0 )
    EwDetachObjObserver( EwNewSlot( _this, WidgetSetGauge_onConfigChanged ), (XObject)_this->Appearance, 
      0 );

  _this->Appearance = value;

  if ( value != 0 )
    EwAttachObjObserver( EwNewSlot( _this, WidgetSetGauge_onConfigChanged ), (XObject)value, 
      0 );

  EwPostSignal( EwNewSlot( _this, WidgetSetGauge_onConfigChanged ), ((XObject)_this ));
}

/* Variants derived from the class : 'WidgetSet::Gauge' */
EW_DEFINE_CLASS_VARIANTS( WidgetSetGauge )
EW_END_OF_CLASS_VARIANTS( WidgetSetGauge )

/* Virtual Method Table (VMT) for the class : 'WidgetSet::Gauge' */
EW_DEFINE_CLASS( WidgetSetGauge, CoreGroup, imageView1, Outlet, Outlet, FloatEffect, 
                 currentAngle, currentAngle, "WidgetSet::Gauge" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  WidgetSetGauge_OnSetBounds,
  CoreGroup_OnSetFocus,
  CoreGroup_OnSetOpacity,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  WidgetSetGauge_UpdateViewState,
  CoreGroup_InvalidateArea,
EW_END_OF_CLASS( WidgetSetGauge )

/* Initializer for the class 'WidgetSet::ToggleButton' */
void WidgetSetToggleButton__Init( WidgetSetToggleButton _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( WidgetSetToggleButton );

  /* ... then construct all embedded objects */
  CoreTimer__Init( &_this->FlashTimer, &_this->_.XObject, 0 );
  CoreKeyPressHandler__Init( &_this->KeyHandler, &_this->_.XObject, 0 );
  CoreSimpleTouchHandler__Init( &_this->TouchHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( WidgetSetToggleButton );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const000F );
  CoreTimer_OnSetPeriod( &_this->FlashTimer, 0 );
  CoreTimer_OnSetBegin( &_this->FlashTimer, 50 );
  _this->KeyHandler.Filter = CoreKeyCodeEnter;
  CoreView_OnSetLayout((CoreView)&_this->TouchHandler, CoreLayoutAlignToBottom | 
  CoreLayoutAlignToLeft | CoreLayoutAlignToRight | CoreLayoutAlignToTop | CoreLayoutResizeHorz 
  | CoreLayoutResizeVert );
  CoreQuadView__OnSetPoint4( &_this->TouchHandler, _Const0010 );
  CoreQuadView__OnSetPoint3( &_this->TouchHandler, _Const0011 );
  CoreQuadView__OnSetPoint2( &_this->TouchHandler, _Const0012 );
  CoreQuadView__OnSetPoint1( &_this->TouchHandler, _Const0013 );
  CoreSimpleTouchHandler_OnSetRetargetOffset( &_this->TouchHandler, 16 );
  CoreSimpleTouchHandler_OnSetMaxStrikeCount( &_this->TouchHandler, 100 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->TouchHandler ), 0 );
  _this->FlashTimer.OnTrigger = EwNewSlot( _this, WidgetSetToggleButton_onFlashTimer );
  _this->KeyHandler.OnRelease = EwNewSlot( _this, WidgetSetToggleButton_onReleaseKey );
  _this->KeyHandler.OnPress = EwNewSlot( _this, WidgetSetToggleButton_onPressKey );
  _this->TouchHandler.OnLeave = EwNewSlot( _this, WidgetSetToggleButton_onLeaveTouch );
  _this->TouchHandler.OnEnter = EwNewSlot( _this, WidgetSetToggleButton_onEnterTouch );
  _this->TouchHandler.OnRelease = EwNewSlot( _this, WidgetSetToggleButton_onReleaseTouch );
  _this->TouchHandler.OnPress = EwNewSlot( _this, WidgetSetToggleButton_onPressTouch );
}

/* Re-Initializer for the class 'WidgetSet::ToggleButton' */
void WidgetSetToggleButton__ReInit( WidgetSetToggleButton _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreTimer__ReInit( &_this->FlashTimer );
  CoreKeyPressHandler__ReInit( &_this->KeyHandler );
  CoreSimpleTouchHandler__ReInit( &_this->TouchHandler );
}

/* Finalizer method for the class 'WidgetSet::ToggleButton' */
void WidgetSetToggleButton__Done( WidgetSetToggleButton _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  CoreTimer__Done( &_this->FlashTimer );
  CoreKeyPressHandler__Done( &_this->KeyHandler );
  CoreSimpleTouchHandler__Done( &_this->TouchHandler );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* 'C' function for method : 'WidgetSet::ToggleButton.OnSetBounds()' */
void WidgetSetToggleButton_OnSetBounds( WidgetSetToggleButton _this, XRect value )
{
  if ( _this->Appearance != 0 )
  {
    XPoint cs = EwGetRectSize( value );
    XPoint ns = cs;
    XPoint delta;

    if ( ns.X < _this->Appearance->WidgetMinSize.X )
      ns.X = _this->Appearance->WidgetMinSize.X;

    if ( ns.Y < _this->Appearance->WidgetMinSize.Y )
      ns.Y = _this->Appearance->WidgetMinSize.Y;

    delta = EwMovePointNeg( ns, cs );

    if ( delta.X != 0 )
    {
      XBool alignToLeft = (( _this->Super3.Layout & CoreLayoutAlignToLeft ) == CoreLayoutAlignToLeft );
      XBool alignToRight = (( _this->Super3.Layout & CoreLayoutAlignToRight ) == 
        CoreLayoutAlignToRight );

      if ( alignToLeft && !alignToRight )
        value.Point2.X = ( value.Point2.X + delta.X );
      else
        if ( !alignToLeft && alignToRight )
          value.Point1.X = ( value.Point1.X - delta.X );
        else
        {
          value.Point1.X = ( value.Point1.X - ( delta.X / 2 ));
          value.Point2.X = ( value.Point1.X + ns.X );
        }
    }

    if ( delta.Y != 0 )
    {
      XBool alignToTop = (( _this->Super3.Layout & CoreLayoutAlignToTop ) == CoreLayoutAlignToTop );
      XBool alignToBottom = (( _this->Super3.Layout & CoreLayoutAlignToBottom ) 
        == CoreLayoutAlignToBottom );

      if ( alignToTop && !alignToBottom )
        value.Point2.Y = ( value.Point2.Y + delta.Y );
      else
        if ( !alignToTop && alignToBottom )
          value.Point1.Y = ( value.Point1.Y - delta.Y );
        else
        {
          value.Point1.Y = ( value.Point1.Y - ( delta.Y / 2 ));
          value.Point2.Y = ( value.Point1.Y + ns.Y );
        }
    }
  }

  CoreGroup_OnSetBounds((CoreGroup)_this, value );
}

/* The method UpdateViewState() is invoked automatically after the state of the 
   component has been changed. This method can be overridden and filled with logic 
   to ensure the visual aspect of the component does reflect its current state. 
   For example, the 'enabled' state of the component can affect its colors (disabled 
   components may appear pale). In this case the logic of the method should modify 
   the respective color properties accordingly to the current 'enabled' state. 
   The current state of the component is passed as a set in the parameter aState. 
   It reflects the very basic component state like its visibility or the ability 
   to react to user inputs. Beside this common state, the method can also involve 
   any other variables used in the component as long as they reflect its current 
   state. For example, the toggle switch component can take in account its toggle 
   state 'on' or 'off' and change accordingly the location of the slider, etc.
   Usually, this method will be invoked automatically by the framework. Optionally 
   you can request its invocation by using the method @InvalidateViewState(). */
void WidgetSetToggleButton_UpdateViewState( WidgetSetToggleButton _this, XSet aState )
{
  XBool needsFace;
  XBool needsLabel;
  XBool restack;
  XRect area;
  XBool isEnabled;
  XBool isFocused;
  XBool isPressed;
  XBool isChecked;

  CoreGroup_UpdateViewState((CoreGroup)_this, aState );
  needsFace = (XBool)(( _this->Appearance != 0 ) && (((((((( _this->Appearance->FaceOffDefault 
  != 0 ) || ( _this->Appearance->FaceOffDisabled != 0 )) || ( _this->Appearance->FaceOffFocused 
  != 0 )) || ( _this->Appearance->FaceOffActive != 0 )) || ( _this->Appearance->FaceOnDefault 
  != 0 )) || ( _this->Appearance->FaceOnDisabled != 0 )) || ( _this->Appearance->FaceOnFocused 
  != 0 )) || ( _this->Appearance->FaceOnActive != 0 )));
  needsLabel = (XBool)(( _this->Appearance != 0 ) && ((( EwCompString( _this->LabelOff, 
  0 ) != 0 ) && ( _this->Appearance->LabelOffFont != 0 )) || (( EwCompString( _this->LabelOn, 
  0 ) != 0 ) && ( _this->Appearance->LabelOnFont != 0 ))));
  restack = 0;
  area = EwGetRectORect( _this->Super2.Bounds );

  if ( needsFace && ( _this->frameView == 0 ))
  {
    _this->frameView = EwNewObject( ViewsFrame, 0 );
    CoreGroup_Add((CoreGroup)_this, ((CoreView)_this->frameView ), 0 );
    restack = 1;
  }
  else
    if ( !needsFace && ( _this->frameView != 0 ))
    {
      CoreGroup_Remove((CoreGroup)_this, ((CoreView)_this->frameView ));
      _this->frameView = 0;
    }

  if ( needsLabel && ( _this->textView == 0 ))
  {
    _this->textView = EwNewObject( ViewsText, 0 );
    CoreGroup_Add((CoreGroup)_this, ((CoreView)_this->textView ), 0 );
    restack = 1;
    ViewsText_OnSetEnableBidiText( _this->textView, 1 );
  }
  else
    if ( !needsLabel && ( _this->textView != 0 ))
    {
      CoreGroup_Remove((CoreGroup)_this, ((CoreView)_this->textView ));
      _this->textView = 0;
    }

  if ( restack )
  {
    if ( _this->frameView != 0 )
      CoreGroup_RestackTop((CoreGroup)_this, ((CoreView)_this->frameView ));

    if ( _this->textView != 0 )
      CoreGroup_RestackTop((CoreGroup)_this, ((CoreView)_this->textView ));
  }

  isEnabled = (( aState & CoreViewStateEnabled ) == CoreViewStateEnabled );
  isFocused = (( aState & CoreViewStateFocused ) == CoreViewStateFocused );
  isPressed = (XBool)((( _this->TouchHandler.Down && _this->TouchHandler.Inside ) 
  || _this->KeyHandler.Down ) || _this->FlashTimer.Enabled );
  isChecked = _this->Checked;

  if ( _this->frameView != 0 )
  {
    ResourcesBitmap bitmap;
    XInt32 frameNo;
    XSet layout = _this->Appearance->FaceLayout;
    XRect r = area;

    if ( isChecked )
    {
      if ( !isEnabled )
      {
        bitmap = _this->Appearance->FaceOnDisabled;
        frameNo = _this->Appearance->FaceOnFrameDisabled;
      }
      else
        if ( isPressed )
        {
          bitmap = _this->Appearance->FaceOnActive;
          frameNo = _this->Appearance->FaceOnFrameActive;
        }
        else
          if ( isFocused )
          {
            bitmap = _this->Appearance->FaceOnFocused;
            frameNo = _this->Appearance->FaceOnFrameFocused;
          }
          else
          {
            bitmap = _this->Appearance->FaceOnDefault;
            frameNo = _this->Appearance->FaceOnFrameDefault;
          }
    }
    else
      if ( !isEnabled )
      {
        bitmap = _this->Appearance->FaceOffDisabled;
        frameNo = _this->Appearance->FaceOffFrameDisabled;
      }
      else
        if ( isPressed )
        {
          bitmap = _this->Appearance->FaceOffActive;
          frameNo = _this->Appearance->FaceOffFrameActive;
        }
        else
          if ( isFocused )
          {
            bitmap = _this->Appearance->FaceOffFocused;
            frameNo = _this->Appearance->FaceOffFrameFocused;
          }
          else
          {
            bitmap = _this->Appearance->FaceOffDefault;
            frameNo = _this->Appearance->FaceOffFrameDefault;
          }

    ViewsFrame_OnSetAnimated( _this->frameView, (XBool)( frameNo < 0 ));
    ViewsFrame_OnSetColor( _this->frameView, _Const0008 );

    if ( frameNo < 0 )
      frameNo = 0;

    if (( bitmap != 0 ) && !(( layout & CoreLayoutResizeHorz ) == CoreLayoutResizeHorz ))
    {
      XBool alignToLeft = (( layout & CoreLayoutAlignToLeft ) == CoreLayoutAlignToLeft );
      XBool alignToRight = (( layout & CoreLayoutAlignToRight ) == CoreLayoutAlignToRight );
      XInt32 w = bitmap->FrameSize.X;

      if ( alignToLeft && !alignToRight )
        r.Point2.X = ( r.Point1.X + w );
      else
        if ( !alignToLeft && alignToRight )
          r.Point1.X = ( r.Point2.X - w );
        else
        {
          r.Point1.X = (( EwGetRectW( r ) / 2 ) - ( w / 2 ));
          r.Point2.X = ( r.Point1.X + w );
        }
    }

    if (( bitmap != 0 ) && !(( layout & CoreLayoutResizeVert ) == CoreLayoutResizeVert ))
    {
      XBool alignToTop = (( layout & CoreLayoutAlignToTop ) == CoreLayoutAlignToTop );
      XBool alignToBottom = (( layout & CoreLayoutAlignToBottom ) == CoreLayoutAlignToBottom );
      XInt32 h = bitmap->FrameSize.Y;

      if ( alignToTop && !alignToBottom )
        r.Point2.Y = ( r.Point1.Y + h );
      else
        if ( !alignToTop && alignToBottom )
          r.Point1.Y = ( r.Point2.Y - h );
        else
        {
          r.Point1.Y = (( EwGetRectH( r ) / 2 ) - ( h / 2 ));
          r.Point2.Y = ( r.Point1.Y + h );
        }
    }

    ViewsFrame_OnSetFrameNumber( _this->frameView, frameNo );
    ViewsFrame_OnSetBitmap( _this->frameView, bitmap );
    CoreRectView__OnSetBounds( _this->frameView, r );
  }

  if ( _this->textView != 0 )
  {
    XColor clr;
    ResourcesFont font;
    XString label;

    if ( isChecked )
    {
      font = _this->Appearance->LabelOnFont;
      label = _this->LabelOn;

      if ( !isEnabled )
        clr = _this->Appearance->LabelOnColorDisabled;
      else
        if ( isPressed )
          clr = _this->Appearance->LabelOnColorActive;
        else
          if ( isFocused )
            clr = _this->Appearance->LabelOnColorFocused;
          else
            clr = _this->Appearance->LabelOnColorDefault;
    }
    else
    {
      font = _this->Appearance->LabelOffFont;
      label = _this->LabelOff;

      if ( !isEnabled )
        clr = _this->Appearance->LabelOffColorDisabled;
      else
        if ( isPressed )
          clr = _this->Appearance->LabelOffColorActive;
        else
          if ( isFocused )
            clr = _this->Appearance->LabelOffColorFocused;
          else
            clr = _this->Appearance->LabelOffColorDefault;
    }

    CoreRectView__OnSetBounds( _this->textView, EwNewRect( area.Point1.X, area.Point1.Y, 
    area.Point2.X - _this->Appearance->LabelMarginRight, area.Point2.Y ));
    ViewsText_OnSetAlignment( _this->textView, _this->Appearance->LabelAlignment );
    ViewsText_OnSetFont( _this->textView, font );
    ViewsText_OnSetString( _this->textView, label );
    ViewsText_OnSetColor( _this->textView, clr );
    ViewsText_OnSetWrapText( _this->textView, 1 );
    ViewsText_OnSetEllipsis( _this->textView, 1 );
  }
}

/* 'C' function for method : 'WidgetSet::ToggleButton.onConfigChanged()' */
void WidgetSetToggleButton_onConfigChanged( WidgetSetToggleButton _this, XObject 
  sender )
{
  XEnum oldKeyCode;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  oldKeyCode = _this->KeyHandler.Filter;
  _this->KeyHandler.Filter = CoreKeyCodeEnter;

  if (( oldKeyCode == CoreKeyCodeNoKey ) && ( _this->KeyHandler.Filter != CoreKeyCodeNoKey ))
    CoreView__ChangeViewState( _this, CoreViewStateFocusable, 0 );

  if (( oldKeyCode != CoreKeyCodeNoKey ) && ( _this->KeyHandler.Filter == CoreKeyCodeNoKey ))
    CoreView__ChangeViewState( _this, 0, CoreViewStateFocusable );

  if ( _this->Appearance != 0 )
    CoreRectView__OnSetBounds( _this, _this->Super2.Bounds );

  CoreGroup_InvalidateViewState((CoreGroup)_this );
}

/* 'C' function for method : 'WidgetSet::ToggleButton.onOutlet()' */
void WidgetSetToggleButton_onOutlet( WidgetSetToggleButton _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->Outlet.Object != 0 )
    WidgetSetToggleButton_OnSetChecked( _this, EwOnGetBool( _this->Outlet ));
}

/* 'C' function for method : 'WidgetSet::ToggleButton.onFlashTimer()' */
void WidgetSetToggleButton_onFlashTimer( WidgetSetToggleButton _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreGroup_InvalidateViewState((CoreGroup)_this );
  WidgetSetToggleButton_OnSetChecked( _this, (XBool)!_this->Checked );

  if ( _this->Outlet.Object != 0 )
  {
    EwOnSetBool( _this->Outlet, _this->Checked );
    EwNotifyRefObservers( _this->Outlet, 0 );
  }
}

/* 'C' function for method : 'WidgetSet::ToggleButton.onReleaseKey()' */
void WidgetSetToggleButton_onReleaseKey( WidgetSetToggleButton _this, XObject sender )
{
  XInt32 pressFeedbackDuration;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  pressFeedbackDuration = 0;

  if ( _this->Appearance != 0 )
    pressFeedbackDuration = 50;

  CoreSimpleTouchHandler_OnSetEnabled( &_this->TouchHandler, 1 );
  CoreGroup_InvalidateViewState((CoreGroup)_this );

  if ((XInt32)( _this->KeyHandler.Time - _this->onPressKeyTime ) >= pressFeedbackDuration )
  {
    WidgetSetToggleButton_OnSetChecked( _this, (XBool)!_this->Checked );

    if ( _this->Outlet.Object != 0 )
    {
      EwOnSetBool( _this->Outlet, _this->Checked );
      EwNotifyRefObservers( _this->Outlet, 0 );
    }
  }
  else
  {
    CoreTimer_OnSetBegin( &_this->FlashTimer, pressFeedbackDuration - (XInt32)( 
    _this->KeyHandler.Time - _this->onPressKeyTime ));
    CoreTimer_OnSetEnabled( &_this->FlashTimer, 1 );
  }
}

/* 'C' function for method : 'WidgetSet::ToggleButton.onPressKey()' */
void WidgetSetToggleButton_onPressKey( WidgetSetToggleButton _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreSimpleTouchHandler_OnSetEnabled( &_this->TouchHandler, 0 );
  CoreGroup_InvalidateViewState((CoreGroup)_this );

  if ( _this->FlashTimer.Enabled )
  {
    CoreTimer_OnSetEnabled( &_this->FlashTimer, 0 );
    WidgetSetToggleButton_OnSetChecked( _this, (XBool)!_this->Checked );

    if ( _this->Outlet.Object != 0 )
    {
      EwOnSetBool( _this->Outlet, _this->Checked );
      EwNotifyRefObservers( _this->Outlet, 0 );
    }
  }

  _this->onPressKeyTime = _this->KeyHandler.Time;
}

/* 'C' function for method : 'WidgetSet::ToggleButton.onLeaveTouch()' */
void WidgetSetToggleButton_onLeaveTouch( WidgetSetToggleButton _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreGroup_InvalidateViewState((CoreGroup)_this );
}

/* 'C' function for method : 'WidgetSet::ToggleButton.onEnterTouch()' */
void WidgetSetToggleButton_onEnterTouch( WidgetSetToggleButton _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreGroup_InvalidateViewState((CoreGroup)_this );
}

/* 'C' function for method : 'WidgetSet::ToggleButton.onReleaseTouch()' */
void WidgetSetToggleButton_onReleaseTouch( WidgetSetToggleButton _this, XObject 
  sender )
{
  XInt32 pressFeedbackDuration;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  pressFeedbackDuration = 0;

  if ( _this->Appearance != 0 )
    pressFeedbackDuration = 50;

  _this->KeyHandler.Enabled = 1;

  if ( !_this->TouchHandler.Inside )
    return;

  if ( _this->TouchHandler.AutoDeflected )
    return;

  if ( _this->TouchHandler.HoldPeriod >= pressFeedbackDuration )
  {
    WidgetSetToggleButton_OnSetChecked( _this, (XBool)!_this->Checked );

    if ( _this->Outlet.Object != 0 )
    {
      EwOnSetBool( _this->Outlet, _this->Checked );
      EwNotifyRefObservers( _this->Outlet, 0 );
    }
  }
  else
  {
    CoreTimer_OnSetBegin( &_this->FlashTimer, pressFeedbackDuration - _this->TouchHandler.HoldPeriod );
    CoreTimer_OnSetEnabled( &_this->FlashTimer, 1 );
  }
}

/* 'C' function for method : 'WidgetSet::ToggleButton.onPressTouch()' */
void WidgetSetToggleButton_onPressTouch( WidgetSetToggleButton _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  _this->KeyHandler.Enabled = 0;

  if ( _this->FlashTimer.Enabled )
  {
    CoreTimer_OnSetEnabled( &_this->FlashTimer, 0 );
    WidgetSetToggleButton_OnSetChecked( _this, (XBool)!_this->Checked );

    if ( _this->Outlet.Object != 0 )
    {
      EwOnSetBool( _this->Outlet, _this->Checked );
      EwNotifyRefObservers( _this->Outlet, 0 );
    }
  }
}

/* 'C' function for method : 'WidgetSet::ToggleButton.OnSetOutlet()' */
void WidgetSetToggleButton_OnSetOutlet( WidgetSetToggleButton _this, XRef value )
{
  if ( !EwCompRef( _this->Outlet, value ))
    return;

  if ( _this->Outlet.Object != 0 )
    EwDetachRefObserver( EwNewSlot( _this, WidgetSetToggleButton_onOutlet ), _this->Outlet, 
      0 );

  _this->Outlet = value;

  if ( value.Object != 0 )
    EwAttachRefObserver( EwNewSlot( _this, WidgetSetToggleButton_onOutlet ), value, 
      0 );

  if ( value.Object != 0 )
    EwPostSignal( EwNewSlot( _this, WidgetSetToggleButton_onOutlet ), ((XObject)_this ));
}

/* 'C' function for method : 'WidgetSet::ToggleButton.OnSetChecked()' */
void WidgetSetToggleButton_OnSetChecked( WidgetSetToggleButton _this, XBool value )
{
  if ( _this->Checked == value )
    return;

  _this->Checked = value;
  CoreGroup_InvalidateViewState((CoreGroup)_this );
}

/* 'C' function for method : 'WidgetSet::ToggleButton.OnSetLabel()' */
void WidgetSetToggleButton_OnSetLabel( WidgetSetToggleButton _this, XString value )
{
  if ( !EwCompString( value, _this->LabelOff ) && !EwCompString( value, _this->LabelOn ))
    return;

  _this->LabelOff = EwShareString( value );
  _this->LabelOn = EwShareString( value );
  CoreGroup_InvalidateViewState((CoreGroup)_this );
}

/* 'C' function for method : 'WidgetSet::ToggleButton.OnSetAppearance()' */
void WidgetSetToggleButton_OnSetAppearance( WidgetSetToggleButton _this, WidgetSetToggleButtonConfig 
  value )
{
  if ( _this->Appearance == value )
    return;

  if ( _this->Appearance != 0 )
    EwDetachObjObserver( EwNewSlot( _this, WidgetSetToggleButton_onConfigChanged ), 
      (XObject)_this->Appearance, 0 );

  _this->Appearance = value;

  if ( value != 0 )
    EwAttachObjObserver( EwNewSlot( _this, WidgetSetToggleButton_onConfigChanged ), 
      (XObject)value, 0 );

  EwPostSignal( EwNewSlot( _this, WidgetSetToggleButton_onConfigChanged ), ((XObject)_this ));
}

/* Variants derived from the class : 'WidgetSet::ToggleButton' */
EW_DEFINE_CLASS_VARIANTS( WidgetSetToggleButton )
EW_END_OF_CLASS_VARIANTS( WidgetSetToggleButton )

/* Virtual Method Table (VMT) for the class : 'WidgetSet::ToggleButton' */
EW_DEFINE_CLASS( WidgetSetToggleButton, CoreGroup, textView, Outlet, Outlet, FlashTimer, 
                 LabelOn, onPressKeyTime, "WidgetSet::ToggleButton" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  WidgetSetToggleButton_OnSetBounds,
  CoreGroup_OnSetFocus,
  CoreGroup_OnSetOpacity,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  WidgetSetToggleButton_UpdateViewState,
  CoreGroup_InvalidateArea,
EW_END_OF_CLASS( WidgetSetToggleButton )

/* Initializer for the class 'WidgetSet::PushButton' */
void WidgetSetPushButton__Init( WidgetSetPushButton _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( WidgetSetPushButton );

  /* ... then construct all embedded objects */
  CoreTimer__Init( &_this->FlashTimer, &_this->_.XObject, 0 );
  CoreKeyPressHandler__Init( &_this->KeyHandler, &_this->_.XObject, 0 );
  CoreSimpleTouchHandler__Init( &_this->TouchHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( WidgetSetPushButton );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const000F );
  CoreTimer_OnSetPeriod( &_this->FlashTimer, 0 );
  CoreTimer_OnSetBegin( &_this->FlashTimer, 50 );
  _this->KeyHandler.Filter = CoreKeyCodeEnter;
  CoreView_OnSetLayout((CoreView)&_this->TouchHandler, CoreLayoutAlignToBottom | 
  CoreLayoutAlignToLeft | CoreLayoutAlignToRight | CoreLayoutAlignToTop | CoreLayoutResizeHorz 
  | CoreLayoutResizeVert );
  CoreQuadView__OnSetPoint4( &_this->TouchHandler, _Const0010 );
  CoreQuadView__OnSetPoint3( &_this->TouchHandler, _Const0011 );
  CoreQuadView__OnSetPoint2( &_this->TouchHandler, _Const0012 );
  CoreQuadView__OnSetPoint1( &_this->TouchHandler, _Const0013 );
  CoreSimpleTouchHandler_OnSetRetargetOffset( &_this->TouchHandler, 16 );
  CoreSimpleTouchHandler_OnSetMaxStrikeCount( &_this->TouchHandler, 100 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->TouchHandler ), 0 );
  _this->FlashTimer.OnTrigger = EwNewSlot( _this, WidgetSetPushButton_onFlashTimer );
  _this->KeyHandler.OnRelease = EwNewSlot( _this, WidgetSetPushButton_onReleaseKey );
  _this->KeyHandler.OnPress = EwNewSlot( _this, WidgetSetPushButton_onPressKey );
  _this->TouchHandler.OnLeave = EwNewSlot( _this, WidgetSetPushButton_onLeaveTouch );
  _this->TouchHandler.OnEnter = EwNewSlot( _this, WidgetSetPushButton_onEnterTouch );
  _this->TouchHandler.OnRelease = EwNewSlot( _this, WidgetSetPushButton_onReleaseTouch );
  _this->TouchHandler.OnPress = EwNewSlot( _this, WidgetSetPushButton_onPressTouch );
}

/* Re-Initializer for the class 'WidgetSet::PushButton' */
void WidgetSetPushButton__ReInit( WidgetSetPushButton _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  CoreTimer__ReInit( &_this->FlashTimer );
  CoreKeyPressHandler__ReInit( &_this->KeyHandler );
  CoreSimpleTouchHandler__ReInit( &_this->TouchHandler );
}

/* Finalizer method for the class 'WidgetSet::PushButton' */
void WidgetSetPushButton__Done( WidgetSetPushButton _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  CoreTimer__Done( &_this->FlashTimer );
  CoreKeyPressHandler__Done( &_this->KeyHandler );
  CoreSimpleTouchHandler__Done( &_this->TouchHandler );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* 'C' function for method : 'WidgetSet::PushButton.OnSetBounds()' */
void WidgetSetPushButton_OnSetBounds( WidgetSetPushButton _this, XRect value )
{
  if ( _this->Appearance != 0 )
  {
    XPoint cs = EwGetRectSize( value );
    XPoint ns = cs;
    XPoint delta;

    if ( ns.X < _this->Appearance->WidgetMinSize.X )
      ns.X = _this->Appearance->WidgetMinSize.X;

    if ( ns.Y < _this->Appearance->WidgetMinSize.Y )
      ns.Y = _this->Appearance->WidgetMinSize.Y;

    delta = EwMovePointNeg( ns, cs );

    if ( delta.X != 0 )
    {
      XBool alignToLeft = (( _this->Super3.Layout & CoreLayoutAlignToLeft ) == CoreLayoutAlignToLeft );
      XBool alignToRight = (( _this->Super3.Layout & CoreLayoutAlignToRight ) == 
        CoreLayoutAlignToRight );

      if ( alignToLeft && !alignToRight )
        value.Point2.X = ( value.Point2.X + delta.X );
      else
        if ( !alignToLeft && alignToRight )
          value.Point1.X = ( value.Point1.X - delta.X );
        else
        {
          value.Point1.X = ( value.Point1.X - ( delta.X / 2 ));
          value.Point2.X = ( value.Point1.X + ns.X );
        }
    }

    if ( delta.Y != 0 )
    {
      XBool alignToTop = (( _this->Super3.Layout & CoreLayoutAlignToTop ) == CoreLayoutAlignToTop );
      XBool alignToBottom = (( _this->Super3.Layout & CoreLayoutAlignToBottom ) 
        == CoreLayoutAlignToBottom );

      if ( alignToTop && !alignToBottom )
        value.Point2.Y = ( value.Point2.Y + delta.Y );
      else
        if ( !alignToTop && alignToBottom )
          value.Point1.Y = ( value.Point1.Y - delta.Y );
        else
        {
          value.Point1.Y = ( value.Point1.Y - ( delta.Y / 2 ));
          value.Point2.Y = ( value.Point1.Y + ns.Y );
        }
    }
  }

  CoreGroup_OnSetBounds((CoreGroup)_this, value );
}

/* The method UpdateViewState() is invoked automatically after the state of the 
   component has been changed. This method can be overridden and filled with logic 
   to ensure the visual aspect of the component does reflect its current state. 
   For example, the 'enabled' state of the component can affect its colors (disabled 
   components may appear pale). In this case the logic of the method should modify 
   the respective color properties accordingly to the current 'enabled' state. 
   The current state of the component is passed as a set in the parameter aState. 
   It reflects the very basic component state like its visibility or the ability 
   to react to user inputs. Beside this common state, the method can also involve 
   any other variables used in the component as long as they reflect its current 
   state. For example, the toggle switch component can take in account its toggle 
   state 'on' or 'off' and change accordingly the location of the slider, etc.
   Usually, this method will be invoked automatically by the framework. Optionally 
   you can request its invocation by using the method @InvalidateViewState(). */
void WidgetSetPushButton_UpdateViewState( WidgetSetPushButton _this, XSet aState )
{
  XBool needsFace;
  XBool needsIcon;
  XBool needsLabel;
  XBool restack;
  XRect area;
  XBool isEnabled;
  XBool isFocused;
  XBool isPressed;

  CoreGroup_UpdateViewState((CoreGroup)_this, aState );
  needsFace = (XBool)(( _this->Appearance != 0 ) && (((( _this->Appearance->FaceDefault 
  != 0 ) || ( _this->Appearance->FaceDisabled != 0 )) || ( _this->Appearance->FaceFocused 
  != 0 )) || ( _this->Appearance->FaceActive != 0 )));
  needsIcon = (XBool)( _this->Icon != 0 );
  needsLabel = (XBool)((( _this->Appearance != 0 ) && ( EwCompString( _this->Label, 
  0 ) != 0 )) && ( _this->Appearance->LabelFont != 0 ));
  restack = 0;
  area = EwGetRectORect( _this->Super2.Bounds );

  if ( needsFace && ( _this->frameView == 0 ))
  {
    _this->frameView = EwNewObject( ViewsFrame, 0 );
    CoreGroup_Add((CoreGroup)_this, ((CoreView)_this->frameView ), 0 );
    restack = 1;
  }
  else
    if ( !needsFace && ( _this->frameView != 0 ))
    {
      CoreGroup_Remove((CoreGroup)_this, ((CoreView)_this->frameView ));
      _this->frameView = 0;
    }

  if ( needsIcon && ( _this->imageView == 0 ))
  {
    _this->imageView = EwNewObject( ViewsImage, 0 );
    CoreGroup_Add((CoreGroup)_this, ((CoreView)_this->imageView ), 0 );
    restack = 1;
  }
  else
    if ( !needsIcon && ( _this->imageView != 0 ))
    {
      CoreGroup_Remove((CoreGroup)_this, ((CoreView)_this->imageView ));
      _this->imageView = 0;
    }

  if ( needsLabel && ( _this->textView == 0 ))
  {
    _this->textView = EwNewObject( ViewsText, 0 );
    CoreGroup_Add((CoreGroup)_this, ((CoreView)_this->textView ), 0 );
    restack = 1;
    ViewsText_OnSetEnableBidiText( _this->textView, 1 );
  }
  else
    if ( !needsLabel && ( _this->textView != 0 ))
    {
      CoreGroup_Remove((CoreGroup)_this, ((CoreView)_this->textView ));
      _this->textView = 0;
    }

  if ( restack )
  {
    if ( _this->frameView != 0 )
      CoreGroup_RestackTop((CoreGroup)_this, ((CoreView)_this->frameView ));

    if ( _this->imageView != 0 )
      CoreGroup_RestackTop((CoreGroup)_this, ((CoreView)_this->imageView ));

    if ( _this->textView != 0 )
      CoreGroup_RestackTop((CoreGroup)_this, ((CoreView)_this->textView ));
  }

  isEnabled = (( aState & CoreViewStateEnabled ) == CoreViewStateEnabled );
  isFocused = (( aState & CoreViewStateFocused ) == CoreViewStateFocused );
  isPressed = (XBool)((( _this->TouchHandler.Down && _this->TouchHandler.Inside ) 
  || _this->KeyHandler.Down ) || _this->FlashTimer.Enabled );

  if ( _this->frameView != 0 )
  {
    ResourcesBitmap bitmap;
    XInt32 frameNo;
    XRect r = area;

    if ( !isEnabled )
    {
      bitmap = _this->Appearance->FaceDisabled;
      frameNo = _this->Appearance->FaceFrameDisabled;
    }
    else
      if ( isPressed )
      {
        bitmap = _this->Appearance->FaceActive;
        frameNo = _this->Appearance->FaceFrameActive;
      }
      else
        if ( isFocused )
        {
          bitmap = _this->Appearance->FaceFocused;
          frameNo = _this->Appearance->FaceFrameFocused;
        }
        else
        {
          bitmap = _this->Appearance->FaceDefault;
          frameNo = _this->Appearance->FaceFrameDefault;
        }

    ViewsFrame_OnSetAnimated( _this->frameView, (XBool)( frameNo < 0 ));
    ViewsFrame_OnSetColor( _this->frameView, _Const0008 );

    if ( frameNo < 0 )
      frameNo = 0;

    ViewsFrame_OnSetFrameNumber( _this->frameView, frameNo );
    ViewsFrame_OnSetBitmap( _this->frameView, bitmap );
    CoreRectView__OnSetBounds( _this->frameView, r );
  }

  if (( _this->imageView != 0 ) && ( _this->Appearance != 0 ))
  {
    XColor clr;

    if ( !isEnabled )
      clr = _this->Appearance->IconTintDisabled;
    else
      if ( isPressed )
        clr = _Const0008;
      else
        if ( isFocused )
          clr = _Const0008;
        else
          clr = _this->Appearance->IconTintDefault;

    ViewsImage_OnSetAnimated( _this->imageView, 1 );
    CoreRectView__OnSetBounds( _this->imageView, EwNewRect( area.Point1.X + _this->Appearance->IconMarginLeft, 
    area.Point1.Y + _this->Appearance->IconMarginTop, area.Point2.X - _this->Appearance->IconMarginRight, 
    area.Point2.Y - _this->Appearance->IconMarginBottom ));
    ViewsImage_OnSetAlignment( _this->imageView, ViewsImageAlignmentAlignHorzCenter 
    | ViewsImageAlignmentAlignVertCenter );
    ViewsImage_OnSetBitmap( _this->imageView, _this->Icon );
    ViewsImage_OnSetFrameNumber( _this->imageView, 0 );
    ViewsImage_OnSetColor( _this->imageView, clr );
  }
  else
    if ( _this->imageView != 0 )
    {
      CoreRectView__OnSetBounds( _this->imageView, area );
      ViewsImage_OnSetAlignment( _this->imageView, ViewsImageAlignmentAlignHorzCenter 
      | ViewsImageAlignmentAlignVertCenter );
      ViewsImage_OnSetBitmap( _this->imageView, _this->Icon );
      ViewsImage_OnSetFrameNumber( _this->imageView, -1 );
      ViewsImage_OnSetColor( _this->imageView, _Const0008 );
    }

  if ( _this->textView != 0 )
  {
    XColor clr;

    if ( !isEnabled )
      clr = _this->Appearance->LabelColorDisabled;
    else
      if ( isPressed )
        clr = _this->Appearance->LabelColorActive;
      else
        if ( isFocused )
          clr = _this->Appearance->LabelColorFocused;
        else
          clr = _this->Appearance->LabelColorDefault;

    CoreRectView__OnSetBounds( _this->textView, EwNewRect( area.Point1.X + _this->Appearance->LabelMarginLeft, 
    area.Point1.Y + _this->Appearance->LabelMarginTop, area.Point2.X - _this->Appearance->LabelMarginRight, 
    area.Point2.Y - _this->Appearance->LabelMarginBottom ));
    ViewsText_OnSetAlignment( _this->textView, ViewsTextAlignmentAlignHorzCenter 
    | ViewsTextAlignmentAlignVertCenter );
    ViewsText_OnSetWrapText( _this->textView, 1 );
    ViewsText_OnSetEllipsis( _this->textView, 1 );
    ViewsText_OnSetFont( _this->textView, _this->Appearance->LabelFont );
    ViewsText_OnSetString( _this->textView, _this->Label );
    ViewsText_OnSetColor( _this->textView, clr );
  }
}

/* 'C' function for method : 'WidgetSet::PushButton.onConfigChanged()' */
void WidgetSetPushButton_onConfigChanged( WidgetSetPushButton _this, XObject sender )
{
  XEnum oldKeyCode;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  oldKeyCode = _this->KeyHandler.Filter;
  _this->KeyHandler.Filter = CoreKeyCodeEnter;

  if (( oldKeyCode == CoreKeyCodeNoKey ) && ( _this->KeyHandler.Filter != CoreKeyCodeNoKey ))
    CoreView__ChangeViewState( _this, CoreViewStateFocusable, 0 );

  if (( oldKeyCode != CoreKeyCodeNoKey ) && ( _this->KeyHandler.Filter == CoreKeyCodeNoKey ))
    CoreView__ChangeViewState( _this, 0, CoreViewStateFocusable );

  if ( _this->Appearance != 0 )
    CoreRectView__OnSetBounds( _this, _this->Super2.Bounds );

  CoreGroup_InvalidateViewState((CoreGroup)_this );
}

/* 'C' function for method : 'WidgetSet::PushButton.onFlashTimer()' */
void WidgetSetPushButton_onFlashTimer( WidgetSetPushButton _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreGroup_InvalidateViewState((CoreGroup)_this );
}

/* 'C' function for method : 'WidgetSet::PushButton.onReleaseKey()' */
void WidgetSetPushButton_onReleaseKey( WidgetSetPushButton _this, XObject sender )
{
  XInt32 pressFeedbackDuration;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  pressFeedbackDuration = 0;

  if ( _this->Appearance != 0 )
    pressFeedbackDuration = 50;

  CoreSimpleTouchHandler_OnSetEnabled( &_this->TouchHandler, 1 );
  EwPostSignal( _this->OnRelease, ((XObject)_this ));
  CoreGroup_InvalidateViewState((CoreGroup)_this );

  if ( !((XInt32)( _this->KeyHandler.Time - _this->onPressKeyTime ) >= pressFeedbackDuration ))
  {
    CoreTimer_OnSetBegin( &_this->FlashTimer, pressFeedbackDuration - (XInt32)( 
    _this->KeyHandler.Time - _this->onPressKeyTime ));
    CoreTimer_OnSetEnabled( &_this->FlashTimer, 1 );
  }
}

/* 'C' function for method : 'WidgetSet::PushButton.onPressKey()' */
void WidgetSetPushButton_onPressKey( WidgetSetPushButton _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreSimpleTouchHandler_OnSetEnabled( &_this->TouchHandler, 0 );
  CoreGroup_InvalidateViewState((CoreGroup)_this );

  if ( _this->FlashTimer.Enabled )
    CoreTimer_OnSetEnabled( &_this->FlashTimer, 0 );

  _this->onPressKeyTime = _this->KeyHandler.Time;
}

/* 'C' function for method : 'WidgetSet::PushButton.onLeaveTouch()' */
void WidgetSetPushButton_onLeaveTouch( WidgetSetPushButton _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreGroup_InvalidateViewState((CoreGroup)_this );
}

/* 'C' function for method : 'WidgetSet::PushButton.onEnterTouch()' */
void WidgetSetPushButton_onEnterTouch( WidgetSetPushButton _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  CoreGroup_InvalidateViewState((CoreGroup)_this );
}

/* 'C' function for method : 'WidgetSet::PushButton.onReleaseTouch()' */
void WidgetSetPushButton_onReleaseTouch( WidgetSetPushButton _this, XObject sender )
{
  XInt32 pressFeedbackDuration;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  pressFeedbackDuration = 0;

  if ( _this->Appearance != 0 )
    pressFeedbackDuration = 50;

  _this->KeyHandler.Enabled = 1;
  EwPostSignal( _this->OnRelease, ((XObject)_this ));

  if ( !_this->TouchHandler.Inside )
    return;

  if ( _this->TouchHandler.AutoDeflected )
    return;

  if ( !( _this->TouchHandler.HoldPeriod >= pressFeedbackDuration ))
  {
    CoreTimer_OnSetBegin( &_this->FlashTimer, pressFeedbackDuration - _this->TouchHandler.HoldPeriod );
    CoreTimer_OnSetEnabled( &_this->FlashTimer, 1 );
  }
}

/* 'C' function for method : 'WidgetSet::PushButton.onPressTouch()' */
void WidgetSetPushButton_onPressTouch( WidgetSetPushButton _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  _this->KeyHandler.Enabled = 0;

  if ( _this->FlashTimer.Enabled )
    CoreTimer_OnSetEnabled( &_this->FlashTimer, 0 );
}

/* 'C' function for method : 'WidgetSet::PushButton.OnSetIcon()' */
void WidgetSetPushButton_OnSetIcon( WidgetSetPushButton _this, ResourcesBitmap value )
{
  if ( _this->Icon == value )
    return;

  _this->Icon = value;
  CoreGroup_InvalidateViewState((CoreGroup)_this );
}

/* 'C' function for method : 'WidgetSet::PushButton.OnSetLabel()' */
void WidgetSetPushButton_OnSetLabel( WidgetSetPushButton _this, XString value )
{
  if ( !EwCompString( _this->Label, value ))
    return;

  _this->Label = EwShareString( value );
  CoreGroup_InvalidateViewState((CoreGroup)_this );
}

/* 'C' function for method : 'WidgetSet::PushButton.OnSetAppearance()' */
void WidgetSetPushButton_OnSetAppearance( WidgetSetPushButton _this, WidgetSetPushButtonConfig 
  value )
{
  if ( _this->Appearance == value )
    return;

  if ( _this->Appearance != 0 )
    EwDetachObjObserver( EwNewSlot( _this, WidgetSetPushButton_onConfigChanged ), 
      (XObject)_this->Appearance, 0 );

  _this->Appearance = value;

  if ( value != 0 )
    EwAttachObjObserver( EwNewSlot( _this, WidgetSetPushButton_onConfigChanged ), 
      (XObject)value, 0 );

  EwPostSignal( EwNewSlot( _this, WidgetSetPushButton_onConfigChanged ), ((XObject)_this ));
}

/* Variants derived from the class : 'WidgetSet::PushButton' */
EW_DEFINE_CLASS_VARIANTS( WidgetSetPushButton )
EW_END_OF_CLASS_VARIANTS( WidgetSetPushButton )

/* Virtual Method Table (VMT) for the class : 'WidgetSet::PushButton' */
EW_DEFINE_CLASS( WidgetSetPushButton, CoreGroup, textView, OnRelease, FlashTimer, 
                 FlashTimer, Label, onPressKeyTime, "WidgetSet::PushButton" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  WidgetSetPushButton_OnSetBounds,
  CoreGroup_OnSetFocus,
  CoreGroup_OnSetOpacity,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  WidgetSetPushButton_UpdateViewState,
  CoreGroup_InvalidateArea,
EW_END_OF_CLASS( WidgetSetPushButton )

/* Embedded Wizard */
