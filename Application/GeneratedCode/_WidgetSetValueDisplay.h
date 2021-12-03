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

#ifndef _WidgetSetValueDisplay_H
#define _WidgetSetValueDisplay_H

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

#include "_CoreGroup.h"

/* Forward declaration of the class Core::DialogContext */
#ifndef _CoreDialogContext_
  EW_DECLARE_CLASS( CoreDialogContext )
#define _CoreDialogContext_
#endif

/* Forward declaration of the class Core::KeyPressHandler */
#ifndef _CoreKeyPressHandler_
  EW_DECLARE_CLASS( CoreKeyPressHandler )
#define _CoreKeyPressHandler_
#endif

/* Forward declaration of the class Core::LayoutContext */
#ifndef _CoreLayoutContext_
  EW_DECLARE_CLASS( CoreLayoutContext )
#define _CoreLayoutContext_
#endif

/* Forward declaration of the class Core::TaskQueue */
#ifndef _CoreTaskQueue_
  EW_DECLARE_CLASS( CoreTaskQueue )
#define _CoreTaskQueue_
#endif

/* Forward declaration of the class Core::View */
#ifndef _CoreView_
  EW_DECLARE_CLASS( CoreView )
#define _CoreView_
#endif

/* Forward declaration of the class Effects::Fader */
#ifndef _EffectsFader_
  EW_DECLARE_CLASS( EffectsFader )
#define _EffectsFader_
#endif

/* Forward declaration of the class Views::Text */
#ifndef _ViewsText_
  EW_DECLARE_CLASS( ViewsText )
#define _ViewsText_
#endif

/* Forward declaration of the class WidgetSet::ValueDisplay */
#ifndef _WidgetSetValueDisplay_
  EW_DECLARE_CLASS( WidgetSetValueDisplay )
#define _WidgetSetValueDisplay_
#endif

/* Forward declaration of the class WidgetSet::ValueDisplayConfig */
#ifndef _WidgetSetValueDisplayConfig_
  EW_DECLARE_CLASS( WidgetSetValueDisplayConfig )
#define _WidgetSetValueDisplayConfig_
#endif


/* This class implements a 'value display' widget. The widget is intended to display 
   a numerical value together with the associated unit (e.g. °C or Volt). The actual 
   value is determined in the property @CurrentValue. Since @CurrentValue is 'int32', 
   you can use the properties @CurrentFactor and @CurrentBias to convert the original 
   value to the expected value range. The conversion follows the equation below:
   ValueToDisplay = ( @CurrentValue * @CurrentFactor ) + @CurrentBias
   Alternative to modify directly the property @CurrentValue, the property @Outlet 
   can refer to any other 'int32' property the widget should remain synchronized 
   with. When the referred property is modified by another one, the widget is automatically 
   notified to remain in sync with the property.
   This approach follows the Model-View-Controller (MVC) programming paradigm. Here 
   the value display widget represents the 'View' and the property referred via 
   'Outlet' can be seen as a part of the 'Model'.
   During its lifetime the widget remains always in one of the both states: 'positive' 
   or 'negative'. The state 'positive' is true if the value resulting from the above 
   equation is greater than or equal to 0 (zero). The state 'negative' is true, 
   if the resulting value is less than 0 (zero).
   The exact look and feel of the widget is determined by the 'Value Display Configuration' 
   object assigned to the property @Appearance. The configuration object provides 
   fonts, colors and other configuration parameters needed to construct and display 
   the widget. Usually, you will manage in your project your own configuration objects 
   and customize the value display widgets according to your design expectations. 
   Depending on the information provided in the associated configuration object, 
   the value display widget will be composed of following views:
   - 'Value' is a text view (Views::Text) displayed per default in the center of 
   the widget. The corresponding text is formatted from the result of the above 
   equation. With the both properties @NoOfDigits and @Precision you control this 
   format operation. Further localization specific aspects to be taken account during 
   the format operation are determined in the associated configuration object. This 
   includes in particular the used decimal sign, the digit group sign, the leading 
   '+' (plus) or '-' (minus) signs, etc.. In the configuration object you can also 
   specify the font, alignment and margins to use for the text view as well as colors 
   for every widget state (positive and negative).
   - 'Unit' is a text view (Views::Text) displayed per default in the center of 
   the widget. The corresponding text is determined in the property @Unit. In the 
   configuration object you can specify the font, alignment and margins to use for 
   the text view. For every widget state (positive or negative) you can specify 
   individual text color values.
   Per default the both views 'Value' and 'Unit' are arranged within the widget 
   area independently. In the configuration object you can specify other layout 
   modes to e.g. arrange the unit to appear appended at the right edge of the displayed 
   value.
   For more details regarding the customization of the value display widget see 
   the description of WidgetSet::ValueDisplayConfig class. */
EW_DEFINE_FIELDS( WidgetSetValueDisplay, CoreGroup )
  EW_VARIABLE( textView2,       ViewsText )
  EW_VARIABLE( textView1,       ViewsText )

  /* The property 'Appearance' refers to a 'Value Display Config' object containing 
     fonts, colors and further configuration attributes to customize this widget. 
     By assigning a configuration object to the property 'Appearance', the widget 
     automatically assumes the look and feel as determined in the properties of 
     the configuration object.
     If there is no configuration object associated to the widget (the property 
     'Appearance' is 'null') the widget appears empty (transparent).
     Please note, configuration objects can be shared among multiple value display 
     widgets. When the properties of the configuration object change, all value 
     display widgets (connected actually to it) are notified and updated to assume 
     the new appearance. */
  EW_PROPERTY( Appearance,      WidgetSetValueDisplayConfig )
  EW_VARIABLE( valueString,     XString )

  /* The property 'Unit' specifies the text to display as unit in this widget. The 
     desired font as well as the colors for all individual widget states have to 
     be specified in the configuration object assigned to the property @Appearance. 
     If there is no configuration object associated to this widget (the property 
     @Appearance is 'null'), no unit is displayed.
     Per default, the unit is displayed centered within the widget area. You can 
     modify the alignment of the unit as well as its margins by specifying them 
     in the configuration object. */
  EW_PROPERTY( Unit,            XString )

  /* The property 'Precision' determines the number of digits to display after the 
     decimal sign (after the integer part) of the number resulting from the equation 
     below:
     ValueToDisplay = ( @CurrentValue * @CurrentFactor ) + @CurrentBias
     If this property is 0 (zero), only the integer part of the resulting number 
     is displayed. The decimal sign is per default '.' (dot). You can configure 
     another localization specific decimal sign in the configuration object assigned 
     to the property @Appearance. The total number of digits to display is determined 
     in the property @NoOfDigits. */
  EW_PROPERTY( Precision,       XInt32 )
EW_END_OF_FIELDS( WidgetSetValueDisplay )

/* Virtual Method Table (VMT) for the class : 'WidgetSet::ValueDisplay' */
EW_DEFINE_METHODS( WidgetSetValueDisplay, CoreGroup )
  EW_METHOD( initLayoutContext, void )( CoreRectView _this, XRect aBounds, CoreOutline 
    aOutline )

  /* The method GetRoot() delivers the application object, this view belongs to. 
     The application object represents the entire screen of the GUI application. 
     Thus in the views hierarchy, the application object serves as the root view.
     This method can fail and return null if the view still doesn't belong to any 
     owner group. */
  EW_METHOD( GetRoot,           CoreRoot )( CoreView _this )
  EW_METHOD( Draw,              void )( CoreGroup _this, GraphicsCanvas aCanvas, 
    XRect aClip, XPoint aOffset, XInt32 aOpacity, XBool aBlend )

  /* The method HandleEvent() is invoked automatically if the view has received 
     an event. For example, touching the view on the touch screen can cause the 
     view to receive a Core::CursorEvent event. Within this method the view can 
     evaluate the event and react to it.
     Whether the event has been handled by the view or not is determined by the 
     return value. To sign an event as handled HandleEvent() should return a valid 
     object (e.g. 'this'). If the event has not been handled, 'null' should be returned.
     Depending on the kind of the event, the framework can continue dispatching 
     of still unhandled events. For example, keyboard events (Core::KeyEvent class) 
     are automatically delivered to the superior @Owner of the receiver view if 
     this view has ignored the event.
     HandleEvent() is invoked automatically by the framework, so you never should 
     need to invoke it directly. However you can prepare and post new events by 
     using the methods DispatchEvent() and BroadcastEvent() of the application class 
     Core::Root. */
  EW_METHOD( HandleEvent,       XObject )( CoreView _this, CoreEvent aEvent )

  /* The method CursorHitTest() is invoked automatically in order to determine whether 
     the view is interested in the receipt of cursor events or not. This method 
     will be invoked immediately after the user has tapped the visible area of the 
     view. If the view is not interested in the cursor event, the framework repeats 
     this procedure for the next behind view until a willing view has been found 
     or all views are evaluated.
     In the implementation of the method the view can evaluate the passed aArea 
     parameter. It determines the place where the user has tapped the view with 
     his fingertip expressed in the coordinates of the views @Owner. The method 
     can test e.g. whether the tapped area does intersect any touchable areas within 
     the view, etc. The affected finger is identified in the parameter aFinger. 
     The first finger (or the first mouse device button) has the number 0.
     The parameter aStrikeCount determines how many times the same area has been 
     tapped in series. This is useful to detect series of multiple touches, e.g. 
     in case of the double click, aStrikeCount == 2.
     The parameter aDedicatedView, if it is not 'null', restricts the event to be 
     handled by this view only. If aDedicatedView == null, no special restriction 
     exists.
     This method is also invoked if during an existing grab cycle the current target 
     view has decided to resign and deflect the cursor events to another view. This 
     is usually the case after the user has performed a gesture the current target 
     view is not interested to process. Thereupon, the system looks for another 
     view willing to take over the cursor event processing after the performed gesture. 
     Which gesture has caused the operation, is specified in the parameter aRetargetReason.
     If the view is willing to process the event, the method should create, initialize 
     and return a new Core::CursorHit object. This object identify the willing view. 
     Otherwise the method should return 'null'.
     CursorHitTest() is invoked automatically by the framework, so you never should 
     need to invoke it directly. This method is predetermined for the hit-test only. 
     The proper processing of events should take place in the @HandleEvent() method 
     by reacting to Core::CursorEvent and Core::DragEvent events. */
  EW_METHOD( CursorHitTest,     CoreCursorHit )( CoreGroup _this, XRect aArea, XInt32 
    aFinger, XInt32 aStrikeCount, CoreView aDedicatedView, XSet aRetargetReason )

  /* The method ArrangeView() is invoked automatically if the superior @Owner group 
     needs to re-arrange its views. For example, the changing of the owners size 
     can cause the enclosed views to adapt their position and size, so all views 
     still fit within the new owners area. This method provides the core functionality 
     for the automatic GUI layout mechanism.
     The arrangement is controlled primarily by the @Layout property of the view. 
     It specifies a set of alignment constraints and determines whether the view 
     can change its size. The bounds area where the view should be arranged, is 
     passed in the parameter aBounds. This is usually the current area of the views 
     owner.
     The parameter aFormation defines the desired arrangement mode. Depending on 
     the value of this parameter, the views can be arranged in rows or columns. 
     If aFormation == Core::Formation.None, no automatic row/column arrangement 
     is performed and the view is moved and scaled only to fit inside the aBounds 
     area.
     ArrangeView() is invoked automatically by the framework, so you never should 
     need to invoke it directly.
     The method returns the size of the view after it has been arranged. */
  EW_METHOD( ArrangeView,       XPoint )( CoreRectView _this, XRect aBounds, XEnum 
    aFormation )

  /* The method MoveView() changes the position of the view by adding the value 
     aOffset to all corners of the view. For example, in case of a line view the 
     value is added to the both line end points.
     The parameter aFastMove serves for the optimization purpose. If it is 'true', 
     the corners are modified without performing any updates of the view and without 
     redrawing the screen. This is useful, when you wish to move or arrange a lot 
     of views at once. In this case it's up to you to request the finally screen 
     update. To do this you can use the method InvalidateArea() of the views @Owner.
     In the case aFastMove == false, the operation automatically requests the screen 
     redraw of the view areas before and after the movement. You don't need to take 
     care about it. */
  EW_METHOD( MoveView,          void )( CoreRectView _this, XPoint aOffset, XBool 
    aFastMove )

  /* The method GetExtent() returns the position and the size of the view relative 
     to the origin of its @Owner. In case of views with a non rectangular shape 
     the method returns the rectangular boundary area enclosing the entire shape. */
  EW_METHOD( GetExtent,         XRect )( CoreRectView _this )

  /* The method ChangeViewState() modifies the current state of the view. The state 
     is a set of switches determining whether a view is visible, whether it can 
     react to user inputs or whether it is just performing some update operations, 
     etc.
     The modification is controlled by the the both parameters. The first aSetState 
     contains the switches to activate within the view state. The second aClearState 
     determines all switches to disable.
     Depending on the state alteration the method will perform different operations, 
     e.g. in response to the clearing of the visible state, the method will request 
     a screen redraw to make disappear the view from the screen.
     ChangeViewState() is invoked automatically by the framework, so you never should 
     need to invoke it directly. All relevant states are available as properties 
     e.g. the property Visible in derived classes reflects the visible state of 
     the view. */
  EW_METHOD( ChangeViewState,   void )( CoreGroup _this, XSet aSetState, XSet aClearState )
  EW_METHOD( OnSetBounds,       void )( WidgetSetValueDisplay _this, XRect value )
  EW_METHOD( OnSetFocus,        void )( CoreGroup _this, CoreView value )
  EW_METHOD( OnSetOpacity,      void )( CoreGroup _this, XInt32 value )

  /* The method IsCurrentDialog() returns 'true' if 'this' component and all of 
     its owners do actually act as active dialogs (see the method @IsActiveDialog()) 
     and there are no further subordinated dialogs existing in context of 'this' 
     component. In other words, 'this' component is absolutely the top-most dialog 
     of all dialogs shown actually in the GUI application, so all user interactions 
     are primarily directed to 'this' dialog.
     If the component has not been presented, it has been dismissed, other dialog 
     has been presented in meantime overlying 'this' component, the owner of the 
     component is not itself an active dialog, or there is other dialog presented 
     in context of 'this' component, the method returns 'false'. */
  EW_METHOD( IsCurrentDialog,   XBool )( CoreGroup _this )

  /* The method IsActiveDialog() returns 'true' if 'this' component does actually 
     act as a dialog (see the method @IsDialog()) and it is the current (top-most) 
     dialog in context of its owner component. If the parameter aRecursive is 'true', 
     the owner in context of which 'this' component actually exists and all superior 
     owners have also to be active dialogs or the owner has to be the application 
     root component.
     If the component is not a dialog, or other dialog has been presented in the 
     meantime overlying 'this' component, the method returns 'false'. Similarly, 
     if the parameter aRecursive is 'true' and the owner of the component is itself 
     not an active dialog, the method returns 'false'. */
  EW_METHOD( IsActiveDialog,    XBool )( CoreGroup _this, XBool aRecursive )

  /* The method DispatchEvent() feeds the component with the event passed in the 
     parameter aEvent and propagates it along the so-called focus path. This focus 
     path leads to the currently selected keyboard event receiver view. If the event 
     is rejected by the view, the same operation is repeated for the next superior 
     view. This permits the hierarchical event dispatching until a willing view 
     has handled the event or all views in the focus path have been evaluated. If 
     the event remains still unhandled, it will be passed to the component itself.
     The focus path is established by the property @Focus. 
     DispatchEvent() returns the value returned by the @HandleEvent() method of 
     the view which has handled the event. In the case, the event was not handled, 
     the method returns 'null'. */
  EW_METHOD( DispatchEvent,     XObject )( CoreGroup _this, CoreEvent aEvent )

  /* The method BroadcastEvent() feeds the component with the event passed in the 
     parameter aEvent and propagates it to all views enclosed within the component 
     until the event has been handled or all views are evaluated. If the event remains 
     still unhandled, it will be passed to the component itself.
     The additional parameter aFilter can be used to limit the operation to special 
     views only, e.g. to visible and touchable views. To broadcast the event to 
     all views pass in the parameter aFilter the value 'Core::ViewState[]'.
     BroadcastEvent() is very useful to provide all views with one and the same 
     event in order e.g. to inform all views about an important global state alteration. 
     To send events to views enclosing a given position use the method @BroadcastEventAtPosition().
     BroadcastEvent() returns the value returned by the @HandleEvent() method of 
     the view which has handled the event. In the case, the event was not handled, 
     the method returns 'null'. */
  EW_METHOD( BroadcastEvent,    XObject )( CoreGroup _this, CoreEvent aEvent, XSet 
    aFilter )

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
  EW_METHOD( UpdateViewState,   void )( WidgetSetValueDisplay _this, XSet aState )

  /* The method InvalidateArea() declares the given area of the component as invalid, 
     this means this area should be redrawn at the next screen update. */
  EW_METHOD( InvalidateArea,    void )( CoreGroup _this, XRect aArea )
EW_END_OF_METHODS( WidgetSetValueDisplay )

/* 'C' function for method : 'WidgetSet::ValueDisplay.OnSetBounds()' */
void WidgetSetValueDisplay_OnSetBounds( WidgetSetValueDisplay _this, XRect value );

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
void WidgetSetValueDisplay_UpdateViewState( WidgetSetValueDisplay _this, XSet aState );

/* 'C' function for method : 'WidgetSet::ValueDisplay.onLayoutViews()' */
void WidgetSetValueDisplay_onLayoutViews( WidgetSetValueDisplay _this, XObject sender );

/* 'C' function for method : 'WidgetSet::ValueDisplay.onFormatValue()' */
void WidgetSetValueDisplay_onFormatValue( WidgetSetValueDisplay _this, XObject sender );

/* 'C' function for method : 'WidgetSet::ValueDisplay.onConfigChanged()' */
void WidgetSetValueDisplay_onConfigChanged( WidgetSetValueDisplay _this, XObject 
  sender );

/* 'C' function for method : 'WidgetSet::ValueDisplay.OnSetUnit()' */
void WidgetSetValueDisplay_OnSetUnit( WidgetSetValueDisplay _this, XString value );

/* 'C' function for method : 'WidgetSet::ValueDisplay.OnSetPrecision()' */
void WidgetSetValueDisplay_OnSetPrecision( WidgetSetValueDisplay _this, XInt32 value );

/* 'C' function for method : 'WidgetSet::ValueDisplay.OnSetAppearance()' */
void WidgetSetValueDisplay_OnSetAppearance( WidgetSetValueDisplay _this, WidgetSetValueDisplayConfig 
  value );

#ifdef __cplusplus
  }
#endif

#endif /* _WidgetSetValueDisplay_H */

/* Embedded Wizard */
