/*
 * identifica_srv02l_AutomatizaFuncaoDiscreta_dt.h
 *
 * Real-Time Workshop code generation for Simulink model "identifica_srv02l_AutomatizaFuncaoDiscreta.mdl".
 *
 * Model Version              : 1.284
 * Real-Time Workshop version : 7.2  (R2008b)  04-Aug-2008
 * C source code generated on : Tue Jun 17 06:54:36 2025
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_task),
  sizeof(t_card)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_task",
  "t_card"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&identifica_srv02l_AutomatizaF_B.HILReadAnalogTimebase_o1), 0, 0,
    31 }
  ,

  { (char_T *)(&identifica_srv02l_Automat_DWork.DiscreteZeroPole_DSTATE), 0, 0,
    69 },

  { (char_T *)(&identifica_srv02l_Automat_DWork.HILReadEncoder_PWORK), 11, 0, 10
  },

  { (char_T *)(&identifica_srv02l_Automat_DWork.HILInitialize_ClockModes[0]), 6,
    0, 52 },

  { (char_T *)(&identifica_srv02l_Automat_DWork.HILInitialize_POSortedChans[0]),
    7, 0, 8 },

  { (char_T *)(&identifica_srv02l_Automat_DWork.HILReadAnalogTimebase_Task), 14,
    0, 1 },

  { (char_T *)(&identifica_srv02l_Automat_DWork.HILInitialize_Card), 15, 0, 1 },

  { (char_T *)(&identifica_srv02l_Automat_DWork.TransportDelay_IWORK.Tail), 10,
    0, 1 },

  { (char_T *)(&identifica_srv02l_Automat_DWork.HILInitialize_DOBits[0]), 8, 0,
    8 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  9U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&identifica_srv02l_AutomatizaF_P.HILInitialize_OOStart), 0, 0, 56
  },

  { (char_T *)(&identifica_srv02l_AutomatizaF_P.HILInitialize_CKChannels[0]), 6,
    0, 10 },

  { (char_T *)(&identifica_srv02l_AutomatizaF_P.HILInitialize_AIChannels[0]), 7,
    0, 46 },

  { (char_T *)(&identifica_srv02l_AutomatizaF_P.Constant_Value), 3, 0, 2 },

  { (char_T *)(&identifica_srv02l_AutomatizaF_P.HILInitialize_Active), 8, 0, 36
  }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] identifica_srv02l_AutomatizaFuncaoDiscreta_dt.h */
