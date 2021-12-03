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

#ifndef _CoreOutline_H
#define _CoreOutline_H

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

#include "_CoreRectView.h"

/* Forward declaration of the class Core::Group */
#ifndef _CoreGroup_
  EW_DECLARE_CLASS( CoreGroup )
#define _CoreGroup_
#endif

/* Forward declaration of the class Core::LayoutContext */
#ifndef _CoreLayoutContext_
  EW_DECLARE_CLASS( CoreLayoutContext )
#define _CoreLayoutContext_
#endif

/* Forward declaration of the class Core::Outline */
#ifndef _CoreOutline_
  EW_DECLARE_CLASS( CoreOutline )
#define _CoreOutline_
#endif

/* Forward declaration of the class Core::View */
#ifndef _CoreView_
  EW_DECLARE_CLASS( CoreView )
#define _CoreView_
#endif

/* Forward declaration of the class Graphics::Canvas */
#ifndef _GraphicsCanvas_
  EW_DECLARE_CLASS( GraphicsCanvas )
#define _GraphicsCanvas_
#endif


/* The class Core::Outline provides a special kind of a view able to unite and control 
   its sibling views. It acts like a lightweight container for the views without 
   being the owner of them:
   - Outline can control only views lying in front of it (views with higher Z-order). 
   Furthermore the affected views have to be signed explicitly with the state 'Embedded'. 
   Views lying behind the outline or views not signed as embedded are ignored by 
   the outline - they are controlled by their @Owner.
   - Outline limits the visibility of the embedded views to its own boundary area. 
   In this manner the views are clipped at the outlines edges.
   - Moving the outline causes the embedded views to be moved accordingly. Together 
   with the outline the views behave like a single union.
   - The embedded views can be scrolled within the outline boundary area. The property 
   @ScrollOffset determines the desired displacement.
   - A Core::SlideTouchHandler can be attached to the outline so the user can scroll 
   the outline content interactively by touching the screen. The property @SlideHandler 
   allows it. 
   - If the size of the outline changes, all embedded views are automatically arranged 
   within the outline boundary accordingly to their @Layout properties.
   - The property @Formation allows more sophisticated arrangement of embedded views 
   in columns and rows. Even table-like grid is possible. It is useful to create 
   scrollable menus or lists. With the properties @SpaceHorz, @SpaceVert and @Space 
   the padding between the automatically arranged views is controlled.
   - To find and enumerate the embedded views, the methods like @FindNextView(), 
   @FindPrevView(), @FindViewAtPosition, @FindViewInDirection() or @GetViewAtIndex() 
   are available. 
   - The method @EnsureVisible() has the job to scroll the outline contents until 
   the given view is visible. The method @AdjustContent() in contrast tries to scroll 
   the outline so the entire outline area is filled with views. Usually this is 
   used after the outline size changes.
   The outline itself is invisible except the Embedded Wizard Composer, where all 
   outlines appear as semitransparent rectangles. This allows you to interact with 
   the outlines during the design time. */
EW_DEFINE_FIELDS( CoreOutline, CoreRectView )
EW_END_OF_FIELDS( CoreOutline )

/* Virtual Method Table (VMT) for the class : 'Core::Outline' */
EW_DEFINE_METHODS( CoreOutline, CoreRectView )
  EW_METHOD( initLayoutContext, void )( CoreRectView _this, XRect aBounds, CoreOutline 
    aOutline )

  /* The method GetRoot() delivers the application object, this view belongs to. 
     The application object represents the entire screen of the GUI application. 
     Thus in the views hierarchy, the application object serves as the root view.
     This method can fail and return null if the view still doesn't belong to any 
     owner group. */
  EW_METHOD( GetRoot,           CoreRoot )( CoreView _this )

  /* The method Draw() is invoked automatically if parts of the view should be redrawn 
     on the screen. This can occur when e.g. the view has been moved or the appearance 
     of the view has changed before.
     Draw() is invoked automatically by the framework, you never will need to invoke 
     this method directly. However you can request an invocation of this method 
     by calling the method InvalidateArea() of the views @Owner. Usually this is 
     also unnecessary unless you are developing your own view.
     The passed parameters determine the drawing destination aCanvas and the area 
     to redraw aClip in the coordinate space of the canvas. The parameter aOffset 
     contains the displacement between the origin of the views owner and the origin 
     of the canvas. You will need it to convert views coordinates into these of 
     the canvas.
     The parameter aOpacity contains the opacity descended from this view's @Owner. 
     It lies in range 0 .. 255. If the view implements its own 'Opacity', 'Color', 
     etc. properties, the Draw() method should calculate the resulting real opacity 
     by mixing the values of these properties with the one passed in aOpacity parameter.
     The parameter aBlend contains the blending mode descended from this view's 
     @Owner. It determines, whether the view should be drawn with alpha-blending 
     active or not. If aBlend is false, the outputs of the view should overwrite 
     the corresponding pixel in the drawing destination aCanvas. If aBlend is true, 
     the outputs should be mixed with the pixel already stored in aCanvas. For this 
     purpose all Graphics Engine functions provide a parameter to specify the mode 
     for the respective drawing operation. If the view implements its own 'Blend' 
     property, the Draw() method should calculate the resulting real blend mode 
     by using logical AND operation of the value of the property and the one passed 
     in aBlend parameter. */
  EW_METHOD( Draw,              void )( CoreOutline _this, GraphicsCanvas aCanvas, 
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
  EW_METHOD( CursorHitTest,     CoreCursorHit )( CoreView _this, XRect aArea, XInt32 
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
  EW_METHOD( ChangeViewState,   void )( CoreView _this, XSet aSetState, XSet aClearState )
  EW_METHOD( OnSetBounds,       void )( CoreOutline _this, XRect value )
EW_END_OF_METHODS( CoreOutline )

/* The method Draw() is invoked automatically if parts of the view should be redrawn 
   on the screen. This can occur when e.g. the view has been moved or the appearance 
   of the view has changed before.
   Draw() is invoked automatically by the framework, you never will need to invoke 
   this method directly. However you can request an invocation of this method by 
   calling the method InvalidateArea() of the views @Owner. Usually this is also 
   unnecessary unless you are developing your own view.
   The passed parameters determine the drawing destination aCanvas and the area 
   to redraw aClip in the coordinate space of the canvas. The parameter aOffset 
   contains the displacement between the origin of the views owner and the origin 
   of the canvas. You will need it to convert views coordinates into these of the 
   canvas.
   The parameter aOpacity contains the opacity descended from this view's @Owner. 
   It lies in range 0 .. 255. If the view implements its own 'Opacity', 'Color', 
   etc. properties, the Draw() method should calculate the resulting real opacity 
   by mixing the values of these properties with the one passed in aOpacity parameter.
   The parameter aBlend contains the blending mode descended from this view's @Owner. 
   It determines, whether the view should be drawn with alpha-blending active or 
   not. If aBlend is false, the outputs of the view should overwrite the corresponding 
   pixel in the drawing destination aCanvas. If aBlend is true, the outputs should 
   be mixed with the pixel already stored in aCanvas. For this purpose all Graphics 
   Engine functions provide a parameter to specify the mode for the respective drawing 
   operation. If the view implements its own 'Blend' property, the Draw() method 
   should calculate the resulting real blend mode by using logical AND operation 
   of the value of the property and the one passed in aBlend parameter. */
void CoreOutline_Draw( CoreOutline _this, GraphicsCanvas aCanvas, XRect aClip, XPoint 
  aOffset, XInt32 aOpacity, XBool aBlend );

/* 'C' function for method : 'Core::Outline.OnSetBounds()' */
void CoreOutline_OnSetBounds( CoreOutline _this, XRect value );

#ifdef __cplusplus
  }
#endif

#endif /* _CoreOutline_H */

/* Embedded Wizard */
