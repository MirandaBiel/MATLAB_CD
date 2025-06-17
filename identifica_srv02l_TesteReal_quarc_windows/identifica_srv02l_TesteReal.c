/*
 * identifica_srv02l_TesteReal.c
 *
 * Real-Time Workshop code generation for Simulink model "identifica_srv02l_TesteReal.mdl".
 *
 * Model Version              : 1.288
 * Real-Time Workshop version : 7.2  (R2008b)  04-Aug-2008
 * C source code generated on : Tue Jun 17 07:09:34 2025
 */

#include "identifica_srv02l_TesteReal.h"
#include "identifica_srv02l_TesteReal_private.h"
#include <stdio.h>
#include "identifica_srv02l_TesteReal_dt.h"

/* Block signals (auto storage) */
BlockIO_identifica_srv02l_Teste identifica_srv02l_TesteReal_B;

/* Continuous states */
ContinuousStates_identifica_srv identifica_srv02l_TesteReal_X;

/* Block states (auto storage) */
D_Work_identifica_srv02l_TesteR identifica_srv02l_TesteRe_DWork;

/* Real-time model */
RT_MODEL_identifica_srv02l_Test identifica_srv02l_TesteReal_M_;
RT_MODEL_identifica_srv02l_Test *identifica_srv02l_TesteReal_M =
  &identifica_srv02l_TesteReal_M_;
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
  rtmSampleHitPtr[1] = rtmStepTask(identifica_srv02l_TesteReal_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(identifica_srv02l_TesteReal_M, 2);
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
  /* To ensure a safe and deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 2 */
  identifica_srv02l_TesteReal_M->Timing.RateInteraction.TID0_2 =
    (identifica_srv02l_TesteReal_M->Timing.TaskCounters.TID[2] == 0);

  /* update PerTaskSampleHits matrix for non-inline sfcn */
  identifica_srv02l_TesteReal_M->Timing.perTaskSampleHits[2] =
    identifica_srv02l_TesteReal_M->Timing.RateInteraction.TID0_2;

  /* tid 1 shares data with slower tid rate: 2 */
  if (identifica_srv02l_TesteReal_M->Timing.TaskCounters.TID[1] == 0) {
    identifica_srv02l_TesteReal_M->Timing.RateInteraction.TID1_2 =
      (identifica_srv02l_TesteReal_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    identifica_srv02l_TesteReal_M->Timing.perTaskSampleHits[5] =
      identifica_srv02l_TesteReal_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  if (++identifica_srv02l_TesteReal_M->Timing.TaskCounters.TID[2] == 25) {/* Sample time: [0.025s, 0.0s] */
    identifica_srv02l_TesteReal_M->Timing.TaskCounters.TID[2] = 0;
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
  identifica_srv02l_TesteReal_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void identifica_srv02l_TesteReal_output0(int_T tid) /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(identifica_srv02l_TesteReal_M)) {
    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(identifica_srv02l_TesteReal_M)) {
    identifica_srv02l_TesteReal_M->Timing.t[0] = rtsiGetT
      (&identifica_srv02l_TesteReal_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(identifica_srv02l_TesteReal_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&identifica_srv02l_TesteReal_M->solverInfo,
                          ((identifica_srv02l_TesteReal_M->Timing.clockTick0+1)*
      identifica_srv02l_TesteReal_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  {
    real_T currentTime;
    if (rtmIsMajorTimeStep(identifica_srv02l_TesteReal_M)) {
      /* S-Function Block: identifica_srv02l_TesteReal/SRV02/SRV02-ET/HIL Read Analog Timebase (hil_read_analog_timebase_block) */
      {
        t_error result;
        result = hil_task_read_analog
          (identifica_srv02l_TesteRe_DWork.HILReadAnalogTimebase_Task, 1,
           &identifica_srv02l_TesteRe_DWork.HILReadAnalogTimebase_Buffer[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(identifica_srv02l_TesteReal_M, _rt_error_message);
        }

        identifica_srv02l_TesteReal_B.HILReadAnalogTimebase_o1 =
          identifica_srv02l_TesteRe_DWork.HILReadAnalogTimebase_Buffer[0];
        identifica_srv02l_TesteReal_B.HILReadAnalogTimebase_o2 =
          identifica_srv02l_TesteRe_DWork.HILReadAnalogTimebase_Buffer[1];
      }

      /* S-Function Block: identifica_srv02l_TesteReal/SRV02/SRV02-ET/HIL Read Encoder (hil_read_encoder_block) */
      {
        t_error result = hil_read_encoder
          (identifica_srv02l_TesteRe_DWork.HILInitialize_Card,
           &identifica_srv02l_TesteReal_P.HILReadEncoder_Channels, 1,
           &identifica_srv02l_TesteRe_DWork.HILReadEncoder_Buffer);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(identifica_srv02l_TesteReal_M, _rt_error_message);
        } else {
          identifica_srv02l_TesteReal_B.HILReadEncoder =
            identifica_srv02l_TesteRe_DWork.HILReadEncoder_Buffer;
        }
      }

      /* Gain: '<S6>/Encoder Calibration  (rad//count)' */
      identifica_srv02l_TesteReal_B.EncoderCalibrationradcount =
        identifica_srv02l_TesteReal_P.EncoderCalibrationradcount_Gain *
        identifica_srv02l_TesteReal_B.HILReadEncoder;
    }

    /* TransferFcn Block: '<S6>/Encoder High-Pass Filter' */
    identifica_srv02l_TesteReal_B.EncoderHighPassFilter =
      identifica_srv02l_TesteReal_P.EncoderHighPassFilter_C[0]*
      identifica_srv02l_TesteReal_X.EncoderHighPassFilter_CSTATE[0]
      + identifica_srv02l_TesteReal_P.EncoderHighPassFilter_C[1]*
      identifica_srv02l_TesteReal_X.EncoderHighPassFilter_CSTATE[1];
    if (rtmIsMajorTimeStep(identifica_srv02l_TesteReal_M)) {
      /* MultiPortSwitch: '<S6>/Position Source Switch' incorporates:
       *  Constant: '<S4>/Pos Src'
       */
      if ((int32_T)identifica_srv02l_TesteReal_P.PosSrc_Value == 1) {
        /* Gain: '<S6>/Potentiometer Calibration  (rad//V)' */
        identifica_srv02l_TesteReal_B.PotentiometerCalibrationradV =
          identifica_srv02l_TesteReal_P.PotentiometerCalibrationradV_Ga *
          identifica_srv02l_TesteReal_B.HILReadAnalogTimebase_o1;
        identifica_srv02l_TesteReal_B.PositionSourceSwitch =
          identifica_srv02l_TesteReal_B.PotentiometerCalibrationradV;
      } else {
        identifica_srv02l_TesteReal_B.PositionSourceSwitch =
          identifica_srv02l_TesteReal_B.EncoderCalibrationradcount;
      }

      /* Gain: '<S6>/Tachometer Calibration  (rad//s//V)' */
      identifica_srv02l_TesteReal_B.TachometerCalibrationradsV =
        identifica_srv02l_TesteReal_P.TachometerCalibrationradsV_Gain *
        identifica_srv02l_TesteReal_B.HILReadAnalogTimebase_o2;
    }

    /* MultiPortSwitch: '<S6>/Velocity Source Switch' incorporates:
     *  Constant: '<Root>/Spd Src'
     */
    if ((int32_T)identifica_srv02l_TesteReal_P.SpdSrc_Value == 1) {
      identifica_srv02l_TesteReal_B.VelocitySourceSwitch =
        identifica_srv02l_TesteReal_B.TachometerCalibrationradsV;
    } else {
      identifica_srv02l_TesteReal_B.VelocitySourceSwitch =
        identifica_srv02l_TesteReal_B.EncoderHighPassFilter;
    }

    if (rtmIsMajorTimeStep(identifica_srv02l_TesteReal_M)) {
      /* RateTransition: '<S2>/Rate Transition1' */
      if (identifica_srv02l_TesteReal_M->Timing.RateInteraction.TID1_2) {
        identifica_srv02l_TesteReal_B.RateTransition1 =
          identifica_srv02l_TesteRe_DWork.RateTransition1_Buffer0;
      }

      /* Gain: '<S7>/Direction Convention: (Right-Hand) system' */
      identifica_srv02l_TesteReal_B.DirectionConventionRightHandsys =
        identifica_srv02l_TesteReal_P.DirectionConventionRightHandsys *
        identifica_srv02l_TesteReal_B.RateTransition1;

      /* Saturate: '<S7>/Amplifier  Saturation (V)' */
      currentTime =
        identifica_srv02l_TesteReal_B.DirectionConventionRightHandsys;
      identifica_srv02l_TesteReal_B.AmplifierSaturationV = rt_SATURATE
        (currentTime,
         identifica_srv02l_TesteReal_P.AmplifierSaturationV_LowerSat,
         identifica_srv02l_TesteReal_P.AmplifierSaturationV_UpperSat);

      /* Gain: '<S7>/Inverse Amplifier  Gain (V//V)' */
      identifica_srv02l_TesteReal_B.InverseAmplifierGainVV =
        identifica_srv02l_TesteReal_P.InverseAmplifierGainVV_Gain *
        identifica_srv02l_TesteReal_B.AmplifierSaturationV;

      /* Saturate: '<S7>/DACB Saturation (V)' */
      currentTime = identifica_srv02l_TesteReal_B.InverseAmplifierGainVV;
      identifica_srv02l_TesteReal_B.DACBSaturationV = rt_SATURATE(currentTime,
        identifica_srv02l_TesteReal_P.DACBSaturationV_LowerSat,
        identifica_srv02l_TesteReal_P.DACBSaturationV_UpperSat);

      /* S-Function Block: identifica_srv02l_TesteReal/SRV02/SRV02-ET/HIL Write Analog (hil_write_analog_block) */
      {
        t_error result;
        result = hil_write_analog
          (identifica_srv02l_TesteRe_DWork.HILInitialize_Card,
           &identifica_srv02l_TesteReal_P.HILWriteAnalog_Channels, 1,
           &identifica_srv02l_TesteReal_B.DACBSaturationV);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(identifica_srv02l_TesteReal_M, _rt_error_message);
        }
      }

      /* Gain: '<S7>/Amplifier  Gain (V//V)' */
      identifica_srv02l_TesteReal_B.AmplifierGainVV =
        identifica_srv02l_TesteReal_P.AmplifierGainVV_Gain *
        identifica_srv02l_TesteReal_B.DACBSaturationV;
    }

    /* TransferFcn Block: '<S5>/Transfer Fcn' */
    identifica_srv02l_TesteReal_B.TransferFcn =
      identifica_srv02l_TesteReal_P.TransferFcn_C*
      identifica_srv02l_TesteReal_X.TransferFcn_CSTATE;

    /* TransportDelay Block: '<S5>/Transport Delay' */
    {
      real_T **uBuffer = (real_T**)
        &identifica_srv02l_TesteRe_DWork.TransportDelay_PWORK.TUbufferPtrs[0];
      real_T **tBuffer = (real_T**)
        &identifica_srv02l_TesteRe_DWork.TransportDelay_PWORK.TUbufferPtrs[1];
      real_T simTime = identifica_srv02l_TesteReal_M->Timing.t[0];
      real_T tMinusDelay = simTime -
        identifica_srv02l_TesteReal_P.TransportDelay_Delay;
      if (identifica_srv02l_TesteReal_P.TransportDelay_Delay == 0.0)
        identifica_srv02l_TesteReal_B.TransportDelay =
          identifica_srv02l_TesteReal_B.TransferFcn;
      else
        identifica_srv02l_TesteReal_B.TransportDelay = rt_TDelayInterpolate(
          tMinusDelay,
          0.0,
          *tBuffer,
          *uBuffer,
          identifica_srv02l_TesteRe_DWork.TransportDelay_IWORK.CircularBufSize,
          &identifica_srv02l_TesteRe_DWork.TransportDelay_IWORK.Last,
          identifica_srv02l_TesteRe_DWork.TransportDelay_IWORK.Tail,
          identifica_srv02l_TesteRe_DWork.TransportDelay_IWORK.Head,
          identifica_srv02l_TesteReal_P.TransportDelay_InitOutput,
          0,
          0);
    }

    if (rtmIsMajorTimeStep(identifica_srv02l_TesteReal_M)) {
      /* RateTransition: '<S1>/Rate Transition1' */
      if (identifica_srv02l_TesteReal_M->Timing.RateInteraction.TID1_2) {
        identifica_srv02l_TesteReal_B.RateTransition1_n =
          identifica_srv02l_TesteRe_DWork.RateTransition1_Buffer0_i;
      }
    }

    /* SignalGenerator Block: '<Root>/Square Wave'
     */
    {
      real_T phase = identifica_srv02l_TesteReal_P.SquareWave_Frequency*
        identifica_srv02l_TesteReal_M->Timing.t[0];
      phase = phase-floor(phase);
      identifica_srv02l_TesteReal_B.SquareWave = ( phase >= 0.5 ) ?
        identifica_srv02l_TesteReal_P.SquareWave_Amplitude :
        -identifica_srv02l_TesteReal_P.SquareWave_Amplitude;
    }

    /* Step: '<Root>/Step' */
    currentTime = identifica_srv02l_TesteReal_M->Timing.t[0];
    if (currentTime < identifica_srv02l_TesteReal_P.Step_Time) {
      identifica_srv02l_TesteReal_B.Step = identifica_srv02l_TesteReal_P.Step_Y0;
    } else {
      identifica_srv02l_TesteReal_B.Step =
        identifica_srv02l_TesteReal_P.Step_YFinal;
    }

    /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
     *  Constant: '<Root>/Define sinal de entrada'
     */
    if ((int32_T)identifica_srv02l_TesteReal_P.Definesinaldeentrada_Value == 1)
    {
      /* Gain: '<Root>/Step Amplitude' */
      identifica_srv02l_TesteReal_B.StepAmplitude =
        identifica_srv02l_TesteReal_P.StepAmplitude_Gain_e *
        identifica_srv02l_TesteReal_B.SquareWave;
      identifica_srv02l_TesteReal_B.MultiportSwitch =
        identifica_srv02l_TesteReal_B.StepAmplitude;
    } else {
      /* Gain: '<Root>/Step Amplitude ' */
      identifica_srv02l_TesteReal_B.StepAmplitude_o =
        identifica_srv02l_TesteReal_P.StepAmplitude_Gain *
        identifica_srv02l_TesteReal_B.Step;
      identifica_srv02l_TesteReal_B.MultiportSwitch =
        identifica_srv02l_TesteReal_B.StepAmplitude_o;
    }

    /* Switch: '<S3>/SwitchControl' incorporates:
     *  Constant: '<S3>/Constant'
     */
    if (identifica_srv02l_TesteReal_P.Constant_Value >
        identifica_srv02l_TesteReal_P.SwitchControl_Threshold) {
      identifica_srv02l_TesteReal_B.SwitchControl =
        identifica_srv02l_TesteReal_B.MultiportSwitch;
    } else {
      identifica_srv02l_TesteReal_B.SwitchControl = 0.0;
    }

    /* Integrator: '<S5>/Integrator' */
    identifica_srv02l_TesteReal_B.Integrator =
      identifica_srv02l_TesteReal_X.Integrator_CSTATE;
    if (rtmIsMajorTimeStep(identifica_srv02l_TesteReal_M)) {
    }

    /* Sum: '<Root>/Sum' */
    identifica_srv02l_TesteReal_B.Sum =
      identifica_srv02l_TesteReal_B.SwitchControl -
      identifica_srv02l_TesteReal_B.Integrator;

    /* RateTransition: '<S1>/Rate Transition' */
    if (rtmIsMajorTimeStep(identifica_srv02l_TesteReal_M) &&
        identifica_srv02l_TesteReal_M->Timing.RateInteraction.TID0_2) {
      identifica_srv02l_TesteReal_B.RateTransition =
        identifica_srv02l_TesteReal_B.Sum;
    }

    /* Sum: '<Root>/Sum1' */
    identifica_srv02l_TesteReal_B.Sum1 =
      identifica_srv02l_TesteReal_B.MultiportSwitch -
      identifica_srv02l_TesteReal_B.PositionSourceSwitch;

    /* RateTransition: '<S2>/Rate Transition' */
    if (rtmIsMajorTimeStep(identifica_srv02l_TesteReal_M) &&
        identifica_srv02l_TesteReal_M->Timing.RateInteraction.TID0_2) {
      identifica_srv02l_TesteReal_B.RateTransition_e =
        identifica_srv02l_TesteReal_B.Sum1;
    }

    if (rtmIsMajorTimeStep(identifica_srv02l_TesteReal_M)) {
      /* Gain: '<S8>/Inverse Amplifier  Gain (V//V)' */
      identifica_srv02l_TesteReal_B.InverseAmplifierGainVV_i =
        identifica_srv02l_TesteReal_P.InverseAmplifierGainVV_Gain_h *
        identifica_srv02l_TesteReal_B.RateTransition1_n;

      /* Saturate: '<S8>/DACB Saturation (V)' */
      currentTime = identifica_srv02l_TesteReal_B.InverseAmplifierGainVV_i;
      identifica_srv02l_TesteReal_B.DACBSaturationV_c = rt_SATURATE(currentTime,
        identifica_srv02l_TesteReal_P.DACBSaturationV_LowerSat_p,
        identifica_srv02l_TesteReal_P.DACBSaturationV_UpperSat_g);

      /* Gain: '<S8>/Amplifier  Gain (V//V)' */
      identifica_srv02l_TesteReal_B.AmplifierGainVV_b =
        identifica_srv02l_TesteReal_P.AmplifierGainVV_Gain_e *
        identifica_srv02l_TesteReal_B.DACBSaturationV_c;

      /* Saturate: '<S8>/Amplifier  Saturation (V)' */
      currentTime = identifica_srv02l_TesteReal_B.AmplifierGainVV_b;
      identifica_srv02l_TesteReal_B.AmplifierSaturationV_c = rt_SATURATE
        (currentTime,
         identifica_srv02l_TesteReal_P.AmplifierSaturationV_LowerSat_g,
         identifica_srv02l_TesteReal_P.AmplifierSaturationV_UpperSat_i);
    }
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function for TID0 */
void identifica_srv02l_TesteReal_update0(int_T tid) /* Sample time: [0.0s, 0.0s] */
{
  /* TransportDelay Block: '<S5>/Transport Delay' */
  {
    real_T **uBuffer = (real_T**)
      &identifica_srv02l_TesteRe_DWork.TransportDelay_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)
      &identifica_srv02l_TesteRe_DWork.TransportDelay_PWORK.TUbufferPtrs[1];
    real_T simTime = identifica_srv02l_TesteReal_M->Timing.t[0];
    identifica_srv02l_TesteRe_DWork.TransportDelay_IWORK.Head =
      ((identifica_srv02l_TesteRe_DWork.TransportDelay_IWORK.Head <
        (identifica_srv02l_TesteRe_DWork.TransportDelay_IWORK.CircularBufSize-1))
       ? (identifica_srv02l_TesteRe_DWork.TransportDelay_IWORK.Head+1) : 0);
    if (identifica_srv02l_TesteRe_DWork.TransportDelay_IWORK.Head ==
        identifica_srv02l_TesteRe_DWork.TransportDelay_IWORK.Tail) {
      identifica_srv02l_TesteRe_DWork.TransportDelay_IWORK.Tail =
        ((identifica_srv02l_TesteRe_DWork.TransportDelay_IWORK.Tail <
          (identifica_srv02l_TesteRe_DWork.TransportDelay_IWORK.CircularBufSize-
           1)) ? (identifica_srv02l_TesteRe_DWork.TransportDelay_IWORK.Tail+1) :
         0);
    }

    (*tBuffer)[identifica_srv02l_TesteRe_DWork.TransportDelay_IWORK.Head] =
      simTime;
    (*uBuffer)[identifica_srv02l_TesteRe_DWork.TransportDelay_IWORK.Head] =
      identifica_srv02l_TesteReal_B.TransferFcn;
  }

  if (rtmIsMajorTimeStep(identifica_srv02l_TesteReal_M)) {
    rt_ertODEUpdateContinuousStates(&identifica_srv02l_TesteReal_M->solverInfo);
  }

  /* Update absolute time */
  if (!(++identifica_srv02l_TesteReal_M->Timing.clockTick0))
    ++identifica_srv02l_TesteReal_M->Timing.clockTickH0;
  identifica_srv02l_TesteReal_M->Timing.t[0] =
    identifica_srv02l_TesteReal_M->Timing.clockTick0 *
    identifica_srv02l_TesteReal_M->Timing.stepSize0 +
    identifica_srv02l_TesteReal_M->Timing.clockTickH0 *
    identifica_srv02l_TesteReal_M->Timing.stepSize0 * 4294967296.0;

  /* Update absolute time */
  if (!(++identifica_srv02l_TesteReal_M->Timing.clockTick1))
    ++identifica_srv02l_TesteReal_M->Timing.clockTickH1;
  identifica_srv02l_TesteReal_M->Timing.t[1] =
    identifica_srv02l_TesteReal_M->Timing.clockTick1 *
    identifica_srv02l_TesteReal_M->Timing.stepSize1 +
    identifica_srv02l_TesteReal_M->Timing.clockTickH1 *
    identifica_srv02l_TesteReal_M->Timing.stepSize1 * 4294967296.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void identifica_srv02l_TesteReal_derivatives(void)
{
  /* TransferFcn Block: '<S6>/Encoder High-Pass Filter' */
  {
    ((StateDerivatives_identifica_srv *)
      identifica_srv02l_TesteReal_M->ModelData.derivs)
      ->EncoderHighPassFilter_CSTATE[0] =
      identifica_srv02l_TesteReal_B.EncoderCalibrationradcount;
    ((StateDerivatives_identifica_srv *)
      identifica_srv02l_TesteReal_M->ModelData.derivs)
      ->EncoderHighPassFilter_CSTATE[0] +=
      (identifica_srv02l_TesteReal_P.EncoderHighPassFilter_A[0])*
      identifica_srv02l_TesteReal_X.EncoderHighPassFilter_CSTATE[0]
      + (identifica_srv02l_TesteReal_P.EncoderHighPassFilter_A[1])*
      identifica_srv02l_TesteReal_X.EncoderHighPassFilter_CSTATE[1];
    ((StateDerivatives_identifica_srv *)
      identifica_srv02l_TesteReal_M->ModelData.derivs)
      ->EncoderHighPassFilter_CSTATE[1]=
      identifica_srv02l_TesteReal_X.EncoderHighPassFilter_CSTATE[0];
  }

  /* TransferFcn Block: '<S5>/Transfer Fcn' */
  {
    ((StateDerivatives_identifica_srv *)
      identifica_srv02l_TesteReal_M->ModelData.derivs)->TransferFcn_CSTATE =
      identifica_srv02l_TesteReal_B.AmplifierSaturationV_c;
    ((StateDerivatives_identifica_srv *)
      identifica_srv02l_TesteReal_M->ModelData.derivs)->TransferFcn_CSTATE +=
      (identifica_srv02l_TesteReal_P.TransferFcn_A)*
      identifica_srv02l_TesteReal_X.TransferFcn_CSTATE;
  }

  /* Derivatives for Integrator: '<S5>/Integrator' */
  ((StateDerivatives_identifica_srv *)
    identifica_srv02l_TesteReal_M->ModelData.derivs)->Integrator_CSTATE =
    identifica_srv02l_TesteReal_B.TransportDelay;
}

/* Model output function for TID2 */
void identifica_srv02l_TesteReal_output2(int_T tid) /* Sample time: [0.025s, 0.0s] */
{
  /* DiscreteZeroPole Block: '<S1>/Discrete Zero-Pole'
   */
  {
    identifica_srv02l_TesteReal_B.DiscreteZeroPole =
      identifica_srv02l_TesteReal_P.DiscreteZeroPole_D*
      identifica_srv02l_TesteReal_B.RateTransition;
    identifica_srv02l_TesteReal_B.DiscreteZeroPole +=
      identifica_srv02l_TesteReal_P.DiscreteZeroPole_C*
      identifica_srv02l_TesteRe_DWork.DiscreteZeroPole_DSTATE;
  }

  /* DiscreteZeroPole Block: '<S2>/Discrete Zero-Pole'
   */
  {
    identifica_srv02l_TesteReal_B.DiscreteZeroPole_c =
      identifica_srv02l_TesteReal_P.DiscreteZeroPole_D_g*
      identifica_srv02l_TesteReal_B.RateTransition_e;
    identifica_srv02l_TesteReal_B.DiscreteZeroPole_c +=
      identifica_srv02l_TesteReal_P.DiscreteZeroPole_C_i*
      identifica_srv02l_TesteRe_DWork.DiscreteZeroPole_DSTATE_a;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function for TID2 */
void identifica_srv02l_TesteReal_update2(int_T tid) /* Sample time: [0.025s, 0.0s] */
{
  identifica_srv02l_TesteRe_DWork.RateTransition1_Buffer0 =
    identifica_srv02l_TesteReal_B.DiscreteZeroPole_c;
  identifica_srv02l_TesteRe_DWork.RateTransition1_Buffer0_i =
    identifica_srv02l_TesteReal_B.DiscreteZeroPole;

  /* DiscreteZeroPole Block: '<S1>/Discrete Zero-Pole' */
  {
    identifica_srv02l_TesteRe_DWork.DiscreteZeroPole_DSTATE =
      identifica_srv02l_TesteReal_B.RateTransition +
      identifica_srv02l_TesteReal_P.DiscreteZeroPole_A*
      identifica_srv02l_TesteRe_DWork.DiscreteZeroPole_DSTATE;
  }

  /* DiscreteZeroPole Block: '<S2>/Discrete Zero-Pole' */
  {
    identifica_srv02l_TesteRe_DWork.DiscreteZeroPole_DSTATE_a =
      identifica_srv02l_TesteReal_B.RateTransition_e +
      identifica_srv02l_TesteReal_P.DiscreteZeroPole_A_o*
      identifica_srv02l_TesteRe_DWork.DiscreteZeroPole_DSTATE_a;
  }

  /* Update absolute time */
  if (!(++identifica_srv02l_TesteReal_M->Timing.clockTick2))
    ++identifica_srv02l_TesteReal_M->Timing.clockTickH2;
  identifica_srv02l_TesteReal_M->Timing.t[2] =
    identifica_srv02l_TesteReal_M->Timing.clockTick2 *
    identifica_srv02l_TesteReal_M->Timing.stepSize2 +
    identifica_srv02l_TesteReal_M->Timing.clockTickH2 *
    identifica_srv02l_TesteReal_M->Timing.stepSize2 * 4294967296.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

void identifica_srv02l_TesteReal_output(int_T tid)
{
  switch (tid) {
   case 0 :
    identifica_srv02l_TesteReal_output0(0);
    break;

   case 2 :
    identifica_srv02l_TesteReal_output2(2);
    break;

   default :
    break;
  }
}

void identifica_srv02l_TesteReal_update(int_T tid)
{
  switch (tid) {
   case 0 :
    identifica_srv02l_TesteReal_update0(0);
    break;

   case 2 :
    identifica_srv02l_TesteReal_update2(2);
    break;

   default :
    break;
  }
}

/* Model initialize function */
void identifica_srv02l_TesteReal_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)identifica_srv02l_TesteReal_M,0,
                sizeof(RT_MODEL_identifica_srv02l_Test));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&identifica_srv02l_TesteReal_M->solverInfo,
                          &identifica_srv02l_TesteReal_M->Timing.simTimeStep);
    rtsiSetTPtr(&identifica_srv02l_TesteReal_M->solverInfo, &rtmGetTPtr
                (identifica_srv02l_TesteReal_M));
    rtsiSetStepSizePtr(&identifica_srv02l_TesteReal_M->solverInfo,
                       &identifica_srv02l_TesteReal_M->Timing.stepSize0);
    rtsiSetdXPtr(&identifica_srv02l_TesteReal_M->solverInfo,
                 &identifica_srv02l_TesteReal_M->ModelData.derivs);
    rtsiSetContStatesPtr(&identifica_srv02l_TesteReal_M->solverInfo,
                         &identifica_srv02l_TesteReal_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&identifica_srv02l_TesteReal_M->solverInfo,
      &identifica_srv02l_TesteReal_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&identifica_srv02l_TesteReal_M->solverInfo,
                          (&rtmGetErrorStatus(identifica_srv02l_TesteReal_M)));
    rtsiSetRTModelPtr(&identifica_srv02l_TesteReal_M->solverInfo,
                      identifica_srv02l_TesteReal_M);
  }

  rtsiSetSimTimeStep(&identifica_srv02l_TesteReal_M->solverInfo, MAJOR_TIME_STEP);
  identifica_srv02l_TesteReal_M->ModelData.intgData.f[0] =
    identifica_srv02l_TesteReal_M->ModelData.odeF[0];
  identifica_srv02l_TesteReal_M->ModelData.contStates = ((real_T *)
    &identifica_srv02l_TesteReal_X);
  rtsiSetSolverData(&identifica_srv02l_TesteReal_M->solverInfo, (void *)
                    &identifica_srv02l_TesteReal_M->ModelData.intgData);
  rtsiSetSolverName(&identifica_srv02l_TesteReal_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      identifica_srv02l_TesteReal_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    identifica_srv02l_TesteReal_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    identifica_srv02l_TesteReal_M->Timing.sampleTimes =
      (&identifica_srv02l_TesteReal_M->Timing.sampleTimesArray[0]);
    identifica_srv02l_TesteReal_M->Timing.offsetTimes =
      (&identifica_srv02l_TesteReal_M->Timing.offsetTimesArray[0]);

    /* task periods */
    identifica_srv02l_TesteReal_M->Timing.sampleTimes[0] = (0.0);
    identifica_srv02l_TesteReal_M->Timing.sampleTimes[1] = (0.001);
    identifica_srv02l_TesteReal_M->Timing.sampleTimes[2] = (0.025);

    /* task offsets */
    identifica_srv02l_TesteReal_M->Timing.offsetTimes[0] = (0.0);
    identifica_srv02l_TesteReal_M->Timing.offsetTimes[1] = (0.0);
    identifica_srv02l_TesteReal_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(identifica_srv02l_TesteReal_M,
             &identifica_srv02l_TesteReal_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = identifica_srv02l_TesteReal_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      identifica_srv02l_TesteReal_M->Timing.perTaskSampleHitsArray;
    identifica_srv02l_TesteReal_M->Timing.perTaskSampleHits =
      (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    identifica_srv02l_TesteReal_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(identifica_srv02l_TesteReal_M, 3.0);
  identifica_srv02l_TesteReal_M->Timing.stepSize0 = 0.001;
  identifica_srv02l_TesteReal_M->Timing.stepSize1 = 0.001;
  identifica_srv02l_TesteReal_M->Timing.stepSize2 = 0.025;

  /* external mode info */
  identifica_srv02l_TesteReal_M->Sizes.checksums[0] = (1931417442U);
  identifica_srv02l_TesteReal_M->Sizes.checksums[1] = (634373038U);
  identifica_srv02l_TesteReal_M->Sizes.checksums[2] = (23699636U);
  identifica_srv02l_TesteReal_M->Sizes.checksums[3] = (3081975177U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    identifica_srv02l_TesteReal_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &identifica_srv02l_TesteReal_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo,
                        identifica_srv02l_TesteReal_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(identifica_srv02l_TesteReal_M));
  }

  identifica_srv02l_TesteReal_M->solverInfoPtr =
    (&identifica_srv02l_TesteReal_M->solverInfo);
  identifica_srv02l_TesteReal_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&identifica_srv02l_TesteReal_M->solverInfo, 0.001);
  rtsiSetSolverMode(&identifica_srv02l_TesteReal_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  identifica_srv02l_TesteReal_M->ModelData.blockIO = ((void *)
    &identifica_srv02l_TesteReal_B);

  {
    identifica_srv02l_TesteReal_B.HILReadAnalogTimebase_o1 = 0.0;
    identifica_srv02l_TesteReal_B.HILReadAnalogTimebase_o2 = 0.0;
    identifica_srv02l_TesteReal_B.HILReadEncoder = 0.0;
    identifica_srv02l_TesteReal_B.EncoderCalibrationradcount = 0.0;
    identifica_srv02l_TesteReal_B.EncoderHighPassFilter = 0.0;
    identifica_srv02l_TesteReal_B.PositionSourceSwitch = 0.0;
    identifica_srv02l_TesteReal_B.TachometerCalibrationradsV = 0.0;
    identifica_srv02l_TesteReal_B.VelocitySourceSwitch = 0.0;
    identifica_srv02l_TesteReal_B.RateTransition1 = 0.0;
    identifica_srv02l_TesteReal_B.DirectionConventionRightHandsys = 0.0;
    identifica_srv02l_TesteReal_B.AmplifierSaturationV = 0.0;
    identifica_srv02l_TesteReal_B.InverseAmplifierGainVV = 0.0;
    identifica_srv02l_TesteReal_B.DACBSaturationV = 0.0;
    identifica_srv02l_TesteReal_B.AmplifierGainVV = 0.0;
    identifica_srv02l_TesteReal_B.TransferFcn = 0.0;
    identifica_srv02l_TesteReal_B.TransportDelay = 0.0;
    identifica_srv02l_TesteReal_B.RateTransition1_n = 0.0;
    identifica_srv02l_TesteReal_B.SquareWave = 0.0;
    identifica_srv02l_TesteReal_B.Step = 0.0;
    identifica_srv02l_TesteReal_B.MultiportSwitch = 0.0;
    identifica_srv02l_TesteReal_B.SwitchControl = 0.0;
    identifica_srv02l_TesteReal_B.Integrator = 0.0;
    identifica_srv02l_TesteReal_B.Sum = 0.0;
    identifica_srv02l_TesteReal_B.RateTransition = 0.0;
    identifica_srv02l_TesteReal_B.DiscreteZeroPole = 0.0;
    identifica_srv02l_TesteReal_B.Sum1 = 0.0;
    identifica_srv02l_TesteReal_B.RateTransition_e = 0.0;
    identifica_srv02l_TesteReal_B.DiscreteZeroPole_c = 0.0;
    identifica_srv02l_TesteReal_B.InverseAmplifierGainVV_i = 0.0;
    identifica_srv02l_TesteReal_B.DACBSaturationV_c = 0.0;
    identifica_srv02l_TesteReal_B.AmplifierGainVV_b = 0.0;
    identifica_srv02l_TesteReal_B.AmplifierSaturationV_c = 0.0;
    identifica_srv02l_TesteReal_B.PotentiometerCalibrationradV = 0.0;
    identifica_srv02l_TesteReal_B.StepAmplitude = 0.0;
    identifica_srv02l_TesteReal_B.StepAmplitude_o = 0.0;
  }

  /* parameters */
  identifica_srv02l_TesteReal_M->ModelData.defaultParam = ((real_T *)
    &identifica_srv02l_TesteReal_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &identifica_srv02l_TesteReal_X;
    identifica_srv02l_TesteReal_M->ModelData.contStates = (x);
    (void) memset((void *)x,0,
                  sizeof(ContinuousStates_identifica_srv));
  }

  /* states (dwork) */
  identifica_srv02l_TesteReal_M->Work.dwork = ((void *)
    &identifica_srv02l_TesteRe_DWork);
  (void) memset((void *)&identifica_srv02l_TesteRe_DWork, 0,
                sizeof(D_Work_identifica_srv02l_TesteR));
  identifica_srv02l_TesteRe_DWork.DiscreteZeroPole_DSTATE = 0.0;
  identifica_srv02l_TesteRe_DWork.DiscreteZeroPole_DSTATE_a = 0.0;

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      identifica_srv02l_TesteRe_DWork.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      identifica_srv02l_TesteRe_DWork.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      identifica_srv02l_TesteRe_DWork.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      identifica_srv02l_TesteRe_DWork.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      identifica_srv02l_TesteRe_DWork.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      identifica_srv02l_TesteRe_DWork.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      identifica_srv02l_TesteRe_DWork.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      identifica_srv02l_TesteRe_DWork.HILInitialize_POValues[i] = 0.0;
    }
  }

  identifica_srv02l_TesteRe_DWork.HILReadAnalogTimebase_Buffer[0] = 0.0;
  identifica_srv02l_TesteRe_DWork.HILReadAnalogTimebase_Buffer[1] = 0.0;
  identifica_srv02l_TesteRe_DWork.RateTransition1_Buffer0 = 0.0;
  identifica_srv02l_TesteRe_DWork.RateTransition1_Buffer0_i = 0.0;
  identifica_srv02l_TesteRe_DWork.TransportDelay_RWORK.modelTStart = 0.0;

  {
    int_T i;
    for (i = 0; i < 2048; i++) {
      identifica_srv02l_TesteRe_DWork.TransportDelay_RWORK.TUbufferArea[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    identifica_srv02l_TesteReal_M->SpecialInfo.mappingInfo = (&dtInfo);
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
void identifica_srv02l_TesteReal_terminate(void)
{
  /* S-Function Block: identifica_srv02l_TesteReal/SRV02/SRV02-ET/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    hil_task_stop_all(identifica_srv02l_TesteRe_DWork.HILInitialize_Card);
    hil_task_delete_all(identifica_srv02l_TesteRe_DWork.HILInitialize_Card);
    hil_monitor_stop_all(identifica_srv02l_TesteRe_DWork.HILInitialize_Card);
    hil_monitor_delete_all(identifica_srv02l_TesteRe_DWork.HILInitialize_Card);
    is_switching = reconfiguration_is_switching_out(_reconfiguration);
    if ((identifica_srv02l_TesteReal_P.HILInitialize_AOTerminate &&
         !is_switching) || (identifica_srv02l_TesteReal_P.HILInitialize_AOExit &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &identifica_srv02l_TesteRe_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] =
            identifica_srv02l_TesteReal_P.HILInitialize_AOFinal;
        }
      }

      result = hil_write_analog
        (identifica_srv02l_TesteRe_DWork.HILInitialize_Card,
         &identifica_srv02l_TesteReal_P.HILInitialize_AOChannels[0], 8U,
         &identifica_srv02l_TesteRe_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_TesteReal_M, _rt_error_message);
      }
    }

    if ((identifica_srv02l_TesteReal_P.HILInitialize_DOTerminate &&
         !is_switching) || (identifica_srv02l_TesteReal_P.HILInitialize_DOExit &&
         is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits =
          &identifica_srv02l_TesteRe_DWork.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = identifica_srv02l_TesteReal_P.HILInitialize_DOFinal;
        }
      }

      result = hil_write_digital
        (identifica_srv02l_TesteRe_DWork.HILInitialize_Card,
         &identifica_srv02l_TesteReal_P.HILInitialize_DOChannels[0], 8U,
         (t_boolean *) &identifica_srv02l_TesteRe_DWork.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_TesteReal_M, _rt_error_message);
      }
    }

    if ((identifica_srv02l_TesteReal_P.HILInitialize_POTerminate &&
         !is_switching) || (identifica_srv02l_TesteReal_P.HILInitialize_POExit &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues =
          &identifica_srv02l_TesteRe_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = identifica_srv02l_TesteReal_P.HILInitialize_POFinal;
        }
      }

      result = hil_write_pwm(identifica_srv02l_TesteRe_DWork.HILInitialize_Card,
        &identifica_srv02l_TesteReal_P.HILInitialize_POChannels[0], 8U,
        &identifica_srv02l_TesteRe_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_TesteReal_M, _rt_error_message);
      }
    }

    hil_close(identifica_srv02l_TesteRe_DWork.HILInitialize_Card);
    identifica_srv02l_TesteRe_DWork.HILInitialize_Card = NULL;
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
  identifica_srv02l_TesteReal_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  identifica_srv02l_TesteReal_update(tid);
}

void MdlInitializeSizes(void)
{
  identifica_srv02l_TesteReal_M->Sizes.numContStates = (4);/* Number of continuous states */
  identifica_srv02l_TesteReal_M->Sizes.numY = (0);/* Number of model outputs */
  identifica_srv02l_TesteReal_M->Sizes.numU = (0);/* Number of model inputs */
  identifica_srv02l_TesteReal_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  identifica_srv02l_TesteReal_M->Sizes.numSampTimes = (3);/* Number of sample times */
  identifica_srv02l_TesteReal_M->Sizes.numBlocks = (49);/* Number of blocks */
  identifica_srv02l_TesteReal_M->Sizes.numBlockIO = (35);/* Number of block outputs */
  identifica_srv02l_TesteReal_M->Sizes.numBlockPrms = (154);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* TransferFcn Block: '<S6>/Encoder High-Pass Filter' */
  identifica_srv02l_TesteReal_X.EncoderHighPassFilter_CSTATE[0] = 0.0;
  identifica_srv02l_TesteReal_X.EncoderHighPassFilter_CSTATE[1] = 0.0;

  /* InitializeConditions for RateTransition: '<S2>/Rate Transition1' */
  identifica_srv02l_TesteRe_DWork.RateTransition1_Buffer0 =
    identifica_srv02l_TesteReal_P.RateTransition1_X0;

  /* TransferFcn Block: '<S5>/Transfer Fcn' */
  identifica_srv02l_TesteReal_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for RateTransition: '<S1>/Rate Transition1' */
  identifica_srv02l_TesteRe_DWork.RateTransition1_Buffer0_i =
    identifica_srv02l_TesteReal_P.RateTransition1_X0_f;

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  identifica_srv02l_TesteReal_X.Integrator_CSTATE =
    identifica_srv02l_TesteReal_P.Integrator_IC;
}

void MdlStart(void)
{
  /* S-Function Block: identifica_srv02l_TesteReal/SRV02/SRV02-ET/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0",
                      &identifica_srv02l_TesteRe_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(identifica_srv02l_TesteReal_M, _rt_error_message);
      return;
    }

    is_switching = reconfiguration_is_switching_in(_reconfiguration);
    result = hil_set_card_specific_options
      (identifica_srv02l_TesteRe_DWork.HILInitialize_Card, "update_rate=normal",
       19);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(identifica_srv02l_TesteReal_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear
      (identifica_srv02l_TesteRe_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(identifica_srv02l_TesteReal_M, _rt_error_message);
      return;
    }

    if ((identifica_srv02l_TesteReal_P.HILInitialize_AIPStart && !is_switching) ||
        (identifica_srv02l_TesteReal_P.HILInitialize_AIPEnter && is_switching))
    {
      {
        int_T i1;
        real_T *dw_AIMinimums =
          &identifica_srv02l_TesteRe_DWork.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = identifica_srv02l_TesteReal_P.HILInitialize_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums =
          &identifica_srv02l_TesteRe_DWork.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = identifica_srv02l_TesteReal_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (identifica_srv02l_TesteRe_DWork.HILInitialize_Card,
         &identifica_srv02l_TesteReal_P.HILInitialize_AIChannels[0], 8U,
         &identifica_srv02l_TesteRe_DWork.HILInitialize_AIMinimums[0],
         &identifica_srv02l_TesteRe_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_TesteReal_M, _rt_error_message);
        return;
      }
    }

    if ((identifica_srv02l_TesteReal_P.HILInitialize_AOPStart && !is_switching) ||
        (identifica_srv02l_TesteReal_P.HILInitialize_AOPEnter && is_switching))
    {
      {
        int_T i1;
        real_T *dw_AOMinimums =
          &identifica_srv02l_TesteRe_DWork.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = identifica_srv02l_TesteReal_P.HILInitialize_AOLow;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums =
          &identifica_srv02l_TesteRe_DWork.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = identifica_srv02l_TesteReal_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges
        (identifica_srv02l_TesteRe_DWork.HILInitialize_Card,
         &identifica_srv02l_TesteReal_P.HILInitialize_AOChannels[0], 8U,
         &identifica_srv02l_TesteRe_DWork.HILInitialize_AOMinimums[0],
         &identifica_srv02l_TesteRe_DWork.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_TesteReal_M, _rt_error_message);
        return;
      }
    }

    if ((identifica_srv02l_TesteReal_P.HILInitialize_AOStart && !is_switching) ||
        (identifica_srv02l_TesteReal_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &identifica_srv02l_TesteRe_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] =
            identifica_srv02l_TesteReal_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog
        (identifica_srv02l_TesteRe_DWork.HILInitialize_Card,
         &identifica_srv02l_TesteReal_P.HILInitialize_AOChannels[0], 8U,
         &identifica_srv02l_TesteRe_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_TesteReal_M, _rt_error_message);
        return;
      }
    }

    if (identifica_srv02l_TesteReal_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &identifica_srv02l_TesteRe_DWork.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] =
            identifica_srv02l_TesteReal_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (identifica_srv02l_TesteRe_DWork.HILInitialize_Card,
         &identifica_srv02l_TesteReal_P.HILInitialize_AOChannels[0], 8U,
         &identifica_srv02l_TesteRe_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_TesteReal_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions
      (identifica_srv02l_TesteRe_DWork.HILInitialize_Card, NULL, 0U,
       &identifica_srv02l_TesteReal_P.HILInitialize_DOChannels[0], 8U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(identifica_srv02l_TesteReal_M, _rt_error_message);
      return;
    }

    if ((identifica_srv02l_TesteReal_P.HILInitialize_DOStart && !is_switching) ||
        (identifica_srv02l_TesteReal_P.HILInitialize_DOEnter && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits =
          &identifica_srv02l_TesteRe_DWork.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = identifica_srv02l_TesteReal_P.HILInitialize_DOInitial;
        }
      }

      result = hil_write_digital
        (identifica_srv02l_TesteRe_DWork.HILInitialize_Card,
         &identifica_srv02l_TesteReal_P.HILInitialize_DOChannels[0], 8U,
         (t_boolean *) &identifica_srv02l_TesteRe_DWork.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_TesteReal_M, _rt_error_message);
        return;
      }
    }

    if (identifica_srv02l_TesteReal_P.HILInitialize_DOReset) {
      {
        int_T i1;
        int32_T *dw_DOStates =
          &identifica_srv02l_TesteRe_DWork.HILInitialize_DOStates[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOStates[i1] =
            identifica_srv02l_TesteReal_P.HILInitialize_DOWatchdog;
        }
      }

      result = hil_watchdog_set_digital_expiration_state
        (identifica_srv02l_TesteRe_DWork.HILInitialize_Card,
         &identifica_srv02l_TesteReal_P.HILInitialize_DOChannels[0], 8U, (const
          t_digital_state *)
         &identifica_srv02l_TesteRe_DWork.HILInitialize_DOStates[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_TesteReal_M, _rt_error_message);
        return;
      }
    }

    if ((identifica_srv02l_TesteReal_P.HILInitialize_EIPStart && !is_switching) ||
        (identifica_srv02l_TesteReal_P.HILInitialize_EIPEnter && is_switching))
    {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &identifica_srv02l_TesteRe_DWork.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] =
            identifica_srv02l_TesteReal_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (identifica_srv02l_TesteRe_DWork.HILInitialize_Card,
         &identifica_srv02l_TesteReal_P.HILInitialize_EIChannels[0], 8U,
         (t_encoder_quadrature_mode *)
         &identifica_srv02l_TesteRe_DWork.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_TesteReal_M, _rt_error_message);
        return;
      }
    }

    if ((identifica_srv02l_TesteReal_P.HILInitialize_EIStart && !is_switching) ||
        (identifica_srv02l_TesteReal_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &identifica_srv02l_TesteRe_DWork.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] =
            identifica_srv02l_TesteReal_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts
        (identifica_srv02l_TesteRe_DWork.HILInitialize_Card,
         &identifica_srv02l_TesteReal_P.HILInitialize_EIChannels[0], 8U,
         &identifica_srv02l_TesteRe_DWork.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_TesteReal_M, _rt_error_message);
        return;
      }
    }

    if ((identifica_srv02l_TesteReal_P.HILInitialize_POPStart && !is_switching) ||
        (identifica_srv02l_TesteReal_P.HILInitialize_POPEnter && is_switching))
    {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &identifica_srv02l_TesteRe_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            identifica_srv02l_TesteReal_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode
        (identifica_srv02l_TesteRe_DWork.HILInitialize_Card,
         &identifica_srv02l_TesteReal_P.HILInitialize_POChannels[0], 8U,
         (t_pwm_mode *)
         &identifica_srv02l_TesteRe_DWork.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_TesteReal_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          &identifica_srv02l_TesteReal_P.HILInitialize_POChannels[0];
        int32_T *dw_POModeValues =
          &identifica_srv02l_TesteRe_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            identifica_srv02l_TesteRe_DWork.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = (p_HILInitialize_POChannels[i1]);
            identifica_srv02l_TesteRe_DWork.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = identifica_srv02l_TesteReal_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            identifica_srv02l_TesteRe_DWork.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
            identifica_srv02l_TesteRe_DWork.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              identifica_srv02l_TesteReal_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency
          (identifica_srv02l_TesteRe_DWork.HILInitialize_Card,
           &identifica_srv02l_TesteRe_DWork.HILInitialize_POSortedChans[0],
           num_duty_cycle_modes,
           &identifica_srv02l_TesteRe_DWork.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(identifica_srv02l_TesteReal_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle
          (identifica_srv02l_TesteRe_DWork.HILInitialize_Card,
           &identifica_srv02l_TesteRe_DWork.HILInitialize_POSortedChans[num_duty_cycle_modes],
           num_frequency_modes,
           &identifica_srv02l_TesteRe_DWork.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(identifica_srv02l_TesteReal_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &identifica_srv02l_TesteRe_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            identifica_srv02l_TesteReal_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &identifica_srv02l_TesteRe_DWork.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] =
            identifica_srv02l_TesteReal_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &identifica_srv02l_TesteRe_DWork.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] =
            identifica_srv02l_TesteReal_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration
        (identifica_srv02l_TesteRe_DWork.HILInitialize_Card,
         &identifica_srv02l_TesteReal_P.HILInitialize_POChannels[0], 8U,
         (t_pwm_configuration *)
         &identifica_srv02l_TesteRe_DWork.HILInitialize_POModeValues[0],
         (t_pwm_alignment *)
         &identifica_srv02l_TesteRe_DWork.HILInitialize_POAlignValues[0],
         (t_pwm_polarity *)
         &identifica_srv02l_TesteRe_DWork.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_TesteReal_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &identifica_srv02l_TesteRe_DWork.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] =
            identifica_srv02l_TesteReal_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues =
          &identifica_srv02l_TesteRe_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] =
            identifica_srv02l_TesteReal_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband
        (identifica_srv02l_TesteRe_DWork.HILInitialize_Card,
         &identifica_srv02l_TesteReal_P.HILInitialize_POChannels[0], 8U,
         &identifica_srv02l_TesteRe_DWork.HILInitialize_POSortedFreqs[0],
         &identifica_srv02l_TesteRe_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_TesteReal_M, _rt_error_message);
        return;
      }
    }

    if ((identifica_srv02l_TesteReal_P.HILInitialize_POStart && !is_switching) ||
        (identifica_srv02l_TesteReal_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues =
          &identifica_srv02l_TesteRe_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] =
            identifica_srv02l_TesteReal_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(identifica_srv02l_TesteRe_DWork.HILInitialize_Card,
        &identifica_srv02l_TesteReal_P.HILInitialize_POChannels[0], 8U,
        &identifica_srv02l_TesteRe_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_TesteReal_M, _rt_error_message);
        return;
      }
    }

    if (identifica_srv02l_TesteReal_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues =
          &identifica_srv02l_TesteRe_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] =
            identifica_srv02l_TesteReal_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (identifica_srv02l_TesteRe_DWork.HILInitialize_Card,
         &identifica_srv02l_TesteReal_P.HILInitialize_POChannels[0], 8U,
         &identifica_srv02l_TesteRe_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(identifica_srv02l_TesteReal_M, _rt_error_message);
        return;
      }
    }
  }

  /* S-Function Block: identifica_srv02l_TesteReal/SRV02/SRV02-ET/HIL Read Analog Timebase (hil_read_analog_timebase_block) */
  {
    t_error result;
    result = hil_task_create_analog_reader
      (identifica_srv02l_TesteRe_DWork.HILInitialize_Card,
       identifica_srv02l_TesteReal_P.HILReadAnalogTimebase_SamplesIn,
       identifica_srv02l_TesteReal_P.HILReadAnalogTimebase_Channels, 2,
       &identifica_srv02l_TesteRe_DWork.HILReadAnalogTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(identifica_srv02l_TesteReal_M, _rt_error_message);
    }
  }

  /* Start for RateTransition: '<S2>/Rate Transition1' */
  identifica_srv02l_TesteReal_B.RateTransition1 =
    identifica_srv02l_TesteReal_P.RateTransition1_X0;

  /* TransportDelay Block: '<S5>/Transport Delay' */
  {
    real_T *pBuffer =
      &identifica_srv02l_TesteRe_DWork.TransportDelay_RWORK.TUbufferArea[0];
    identifica_srv02l_TesteRe_DWork.TransportDelay_IWORK.Tail = 0;
    identifica_srv02l_TesteRe_DWork.TransportDelay_IWORK.Head = 0;
    identifica_srv02l_TesteRe_DWork.TransportDelay_IWORK.Last = 0;
    identifica_srv02l_TesteRe_DWork.TransportDelay_IWORK.CircularBufSize = 1024;
    pBuffer[0] = identifica_srv02l_TesteReal_P.TransportDelay_InitOutput;
    pBuffer[1024] = identifica_srv02l_TesteReal_M->Timing.t[0];
    identifica_srv02l_TesteRe_DWork.TransportDelay_PWORK.TUbufferPtrs[0] = (void
      *) &pBuffer[0];
    identifica_srv02l_TesteRe_DWork.TransportDelay_PWORK.TUbufferPtrs[1] = (void
      *) &pBuffer[1024];
  }

  /* Start for RateTransition: '<S1>/Rate Transition1' */
  identifica_srv02l_TesteReal_B.RateTransition1_n =
    identifica_srv02l_TesteReal_P.RateTransition1_X0_f;
  MdlInitialize();
}

RT_MODEL_identifica_srv02l_Test *identifica_srv02l_TesteReal(void)
{
  identifica_srv02l_TesteReal_initialize(1);
  return identifica_srv02l_TesteReal_M;
}

void MdlTerminate(void)
{
  identifica_srv02l_TesteReal_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
