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

#ifndef _WidgetSetToggleButton_H
#define _WidgetSetToggleButton_H

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
#include "_CoreKeyPressHandler.h"
#include "_CoreSimpleTouchHandler.h"
#include "_CoreTimer.h"

/* Forward declaration of the class Core::DialogContext */
#ifndef _CoreDialogContext_
  EW_DECLARE_CLASS( CoreDialogContext )
#define _CoreDialogContext_
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

/* Forward declaration of the class Views::Frame */
#ifndef _ViewsFrame_
  EW_DECLARE_CLASS( ViewsFrame )
#define _ViewsFrame_
#endif

/* Forward declaration of the class Views::Text */
#ifndef _ViewsText_
  EW_DECLARE_CLASS( ViewsText )
#define _ViewsText_
#endif

/* Forward declaration of the class WidgetSet::ToggleButton */
#ifndef _WidgetSetToggleButton_
  EW_DECLARE_CLASS( WidgetSetToggleButton )
#define _WidgetSetToggleButton_
#endif

/* Forward declaration of the class WidgetSet::ToggleButtonConfig */
#ifndef _WidgetSetToggleButtonConfig_
  EW_DECLARE_CLASS( WidgetSetToggleButtonConfig )
#define _WidgetSetToggleButtonConfig_
#endif


/* This class implements a bistable 'toggle button' widget (a switch). When the 
   user taps the button, the current state of the button represented by the boolean 
   property @Checked is toggled and signal is sent to one of the slot methods stored 
   in the properties @OnSwitchOff or @OnSwitchOn. By connecting further slot methods 
   to the properties @OnPress, @OnRelease, @OnEnter and @OnLeave you can react to 
   other events triggered while the user interacts with the button.
   Alternatively the property @Outlet can refer to any other 'bool' property the 
   widget should remain synchronized with. When the user toggles the button, the 
   affected property is automatically updated to reflect the button's current state. 
   On the other hand, when the referred property is modified by another one, the 
   toggle button is automatically notified to remain in sync with the property.
   This approach follows the Model-View-Controller (MVC) programming paradigm. Here 
   the toggle button represents the 'View' and 'Controller' and the property referred 
   via 'Outlet' can be seen as a part of the 'Model'.
   During its lifetime the button remains always in one of the four states: 'disabled', 
   'default', 'focused' and 'active'. The state 'disabled' is true for every not 
   available button (the property @Enabled of the button is 'false'). Such buttons 
   will ignore all user inputs. The state 'default' determines a button, which is 
   ready to be touched by the user or ready to become focused. As soon as the button 
   becomes focused, it switches in the state 'focused'. In this state the user can 
   activate the button by pressing a key on the keyboard. Finally, the state 'active' 
   is true, if the user actually interacts with the button (the button is pressed).
   The exact look and feel of the toggle button is determined by the 'Toggle Button 
   Configuration' object assigned to the property @Appearance. The configuration 
   object provides bitmaps, colors, fonts and other configuration parameters needed 
   to construct and display the toggle button. Usually, you will manage in your 
   project your own configuration objects and customize the toggle buttons according 
   to your design expectations. Depending on the information provided in the associated 
   configuration object, the toggle button will be composed of following views:
   - 'Face' is a bitmap frame view (Views::Frame) filling per default the entire 
   background of the button. In the configuration object you can individually specify 
   for every button state the desired bitmap, its opacity, frame number (if the 
   bitmap is multi-frame) and tint color (if the bitmap contains Alpha8 information 
   only). The button can automatically play animated bitmaps. If desired, you can 
   also configure the bitmap to be arranged horizontally and vertically instead 
   of filling the entire widget area.
   - 'Icon' is an image view (Views::Image) displayed per default in the center 
   of the button. The corresponding bitmap is determined in the property @Icon. 
   If the bitmap is multi-frame, the desired frame number can be selected by using 
   the property @IconFrame or individually for every button state by using the properties 
   @IconOffFrame, @IconOnFrame, @IconOffFrameActive, @IconOffFrameDefault, @IconOffFrameDisabled, 
   @IconOffFrameFocused, @IconOnFrameActive, @IconOnFrameDefault, @IconOnFrameDisabled 
   and @IconOnFrameFocused In the configuration object you can specify the alignment 
   and margins how to arrange the @Icon bitmap within the button area. Furthermore, 
   for every button state the opacity and tint color (if the @Icon bitmap contains 
   Alpha8 information only) can be determined. The button can automatically play 
   animated bitmaps.
   - 'Label' is a text view (Views::Text) displayed per default in the center of 
   the button. The corresponding text is determined in the property @Label or @LabelOff 
   and @LabelOn depending on the current state of the button (property @Checked). 
   In the configuration object you can specify the font, alignment and margins to 
   use for the text view. For every button state you can specify individual text 
   color values.
   In particular application cases you can instruct the button to automatically 
   resign and retarget the actual touch interaction to another touch handler (e.g. 
   another widget) after the user has performed a horizontal wipe gesture (@ResignAfterHorizontalWipe) 
   or vertical wipe gesture (@ResignAfterVerticalWipe). Using these properties several 
   widgets can cooperate during an active user interaction even if these handler 
   overlap each other.
   If the button is actually focused, it can also be activated by pressing the keyboard 
   key Core::KeyCode.Enter. In the configuration object you can specify another 
   key code, if desired. To prevent the button from being able to be focused, specify 
   in the configuration object the Core::KeyCode.NoKey as the code to activate the 
   button.
   For more details regarding the customization of the button see the description 
   of WidgetSet::ToggleButtonConfig class. */
EW_DEFINE_FIELDS( WidgetSetToggleButton, CoreGroup )
  EW_VARIABLE( textView,        ViewsText )
  EW_VARIABLE( frameView,       ViewsFrame )

  /* The property 'Appearance' refers to a 'Toggle Button Config' object containing 
     bitmaps, colors, fonts and further configuration attributes to customize this 
     toggle button widget. By assigning a configuration object to the property 'Appearance', 
     the toggle button automatically assumes the look and feel as determined in 
     the properties of the configuration object.
     If there is no configuration object associated to the toggle button (the property 
     'Appearance' is 'null') the toggle button limits to display the bitmap specified 
     in the property @Icon.
     Please note, configuration objects can be shared among multiple toggle button 
     widgets. When the properties of the configuration object change, all toggle 
     buttons (connected actually to it) are notified and updated to assume the new 
     appearance. */
  EW_PROPERTY( Appearance,      WidgetSetToggleButtonConfig )

  /* The property 'Outlet' can refer to any other 'bool' property the widget should 
     remain synchronized with. When the user toggles the button, the affected property 
     is automatically updated to reflect the button's current state. On the other 
     hand, when the referred property is modified by another one, the toggle button 
     is automatically notified to remain in sync with the property (the property 
     @Checked is updated to the value of the property referred in Outlet).
     This approach follows the Model-View-Controller (MVC) programming paradigm. 
     Here the toggle button represents the 'View' and 'Controller' and the property 
     referred via 'Outlet' can be seen as a part of the 'Model'. */
  EW_PROPERTY( Outlet,          XRef )
  EW_OBJECT  ( FlashTimer,      CoreTimer )
  EW_OBJECT  ( KeyHandler,      CoreKeyPressHandler )
  EW_OBJECT  ( TouchHandler,    CoreSimpleTouchHandler )

  /* The property 'LabelOn' specifies the text to display as label in this toggle 
     button widget when it is in the switched-on state (property @Checked is 'true'). 
     The desired font as well as the colors for all individual button states have 
     to be specified in the configuration object assigned to the property @Appearance. 
     If there is no configuration object associated to this toggle button widget 
     (the property @Appearance is 'null'), no label is displayed.
     Per default, the label is displayed centered within the toggle button area. 
     You can modify the alignment of the label as well as its margins by specifying 
     them in the configuration object. */
  EW_PROPERTY( LabelOn,         XString )

  /* The property 'LabelOff' specifies the text to display as label in this toggle 
     button widget when it is in the switched-off state (property @Checked is 'false'). 
     The desired font as well as the colors for all individual button states have 
     to be specified in the configuration object assigned to the property @Appearance. 
     If there is no configuration object associated to this toggle button widget 
     (the property @Appearance is 'null'), no label is displayed.
     Per default, the label is displayed centered within the toggle button area. 
     You can modify the alignment of the label as well as its margins by specifying 
     them in the configuration object. */
  EW_PROPERTY( LabelOff,        XString )
  EW_VARIABLE( onPressKeyTime,  XUInt32 )

  /* The property 'Checked' stores the current state of the toggle button. As long 
     as the property is 'false', the widget is in switched-off state. In turn, initializing 
     the property with the value 'true' causes the button to change in the switched-on 
     state. */
  EW_PROPERTY( Checked,         XBool )
EW_END_OF_FIELDS( WidgetSetToggleButton )

/* Virtual Method Table (VMT) for the class : 'WidgetSet::ToggleButton' */
EW_DEFINE_METHODS( WidgetSetToggleButton, CoreGroup )
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
  EW_METHOD( OnSetBounds,       void )( WidgetSetToggleButton _this, XRect value )
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
  EW_METHOD( UpdateViewState,   void )( WidgetSetToggleButton _this, XSet aState )

  /* The method InvalidateArea() declares the given area of the component as invalid, 
     this means this area should be redrawn at the next screen update. */
  EW_METHOD( InvalidateArea,    void )( CoreGroup _this, XRect aArea )
EW_END_OF_METHODS( WidgetSetToggleButton )

/* 'C' function for method : 'WidgetSet::ToggleButton.OnSetBounds()' */
void WidgetSetToggleButton_OnSetBounds( WidgetSetToggleButton _this, XRect value );

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
void WidgetSetToggleButton_UpdateViewState( WidgetSetToggleButton _this, XSet aState );

/* 'C' function for method : 'WidgetSet::ToggleButton.onConfigChanged()' */
void WidgetSetToggleButton_onConfigChanged( WidgetSetToggleButton _this, XObject 
  sender );

/* 'C' function for method : 'WidgetSet::ToggleButton.onOutlet()' */
void WidgetSetToggleButton_onOutlet( WidgetSetToggleButton _this, XObject sender );

/* 'C' function for method : 'WidgetSet::ToggleButton.onFlashTimer()' */
void WidgetSetToggleButton_onFlashTimer( WidgetSetToggleButton _this, XObject sender );

/* 'C' function for method : 'WidgetSet::ToggleButton.onReleaseKey()' */
void WidgetSetToggleButton_onReleaseKey( WidgetSetToggleButton _this, XObject sender );

/* 'C' function for method : 'WidgetSet::ToggleButton.onPressKey()' */
void WidgetSetToggleButton_onPressKey( WidgetSetToggleButton _this, XObject sender );

/* 'C' function for method : 'WidgetSet::ToggleButton.onLeaveTouch()' */
void WidgetSetToggleButton_onLeaveTouch( WidgetSetToggleButton _this, XObject sender );

/* 'C' function for method : 'WidgetSet::ToggleButton.onEnterTouch()' */
void WidgetSetToggleButton_onEnterTouch( WidgetSetToggleButton _this, XObject sender );

/* 'C' function for method : 'WidgetSet::ToggleButton.onReleaseTouch()' */
void WidgetSetToggleButton_onReleaseTouch( WidgetSetToggleButton _this, XObject 
  sender );

/* 'C' function for method : 'WidgetSet::ToggleButton.onPressTouch()' */
void WidgetSetToggleButton_onPressTouch( WidgetSetToggleButton _this, XObject sender );

/* 'C' function for method : 'WidgetSet::ToggleButton.OnSetOutlet()' */
void WidgetSetToggleButton_OnSetOutlet( WidgetSetToggleButton _this, XRef value );

/* 'C' function for method : 'WidgetSet::ToggleButton.OnSetChecked()' */
void WidgetSetToggleButton_OnSetChecked( WidgetSetToggleButton _this, XBool value );

/* 'C' function for method : 'WidgetSet::ToggleButton.OnSetLabel()' */
void WidgetSetToggleButton_OnSetLabel( WidgetSetToggleButton _this, XString value );

/* 'C' function for method : 'WidgetSet::ToggleButton.OnSetAppearance()' */
void WidgetSetToggleButton_OnSetAppearance( WidgetSetToggleButton _this, WidgetSetToggleButtonConfig 
  value );

#ifdef __cplusplus
  }
#endif

#endif /* _WidgetSetToggleButton_H */

/* Embedded Wizard */
