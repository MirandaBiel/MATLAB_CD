/*
 * identifica_srv02l_TesteReal.h
 *
 * Real-Time Workshop code generation for Simulink model "identifica_srv02l_TesteReal.mdl".
 *
 * Model Version              : 1.288
 * Real-Time Workshop version : 7.2  (R2008b)  04-Aug-2008
 * C source code generated on : Tue Jun 17 07:09:34 2025
 */
#ifndef RTW_HEADER_identifica_srv02l_TesteReal_h_
#define RTW_HEADER_identifica_srv02l_TesteReal_h_
#ifndef identifica_srv02l_TesteReal_COMMON_INCLUDES_
# define identifica_srv02l_TesteReal_COMMON_INCLUDES_
#include <float.h>
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "hil.h"
#include "quanser_messages.h"
#include "dynamic_reconfiguration.h"
#include "quanser_extern.h"
#include "rt_SATURATE.h"
#include "rt_nonfinite.h"
#endif                                 /* identifica_srv02l_TesteReal_COMMON_INCLUDES_ */

#include "identifica_srv02l_TesteReal_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ((rtm)->Timing.mdlref_GlobalTID)
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ((rtm)->Timing.mdlref_GlobalTID = (val))
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ((rtm)->Timing.mdlref_TriggerTID)
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ((rtm)->Timing.mdlref_TriggerTID = (val))
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ((rtm)->ModelData.paramIsMalloced)
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ((rtm)->ModelData.paramIsMalloced = (val))
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ((rtm)->Timing.RateInteraction)
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ((rtm)->Timing.RateInteraction = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ((rtm)->modelMethodsInfo)
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ((rtm)->modelMethodsInfo = (val))
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->Work.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->Work.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->Work.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->Work.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTime
# define rtmGetVarNextHitTime(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTime
# define rtmSetVarNextHitTime(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) <= 1)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) (((rtm)->Timing.sampleTimeTaskIDPtr[sti] == (tid)))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define identifica_srv02l_TesteReal_rtModel RT_MODEL_identifica_srv02l_Test

/* Block signals (auto storage) */
typedef struct {
  real_T HILReadAnalogTimebase_o1;     /* '<S6>/HIL Read Analog Timebase' */
  real_T HILReadAnalogTimebase_o2;     /* '<S6>/HIL Read Analog Timebase' */
  real_T HILReadEncoder;               /* '<S6>/HIL Read Encoder' */
  real_T EncoderCalibrationradcount;   /* '<S6>/Encoder Calibration  (rad//count)' */
  real_T EncoderHighPassFilter;        /* '<S6>/Encoder High-Pass Filter' */
  real_T PositionSourceSwitch;         /* '<S6>/Position Source Switch' */
  real_T TachometerCalibrationradsV;   /* '<S6>/Tachometer Calibration  (rad//s//V)' */
  real_T VelocitySourceSwitch;         /* '<S6>/Velocity Source Switch' */
  real_T RateTransition1;              /* '<S2>/Rate Transition1' */
  real_T DirectionConventionRightHandsys;/* '<S7>/Direction Convention: (Right-Hand) system' */
  real_T AmplifierSaturationV;         /* '<S7>/Amplifier  Saturation (V)' */
  real_T InverseAmplifierGainVV;       /* '<S7>/Inverse Amplifier  Gain (V//V)' */
  real_T DACBSaturationV;              /* '<S7>/DACB Saturation (V)' */
  real_T AmplifierGainVV;              /* '<S7>/Amplifier  Gain (V//V)' */
  real_T TransferFcn;                  /* '<S5>/Transfer Fcn' */
  real_T TransportDelay;               /* '<S5>/Transport Delay' */
  real_T RateTransition1_n;            /* '<S1>/Rate Transition1' */
  real_T SquareWave;                   /* '<Root>/Square Wave' */
  real_T Step;                         /* '<Root>/Step' */
  real_T MultiportSwitch;              /* '<Root>/Multiport Switch' */
  real_T SwitchControl;                /* '<S3>/SwitchControl' */
  real_T Integrator;                   /* '<S5>/Integrator' */
  real_T Sum;                          /* '<Root>/Sum' */
  real_T RateTransition;               /* '<S1>/Rate Transition' */
  real_T DiscreteZeroPole;             /* '<S1>/Discrete Zero-Pole' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T RateTransition_e;             /* '<S2>/Rate Transition' */
  real_T DiscreteZeroPole_c;           /* '<S2>/Discrete Zero-Pole' */
  real_T InverseAmplifierGainVV_i;     /* '<S8>/Inverse Amplifier  Gain (V//V)' */
  real_T DACBSaturationV_c;            /* '<S8>/DACB Saturation (V)' */
  real_T AmplifierGainVV_b;            /* '<S8>/Amplifier  Gain (V//V)' */
  real_T AmplifierSaturationV_c;       /* '<S8>/Amplifier  Saturation (V)' */
  real_T PotentiometerCalibrationradV; /* '<S6>/Potentiometer Calibration  (rad//V)' */
  real_T StepAmplitude;                /* '<Root>/Step Amplitude' */
  real_T StepAmplitude_o;              /* '<Root>/Step Amplitude ' */
} BlockIO_identifica_srv02l_Teste;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteZeroPole_DSTATE;      /* '<S1>/Discrete Zero-Pole' */
  real_T DiscreteZeroPole_DSTATE_a;    /* '<S2>/Discrete Zero-Pole' */
  real_T HILInitialize_AIMinimums[8];  /* '<S6>/HIL Initialize' */
  real_T HILInitialize_AIMaximums[8];  /* '<S6>/HIL Initialize' */
  real_T HILInitialize_AOMinimums[8];  /* '<S6>/HIL Initialize' */
  real_T HILInitialize_AOMaximums[8];  /* '<S6>/HIL Initialize' */
  real_T HILInitialize_AOVoltages[8];  /* '<S6>/HIL Initialize' */
  real_T HILInitialize_FilterFrequency[8];/* '<S6>/HIL Initialize' */
  real_T HILInitialize_POSortedFreqs[8];/* '<S6>/HIL Initialize' */
  real_T HILInitialize_POValues[8];    /* '<S6>/HIL Initialize' */
  real_T HILReadAnalogTimebase_Buffer[2];/* '<S6>/HIL Read Analog Timebase' */
  real_T RateTransition1_Buffer0;      /* '<S2>/Rate Transition1' */
  real_T RateTransition1_Buffer0_i;    /* '<S1>/Rate Transition1' */
  struct {
    real_T modelTStart;
    real_T TUbufferArea[2048];
  } TransportDelay_RWORK;              /* '<S5>/Transport Delay' */

  void *HILReadEncoder_PWORK;          /* '<S6>/HIL Read Encoder' */
  void *HILWriteAnalog_PWORK;          /* '<S6>/HIL Write Analog' */
  struct {
    void *TUbufferPtrs[2];
  } TransportDelay_PWORK;              /* '<S5>/Transport Delay' */

  struct {
    void *LoggedData;
  } ToWorkspaceModeloExperimental_P;   /* '<Root>/To Workspace Modelo Experimental' */

  struct {
    void *LoggedData;
  } ToWorkspaceSistemaReal_PWORK;      /* '<Root>/To Workspace Sistema Real' */

  struct {
    void *LoggedData;
  } VmV_PWORK;                         /* '<Root>/Vm (V)' */

  struct {
    void *LoggedData;
  } VmV1_PWORK;                        /* '<Root>/Vm (V)1' */

  struct {
    void *LoggedData;
  } theta_lrad_PWORK;                  /* '<Root>/theta_l (rad)' */

  struct {
    void *LoggedData;
  } w_lrads_PWORK;                     /* '<Root>/w_l (rad//s)' */

  int32_T HILInitialize_ClockModes[3]; /* '<S6>/HIL Initialize' */
  int32_T HILInitialize_DOStates[8];   /* '<S6>/HIL Initialize' */
  int32_T HILInitialize_QuadratureModes[8];/* '<S6>/HIL Initialize' */
  int32_T HILInitialize_InitialEICounts[8];/* '<S6>/HIL Initialize' */
  int32_T HILInitialize_POModeValues[8];/* '<S6>/HIL Initialize' */
  int32_T HILInitialize_POAlignValues[8];/* '<S6>/HIL Initialize' */
  int32_T HILInitialize_POPolarityVals[8];/* '<S6>/HIL Initialize' */
  int32_T HILReadEncoder_Buffer;       /* '<S6>/HIL Read Encoder' */
  uint32_T HILInitialize_POSortedChans[8];/* '<S6>/HIL Initialize' */
  t_task HILReadAnalogTimebase_Task;   /* '<S6>/HIL Read Analog Timebase' */
  t_card HILInitialize_Card;           /* '<S6>/HIL Initialize' */
  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TransportDelay_IWORK;              /* '<S5>/Transport Delay' */

  boolean_T HILInitialize_DOBits[8];   /* '<S6>/HIL Initialize' */
} D_Work_identifica_srv02l_TesteR;

/* Continuous states (auto storage) */
typedef struct {
  real_T EncoderHighPassFilter_CSTATE[2];/* '<S6>/Encoder High-Pass Filter' */
  real_T TransferFcn_CSTATE;           /* '<S5>/Transfer Fcn' */
  real_T Integrator_CSTATE;            /* '<S5>/Integrator' */
} ContinuousStates_identifica_srv;

/* State derivatives (auto storage) */
typedef struct {
  real_T EncoderHighPassFilter_CSTATE[2];/* '<S6>/Encoder High-Pass Filter' */
  real_T TransferFcn_CSTATE;           /* '<S5>/Transfer Fcn' */
  real_T Integrator_CSTATE;            /* '<S5>/Integrator' */
} StateDerivatives_identifica_srv;

/* State disabled  */
typedef struct {
  boolean_T EncoderHighPassFilter_CSTATE[2];/* '<S6>/Encoder High-Pass Filter' */
  boolean_T TransferFcn_CSTATE;        /* '<S5>/Transfer Fcn' */
  boolean_T Integrator_CSTATE;         /* '<S5>/Integrator' */
} StateDisabled_identifica_srv02l;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            identifica_srv02l_TesteReal_B
#define BlockIO                        BlockIO_identifica_srv02l_Teste
#define rtX                            identifica_srv02l_TesteReal_X
#define ContinuousStates               ContinuousStates_identifica_srv
#define rtP                            identifica_srv02l_TesteReal_P
#define Parameters                     Parameters_identifica_srv02l_Te
#define rtDWork                        identifica_srv02l_TesteRe_DWork
#define D_Work                         D_Work_identifica_srv02l_TesteR

/* Parameters (auto storage) */
struct Parameters_identifica_srv02l_Te_ {
  real_T HILInitialize_OOStart;        /* Expression: set_other_outputs_at_start
                                        * '<S6>/HIL Initialize'
                                        */
  real_T HILInitialize_OOEnter;        /* Expression: set_other_outputs_at_switch_in
                                        * '<S6>/HIL Initialize'
                                        */
  real_T HILInitialize_OOTerminate;    /* Expression: set_other_outputs_at_terminate
                                        * '<S6>/HIL Initialize'
                                        */
  real_T HILInitialize_OOExit;         /* Expression: set_other_outputs_at_switch_out
                                        * '<S6>/HIL Initialize'
                                        */
  real_T HILInitialize_AIHigh;         /* Expression: analog_input_maximums
                                        * '<S6>/HIL Initialize'
                                        */
  real_T HILInitialize_AILow;          /* Expression: analog_input_minimums
                                        * '<S6>/HIL Initialize'
                                        */
  real_T HILInitialize_AOHigh;         /* Expression: analog_output_maximums
                                        * '<S6>/HIL Initialize'
                                        */
  real_T HILInitialize_AOLow;          /* Expression: analog_output_minimums
                                        * '<S6>/HIL Initialize'
                                        */
  real_T HILInitialize_AOInitial;      /* Expression: initial_analog_outputs
                                        * '<S6>/HIL Initialize'
                                        */
  real_T HILInitialize_AOFinal;        /* Expression: final_analog_outputs
                                        * '<S6>/HIL Initialize'
                                        */
  real_T HILInitialize_AOWatchdog;     /* Expression: watchdog_analog_outputs
                                        * '<S6>/HIL Initialize'
                                        */
  real_T HILInitialize_POFrequency;    /* Expression: pwm_frequency
                                        * '<S6>/HIL Initialize'
                                        */
  real_T HILInitialize_POLeading;      /* Expression: pwm_leading_deadband
                                        * '<S6>/HIL Initialize'
                                        */
  real_T HILInitialize_POTrailing;     /* Expression: pwm_trailing_deadband
                                        * '<S6>/HIL Initialize'
                                        */
  real_T HILInitialize_POInitial;      /* Expression: initial_pwm_outputs
                                        * '<S6>/HIL Initialize'
                                        */
  real_T HILInitialize_POFinal;        /* Expression: final_pwm_outputs
                                        * '<S6>/HIL Initialize'
                                        */
  real_T HILInitialize_POWatchdog;     /* Expression: watchdog_pwm_outputs
                                        * '<S6>/HIL Initialize'
                                        */
  real_T EncoderCalibrationradcount_Gain;/* Expression: -K_ENC
                                          * '<S6>/Encoder Calibration  (rad//count)'
                                          */
  real_T EncoderHighPassFilter_A[2];   /* Computed Parameter: A
                                        * '<S6>/Encoder High-Pass Filter'
                                        */
  real_T EncoderHighPassFilter_C[2];   /* Computed Parameter: C
                                        * '<S6>/Encoder High-Pass Filter'
                                        */
  real_T PosSrc_Value;                 /* Expression: 2
                                        * '<S4>/Pos Src'
                                        */
  real_T TachometerCalibrationradsV_Gain;/* Expression: K_TACH
                                          * '<S6>/Tachometer Calibration  (rad//s//V)'
                                          */
  real_T SpdSrc_Value;                 /* Expression: 2
                                        * '<Root>/Spd Src'
                                        */
  real_T RateTransition1_X0;           /* Expression: 0
                                        * '<S2>/Rate Transition1'
                                        */
  real_T DirectionConventionRightHandsys;/* Expression: -1
                                          * '<S7>/Direction Convention: (Right-Hand) system'
                                          */
  real_T AmplifierSaturationV_UpperSat;/* Expression: VMAX_AMP
                                        * '<S7>/Amplifier  Saturation (V)'
                                        */
  real_T AmplifierSaturationV_LowerSat;/* Expression: -VMAX_AMP
                                        * '<S7>/Amplifier  Saturation (V)'
                                        */
  real_T InverseAmplifierGainVV_Gain;  /* Expression: 1/K_AMP
                                        * '<S7>/Inverse Amplifier  Gain (V//V)'
                                        */
  real_T DACBSaturationV_UpperSat;     /* Expression: VMAX_DAC
                                        * '<S7>/DACB Saturation (V)'
                                        */
  real_T DACBSaturationV_LowerSat;     /* Expression: -VMAX_DAC
                                        * '<S7>/DACB Saturation (V)'
                                        */
  real_T AmplifierGainVV_Gain;         /* Expression: -K_AMP
                                        * '<S7>/Amplifier  Gain (V//V)'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: A
                                        * '<S5>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: C
                                        * '<S5>/Transfer Fcn'
                                        */
  real_T TransportDelay_Delay;         /* Expression: L
                                        * '<S5>/Transport Delay'
                                        */
  real_T TransportDelay_InitOutput;    /* Expression: 0
                                        * '<S5>/Transport Delay'
                                        */
  real_T RateTransition1_X0_f;         /* Expression: 0
                                        * '<S1>/Rate Transition1'
                                        */
  real_T Definesinaldeentrada_Value;   /* Expression: 2
                                        * '<Root>/Define sinal de entrada'
                                        */
  real_T SquareWave_Amplitude;         /* Expression: 1
                                        * '<Root>/Square Wave'
                                        */
  real_T SquareWave_Frequency;         /* Expression: 5
                                        * '<Root>/Square Wave'
                                        */
  real_T Step_Time;                    /* Expression: 0.5
                                        * '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * '<Root>/Step'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * '<S5>/Integrator'
                                        */
  real_T DiscreteZeroPole_A;           /* Computed Parameter: A
                                        * '<S1>/Discrete Zero-Pole'
                                        */
  real_T DiscreteZeroPole_C;           /* Computed Parameter: C
                                        * '<S1>/Discrete Zero-Pole'
                                        */
  real_T DiscreteZeroPole_D;           /* Computed Parameter: D
                                        * '<S1>/Discrete Zero-Pole'
                                        */
  real_T DiscreteZeroPole_A_o;         /* Computed Parameter: A
                                        * '<S2>/Discrete Zero-Pole'
                                        */
  real_T DiscreteZeroPole_C_i;         /* Computed Parameter: C
                                        * '<S2>/Discrete Zero-Pole'
                                        */
  real_T DiscreteZeroPole_D_g;         /* Computed Parameter: D
                                        * '<S2>/Discrete Zero-Pole'
                                        */
  real_T InverseAmplifierGainVV_Gain_h;/* Expression: 1/K_AMP
                                        * '<S8>/Inverse Amplifier  Gain (V//V)'
                                        */
  real_T DACBSaturationV_UpperSat_g;   /* Expression: VMAX_DAC
                                        * '<S8>/DACB Saturation (V)'
                                        */
  real_T DACBSaturationV_LowerSat_p;   /* Expression: -VMAX_DAC
                                        * '<S8>/DACB Saturation (V)'
                                        */
  real_T AmplifierGainVV_Gain_e;       /* Expression: K_AMP
                                        * '<S8>/Amplifier  Gain (V//V)'
                                        */
  real_T AmplifierSaturationV_UpperSat_i;/* Expression: VMAX_AMP
                                          * '<S8>/Amplifier  Saturation (V)'
                                          */
  real_T AmplifierSaturationV_LowerSat_g;/* Expression: -VMAX_AMP
                                          * '<S8>/Amplifier  Saturation (V)'
                                          */
  real_T StepAmplitude_Gain;           /* Expression: 0.087266
                                        * '<Root>/Step Amplitude '
                                        */
  real_T StepAmplitude_Gain_e;         /* Expression: 0.087266
                                        * '<Root>/Step Amplitude'
                                        */
  real_T PotentiometerCalibrationradV_Ga;/* Expression: K_POT
                                          * '<S6>/Potentiometer Calibration  (rad//V)'
                                          */
  int32_T HILInitialize_CKChannels[3]; /* Computed Parameter: CKChannels
                                        * '<S6>/HIL Initialize'
                                        */
  int32_T HILInitialize_DOWatchdog;    /* Computed Parameter: DOWatchdog
                                        * '<S6>/HIL Initialize'
                                        */
  int32_T HILInitialize_EIInitial;     /* Computed Parameter: EIInitial
                                        * '<S6>/HIL Initialize'
                                        */
  int32_T HILInitialize_POModes;       /* Computed Parameter: POModes
                                        * '<S6>/HIL Initialize'
                                        */
  int32_T HILInitialize_POConfiguration;/* Computed Parameter: POConfiguration
                                         * '<S6>/HIL Initialize'
                                         */
  int32_T HILInitialize_POAlignment;   /* Computed Parameter: POAlignment
                                        * '<S6>/HIL Initialize'
                                        */
  int32_T HILInitialize_POPolarity;    /* Computed Parameter: POPolarity
                                        * '<S6>/HIL Initialize'
                                        */
  int32_T HILReadAnalogTimebase_Clock; /* Computed Parameter: Clock
                                        * '<S6>/HIL Read Analog Timebase'
                                        */
  uint32_T HILInitialize_AIChannels[8];/* Computed Parameter: AIChannels
                                        * '<S6>/HIL Initialize'
                                        */
  uint32_T HILInitialize_AOChannels[8];/* Computed Parameter: AOChannels
                                        * '<S6>/HIL Initialize'
                                        */
  uint32_T HILInitialize_DOChannels[8];/* Computed Parameter: DOChannels
                                        * '<S6>/HIL Initialize'
                                        */
  uint32_T HILInitialize_EIChannels[8];/* Computed Parameter: EIChannels
                                        * '<S6>/HIL Initialize'
                                        */
  uint32_T HILInitialize_EIQuadrature; /* Computed Parameter: EIQuadrature
                                        * '<S6>/HIL Initialize'
                                        */
  uint32_T HILInitialize_POChannels[8];/* Computed Parameter: POChannels
                                        * '<S6>/HIL Initialize'
                                        */
  uint32_T HILReadAnalogTimebase_Channels[2];/* Computed Parameter: Channels
                                              * '<S6>/HIL Read Analog Timebase'
                                              */
  uint32_T HILReadAnalogTimebase_SamplesIn;/* Computed Parameter: SamplesInBuffer
                                            * '<S6>/HIL Read Analog Timebase'
                                            */
  uint32_T HILReadEncoder_Channels;    /* Computed Parameter: Channels
                                        * '<S6>/HIL Read Encoder'
                                        */
  uint32_T HILWriteAnalog_Channels;    /* Computed Parameter: Channels
                                        * '<S6>/HIL Write Analog'
                                        */
  uint8_T Constant_Value;              /* Expression: uint8(1)
                                        * '<S3>/Constant'
                                        */
  uint8_T SwitchControl_Threshold;     /* Expression: uint8(0)
                                        * '<S3>/SwitchControl'
                                        */
  boolean_T HILInitialize_Active;      /* Computed Parameter: Active
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_CKPStart;    /* Computed Parameter: CKPStart
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_CKPEnter;    /* Computed Parameter: CKPEnter
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AIPStart;    /* Computed Parameter: AIPStart
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AIPEnter;    /* Computed Parameter: AIPEnter
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOPStart;    /* Computed Parameter: AOPStart
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOPEnter;    /* Computed Parameter: AOPEnter
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOStart;     /* Computed Parameter: AOStart
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOEnter;     /* Computed Parameter: AOEnter
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOTerminate; /* Computed Parameter: AOTerminate
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOExit;      /* Computed Parameter: AOExit
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_AOReset;     /* Computed Parameter: AOReset
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOPStart;    /* Computed Parameter: DOPStart
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOPEnter;    /* Computed Parameter: DOPEnter
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOStart;     /* Computed Parameter: DOStart
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOEnter;     /* Computed Parameter: DOEnter
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOTerminate; /* Computed Parameter: DOTerminate
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOExit;      /* Computed Parameter: DOExit
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOReset;     /* Computed Parameter: DOReset
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIPStart;    /* Computed Parameter: EIPStart
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIPEnter;    /* Computed Parameter: EIPEnter
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIStart;     /* Computed Parameter: EIStart
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_EIEnter;     /* Computed Parameter: EIEnter
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POPStart;    /* Computed Parameter: POPStart
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POPEnter;    /* Computed Parameter: POPEnter
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POStart;     /* Computed Parameter: POStart
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POEnter;     /* Computed Parameter: POEnter
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POTerminate; /* Computed Parameter: POTerminate
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POExit;      /* Computed Parameter: POExit
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_POReset;     /* Computed Parameter: POReset
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_OOReset;     /* Computed Parameter: OOReset
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOInitial;   /* Computed Parameter: DOInitial
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILInitialize_DOFinal;     /* Computed Parameter: DOFinal
                                        * '<S6>/HIL Initialize'
                                        */
  boolean_T HILReadAnalogTimebase_Active;/* Computed Parameter: Active
                                          * '<S6>/HIL Read Analog Timebase'
                                          */
  boolean_T HILReadEncoder_Active;     /* Computed Parameter: Active
                                        * '<S6>/HIL Read Encoder'
                                        */
  boolean_T HILWriteAnalog_Active;     /* Computed Parameter: Active
                                        * '<S6>/HIL Write Analog'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_identifica_srv02l_Test {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    real_T *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    real_T *derivs;
    real_T *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeF[1][4];
    ODE1_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    time_T stepSize2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID0_2;
      boolean_T TID1_2;
    } RateInteraction;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[3];
    time_T offsetTimesArray[3];
    int_T sampleTimeTaskIDArray[3];
    int_T sampleHitArray[3];
    int_T perTaskSampleHitsArray[9];
    time_T tArray[3];
  } Timing;

  /*
   * Work:
   * The following substructure contains information regarding
   * the work vectors in the model.
   */
  struct {
    void *dwork;
  } Work;
};

/* Block parameters (auto storage) */
extern Parameters_identifica_srv02l_Te identifica_srv02l_TesteReal_P;

/* Block signals (auto storage) */
extern BlockIO_identifica_srv02l_Teste identifica_srv02l_TesteReal_B;

/* Continuous states (auto storage) */
extern ContinuousStates_identifica_srv identifica_srv02l_TesteReal_X;

/* Block states (auto storage) */
extern D_Work_identifica_srv02l_TesteR identifica_srv02l_TesteRe_DWork;

/* External function called from main */
extern time_T rt_SimUpdateDiscreteEvents(int_T rtmNumSampTimes,
  void *rtmTimingData,
  int_T *rtmSampleHitPtr,
  int_T *rtmPerTaskSampleHits)
  ;

/* Model entry point functions */
extern void identifica_srv02l_TesteReal_SetEventsForThisBaseStep(boolean_T
  *eventFlags);
extern void identifica_srv02l_TesteReal_initialize(boolean_T firstTime);
extern void identifica_srv02l_TesteReal_output(int_T tid);
extern void identifica_srv02l_TesteReal_update(int_T tid);
extern void identifica_srv02l_TesteReal_output0(int_T tid);
extern void identifica_srv02l_TesteReal_terminate(void);

/* Real-time Model object */
extern RT_MODEL_identifica_srv02l_Test *identifica_srv02l_TesteReal_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : identifica_srv02l_TesteReal
 * '<S1>'   : identifica_srv02l_TesteReal/Controlador
 * '<S2>'   : identifica_srv02l_TesteReal/Controlador1
 * '<S3>'   : identifica_srv02l_TesteReal/Manual Switch 1
 * '<S4>'   : identifica_srv02l_TesteReal/SRV02
 * '<S5>'   : identifica_srv02l_TesteReal/SRV02 Modelo Experimental
 * '<S6>'   : identifica_srv02l_TesteReal/SRV02/SRV02-ET
 * '<S7>'   : identifica_srv02l_TesteReal/SRV02/SRV02-ET/Actuator Electrical  Dynamics
 * '<S8>'   : identifica_srv02l_TesteReal/SRV02 Modelo Experimental/Actuator Dynamics
 */
#endif                                 /* RTW_HEADER_identifica_srv02l_TesteReal_h_ */
