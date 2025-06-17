/*
 * identifica_srv02l_TesteReal_data.c
 *
 * Real-Time Workshop code generation for Simulink model "identifica_srv02l_TesteReal.mdl".
 *
 * Model Version              : 1.288
 * Real-Time Workshop version : 7.2  (R2008b)  04-Aug-2008
 * C source code generated on : Tue Jun 17 07:09:34 2025
 */

#include "identifica_srv02l_TesteReal.h"
#include "identifica_srv02l_TesteReal_private.h"

/* Block parameters (auto storage) */
Parameters_identifica_srv02l_Te identifica_srv02l_TesteReal_P = {
  0.0,                                 /* HILInitialize_OOStart : '<S6>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOEnter : '<S6>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOTerminate : '<S6>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOExit : '<S6>/HIL Initialize'
                                        */
  10.0,                                /* HILInitialize_AIHigh : '<S6>/HIL Initialize'
                                        */
  -10.0,                               /* HILInitialize_AILow : '<S6>/HIL Initialize'
                                        */
  10.0,                                /* HILInitialize_AOHigh : '<S6>/HIL Initialize'
                                        */
  -10.0,                               /* HILInitialize_AOLow : '<S6>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_AOInitial : '<S6>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_AOFinal : '<S6>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_AOWatchdog : '<S6>/HIL Initialize'
                                        */
  2.4305934065934067E+004,             /* HILInitialize_POFrequency : '<S6>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POLeading : '<S6>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POTrailing : '<S6>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POInitial : '<S6>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POFinal : '<S6>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POWatchdog : '<S6>/HIL Initialize'
                                        */
  -1.5339807878856412E-003,            /* EncoderCalibrationradcount_Gain : '<S6>/Encoder Calibration  (rad//count)'
                                        */

  /*  EncoderHighPassFilter_A : '<S6>/Encoder High-Pass Filter'
   */
  { -2.8274333882308139E+002, -2.4674011002723397E+004 },

  /*  EncoderHighPassFilter_C : '<S6>/Encoder High-Pass Filter'
   */
  { 2.4674011002723397E+004, 0.0 },
  2.0,                                 /* PosSrc_Value : '<S4>/Pos Src'
                                        */
  -9.9733100113961670E-001,            /* TachometerCalibrationradsV_Gain : '<S6>/Tachometer Calibration  (rad//s//V)'
                                        */
  2.0,                                 /* SpdSrc_Value : '<Root>/Spd Src'
                                        */
  0.0,                                 /* RateTransition1_X0 : '<S2>/Rate Transition1'
                                        */
  -1.0,                                /* DirectionConventionRightHandsys : '<S7>/Direction Convention: (Right-Hand) system'
                                        */
  24.0,                                /* AmplifierSaturationV_UpperSat : '<S7>/Amplifier  Saturation (V)'
                                        */
  -24.0,                               /* AmplifierSaturationV_LowerSat : '<S7>/Amplifier  Saturation (V)'
                                        */
  1.0,                                 /* InverseAmplifierGainVV_Gain : '<S7>/Inverse Amplifier  Gain (V//V)'
                                        */
  10.0,                                /* DACBSaturationV_UpperSat : '<S7>/DACB Saturation (V)'
                                        */
  -10.0,                               /* DACBSaturationV_LowerSat : '<S7>/DACB Saturation (V)'
                                        */
  -1.0,                                /* AmplifierGainVV_Gain : '<S7>/Amplifier  Gain (V//V)'
                                        */
  -14.1465,                            /* TransferFcn_A : '<S5>/Transfer Fcn'
                                        */
  4.028,                               /* TransferFcn_C : '<S5>/Transfer Fcn'
                                        */
  0.0,                                 /* TransportDelay_Delay : '<S5>/Transport Delay'
                                        */
  0.0,                                 /* TransportDelay_InitOutput : '<S5>/Transport Delay'
                                        */
  0.0,                                 /* RateTransition1_X0_f : '<S1>/Rate Transition1'
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
  0.0,                                 /* Integrator_IC : '<S5>/Integrator'
                                        */
  4.5627352617447486E-001,             /* DiscreteZeroPole_A : '<S1>/Discrete Zero-Pole'
                                        */
  -1.7006877114773758E+001,            /* DiscreteZeroPole_C : '<S1>/Discrete Zero-Pole'
                                        */
  6.9179101425685545E+001,             /* DiscreteZeroPole_D : '<S1>/Discrete Zero-Pole'
                                        */
  4.5627352617447486E-001,             /* DiscreteZeroPole_A_o : '<S2>/Discrete Zero-Pole'
                                        */
  -1.7006877114773758E+001,            /* DiscreteZeroPole_C_i : '<S2>/Discrete Zero-Pole'
                                        */
  6.9179101425685545E+001,             /* DiscreteZeroPole_D_g : '<S2>/Discrete Zero-Pole'
                                        */
  1.0,                                 /* InverseAmplifierGainVV_Gain_h : '<S8>/Inverse Amplifier  Gain (V//V)'
                                        */
  10.0,                                /* DACBSaturationV_UpperSat_g : '<S8>/DACB Saturation (V)'
                                        */
  -10.0,                               /* DACBSaturationV_LowerSat_p : '<S8>/DACB Saturation (V)'
                                        */
  1.0,                                 /* AmplifierGainVV_Gain_e : '<S8>/Amplifier  Gain (V//V)'
                                        */
  24.0,                                /* AmplifierSaturationV_UpperSat_i : '<S8>/Amplifier  Saturation (V)'
                                        */
  -24.0,                               /* AmplifierSaturationV_LowerSat_g : '<S8>/Amplifier  Saturation (V)'
                                        */
  0.087266,                            /* StepAmplitude_Gain : '<Root>/Step Amplitude '
                                        */
  0.087266,                            /* StepAmplitude_Gain_e : '<Root>/Step Amplitude'
                                        */
  -6.1435589670200397E-001,            /* PotentiometerCalibrationradV_Ga : '<S6>/Potentiometer Calibration  (rad//V)'
                                        */

  /*  HILInitialize_CKChannels : '<S6>/HIL Initialize'
   */
  { 0, 1, 2 },
  0,                                   /* HILInitialize_DOWatchdog : '<S6>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIInitial : '<S6>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POModes : '<S6>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POConfiguration : '<S6>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POAlignment : '<S6>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POPolarity : '<S6>/HIL Initialize'
                                        */
  0,                                   /* HILReadAnalogTimebase_Clock : '<S6>/HIL Read Analog Timebase'
                                        */

  /*  HILInitialize_AIChannels : '<S6>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  HILInitialize_AOChannels : '<S6>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  HILInitialize_DOChannels : '<S6>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  HILInitialize_EIChannels : '<S6>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },
  4U,                                  /* HILInitialize_EIQuadrature : '<S6>/HIL Initialize'
                                        */

  /*  HILInitialize_POChannels : '<S6>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  HILReadAnalogTimebase_Channels : '<S6>/HIL Read Analog Timebase'
   */
  { 0U, 1U },
  1000U,                               /* HILReadAnalogTimebase_SamplesIn : '<S6>/HIL Read Analog Timebase'
                                        */
  0U,                                  /* HILReadEncoder_Channels : '<S6>/HIL Read Encoder'
                                        */
  0U,                                  /* HILWriteAnalog_Channels : '<S6>/HIL Write Analog'
                                        */
  1U,                                  /* Constant_Value : '<S3>/Constant'
                                        */
  0U,                                  /* SwitchControl_Threshold : '<S3>/SwitchControl'
                                        */
  0,                                   /* HILInitialize_Active : '<S6>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_CKPStart : '<S6>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_CKPEnter : '<S6>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_AIPStart : '<S6>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AIPEnter : '<S6>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_AOPStart : '<S6>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOPEnter : '<S6>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_AOStart : '<S6>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOEnter : '<S6>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_AOTerminate : '<S6>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOExit : '<S6>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOReset : '<S6>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOPStart : '<S6>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOPEnter : '<S6>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_DOStart : '<S6>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOEnter : '<S6>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_DOTerminate : '<S6>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOExit : '<S6>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOReset : '<S6>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_EIPStart : '<S6>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIPEnter : '<S6>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_EIStart : '<S6>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIEnter : '<S6>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POPStart : '<S6>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POPEnter : '<S6>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POStart : '<S6>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POEnter : '<S6>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POTerminate : '<S6>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POExit : '<S6>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POReset : '<S6>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_OOReset : '<S6>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOInitial : '<S6>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOFinal : '<S6>/HIL Initialize'
                                        */
  1,                                   /* HILReadAnalogTimebase_Active : '<S6>/HIL Read Analog Timebase'
                                        */
  1,                                   /* HILReadEncoder_Active : '<S6>/HIL Read Encoder'
                                        */
  0                                    /* HILWriteAnalog_Active : '<S6>/HIL Write Analog'
                                        */
};
