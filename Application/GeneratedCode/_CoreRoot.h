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

#ifndef _CoreRoot_H
#define _CoreRoot_H

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
#include "_CoreTimer.h"

/* Forward declaration of the class Core::CursorEvent */
#ifndef _CoreCursorEvent_
  EW_DECLARE_CLASS( CoreCursorEvent )
#define _CoreCursorEvent_
#endif

/* Forward declaration of the class Core::CursorGrabEvent */
#ifndef _CoreCursorGrabEvent_
  EW_DECLARE_CLASS( CoreCursorGrabEvent )
#define _CoreCursorGrabEvent_
#endif

/* Forward declaration of the class Core::DialogContext */
#ifndef _CoreDialogContext_
  EW_DECLARE_CLASS( CoreDialogContext )
#define _CoreDialogContext_
#endif

/* Forward declaration of the class Core::DragEvent */
#ifndef _CoreDragEvent_
  EW_DECLARE_CLASS( CoreDragEvent )
#define _CoreDragEvent_
#endif

/* Forward declaration of the class Core::Event */
#ifndef _CoreEvent_
  EW_DECLARE_CLASS( CoreEvent )
#define _CoreEvent_
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

/* Forward declaration of the class Core::Root */
#ifndef _CoreRoot_
  EW_DECLARE_CLASS( CoreRoot )
#define _CoreRoot_
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

/* Forward declaration of the class Graphics::Canvas */
#ifndef _GraphicsCanvas_
  EW_DECLARE_CLASS( GraphicsCanvas )
#define _GraphicsCanvas_
#endif


/* The class Core::Root provides the base functionality for the entire GUI application. 
   Due to its ancestry, the application provides the entire set of functionality 
   implemented in the Core::Group class. It serves as the root container for all 
   GUI components, menus, panels, etc.
   The application also provides an interface to the underlying target system and 
   to the screen. The coordinate system of the application corresponds therefore 
   to the coordinate system of the screen. Every Embedded Wizard application needs 
   one application object.
   The interface of the Core::Root class provides several methods and properties 
   to control the application and to coordinate the screen update and the event 
   dispatching. For example:
   The property @Keyboard allows the management of virtual keyboard components. 
   A keyboard component is an ordinary GUI component you can design and fill e.g. 
   with buttons. Its job is to generate keyboard events in response to other user 
   interaction events, like the touch event. For this purpose the application will 
   provide the virtual keyboard component with all necessary touch events before 
   these are passed to the remaining parts of the GUI. Additionally, the application 
   ensures that the virtual keyboard always remains visible on the top of the screen.
   - The methods @BeginAnimation() and @EndAnimation() allow you to temporarily 
   deactivate the handling of keyboard and mouse/touch panel events. This is useful 
   during animated screen transitions to avoid interferences with user interactions.
   - The methods @BeginModal() and @EndModal() are useful to temporarily limit the 
   event delivery to a particular component. In this manner the component will become 
   'modal'. The event delivery limitation ensures that the user will interact with 
   the given component only whereas the remaining GUI parts are not available. Modal 
   GUI components are very common in all GUI applications.
   - The methods @CaptureCursor(), @DeflectCursor() and @RetargetCursor() affect 
   the flow of touch events. They are used in special cases, when e.g. after receiving 
   a touch event the component needs to redirect the events to other component.
   - The methods @DriveCursorHitting(), @DriveCursorMovement(), @DriveMultiTouchHitting(), 
   @DriveMultiTouchMovement() and @DriveKeyboardHitting() are for the integration 
   purpose with the underlaying target system. You will never need to invoke these 
   methods from the GUI application. But if you are responsible for the integration 
   of the GUI application with your target system, you may need to feed these methods 
   with events from your touch screen or hardware keyboard.
   - The properties @Language and @Styles reflect the currently selected language 
   and the active styles. These may determine the visual aspect of the GUI application. 
   The properties cover the underlaying Chora variables 'language' and 'styles' 
   and broadcast Core::LanguageEvent or Core::StylesEvent in case of their modification. */
EW_DEFINE_FIELDS( CoreRoot, CoreGroup )
  EW_VARIABLE( keyLastTarget,   XObject )
  EW_ARRAY   ( cursorTargetView, CoreView, [10])
  EW_VARIABLE( canvas,          GraphicsCanvas )
  EW_OBJECT  ( cursorHoldTimer, CoreTimer )
  EW_VARIABLE( updateLock,      XInt32 )
  EW_VARIABLE( currentEventTimestamp, XUInt32 )
  EW_ARRAY   ( cursorSequelCounter, XInt32, [10])
  EW_ARRAY   ( cursorSequelArea, XRect, [10])
  EW_ARRAY   ( cursorHoldPeriod, XInt32, [10])
  EW_ARRAY   ( cursorHittingPos, XPoint, [10])
  EW_ARRAY   ( cursorHittingTime, XUInt32, [10])
  EW_ARRAY   ( cursorCurrentPos, XPoint, [10])
  EW_ARRAY   ( cursorHitOffset, XPoint, [10])
  EW_ARRAY   ( cursorLastPos,   XPoint, [10])
  EW_ARRAY   ( cursorFirstPos,  XPoint, [10])
  EW_VARIABLE( cursorFinger,    XInt32 )
  EW_VARIABLE( fpsTime,         XUInt32 )
  EW_VARIABLE( fpsCounter,      XInt32 )
  EW_ARRAY   ( lastRegions,     XRect, [3])
  EW_VARIABLE( noOfLastRegions, XInt32 )
  EW_ARRAY   ( regionsArea,     XInt32, [4])
  EW_ARRAY   ( regions,         XRect, [4])
  EW_VARIABLE( noOfRegions,     XInt32 )
  EW_VARIABLE( keyLastCode,     XEnum )
  EW_VARIABLE( keyLastCharCode, XChar )
  EW_VARIABLE( hasRootFocus,    XBool )
EW_END_OF_FIELDS( CoreRoot )

/* Virtual Method Table (VMT) for the class : 'Core::Root' */
EW_DEFINE_METHODS( CoreRoot, CoreGroup )
  EW_METHOD( initLayoutContext, void )( CoreRectView _this, XRect aBounds, CoreOutline 
    aOutline )

  /* The method GetRoot() delivers the application object, this view belongs to. 
     The application object represents the entire screen of the GUI application. 
     Thus in the views hierarchy, the application object serves as the root view.
     This method can fail and return null if the view still doesn't belong to any 
     owner group. */
  EW_METHOD( GetRoot,           CoreRoot )( CoreRoot _this )
  EW_METHOD( Draw,              void )( CoreRoot _this, GraphicsCanvas aCanvas, 
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
  EW_METHOD( ChangeViewState,   void )( CoreRoot _this, XSet aSetState, XSet aClearState )
  EW_METHOD( OnSetBounds,       void )( CoreGroup _this, XRect value )
  EW_METHOD( OnSetFocus,        void )( CoreRoot _this, CoreView value )
  EW_METHOD( OnSetOpacity,      void )( CoreRoot _this, XInt32 value )

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
  EW_METHOD( IsCurrentDialog,   XBool )( CoreRoot _this )

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
  EW_METHOD( IsActiveDialog,    XBool )( CoreRoot _this, XBool aRecursive )

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
  EW_METHOD( DispatchEvent,     XObject )( CoreRoot _this, CoreEvent aEvent )

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
  EW_METHOD( BroadcastEvent,    XObject )( CoreRoot _this, CoreEvent aEvent, XSet 
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
  EW_METHOD( UpdateViewState,   void )( CoreGroup _this, XSet aState )

  /* The method InvalidateArea() declares the given area of the component as invalid, 
     this means this area should be redrawn at the next screen update. */
  EW_METHOD( InvalidateArea,    void )( CoreRoot _this, XRect aArea )
EW_END_OF_METHODS( CoreRoot )

/* The method GetRoot() delivers the application object, this view belongs to. The 
   application object represents the entire screen of the GUI application. Thus 
   in the views hierarchy, the application object serves as the root view.
   This method can fail and return null if the view still doesn't belong to any 
   owner group. */
CoreRoot CoreRoot_GetRoot( CoreRoot _this );

/* 'C' function for method : 'Core::Root.Draw()' */
void CoreRoot_Draw( CoreRoot _this, GraphicsCanvas aCanvas, XRect aClip, XPoint 
  aOffset, XInt32 aOpacity, XBool aBlend );

/* The method ChangeViewState() modifies the current state of the view. The state 
   is a set of switches determining whether a view is visible, whether it can react 
   to user inputs or whether it is just performing some update operations, etc.
   The modification is controlled by the the both parameters. The first aSetState 
   contains the switches to activate within the view state. The second aClearState 
   determines all switches to disable.
   Depending on the state alteration the method will perform different operations, 
   e.g. in response to the clearing of the visible state, the method will request 
   a screen redraw to make disappear the view from the screen.
   ChangeViewState() is invoked automatically by the framework, so you never should 
   need to invoke it directly. All relevant states are available as properties e.g. 
   the property Visible in derived classes reflects the visible state of the view. */
void CoreRoot_ChangeViewState( CoreRoot _this, XSet aSetState, XSet aClearState );

/* 'C' function for method : 'Core::Root.OnSetFocus()' */
void CoreRoot_OnSetFocus( CoreRoot _this, CoreView value );

/* 'C' function for method : 'Core::Root.OnSetOpacity()' */
void CoreRoot_OnSetOpacity( CoreRoot _this, XInt32 value );

/* The method IsCurrentDialog() returns 'true' if 'this' component and all of its 
   owners do actually act as active dialogs (see the method @IsActiveDialog()) and 
   there are no further subordinated dialogs existing in context of 'this' component. 
   In other words, 'this' component is absolutely the top-most dialog of all dialogs 
   shown actually in the GUI application, so all user interactions are primarily 
   directed to 'this' dialog.
   If the component has not been presented, it has been dismissed, other dialog 
   has been presented in meantime overlying 'this' component, the owner of the component 
   is not itself an active dialog, or there is other dialog presented in context 
   of 'this' component, the method returns 'false'. */
XBool CoreRoot_IsCurrentDialog( CoreRoot _this );

/* The method IsActiveDialog() returns 'true' if 'this' component does actually 
   act as a dialog (see the method @IsDialog()) and it is the current (top-most) 
   dialog in context of its owner component. If the parameter aRecursive is 'true', 
   the owner in context of which 'this' component actually exists and all superior 
   owners have also to be active dialogs or the owner has to be the application 
   root component.
   If the component is not a dialog, or other dialog has been presented in the meantime 
   overlying 'this' component, the method returns 'false'. Similarly, if the parameter 
   aRecursive is 'true' and the owner of the component is itself not an active dialog, 
   the method returns 'false'. */
XBool CoreRoot_IsActiveDialog( CoreRoot _this, XBool aRecursive );

/* The method DispatchEvent() feeds the component with the event passed in the parameter 
   aEvent and propagates it along the so-called focus path. This focus path leads 
   to the currently selected keyboard event receiver view. If the event is rejected 
   by the view, the same operation is repeated for the next superior view. This 
   permits the hierarchical event dispatching until a willing view has handled the 
   event or all views in the focus path have been evaluated. If the event remains 
   still unhandled, it will be passed to the component itself.
   The focus path is established by the property @Focus. 
   DispatchEvent() returns the value returned by the @HandleEvent() method of the 
   view which has handled the event. In the case, the event was not handled, the 
   method returns 'null'. */
XObject CoreRoot_DispatchEvent( CoreRoot _this, CoreEvent aEvent );

/* The method BroadcastEvent() feeds the component with the event passed in the 
   parameter aEvent and propagates it to all views enclosed within the component 
   until the event has been handled or all views are evaluated. If the event remains 
   still unhandled, it will be passed to the component itself.
   The additional parameter aFilter can be used to limit the operation to special 
   views only, e.g. to visible and touchable views. To broadcast the event to all 
   views pass in the parameter aFilter the value 'Core::ViewState[]'.
   BroadcastEvent() is very useful to provide all views with one and the same event 
   in order e.g. to inform all views about an important global state alteration. 
   To send events to views enclosing a given position use the method @BroadcastEventAtPosition().
   BroadcastEvent() returns the value returned by the @HandleEvent() method of the 
   view which has handled the event. In the case, the event was not handled, the 
   method returns 'null'. */
XObject CoreRoot_BroadcastEvent( CoreRoot _this, CoreEvent aEvent, XSet aFilter );

/* The method InvalidateArea() declares the given area of the component as invalid, 
   this means this area should be redrawn at the next screen update. */
void CoreRoot_InvalidateArea( CoreRoot _this, XRect aArea );

/* 'C' function for method : 'Core::Root.createDragEvent()' */
CoreDragEvent CoreRoot_createDragEvent( CoreRoot _this );

/* 'C' function for method : 'Core::Root.createCursorEvent()' */
CoreCursorEvent CoreRoot_createCursorEvent( CoreRoot _this );

/* 'C' function for method : 'Core::Root.createCursorGrabEvent()' */
CoreCursorGrabEvent CoreRoot_createCursorGrabEvent( CoreRoot _this );

/* 'C' function for method : 'Core::Root.cursorHoldTimerProc()' */
void CoreRoot_cursorHoldTimerProc( CoreRoot _this, XObject sender );

/* The method GetFPS() returns the screen update performance expressed in frames 
   per second. The performance is estimated for the period between the current and 
   the preceding invocation of the GetFPS() method. */
XInt32 CoreRoot_GetFPS( CoreRoot _this );

/* Wrapper function for the non virtual method : 'Core::Root.GetFPS()' */
XInt32 CoreRoot__GetFPS( void* _this );

/* The following define announces the presence of the method Core::Root.GetFPS(). */
#define _CoreRoot__GetFPS_

/* The method Update() exists for the integration purpose with the underlying target 
   system. You will never need to invoke this method directly from your GUI application. 
   The method is responsible for the redrawing of invalid screen areas.
   This method forces the redraw of all affected views and returns the position 
   and the size of the redrawn area. If there is no invalid area to redraw, */
XRect CoreRoot_Update( CoreRoot _this );

/* Wrapper function for the non virtual method : 'Core::Root.Update()' */
XRect CoreRoot__Update( void* _this );

/* The following define announces the presence of the method Core::Root.Update(). */
#define _CoreRoot__Update_

/* The method UpdateGE20() exists for the integration purpose with the underlying 
   target system. You will never need to invoke this method directly from your GUI 
   application. The method is responsible for the redrawing of invalid screen areas.
   This method forces the redraw of all affected views into the given drawing destination 
   aCanvas and returns the position and the size of the redrawn area. If there is 
   no invalid area to redraw, UpdateGE20() returns an empty rectangle. This method 
   is intended to work with the new Graphics Engine 2.0 only. */
XRect CoreRoot_UpdateGE20( CoreRoot _this, GraphicsCanvas aCanvas );

/* Wrapper function for the non virtual method : 'Core::Root.UpdateGE20()' */
XRect CoreRoot__UpdateGE20( void* _this, GraphicsCanvas aCanvas );

/* The following define announces the presence of the method Core::Root.UpdateGE20(). */
#define _CoreRoot__UpdateGE20_

/* The method EndUpdate() belongs to an interface required for integration purpose 
   with the underlying target system. You will never need to invoke this method 
   directly from your GUI application.
   Calling this method finalizes the screen update cycle initiated by the preceding 
   @BeginUpdate() invocation. */
void CoreRoot_EndUpdate( CoreRoot _this );

/* Wrapper function for the non virtual method : 'Core::Root.EndUpdate()' */
void CoreRoot__EndUpdate( void* _this );

/* The following define announces the presence of the method Core::Root.EndUpdate(). */
#define _CoreRoot__EndUpdate_

/* The method UpdateCanvas() belongs to an interface required for integration purpose 
   with the underlying target system. You will never need to invoke this method 
   directly from your GUI application.
   This method redraws all invalid screen regions into the canvas passed in the 
   parameter aCanvas. The parameter aOffset determines the origin where to map the 
   top-left corner of the canvas on the screen. All update areas lying outside the 
   canvas are clipped.
   The method returns the position and the size of the resulting area within the 
   canvas affected by the update. If there is no intersection between the canvas 
   and any of the invalid areas, UpdateCanvas() returns an empty rectangle. */
XRect CoreRoot_UpdateCanvas( CoreRoot _this, GraphicsCanvas aCanvas, XPoint aOffset );

/* Wrapper function for the non virtual method : 'Core::Root.UpdateCanvas()' */
XRect CoreRoot__UpdateCanvas( void* _this, GraphicsCanvas aCanvas, XPoint aOffset );

/* The following define announces the presence of the method Core::Root.UpdateCanvas(). */
#define _CoreRoot__UpdateCanvas_

/* The method GetUpdateRegion() belongs to an interface required for integration 
   purpose with the underlying target system. You will never need to invoke this 
   method directly from your GUI application.
   This method returns the position and the size of the invalid region with the 
   number specified in the parameter aRegionNo. If the desired region does not exist, 
   the method returns an empty area. */
XRect CoreRoot_GetUpdateRegion( CoreRoot _this, XInt32 aRegionNo );

/* Wrapper function for the non virtual method : 'Core::Root.GetUpdateRegion()' */
XRect CoreRoot__GetUpdateRegion( void* _this, XInt32 aRegionNo );

/* The following define announces the presence of the method Core::Root.GetUpdateRegion(). */
#define _CoreRoot__GetUpdateRegion_

/* The method BeginUpdate() belongs to an interface required for integration purpose 
   with the underlying target system. You will never need to invoke this method 
   directly from your GUI application.
   Calling this method initiates a new screen update cycle. Subsequently the method 
   @UpdateCanvas() can be called in order to perform all waiting drawing operations. 
   If necessary UpdateCanvas() can be called multiple times in order to draw multiple 
   screen areas individually. Finally the update cycle is terminated by calling 
   the method @EndUpdate().
   The method BeginUpdate() returns the number of invalid regions waiting currently 
   for the update. If there is nothing to update, the method returns 0 (zero). The 
   position and the size of the invalid regions can be queried by using the method 
   @GetUpdateRegion(). */
XInt32 CoreRoot_BeginUpdate( CoreRoot _this );

/* Wrapper function for the non virtual method : 'Core::Root.BeginUpdate()' */
XInt32 CoreRoot__BeginUpdate( void* _this );

/* The following define announces the presence of the method Core::Root.BeginUpdate(). */
#define _CoreRoot__BeginUpdate_

/* The method DoesNeedUpdate() returns a value indicating whether an area of the 
   application needs an update. If there is no invalid area to redraw, DoesNeedUpdate() 
   returns 'false'. */
XBool CoreRoot_DoesNeedUpdate( CoreRoot _this );

/* Wrapper function for the non virtual method : 'Core::Root.DoesNeedUpdate()' */
XBool CoreRoot__DoesNeedUpdate( void* _this );

/* The following define announces the presence of the method Core::Root.DoesNeedUpdate(). */
#define _CoreRoot__DoesNeedUpdate_

/* The method Initialize() exists for the integration purpose with the underlying 
   target system. You will never need to invoke this method directly from your GUI 
   application. The method is responsible for the preparation of the application 
   object to work with a screen with the given size aSize. */
CoreRoot CoreRoot_Initialize( CoreRoot _this, XPoint aSize );

/* Wrapper function for the non virtual method : 'Core::Root.Initialize()' */
CoreRoot CoreRoot__Initialize( void* _this, XPoint aSize );

/* The following define announces the presence of the method Core::Root.Initialize(). */
#define _CoreRoot__Initialize_

/* 'C' function for method : 'Core::Root.SetRootFocus()' */
XBool CoreRoot_SetRootFocus( CoreRoot _this, XBool aHasRootFocus );

/* Wrapper function for the non virtual method : 'Core::Root.SetRootFocus()' */
XBool CoreRoot__SetRootFocus( void* _this, XBool aHasRootFocus );

/* The following define announces the presence of the method Core::Root.SetRootFocus(). */
#define _CoreRoot__SetRootFocus_

/* The method 'SetUserInputTimestamp()' exists for optional purpose to provide the 
   exact timestamp when the last user interaction took place. With this exact information 
   the GUI application can calculate better interactions like touch screen gestures, 
   etc. The time is expressed in milliseconds.
   Usually the method will be invoked in response to user input events received 
   in the main() message loop from the target specific keyboard or touch screen 
   driver. The method should be called before the event is fed to the GUI system. */
void CoreRoot_SetUserInputTimestamp( CoreRoot _this, XUInt32 aTimestamp );

/* Wrapper function for the non virtual method : 'Core::Root.SetUserInputTimestamp()' */
void CoreRoot__SetUserInputTimestamp( void* _this, XUInt32 aTimestamp );

/* The following define announces the presence of the method Core::Root.SetUserInputTimestamp(). */
#define _CoreRoot__SetUserInputTimestamp_

/* The method DriveKeyboardHitting() exists for the integration purpose with the 
   underlying target system. Usually the method will be invoked in response to events 
   received in the main() message loop from the target specific hardware keyboard 
   driver.
   The parameters passed to the method determine the event. aDown determines whether 
   the user has pressed (== 'true') or released (== 'false') a key. The parameters 
   aCode and aCharCode are used exclusively. They determine the affected key. If 
   the method is called with a valid aCode then aCharCode should be '\0'. If the 
   method is called with a valid aCharCode then aCode should be Core::KeyCode.NoKey. */
XBool CoreRoot_DriveKeyboardHitting( CoreRoot _this, XEnum aCode, XChar aCharCode, 
  XBool aDown );

/* Wrapper function for the non virtual method : 'Core::Root.DriveKeyboardHitting()' */
XBool CoreRoot__DriveKeyboardHitting( void* _this, XEnum aCode, XChar aCharCode, 
  XBool aDown );

/* The following define announces the presence of the method Core::Root.DriveKeyboardHitting(). */
#define _CoreRoot__DriveKeyboardHitting_

/* The method DriveCursorMovement() exists for the integration purpose with the 
   underlying target system. Usually the method will be invoked in response to to 
   drag events received in the main() message loop from the target specific touch 
   screen driver.
   The method expects only one parameter aPos. This parameter determines the current 
   cursor (or finger in the touch screen analogy) position. aPos lies relative to 
   the top-left corner of the application coordinate system.
   Please note, this method is limited to process a single touch (or mouse) event 
   at the same time. When integrating with a target system supporting multi-touch 
   please use the method @DriveMultiTouchMovement(). */
XBool CoreRoot_DriveCursorMovement( CoreRoot _this, XPoint aPos );

/* Wrapper function for the non virtual method : 'Core::Root.DriveCursorMovement()' */
XBool CoreRoot__DriveCursorMovement( void* _this, XPoint aPos );

/* The following define announces the presence of the method Core::Root.DriveCursorMovement(). */
#define _CoreRoot__DriveCursorMovement_

/* The method DriveMultiTouchMovement() exists for the integration purpose with 
   the underlying target system. Usually the method will be invoked in response 
   to to drag events received in the main() message loop from the target specific 
   touch screen driver.
   The parameter aPos determines the current cursor (or finger in the touch screen 
   analogy) position. aPos lies relative to the top-left corner of the application 
   coordinate system. The number of the finger is specified in the parameter aFinger. 
   The first finger has the number 0, the second 1, and so far till 9.
   Please note, unlike the method @DriveCursorMovement() this method is able to 
   process and dispatch several multi-touch events simultaneously. */
XBool CoreRoot_DriveMultiTouchMovement( CoreRoot _this, XInt32 aFinger, XPoint aPos );

/* Wrapper function for the non virtual method : 'Core::Root.DriveMultiTouchMovement()' */
XBool CoreRoot__DriveMultiTouchMovement( void* _this, XInt32 aFinger, XPoint aPos );

/* The following define announces the presence of the method Core::Root.DriveMultiTouchMovement(). */
#define _CoreRoot__DriveMultiTouchMovement_

/* The method DriveCursorHitting() exists for the integration purpose with the underlying 
   target system. Usually the method will be invoked in response to to touch events 
   received in the main() message loop from the target specific touch screen driver.
   The parameters passed to the method determine the event. aDown determines whether 
   the user has pressed (== 'true') or released (== 'false') his finger at the position 
   aPos relative to the top-left origin of the GUI application area. The parameter 
   aFinger specifies the finger (or mouse button) the user pressed for this operation. 
   The first finger (mouse button) has the number 0, the second 1, and so far.
   Please note, this method is limited to process a single touch (or mouse) event 
   at the same time. When integrating with a target system supporting multi-touch 
   please use the method @DriveMultiTouchHitting(). */
XBool CoreRoot_DriveCursorHitting( CoreRoot _this, XBool aDown, XInt32 aFinger, 
  XPoint aPos );

/* Wrapper function for the non virtual method : 'Core::Root.DriveCursorHitting()' */
XBool CoreRoot__DriveCursorHitting( void* _this, XBool aDown, XInt32 aFinger, XPoint 
  aPos );

/* The following define announces the presence of the method Core::Root.DriveCursorHitting(). */
#define _CoreRoot__DriveCursorHitting_

/* The method DriveMultiTouchHitting() exists for the integration purpose with the 
   underlying target system. Usually the method will be invoked in response to touch 
   events received in the main() message loop from the target specific touch screen 
   driver.
   The parameters passed to the method determine the event. aDown determines whether 
   the user has pressed (== 'true') or released (== 'false') his finger at the position 
   aPos relative to the top-left origin of the GUI application area. The parameter 
   aFinger identifies the associated finger. The first finger has the number 0, 
   the second 1 and so far till 9. 
   Please note, unlike the method @DriveCursorHitting() this method is able to process 
   and dispatch several multi-touch events simultaneously. */
XBool CoreRoot_DriveMultiTouchHitting( CoreRoot _this, XBool aDown, XInt32 aFinger, 
  XPoint aPos );

/* Wrapper function for the non virtual method : 'Core::Root.DriveMultiTouchHitting()' */
XBool CoreRoot__DriveMultiTouchHitting( void* _this, XBool aDown, XInt32 aFinger, 
  XPoint aPos );

/* The following define announces the presence of the method Core::Root.DriveMultiTouchHitting(). */
#define _CoreRoot__DriveMultiTouchHitting_

/* The method RetargetCursorWithReason() changes the currently active cursor event 
   target view. Usually, the target view is determined when the user presses the 
   finger on the touch screen. Once determined, the target view remains active until 
   the user has released the finger. In the meantime the framework will provide 
   this target view with all cursor events. This entire cycle is called 'grab cycle'. 
   The method RetargetCursorWithReason() allows you to select a new target view 
   without the necessity to wait until the user has released the touch screen and 
   thus has finalized the grab cycle.
   Except the additional parameter aRetargetReason, this method works similarly 
   to @RetargetCursor(). At first the method asks the new potential target view 
   aNewTarget whether it or one of its sub-views is willing to continue processing 
   the cursor events for the gesture specified in aRetargetReason. If successful, 
   the method hands over the cursor event flow to this determined view. If there 
   is no view willing to handle these events, the method hands over the event flow 
   directly to the view specified in the parameter aFallbackTarget. If no willing 
   view could be found and no fall-back view was given, the current grab cycle is 
   finalized as if the user had released the touch screen.
   Unlike the method @DeflectCursor() this RetargetCursorWithReason() method performs 
   the cursor hit test for all views of the new potential target. This is as if 
   the user had tapped the screen and the framework tries to determine the view 
   affected by this interaction. This search operation is limited to views at the 
   current cursor position. Unlike @RetargetCursor(), this method limits additionally 
   to candidates willing to handle the gesture specified in the parameter aRetargetReason.
   When switching the target view, the framework provides the old and the new target 
   views with cursor events. The old view will receive a Core::CursorEvent with 
   variables Down == 'false' and AutoDeflected == 'true' - this simulates the release 
   operations. The new target view will receive a Core::CursorEvent with the variable 
   Down == 'true' as if it had been just touched by the user.
   If the application is running within a multi-touch environment, the invocation 
   of the RetargetCursor() method does affect the event flow corresponding only 
   to the finger which has lastly generated touch events. */
void CoreRoot_RetargetCursorWithReason( CoreRoot _this, CoreView aNewTarget, CoreView 
  aFallbackTarget, XSet aRetargetReason );

/* The method DeflectCursor() changes the currently active cursor event target view. 
   Usually, the target view is determined when the user presses the finger on the 
   touch screen. Once determined, the target view remains active until the user 
   has released the finger. In the meantime the framework will provide this target 
   view with all cursor events. This entire cycle is called 'grab cycle'. The method 
   DeflectCursor() allows you to select a new target view without the necessity 
   to wait until the user has released the touch screen and thus has finalized the 
   grab cycle.
   Unlike the method @RetargetCursor() this @DeflectCursor() method hands over the 
   cursor event flow to the new target regardless its position or state. If no new 
   target view has been specified, the current grab cycle is finalized as if the 
   user had released the touch screen.
   When switching the target view, the framework provides the old and the new target 
   views with cursor events. The old view will receive a Core::CursorEvent with 
   variables Down == 'false' and AutoDeflected == 'true' - this simulates the release 
   operations. The new target view will receive a Core::CursorEvent with the variable 
   Down == 'true' as if it had been just touched by the user.
   If the application is running within a multi-touch environment, the invocation 
   of the DeflectCursor() method does affect the event flow corresponding only to 
   the finger which has lastly generated touch events. */
void CoreRoot_DeflectCursor( CoreRoot _this, CoreView aNewTarget, XPoint aHitOffset );

#ifdef __cplusplus
  }
#endif

#endif /* _CoreRoot_H */

/* Embedded Wizard */
