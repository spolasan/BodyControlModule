/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TurnLights_Algorithm.h
 *
 * Code generated for Simulink model 'TurnLights_Algorithm'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Sun Mar 22 12:43:30 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef TurnLights_Algorithm_h_
#define TurnLights_Algorithm_h_
#ifndef TurnLights_Algorithm_COMMON_INCLUDES_
#define TurnLights_Algorithm_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                               /* TurnLights_Algorithm_COMMON_INCLUDES_ */

#include "TurnLights_Algorithm_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int32_T clockTickCounter;            /* '<S1>/Pulse Generator' */
} DW_TurnLights_Algorithm_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  boolean_T LH_TL_SW;                  /* '<Root>/LH_TL_SW' */
  boolean_T RH_TL_SW;                  /* '<Root>/RH_TL_SW' */
  boolean_T HZ_SW;                     /* '<Root>/HZ_SW' */
} ExtU_TurnLights_Algorithm_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T LH_Front_TL;               /* '<Root>/LH_Front_TL' */
  boolean_T LH_Rear_TL;                /* '<Root>/LH_Rear_TL' */
  boolean_T RH_Front_TL;               /* '<Root>/RH_Front_TL' */
  boolean_T RH_Rear_TL;                /* '<Root>/RH_Rear_TL' */
} ExtY_TurnLights_Algorithm_T;

/* Real-time Model Data Structure */
struct tag_RTM_TurnLights_Algorithm_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_TurnLights_Algorithm_T TurnLights_Algorithm_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_TurnLights_Algorithm_T TurnLights_Algorithm_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_TurnLights_Algorithm_T TurnLights_Algorithm_Y;

/* Model entry point functions */
extern void TurnLights_Algorithm_initialize(void);
extern void TurnLights_Algorithm_step(void);
extern void TurnLights_Algorithm_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TurnLights_Algorithm_T *const TurnLights_Algorithm_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('TurnLights_Model/TurnLights_Algorithm')    - opens subsystem TurnLights_Model/TurnLights_Algorithm
 * hilite_system('TurnLights_Model/TurnLights_Algorithm/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'TurnLights_Model'
 * '<S1>'   : 'TurnLights_Model/TurnLights_Algorithm'
 * '<S2>'   : 'TurnLights_Model/TurnLights_Algorithm/Subsystem'
 */
#endif                                 /* TurnLights_Algorithm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
