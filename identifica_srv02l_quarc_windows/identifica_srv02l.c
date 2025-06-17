/*
 * identifica_srv02l.c
 *
 * Real-Time Workshop code generation for Simulink model "identifica_srv02l.mdl".
 *
 * Model Version              : 1.261
 * Real-Time Workshop version : 7.2  (R2008b)  04-Aug-2008
 * C source code generated on : Tue Jun 17 05:57:22 2025
 */

#include "identifica_srv02l.h"
#include "identifica_srv02l_private.h"
#include <stdio.h>
#include "identifica_srv02l_dt.h"

/* Block signals (auto storage) */
BlockIO_identifica_srv02l identifica_srv02l_B;

/* Continuous states */
ContinuousStates_identifica_srv identifica_srv02l_X;

/* Block states (auto storage) */
D_Work_identifica_srv02l identifica_srv02l_DWork;

/* Real-time model */
RT_MODEL_identifica_srv02l identifica_srv02l_M_;
RT_MODEL_identifica_srv02l *identifica_srv02l_M = &identifica_srv02l_M_;
static void rate_monotonic_scheduler(void);

/*********************************************************************
 * Function rt_TDelayInterpolate
 *
 * Abstract:
 * Time delay interpolation routine
 *
 * The linear interpolation is performed using the formula:
 *
 *          (t2 - tMinusDelay)         (tMinusDelay - t1)
 * u(t)  =  ----------------- * u1  +  ------------------- * u2
 *              (t2 - t1)                  (t2 - t1)
 */
real_T rt_TDelayInterpolate(
  real_T tMinusDelay,                  /* tMinusDelay = currentSimTime - delay */
  real_T tStart,
  real_T *tBuf,
  real_T *uBuf,
  int_T bufSz,
  int_T *lastIdx,
  int_T oldestIdx,
  int_T newIdx,
  real_T initOutput,
  boolean_T discrete,
  boolean_T minorStepAndTAtLastMajorOutput)
{
  int_T i;
  real_T yout, t1, t2, u1, u2;

  /*
   * If tMinusDelay is less than zero, should output initial value
   */
  if (tMinusDelay <= tStart)
    return initOutput;

  /* For fixed buffer extrapolation:
   * if tMinusDelay is small than the time at oldestIdx, if discrete, output
   * tailptr value,  else use tailptr and tailptr+1 value to extrapolate
   * It is also for fixed buffer. Note: The same condition can happen for transport delay block where
   * use tStart and and t[tail] other than using t[tail] and t[tail+1].
   * See below
   */
  if ((tMinusDelay <= tBuf[oldestIdx] ) ) {
    if (discrete) {
      return(uBuf[oldestIdx]);
    } else {
      int_T tempIdx= oldestIdx + 1;
      if (oldestIdx == bufSz-1)
        tempIdx = 0;
      t1= tBuf[oldestIdx];
      t2= tBuf[tempIdx];
      u1= uBuf[oldestIdx];
      u2= uBuf[tempIdx];
      if (t2 == t1) {
        if (tMinusDelay >= t2) {
          yout = u2;
        } else {
          yout = u1;
        }
      } else {
        real_T f1 = (t2-tMinusDelay) / (t2-t1);
        real_T f2 = 1.0 - f1;

        /*
         * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
         */
        yout = f1*u1 + f2*u2;
      }

      return yout;
    }
  }

  /*
   * When block does not have direct feedthrough, we use the table of
   * values to extrapolate off the end of the table for delays that are less
   * than 0 (less then step size).  This is not completely accurate.  The
   * chain of events is as follows for a given time t.  Major output - look
   * in table.  Update - add entry to table.  Now, if we call the output at
   * time t again, there is a new entry in the table. For very small delays,
   * this means that we will have a different answer from the previous call
   * to the output fcn at the same time t.  The following code prevents this
   * from happening.
   */
  if (minorStepAndTAtLastMajorOutput) {
    /* pretend that the new entry has not been added to table */
    if (newIdx != 0) {
      if (*lastIdx == newIdx) {
        (*lastIdx)--;
      }

      newIdx--;
    } else {
      if (*lastIdx == newIdx) {
        *lastIdx = bufSz-1;
      }

      newIdx = bufSz - 1;
    }
  }

  i = *lastIdx;
  if (tBuf[i] < tMinusDelay) {
    /* Look forward starting at last index */
    while (tBuf[i] < tMinusDelay) {
      /* May occur if the delay is less than step-size - extrapolate */
      if (i == newIdx)
        break;
      i = ( i < (bufSz-1) ) ? (i+1) : 0;/* move through buffer */
    }
  } else {
    /*
     * Look backwards starting at last index which can happen when the
     * delay time increases.
     */
    while (tBuf[i] >= tMinusDelay) {
      /*
       * Due to the entry condition at top of function, we
       * should never hit the end.
       */
      i = (i > 0) ? i-1 : (bufSz-1);   /* move through buffer */
    }

    i = ( i < (bufSz-1) ) ? (i+1) : 0;
  }

  *lastIdx = i;
  if (discrete) {
    /*
     * tempEps = 128 * eps;
     * localEps = max(tempEps, tempEps*fabs(tBuf[i]))/2;
     */
    double tempEps = (DBL_EPSILON) * 128.0;
    double localEps = tempEps * fabs(tBuf[i]);
    if (tempEps > localEps) {
      localEps = tempEps;
    }

    localEps = localEps / 2.0;
    if (tMinusDelay >= (tBuf[i] - localEps)) {
      yout = uBuf[i];
    } else {
      if (i == 0) {
        yout = uBuf[bufSz-1];
      } else {
        yout = uBuf[i-1];
      }
    }
  } else {
    if (i == 0) {
      t1 = tBuf[bufSz-1];
      u1 = uBuf[bufSz-1];
    } else {
      t1 = tBuf[i-1];
      u1 = uBuf[i-1];
    }

    t2 = tBuf[i];
    u2 = uBuf[i];
    if (t2 == t1) {
      if (tMinusDelay >= t2) {
        yout = u2;
      } else {
        yout = u1;
      }
    } else {
      real_T f1 = (t2-tMinusDelay) / (t2-t1);
      real_T f2 = 1.0 - f1;

      /*
       * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
       */
      yout = f1*u1 + f2*u2;
    }
  }

  return(yout);
}

/* end function rt_TDelayInterpolate
 *********************************************************************/
time_T rt_SimUpdateDiscreteEvents(int_T rtmNumSampTimes,
  void *rtmTimingData,
  int_T *rtmSampleHitPtr,
  int_T *rtmPerTaskSampleHits)
{
  rtmSampleHitPtr[1] = rtmStepTask(identifica_srv02l_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(identifica_srv02l_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/* This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchagne data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  if (++identifica_srv02l_M->Timing.TaskCounters.TID[2] == 1000) {/* Sample time: [1.0s, 0.0s] */
    identifica_srv02l_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  identifica_srv02l_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void identifica_srv02l_output0(int_T tid) /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(identifica_srv02l_M)) {
    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(identifica_srv02l_M)) {
    identifica_srv02l_M->Timing.t[0] = rtsiGetT(&identifica_srv02l_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(identifica_srv02l_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&identifica_srv02l_M->solverInfo,
                          ((identifica_srv02l_M->Timing.clockTick0+1)*
      identifica_srv02l_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  {
    real_T currentTime;
    if (rtmIsMajorTimeStep(identifica_srv02l_M)) {
      /* S-Function Block: identifica_srv02l/SRV02/SRV02-ET/HIL Read Analog Timebase (hil_read_analog_timebase_block) */
      {
        t_error result;
        result = hil_task_read_analog
          (identifica_srv02l_DWork.HILReadAnalogTimebase_Task, 1,
           &identifica_srv02l_DWork.HILReadAnalogTimebase_Buffer[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(identifica_srv02l_M, _rt_error_message);
        }

        identifica_srv02l_B.HILReadAnalogTimebase_o1 =
          identifica_srv02l_DWork.HILReadAnalogTimebase_Buffer[0];
        identifica_srv02l_B.HILReadAnalogTimebase_o2 =
          identifica_srv02l_DWork.HILReadAnalogTimebase_Buffer[1];
      }

      /* S-Function Block: identifica_srv02l/SRV02/SRV02-ET/HIL Read Encoder (hil_read_encoder_block) */
      {
        t_error result = hil_read_encoder
          (identifica_srv02l_DWork.HILInitialize_Card,
           &identifica_srv02l_P.HILReadEncoder_Channels, 1,
           &identifica_srv02l_DWork.HILReadEncoder_Buffer);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(identifica_srv02l_M, _rt_error_message);
        } else {
          identifica_srv02l_B.HILReadEncoder =
            identifica_srv02l_DWork.HILReadEncoder_Buffer;
        }
      }

      /* Gain: '<S4>/Encoder Calibration  (rad//count)' */
      identifica_srv02l_B.EncoderCalibrationradcount =
        identifica_srv02l_P.EncoderCalibrationradcount_Gain *
        identifica_srv02l_B.HILReadEncoder;
    }

    /* TransferFcn Block: '<S4>/Encoder High-Pass Filter' */
    identifica_srv02l_B.EncoderHighPassFilter =
      identifica_srv02l_P.EncoderHighPassFilter_C[0]*
      identifica_srv02l_X.EncoderHighPassFilter_CSTATE[0]
      + identifica_srv02l_P.EncoderHighPassFilter_C[1]*
      identifica_srv02l_X.EncoderHighPassFilter_CSTATE[1];
    if (rtmIsMajorTimeStep(identifica_srv02l_M)) {
      /* MultiPortSwitch: '<S4>/Position Source Switch' incorporates:
       *  Constant: '<S2>/Pos Src'
       */
      if ((int32_T)identifica_srv02l_P.PosSrc_Value == 1) {
        /* Gain: '<S4>/Potentiometer Calibration  (rad//V)' */
        identifica_srv02l_B.PotentiometerCalibrationradV =
          identifica_srv02l_P.PotentiometerCalibrationradV_Ga *
          identifica_srv02l_B.HILReadAnalogTimebase_o1;
        identifica_srv02l_B.PositionSourceSwitch =
          identifica_srv02l_B.PotentiometerCalibrationradV;
      } else {
        identifica_srv02l_B.PositionSourceSwitch =
          identifica_srv02l_B.EncoderCalibrationradcount;
      }

      /* Gain: '<S4>/Tachometer Calibration  (rad//s//V)' */
      identifica_srv02l_B.TachometerCalibrationradsV =
        identifica_srv02l_P.TachometerCalibrationradsV_Gain *
        identifica_srv02l_B.HILReadAnalogTimebase_o2;
    }

    /* MultiPortSwitch: '<S4>/Velocity Source Switch' incorporates:
     *  Constant: '<Root>/Spd Src'
     */
    if ((int32_T)identifica_srv02l_P.SpdSrc_Value == 1) {
      identifica_srv02l_B.VelocitySourceSwitch =
        identifica_srv02l_B.TachometerCalibrationradsV;
    } else {
      identifica_srv02l_B.VelocitySourceSwitch =
        identifica_srv02l_B.EncoderHighPassFilter;
    }

    /* SignalGenerator Block: '<Root>/Square Wave'
     */
    {
      real_T phase = identifica_srv02l_P.SquareWave_Frequency*
        identifica_srv02l_M->Timing.t[0];
      phase = phase-floor(phase);
      identifica_srv02l_B.SquareWave = ( phase >= 0.5 ) ?
        identifica_srv02l_P.SquareWave_Amplitude :
        -identifica_srv02l_P.SquareWave_Amplitude;
    }

    /* Step: '<Root>/Step' */
    currentTime = identifica_srv02l_M->Timing.t[0];
    if (currentTime < identifica_srv02l_P.Step_Time) {
      identifica_srv02l_B.Step = identifica_srv02l_P.Step_Y0;
    } else {
      identifica_srv02l_B.Step = identifica_srv02l_P.Step_YFinal;
    }

    /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
     *  Constant: '<Root>/Define sinal de entrada'
     */
    if ((int32_T)identifica_srv02l_P.Definesinaldeentrada_Value == 1) {
      /* Gain: '<Root>/Step Amplitude' */
      identifica_srv02l_B.StepAmplitude =
        identifica_srv02l_P.StepAmplitude_Gain_h *
        identifica_srv02l_B.SquareWave;
      identifica_srv02l_B.MultiportSwitch = identifica_srv02l_B.StepAmplitude;
    } else {
      /* Gain: '<Root>/Step Amplitude ' */
      identifica_srv02l_B.StepAmplitude_j =
        identifica_srv02l_P.StepAmplitude_Gain * identifica_srv02l_B.Step;
      identifica_srv02l_B.MultiportSwitch = identifica_srv02l_B.StepAmplitude_j;
    }

    /* Gain: '<S5>/Direction Convention: (Right-Hand) system' */
    identifica_srv02l_B.DirectionConventionRightHandsys =
      identifica_srv02l_P.DirectionConventionRightHandsys *
      identifica_srv02l_B.MultiportSwitch;

    /* Saturate: '<S5>/Amplifier  Saturation (V)' */
    currentTime = identifica_srv02l_B.DirectionConventionRightHandsys;
    identifica_srv02l_B.AmplifierSaturationV = rt_SATURATE(currentTime,
      identifica_srv02l_P.AmplifierSaturationV_LowerSat,
      identifica_srv02l_P.AmplifierSaturationV_UpperSat);

    /* Gain: '<S5>/Inverse Amplifier  Gain (V//V)' */
    identifica_srv02l_B.InverseAmplifierGainVV =
      identifica_srv02l_P.InverseAmplifierGainVV_Gain *
      identifica_srv02l_B.AmplifierSaturationV;

    /* Saturate: '<S5>/DACB Saturation (V)' */
    currentTime = identifica_srv02l_B.InverseAmplifierGainVV;
    identifica_srv02l_B.DACBSaturationV = rt_SATURATE(currentTime,
      identifica_srv02l_P.DACBSaturationV_LowerSat,
      identifica_srv02l_P.DACBSaturationV_UpperSat);
    if (rtmIsMajorTimeStep(identifica_srv02l_M)) {
      /* S-Function Block: identifica_srv02l/SRV02/SRV02-ET/HIL Write Analog (hil_write_analog_block) */
      {
        t_error result;
        result = hil_write_analog(identifica_srv02l_DWork.HILInitialize_Card,
          &identifica_srv02l_P.HILWriteAnalog_Channels, 1,
          &identifica_srv02l_B.DACBSaturationV);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(identifica_srv02l_M, _rt_error_message);
        }
      }
    }

    /* Gain: '<S5>/Amplifier  Gain (V//V)' */
    identifica_srv02l_B.AmplifierGainVV =
      identifica_srv02l_P.AmplifierGainVV_Gain *
      identifica_srv02l_B.DACBSaturationV;

    /* TransferFcn Block: '<S3>/Transfer Fcn' */
    identifica_srv02l_B.TransferFcn = identifica_srv02l_P.TransferFcn_C*
      identifica_srv02l_X.TransferFcn_CSTATE;

    /* TransportDelay Block: '<S3>/Transport Delay' */
    {
      real_T **uBuffer = (real_T**)
        &identifica_srv02l_DWork.TransportDelay_PWORK.TUbufferPtrs[0];
      real_T **tBuffer = (real_T**)
        &identifica_srv02l_DWork.TransportDelay_PWORK.TUbufferPtrs[1];
      real_T simTime = identifica_srv02l_M->Timing.t[0];
      real_T tMinusDelay = simTime - identifica_srv02l_P.TransportDelay_Delay;
      if (identifica_srv02l_P.TransportDelay_Delay == 0.0)
        identifica_srv02l_B.TransportDelay = identifica_srv02l_B.TransferFcn;
      else
        identifica_srv02l_B.TransportDelay = rt_TDelayInterpolate(
          tMinusDelay,
          0.0,
          *tBuffer,
          *uBuffer,
          identifica_srv02l_DWork.TransportDelay_IWORK.CircularBufSize,
          &identifica_srv02l_DWork.TransportDelay_IWORK.Last,
          identifica_srv02l_DWork.TransportDelay_IWORK.Tail,
          identifica_srv02l_DWork.TransportDelay_IWORK.Head,
          identifica_srv02l_P.TransportDelay_InitOutput,
          0,
          0);
    }

    if (rtmIsMajorTimeStep(identifica_srv02l_M)) {
    }

    /* Integrator: '<S3>/Integrator' */
    identifica_srv02l_B.Integrator = identifica_srv02l_X.Integrator_CSTATE;
    if (rtmIsMajorTimeStep(identifica_srv02l_M)) {
    }

    /* Switch: '<S1>/SwitchControl' incorporates:
     *  Constant: '<S1>/Constant'
     */
    if (identifica_srv02l_P.Constant_Value >
        identifica_srv02l_P.SwitchControl_Threshold) {
      identifica_srv02l_B.SwitchControl = identifica_srv02l_B.MultiportSwitch;
    } else {
      identifica_srv02l_B.SwitchControl = 0.0;
    }

    /* Gain: '<S6>/Inverse Amplifier  Gain (V//V)' */
    identifica_srv02l_B.InverseAmplifierGainVV_o =
      identifica_srv02l_P.InverseAmplifierGainVV_Gain_g *
      identifica_srv02l_B.SwitchControl;

    /* Saturate: '<S6>/DACB Saturation (V)' */
    currentTime = identifica_srv02l_B.InverseAmplifierGainVV_o;
    identifica_srv02l_B.DACBSaturationV_p = rt_SATURATE(currentTime,
      identifica_srv02l_P.DACBSaturationV_LowerSat_g,
      identifica_srv02l_P.DACBSaturationV_UpperSat_m);

    /* Gain: '<S6>/Amplifier  Gain (V//V)' */
    identifica_srv02l_B.AmplifierGainVV_n =
      identifica_srv02l_P.AmplifierGainVV_Gain_n *
      identifica_srv02l_B.DACBSaturationV_p;

    /* Saturate: '<S6>/Amplifier  Saturation (V)' */
    currentTime = identifica_srv02l_B.AmplifierGainVV_n;
    identifica_srv02l_B.AmplifierSaturationV_e = rt_SATURATE(currentTime,
      identifica_srv02l_P.AmplifierSaturationV_LowerSat_i,
      identifica_srv02l_P.AmplifierSaturationV_UpperSat_n);
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function for TID0 */
void identifica_srv02l_update0(int_T tid) /* Sample time: [0.0s, 0.0s] */
{
  /* TransportDelay Block: '<S3>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &identifica_srv02l_DWork.TransportDelay_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &identifica_srv02l_DWork.TransportDelay_PWORK.TUbufferPtrs[1];
    real_T simTime = identifica_srv02l_M->Timing.t[0];
    identifica_srv02l_DWork.TransportDelay_IWORK.Head =
      ((identifica_srv02l_DWork.TransportDelay_IWORK.Head <
        (identifica_srv02l_DWork.TransportDelay_IWORK.CircularBufSize-1)) ?
       (identifica_srv02l_DWork.TransportDelay_IWORK.Head+1) : 0);
    if (identifica_srv02l_DWork.TransportDelay_IWORK.Head ==
        identifica_srv02l_DWork.TransportDelay_IWORK.Tail) {
      identifica_srv02l_DWork.TransportDelay_IWORK.Tail =
        ((identifica_srv02l_DWork.TransportDelay_IWORK.Tail <
          (identifica_srv02l_DWork.TransportDelay_IWORK.CircularBufSize-1)) ?
         (identifica_srv02l_DWork.TransportDelay_IWORK.Tail+1) : 0);
    }

    (*tBuffer)[identifica_srv02l_DWork.TransportDelay_IWORK.Head] = simTime;
    (*uBuffer)[identifica_srv02l_DWork.TransportDelay_IWORK.Head] =
      identifica_srv02l_B.TransferFcn;
  }

  if (rtmIsMajorTimeStep(identifica_srv02l_M)) {
    rt_ertODEUpdateContinuousStates(&identifica_srv02l_M->solverInfo);
  }

  /* Update absolute time */
  if (!(++identifica_srv02l_M->Timing.clockTick0))
    ++identifica_srv02l_M->Timing.clockTickH0;
  identifica_srv02l_M->Timing.t[0] = identifica_srv02l_M->Timing.clockTick0 *
    identifica_srv02l_M->Timing.stepSize0 +
    identifica_srv02l_M->Timing.clockTickH0 *
    identifica_srv02l_M->Timing.stepSize0 * 4294967296.0;

  /* Update absolute time */
  if (!(++identifica_srv02l_M->Timing.clockTick1))
    ++identifica_srv02l_M->Timing.clockTickH1;
  identifica_srv02l_M->Timing.t[1] = identifica_srv02l_M->Timing.clockTick1 *
    identifica_srv02l_M->Timing.stepSize1 +
    identifica_srv02l_M->Timing.clockTickH1 *
    identifica_srv02l_M->Timing.stepSize1 * 4294967296.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void identifica_srv02l_derivatives(void)
{
  /* TransferFcn Block: '<S4>/Encoder High-Pass Filter' */
  {
    ((StateDerivatives_identifica_srv *) identifica_srv02l_M->ModelData.derivs
      )->EncoderHighPassFilter_CSTATE[0] =
      identifica_srv02l_B.EncoderCalibrationradcount;
    ((StateDerivatives_identifica_srv *) identifica_srv02l_M->ModelData.derivs
      )->EncoderHighPassFilter_CSTATE[0] +=
      (identifica_srv02l_P.EncoderHighPassFilter_A[0])*
      identifica_srv02l_X.EncoderHighPassFilter_CSTATE[0]
      + (identifica_srv02l_P.EncoderHighPassFilter_A[1])*
      identifica_srv02l_X.EncoderHighPassFilter_CSTATE[1];
    ((StateDerivatives_identifica_srv *) identifica_srv02l_M->ModelData.derivs
      )->EncoderHighPassFilter_CSTATE[1]=
      identifica_srv02l_X.EncoderHighPassFilter_CSTATE[0];
  }

  /* TransferFcn Block: '<S3>/Transfer Fcn' */
  {
    ((StateDerivatives_identifica_srv *) identifica_srv02l_M->ModelData.derivs
      )->TransferFcn_CSTATE = identifica_srv02l_B.AmplifierSaturationV_e;
    ((StateDerivatives_identifica_srv *) identifica_srv02l_M->ModelData.derivs
      )->TransferFcn_CSTATE += (identifica_srv02l_P.TransferFcn_A)*
      identifica_srv02l_X.TransferFcn_CSTATE;
  }

  /* Derivatives for Integrator: '<S3>/Integrator' */
  ((StateDerivatives_identifica_srv *) identifica_srv02l_M->ModelData.derivs)
    ->Integrator_CSTATE = identifica_srv02l_B.TransportDelay;
}

/* Model output function for TID2 */
void identifica_srv02l_output2(int_T tid) /* Sample time: [1.0s, 0.0s] */
{
  /* ZeroOrderHold: '<Root>/Zero-Order Hold1' */
  identifica_srv02l_B.ZeroOrderHold1 = 0.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function for TID2 */
void identifica_srv02l_update2(int_T tid) /* Sample time: [1.0s, 0.0s] */
{
  /* Update absolute time */
  if (!(++identifica_srv02l_M->Timing.clockTick2))
    ++identifica_srv02l_M->Timing.clockTickH2;
  identifica_srv02l_M->Timing.t[2] = identifica_srv02l_M->Timing.clockTick2 *
    identifica_srv02l_M->Timing.stepSize2 +
    identifica_srv02l_M->Timing.clockTickH2 *
    identifica_srv02l_M->Timing.stepSize2 * 4294967296.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

void identifica_srv02l_output(int_T tid)
{
  switch (tid) {
   case 0 :
    identifica_srv02l_output0(0);
    break;

   case 2 :
    identifica_srv02l_output2(2);
    break;

   default :
    break;
  }
}

void identifica_srv02l_update(int_T tid)
{
  switch (tid) {
   case 0 :
    identifica_srv02l_update0(0);
    break;

   case 2 :
    identifica_srv02l_update2(2);
    break;

   default :
    break;
  }
}

/* Model initialize function */
void identifica_srv02l_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)identifica_srv02l_M,0,
                sizeof(RT_MODEL_identifica_srv02l));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&identifica_srv02l_M->solverInfo,
                          &identifica_srv02l_M->Timing.simTimeStep);
    rtsiSetTPtr(&identifica_srv02l_M->solverInfo, &rtmGetTPtr
                (identifica_srv02l_M));
    rtsiSetStepSizePtr(&identifica_srv02l_M->solverInfo,
                       &identifica_srv02l_M->Timing.stepSize0);
    rtsiSetdXPtr(&identifica_srv02l_M->solverInfo,
                 &identifica_srv02l_M->ModelData.derivs);
    rtsiSetContStatesPtr(&identifica_srv02l_M->solverInfo,
                         &identifica_srv02l_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&identifica_srv02l_M->solverInfo,
      &identifica_srv02l_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&identifica_srv02l_M->solverInfo, (&rtmGetErrorStatus
      (identifica_srv02l_M)));
    rtsiSetRTModelPtr(&identifica_srv02l_M->solverInfo, identifica_srv02l_M);
  }

  rtsiSetSimTimeStep(&identifica_srv02l_M->solverInfo, MAJOR_TIME_STEP);
  identifica_srv02l_M->ModelData.intgData.f[0] =
    identifica_srv02l_M->ModelData.odeF[0];
  identifica_srv02l_M->ModelData.contStates = ((real_T *) &identifica_srv02l_X);
  rtsiSetSolverData(&identifica_srv02l_M->solverInfo, (void *)
                    &identifica_srv02l_M->ModelData.intgData);
  rtsiSetSolverName(&identifica_srv02l_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = identifica_srv02l_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    identifica_srv02l_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    identifica_srv02l_M->Timing.sampleTimes =
      (&identifica_srv02l_M->Timing.sampleTimesArray[0]);
    identifica_srv02l_M->Timing.offsetTimes =
      (&identifica_srv02l_M->Timing.offsetTimesArray[0]);

    /* task periods */
    identifica_srv02l_M->Timing.sampleTimes[0] = (0.0);
    identifica_srv02l_M->Timing.sampleTimes[1] = (0.001);
    identifica_srv02l_M->Timing.sampleTimes[2] = (1.0);

    /* task offsets */
    identifica_srv02l_M->Timing.offsetTimes[0] = (0.0);
    identifica_srv02l_M->Timing.offsetTimes[1] = (0.0);
    identifica_srv02l_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(identifica_srv02l_M, &identifica_srv02l_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = identifica_srv02l_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      identifica_srv02l_M->Timing.perTaskSampleHitsArray;
    identifica_srv02l_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    identifica_srv02l_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(identifica_srv02l_M, 3.0);
  identifica_srv02l_M->Timing.stepSize0 = 0.001;
  identifica_srv02l_M->Timing.stepSize1 = 0.001;
  identifica_srv02l_M->Timing.stepSize2 = 1.0;

  /* external mode info */
  identifica_srv02l_M->Sizes.checksums[0] = (90425629U);
  identifica_srv02l_M->Sizes.checksums[1] = (4150723548U);
  identifica_srv02l_M->Sizes.checksums[2] = (3048048823U);
  identifica_srv02l_M->Sizes.checksums[3] = (1365482804U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    identifica_srv02l_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &identifica_srv02l_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, identifica_srv02l_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(identifica_srv02l_M));
  }

  identifica_srv02l_M->solverInfoPtr = (&identifica_srv02l_M->solverInfo);
  identifica_srv02l_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&identifica_srv02l_M->solverInfo, 0.001);
  rtsiSetSolverMode(&identifica_srv02l_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  identifica_srv02l_M->ModelData.blockIO = ((void *) &identifica_srv02l_B);

  {
    identifica_srv02l_B.HILReadAnalogTimebase_o1 = 0.0;
    identifica_srv02l_B.HILReadAnalogTimebase_o2 = 0.0;
    identifica_srv02l_B.HILReadEncoder = 0.0;
    identifica_srv02l_B.EncoderCalibrationradcount = 0.0;
    identifica_srv02l_B.EncoderHighPassFilter = 0.0;
    identifica_srv02l_B.PositionSourceSwitch = 0.0;
    identifica_srv02l_B.TachometerCalibrationradsV = 0.0;
    identifica_srv02l_B.VelocitySourceSwitch = 0.0;
    identifica_srv02l_B.SquareWave = 0.0;
    identifica_srv02l_B.Step = 0.0;
    identifica_srv02l_B.MultiportSwitch = 0.0;
    identifica_srv02l_B.DirectionConventionRightHandsys = 0.0;
    identifica_srv02l_B.AmplifierSaturationV = 0.0;
    identifica_srv02l_B.InverseAmplifierGainVV = 0.0;
    identifica_srv02l_B.DACBSaturationV = 0.0;
    identifica_srv02l_B.AmplifierGainVV = 0.0;
    identifica_srv02l_B.ZeroOrderHold1 = 0.0;
    identifica_srv02l_B.TransferFcn = 0.0;
    identifica_srv02l_B.TransportDelay = 0.0;
    identifica_srv02l_B.Integrator = 0.0;
    identifica_srv02l_B.SwitchControl = 0.0;
    identifica_srv02l_B.InverseAmplifierGainVV_o = 0.0;
    identifica_srv02l_B.DACBSaturationV_p = 0.0;
    identifica_srv02l_B.AmplifierGainVV_n = 0.0;
    identifica_srv02l_B.AmplifierSaturationV_e = 0.0;
    identifica_srv02l_B.PotentiometerCalibrationradV = 0.0;
    identifica_srv02l_B.StepAmplitude = 0.0;
    identifica_srv02l_B.StepAmplitude_j = 0.0;
  }

  /* parameters */
  identifica_srv02l_M->ModelData.defaultParam = ((real_T *) &identifica_srv02l_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &identifica_srv02l_X;
    identifica_srv02l_M->ModelData.contStates = (x);
    (void) memset((void *)x,0,
                  sizeof(ContinuousStates_identifica_srv));
  }

  /* states (dwork) */
  identifica_srv02l_M->Work.dwork = ((void *) &identifica_srv02l_DWork);
  (void) memset((void *)&identifica_srv02l_DWork, 0,
                sizeof(D_Work_identifica_srv02l));

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      identifica_srv02l_DWork.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      identifica_srv02l_DWork.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      identifica_srv02l_DWork.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      identifica_srv02l_DWork.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      identifica_srv02l_DWork.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      identifica_srv02l_DWork.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      identifica_srv02l_DWork.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      identifica_srv02l_DWork.HILInitialize_POValues[i] = 0.0;
    }
  }

  identifica_srv02l_DWork.HILReadAnalogTimebase_Buffer[0] = 0.0;
  identifica_srv02l_DWork.HILReadAnalogTimebase_Buffer[1] = 0.0;
  identifica_srv02l_DWork.TransportDelay_RWORK.modelTStart = 0.0;

  {
    int_T i;
    for (i = 0; i < 2048; i++) {
      identifica_srv02l_DWork.TransportDelay_RWORK.TUbufferArea[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    identifica_srv02l_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }
}

/* Model terminate function */
void identifica_srv02l_terminate(void)
{
  /* S-Function Block: identifica_srv02l/SRV02/SRV02-ET/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    hil_task_stop_all(identifica_srv02l_DWork.HILInitialize_Card);
    hil_task_delete_all(identifica_srv02l_DWork.HILInitialize_Card);
    hil_monitor_stop_all(identifica_srv02l_DWork.HILInitialize_Card);
    hil_monitor_delete_all(identifica_srv02l_DWork.HILInitialize_Card);
    is_switching = reconfiguration_is_switching_out(_reconfiguration);
    if ((identifica_srv02l_P.HILInitialize_AOTerminate && !is_switching) ||
        (identifica_srv02l_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &identifica_srv02l_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = identifica_srv02l_P.HILInitialize_AOFinal;
        }
      }

      result = hil_write_analog(identifica_srv02l_DWork.HILInitialize_Card,
        &identifica_srv02l_P.HILInitialize_AOChannels[0], 8U,
        &identifica_srv02l_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_M, _rt_error_message);
      }
    }

    if ((identifica_srv02l_P.HILInitialize_DOTerminate && !is_switching) ||
        (identifica_srv02l_P.HILInitialize_DOExit && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &identifica_srv02l_DWork.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = identifica_srv02l_P.HILInitialize_DOFinal;
        }
      }

      result = hil_write_digital(identifica_srv02l_DWork.HILInitialize_Card,
        &identifica_srv02l_P.HILInitialize_DOChannels[0], 8U, (t_boolean *)
        &identifica_srv02l_DWork.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_M, _rt_error_message);
      }
    }

    if ((identifica_srv02l_P.HILInitialize_POTerminate && !is_switching) ||
        (identifica_srv02l_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &identifica_srv02l_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = identifica_srv02l_P.HILInitialize_POFinal;
        }
      }

      result = hil_write_pwm(identifica_srv02l_DWork.HILInitialize_Card,
        &identifica_srv02l_P.HILInitialize_POChannels[0], 8U,
        &identifica_srv02l_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_M, _rt_error_message);
      }
    }

    hil_close(identifica_srv02l_DWork.HILInitialize_Card);
    identifica_srv02l_DWork.HILInitialize_Card = NULL;
  }

  /* External mode */
  rtExtModeShutdown(3);
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  identifica_srv02l_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  identifica_srv02l_update(tid);
}

void MdlInitializeSizes(void)
{
  identifica_srv02l_M->Sizes.numContStates = (4);/* Number of continuous states */
  identifica_srv02l_M->Sizes.numY = (0);/* Number of model outputs */
  identifica_srv02l_M->Sizes.numU = (0);/* Number of model inputs */
  identifica_srv02l_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  identifica_srv02l_M->Sizes.numSampTimes = (3);/* Number of sample times */
  identifica_srv02l_M->Sizes.numBlocks = (41);/* Number of blocks */
  identifica_srv02l_M->Sizes.numBlockIO = (28);/* Number of block outputs */
  identifica_srv02l_M->Sizes.numBlockPrms = (146);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* TransferFcn Block: '<S4>/Encoder High-Pass Filter' */
  identifica_srv02l_X.EncoderHighPassFilter_CSTATE[0] = 0.0;
  identifica_srv02l_X.EncoderHighPassFilter_CSTATE[1] = 0.0;

  /* TransferFcn Block: '<S3>/Transfer Fcn' */
  identifica_srv02l_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S3>/Integrator' */
  identifica_srv02l_X.Integrator_CSTATE = identifica_srv02l_P.Integrator_IC;
}

void MdlStart(void)
{
  /* S-Function Block: identifica_srv02l/SRV02/SRV02-ET/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &identifica_srv02l_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(identifica_srv02l_M, _rt_error_message);
      return;
    }

    is_switching = reconfiguration_is_switching_in(_reconfiguration);
    result = hil_set_card_specific_options
      (identifica_srv02l_DWork.HILInitialize_Card, "update_rate=normal", 19);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(identifica_srv02l_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(identifica_srv02l_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(identifica_srv02l_M, _rt_error_message);
      return;
    }

    if ((identifica_srv02l_P.HILInitialize_AIPStart && !is_switching) ||
        (identifica_srv02l_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums =
          &identifica_srv02l_DWork.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = identifica_srv02l_P.HILInitialize_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums =
          &identifica_srv02l_DWork.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = identifica_srv02l_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (identifica_srv02l_DWork.HILInitialize_Card,
         &identifica_srv02l_P.HILInitialize_AIChannels[0], 8U,
         &identifica_srv02l_DWork.HILInitialize_AIMinimums[0],
         &identifica_srv02l_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_M, _rt_error_message);
        return;
      }
    }

    if ((identifica_srv02l_P.HILInitialize_AOPStart && !is_switching) ||
        (identifica_srv02l_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums =
          &identifica_srv02l_DWork.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = identifica_srv02l_P.HILInitialize_AOLow;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums =
          &identifica_srv02l_DWork.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = identifica_srv02l_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges
        (identifica_srv02l_DWork.HILInitialize_Card,
         &identifica_srv02l_P.HILInitialize_AOChannels[0], 8U,
         &identifica_srv02l_DWork.HILInitialize_AOMinimums[0],
         &identifica_srv02l_DWork.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_M, _rt_error_message);
        return;
      }
    }

    if ((identifica_srv02l_P.HILInitialize_AOStart && !is_switching) ||
        (identifica_srv02l_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &identifica_srv02l_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = identifica_srv02l_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(identifica_srv02l_DWork.HILInitialize_Card,
        &identifica_srv02l_P.HILInitialize_AOChannels[0], 8U,
        &identifica_srv02l_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_M, _rt_error_message);
        return;
      }
    }

    if (identifica_srv02l_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &identifica_srv02l_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = identifica_srv02l_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (identifica_srv02l_DWork.HILInitialize_Card,
         &identifica_srv02l_P.HILInitialize_AOChannels[0], 8U,
         &identifica_srv02l_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions
      (identifica_srv02l_DWork.HILInitialize_Card, NULL, 0U,
       &identifica_srv02l_P.HILInitialize_DOChannels[0], 8U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(identifica_srv02l_M, _rt_error_message);
      return;
    }

    if ((identifica_srv02l_P.HILInitialize_DOStart && !is_switching) ||
        (identifica_srv02l_P.HILInitialize_DOEnter && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &identifica_srv02l_DWork.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = identifica_srv02l_P.HILInitialize_DOInitial;
        }
      }

      result = hil_write_digital(identifica_srv02l_DWork.HILInitialize_Card,
        &identifica_srv02l_P.HILInitialize_DOChannels[0], 8U, (t_boolean *)
        &identifica_srv02l_DWork.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_M, _rt_error_message);
        return;
      }
    }

    if (identifica_srv02l_P.HILInitialize_DOReset) {
      {
        int_T i1;
        int32_T *dw_DOStates = &identifica_srv02l_DWork.HILInitialize_DOStates[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOStates[i1] = identifica_srv02l_P.HILInitialize_DOWatchdog;
        }
      }

      result = hil_watchdog_set_digital_expiration_state
        (identifica_srv02l_DWork.HILInitialize_Card,
         &identifica_srv02l_P.HILInitialize_DOChannels[0], 8U, (const
          t_digital_state *) &identifica_srv02l_DWork.HILInitialize_DOStates[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_M, _rt_error_message);
        return;
      }
    }

    if ((identifica_srv02l_P.HILInitialize_EIPStart && !is_switching) ||
        (identifica_srv02l_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &identifica_srv02l_DWork.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] =
            identifica_srv02l_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (identifica_srv02l_DWork.HILInitialize_Card,
         &identifica_srv02l_P.HILInitialize_EIChannels[0], 8U,
         (t_encoder_quadrature_mode *)
         &identifica_srv02l_DWork.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_M, _rt_error_message);
        return;
      }
    }

    if ((identifica_srv02l_P.HILInitialize_EIStart && !is_switching) ||
        (identifica_srv02l_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &identifica_srv02l_DWork.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = identifica_srv02l_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(identifica_srv02l_DWork.HILInitialize_Card,
        &identifica_srv02l_P.HILInitialize_EIChannels[0], 8U,
        &identifica_srv02l_DWork.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_M, _rt_error_message);
        return;
      }
    }

    if ((identifica_srv02l_P.HILInitialize_POPStart && !is_switching) ||
        (identifica_srv02l_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &identifica_srv02l_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = identifica_srv02l_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(identifica_srv02l_DWork.HILInitialize_Card,
        &identifica_srv02l_P.HILInitialize_POChannels[0], 8U, (t_pwm_mode *)
        &identifica_srv02l_DWork.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          &identifica_srv02l_P.HILInitialize_POChannels[0];
        int32_T *dw_POModeValues =
          &identifica_srv02l_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            identifica_srv02l_DWork.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = (p_HILInitialize_POChannels[i1]);
            identifica_srv02l_DWork.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = identifica_srv02l_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            identifica_srv02l_DWork.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
            identifica_srv02l_DWork.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              identifica_srv02l_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency
          (identifica_srv02l_DWork.HILInitialize_Card,
           &identifica_srv02l_DWork.HILInitialize_POSortedChans[0],
           num_duty_cycle_modes,
           &identifica_srv02l_DWork.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(identifica_srv02l_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle
          (identifica_srv02l_DWork.HILInitialize_Card,
           &identifica_srv02l_DWork.HILInitialize_POSortedChans[num_duty_cycle_modes],
           num_frequency_modes,
           &identifica_srv02l_DWork.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(identifica_srv02l_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &identifica_srv02l_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            identifica_srv02l_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &identifica_srv02l_DWork.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = identifica_srv02l_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &identifica_srv02l_DWork.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = identifica_srv02l_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration
        (identifica_srv02l_DWork.HILInitialize_Card,
         &identifica_srv02l_P.HILInitialize_POChannels[0], 8U,
         (t_pwm_configuration *)
         &identifica_srv02l_DWork.HILInitialize_POModeValues[0],
         (t_pwm_alignment *)
         &identifica_srv02l_DWork.HILInitialize_POAlignValues[0],
         (t_pwm_polarity *)
         &identifica_srv02l_DWork.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &identifica_srv02l_DWork.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = identifica_srv02l_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &identifica_srv02l_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = identifica_srv02l_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(identifica_srv02l_DWork.HILInitialize_Card,
        &identifica_srv02l_P.HILInitialize_POChannels[0], 8U,
        &identifica_srv02l_DWork.HILInitialize_POSortedFreqs[0],
        &identifica_srv02l_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_M, _rt_error_message);
        return;
      }
    }

    if ((identifica_srv02l_P.HILInitialize_POStart && !is_switching) ||
        (identifica_srv02l_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &identifica_srv02l_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = identifica_srv02l_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(identifica_srv02l_DWork.HILInitialize_Card,
        &identifica_srv02l_P.HILInitialize_POChannels[0], 8U,
        &identifica_srv02l_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_M, _rt_error_message);
        return;
      }
    }

    if (identifica_srv02l_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &identifica_srv02l_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = identifica_srv02l_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (identifica_srv02l_DWork.HILInitialize_Card,
         &identifica_srv02l_P.HILInitialize_POChannels[0], 8U,
         &identifica_srv02l_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_M, _rt_error_message);
        return;
      }
    }
  }

  /* S-Function Block: identifica_srv02l/SRV02/SRV02-ET/HIL Read Analog Timebase (hil_read_analog_timebase_block) */
  {
    t_error result;
    result = hil_task_create_analog_reader
      (identifica_srv02l_DWork.HILInitialize_Card,
       identifica_srv02l_P.HILReadAnalogTimebase_SamplesIn,
       identifica_srv02l_P.HILReadAnalogTimebase_Channels, 2,
       &identifica_srv02l_DWork.HILReadAnalogTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(identifica_srv02l_M, _rt_error_message);
    }
  }

  /* TransportDelay Block: '<S3>/Transport Delay' */
  {
    real_T *pBuffer =
      &identifica_srv02l_DWork.TransportDelay_RWORK.TUbufferArea[0];
    identifica_srv02l_DWork.TransportDelay_IWORK.Tail = 0;
    identifica_srv02l_DWork.TransportDelay_IWORK.Head = 0;
    identifica_srv02l_DWork.TransportDelay_IWORK.Last = 0;
    identifica_srv02l_DWork.TransportDelay_IWORK.CircularBufSize = 1024;
    pBuffer[0] = identifica_srv02l_P.TransportDelay_InitOutput;
    pBuffer[1024] = identifica_srv02l_M->Timing.t[0];
    identifica_srv02l_DWork.TransportDelay_PWORK.TUbufferPtrs[0] = (void *)
      &pBuffer[0];
    identifica_srv02l_DWork.TransportDelay_PWORK.TUbufferPtrs[1] = (void *)
      &pBuffer[1024];
  }

  MdlInitialize();
}

RT_MODEL_identifica_srv02l *identifica_srv02l(void)
{
  identifica_srv02l_initialize(1);
  return identifica_srv02l_M;
}

void MdlTerminate(void)
{
  identifica_srv02l_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
