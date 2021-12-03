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

#ifndef Graphics_H
#define Graphics_H

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

#include "_GraphicsArcPath.h"
#include "_GraphicsCanvas.h"
#include "_GraphicsPath.h"
#include "_GraphicsWarpMatrix.h"

/* The definition Graphics::Edges enumerates the parts of a free scalable frame. 
   It is used to determine, which parts should be drawn. */
typedef enum
{

  /* The item 'Left' determines whether the left edge of the frame should be drawn. */
  GraphicsEdgesLeft                     = 0x00000001,

  /* The item 'Top' determines whether the top edge of the frame should be drawn. */
  GraphicsEdgesTop                      = 0x00000002,

  /* The item 'Right' determines whether the right edge of the frame should be drawn. */
  GraphicsEdgesRight                    = 0x00000004,

  /* The item 'Bottom' determines whether the bottom edge of the frame should be 
     drawn. */
  GraphicsEdgesBottom                   = 0x00000008,

  /* The item 'Interior' determines whether the interior area of the frame should 
     be drawn. */
  GraphicsEdgesInterior                 = 0x00000010
} GraphicsEdges;

/* The definition Graphics::FillRule enumerates the possible modes how complex polygons 
   consisting of nested paths are filled. It is used to determine how Views::FillPath 
   should fill the path. */
typedef enum
{

  /* Fills the path areas alternately depending on the nesting level of the closed 
     paths. An area is considered as filled if the number of path segments between 
     a point lying inside the area and any point outside the entire shape is odd. 
     If the number of path segments is even, the area is not filled. */
  GraphicsFillRuleEvenOdd               = 0,

  /* Fills the path areas depending on the nesting level of the closed paths and 
     their winding direction. An area is considered as filled when counting the 
     path segments between a point lying inside the area and any point outside the 
     entire shape the resulting value is not zero, whereby paths with positive winding 
     direction increment the value while paths with negative winding decrement it. 
     If the counter value is 0, the area is not filled. */
  GraphicsFillRuleNonZero               = 1
} GraphicsFillRule;

/* The definition Graphics::ArcStyle enumerates the possible shapes of an elliptical 
   arc. It is used to determine the mode how Graphics::ArcPath should calculate 
   the path data. */
typedef enum
{

  /* Simple elliptical arc. The both arc ends remain opened unless the angle of 
     the arc is equal to or greater than 360.0 degree. */
  GraphicsArcStyleArc                   = 0,

  /* Segment of an ellipse with the start and the end positions of the arc being 
     connected together by a straight line segment.
     If the arc forms a closed ellipse (the angle of the arc is equal to or greater 
     than 360.0 degree), no line segment is added. */
  GraphicsArcStyleSegment               = 1,

  /* Shape typical for displaying pie charts. Here the start and the end positions 
     of the arc are connected with the center of the ellipse by additional straight 
     line segments.
     If the arc forms a closed ellipse (the angle of the arc is equal to or greater 
     than 360.0 degree), no line segments are added as connections with the center 
     position. */
  GraphicsArcStylePie                   = 2,

  /* Shape typical for displaying circular bar diagrams with rounded start and end 
     edges. Here the start and the end positions of the arc are connected with the 
     center of the ellipse by additional semi-circles.
     If the arc forms a closed ellipse (the angle of the arc is equal to or greater 
     than 360.0 degree), no connections with the center position is added. */
  GraphicsArcStylePieRounded            = 3,

  /* Shape typical for displaying circular bar diagrams with rounded start edges. 
     Here the start position of the arc is connected with the center of the ellipse 
     by additional semi-circle. The end position, in turn, is connected by a straight 
     line segment.
     If the arc forms a closed ellipse (the angle of the arc is equal to or greater 
     than 360.0 degree), no connections with the center position is added. */
  GraphicsArcStylePieRoundedStart       = 4,

  /* Shape typical for displaying circular bar diagrams with rounded end edges. 
     Here the start position of the arc is connected with the center of the ellipse 
     by additional straight line segment. The end position, in turn, is connected 
     with the center by a semi-circle.
     If the arc forms a closed ellipse (the angle of the arc is equal to or greater 
     than 360.0 degree), no connections with the center position is added. */
  GraphicsArcStylePieRoundedEnd         = 5
} GraphicsArcStyle;

#ifdef __cplusplus
  }
#endif

#endif /* Graphics_H */

/* Embedded Wizard */
