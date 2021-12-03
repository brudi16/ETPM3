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

#ifndef _ViewsText_H
#define _ViewsText_H

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

/* Forward declaration of the class Resources::Font */
#ifndef _ResourcesFont_
  EW_DECLARE_CLASS( ResourcesFont )
#define _ResourcesFont_
#endif

/* Forward declaration of the class Views::Text */
#ifndef _ViewsText_
  EW_DECLARE_CLASS( ViewsText )
#define _ViewsText_
#endif


/* The class Views::Text provides a kind of view specialized to print the text. 
   The text is stored in the property @String. It can consist of several rows separated 
   by the new-line sign '\\n'. Optionally an automatic text wrap ca be performed 
   if the property @WrapText is 'true'. The automatic text wrap takes place primarily 
   between words. More sophisticated text wrap can be controlled by following special 
   signs used within the text:
   - The tilde sign '~' and the soft-hyphen sign '\x00AD' identify a potential text 
   wrap position. They are usually not displayed until the text wrap took place 
   at their position. Then the text row is terminated with a hyphen '-' sign.
   - The circumflex accent '^' sign and '\x200B' zero-width non breakable space 
   identify potential text wrap positions without ever being visible.
   In order to be able to output the special characters '^' and '~' and as regular 
   signs, the character '%' can be applied in front of the affected sign to convert 
   it to a regular sign. To show the '%' sign itself, use '%%' sequence.
   Beside the automatic text wrap, an explicit linefeed is possible when the '\n' 
   sign has been found in the string.
   The text output is performed with the font specified in the property @Font. The 
   position and the size of the area where the text is drawn is determined by the 
   property @Bounds. If the size of this area differs from the size of the text, 
   the text can be aligned. This is controlled by the property @Alignment. With 
   the property @Orientation the displayed content can be rotated. The color to 
   print the text is defined by the property @Color. Alternatively, the text can 
   be drawn with a color gradient specified by the properties @ColorTL, @ColorTR, 
   @ColorBL and @ColorBR. For each view's corner different color can be set.
   The property @SlideHandler permits the text view to be connected together with 
   an interactive Core::SlideTouchHandler. In this manner the user can scroll the 
   displayed text by simply touching the slide handler on the screen. Alternatively, 
   the scroll position can be controlled by the value of the property @ScrollOffset.
   The visibility of the text is controlled by the properties @Visible and @Embedded. 
   In particular the property @Embedded can determine whether the corresponding 
   view is limited (== embedded) to the boundary of a sibling Core::Outline view 
   or not. The embedding of views within a Core::Outline allows a kind of sub-groups 
   within the GUI component itself. Very useful for any kind of scrollable lists, 
   menus, etc.
   With the property @EnableBidiText the view can be configured to treat the original 
   string @String as containing bi-directional text. In such case, the string is 
   processed by the Unicode Bidirectional Algorithm. If the text contains Arabic 
   characters, the algorithm performs the shaping and determines the obligatory 
   Arabic ligatures. With the method @IsBidiText(), @IsBaseDirectionRTL() and @IsCharDirectionRTL() 
   the resulting state of the processed text can be determined.
   The text provides an additional set of methods useful to access the text rows 
   and glyphs, e.g. @GetNoOfRows(), @GetRowArea(), @RowCol2Position(), @RowCol2StringIndex(), 
   @StringIndex2RowCol(), etc. These methods can be invoked from a slot method assigned 
   to the property @OnUpdate. In this manner text position can be calculated or 
   additional decorations can be drawn. */
EW_DEFINE_FIELDS( ViewsText, CoreRectView )
  /* The property 'Font' refers to the font object used to print the text. The text 
     is determined by the property @String. */
  EW_PROPERTY( Font,            ResourcesFont )

  /* The property 'OnUpdate' can refer to a slot method, which should be invoked 
     by the view after the displayed @String or the position of the view have been 
     changed. This method is intended to update decorations, like the position of 
     a blinking caret in a text editor, etc. For this purpose methods @GetContentArea(), 
     @GetRowArea(), @RowCol2Position(), @Position2RowCol(), @GetNoOfRows(), @GetRowString(), 
     @RowCol2StringIndex() can be used. It's up to you to provide the slot method 
     and to fill it with the desired behavior. */
  EW_PROPERTY( OnUpdate,        XSlot )
  EW_VARIABLE( flowString,      XString )

  /* The property 'String' stores the text to print in this view. The corresponding 
     font is determined by the property @Font. The text can consist of several rows 
     separated by the new-line sign '\n'. Optionally an automatic text wrap can 
     be performed if the property @WrapText is 'true'. The automatic text wrap takes 
     place primarily between words. More sophisticated text wrap can be controlled 
     by following special signs used within the text:
     - The tilde sign '~' and the soft-hyphen sign '\x00AD' identify a potential 
     text wrap position. They are usually not displayed until the text wrap took 
     place at their position. Then the text row is terminated with a hyphen '-' 
     sign.
     - The circumflex accent '^' sign identifies a potential text wrap position 
     without ever being visible.
     In order to be able to output the special characters '^', '~' and '\x00AD' 
     as regular signs, the character '%' can be applied in front of the affected 
     sign to convert it to a regular sign. To show the '%' sign itself, use '%%' 
     sequence. */
  EW_PROPERTY( String,          XString )
  EW_VARIABLE( bidiContext,     XHandle )
  EW_VARIABLE( textSize,        XPoint )

  /* The property 'Alignment' determines how the view should display the text rows 
     if their size differ from the size of the view. In this manner the rows can 
     be aligned horizontally. The entire text block can be aligned vertically.
     Please note, the orientation of the area in context of which the text is aligned 
     is affected by the property @Orientation. For example, if the view is configured 
     to rotate the text 90 degrees counter-clockwise and to align it to the left 
     edge, all text rows will be arranged consequently at the bottom edge of the 
     view. */
  EW_PROPERTY( Alignment,       XSet )

  /* The property 'Color' controls the color of the entire view. Thus this property 
     is useful if no gradients are desired. The resulting colors can additionally 
     be modulated by the values specified in the properties @ColorTL, @ColorTR, 
     @ColorBL and @ColorBR. */
  EW_PROPERTY( Color,           XColor )

  /* The property 'WrapText' determines whether long text rows should be wrapped 
     automatically. If this property is 'true', the view will wrap the text rows 
     which are longer than the value resulting from the property @WrapWidth. */
  EW_PROPERTY( WrapText,        XBool )

  /* The property 'Ellipsis' determines whether leading and/or closing characters 
     of the string @String should be replaced with ellipsis '...', if necessary, 
     so that the result fits in the specified @Bounds area. */
  EW_PROPERTY( Ellipsis,        XBool )

  /* The property 'EnableBidiText' controls how the Text view should handle strings 
     containing bidirectional or right-to-left (e.g. Arabic) contents. If this property 
     is 'true', the Text view applies the 'Unicode Bidirectional Algoritm' on the 
     specified string. This includes the shaping of Arabic glyphs and building of 
     Arabic mandatory ligatures. If this property is 'false', none of the here described 
     steps is applied - the Text view displays the string as it is. */
  EW_PROPERTY( EnableBidiText,  XBool )
  EW_VARIABLE( reparsed,        XBool )
EW_END_OF_FIELDS( ViewsText )

/* Virtual Method Table (VMT) for the class : 'Views::Text' */
EW_DEFINE_METHODS( ViewsText, CoreRectView )
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
  EW_METHOD( Draw,              void )( ViewsText _this, GraphicsCanvas aCanvas, 
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
  EW_METHOD( OnSetBounds,       void )( ViewsText _this, XRect value )
EW_END_OF_METHODS( ViewsText )

/* 'C' function for method : 'Views::Text.Done()' */
void ViewsText_Done( ViewsText _this );

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
void ViewsText_Draw( ViewsText _this, GraphicsCanvas aCanvas, XRect aClip, XPoint 
  aOffset, XInt32 aOpacity, XBool aBlend );

/* 'C' function for method : 'Views::Text.OnSetBounds()' */
void ViewsText_OnSetBounds( ViewsText _this, XRect value );

/* 'C' function for method : 'Views::Text.freeBidi()' */
void ViewsText_freeBidi( ViewsText _this, XHandle aBidi );

/* 'C' function for method : 'Views::Text.createBidi()' */
XHandle ViewsText_createBidi( ViewsText _this, XInt32 aSize );

/* 'C' function for method : 'Views::Text.preOnUpdateSlot()' */
void ViewsText_preOnUpdateSlot( ViewsText _this, XObject sender );

/* 'C' function for method : 'Views::Text.preReparseSlot()' */
void ViewsText_preReparseSlot( ViewsText _this, XObject sender );

/* 'C' function for method : 'Views::Text.reparseSlot()' */
void ViewsText_reparseSlot( ViewsText _this, XObject sender );

/* 'C' function for method : 'Views::Text.OnSetEnableBidiText()' */
void ViewsText_OnSetEnableBidiText( ViewsText _this, XBool value );

/* The onset method for the property 'Ellipsis' changes the ellipsis mode and forces 
   an update. */
void ViewsText_OnSetEllipsis( ViewsText _this, XBool value );

/* 'C' function for method : 'Views::Text.OnSetOnUpdate()' */
void ViewsText_OnSetOnUpdate( ViewsText _this, XSlot value );

/* 'C' function for method : 'Views::Text.OnSetWrapText()' */
void ViewsText_OnSetWrapText( ViewsText _this, XBool value );

/* 'C' function for method : 'Views::Text.OnSetAlignment()' */
void ViewsText_OnSetAlignment( ViewsText _this, XSet value );

/* 'C' function for method : 'Views::Text.OnSetString()' */
void ViewsText_OnSetString( ViewsText _this, XString value );

/* 'C' function for method : 'Views::Text.OnSetFont()' */
void ViewsText_OnSetFont( ViewsText _this, ResourcesFont value );

/* 'C' function for method : 'Views::Text.OnSetColor()' */
void ViewsText_OnSetColor( ViewsText _this, XColor value );

/* The method IsBaseDirectionRTL() returns 'true' if the text specified in @String 
   starts with an RTL (right-to-left) character. This implies the base direction 
   of the entire text paragraph. If the text starts with an LTR (left-to-right) 
   sign or the property @EnableBidiText is 'false', this method returns 'false'. */
XBool ViewsText_IsBaseDirectionRTL( ViewsText _this );

/* The method IsBidiText() returns 'true' if the text specified in the property 
   @String contains any right-to-left contents or any other Bidi algorithm specific 
   control codes requiring the Bidi processing of this text. Please note, if the 
   property @EnableBidiText is false, the text is not processed by the Bidi algorithm 
   and this method returns 'false'. */
XBool ViewsText_IsBidiText( ViewsText _this );

/* The method GetContentArea() returns the position and the size of an area where 
   the view will show the text. This area is expressed in coordinates relative to 
   the top-left corner of the view's @Owner. The method takes in account all properties 
   which do affect the position and the alignment of the text, e.g. @Alignment, 
   @Orientation, @ScrollOffset, @WrapText, etc. */
XRect ViewsText_GetContentArea( ViewsText _this );

#ifdef __cplusplus
  }
#endif

#endif /* _ViewsText_H */

/* Embedded Wizard */
