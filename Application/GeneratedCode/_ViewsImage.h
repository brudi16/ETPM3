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

#ifndef _ViewsImage_H
#define _ViewsImage_H

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

/* Forward declaration of the class Core::Timer */
#ifndef _CoreTimer_
  EW_DECLARE_CLASS( CoreTimer )
#define _CoreTimer_
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

/* Forward declaration of the class Resources::Bitmap */
#ifndef _ResourcesBitmap_
  EW_DECLARE_CLASS( ResourcesBitmap )
#define _ResourcesBitmap_
#endif

/* Forward declaration of the class Views::Image */
#ifndef _ViewsImage_
  EW_DECLARE_CLASS( ViewsImage )
#define _ViewsImage_
#endif


/* The class Views::Image provides a kind of view specialized to draw and animate 
   bitmaps. The bitmap is determined by the property @Bitmap. In case of a multi-frame 
   bitmap the desired frame can be selected by the property @FrameNumber. The animation 
   of bitmaps containing short video sequences is controlled by the properties @Animated 
   and @Endless. Alternatively, the animation can be controlled by sending signals 
   to the slot methods @StartAnimation and @StopAnimation.
   The position and the size of the area where the bitmap is drawn is determined 
   by the property @Bounds. If the size of this area differs from the size of the 
   bitmap the bitmap can be aligned or scaled within this area. This is controlled 
   by the property @Alignment. With the property @Orientation the displayed content 
   can be rotated. The properties @Color, @ColorTL, @ColorTR, @ColorBL and @ColorBR 
   can be used to tint the bitmap or to modulate its transparency. For each view's 
   corner different color can be set, so the bitmap can be shown with fancy color 
   or opacity gradients. The particular effect of the colors depends on the type 
   of the bitmap:
   - Alpha8 bitmaps will be tinted with the given colors due to the fact they don't 
   provide their own color information. This allows one and the same Alpha8 bitmap 
   to be drawn with different colors.
   - In case of Native, Index8 or RGB565 bitmaps the opacity of the bitmap is modulated 
   by the color's alpha value. The original RGB information stored in the bitmap 
   are not affected. This allows one and the same bitmap to be drawn with different 
   transparencies.
   The property @SlideHandler permits the image view to be connected together with 
   an interactive Core::SlideTouchHandler. In this manner the user can scroll the 
   displayed bitmap by simply touching the slide handler on the screen. Alternatively, 
   the scroll position can be controlled by the value of the property @ScrollOffset.
   The visibility of the image is controlled by the properties @Visible, @AlphaBlended, 
   @Opacity and @Embedded. In particular the property @Embedded can determine whether 
   the corresponding view is limited (== embedded) to the boundary of a sibling 
   Core::Outline view or not. The embedding of views within a Core::Outline allows 
   a kind of sub-groups within the GUI component itself. Very useful for any kind 
   of scrollable lists, menus, etc. */
EW_DEFINE_FIELDS( ViewsImage, CoreRectView )
  EW_VARIABLE( timer,           CoreTimer )

  /* The property 'Bitmap' refers to the bitmap object to display in this view. 
     If the bitmap consists of more than one frame, the desired frame number can 
     be determined by the property @FrameNumber. If the bitmap is animated, the 
     animation will start if the property @Animated is 'true'. */
  EW_PROPERTY( Bitmap,          ResourcesBitmap )
  EW_VARIABLE( startTime,       XUInt32 )
  EW_VARIABLE( animFrameNumber, XInt32 )

  /* The property 'Color' controls the color of the entire image. Thus this property 
     is useful if no gradients are desired. The resulting colors can additionally 
     be modulated by the values specified in the properties @ColorTL, @ColorTR, 
     @ColorBL and @ColorBR.
     The effect of this color value depends on the type of the bitmap specified 
     in the @Bitmap property:
     - Alpha8 bitmaps will be tinted with the given colors due to the fact they 
     don't provide their own color information. This allows one and the same Alpha8 
     bitmap to be drawn with different colors.
     - In case of Native, Index8 or RGB565 bitmaps the opacity of the bitmap is 
     modulated by the color's alpha value. The original RGB information stored in 
     the bitmap are not affected. This allows one and the same bitmap to be drawn 
     with different transparencies. */
  EW_PROPERTY( Color,           XColor )

  /* The property 'FrameNumber' determines the bitmap frame to display in this view. 
     Each bitmap consists of either one or more frames (images). The first frame 
     has the number 0, the second frame has the number 1, and so far. Bitmaps containing 
     more than one frame are called multi-frame bitmaps. See Resources::Bitmap.
     Changes of this property cause the view to switch the shown frame. If the desired 
     frame is not available in the bitmap, no bitmap is shown. Additionally, the 
     value stored in this property determines the frame to start an animation of 
     an animated bitmap. The animation is controlled by the property @Animated. */
  EW_PROPERTY( FrameNumber,     XInt32 )

  /* The property 'Animated' determines whether the view may play animated bitmaps. 
     Assigning the value 'true' to this property can cause the view to re-start 
     the animated bitmap with the frame specified in the property @FrameNumber. 
     The value 'false' in contrast stops the running animated bitmap at its current 
     position. The animation can also be controlled by sending signals to the slot 
     methods @StartAnimation and @StopAnimation. Animated bitmaps are a special 
     kind of bitmaps containing short video sequences. The animation can work with 
     an animated bitmap only. See Resources::Bitmap. */
  EW_PROPERTY( Animated,        XBool )

  /* The property 'AutoSize' determines whether @Bounds of the view should be adjusted 
     automatically in response to bitmap changes. If AutoSize is 'true', the view 
     will adapt its bounds area correspondingly to the size of a bitmap assigned 
     to the @Bitmap property. */
  EW_PROPERTY( AutoSize,        XBool )
EW_END_OF_FIELDS( ViewsImage )

/* Virtual Method Table (VMT) for the class : 'Views::Image' */
EW_DEFINE_METHODS( ViewsImage, CoreRectView )
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
  EW_METHOD( Draw,              void )( ViewsImage _this, GraphicsCanvas aCanvas, 
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
  EW_METHOD( OnSetBounds,       void )( CoreRectView _this, XRect value )
EW_END_OF_METHODS( ViewsImage )

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
void ViewsImage_Draw( ViewsImage _this, GraphicsCanvas aCanvas, XRect aClip, XPoint 
  aOffset, XInt32 aOpacity, XBool aBlend );

/* 'C' function for method : 'Views::Image.observerSlot()' */
void ViewsImage_observerSlot( ViewsImage _this, XObject sender );

/* 'C' function for method : 'Views::Image.timerSlot()' */
void ViewsImage_timerSlot( ViewsImage _this, XObject sender );

/* 'C' function for method : 'Views::Image.OnSetAutoSize()' */
void ViewsImage_OnSetAutoSize( ViewsImage _this, XBool value );

/* 'C' function for method : 'Views::Image.OnSetColor()' */
void ViewsImage_OnSetColor( ViewsImage _this, XColor value );

/* 'C' function for method : 'Views::Image.OnSetAnimated()' */
void ViewsImage_OnSetAnimated( ViewsImage _this, XBool value );

/* 'C' function for method : 'Views::Image.OnSetFrameNumber()' */
void ViewsImage_OnSetFrameNumber( ViewsImage _this, XInt32 value );

/* 'C' function for method : 'Views::Image.OnSetBitmap()' */
void ViewsImage_OnSetBitmap( ViewsImage _this, ResourcesBitmap value );

/* 'C' function for method : 'Views::Image.OnSetEmbedded()' */
void ViewsImage_OnSetEmbedded( ViewsImage _this, XBool value );

/* The method GetContentArea() returns the position and the size of an area where 
   the view will show the bitmap. This area is expressed in coordinates relative 
   to the top-left corner of the view's @Owner. The method takes in account all 
   properties which do affect the position and the alignment of the bitmap, e.g. 
   @Alignment or @ScrollOffset. */
XRect ViewsImage_GetContentArea( ViewsImage _this );

#ifdef __cplusplus
  }
#endif

#endif /* _ViewsImage_H */

/* Embedded Wizard */
