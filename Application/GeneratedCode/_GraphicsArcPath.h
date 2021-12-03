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

#ifndef _GraphicsArcPath_H
#define _GraphicsArcPath_H

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

#include "_GraphicsPath.h"

/* Forward declaration of the class Graphics::ArcPath */
#ifndef _GraphicsArcPath_
  EW_DECLARE_CLASS( GraphicsArcPath )
#define _GraphicsArcPath_
#endif


/* The class Graphics::ArcPath provides a convenient version of Graphics::Path class 
   intended to calculate paths for elliptical arcs, segments, pies or rings. The 
   arc is configured with the properties @StartAngle, @EndAngle, @RadiusX and @RadiusY. 
   With the property @Style the particular variant (Arc, Segment, Pie, etc.) of 
   the resulting path is determined. If the style 'Pie', 'PieRounded', 'PieRoundedStart' 
   or 'PieRoundedEnd' is selected, the the additional properties @InnerRadiusX and 
   @InnerRadiusY can be used to construct a ring or segment of a ring.
   With the path information the curves can be displayed on the screen. The view 
   Views::FillPath displays the path as filled polygon. The view Views::StrokePath 
   displays the path as a line with specified width. */
EW_DEFINE_FIELDS( GraphicsArcPath, GraphicsPath )
  /* The property 'EndAngle' determines the angle for the end position of the arc 
     expressed in degree and measured clockwise relative to the positive X-axis 
     of the coordinate system. */
  EW_PROPERTY( EndAngle,        XFloat )

  /* The property 'StartAngle' determines the angle for the start position of the 
     arc expressed in degree and measured clockwise relative to the positive X-axis 
     of the coordinate system. */
  EW_PROPERTY( StartAngle,      XFloat )

  /* The property 'InnerRadiusY' determines the inner radius of the arc in vertical 
     direction used when constructing a path configured with @Style == Graphics::ArcStyle.Pie, 
     @Style == Graphics::ArcStyle.PieRoundedStart, @Style == Graphics::ArcStyle.PieRoundedEnd 
     or @Style == Graphics::ArcStyle.PieRounded. */
  EW_PROPERTY( InnerRadiusY,    XFloat )

  /* The property 'InnerRadiusX' determines the inner radius of the arc in horizontal 
     direction used when constructing a path configured with @Style == Graphics::ArcStyle.Pie, 
     @Style == Graphics::ArcStyle.PieRoundedStart, @Style == Graphics::ArcStyle.PieRoundedEnd 
     or @Style == Graphics::ArcStyle.PieRounded. */
  EW_PROPERTY( InnerRadiusX,    XFloat )

  /* The property 'RadiusY' determines the radius of the arc in vertical direction. */
  EW_PROPERTY( RadiusY,         XFloat )

  /* The property 'RadiusX' determines the radius of the arc in horizontal direction. */
  EW_PROPERTY( RadiusX,         XFloat )

  /* The property 'Style' determines the resulting shape of the calculated path. 
     The property can assume following values:
     - Arc: Simple elliptical arc. The both arc ends remain opened unless the angle 
     of the arc is equal to or greater than 360.0 degree.
     - Segment: Segment of an ellipse with the start and the end positions of the 
     arc being connected together by a straight line segment. If the arc forms a 
     closed ellipse (the angle of the arc is equal to or greater than 360.0 degree), 
     no line segment is added.
     - Pie: Shape typical for displaying pie charts. Here the start and the end 
     positions of the arc are connected with the center of the ellipse by additional 
     straight line segments. If the arc forms a closed ellipse (the angle of the 
     arc is equal to or greater than 360.0 degree), no line segments are added as 
     connections with the center position. This style can be used together with 
     the properties @InnerRadiusX and @InnerRadiusY permitting the construction 
     of ring segments.
     - PieRounded: Shape typical for displaying circular bar diagrams with rounded 
     start and end edges. Here the start and the end positions of the arc are connected 
     with the center of the ellipse by additional semi-circles. If the arc forms 
     a closed ellipse (the angle of the arc is equal to or greater than 360.0 degree), 
     no connections with the center position is added. This style can be used together 
     with the properties @InnerRadiusX and @InnerRadiusY permitting the construction 
     of ring segments with rounded edges.
     - PieRoundedStart: Shape typical for displaying circular bar diagrams with 
     rounded start edges. Here the start position of the arc is connected with the 
     center of the ellipse by additional semi-circle. The end position, in turn, 
     is connected by a straight line segment. If the arc forms a closed ellipse 
     (the angle of the arc is equal to or greater than 360.0 degree), no connections 
     with the center position is added. This style can be used together with the 
     properties @InnerRadiusX and @InnerRadiusY permitting the construction of ring 
     segments with rounded edges.
     - PieRoundedEnd: Shape typical for displaying circular bar diagrams with rounded 
     end edges. Here the start position of the arc is connected with the center 
     of the ellipse by additional straight line segment. The end position, in turn, 
     is connected with the center by a semi-circle. If the arc forms a closed ellipse 
     (the angle of the arc is equal to or greater than 360.0 degree), no connections 
     with the center position is added. This style can be used together with the 
     properties @InnerRadiusX and @InnerRadiusY permitting the construction of ring 
     segments with rounded edges. */
  EW_PROPERTY( Style,           XEnum )
EW_END_OF_FIELDS( GraphicsArcPath )

/* Virtual Method Table (VMT) for the class : 'Graphics::ArcPath' */
EW_DEFINE_METHODS( GraphicsArcPath, GraphicsPath )
EW_END_OF_METHODS( GraphicsArcPath )

/* 'C' function for method : 'Graphics::ArcPath.updatePath()' */
void GraphicsArcPath_updatePath( GraphicsArcPath _this, XObject sender );

/* 'C' function for method : 'Graphics::ArcPath.OnSetEndAngle()' */
void GraphicsArcPath_OnSetEndAngle( GraphicsArcPath _this, XFloat value );

/* 'C' function for method : 'Graphics::ArcPath.OnSetStartAngle()' */
void GraphicsArcPath_OnSetStartAngle( GraphicsArcPath _this, XFloat value );

/* 'C' function for method : 'Graphics::ArcPath.OnGetInnerRadius()' */
XFloat GraphicsArcPath_OnGetInnerRadius( GraphicsArcPath _this );

/* 'C' function for method : 'Graphics::ArcPath.OnSetInnerRadius()' */
void GraphicsArcPath_OnSetInnerRadius( GraphicsArcPath _this, XFloat value );

/* 'C' function for method : 'Graphics::ArcPath.OnSetRadius()' */
void GraphicsArcPath_OnSetRadius( GraphicsArcPath _this, XFloat value );

/* 'C' function for method : 'Graphics::ArcPath.OnSetStyle()' */
void GraphicsArcPath_OnSetStyle( GraphicsArcPath _this, XEnum value );

#ifdef __cplusplus
  }
#endif

#endif /* _GraphicsArcPath_H */

/* Embedded Wizard */
