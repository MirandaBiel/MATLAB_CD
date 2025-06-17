/*
 * identifica_srv02l_v35_data.c
 *
 * Real-Time Workshop code generation for Simulink model "identifica_srv02l_v35.mdl".
 *
 * Model Version              : 1.282
 * Real-Time Workshop version : 7.2  (R2008b)  04-Aug-2008
 * C source code generated on : Tue Jun 17 06:42:06 2025
 */

#include "identifica_srv02l_v35.h"
#include "identifica_srv02l_v35_private.h"

/* Block parameters (auto storage) */
Parameters_identifica_srv02l_v3 identifica_srv02l_v35_P = {
  0.0,                                 /* HILInitialize_OOStart : '<S4>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOEnter : '<S4>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOTerminate : '<S4>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOExit : '<S4>/HIL Initialize'
                                        */
  10.0,                                /* HILInitialize_AIHigh : '<S4>/HIL Initialize'
                                        */
  -10.0,                               /* HILInitialize_AILow : '<S4>/HIL Initialize'
                                        */
  10.0,                                /* HILInitialize_AOHigh : '<S4>/HIL Initialize'
                                        */
  -10.0,                               /* HILInitialize_AOLow : '<S4>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_AOInitial : '<S4>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_AOFinal : '<S4>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_AOWatchdog : '<S4>/HIL Initialize'
                                        */
  2.4305934065934067E+004,             /* HILInitialize_POFrequency : '<S4>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POLeading : '<S4>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POTrailing : '<S4>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POInitial : '<S4>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POFinal : '<S4>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POWatchdog : '<S4>/HIL Initialize'
                                        */
  -1.5339807878856412E-003,            /* EncoderCalibrationradcount_Gain : '<S4>/Encoder Calibration  (rad//count)'
                                        */

  /*  EncoderHighPassFilter_A : '<S4>/Encoder High-Pass Filter'
   */
  { -2.8274333882308139E+002, -2.4674011002723397E+004 },

  /*  EncoderHighPassFilter_C : '<S4>/Encoder High-Pass Filter'
   */
  { 2.4674011002723397E+004, 0.0 },
  2.0,                                 /* PosSrc_Value : '<S2>/Pos Src'
                                        */
  -9.9733100113961670E-001,            /* TachometerCalibrationradsV_Gain : '<S4>/Tachometer Calibration  (rad//s//V)'
                                        */
  2.0,                                 /* SpdSrc_Value : '<Root>/Spd Src'
                                        */
  -1.0,                                /* DirectionConventionRightHandsys : '<S5>/Direction Convention: (Right-Hand) system'
                                        */
  24.0,                                /* AmplifierSaturationV_UpperSat : '<S5>/Amplifier  Saturation (V)'
                                        */
  -24.0,                               /* AmplifierSaturationV_LowerSat : '<S5>/Amplifier  Saturation (V)'
                                        */
  1.0,                                 /* InverseAmplifierGainVV_Gain : '<S5>/Inverse Amplifier  Gain (V//V)'
                                        */
  10.0,                                /* DACBSaturationV_UpperSat : '<S5>/DACB Saturation (V)'
                                        */
  -10.0,                               /* DACBSaturationV_LowerSat : '<S5>/DACB Saturation (V)'
                                        */
  -1.0,                                /* AmplifierGainVV_Gain : '<S5>/Amplifier  Gain (V//V)'
                                        */
  -14.1465,                            /* TransferFcn_A : '<S3>/Transfer Fcn'
                                        */
  4.028,                               /* TransferFcn_C : '<S3>/Transfer Fcn'
                                        */
  0.0,                                 /* TransportDelay_Delay : '<S3>/Transport Delay'
                                        */
  0.0,                                 /* TransportDelay_InitOutput : '<S3>/Transport Delay'
                                        */
  0.0,                                 /* RateTransition1_X0 : '<Root>/Rate Transition1'
                                        */
  2.0,                                 /* Definesinaldeentrada_Value : '<Root>/Define sinal de entrada'
                                        */
  1.0,                                 /* SquareWave_Amplitude : '<Root>/Square Wave'
                                        */
  5.0,                                 /* SquareWave_Frequency : '<Root>/Square Wave'
                                        */
  0.5,                                 /* Step_Time : '<Root>/Step'
                                        */
  0.0,                                 /* Step_Y0 : '<Root>/Step'
                                        */
  1.0,                                 /* Step_YFinal : '<Root>/Step'
                                        */
  0.0,                                 /* Integrator_IC : '<S3>/Integrator'
                                        */
  0.4563,                              /* DiscreteTransferFcn_A : '<Root>/Discrete Transfer Fcn'
                                        */
  -17.459466,                          /* DiscreteTransferFcn_C : '<Root>/Discrete Transfer Fcn'
                                        */
  6.818E+001,                          /* DiscreteTransferFcn_D : '<Root>/Discrete Transfer Fcn'
                                        */
  1.0,                                 /* InverseAmplifierGainVV_Gain_i : '<S6>/Inverse Amplifier  Gain (V//V)'
                                        */
  10.0,                                /* DACBSaturationV_UpperSat_d : '<S6>/DACB Saturation (V)'
                                        */
  -10.0,                               /* DACBSaturationV_LowerSat_b : '<S6>/DACB Saturation (V)'
                                        */
  1.0,                                 /* AmplifierGainVV_Gain_c : '<S6>/Amplifier  Gain (V//V)'
                                        */
  24.0,                                /* AmplifierSaturationV_UpperSat_d : '<S6>/Amplifier  Saturation (V)'
                                        */
  -24.0,                               /* AmplifierSaturationV_LowerSat_m : '<S6>/Amplifier  Saturation (V)'
                                        */
  0.087266,                            /* StepAmplitude_Gain : '<Root>/Step Amplitude '
                                        */
  0.087266,                            /* StepAmplitude_Gain_h : '<Root>/Step Amplitude'
                                        */
  -6.1435589670200397E-001,            /* PotentiometerCalibrationradV_Ga : '<S4>/Potentiometer Calibration  (rad//V)'
                                        */

  /*  HILInitialize_CKChannels : '<S4>/HIL Initialize'
   */
  { 0, 1, 2 },
  0,                                   /* HILInitialize_DOWatchdog : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIInitial : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POModes : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POConfiguration : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POAlignment : '<S4>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POPolarity : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILReadAnalogTimebase_Clock : '<S4>/HIL Read Analog Timebase'
                                        */

  /*  HILInitialize_AIChannels : '<S4>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  HILInitialize_AOChannels : '<S4>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  HILInitialize_DOChannels : '<S4>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  HILInitialize_EIChannels : '<S4>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },
  4U,                                  /* HILInitialize_EIQuadrature : '<S4>/HIL Initialize'
                                        */

  /*  HILInitialize_POChannels : '<S4>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  HILReadAnalogTimebase_Channels : '<S4>/HIL Read Analog Timebase'
   */
  { 0U, 1U },
  1000U,                               /* HILReadAnalogTimebase_SamplesIn : '<S4>/HIL Read Analog Timebase'
                                        */
  0U,                                  /* HILReadEncoder_Channels : '<S4>/HIL Read Encoder'
                                        */
  0U,                                  /* HILWriteAnalog_Channels : '<S4>/HIL Write Analog'
                                        */
  1U,                                  /* Constant_Value : '<S1>/Constant'
                                        */
  0U,                                  /* SwitchControl_Threshold : '<S1>/SwitchControl'
                                        */
  0,                                   /* HILInitialize_Active : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_CKPStart : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_CKPEnter : '<S4>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_AIPStart : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AIPEnter : '<S4>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_AOPStart : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOPEnter : '<S4>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_AOStart : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOEnter : '<S4>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_AOTerminate : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOExit : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOReset : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOPStart : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOPEnter : '<S4>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_DOStart : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOEnter : '<S4>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_DOTerminate : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOExit : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOReset : '<S4>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_EIPStart : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIPEnter : '<S4>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_EIStart : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIEnter : '<S4>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POPStart : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POPEnter : '<S4>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POStart : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POEnter : '<S4>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POTerminate : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POExit : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POReset : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_OOReset : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOInitial : '<S4>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOFinal : '<S4>/HIL Initialize'
                                        */
  1,                                   /* HILReadAnalogTimebase_Active : '<S4>/HIL Read Analog Timebase'
                                        */
  1,                                   /* HILReadEncoder_Active : '<S4>/HIL Read Encoder'
                                        */
  0                                    /* HILWriteAnalog_Active : '<S4>/HIL Write Analog'
                                        */
};
