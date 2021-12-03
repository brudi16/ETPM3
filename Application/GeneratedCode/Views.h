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

#ifndef Views_H
#define Views_H

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

#include "_ViewsFillPath.h"
#include "_ViewsFrame.h"
#include "_ViewsImage.h"
#include "_ViewsRectangle.h"
#include "_ViewsText.h"
#include "_ViewsWarpImage.h"
#include "_ViewsWarpView.h"

/* The definition Views::ImageAlignment determines the set of constraints to apply 
   on a bitmap if its size differ from the size of the view where the bitmap is 
   shown. Depending on the active constraints a bitmap can be aligned or stretched 
   within the view's area. */
typedef enum
{

  /* The constraint 'AlignHorzLeft' aligns the bitmap to the left edge of the area 
     where the bitmap is displayed. */
  ViewsImageAlignmentAlignHorzLeft      = 0x00000001,

  /* The constraint 'AlignHorzCenter' aligns the bitmap horizontally in the middle 
     of the area where the bitmap is displayed. */
  ViewsImageAlignmentAlignHorzCenter    = 0x00000002,

  /* The constraint 'AlignHorzRight' aligns the bitmap to the right edge of the 
     area where the bitmap is displayed. */
  ViewsImageAlignmentAlignHorzRight     = 0x00000004,

  /* The constraint 'AlignVertTop' aligns the bitmap to the top edge of the area 
     where the bitmap is displayed. */
  ViewsImageAlignmentAlignVertTop       = 0x00000008,

  /* The constraint 'AlignVertCenter' aligns the bitmap vertically in the middle 
     of the area of the area where the bitmap is displayed. */
  ViewsImageAlignmentAlignVertCenter    = 0x00000010,

  /* The constraint 'AlignVertBottom' aligns the bitmap to the bottom edge of the 
     area where the bitmap is displayed. */
  ViewsImageAlignmentAlignVertBottom    = 0x00000020,

  /* The constraint 'ScaleToFill' scales the bitmap to the size of the view while 
     keeping the bitmap's aspect ratio. The bitmap is scaled until the entire view's 
     area is covered by the bitmap. If the aspect ratio of the bitmap differ to 
     the of the view, the bitmap is clipped on the view's edges. */
  ViewsImageAlignmentScaleToFill        = 0x00000040,

  /* The constraint 'ScaleToFit' scales the bitmap to the size of the view while 
     keeping the bitmap's aspect ratio. The bitmap is scaled until the entire bitmap 
     fits within the view's area. If the aspect ratio of the bitmap differ to the 
     of the view, parts of the view remain not covered by the bitmap. */
  ViewsImageAlignmentScaleToFit         = 0x00000080,

  /* The constraint 'StretchToFill' scales the bitmap to the size of the view without 
     taking in account the bitmaps's aspect ratio. Thus the bitmap may appear distorted. */
  ViewsImageAlignmentStretchToFill      = 0x00000100
} ViewsImageAlignment;

/* The definition Views::TextAlignment determines the set of constraints to apply 
   on text rows and blocks if their size differ from the size of the view where 
   the text is shown. Depending on the active constraints the text rows can be aligned 
   horizontally and text blocks vertically. */
typedef enum
{

  /* The constraint 'AlignHorzLeft' aligns the text rows to the left edge of the 
     area where the text is displayed. */
  ViewsTextAlignmentAlignHorzLeft       = 0x00000001,

  /* The constraint 'AlignHorzCenter' aligns the text rows horizontally in the middle 
     of the area where the text is displayed. */
  ViewsTextAlignmentAlignHorzCenter     = 0x00000002,

  /* The constraint 'AlignHorzRight' aligns the text rows to the right edge of the 
     area where the text is displayed. */
  ViewsTextAlignmentAlignHorzRight      = 0x00000004,

  /* The constraint 'AlignVertTop' aligns the text row or the entire text block 
     to the top edge of the area where the text is displayed. */
  ViewsTextAlignmentAlignVertTop        = 0x00000008,

  /* The constraint 'AlignVertCenter' aligns the text row or the entire text block 
     vertically in the middle of the area where the text is displayed. */
  ViewsTextAlignmentAlignVertCenter     = 0x00000010,

  /* The constraint 'AlignVertBottom' aligns the row or the entire text block to 
     the bottom edge of the area where the text is displayed. */
  ViewsTextAlignmentAlignVertBottom     = 0x00000020,

  /* The constraint 'AlignHorzJustified' instructs the Text view to stretch all 
     automatically wrapped text rows to the predetermined wrap width. The stretching 
     takes place on blank signs only and affects multi-line text only. This option 
     can be combined with AlignHorzLeft, AlignHorzCenter, AlignHorzRight or AlignHorzAuto. */
  ViewsTextAlignmentAlignHorzJustified  = 0x00000040,

  /* The constraint 'AlignHorzAuto' aligns the text rows depending on its content 
     to the left or right edge of the area where the text is displayed. If the Text 
     view is configured to apply the Unicode Bidirectional Algorithm on the provided 
     text and this text starts with a right-to-left character, the option implies 
     the alignment to the right edge. In all other cases the left alignment is assumed. */
  ViewsTextAlignmentAlignHorzAuto       = 0x00000080
} ViewsTextAlignment;

/* The definition Views::Orientation determines the possible options to control 
   the orientation of the content displayed in the Views::Image, Views::Group and 
   Views::Text views. Depending on the selected option the view displays the content 
   rotated. */
typedef enum
{

  /* No rotation applied on the view content. */
  ViewsOrientationNormal                = 0,

  /* The view content is rotated by 90 degrees in counter-clockwise direction. */
  ViewsOrientationRotated_90            = 1,

  /* The view content is rotated by 180 degrees in counter-clockwise direction. */
  ViewsOrientationRotated_180           = 2,

  /* The view content is rotated by 90 degrees in clockwise direction. */
  ViewsOrientationRotated_270           = 3
} ViewsOrientation;

#ifdef __cplusplus
  }
#endif

#endif /* Views_H */

/* Embedded Wizard */
