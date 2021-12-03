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

#ifndef Effects_H
#define Effects_H

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

#include "_EffectsEffect.h"
#include "_EffectsEffectTimerClass.h"
#include "_EffectsFader.h"
#include "_EffectsFaderTask.h"
#include "_EffectsFloatEffect.h"
#include "_EffectsShowHideTransition.h"
#include "_EffectsTimingList.h"
#include "_EffectsTransition.h"
#include "_EffectsVisibilityFader.h"

/* The definition Effects::Timing determines the available timing functions for 
   animation effects. Except the 'Custom' item, all items of this definition represent 
   build-in timing functions. These can be simply selected in the effect property 
   Timing. */
typedef enum
{

  /* The timing function 'Linear' describes an animation which follows a straight 
     line. */
  EffectsTimingLinear                   = 0,

  /* The timing function 'Power_In' defines an animation, which starts slow and 
     then accelerates using the power function f(t)=t^Exponent. The parameter 'Exponent' 
     can be configured. */
  EffectsTimingPower_In                 = 1,

  /* The timing function 'Power_Out' defines an animation, which starts fast and 
     then decelerates using the power function f(t)=t^Exponent. The parameter 'Exponent' 
     can be configured. */
  EffectsTimingPower_Out                = 2,

  /* The timing function 'Power_InOut' defines an animation, which starts slow, 
     accelerates and then decelerates again using the power function f(t)=t^Exponent. 
     The parameter 'Exponent' can be configured. */
  EffectsTimingPower_InOut              = 3,

  /* The timing function 'Exp_In' defines an animation, which starts slow and then 
     accelerates using the formula f(t)=(exp(Exponent*t)-1.0)/(exp(Exponent)-1.0). 
     The parameter 'Exponent' can be configured. */
  EffectsTimingExp_In                   = 4,

  /* The timing function 'Exp_Out' defines an animation, which starts fast and then 
     decelerates using the formula f(t)=(exp(Exponent*t)-1.0)/(exp(Exponent)-1.0). 
     The parameter 'Exponent' can be configured. */
  EffectsTimingExp_Out                  = 5,

  /* The timing function 'Exp_InOut' defines an animation, which starts slow, accelerates 
     and then decelerates again using the formula f(t)=(exp(Exponent*t)-1.0)/(exp(Exponent)-1.0). 
     The parameter 'Exponent' can be configured. */
  EffectsTimingExp_InOut                = 6,

  /* The timing function 'EaseSine_In' defines an animation, which starts slow and 
     then accelerates using the sine function f(t)=sin(t*90). */
  EffectsTimingSine_In                  = 7,

  /* The timing function 'EaseSine_Out' defines an animation, which starts fast 
     and then decelerates using the sine function f(t)=sin(t*90). */
  EffectsTimingSine_Out                 = 8,

  /* The timing function 'EaseSine_InOut' defines an animation, which starts slow, 
     accelerates and then decelerates again using the sine function f(t)=sin(t*90). */
  EffectsTimingSine_InOut               = 9,

  /* The timing function 'EaseCircle_In' defines an animation, which starts slow 
     and then accelerates using the circular function f(t)=1-sqrt(1-t^2). */
  EffectsTimingCircle_In                = 10,

  /* The timing function 'EaseCircle_Out' defines an animation, which starts fast 
     and then decelerates using the circular function f(t)=1-sqrt(1-t^2). */
  EffectsTimingCircle_Out               = 11,

  /* The timing function 'EaseCircle_InOut' defines an animation, which starts slow, 
     accelerates and then decelerates again using the circular function f(t)=1-sqrt(1-t^2). */
  EffectsTimingCircle_InOut             = 12,

  /* The timing function 'EaseBack_In' defines an animation, which at the begin 
     retracts slightly and then it accelerates again towards the finish. The amplitude 
     of the retraction can be determined. This timing is based of the formula f(t)=t^3-t*Amplitude*sin(t*180). 
     The parameter 'Amplitude' can be configured. */
  EffectsTimingBack_In                  = 13,

  /* The timing function 'EaseBack_Out' defines an animation, which at the begin 
     decelerates again towards the finish and then swings slightly over the final 
     position. The amplitude of the retraction at the final position can be determined. 
     This timing is based of the formula f(t)=t^3-t*Amplitude*sin(t*180). The parameter 
     'Amplitude' can be configured. */
  EffectsTimingBack_Out                 = 14,

  /* The timing function 'EaseBack_InOut' defines an animation, which at the begin 
     retracts slightly and then it accelerates again. At the half time the animation 
     decelerates and once reached the final position it swings slightly over it. 
     The amplitude of the retractions at the start and the end position can be determined. 
     This timing is based of the formula f(t)=t^3-t*Amplitude*sin(t*180). The parameter 
     'Amplitude' can be configured. */
  EffectsTimingBack_InOut               = 15,

  /* The timing function 'EaseElastic_In' defines an animation, which similarly 
     to a spring oscillates back and forth around its start position increasing 
     with every oscillation its amplitude. The total number of oscillations can 
     be determined. With the end of the last oscillation the animation reaches its 
     final position. This timing is based of the formula f(t)=t^3*sin(t*90*(1+4*Oscillations)). 
     The parameter 'Oscillations' can be configured. */
  EffectsTimingElastic_In               = 16,

  /* The timing function 'EaseElastic_Out' defines an animation, which similarly 
     to a spring oscillates back and forth around its finish position decreasing 
     with every oscillation its amplitude. The total number of oscillations can 
     be determined. With the end of the last oscillation the animation reaches its 
     final position. This timing is based of the formula f(t)=t^3*sin(t*90*(1+4*Oscillations)). 
     The parameter 'Oscillations' can be configured. */
  EffectsTimingElastic_Out              = 17,

  /* The timing function 'EaseElastic_InOut' defines an animation, which oscillates 
     back and forth around its start position increasing with every oscillation 
     its amplitude. Then from the halftime the animation oscillates around its finish 
     position decelerating again its amplitude with every oscillation. How often 
     the animation oscillates around the start and finish position can be determined. 
     With the end of the last oscillation the animation reaches its final position. 
     This timing is based of the formula f(t)=t^3*sin(t*90*(1+4*Oscillations)). 
     The parameter 'Oscillations' can be configured. */
  EffectsTimingElastic_InOut            = 18,

  /* The timing function 'EaseBounce_In' defines an animation, which bounces on 
     its start position increasing with every bounce its amplitude. The total number 
     of bounces and how much the amplitude is increased can be determined. With 
     the end of the last bounce the animation reaches its final position. The number 
     of bounces and the bounce amplitude can be configured. */
  EffectsTimingBounce_In                = 19,

  /* The timing function 'EaseBounce_Out' defines an animation, which bounces on 
     its finish position decreasing with every bounce its amplitude. The total number 
     of bounces and how much the amplitude is decreased can be determined. With 
     the end of the last bounce the animation reaches its final position. The number 
     of bounces and the bounce amplitude can be configured. */
  EffectsTimingBounce_Out               = 20,

  /* The timing function 'EaseBounce_InOut' defines an animation, which bounces 
     on its start position increasing with every bounce its amplitude. Then from 
     the halftime this animation bounces on its finish position decreasing again 
     its amplitude with every bounce. How often the animation bounces on the start 
     and on the finish position and how much the amplitude is increased/decreased 
     can be determined. With the end of the last bounce the animation reaches its 
     final position. The number of bounces and the bounce amplitude can be configured. */
  EffectsTimingBounce_InOut             = 21,

  /* The timing function 'EaseIn_FastOut' describes an animation which starts slow 
     and then accelerates. */
  EffectsTimingEaseIn_FastOut           = 22,

  /* The timing function 'FastIn_EaseOut' describes an animation which starts fast 
     and then decelerates. */
  EffectsTimingFastIn_EaseOut           = 23,

  /* The timing function 'EaseIn_EaseOut' describes an animation which starts slow, 
     accelerates and then decelerates again. */
  EffectsTimingEaseIn_EaseOut           = 24,

  /* The timing function 'FastIn_FastOut' describes an animation which starts fast, 
     decelerates and then accelerates again. */
  EffectsTimingFastIn_FastOut           = 25,

  /* The item 'Custom' determines a user defined timing function curve based on 
     a Bezier curve. See description of the class Effects::Effect. */
  EffectsTimingCustom                   = 26
} EffectsTiming;

/* The global autoobject Effects::EffectTimer triggers all actually active animation 
   effects. In this way all effects will run simultanously. Per default the timer 
   is configured with 15 ms period (~60 FPS). By overriding the Effects::EffectTimer 
   autoobject by a variant you can specify another resolution to drive the animations. */
EW_DECLARE_AUTOOBJECT( EffectsEffectTimer, EffectsEffectTimerClass )

/* The global autoobject Effects::ShowHideCentered represents the most primitive 
   fade-in/out operation affecting the pure visibility of a given GUI component. 
   When using the transition for the fade-in operation, the GUI component is automatically 
   arranged to appear centered within the area of its owner component. This transition 
   is thus ideal wherever one GUI component should instantly appear or disappear 
   in context of another component without any animation effects.
   Please note, with this transition the fade-in operation is performed just at 
   the beginning of all other transitions running simultaneously, in other words, 
   the GUI component appears during the start phase of the transition. In turn, 
   to fade-out the component, the operation is executed during the end phase of 
   the transition. 
   This object exists for your convenience permitting you to simply refer the transition 
   wherever it is required in your implementation without having to take care of 
   the creation and configuration of the object. If you require the transition to 
   run with other configuration (e.g. to show the GUI component at the end instead 
   of the start phase), create a copy of this object and adapt its properties accordingly. */
EW_DECLARE_AUTOOBJECT( EffectsShowHideCentered, EffectsShowHideTransition )

#ifdef __cplusplus
  }
#endif

#endif /* Effects_H */

/* Embedded Wizard */
