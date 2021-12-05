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
#include "_ApplicationApplication.h"
#include "_ApplicationCurrentMeasurement.h"
#include "_ApplicationDetectorScreen.h"
#include "_ApplicationDeviceClass.h"
#include "_ApplicationDistanceMeasurement.h"
#include "_ApplicationMenu.h"
#include "_ApplicationSettings.h"
#include "_ApplicationWelcomeScreen.h"
#include "_CoreGroup.h"
#include "_CoreRoot.h"
#include "_CoreSimpleTouchHandler.h"
#include "_CoreView.h"
#include "_ResourcesBitmap.h"
#include "_ResourcesFont.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
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
#include "Application.h"
#include "Core.h"
#include "WidgetSet.h"
#include "DeviceDriver.h"

/* Compressed strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned int _StringsDefault0[] =
{
  0x00000132, /* ratio 60.13 % */
  0xB8003100, 0x8009A452, 0x00D20030, 0x0E600370, 0x86001000, 0x0620041C, 0x65001B00,
  0x40002800, 0x3A002304, 0xF47CC71E, 0x80043208, 0x16060B93, 0x641198E9, 0xDF209146,
  0x12739000, 0x12950580, 0x99DCCCEB, 0x8DC82191, 0x74223306, 0xC66693A8, 0xD67D1E36,
  0x4832A024, 0xA70494CD, 0x90A91C90, 0x358699E1, 0x0264A80D, 0x9AC708A0, 0x444A091B,
  0x002A8708, 0x5E4F0C99, 0xA151D950, 0x19089043, 0xD408CC8A, 0x450050E3, 0x39ED223D,
  0x950164F2, 0x3C9E9148, 0x4EC8F2A0, 0x126A6484, 0x21741826, 0x1F38B05E, 0x18EA34D3,
  0x09B64A24, 0x3C75C2B1, 0x80E7A6B7, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XRect _Const0000 = {{ 0, 0 }, { 240, 320 }};
static const XRect _Const0001 = {{ 29, 69 }, { 211, 252 }};
static const XPoint _Const0002 = { 0, 0 };
static const XPoint _Const0003 = { 240, 0 };
static const XPoint _Const0004 = { 240, 320 };
static const XPoint _Const0005 = { 0, 320 };
static const XColor _Const0006 = { 0xDC, 0xDC, 0xDC, 0xFF };
static const XRect _Const0007 = {{ 0, 168 }, { 240, 254 }};
static const XStringRes _Const0008 = { _StringsDefault0, 0x0002 };
static const XColor _Const0009 = { 0x00, 0x00, 0x00, 0xFF };
static const XRect _Const000A = {{ 0, 0 }, { 240, 86 }};
static const XStringRes _Const000B = { _StringsDefault0, 0x001A };
static const XRect _Const000C = {{ 0, 270 }, { 50, 320 }};
static const XRect _Const000D = {{ 0, 0 }, { 240, 80 }};
static const XStringRes _Const000E = { _StringsDefault0, 0x0025 };
static const XRect _Const000F = {{ 0, 80 }, { 240, 261 }};
static const XRect _Const0010 = {{ 83, 160 }, { 157, 192 }};
static const XStringRes _Const0011 = { _StringsDefault0, 0x003B };
static const XRect _Const0012 = {{ 0, 0 }, { 240, 51 }};
static const XStringRes _Const0013 = { _StringsDefault0, 0x003F };
static const XRect _Const0014 = {{ 45, 71 }, { 195, 121 }};
static const XStringRes _Const0015 = { _StringsDefault0, 0x004A };
static const XRect _Const0016 = {{ 45, 116 }, { 195, 166 }};
static const XStringRes _Const0017 = { _StringsDefault0, 0x0050 };
static const XRect _Const0018 = {{ 43, 160 }, { 193, 210 }};
static const XRect _Const0019 = {{ 0, 0 }, { 240, 81 }};
static const XStringRes _Const001A = { _StringsDefault0, 0x005A };
static const XRect _Const001B = {{ 25, 96 }, { 225, 146 }};
static const XRect _Const001C = {{ 25, 176 }, { 225, 226 }};
static const XRect _Const001D = {{ 71, 144 }, { 179, 176 }};
static const XStringRes _Const001E = { _StringsDefault0, 0x0071 };
static const XRect _Const001F = {{ 73, 226 }, { 167, 258 }};
static const XStringRes _Const0020 = { _StringsDefault0, 0x0076 };
static const XStringRes _Const0021 = { _StringsDefault0, 0x007D };
static const XRect _Const0022 = {{ 0, 225 }, { 120, 320 }};
static const XStringRes _Const0023 = { _StringsDefault0, 0x0084 };
static const XRect _Const0024 = {{ 120, 130 }, { 240, 225 }};
static const XStringRes _Const0025 = { _StringsDefault0, 0x008E };
static const XRect _Const0026 = {{ 0, 130 }, { 120, 225 }};
static const XRect _Const0027 = {{ 120, 225 }, { 240, 320 }};

/* Initializer for the class 'Application::Application' */
void ApplicationApplication__Init( ApplicationApplication _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreRoot__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ApplicationApplication );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ApplicationApplication );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );

  /* Call the user defined constructor */
  ApplicationApplication_Init( _this, aArg );
}

/* Re-Initializer for the class 'Application::Application' */
void ApplicationApplication__ReInit( ApplicationApplication _this )
{
  /* At first re-initialize the super class ... */
  CoreRoot__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Application::Application' */
void ApplicationApplication__Done( ApplicationApplication _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreRoot );

  /* Don't forget to deinitialize the super class ... */
  CoreRoot__Done( &_this->_.Super );
}

/* The method Init() is invoked automatically after the component has been created. 
   This method can be overridden and filled with logic containing additional initialization 
   statements. */
void ApplicationApplication_Init( ApplicationApplication _this, XHandle aArg )
{
  CoreGroup newDialog;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  newDialog = ((CoreGroup)EwNewObject( ApplicationWelcomeScreen, 0 ));
  CoreGroup_PresentDialog((CoreGroup)_this, newDialog, 0, 0, 0, 0, 0, 0, EwNullSlot, 
  EwNullSlot, 0 );
}

/* Variants derived from the class : 'Application::Application' */
EW_DEFINE_CLASS_VARIANTS( ApplicationApplication )
EW_END_OF_CLASS_VARIANTS( ApplicationApplication )

/* Virtual Method Table (VMT) for the class : 'Application::Application' */
EW_DEFINE_CLASS( ApplicationApplication, CoreRoot, _.VMT, _.VMT, _.VMT, _.VMT, _.VMT, 
                 _.VMT, "Application::Application" )
  CoreRectView_initLayoutContext,
  CoreRoot_GetRoot,
  CoreRoot_Draw,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreRoot_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreRoot_OnSetFocus,
  CoreRoot_OnSetOpacity,
  CoreRoot_IsCurrentDialog,
  CoreRoot_IsActiveDialog,
  CoreRoot_DispatchEvent,
  CoreRoot_BroadcastEvent,
  CoreGroup_UpdateViewState,
  CoreRoot_InvalidateArea,
EW_END_OF_CLASS( ApplicationApplication )

/* Include a file containing the font resource : 'Application::Font' */
#include "_ApplicationFont.h"

/* Table with links to derived variants of the font resource : 'Application::Font' */
EW_RES_WITHOUT_VARIANTS( ApplicationFont )

/* Include a file containing the font resource : 'Application::TitelFont' */
#include "_ApplicationTitelFont.h"

/* Table with links to derived variants of the font resource : 'Application::TitelFont' */
EW_RES_WITHOUT_VARIANTS( ApplicationTitelFont )

/* Initializer for the class 'Application::WelcomeScreen' */
void ApplicationWelcomeScreen__Init( ApplicationWelcomeScreen _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ApplicationWelcomeScreen );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Rectangle, &_this->_.XObject, 0 );
  ViewsImage__Init( &_this->Image, &_this->_.XObject, 0 );
  CoreSimpleTouchHandler__Init( &_this->SimpleTouchHandler, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ApplicationWelcomeScreen );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Rectangle, _Const0000 );
  CoreView_OnSetLayout((CoreView)&_this->Image, CoreLayoutAlignToBottom | CoreLayoutAlignToLeft 
  | CoreLayoutAlignToRight | CoreLayoutAlignToTop | CoreLayoutResizeHorz | CoreLayoutResizeVert );
  CoreRectView__OnSetBounds( &_this->Image, _Const0001 );
  ViewsImage_OnSetAutoSize( &_this->Image, 0 );
  ViewsImage_OnSetEmbedded( &_this->Image, 0 );
  CoreQuadView__OnSetPoint4( &_this->SimpleTouchHandler, _Const0002 );
  CoreQuadView__OnSetPoint3( &_this->SimpleTouchHandler, _Const0003 );
  CoreQuadView__OnSetPoint2( &_this->SimpleTouchHandler, _Const0004 );
  CoreQuadView__OnSetPoint1( &_this->SimpleTouchHandler, _Const0005 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Rectangle ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Image ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->SimpleTouchHandler ), 0 );
  ViewsImage_OnSetBitmap( &_this->Image, EwLoadResource( &ApplicationZhawLogo, ResourcesBitmap ));
  _this->SimpleTouchHandler.OnRelease = EwNewSlot( _this, ApplicationWelcomeScreen_UpdateViewMenu );
}

/* Re-Initializer for the class 'Application::WelcomeScreen' */
void ApplicationWelcomeScreen__ReInit( ApplicationWelcomeScreen _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Rectangle );
  ViewsImage__ReInit( &_this->Image );
  CoreSimpleTouchHandler__ReInit( &_this->SimpleTouchHandler );
}

/* Finalizer method for the class 'Application::WelcomeScreen' */
void ApplicationWelcomeScreen__Done( ApplicationWelcomeScreen _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Rectangle );
  ViewsImage__Done( &_this->Image );
  CoreSimpleTouchHandler__Done( &_this->SimpleTouchHandler );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* 'C' function for method : 'Application::WelcomeScreen.UpdateViewMenu()' */
void ApplicationWelcomeScreen_UpdateViewMenu( ApplicationWelcomeScreen _this, XObject 
  sender )
{
  CoreGroup newDialog;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  newDialog = ((CoreGroup)EwNewObject( ApplicationMenu, 0 ));

  if ( CoreGroup__IsCurrentDialog( _this ))
    CoreGroup_SwitchToDialog((CoreGroup)_this, newDialog, 0, 0, 0, 0, 0, 0, 0, EwNullSlot, 
    EwNullSlot, 0 );
}

/* Variants derived from the class : 'Application::WelcomeScreen' */
EW_DEFINE_CLASS_VARIANTS( ApplicationWelcomeScreen )
EW_END_OF_CLASS_VARIANTS( ApplicationWelcomeScreen )

/* Virtual Method Table (VMT) for the class : 'Application::WelcomeScreen' */
EW_DEFINE_CLASS( ApplicationWelcomeScreen, CoreGroup, Rectangle, Rectangle, Rectangle, 
                 Rectangle, _.VMT, _.VMT, "Application::WelcomeScreen" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreGroup_OnSetFocus,
  CoreGroup_OnSetOpacity,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
EW_END_OF_CLASS( ApplicationWelcomeScreen )

/* Initializer for the class 'Application::DetectorScreen' */
void ApplicationDetectorScreen__Init( ApplicationDetectorScreen _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ApplicationDetectorScreen );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Rectangle, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->Text, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->Text1, &_this->_.XObject, 0 );
  WidgetSetPushButton__Init( &_this->PushButton, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ApplicationDetectorScreen );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Rectangle, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->Rectangle, _Const0006 );
  CoreRectView__OnSetBounds( &_this->Text, _Const0007 );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &_Const0008 ));
  ViewsText_OnSetColor( &_this->Text, _Const0009 );
  CoreRectView__OnSetBounds( &_this->Text1, _Const000A );
  ViewsText_OnSetString( &_this->Text1, EwLoadString( &_Const000B ));
  ViewsText_OnSetColor( &_this->Text1, _Const0009 );
  CoreRectView__OnSetBounds( &_this->PushButton, _Const000C );
  WidgetSetPushButton_OnSetLabel( &_this->PushButton, 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Rectangle ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Text ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Text1 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->PushButton ), 0 );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &ApplicationFont, ResourcesFont ));
  ViewsText_OnSetFont( &_this->Text1, EwLoadResource( &ApplicationTitelFont, ResourcesFont ));
  _this->PushButton.OnRelease = EwNewSlot( _this, ApplicationDetectorScreen_UpdateViewMenu );
  WidgetSetPushButton_OnSetAppearance( &_this->PushButton, EwGetAutoObject( &WidgetSetPushButton_Medium, 
  WidgetSetPushButtonConfig ));
}

/* Re-Initializer for the class 'Application::DetectorScreen' */
void ApplicationDetectorScreen__ReInit( ApplicationDetectorScreen _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Rectangle );
  ViewsText__ReInit( &_this->Text );
  ViewsText__ReInit( &_this->Text1 );
  WidgetSetPushButton__ReInit( &_this->PushButton );
}

/* Finalizer method for the class 'Application::DetectorScreen' */
void ApplicationDetectorScreen__Done( ApplicationDetectorScreen _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Rectangle );
  ViewsText__Done( &_this->Text );
  ViewsText__Done( &_this->Text1 );
  WidgetSetPushButton__Done( &_this->PushButton );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* 'C' function for method : 'Application::DetectorScreen.UpdateViewMenu()' */
void ApplicationDetectorScreen_UpdateViewMenu( ApplicationDetectorScreen _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( CoreGroup__IsActiveDialog( _this, 1 ))
    CoreGroup_DismissDialog( _this->Super3.Owner, ((CoreGroup)_this ), 0, 0, 0, 
    EwNullSlot, EwNullSlot, 1 );
}

/* Variants derived from the class : 'Application::DetectorScreen' */
EW_DEFINE_CLASS_VARIANTS( ApplicationDetectorScreen )
EW_END_OF_CLASS_VARIANTS( ApplicationDetectorScreen )

/* Virtual Method Table (VMT) for the class : 'Application::DetectorScreen' */
EW_DEFINE_CLASS( ApplicationDetectorScreen, CoreGroup, Rectangle, Rectangle, Rectangle, 
                 Rectangle, _.VMT, _.VMT, "Application::DetectorScreen" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreGroup_OnSetFocus,
  CoreGroup_OnSetOpacity,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
EW_END_OF_CLASS( ApplicationDetectorScreen )

/* Initializer for the class 'Application::CurrentMeasurement' */
void ApplicationCurrentMeasurement__Init( ApplicationCurrentMeasurement _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ApplicationCurrentMeasurement );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Rectangle, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->Text, &_this->_.XObject, 0 );
  WidgetSetGauge__Init( &_this->Gauge, &_this->_.XObject, 0 );
  WidgetSetValueDisplay__Init( &_this->ValueDisplay, &_this->_.XObject, 0 );
  WidgetSetPushButton__Init( &_this->PushButton, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ApplicationCurrentMeasurement );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Rectangle, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->Rectangle, _Const0006 );
  CoreRectView__OnSetBounds( &_this->Text, _Const000D );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &_Const000E ));
  ViewsText_OnSetColor( &_this->Text, _Const0009 );
  CoreRectView__OnSetBounds( &_this->Gauge, _Const000F );
  WidgetSetGauge_OnSetMaxValue( &_this->Gauge, 10 );
  WidgetSetGauge_OnSetCurrentValue( &_this->Gauge, 5 );
  CoreView_OnSetLayout((CoreView)&_this->ValueDisplay, 0 );
  CoreRectView__OnSetBounds( &_this->ValueDisplay, _Const0010 );
  WidgetSetValueDisplay_OnSetUnit( &_this->ValueDisplay, EwLoadString( &_Const0011 ));
  WidgetSetValueDisplay_OnSetPrecision( &_this->ValueDisplay, 1 );
  CoreRectView__OnSetBounds( &_this->PushButton, _Const000C );
  WidgetSetPushButton_OnSetLabel( &_this->PushButton, 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Rectangle ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Text ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Gauge ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->ValueDisplay ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->PushButton ), 0 );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &ApplicationTitelFont, ResourcesFont ));
  WidgetSetGauge_OnSetAppearance( &_this->Gauge, EwGetAutoObject( &WidgetSetGauge_Medium, 
  WidgetSetGaugeConfig ));
  WidgetSetValueDisplay_OnSetAppearance( &_this->ValueDisplay, EwGetAutoObject( 
  &WidgetSetValueDisplay_Medium, WidgetSetValueDisplayConfig ));
  _this->PushButton.OnRelease = EwNewSlot( _this, ApplicationCurrentMeasurement_UpdateViewMenu );
  WidgetSetPushButton_OnSetAppearance( &_this->PushButton, EwGetAutoObject( &WidgetSetPushButton_Medium, 
  WidgetSetPushButtonConfig ));
}

/* Re-Initializer for the class 'Application::CurrentMeasurement' */
void ApplicationCurrentMeasurement__ReInit( ApplicationCurrentMeasurement _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Rectangle );
  ViewsText__ReInit( &_this->Text );
  WidgetSetGauge__ReInit( &_this->Gauge );
  WidgetSetValueDisplay__ReInit( &_this->ValueDisplay );
  WidgetSetPushButton__ReInit( &_this->PushButton );
}

/* Finalizer method for the class 'Application::CurrentMeasurement' */
void ApplicationCurrentMeasurement__Done( ApplicationCurrentMeasurement _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Rectangle );
  ViewsText__Done( &_this->Text );
  WidgetSetGauge__Done( &_this->Gauge );
  WidgetSetValueDisplay__Done( &_this->ValueDisplay );
  WidgetSetPushButton__Done( &_this->PushButton );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* 'C' function for method : 'Application::CurrentMeasurement.UpdateViewMenu()' */
void ApplicationCurrentMeasurement_UpdateViewMenu( ApplicationCurrentMeasurement _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( CoreGroup__IsActiveDialog( _this, 1 ))
    CoreGroup_DismissDialog( _this->Super3.Owner, ((CoreGroup)_this ), 0, 0, 0, 
    EwNullSlot, EwNullSlot, 1 );
}

/* Variants derived from the class : 'Application::CurrentMeasurement' */
EW_DEFINE_CLASS_VARIANTS( ApplicationCurrentMeasurement )
EW_END_OF_CLASS_VARIANTS( ApplicationCurrentMeasurement )

/* Virtual Method Table (VMT) for the class : 'Application::CurrentMeasurement' */
EW_DEFINE_CLASS( ApplicationCurrentMeasurement, CoreGroup, Rectangle, Rectangle, 
                 Rectangle, Rectangle, _.VMT, _.VMT, "Application::CurrentMeasurement" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreGroup_OnSetFocus,
  CoreGroup_OnSetOpacity,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
EW_END_OF_CLASS( ApplicationCurrentMeasurement )

/* Initializer for the class 'Application::Settings' */
void ApplicationSettings__Init( ApplicationSettings _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ApplicationSettings );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Rectangle, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->Text, &_this->_.XObject, 0 );
  WidgetSetPushButton__Init( &_this->MenuButton, &_this->_.XObject, 0 );
  WidgetSetToggleButton__Init( &_this->ToggleButton, &_this->_.XObject, 0 );
  WidgetSetToggleButton__Init( &_this->ToggleButton1, &_this->_.XObject, 0 );
  WidgetSetToggleButton__Init( &_this->ToggleButton2, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ApplicationSettings );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Rectangle, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->Rectangle, _Const0006 );
  CoreRectView__OnSetBounds( &_this->Text, _Const0012 );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &_Const0013 ));
  ViewsText_OnSetColor( &_this->Text, _Const0009 );
  CoreRectView__OnSetBounds( &_this->MenuButton, _Const000C );
  WidgetSetPushButton_OnSetLabel( &_this->MenuButton, 0 );
  CoreRectView__OnSetBounds( &_this->ToggleButton, _Const0014 );
  WidgetSetToggleButton_OnSetLabel( &_this->ToggleButton, EwLoadString( &_Const0015 ));
  CoreRectView__OnSetBounds( &_this->ToggleButton1, _Const0016 );
  WidgetSetToggleButton_OnSetLabel( &_this->ToggleButton1, EwLoadString( &_Const0017 ));
  CoreRectView__OnSetBounds( &_this->ToggleButton2, _Const0018 );
  WidgetSetToggleButton_OnSetLabel( &_this->ToggleButton2, EwLoadString( &_Const0017 ));
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Rectangle ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Text ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->MenuButton ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->ToggleButton ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->ToggleButton1 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->ToggleButton2 ), 0 );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &ApplicationTitelFont, ResourcesFont ));
  _this->MenuButton.OnRelease = EwNewSlot( _this, ApplicationSettings_UpdateViewMenu );
  WidgetSetPushButton_OnSetAppearance( &_this->MenuButton, EwGetAutoObject( &WidgetSetPushButton_Medium, 
  WidgetSetPushButtonConfig ));
  WidgetSetToggleButton_OnSetOutlet( &_this->ToggleButton, EwNewRef( EwGetAutoObject( 
  &ApplicationDevice, ApplicationDeviceClass ), ApplicationDeviceClass_OnGetLamptest, 
  ApplicationDeviceClass_OnSetLamptest ));
  WidgetSetToggleButton_OnSetAppearance( &_this->ToggleButton, EwGetAutoObject( 
  &WidgetSetSwitch_Medium, WidgetSetToggleButtonConfig ));
  WidgetSetToggleButton_OnSetAppearance( &_this->ToggleButton1, EwGetAutoObject( 
  &WidgetSetSwitch_Medium, WidgetSetToggleButtonConfig ));
  WidgetSetToggleButton_OnSetAppearance( &_this->ToggleButton2, EwGetAutoObject( 
  &WidgetSetSwitch_Medium, WidgetSetToggleButtonConfig ));
}

/* Re-Initializer for the class 'Application::Settings' */
void ApplicationSettings__ReInit( ApplicationSettings _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Rectangle );
  ViewsText__ReInit( &_this->Text );
  WidgetSetPushButton__ReInit( &_this->MenuButton );
  WidgetSetToggleButton__ReInit( &_this->ToggleButton );
  WidgetSetToggleButton__ReInit( &_this->ToggleButton1 );
  WidgetSetToggleButton__ReInit( &_this->ToggleButton2 );
}

/* Finalizer method for the class 'Application::Settings' */
void ApplicationSettings__Done( ApplicationSettings _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Rectangle );
  ViewsText__Done( &_this->Text );
  WidgetSetPushButton__Done( &_this->MenuButton );
  WidgetSetToggleButton__Done( &_this->ToggleButton );
  WidgetSetToggleButton__Done( &_this->ToggleButton1 );
  WidgetSetToggleButton__Done( &_this->ToggleButton2 );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* 'C' function for method : 'Application::Settings.UpdateViewMenu()' */
void ApplicationSettings_UpdateViewMenu( ApplicationSettings _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( CoreGroup__IsActiveDialog( _this, 1 ))
    CoreGroup_DismissDialog( _this->Super3.Owner, ((CoreGroup)_this ), 0, 0, 0, 
    EwNullSlot, EwNullSlot, 1 );
}

/* Variants derived from the class : 'Application::Settings' */
EW_DEFINE_CLASS_VARIANTS( ApplicationSettings )
EW_END_OF_CLASS_VARIANTS( ApplicationSettings )

/* Virtual Method Table (VMT) for the class : 'Application::Settings' */
EW_DEFINE_CLASS( ApplicationSettings, CoreGroup, Rectangle, Rectangle, Rectangle, 
                 Rectangle, _.VMT, _.VMT, "Application::Settings" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreGroup_OnSetFocus,
  CoreGroup_OnSetOpacity,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
EW_END_OF_CLASS( ApplicationSettings )

/* Initializer for the class 'Application::DistanceMeasurement' */
void ApplicationDistanceMeasurement__Init( ApplicationDistanceMeasurement _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ApplicationDistanceMeasurement );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Rectangle, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->Text, &_this->_.XObject, 0 );
  WidgetSetPushButton__Init( &_this->PushButton, &_this->_.XObject, 0 );
  WidgetSetHorizontalValueBar__Init( &_this->HorizontalValueBar, &_this->_.XObject, 0 );
  WidgetSetHorizontalValueBar__Init( &_this->HorizontalValueBar1, &_this->_.XObject, 0 );
  WidgetSetValueDisplay__Init( &_this->ValueDisplay, &_this->_.XObject, 0 );
  WidgetSetValueDisplay__Init( &_this->ValueDisplay1, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ApplicationDistanceMeasurement );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Rectangle, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->Rectangle, _Const0006 );
  CoreRectView__OnSetBounds( &_this->Text, _Const0019 );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &_Const001A ));
  ViewsText_OnSetColor( &_this->Text, _Const0009 );
  CoreRectView__OnSetBounds( &_this->PushButton, _Const000C );
  WidgetSetPushButton_OnSetLabel( &_this->PushButton, 0 );
  CoreRectView__OnSetBounds( &_this->HorizontalValueBar, _Const001B );
  CoreRectView__OnSetBounds( &_this->HorizontalValueBar1, _Const001C );
  CoreRectView__OnSetBounds( &_this->ValueDisplay, _Const001D );
  WidgetSetValueDisplay_OnSetUnit( &_this->ValueDisplay, EwLoadString( &_Const001E ));
  WidgetSetValueDisplay_OnSetPrecision( &_this->ValueDisplay, 1 );
  CoreRectView__OnSetBounds( &_this->ValueDisplay1, _Const001F );
  WidgetSetValueDisplay_OnSetUnit( &_this->ValueDisplay1, EwLoadString( &_Const0020 ));
  WidgetSetValueDisplay_OnSetPrecision( &_this->ValueDisplay1, 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Rectangle ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Text ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->PushButton ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->HorizontalValueBar ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->HorizontalValueBar1 ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->ValueDisplay ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->ValueDisplay1 ), 0 );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &ApplicationTitelFont, ResourcesFont ));
  _this->PushButton.OnRelease = EwNewSlot( _this, ApplicationDistanceMeasurement_UpdateViewMenu );
  WidgetSetPushButton_OnSetAppearance( &_this->PushButton, EwGetAutoObject( &WidgetSetPushButton_Medium, 
  WidgetSetPushButtonConfig ));
  WidgetSetHorizontalValueBar_OnSetAppearance( &_this->HorizontalValueBar, EwGetAutoObject( 
  &WidgetSetHorizontalValueBar_Medium, WidgetSetHorizontalValueBarConfig ));
  WidgetSetHorizontalValueBar_OnSetAppearance( &_this->HorizontalValueBar1, EwGetAutoObject( 
  &WidgetSetHorizontalValueBar_Medium, WidgetSetHorizontalValueBarConfig ));
  WidgetSetValueDisplay_OnSetAppearance( &_this->ValueDisplay, EwGetAutoObject( 
  &WidgetSetValueDisplay_Medium, WidgetSetValueDisplayConfig ));
  WidgetSetValueDisplay_OnSetAppearance( &_this->ValueDisplay1, EwGetAutoObject( 
  &WidgetSetValueDisplay_Medium, WidgetSetValueDisplayConfig ));
}

/* Re-Initializer for the class 'Application::DistanceMeasurement' */
void ApplicationDistanceMeasurement__ReInit( ApplicationDistanceMeasurement _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Rectangle );
  ViewsText__ReInit( &_this->Text );
  WidgetSetPushButton__ReInit( &_this->PushButton );
  WidgetSetHorizontalValueBar__ReInit( &_this->HorizontalValueBar );
  WidgetSetHorizontalValueBar__ReInit( &_this->HorizontalValueBar1 );
  WidgetSetValueDisplay__ReInit( &_this->ValueDisplay );
  WidgetSetValueDisplay__ReInit( &_this->ValueDisplay1 );
}

/* Finalizer method for the class 'Application::DistanceMeasurement' */
void ApplicationDistanceMeasurement__Done( ApplicationDistanceMeasurement _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Rectangle );
  ViewsText__Done( &_this->Text );
  WidgetSetPushButton__Done( &_this->PushButton );
  WidgetSetHorizontalValueBar__Done( &_this->HorizontalValueBar );
  WidgetSetHorizontalValueBar__Done( &_this->HorizontalValueBar1 );
  WidgetSetValueDisplay__Done( &_this->ValueDisplay );
  WidgetSetValueDisplay__Done( &_this->ValueDisplay1 );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* 'C' function for method : 'Application::DistanceMeasurement.UpdateViewMenu()' */
void ApplicationDistanceMeasurement_UpdateViewMenu( ApplicationDistanceMeasurement _this, 
  XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( CoreGroup__IsActiveDialog( _this, 1 ))
    CoreGroup_DismissDialog( _this->Super3.Owner, ((CoreGroup)_this ), 0, 0, 0, 
    EwNullSlot, EwNullSlot, 1 );
}

/* Variants derived from the class : 'Application::DistanceMeasurement' */
EW_DEFINE_CLASS_VARIANTS( ApplicationDistanceMeasurement )
EW_END_OF_CLASS_VARIANTS( ApplicationDistanceMeasurement )

/* Virtual Method Table (VMT) for the class : 'Application::DistanceMeasurement' */
EW_DEFINE_CLASS( ApplicationDistanceMeasurement, CoreGroup, Rectangle, Rectangle, 
                 Rectangle, Rectangle, _.VMT, _.VMT, "Application::DistanceMeasurement" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreGroup_OnSetFocus,
  CoreGroup_OnSetOpacity,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
EW_END_OF_CLASS( ApplicationDistanceMeasurement )

/* Include a file containing the bitmap resource : 'Application::ZhawLogo' */
#include "_ApplicationZhawLogo.h"

/* Table with links to derived variants of the bitmap resource : 'Application::ZhawLogo' */
EW_RES_WITHOUT_VARIANTS( ApplicationZhawLogo )

/* Initializer for the class 'Application::Menu' */
void ApplicationMenu__Init( ApplicationMenu _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreGroup__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ApplicationMenu );

  /* ... then construct all embedded objects */
  ViewsRectangle__Init( &_this->Rectangle, &_this->_.XObject, 0 );
  ViewsText__Init( &_this->Text, &_this->_.XObject, 0 );
  WidgetSetPushButton__Init( &_this->CurrentButton, &_this->_.XObject, 0 );
  WidgetSetPushButton__Init( &_this->DistanceButton, &_this->_.XObject, 0 );
  WidgetSetPushButton__Init( &_this->DetectorButton, &_this->_.XObject, 0 );
  WidgetSetPushButton__Init( &_this->SettingsButton, &_this->_.XObject, 0 );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ApplicationMenu );

  /* ... and initialize objects, variables, properties, etc. */
  CoreRectView__OnSetBounds( _this, _Const0000 );
  CoreRectView__OnSetBounds( &_this->Rectangle, _Const0000 );
  ViewsRectangle_OnSetColor( &_this->Rectangle, _Const0006 );
  CoreRectView__OnSetBounds( &_this->Text, _Const0012 );
  ViewsText_OnSetString( &_this->Text, EwLoadString( &_Const0021 ));
  ViewsText_OnSetColor( &_this->Text, _Const0009 );
  CoreRectView__OnSetBounds( &_this->CurrentButton, _Const0022 );
  WidgetSetPushButton_OnSetLabel( &_this->CurrentButton, EwLoadString( &_Const0023 ));
  CoreRectView__OnSetBounds( &_this->DistanceButton, _Const0024 );
  WidgetSetPushButton_OnSetLabel( &_this->DistanceButton, EwLoadString( &_Const0025 ));
  CoreRectView__OnSetBounds( &_this->DetectorButton, _Const0026 );
  WidgetSetPushButton_OnSetLabel( &_this->DetectorButton, EwLoadString( &_Const000B ));
  CoreRectView__OnSetBounds( &_this->SettingsButton, _Const0027 );
  WidgetSetPushButton_OnSetLabel( &_this->SettingsButton, EwLoadString( &_Const0013 ));
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Rectangle ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->Text ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->CurrentButton ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->DistanceButton ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->DetectorButton ), 0 );
  CoreGroup_Add((CoreGroup)_this, ((CoreView)&_this->SettingsButton ), 0 );
  ViewsText_OnSetFont( &_this->Text, EwLoadResource( &ApplicationTitelFont, ResourcesFont ));
  _this->CurrentButton.OnRelease = EwNewSlot( _this, ApplicationMenu_UpdateViewCurrent );
  WidgetSetPushButton_OnSetAppearance( &_this->CurrentButton, EwGetAutoObject( &WidgetSetPushButton_Medium, 
  WidgetSetPushButtonConfig ));
  _this->DistanceButton.OnRelease = EwNewSlot( _this, ApplicationMenu_UpdateViewDistance );
  WidgetSetPushButton_OnSetAppearance( &_this->DistanceButton, EwGetAutoObject( 
  &WidgetSetPushButton_Medium, WidgetSetPushButtonConfig ));
  _this->DetectorButton.OnRelease = EwNewSlot( _this, ApplicationMenu_UpdateViewDetector );
  WidgetSetPushButton_OnSetAppearance( &_this->DetectorButton, EwGetAutoObject( 
  &WidgetSetPushButton_Medium, WidgetSetPushButtonConfig ));
  _this->SettingsButton.OnRelease = EwNewSlot( _this, ApplicationMenu_UpdateViewSettings );
  WidgetSetPushButton_OnSetAppearance( &_this->SettingsButton, EwGetAutoObject( 
  &WidgetSetPushButton_Medium, WidgetSetPushButtonConfig ));
}

/* Re-Initializer for the class 'Application::Menu' */
void ApplicationMenu__ReInit( ApplicationMenu _this )
{
  /* At first re-initialize the super class ... */
  CoreGroup__ReInit( &_this->_.Super );

  /* ... then re-construct all embedded objects */
  ViewsRectangle__ReInit( &_this->Rectangle );
  ViewsText__ReInit( &_this->Text );
  WidgetSetPushButton__ReInit( &_this->CurrentButton );
  WidgetSetPushButton__ReInit( &_this->DistanceButton );
  WidgetSetPushButton__ReInit( &_this->DetectorButton );
  WidgetSetPushButton__ReInit( &_this->SettingsButton );
}

/* Finalizer method for the class 'Application::Menu' */
void ApplicationMenu__Done( ApplicationMenu _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreGroup );

  /* Finalize all embedded objects */
  ViewsRectangle__Done( &_this->Rectangle );
  ViewsText__Done( &_this->Text );
  WidgetSetPushButton__Done( &_this->CurrentButton );
  WidgetSetPushButton__Done( &_this->DistanceButton );
  WidgetSetPushButton__Done( &_this->DetectorButton );
  WidgetSetPushButton__Done( &_this->SettingsButton );

  /* Don't forget to deinitialize the super class ... */
  CoreGroup__Done( &_this->_.Super );
}

/* 'C' function for method : 'Application::Menu.UpdateViewDetector()' */
void ApplicationMenu_UpdateViewDetector( ApplicationMenu _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( CoreGroup__IsActiveDialog( _this, 1 ))
    CoreGroup_PresentDialog((CoreGroup)CoreView__GetRoot( _this ), ((CoreGroup)EwNewObject( 
    ApplicationDetectorScreen, 0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* 'C' function for method : 'Application::Menu.UpdateViewDistance()' */
void ApplicationMenu_UpdateViewDistance( ApplicationMenu _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( CoreGroup__IsActiveDialog( _this, 1 ))
    CoreGroup_PresentDialog((CoreGroup)CoreView__GetRoot( _this ), ((CoreGroup)EwNewObject( 
    ApplicationDistanceMeasurement, 0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 
    0 );
}

/* 'C' function for method : 'Application::Menu.UpdateViewCurrent()' */
void ApplicationMenu_UpdateViewCurrent( ApplicationMenu _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( CoreGroup__IsActiveDialog( _this, 1 ))
    CoreGroup_PresentDialog((CoreGroup)CoreView__GetRoot( _this ), ((CoreGroup)EwNewObject( 
    ApplicationCurrentMeasurement, 0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 
    0 );
}

/* 'C' function for method : 'Application::Menu.UpdateViewSettings()' */
void ApplicationMenu_UpdateViewSettings( ApplicationMenu _this, XObject sender )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( CoreGroup__IsActiveDialog( _this, 1 ))
    CoreGroup_PresentDialog((CoreGroup)CoreView__GetRoot( _this ), ((CoreGroup)EwNewObject( 
    ApplicationSettings, 0 )), 0, 0, 0, 0, 0, 0, EwNullSlot, EwNullSlot, 0 );
}

/* Variants derived from the class : 'Application::Menu' */
EW_DEFINE_CLASS_VARIANTS( ApplicationMenu )
EW_END_OF_CLASS_VARIANTS( ApplicationMenu )

/* Virtual Method Table (VMT) for the class : 'Application::Menu' */
EW_DEFINE_CLASS( ApplicationMenu, CoreGroup, Rectangle, Rectangle, Rectangle, Rectangle, 
                 _.VMT, _.VMT, "Application::Menu" )
  CoreRectView_initLayoutContext,
  CoreView_GetRoot,
  CoreGroup_Draw,
  CoreView_HandleEvent,
  CoreGroup_CursorHitTest,
  CoreRectView_ArrangeView,
  CoreRectView_MoveView,
  CoreRectView_GetExtent,
  CoreGroup_ChangeViewState,
  CoreGroup_OnSetBounds,
  CoreGroup_OnSetFocus,
  CoreGroup_OnSetOpacity,
  CoreGroup_IsCurrentDialog,
  CoreGroup_IsActiveDialog,
  CoreGroup_DispatchEvent,
  CoreGroup_BroadcastEvent,
  CoreGroup_UpdateViewState,
  CoreGroup_InvalidateArea,
EW_END_OF_CLASS( ApplicationMenu )

/* User defined inline code: 'Application::Inline' */
/*

  TO DO:

  Include external header files or add type and function declarations needed
  in the implementation of Application::DeviceClass. For example:

    #include "DeviceDriver.h"

    #include "your_middleware_api.h"

    void Your_Middleware_Some_Function( int aSomeArg );

*/

/* Initializer for the class 'Application::DeviceClass' */
void ApplicationDeviceClass__Init( ApplicationDeviceClass _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  TemplatesDeviceClass__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( ApplicationDeviceClass );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( ApplicationDeviceClass );

  /* Call the user defined constructor */
  ApplicationDeviceClass_Init( _this, aArg );
}

/* Re-Initializer for the class 'Application::DeviceClass' */
void ApplicationDeviceClass__ReInit( ApplicationDeviceClass _this )
{
  /* At first re-initialize the super class ... */
  TemplatesDeviceClass__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Application::DeviceClass' */
void ApplicationDeviceClass__Done( ApplicationDeviceClass _this )
{
  /* Call the user defined destructor of the class */
  ApplicationDeviceClass_Done( _this );

  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( TemplatesDeviceClass );

  /* Don't forget to deinitialize the super class ... */
  TemplatesDeviceClass__Done( &_this->_.Super );
}

/* 'C' function for method : 'Application::DeviceClass.Done()' */
void ApplicationDeviceClass_Done( ApplicationDeviceClass _this )
{
  XObject thisObject = ((XObject)_this );

  {
    /*
       TO DO:

       Depending on your application case you call functions of the underlying
       middleware (or access the device directly) in order to perform the necessary
       de-initialization steps. For example, you invoke some 'C' function:

         YourDevice_DeInitialize();

       IMPORTANT:
       ----------

       The variable 'thisObject' represents the actually de-initialized instance of the
       Application::DeviceClass. If you have stored this object at the initialization
       time (in the 'Init' method) in some global C variable or registered it by the
       middleware, it is important to perform now the opposite operation. Set the
       global variable to NULL or de-register 'thisObject' object from the middleware.

    */
  }
}

/* 'C' function for method : 'Application::DeviceClass.Init()' */
void ApplicationDeviceClass_Init( ApplicationDeviceClass _this, XHandle aArg )
{
  XObject thisObject;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aArg );

  thisObject = ((XObject)_this );
  {
    /*
       TO DO:

       Depending on your application case you call functions of the underlying
       middleware (or access the device directly) in order to perform the necessary
       initialization steps. For example, you invoke some 'C' function:

         YourDevice_Initialize();

       The variable 'thisObject' represents the actually initialized instance of the
       Application::DeviceClass. You can store this variable e.g. in the middleware
       and use it whenever the middleware needs to notify the GUI application about
       some state alternation or events. In this manner, the middleware will be able
       to invoke methods of the interface device object.

       For example, you can store 'thisObject' in some global C variable:

         // Declaration of the global C variable
         XObject theDeviceObject;

         // Store the instance in the global variable
         theDeviceObject = thisObject;

       Later use the global variable e.g. to provide the GUI application with events:

         ApplicationDeviceClass__TriggerSomeEvent( theDeviceObject );

       IMPORTANT:
       ----------

       If you store 'thisObject' for later use, don't forget to implement the opposite
       operation in the method 'Done'. Concrete, 'Done' should set the global variable
       again to the value NULL.

    */
  }
}

/* 'C' function for method : 'Application::DeviceClass.OnSetLamptest()' */
void ApplicationDeviceClass_OnSetLamptest( ApplicationDeviceClass _this, XBool value )
{
  if ( _this->Lamptest == value )
    return;

  _this->Lamptest = value;
  {
    if(value){
      DeviceDriver_SetLampTest();
    }
  }
  EwNotifyRefObservers( EwNewRef( _this, ApplicationDeviceClass_OnGetLamptest, ApplicationDeviceClass_OnSetLamptest ), 
    0 );
}

/* Default onget method for the property 'Lamptest' */
XBool ApplicationDeviceClass_OnGetLamptest( ApplicationDeviceClass _this )
{
  return _this->Lamptest;
}

/* Variants derived from the class : 'Application::DeviceClass' */
EW_DEFINE_CLASS_VARIANTS( ApplicationDeviceClass )
EW_END_OF_CLASS_VARIANTS( ApplicationDeviceClass )

/* Virtual Method Table (VMT) for the class : 'Application::DeviceClass' */
EW_DEFINE_CLASS( ApplicationDeviceClass, TemplatesDeviceClass, _.VMT, _.VMT, _.VMT, 
                 _.VMT, _.VMT, _.VMT, "Application::DeviceClass" )
EW_END_OF_CLASS( ApplicationDeviceClass )

/* User defined auto object: 'Application::Device' */
EW_DEFINE_AUTOOBJECT( ApplicationDevice, ApplicationDeviceClass )

/* Initializer for the auto object 'Application::Device' */
void ApplicationDevice__Init( ApplicationDeviceClass _this )
{
  EW_UNUSED_ARG( _this );
}

/* Table with links to derived variants of the auto object : 'Application::Device' */
EW_DEFINE_AUTOOBJECT_VARIANTS( ApplicationDevice )
EW_END_OF_AUTOOBJECT_VARIANTS( ApplicationDevice )

/* Embedded Wizard */
