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

#include "ewlocale.h"
#include "_CoreGroup.h"
#include "_CoreTimer.h"
#include "_CoreView.h"
#include "_EffectsEffect.h"
#include "_EffectsEffectTimerClass.h"
#include "_EffectsFader.h"
#include "_EffectsFaderTask.h"
#include "_EffectsFloatEffect.h"
#include "_EffectsShowHideTransition.h"
#include "_EffectsTimingList.h"
#include "_EffectsTransition.h"
#include "_EffectsVisibilityFader.h"
#include "Core.h"
#include "Effects.h"

/* Compressed strings for the language 'Default'. */
EW_CONST_STRING_PRAGMA static const unsigned int _StringsDefault0[] =
{
  0x0000019E, /* ratio 53.14 % */
  0xB8008500, 0x000A8452, 0x00F20039, 0x0DC00348, 0x40003380, 0xE003A000, 0x0083C44D,
  0x536800CA, 0x8C9D8011, 0x345CC317, 0x19244003, 0x92250890, 0xA3916844, 0x29129144,
  0x60039C8A, 0x1716000D, 0xB34000EF, 0x9D98C010, 0x7CD21917, 0x802273E9, 0xB001253A,
  0x22F09A51, 0x1D0EA442, 0x11087432, 0x03140000, 0xA8D5020B, 0x8D49E932, 0xB49C0129,
  0xC3A691A8, 0x8A254613, 0x22D4B901, 0x2D148BD5, 0x142A04C6, 0x369A526E, 0x6AC8F6AD,
  0xA9C2A110, 0xF5CAED0F, 0x48E4362A, 0x1B0560C2, 0xE6B33B9E, 0x8B749CCD, 0x975894F2,
  0x488A4FE8, 0xAA5D2E45, 0x86D3E250, 0x055701A0, 0xD6EF8260, 0x5E5126C3, 0x2DB1AB5C,
  0x93438868, 0x31A8452E, 0x83A36775, 0x9C6D1A61, 0x80EFAAD7, 0x00000000
};

/* Constant values used in this 'C' module only. */
static const XStringRes _Const0000 = { _StringsDefault0, 0x0002 };
static const XStringRes _Const0001 = { _StringsDefault0, 0x0044 };
static const XStringRes _Const0002 = { _StringsDefault0, 0x006C };
static const XStringRes _Const0003 = { _StringsDefault0, 0x00A9 };

#ifndef EW_DONT_CHECK_INDEX
  /* This function is used to check the indices when accessing an array.
     If you don't want this verification add the define EW_DONT_CHECK_INDEX
     to your Makefile or project settings. */
  static int EwCheckIndex( int aIndex, int aRange, const char* aFile, int aLine )
  {
    if (( aIndex < 0 ) || ( aIndex >= aRange ))
    {
      EwPrint( "[FATAL ERROR in %s:%d] Array index %d out of bounds %d",
                aFile, aLine, aIndex, aRange );
      EwPanic();
    }
    return aIndex;
  }

  #define EwCheckIndex( aIndex, aRange ) \
    EwCheckIndex( aIndex, aRange, __FILE__, __LINE__ )
#else
  #define EwCheckIndex( aIndex, aRange ) aIndex
#endif

/* Initializer for the class 'Effects::Effect' */
void EffectsEffect__Init( EffectsEffect _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( EffectsEffect );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( EffectsEffect );

  /* ... and initialize objects, variables, properties, etc. */
  _this->invCycleDuration = 0.001000f;
  _this->Timing = EffectsTimingLinear;
  _this->CycleDuration = 1000;
}

/* Re-Initializer for the class 'Effects::Effect' */
void EffectsEffect__ReInit( EffectsEffect _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Effects::Effect' */
void EffectsEffect__Done( EffectsEffect _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( XObject );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_.Super );
}

/* 'C' function for method : 'Effects::Effect.timerSlot()' */
void EffectsEffect_timerSlot( EffectsEffect _this, XObject sender )
{
  XBool done;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( sender );

  if ( _this->timer == 0 )
    return;

  if ( _this->startDirection == 0 )
  {
    _this->startDirection = 1;
    _this->direction = _this->startDirection;
    _this->startTime = _this->timer->Time;
    _this->cycleCounter = 0;
    _this->lastFrame = -1.000000f;
  }

  if (( _this->startDirection > 0 ) && ( _this->direction > 0 ))
    done = EffectsEffect_runFwdFwd( _this );
  else
    if (( _this->startDirection < 0 ) && ( _this->direction < 0 ))
      done = EffectsEffect_runRevRev( _this );
    else
      if ( _this->startDirection > 0 )
        done = EffectsEffect_runFwdRev( _this );
      else
        done = EffectsEffect_runRevFwd( _this );

  if ( done )
  {
    EffectsEffect_OnSetEnabled( _this, 0 );
    EwSignal( _this->OnFinished, ((XObject)_this ));
  }
}

/* 'C' function for method : 'Effects::Effect.run()' */
void EffectsEffect_run( EffectsEffect _this, XFloat aFrame )
{
  if (( _this->timingList == 0 ) && ((( _this->Timing == EffectsTimingBounce_In ) 
      || ( _this->Timing == EffectsTimingBounce_Out )) || ( _this->Timing == EffectsTimingBounce_InOut )))
  {
    XFloat sum = 0.500000f;
    XInt32 i;
    XFloat invSum;
    _this->timingList = EwNewObject( EffectsTimingList, 0 );
    _this->timingList->spans[ 0 ] = 1.000000f;
    _this->timingList->amps[ 0 ] = 1.000000f;

    for ( i = 1; i < 4; i = i + 1 )
    {
      _this->timingList->spans[ EwCheckIndex( i, 12 )] = _this->timingList->spans[ 
      EwCheckIndex( i - 1, 12 )] * 0.707107f;
      _this->timingList->amps[ EwCheckIndex( i, 12 )] = _this->timingList->amps[ 
      EwCheckIndex( i - 1, 12 )] * 0.500000f;
      sum = sum + _this->timingList->spans[ EwCheckIndex( i, 12 )];
    }

    invSum = 1.000000f / sum;
    _this->timingList->spans[ 0 ] = 0.500000f;
    sum = 0.000000f;

    for ( i = 0; i < 4; i = i + 1 )
    {
      _this->timingList->spans[ EwCheckIndex( i, 12 )] = _this->timingList->spans[ 
      EwCheckIndex( i, 12 )] * invSum;
      sum = sum + _this->timingList->spans[ EwCheckIndex( i, 12 )];
    }

    _this->timingList->spans[ 4 ] = _this->timingList->spans[ 4 ] + ( 1.000000f 
    - sum );
  }

  switch ( _this->Timing )
  {
    case EffectsTimingPower_In :
      aFrame = EwMathPow( aFrame, 3.000000f );
    break;

    case EffectsTimingPower_Out :
    {
      aFrame = 1.000000f - aFrame;
      aFrame = 1.000000f - EwMathPow( aFrame, 3.000000f );
    }
    break;

    case EffectsTimingPower_InOut :
    {
      aFrame = aFrame * 2.000000f;

      if ( aFrame < 1.000000f )
        aFrame = EwMathPow( aFrame, 3.000000f ) / 2.000000f;
      else
      {
        aFrame = 2.000000f - aFrame;
        aFrame = ( 2.000000f - EwMathPow( aFrame, 3.000000f )) * 0.500000f;
      }
    }
    break;

    case EffectsTimingExp_In :
      aFrame = ( EwMathPow( 2.718000f, 3.000000f * aFrame ) - 1.000000f ) / 19.079288f;
    break;

    case EffectsTimingExp_Out :
    {
      aFrame = 1.000000f - aFrame;
      aFrame = 1.000000f - (( EwMathPow( 2.718000f, 3.000000f * aFrame ) - 1.000000f ) 
      / 19.079288f );
    }
    break;

    case EffectsTimingExp_InOut :
    {
      aFrame = aFrame * 2.000000f;

      if ( aFrame < 1.000000f )
        aFrame = (( EwMathPow( 2.718000f, 3.000000f * aFrame ) - 1.000000f ) / 19.079288f ) 
        / 2.000000f;
      else
      {
        aFrame = 2.000000f - aFrame;
        aFrame = ( 2.000000f - (( EwMathPow( 2.718000f, 3.000000f * aFrame ) - 1.000000f ) 
        / 19.079288f )) * 0.500000f;
      }
    }
    break;

    case EffectsTimingSine_In :
      aFrame = 1.000000f - EwMathCos( aFrame * 90.000000f );
    break;

    case EffectsTimingSine_Out :
      aFrame = EwMathSin( aFrame * 90.000000f );
    break;

    case EffectsTimingSine_InOut :
    {
      aFrame = aFrame * 2.000000f;

      if ( aFrame < 1.000000f )
      {
        aFrame = 1.000000f - EwMathCos( aFrame * 90.000000f );
        aFrame = aFrame * 0.500000f;
      }
      else
      {
        aFrame = 2.000000f - aFrame;
        aFrame = 1.000000f - EwMathCos( aFrame * 90.000000f );
        aFrame = ( 2.000000f - aFrame ) * 0.500000f;
      }
    }
    break;

    case EffectsTimingCircle_In :
      aFrame = 1.000000f - EwMathSqrt( 1.000000f - ( aFrame * aFrame ));
    break;

    case EffectsTimingCircle_Out :
    {
      aFrame = 1.000000f - aFrame;
      aFrame = EwMathSqrt( 1.000000f - ( aFrame * aFrame ));
    }
    break;

    case EffectsTimingCircle_InOut :
    {
      aFrame = aFrame * 2.000000f;

      if ( aFrame < 1.000000f )
      {
        aFrame = 1.000000f - EwMathSqrt( 1.000000f - ( aFrame * aFrame ));
        aFrame = aFrame * 0.500000f;
      }
      else
      {
        aFrame = 2.000000f - aFrame;
        aFrame = 1.000000f - EwMathSqrt( 1.000000f - ( aFrame * aFrame ));
        aFrame = ( 2.000000f - aFrame ) * 0.500000f;
      }
    }
    break;

    case EffectsTimingBack_In :
      aFrame = (( aFrame * aFrame ) * aFrame ) - (( aFrame * 0.500000f ) * EwMathSin( 
      aFrame * 180.000000f ));
    break;

    case EffectsTimingBack_Out :
    {
      aFrame = 1.000000f - aFrame;
      aFrame = (( aFrame * aFrame ) * aFrame ) - (( aFrame * 0.500000f ) * EwMathSin( 
      aFrame * 180.000000f ));
      aFrame = 1.000000f - aFrame;
    }
    break;

    case EffectsTimingBack_InOut :
    {
      aFrame = aFrame * 2.000000f;

      if ( aFrame < 1.000000f )
      {
        aFrame = (( aFrame * aFrame ) * aFrame ) - (( aFrame * 0.500000f ) * EwMathSin( 
        aFrame * 180.000000f ));
        aFrame = aFrame * 0.500000f;
      }
      else
      {
        aFrame = 2.000000f - aFrame;
        aFrame = (( aFrame * aFrame ) * aFrame ) - (( aFrame * 0.500000f ) * EwMathSin( 
        aFrame * 180.000000f ));
        aFrame = ( 2.000000f - aFrame ) * 0.500000f;
      }
    }
    break;

    case EffectsTimingElastic_In :
      aFrame = (( aFrame * aFrame ) * aFrame ) * EwMathSin(( aFrame * 90.000000f ) 
      * 13.000000f );
    break;

    case EffectsTimingElastic_Out :
    {
      aFrame = 1.000000f - aFrame;
      aFrame = 1.000000f - ((( aFrame * aFrame ) * aFrame ) * EwMathSin(( aFrame 
      * 90.000000f ) * 13.000000f ));
    }
    break;

    case EffectsTimingElastic_InOut :
    {
      aFrame = aFrame * 2.000000f;

      if ( aFrame < 1.000000f )
      {
        aFrame = (( aFrame * aFrame ) * aFrame ) * EwMathSin(( aFrame * 90.000000f ) 
        * 13.000000f );
        aFrame = aFrame * 0.500000f;
      }
      else
      {
        aFrame = 2.000000f - aFrame;
        aFrame = (( aFrame * aFrame ) * aFrame ) * EwMathSin(( aFrame * 90.000000f ) 
        * 13.000000f );
        aFrame = ( 2.000000f - aFrame ) * 0.500000f;
      }
    }
    break;

    case EffectsTimingBounce_In :
    {
      EffectsTimingList list = _this->timingList;
      XInt32 i = 0;
      XFloat t1 = 0.000000f;
      XFloat t2 = list->spans[ 0 ];
      XFloat t = 1.000000f - aFrame;

      while ( t > t2 )
      {
        i = i + 1;
        t1 = t2;
        t2 = t2 + list->spans[ EwCheckIndex( i, 12 )];
      }

      aFrame = ( t - t1 ) / ( t2 - t1 );

      if ( i == 0 )
        aFrame = 1.000000f - ( aFrame * aFrame );
      else
      {
        aFrame = ( 2.000000f * aFrame ) - 1.000000f;
        aFrame = list->amps[ EwCheckIndex( i, 12 )] * ( 1.000000f - ( aFrame * aFrame ));
      }
    }
    break;

    case EffectsTimingBounce_Out :
    {
      EffectsTimingList list = _this->timingList;
      XInt32 i = 0;
      XFloat t1 = 0.000000f;
      XFloat t2 = list->spans[ 0 ];

      while ( aFrame > t2 )
      {
        i = i + 1;
        t1 = t2;
        t2 = t2 + list->spans[ EwCheckIndex( i, 12 )];
      }

      aFrame = ( aFrame - t1 ) / ( t2 - t1 );

      if ( i == 0 )
        aFrame = aFrame * aFrame;
      else
      {
        aFrame = ( 2.000000f * aFrame ) - 1.000000f;
        aFrame = 1.000000f - ( list->amps[ EwCheckIndex( i, 12 )] * ( 1.000000f 
        - ( aFrame * aFrame )));
      }
    }
    break;

    case EffectsTimingBounce_InOut :
    {
      EffectsTimingList list = _this->timingList;
      XInt32 i = 0;
      XFloat t1 = 0.000000f;
      XFloat t2 = list->spans[ 0 ];
      XFloat f = aFrame * 2.000000f;
      XFloat t = f - 1.000000f;

      if ( f < 1.000000f )
        t = -t;

      while ( t > t2 )
      {
        i = i + 1;
        t1 = t2;
        t2 = t2 + list->spans[ EwCheckIndex( i, 12 )];
      }

      t = ( t - t1 ) / ( t2 - t1 );

      if ( i == 0 )
        t = t * t;
      else
      {
        t = ( 2.000000f * t ) - 1.000000f;
        t = 1.000000f - ( list->amps[ EwCheckIndex( i, 12 )] * ( 1.000000f - ( t 
        * t )));
      }

      if ( f < 1.000000f )
        aFrame = 0.500000f * ( 1.000000f - t );
      else
        aFrame = 0.500000f * ( 1.000000f + t );
    }
    break;

    default : 
      if ( _this->useBezier2 )
      {
        XFloat f = aFrame;
        XFloat nf = 1.000000f - f;
        aFrame = (( nf * f ) * ( _this->curveFactor1 + 1.000000f )) + ( f * f );
      }
      else
        if ( _this->useBezier3 )
        {
          XFloat f = aFrame;
          XFloat nf = 1.000000f - f;
          XFloat f2 = f * f;
          XFloat nf2 = nf * nf;
          aFrame = ((( nf2 * f ) * ( _this->curveFactor1 + 1.000000f )) + (( nf 
          * f2 ) * ( _this->curveFactor2 + 2.000000f ))) + ( f2 * f );
        }
  }

  EffectsEffect__Animate( _this, aFrame );
  EwSignal( _this->OnAnimate, ((XObject)_this ));
}

/* 'C' function for method : 'Effects::Effect.runRevRev()' */
XBool EffectsEffect_runRevRev( EffectsEffect _this )
{
  XInt32 time = (XInt32)( _this->timer->Time - _this->startTime );
  XInt32 period0;
  XInt32 periodN;
  XBool done;
  XFloat frame;

  if ( time < 0 )
    time = -time;

  period0 = _this->CycleDuration;
  periodN = _this->CycleDuration;
  done = 0;
  frame = _this->lastFrame;

  if (( _this->cycleCounter == 0 ) && ( time >= period0 ))
  {
    _this->cycleCounter = 1;
    time = time - period0;
    _this->startTime = _this->startTime + period0;
  }

  if (( _this->cycleCounter > 0 ) && ( time >= periodN ))
  {
    XInt32 cycles = time / periodN;
    _this->cycleCounter = _this->cycleCounter + cycles;
    time = time - ( cycles * periodN );
    _this->startTime = _this->startTime + ( cycles * periodN );
  }

  if (( _this->cycleCounter > 2 ) && ( _this->NoOfCycles == 0 ))
    _this->cycleCounter = 1;

  if (( _this->cycleCounter >= _this->NoOfCycles ) && ( _this->NoOfCycles > 0 ))
  {
    done = 1;
    frame = 0.000000f;
  }
  else
    if ( time >= 0 )
      frame = 1.000000f - ((XFloat)time * _this->invCycleDuration );
    else
      if ( frame >= 0.000000f )
        frame = 0.000000f;

  if ( frame != _this->lastFrame )
  {
    _this->lastFrame = frame;
    EffectsEffect_run( _this, frame );
  }

  return done;
}

/* 'C' function for method : 'Effects::Effect.runRevFwd()' */
XBool EffectsEffect_runRevFwd( EffectsEffect _this )
{
  XInt32 time = (XInt32)( _this->startTime - _this->timer->Time );
  XInt32 period0 = _this->CycleDuration;
  XInt32 periodN = _this->CycleDuration;
  XBool done = 0;
  XFloat frame = _this->lastFrame;

  if (( _this->cycleCounter > 1 ) && ( time < 0 ))
  {
    XInt32 cycles = (( -time + periodN ) - 1 ) / periodN;

    if (( _this->cycleCounter - cycles ) <= 0 )
      cycles = _this->cycleCounter - 1;

    _this->cycleCounter = _this->cycleCounter - cycles;
    time = time + ( cycles * periodN );
    _this->startTime = _this->startTime + ( cycles * periodN );
  }

  if ((( _this->cycleCounter == 1 ) && ( time < 0 )) && ( _this->NoOfCycles > 0 ))
  {
    _this->cycleCounter = 0;
    time = time + period0;
    _this->startTime = _this->startTime + period0;
  }

  if ((( _this->cycleCounter == 1 ) && ( time < 0 )) && ( _this->NoOfCycles == 0 ))
  {
    XInt32 cycles = (( -time + periodN ) - 1 ) / periodN;
    time = time + ( cycles * periodN );
    _this->startTime = _this->startTime + ( cycles * periodN );
  }

  if ( time < 0 )
  {
    done = 1;
    frame = 1.000000f;
  }
  else
    if ( time >= 0 )
      frame = 1.000000f - ((XFloat)time * _this->invCycleDuration );
    else
      if ( frame >= 0.000000f )
        frame = 1.000000f;

  if ( frame != _this->lastFrame )
  {
    _this->lastFrame = frame;
    EffectsEffect_run( _this, frame );
  }

  return done;
}

/* 'C' function for method : 'Effects::Effect.runFwdRev()' */
XBool EffectsEffect_runFwdRev( EffectsEffect _this )
{
  XInt32 time = (XInt32)( _this->startTime - _this->timer->Time );
  XInt32 period0 = _this->CycleDuration;
  XInt32 periodN = _this->CycleDuration;
  XBool done = 0;
  XFloat frame = _this->lastFrame;

  if (( _this->cycleCounter > 1 ) && ( time < 0 ))
  {
    XInt32 cycles = (( -time + periodN ) - 1 ) / periodN;

    if (( _this->cycleCounter - cycles ) <= 0 )
      cycles = _this->cycleCounter - 1;

    _this->cycleCounter = _this->cycleCounter - cycles;
    time = time + ( cycles * periodN );
    _this->startTime = _this->startTime + ( cycles * periodN );
  }

  if ((( _this->cycleCounter == 1 ) && ( time < 0 )) && ( _this->NoOfCycles > 0 ))
  {
    _this->cycleCounter = 0;
    time = time + period0;
    _this->startTime = _this->startTime + period0;
  }

  if ((( _this->cycleCounter == 1 ) && ( time < 0 )) && ( _this->NoOfCycles == 0 ))
  {
    XInt32 cycles = (( -time + periodN ) - 1 ) / periodN;
    time = time + ( cycles * periodN );
    _this->startTime = _this->startTime + ( cycles * periodN );
  }

  if ( time < 0 )
  {
    done = 1;
    frame = 0.000000f;
  }
  else
    if ( time >= 0 )
      frame = (XFloat)time * _this->invCycleDuration;
    else
      if ( frame >= 0.000000f )
        frame = 0.000000f;

  if ( frame != _this->lastFrame )
  {
    _this->lastFrame = frame;
    EffectsEffect_run( _this, frame );
  }

  return done;
}

/* 'C' function for method : 'Effects::Effect.runFwdFwd()' */
XBool EffectsEffect_runFwdFwd( EffectsEffect _this )
{
  XInt32 time = (XInt32)( _this->timer->Time - _this->startTime );
  XInt32 period0;
  XInt32 periodN;
  XBool done;
  XFloat frame;

  if ( time < 0 )
    time = -time;

  period0 = _this->CycleDuration;
  periodN = _this->CycleDuration;
  done = 0;
  frame = _this->lastFrame;

  if (( _this->cycleCounter == 0 ) && ( time >= period0 ))
  {
    _this->cycleCounter = 1;
    time = time - period0;
    _this->startTime = _this->startTime + period0;
  }

  if (( _this->cycleCounter > 0 ) && ( time >= periodN ))
  {
    XInt32 cycles = time / periodN;
    _this->cycleCounter = _this->cycleCounter + cycles;
    time = time - ( cycles * periodN );
    _this->startTime = _this->startTime + ( cycles * periodN );
  }

  if (( _this->cycleCounter > 2 ) && ( _this->NoOfCycles == 0 ))
    _this->cycleCounter = 1;

  if (( _this->cycleCounter >= _this->NoOfCycles ) && ( _this->NoOfCycles > 0 ))
  {
    done = 1;
    frame = 1.000000f;
  }
  else
    if ( time >= 0 )
      frame = (XFloat)time * _this->invCycleDuration;
    else
      if ( frame >= 0.000000f )
        frame = 1.000000f;

  if ( frame != _this->lastFrame )
  {
    _this->lastFrame = frame;
    EffectsEffect_run( _this, frame );
  }

  return done;
}

/* 'C' function for method : 'Effects::Effect.OnSetTiming()' */
void EffectsEffect_OnSetTiming( EffectsEffect _this, XEnum value )
{
  if ( _this->Timing == value )
    return;

  _this->Timing = value;
  _this->timingList = 0;

  switch ( value )
  {
    case EffectsTimingEaseIn_EaseOut :
    {
      _this->curveFactor1 = -1.100000f;
      _this->curveFactor2 = 1.100000f;
    }
    break;

    case EffectsTimingEaseIn_FastOut :
    {
      _this->curveFactor1 = -1.000000f;
      _this->curveFactor2 = -2.000000f;
    }
    break;

    case EffectsTimingFastIn_EaseOut :
    {
      _this->curveFactor1 = 2.000000f;
      _this->curveFactor2 = 1.000000f;
    }
    break;

    case EffectsTimingFastIn_FastOut :
    {
      _this->curveFactor1 = 1.100000f;
      _this->curveFactor2 = -1.100000f;
    }
    break;

    case EffectsTimingLinear :
    {
      _this->curveFactor1 = 0.000000f;
      _this->curveFactor2 = 0.000000f;
    }
    break;

    default : 
    {
      _this->curveFactor1 = 0.000000f;
      _this->curveFactor2 = 0.000000f;
    }
  }

  _this->useBezier2 = (XBool)(( _this->curveFactor1 == _this->curveFactor2 ) && 
  ( _this->curveFactor1 != 0.000000f ));
  _this->useBezier3 = (XBool)( !_this->useBezier2 && ( _this->curveFactor1 != _this->curveFactor2 ));
}

/* 'C' function for method : 'Effects::Effect.OnSetNoOfCycles()' */
void EffectsEffect_OnSetNoOfCycles( EffectsEffect _this, XInt32 value )
{
  if ( value < 0 )
    value = 0;

  _this->NoOfCycles = value;
}

/* 'C' function for method : 'Effects::Effect.OnSetCycleDuration()' */
void EffectsEffect_OnSetCycleDuration( EffectsEffect _this, XInt32 value )
{
  if ( value < 15 )
    value = 15;

  _this->CycleDuration = value;
  _this->invCycleDuration = 1.000000f / (XFloat)value;
}

/* 'C' function for method : 'Effects::Effect.OnSetEnabled()' */
void EffectsEffect_OnSetEnabled( EffectsEffect _this, XBool value )
{
  if ( _this->Enabled == value )
    return;

  _this->Enabled = value;

  if ( !value && ( _this->timer != 0 ))
  {
    EwDetachObjObserver( EwNewSlot( _this, EffectsEffect_timerSlot ), (XObject)_this->timer, 
      0 );
    _this->timer = 0;
  }

  if ( value )
  {
    _this->timer = ((CoreTimer)EwGetAutoObject( &EffectsEffectTimer, EffectsEffectTimerClass ));
    EwAttachObjObserver( EwNewSlot( _this, EffectsEffect_timerSlot ), (XObject)_this->timer, 
      0 );
    _this->startDirection = 0;
    EwPostSignal( EwNewSlot( _this, EffectsEffect_timerSlot ), ((XObject)_this ));
  }
}

/* 'C' function for method : 'Effects::Effect.Animate()' */
void EffectsEffect_Animate( EffectsEffect _this, XFloat aProgress )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
  EW_UNUSED_ARG( aProgress );
}

/* Wrapper function for the virtual method : 'Effects::Effect.Animate()' */
void EffectsEffect__Animate( void* _this, XFloat aProgress )
{
  ((EffectsEffect)_this)->_.VMT->Animate((EffectsEffect)_this, aProgress );
}

/* Variants derived from the class : 'Effects::Effect' */
EW_DEFINE_CLASS_VARIANTS( EffectsEffect )
EW_END_OF_CLASS_VARIANTS( EffectsEffect )

/* Virtual Method Table (VMT) for the class : 'Effects::Effect' */
EW_DEFINE_CLASS( EffectsEffect, XObject, timingList, OnFinished, direction, direction, 
                 direction, direction, "Effects::Effect" )
  EffectsEffect_Animate,
EW_END_OF_CLASS( EffectsEffect )

/* Initializer for the class 'Effects::FloatEffect' */
void EffectsFloatEffect__Init( EffectsFloatEffect _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  EffectsEffect__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( EffectsFloatEffect );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( EffectsFloatEffect );

  /* ... and initialize objects, variables, properties, etc. */
  _this->Value2 = 1.000000f;
}

/* Re-Initializer for the class 'Effects::FloatEffect' */
void EffectsFloatEffect__ReInit( EffectsFloatEffect _this )
{
  /* At first re-initialize the super class ... */
  EffectsEffect__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Effects::FloatEffect' */
void EffectsFloatEffect__Done( EffectsFloatEffect _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( EffectsEffect );

  /* Don't forget to deinitialize the super class ... */
  EffectsEffect__Done( &_this->_.Super );
}

/* 'C' function for method : 'Effects::FloatEffect.Animate()' */
void EffectsFloatEffect_Animate( EffectsFloatEffect _this, XFloat aProgress )
{
  _this->Value = _this->Value1 + (( _this->Value2 - _this->Value1 ) * aProgress );
}

/* Variants derived from the class : 'Effects::FloatEffect' */
EW_DEFINE_CLASS_VARIANTS( EffectsFloatEffect )
EW_END_OF_CLASS_VARIANTS( EffectsFloatEffect )

/* Virtual Method Table (VMT) for the class : 'Effects::FloatEffect' */
EW_DEFINE_CLASS( EffectsFloatEffect, EffectsEffect, _.VMT, _.VMT, _.VMT, _.VMT, 
                 _.VMT, _.VMT, "Effects::FloatEffect" )
  EffectsFloatEffect_Animate,
EW_END_OF_CLASS( EffectsFloatEffect )

/* Initializer for the class 'Effects::Fader' */
void EffectsFader__Init( EffectsFader _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( EffectsFader );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( EffectsFader );

  /* ... and initialize objects, variables, properties, etc. */
  _this->RemoveIfHidden = 1;
  _this->RestackTopmost = 1;
  _this->AssignFocus = 1;
  _this->UseCurrentState = 1;
  _this->Enabled = 1;
  _this->Visible = 1;
}

/* Re-Initializer for the class 'Effects::Fader' */
void EffectsFader__ReInit( EffectsFader _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Effects::Fader' */
void EffectsFader__Done( EffectsFader _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( XObject );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_.Super );
}

/* The method Complete() is intended to be called by the implementation of your 
   adapted fader as soon as the animation effects used inside the fader has finalized 
   their work. This is essential in order to ensure, that next faders waiting for 
   execution can start with their animations. */
void EffectsFader_Complete( EffectsFader _this )
{
  if ( _this->task != 0 )
    CoreTask__Complete( _this->task );
}

/* The method IsFinished() should return 'true' if the fader has finalized its fading 
   animation and 'false' if the animation is not started or it is still in progress. 
   This method should therefore be overridden in derived classes to evaluate the 
   state of animation effects used inside the fader. */
XBool EffectsFader_IsFinished( EffectsFader _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  return 1;
}

/* Wrapper function for the virtual method : 'Effects::Fader.IsFinished()' */
XBool EffectsFader__IsFinished( void* _this )
{
  return ((EffectsFader)_this)->_.VMT->IsFinished((EffectsFader)_this );
}

/* The method OnEnd() is invoked automatically just in the moment, when this fader 
   and all other faders belonging to the same fading task have signaled that they 
   are finished with their animations. The default implementation of this method 
   simply does nothing.
   Derived classes can override this method and implement there the code to complete 
   the animation (e.g. to remove the group from its owner after it has been faded-out, 
   etc.). The implementation of the overridden OnEnd() method has to use the variables 
   @Group and @Owner to determine on which group the fader has applied the animation. 
   Depending on the kind of the implemented animation, the OnEnd() method can also 
   evaluate the properties @UseCurrentState, @AssignFocus and @RestackTopmost. */
void EffectsFader_OnEnd( EffectsFader _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );
}

/* Wrapper function for the virtual method : 'Effects::Fader.OnEnd()' */
void EffectsFader__OnEnd( void* _this )
{
  ((EffectsFader)_this)->_.VMT->OnEnd((EffectsFader)_this );
}

/* The method OnStart() is invoked automatically just in the moment, when the fader 
   is triggered to begin its animation. The default implementation of this method 
   simply calls the @Complete() method indicating so, that the fader is done with 
   its work. Thereupon the next fader waiting for its execution can start.
   Derived classes should override this method and implement there the code to prepare 
   and start the desired fade-in/out animation effects. The implementation of the 
   overridden OnStart() method has to use the variables @Group and @Owner to determine 
   on which group the fader should apply the animation. Depending on the kind of 
   the implemented animation, the OnStart() method can also evaluate the properties 
   @UseCurrentState, @AssignFocus and @RestackTopmost.
   Please note, if there is a slot method associated to the property @OnInitialize, 
   this slot method is signaled shortly before the method OnStart() is executed 
   given the slot method a possibility to apply more individual initialization steps 
   on the fader just before the animation begins.
   When the animation reaches its end (e.g. when the animation effects used inside 
   the fader do terminate), your implementation of the fader should invoke the method 
   @Complete() otherwise the animation is considered as still being in progress 
   causing other pending faders to wait. */
void EffectsFader_OnStart( EffectsFader _this )
{
  EffectsFader_Complete( _this );
}

/* Wrapper function for the virtual method : 'Effects::Fader.OnStart()' */
void EffectsFader__OnStart( void* _this )
{
  ((EffectsFader)_this)->_.VMT->OnStart((EffectsFader)_this );
}

/* Variants derived from the class : 'Effects::Fader' */
EW_DEFINE_CLASS_VARIANTS( EffectsFader )
EW_END_OF_CLASS_VARIANTS( EffectsFader )

/* Virtual Method Table (VMT) for the class : 'Effects::Fader' */
EW_DEFINE_CLASS( EffectsFader, XObject, task, onCancel, Visible, Visible, Visible, 
                 Visible, "Effects::Fader" )
  EffectsFader_IsFinished,
  EffectsFader_OnEnd,
  EffectsFader_OnStart,
EW_END_OF_CLASS( EffectsFader )

/* Initializer for the class 'Effects::VisibilityFader' */
void EffectsVisibilityFader__Init( EffectsVisibilityFader _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  EffectsFader__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( EffectsVisibilityFader );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( EffectsVisibilityFader );

  /* ... and initialize objects, variables, properties, etc. */
}

/* Re-Initializer for the class 'Effects::VisibilityFader' */
void EffectsVisibilityFader__ReInit( EffectsVisibilityFader _this )
{
  /* At first re-initialize the super class ... */
  EffectsFader__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Effects::VisibilityFader' */
void EffectsVisibilityFader__Done( EffectsVisibilityFader _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( EffectsFader );

  /* Don't forget to deinitialize the super class ... */
  EffectsFader__Done( &_this->_.Super );
}

/* The method IsFinished() should return 'true' if the fader has finalized its fading 
   animation and 'false' if the animation is not started or it is still in progress. 
   This method should therefore be overridden in derived classes to evaluate the 
   state of animation effects used inside the fader. */
XBool EffectsVisibilityFader_IsFinished( EffectsVisibilityFader _this )
{
  return _this->finished;
}

/* The method OnEnd() is invoked automatically just in the moment, when this fader 
   and all other faders belonging to the same fading task have signaled that they 
   are finished with their animations. The default implementation of this method 
   simply does nothing.
   Derived classes can override this method and implement there the code to complete 
   the animation (e.g. to remove the group from its owner after it has been faded-out, 
   etc.). The implementation of the overridden OnEnd() method has to use the variables 
   @Group and @Owner to determine on which group the fader has applied the animation. 
   Depending on the kind of the implemented animation, the OnEnd() method can also 
   evaluate the properties @UseCurrentState, @AssignFocus and @RestackTopmost. */
void EffectsVisibilityFader_OnEnd( EffectsVisibilityFader _this )
{
  if ( !_this->Super1.Visible && ( _this->Super1.Group->Super2.Owner != 0 ))
    CoreGroup_OnSetVisible( _this->Super1.Group, 0 );

  if (( !_this->Super1.Visible && _this->Super1.RemoveIfHidden ) && ( _this->Super1.Group->Super2.Owner 
      != 0 ))
    CoreGroup_Remove( _this->Super1.Group->Super2.Owner, ((CoreView)_this->Super1.Group ));

  if ( !_this->Super1.Enabled )
    CoreGroup_OnSetEnabled( _this->Super1.Group, 0 );
}

/* The method OnStart() is invoked automatically just in the moment, when the fader 
   is triggered to begin its animation. The default implementation of this method 
   simply calls the @Complete() method indicating so, that the fader is done with 
   its work. Thereupon the next fader waiting for its execution can start.
   Derived classes should override this method and implement there the code to prepare 
   and start the desired fade-in/out animation effects. The implementation of the 
   overridden OnStart() method has to use the variables @Group and @Owner to determine 
   on which group the fader should apply the animation. Depending on the kind of 
   the implemented animation, the OnStart() method can also evaluate the properties 
   @UseCurrentState, @AssignFocus and @RestackTopmost.
   Please note, if there is a slot method associated to the property @OnInitialize, 
   this slot method is signaled shortly before the method OnStart() is executed 
   given the slot method a possibility to apply more individual initialization steps 
   on the fader just before the animation begins.
   When the animation reaches its end (e.g. when the animation effects used inside 
   the fader do terminate), your implementation of the fader should invoke the method 
   @Complete() otherwise the animation is considered as still being in progress 
   causing other pending faders to wait. */
void EffectsVisibilityFader_OnStart( EffectsVisibilityFader _this )
{
  if ( _this->Super1.Enabled )
    CoreGroup_OnSetEnabled( _this->Super1.Group, 1 );

  if (( _this->Super1.Visible || _this->Super1.AddToOwner ) && ( _this->Super1.Group->Super2.Owner 
      == 0 ))
  {
    CoreGroup_OnSetVisible( _this->Super1.Group, 0 );
    CoreGroup_Add( _this->Super1.Owner, ((CoreView)_this->Super1.Group ), 0 );
  }

  if ( _this->Super1.Visible && _this->Super1.RestackTopmost )
    CoreGroup_RestackTop( _this->Super1.Group->Super2.Owner, ((CoreView)_this->Super1.Group ));

  if ( _this->Super1.Visible && _this->Super1.AssignFocus )
    CoreGroup__OnSetFocus( _this->Super1.Group->Super2.Owner, ((CoreView)_this->Super1.Group ));

  if ( _this->Super1.Visible && !_this->Super1.UseCurrentState )
    CoreRectView__OnSetBounds( _this->Super1.Group, EwSetRectOrigin( _this->Super1.Group->Super1.Bounds, 
    _this->Position ));

  if ( _this->Super1.Visible )
  {
    CoreGroup__OnSetOpacity( _this->Super1.Group, 255 );
    CoreGroup_OnSetVisible( _this->Super1.Group, 1 );
  }

  if ( !_this->Super1.Visible && ( _this->Super1.Owner->Focus == (CoreView)_this->Super1.Group ))
    CoreGroup__OnSetFocus( _this->Super1.Owner, 0 );

  _this->finished = 1;
  EffectsFader_Complete((EffectsFader)_this );
}

/* Variants derived from the class : 'Effects::VisibilityFader' */
EW_DEFINE_CLASS_VARIANTS( EffectsVisibilityFader )
EW_END_OF_CLASS_VARIANTS( EffectsVisibilityFader )

/* Virtual Method Table (VMT) for the class : 'Effects::VisibilityFader' */
EW_DEFINE_CLASS( EffectsVisibilityFader, EffectsFader, _.VMT, _.VMT, _.VMT, _.VMT, 
                 _.VMT, _.VMT, "Effects::VisibilityFader" )
  EffectsVisibilityFader_IsFinished,
  EffectsVisibilityFader_OnEnd,
  EffectsVisibilityFader_OnStart,
EW_END_OF_CLASS( EffectsVisibilityFader )

/* Initializer for the class 'Effects::Transition' */
void EffectsTransition__Init( EffectsTransition _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( EffectsTransition );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( EffectsTransition );
}

/* Re-Initializer for the class 'Effects::Transition' */
void EffectsTransition__ReInit( EffectsTransition _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Effects::Transition' */
void EffectsTransition__Done( EffectsTransition _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( XObject );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_.Super );
}

/* The method CreatePresentFader() creates an object of one of the classes descending 
   from Effects::Fader and configures it with parameters according to the desired 
   fade-in (present) transition. Finally the prepared fader object is returned to 
   the caller. Typically, the created fader is used to show (to present) a GUI component 
   when the user navigates to it. The method has to be overridden and implemented 
   in derived classes. The actual implementation does nothing and returns 'null'. */
EffectsFader EffectsTransition_CreatePresentFader( EffectsTransition _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  return 0;
}

/* Wrapper function for the virtual method : 'Effects::Transition.CreatePresentFader()' */
EffectsFader EffectsTransition__CreatePresentFader( void* _this )
{
  return ((EffectsTransition)_this)->_.VMT->CreatePresentFader((EffectsTransition)_this );
}

/* The method CreateDismissFader() creates an object of one of the classes descending 
   from Effects::Fader and configures it with parameters according to the desired 
   fade-out (dismiss) transition. Finally the prepared fader object is returned 
   to the caller. Typically, the created fader is used to hide (to dismiss) a GUI 
   component when the user leaves it while he/she navigates in the GUI system. The 
   method has to be overridden and implemented in derived classes. The actual implementation 
   does nothing and returns 'null'. */
EffectsFader EffectsTransition_CreateDismissFader( EffectsTransition _this )
{
  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  return 0;
}

/* Wrapper function for the virtual method : 'Effects::Transition.CreateDismissFader()' */
EffectsFader EffectsTransition__CreateDismissFader( void* _this )
{
  return ((EffectsTransition)_this)->_.VMT->CreateDismissFader((EffectsTransition)_this );
}

/* The method CreateRestoreFader() creates an object of one of the classes descending 
   from Effects::Fader and configures it with parameters according to the desired 
   fade-in (restore) transition. Finally the prepared fader object is returned to 
   the caller. Typically, the created fader is used to show (to restore the original 
   visible state) of a GUI component, which has been obscured (overlaid) by other 
   GUI components during the user navigates in the GUI system. The method has to 
   be overridden and implemented in derived classes. The actual implementation of 
   this method redirects the operation to the method @CreatePresentFader(). */
EffectsFader EffectsTransition_CreateRestoreFader( EffectsTransition _this )
{
  return EffectsTransition__CreatePresentFader( _this );
}

/* Wrapper function for the virtual method : 'Effects::Transition.CreateRestoreFader()' */
EffectsFader EffectsTransition__CreateRestoreFader( void* _this )
{
  return ((EffectsTransition)_this)->_.VMT->CreateRestoreFader((EffectsTransition)_this );
}

/* The method CreateOverlayFader() creates an object of one of the classes descending 
   from Effects::Fader and configures it with parameters according to the desired 
   fade-out (overlay) transition. Finally the prepared fader object is returned 
   to the caller. Typically, the created fader is used to temporarily hide (to overlay) 
   a GUI component when the user navigates a deeper level in the GUI system. The 
   method has to be overridden and implemented in derived classes. The actual implementation 
   of this method redirects the operation to the method @CreateDismissFader(). */
EffectsFader EffectsTransition_CreateOverlayFader( EffectsTransition _this )
{
  return EffectsTransition__CreateDismissFader( _this );
}

/* Wrapper function for the virtual method : 'Effects::Transition.CreateOverlayFader()' */
EffectsFader EffectsTransition__CreateOverlayFader( void* _this )
{
  return ((EffectsTransition)_this)->_.VMT->CreateOverlayFader((EffectsTransition)_this );
}

/* Variants derived from the class : 'Effects::Transition' */
EW_DEFINE_CLASS_VARIANTS( EffectsTransition )
EW_END_OF_CLASS_VARIANTS( EffectsTransition )

/* Virtual Method Table (VMT) for the class : 'Effects::Transition' */
EW_DEFINE_CLASS( EffectsTransition, XObject, _.VMT, _.VMT, _.VMT, _.VMT, _.VMT, 
                 _.VMT, "Effects::Transition" )
  EffectsTransition_CreatePresentFader,
  EffectsTransition_CreateDismissFader,
  EffectsTransition_CreateRestoreFader,
  EffectsTransition_CreateOverlayFader,
EW_END_OF_CLASS( EffectsTransition )

/* Initializer for the class 'Effects::ShowHideTransition' */
void EffectsShowHideTransition__Init( EffectsShowHideTransition _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  EffectsTransition__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( EffectsShowHideTransition );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( EffectsShowHideTransition );

  /* ... and initialize objects, variables, properties, etc. */
}

/* Re-Initializer for the class 'Effects::ShowHideTransition' */
void EffectsShowHideTransition__ReInit( EffectsShowHideTransition _this )
{
  /* At first re-initialize the super class ... */
  EffectsTransition__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Effects::ShowHideTransition' */
void EffectsShowHideTransition__Done( EffectsShowHideTransition _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( EffectsTransition );

  /* Don't forget to deinitialize the super class ... */
  EffectsTransition__Done( &_this->_.Super );
}

/* The method CreatePresentFader() creates an object of one of the classes descending 
   from Effects::Fader and configures it with parameters according to the desired 
   fade-in (present) transition. Finally the prepared fader object is returned to 
   the caller. Typically, the created fader is used to show (to present) a GUI component 
   when the user navigates to it. The method has to be overridden and implemented 
   in derived classes. The actual implementation does nothing and returns 'null'. */
EffectsFader EffectsShowHideTransition_CreatePresentFader( EffectsShowHideTransition _this )
{
  EffectsVisibilityFader fader = EwNewObject( EffectsVisibilityFader, 0 );

  fader->Super1.Visible = 1;
  fader->Super1.Enabled = 1;
  fader->Super1.AssignFocus = 0;
  fader->Super1.RestackTopmost = 1;
  fader->Super1.UseCurrentState = 0;
  fader->Super1.OnInitialize = EwNewSlot( _this, EffectsShowHideTransition_onInitializeIn );
  return ((EffectsFader)fader );
}

/* The method CreateDismissFader() creates an object of one of the classes descending 
   from Effects::Fader and configures it with parameters according to the desired 
   fade-out (dismiss) transition. Finally the prepared fader object is returned 
   to the caller. Typically, the created fader is used to hide (to dismiss) a GUI 
   component when the user leaves it while he/she navigates in the GUI system. The 
   method has to be overridden and implemented in derived classes. The actual implementation 
   does nothing and returns 'null'. */
EffectsFader EffectsShowHideTransition_CreateDismissFader( EffectsShowHideTransition _this )
{
  EffectsVisibilityFader fader;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  fader = EwNewObject( EffectsVisibilityFader, 0 );
  fader->Super1.Visible = 0;
  fader->Super1.Enabled = 0;
  fader->Super1.RemoveIfHidden = 1;
  return ((EffectsFader)fader );
}

/* The method CreateRestoreFader() creates an object of one of the classes descending 
   from Effects::Fader and configures it with parameters according to the desired 
   fade-in (restore) transition. Finally the prepared fader object is returned to 
   the caller. Typically, the created fader is used to show (to restore the original 
   visible state) of a GUI component, which has been obscured (overlaid) by other 
   GUI components during the user navigates in the GUI system. The method has to 
   be overridden and implemented in derived classes. The actual implementation of 
   this method redirects the operation to the method @CreatePresentFader(). */
EffectsFader EffectsShowHideTransition_CreateRestoreFader( EffectsShowHideTransition _this )
{
  EffectsFader fader = EffectsTransition_CreateRestoreFader((EffectsTransition)_this );

  fader->RestackTopmost = 0;
  fader->Enabled = 1;
  return fader;
}

/* The method CreateOverlayFader() creates an object of one of the classes descending 
   from Effects::Fader and configures it with parameters according to the desired 
   fade-out (overlay) transition. Finally the prepared fader object is returned 
   to the caller. Typically, the created fader is used to temporarily hide (to overlay) 
   a GUI component when the user navigates a deeper level in the GUI system. The 
   method has to be overridden and implemented in derived classes. The actual implementation 
   of this method redirects the operation to the method @CreateDismissFader(). */
EffectsFader EffectsShowHideTransition_CreateOverlayFader( EffectsShowHideTransition _this )
{
  EffectsVisibilityFader fader;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  fader = EwNewObject( EffectsVisibilityFader, 0 );
  fader->Super1.Visible = 0;
  fader->Super1.Enabled = 1;
  fader->Super1.AddToOwner = 1;
  fader->Super1.RemoveIfHidden = 0;
  return ((EffectsFader)fader );
}

/* 'C' function for method : 'Effects::ShowHideTransition.onInitializeIn()' */
void EffectsShowHideTransition_onInitializeIn( EffectsShowHideTransition _this, 
  XObject sender )
{
  EffectsVisibilityFader fader;
  XRect bounds;
  XPoint size;
  XPoint pos;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( _this );

  fader = EwCastObject( sender, EffectsVisibilityFader );
  bounds = EwGetRectORect( fader->Super1.Owner->Super1.Bounds );
  size = EwGetRectSize( fader->Super1.Group->Super1.Bounds );
  pos = bounds.Point1;
  pos.X = (( bounds.Point1.X + ( EwGetRectW( bounds ) / 2 )) - ( size.X / 2 ));
  pos.Y = (( bounds.Point1.Y + ( EwGetRectH( bounds ) / 2 )) - ( size.Y / 2 ));
  fader->Position = pos;
}

/* Variants derived from the class : 'Effects::ShowHideTransition' */
EW_DEFINE_CLASS_VARIANTS( EffectsShowHideTransition )
EW_END_OF_CLASS_VARIANTS( EffectsShowHideTransition )

/* Virtual Method Table (VMT) for the class : 'Effects::ShowHideTransition' */
EW_DEFINE_CLASS( EffectsShowHideTransition, EffectsTransition, _.VMT, _.VMT, _.VMT, 
                 _.VMT, _.VMT, _.VMT, "Effects::ShowHideTransition" )
  EffectsShowHideTransition_CreatePresentFader,
  EffectsShowHideTransition_CreateDismissFader,
  EffectsShowHideTransition_CreateRestoreFader,
  EffectsShowHideTransition_CreateOverlayFader,
EW_END_OF_CLASS( EffectsShowHideTransition )

/* Initializer for the class 'Effects::EffectTimerClass' */
void EffectsEffectTimerClass__Init( EffectsEffectTimerClass _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreTimer__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( EffectsEffectTimerClass );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( EffectsEffectTimerClass );
}

/* Re-Initializer for the class 'Effects::EffectTimerClass' */
void EffectsEffectTimerClass__ReInit( EffectsEffectTimerClass _this )
{
  /* At first re-initialize the super class ... */
  CoreTimer__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Effects::EffectTimerClass' */
void EffectsEffectTimerClass__Done( EffectsEffectTimerClass _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreTimer );

  /* Don't forget to deinitialize the super class ... */
  CoreTimer__Done( &_this->_.Super );
}

/* The method Trigger() will be invoked when the timer is expired (when the interval 
   defined in @Begin or @Period is elapsed). The method can be overridden and implemented 
   in derived classes. The default implementation of this method sends a signal 
   to the slot method stored in the @OnTrigger property. */
void EffectsEffectTimerClass_Trigger( EffectsEffectTimerClass _this )
{
  CoreTimer_Trigger((CoreTimer)_this );
  EwNotifyObjObservers((XObject)_this, 0 );
}

/* Variants derived from the class : 'Effects::EffectTimerClass' */
EW_DEFINE_CLASS_VARIANTS( EffectsEffectTimerClass )
EW_END_OF_CLASS_VARIANTS( EffectsEffectTimerClass )

/* Virtual Method Table (VMT) for the class : 'Effects::EffectTimerClass' */
EW_DEFINE_CLASS( EffectsEffectTimerClass, CoreTimer, _.VMT, _.VMT, _.VMT, _.VMT, 
                 _.VMT, _.VMT, "Effects::EffectTimerClass" )
  EffectsEffectTimerClass_Trigger,
EW_END_OF_CLASS( EffectsEffectTimerClass )

/* The global autoobject Effects::EffectTimer triggers all actually active animation 
   effects. In this way all effects will run simultanously. Per default the timer 
   is configured with 15 ms period (~60 FPS). By overriding the Effects::EffectTimer 
   autoobject by a variant you can specify another resolution to drive the animations. */
EW_DEFINE_AUTOOBJECT( EffectsEffectTimer, EffectsEffectTimerClass )

/* Initializer for the auto object 'Effects::EffectTimer' */
void EffectsEffectTimer__Init( EffectsEffectTimerClass _this )
{
  CoreTimer_OnSetPeriod((CoreTimer)_this, 15 );
  CoreTimer_OnSetEnabled((CoreTimer)_this, 1 );
}

/* Table with links to derived variants of the auto object : 'Effects::EffectTimer' */
EW_DEFINE_AUTOOBJECT_VARIANTS( EffectsEffectTimer )
EW_END_OF_AUTOOBJECT_VARIANTS( EffectsEffectTimer )

/* Initializer for the class 'Effects::TimingList' */
void EffectsTimingList__Init( EffectsTimingList _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  XObject__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( EffectsTimingList );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( EffectsTimingList );
}

/* Re-Initializer for the class 'Effects::TimingList' */
void EffectsTimingList__ReInit( EffectsTimingList _this )
{
  /* At first re-initialize the super class ... */
  XObject__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Effects::TimingList' */
void EffectsTimingList__Done( EffectsTimingList _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( XObject );

  /* Don't forget to deinitialize the super class ... */
  XObject__Done( &_this->_.Super );
}

/* Variants derived from the class : 'Effects::TimingList' */
EW_DEFINE_CLASS_VARIANTS( EffectsTimingList )
EW_END_OF_CLASS_VARIANTS( EffectsTimingList )

/* Virtual Method Table (VMT) for the class : 'Effects::TimingList' */
EW_DEFINE_CLASS( EffectsTimingList, XObject, _.VMT, _.VMT, _.VMT, _.VMT, _.VMT, 
                 _.VMT, "Effects::TimingList" )
EW_END_OF_CLASS( EffectsTimingList )

/* Initializer for the class 'Effects::FaderTask' */
void EffectsFaderTask__Init( EffectsFaderTask _this, XObject aLink, XHandle aArg )
{
  /* At first initialize the super class ... */
  CoreTask__Init( &_this->_.Super, aLink, aArg );

  /* Allow the Immediate Garbage Collection to evalute the members of this class. */
  _this->_.XObject._.GCT = EW_CLASS_GCT( EffectsFaderTask );

  /* Setup the VMT pointer */
  _this->_.VMT = EW_CLASS( EffectsFaderTask );
}

/* Re-Initializer for the class 'Effects::FaderTask' */
void EffectsFaderTask__ReInit( EffectsFaderTask _this )
{
  /* At first re-initialize the super class ... */
  CoreTask__ReInit( &_this->_.Super );
}

/* Finalizer method for the class 'Effects::FaderTask' */
void EffectsFaderTask__Done( EffectsFaderTask _this )
{
  /* Finalize this class */
  _this->_.Super._.VMT = EW_CLASS( CoreTask );

  /* Don't forget to deinitialize the super class ... */
  CoreTask__Done( &_this->_.Super );
}

/* The method OnComplete() is called when the task is done with its work. The default 
   implementation of this method does nothing. You can override this method in derived 
   task classes and implement what to do when the task is finished. For example, 
   you can release resources used temporarily during animations.
   To complete a task you should call explicitly the method @Complete(). The parameter 
   aQueue refers to the queue this task belonged to. It can be used e.g. to schedule 
   again a task to the same queue, etc. */
void EffectsFaderTask_OnComplete( EffectsFaderTask _this, CoreTaskQueue aQueue )
{
  EffectsFader fader;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aQueue );

  fader = _this->first;

  while ( fader != 0 )
  {
    EffectsFader__OnEnd( fader );
    fader->Group->Super2.viewState = fader->Group->Super2.viewState & ~CoreViewStateRunningFader;
    fader = fader->next;
  }

  fader = _this->first;

  while ( fader != 0 )
  {
    EwPostSignal( fader->onComplete, ((XObject)fader ));
    fader = fader->next;
  }
}

/* The method OnCancel() is called when the task is canceled after being started. 
   The default implementation of this method does nothing. You can override this 
   method in derived task classes and implement what to do when the task is prematurely 
   aborted. For example, you can stop running timers and effects started in the 
   preceding @OnStart() method.
   To cancel a task you should call explicitly the method @Cancel(). The parameter 
   aQueue refers to the queue this task belonged to. It can be used e.g. to schedule 
   again a task to the same queue, etc. */
void EffectsFaderTask_OnCancel( EffectsFaderTask _this, CoreTaskQueue aQueue )
{
  EffectsFader fader;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aQueue );

  fader = _this->first;

  while ( fader != 0 )
  {
    EwPostSignal( fader->onCancel, ((XObject)fader ));
    fader = fader->next;
  }

  _this->first = 0;
  _this->last = 0;
}

/* The method OnStart() is called at the begin of the execution of this task. The 
   default implementation of the method simply cancels the task causing the next 
   available task in the task queue to be started. You should override this method 
   in derived task classes to implement what the task should do.
   There are three typical application cases how to implement the OnStart() method:
   - In its simplest case the entire task algorithm is implemented in the OnStart() 
   method. In this case the method @Complete() should be called before leaving OnStart().
   - If the task does take long time for execution by using timers or effects, you 
   should put in OnStart() the code necessary to start the timers/effects. Don't 
   forget to call @Complete() when all timers/effects are done.
   - If the task is divided in many small execution steps, the OnStart() method 
   should call @Continue() to request the @OnContinue() method to be executed after 
   a short delay (usually after the next screen update). In @OnContinue() you can 
   perform the next step of the task. If necessary, @OnContinue() can also request 
   to be called again after a short delay. At the end of the task, after the last 
   step is terminated, don't forget to call @Complete().
   The parameter aQueue refers to the queue this task belongs to. It can be used 
   to schedule more task to execute later. */
void EffectsFaderTask_OnStart( EffectsFaderTask _this, CoreTaskQueue aQueue )
{
  EffectsFader fader;

  /* Dummy expressions to avoid the 'C' warning 'unused argument'. */
  EW_UNUSED_ARG( aQueue );

  if ( _this->first == 0 )
    CoreTask__Complete( _this );

  fader = _this->first;

  while ( fader != 0 )
  {
    fader->Group->Super2.viewState = ( fader->Group->Super2.viewState | CoreViewStateRunningFader ) 
    & ~CoreViewStatePendingFader;
    fader->Group->pendingFader = 0;
    fader = fader->next;
  }

  fader = _this->first;

  while ( fader != 0 )
  {
    EwSignal( fader->OnInitialize, ((XObject)fader ));
    EffectsFader__OnStart( fader );
    fader = fader->next;
  }
}

/* The method Complete() informs the task queue about the completion of this task. 
   Thereupon the next available task in the queue can be executed. This method is 
   usually called in context of the @OnStart() or @OnContinue() method when the 
   task has finalized its work. Calling the method for a not current task has no 
   effect. */
void EffectsFaderTask_Complete( EffectsFaderTask _this )
{
  EffectsFader fader = _this->first;

  while (( fader != 0 ) && EffectsFader__IsFinished( fader ))
    fader = fader->next;

  if ( fader == 0 )
    CoreTask_Complete((CoreTask)_this );
}

/* 'C' function for method : 'Effects::FaderTask.RemoveFader()' */
void EffectsFaderTask_RemoveFader( EffectsFaderTask _this, EffectsFader aFader )
{
  if ( aFader == 0 )
    return;

  if ( CoreTask_IsCurrent((CoreTask)_this ))
  {
    EwThrow( EwLoadString( &_Const0000 ));
    return;
  }

  if ( aFader->task != _this )
  {
    EwThrow( EwLoadString( &_Const0001 ));
    return;
  }

  if ( aFader->next != 0 )
    aFader->next->prev = aFader->prev;
  else
    _this->last = aFader->prev;

  if ( aFader->prev != 0 )
    aFader->prev->next = aFader->next;
  else
    _this->first = aFader->next;

  aFader->task = 0;
  aFader->next = 0;
  aFader->prev = 0;

  if ( aFader->Group != 0 )
    aFader->Group->pendingFader = 0;

  EwPostSignal( aFader->onCancel, ((XObject)aFader ));

  if ( _this->first == 0 )
    CoreTask_Cancel((CoreTask)_this );
}

/* 'C' function for method : 'Effects::FaderTask.AddFader()' */
void EffectsFaderTask_AddFader( EffectsFaderTask _this, EffectsFader aFader )
{
  if ( aFader == 0 )
    return;

  if ( CoreTask_IsCurrent((CoreTask)_this ))
  {
    EwThrow( EwLoadString( &_Const0002 ));
    return;
  }

  if ( aFader->task != 0 )
  {
    EwThrow( EwLoadString( &_Const0003 ));
    return;
  }

  aFader->prev = _this->last;
  aFader->next = 0;

  if ( _this->last != 0 )
    _this->last->next = aFader;
  else
    _this->first = aFader;

  _this->last = aFader;
  aFader->task = _this;
}

/* Variants derived from the class : 'Effects::FaderTask' */
EW_DEFINE_CLASS_VARIANTS( EffectsFaderTask )
EW_END_OF_CLASS_VARIANTS( EffectsFaderTask )

/* Virtual Method Table (VMT) for the class : 'Effects::FaderTask' */
EW_DEFINE_CLASS( EffectsFaderTask, CoreTask, last, _.VMT, _.VMT, _.VMT, _.VMT, _.VMT, 
                 "Effects::FaderTask" )
  EffectsFaderTask_OnComplete,
  EffectsFaderTask_OnCancel,
  EffectsFaderTask_OnStart,
  EffectsFaderTask_Complete,
EW_END_OF_CLASS( EffectsFaderTask )

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
EW_DEFINE_AUTOOBJECT( EffectsShowHideCentered, EffectsShowHideTransition )

/* Initializer for the auto object 'Effects::ShowHideCentered' */
void EffectsShowHideCentered__Init( EffectsShowHideTransition _this )
{
  EW_UNUSED_ARG( _this );
}

/* Table with links to derived variants of the auto object : 'Effects::ShowHideCentered' */
EW_DEFINE_AUTOOBJECT_VARIANTS( EffectsShowHideCentered )
EW_END_OF_AUTOOBJECT_VARIANTS( EffectsShowHideCentered )

/* Embedded Wizard */
