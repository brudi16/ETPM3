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

#ifndef _EffectsEffect_H
#define _EffectsEffect_H

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

/* Forward declaration of the class Core::Timer */
#ifndef _CoreTimer_
  EW_DECLARE_CLASS( CoreTimer )
#define _CoreTimer_
#endif

/* Forward declaration of the class Effects::Effect */
#ifndef _EffectsEffect_
  EW_DECLARE_CLASS( EffectsEffect )
#define _EffectsEffect_
#endif

/* Forward declaration of the class Effects::TimingList */
#ifndef _EffectsTimingList_
  EW_DECLARE_CLASS( EffectsTimingList )
#define _EffectsTimingList_
#endif


/* The class Effects::Effect provides the base functionality for all kinds of animation 
   effects. Effects allow the designer to enrich the GUI application with additional 
   fancy and eye candy animations. For example, the effect Effects::ColorEffect 
   performs the color fade animation. Effects::RectEffect in contrast can animate 
   the position and the size of a GUI component, etc. Animation effects are determined 
   by their duration and by the timing function.
   The duration is primarily controlled by the value of the property @CycleDuration. 
   This is the time the effect will take for a single animation run. Whether and 
   how often the animation is repeated is stored in the property @NoOfCycles. In 
   this case the property @InterCycleDelay can determine an optional interval to 
   wait between two consecutive animation runs. Finally the property @InitialDelay 
   determines the interval to wait at the very beginning of the effect still before 
   the first animation run began.
   The timing function determines the curve to run the animation. The class implements 
   an extensive set of various timing functions. In its simplest case the animation 
   can follow a straight line, or it can start slow and get faster afterwards. More 
   complex timings perform realistic spring elastic and bounce animations. Besides 
   it the user can configure his/her own animation curve. In such case the timing 
   function is based on a cubic Bezier curve. It gives the designer a lot of possibilities 
   to specify very fancy timing functions. The timing is controlled by the property 
   @Timing. In the case the designer wants to specify a new curve, the properties 
   @TimingCustom1 and @TimingCustom2 are available. With the property @Noise an 
   additional random noise can be added to the effect.
   During the runtime of the animation, the effect will send signals to the slot 
   method stored in the property @OnAnimate. When the effect is finished a signal 
   is send to the slot method stored in the @OnFinished property.
   Whether the effect is running or not is controlled by its property @Enabled. 
   It can be used to start and stop the effect. The effect can also be controlled 
   by sending signals to its @StartEffect and @StopEffect slot methods. With the 
   property @Reversed the playback direction can be determined. This allows to simply 
   rewind running effects or to configure an effect to be played in the reverse 
   direction. The slot method @ReverseEffect can also be used to switch the playback 
   direction. */
EW_DEFINE_FIELDS( EffectsEffect, XObject )
  EW_VARIABLE( timingList,      EffectsTimingList )
  EW_VARIABLE( timer,           CoreTimer )

  /* The property 'OnFinished' can refer to a slot method, which should be invoked 
     when the effect is done. It's up to you to provide the slot method and to fill 
     it with the desired behavior. It makes possible to chain effects together, 
     so the finish of one effect can trigger another effect. To do this simply assign 
     the @StartEffect slot method of the one effect to the OnFinished property of 
     the other effect. */
  EW_PROPERTY( OnFinished,      XSlot )

  /* The property 'OnAnimate' can refer to a slot method, which should be invoked 
     when the effect triggers the next animation frame. It's up to you to provide 
     the slot method and to fill it with the desired behavior. From the method you 
     can query the current progress of the animation. For this purpose derived classes 
     provide a variable Value.
     Usually, it is not necessary to implement any slot methods in order to perform 
     the animation. All derived effect classes do provide an Outlet property, which 
     can refer to the property which should be animated. */
  EW_PROPERTY( OnAnimate,       XSlot )
  EW_VARIABLE( direction,       XInt32 )
  EW_VARIABLE( startDirection,  XInt32 )
  EW_VARIABLE( curveFactor2,    XFloat )
  EW_VARIABLE( curveFactor1,    XFloat )
  EW_VARIABLE( invCycleDuration, XFloat )
  EW_VARIABLE( lastFrame,       XFloat )
  EW_VARIABLE( cycleCounter,    XInt32 )
  EW_VARIABLE( startTime,       XUInt32 )

  /* The property 'NoOfCycles' determines how often the effect should repeat the 
     animation. If this value is zero, the effect will run endless. */
  EW_PROPERTY( NoOfCycles,      XInt32 )

  /* The property 'CycleDuration' stores the period in milliseconds of a single 
     animation run. */
  EW_PROPERTY( CycleDuration,   XInt32 )

  /* The property 'Timing' determines the curve to interpolate the animated values 
     during the animation:
     - Effects::Timing.Linear : the animation will follow a straight line. The values 
     will be linearly interpolated.
     - Effects::Timing.Power_In : the animation starts slow and then accelerates 
     using the power function f(t)=t^Exponent. The exponent is determined by the 
     property @Exponent. To achieve an effect like the jQuery 'easeInQuad', 'easeInCube', 
     'easeInQuart' and 'easeInQuint' set the Exponent to the corresponding value 
     2.0, 3.0, 4.0 or 5.0.
     - Effects::Timing.Power_Out : the animation starts fast and then decelerates 
     using the power function f(t)=t^Exponent. The exponent is determined by the 
     property @Exponent. To achieve an effect like the jQuery 'easeOutQuad', 'easeOutCube', 
     'easeOutQuart' and 'easeOutQuint' set the Exponent to the corresponding value 
     2.0, 3.0, 4.0 or 5.0.
     - Effects::Timing.Power_InOut : the animation starts slow, accelerates and 
     then decelerates again using the power function f(t)=t^Exponent. The exponent 
     is determined by the property @Exponent. To achieve an effect like the jQuery 
     'easeInOutQuad', 'easeInOutCube', 'easeInOutQuart' and 'easeInOutQuint' set 
     the Exponent to the corresponding value 2.0, 3.0, 4.0 or 5.0.
     - Effects::Timing.Exp_In : the animation starts slow and then accelerates using 
     the formula f(t)=(exp(Exponent*t)-1.0)/(exp(Exponent)-1.0). The exponent is 
     determined by the property @Exponent. To achieve an effect like the jQuery 
     'easeInExpo' set the Exponent to the value 7.0.
     - Effects::Timing.Exp_Out : the animation starts fast and then decelerates 
     using the formula f(t)=(exp(Exponent*t)-1.0)/(exp(Exponent)-1.0). The exponent 
     is determined by the property @Exponent. To achieve an effect like the jQuery 
     'easeOutExpo' set the Exponent to the value 7.0.
     - Effects::Timing.Exp_InOut : the animation starts slow, accelerates and then 
     decelerates again using the formula f(t)=(exp(Exponent*t)-1.0)/(exp(Exponent)-1.0). 
     The exponent is determined by the property @Exponent. To achieve an effect 
     like the jQuery 'easeInOutExpo' set the Exponent to the value 7.0.
     - Effects::Timing.Sine_In : the animation starts slow and then accelerates 
     using the sine function f(t)=sin(t*90).
     - Effects::Timing.Sine_Out : the animation starts fast and then decelerates 
     using the sine function f(t)=sin(t*90).
     - Effects::Timing.Sine_InOut : the animation starts slow, accelerates and then 
     decelerates again using the sine function f(t)=sin(t*90).
     - Effects::Timing.Circle_In : the animation starts slow and then accelerates 
     using the circular function f(t)=1-sqrt(1-t^2).
     - Effects::Timing.Circle_Out : the animation starts fast and then decelerates 
     using the circular function f(t)=1-sqrt(1-t^2).
     - Effects::Timing.Circle_InOut : the animation starts slow, accelerates and 
     then decelerates again using the circular function f(t)=1-sqrt(1-t^2).
     - Effects::Timing.Back_In : at the begin the animation retracts slightly and 
     then it accelerates again towards the finish. The amplitude of the retraction 
     is determined by the property @Amplitude. This timing is based on the formula 
     f(t)=t^3-t*Amplitude*sin(t*180).
     - Effects::Timing.Back_Out : at the begin the animation decelerates again towards 
     the finish and then swings slightly over the final position. The amplitude 
     of the retraction at the final position is determined by the property @Amplitude. 
     This timing is based on the formula f(t)=t^3-t*Amplitude*sin(t*180).
     - Effects::Timing.Back_InOut : at the begin the animation retracts slightly 
     and then it accelerates again. At the half time the animation decelerates and 
     once reached the final position it swings slightly over it. The amplitude of 
     the retractions at the start and the end position is determined by the property 
     @Amplitude. This timing is based on the formula f(t)=t^3-t*Amplitude*sin(t*180).
     - Effects::Timing.Elastic_In : similarly to a spring this animation oscillates 
     back and forth around its start position increasing with every oscillation 
     its amplitude. The total number of oscillations is determined by the property 
     @Oscillations. With the end of the last oscillation the animation reaches its 
     final position. This timing is based on the formula f(t)=t^3*sin(t*90*(1+4*Oscillations)).
     - Effects::Timing.Elastic_Out : similarly to a spring this animation oscillates 
     back and forth around its finish position decreasing with every oscillation 
     its amplitude. The total number of oscillations is determined by the property 
     @Oscillations. With the end of the last oscillation the animation reaches its 
     final position. This timing is based on the formula f(t)=t^3*sin(t*90*(1+4*Oscillations)).
     - Effects::Timing.Elastic_InOut : this animation oscillates back and forth 
     around its start position increasing with every oscillation its amplitude. 
     Then from the halftime the animation oscillates around its finish position 
     decelerating again its amplitude with every oscillation. How often the animation 
     oscillates around the start and finish position is determined by the property 
     @Oscillations. With the end of the last oscillation the animation reaches its 
     final position. This timing is based on the formula f(t)=t^3*sin(t*90*(1+4*Oscillations)).
     - Effects::Timing.Bounce_In : this animation bounces on its start position 
     increasing with every bounce its amplitude. The total number of bounces is 
     determined by the property @Bounces. How much the amplitude is increased is 
     determined by the property @Elasticity. With the end of the last bounce the 
     animation reaches its final position.
     - Effects::Timing.Bounce_Out : this animation bounces on its finish position 
     decreasing with every bounce its amplitude. The total number of bounces is 
     determined by the property @Bounces. How much the amplitude is decreased is 
     determined by the property @Elasticity. With the end of the last bounce the 
     animation reaches its final position.
     - Effects::Timing.Bounce_InOut : this animation bounces on its start position 
     increasing with every bounce its amplitude. Then from the halftime this animation 
     bounces on its finish position decreasing again its amplitude with every bounce. 
     How often the animation bounces on the start and on the finish position is 
     determined by the property @Bounces. How much the amplitude is increased/decreased 
     is determined by the property @Elasticity. With the end of the last bounce 
     the animation reaches its final position.
     - Effects::Timing.EaseIn_FastOut : the animation starts slow and then accelerates. 
     This mode corresponds to Effects::Timing.Power_In with property @Exponent set 
     to 3.0. 
     - Effects::Timing.FastIn_EaseOut : the animation starts fast and then decelerates. 
     This mode corresponds to Effects::Timing.Power_Out with property @Exponent 
     set to 3.0. 
     - Effects::Timing.FastIn_FastOut : the animation starts fast, decelerates and 
     then accelerates again.
     - Effects::Timing.EaseIn_EaseOut : the animation starts slow, accelerates and 
     then decelerates again.
     - Effects::Timing.Custom : The animation curve is determined by properties 
     @TimingCustom1 and @TimingCustom2. */
  EW_PROPERTY( Timing,          XEnum )

  /* The property 'Enabled' determines whether the effect is currently running or 
     not. Changing the value of this property from 'false' to 'true' will re-start 
     the effect. In such case the effect will start from the beginning.
     The lifetime of the effect can also be controlled by sending signals to the 
     slot methods @StartEffect and @StopEffect. Moreover with the property @Reversed 
     and the slot method @ReverseEffect the playback direction can be controlled. */
  EW_PROPERTY( Enabled,         XBool )
  EW_VARIABLE( useBezier2,      XBool )
  EW_VARIABLE( useBezier3,      XBool )
EW_END_OF_FIELDS( EffectsEffect )

/* Virtual Method Table (VMT) for the class : 'Effects::Effect' */
EW_DEFINE_METHODS( EffectsEffect, XObject )
  EW_METHOD( Animate,           void )( EffectsEffect _this, XFloat aProgress )
EW_END_OF_METHODS( EffectsEffect )

/* 'C' function for method : 'Effects::Effect.timerSlot()' */
void EffectsEffect_timerSlot( EffectsEffect _this, XObject sender );

/* 'C' function for method : 'Effects::Effect.run()' */
void EffectsEffect_run( EffectsEffect _this, XFloat aFrame );

/* 'C' function for method : 'Effects::Effect.runRevRev()' */
XBool EffectsEffect_runRevRev( EffectsEffect _this );

/* 'C' function for method : 'Effects::Effect.runRevFwd()' */
XBool EffectsEffect_runRevFwd( EffectsEffect _this );

/* 'C' function for method : 'Effects::Effect.runFwdRev()' */
XBool EffectsEffect_runFwdRev( EffectsEffect _this );

/* 'C' function for method : 'Effects::Effect.runFwdFwd()' */
XBool EffectsEffect_runFwdFwd( EffectsEffect _this );

/* 'C' function for method : 'Effects::Effect.OnSetTiming()' */
void EffectsEffect_OnSetTiming( EffectsEffect _this, XEnum value );

/* 'C' function for method : 'Effects::Effect.OnSetNoOfCycles()' */
void EffectsEffect_OnSetNoOfCycles( EffectsEffect _this, XInt32 value );

/* 'C' function for method : 'Effects::Effect.OnSetCycleDuration()' */
void EffectsEffect_OnSetCycleDuration( EffectsEffect _this, XInt32 value );

/* 'C' function for method : 'Effects::Effect.OnSetEnabled()' */
void EffectsEffect_OnSetEnabled( EffectsEffect _this, XBool value );

/* 'C' function for method : 'Effects::Effect.Animate()' */
void EffectsEffect_Animate( EffectsEffect _this, XFloat aProgress );

/* Wrapper function for the virtual method : 'Effects::Effect.Animate()' */
void EffectsEffect__Animate( void* _this, XFloat aProgress );

#ifdef __cplusplus
  }
#endif

#endif /* _EffectsEffect_H */

/* Embedded Wizard */
