/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TurnLights_Algorithm.c
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

#include "TurnLights_Algorithm.h"
#include "rtwtypes.h"

/* Block states (default storage) */
DW_TurnLights_Algorithm_T TurnLights_Algorithm_DW;

/* External inputs (root inport signals with default storage) */
ExtU_TurnLights_Algorithm_T TurnLights_Algorithm_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_TurnLights_Algorithm_T TurnLights_Algorithm_Y;

/* Real-time model */
static RT_MODEL_TurnLights_Algorithm_T TurnLights_Algorithm_M_;
RT_MODEL_TurnLights_Algorithm_T *const TurnLights_Algorithm_M =
  &TurnLights_Algorithm_M_;

/* Model step function */
void TurnLights_Algorithm_step(void)
{
  int32_T rtb_PulseGenerator;
  boolean_T rtb_NOT_HAZARD;
  boolean_T rtb_Switch;
  boolean_T rtb_Switch_tmp;
  boolean_T rtb_Switch_tmp_0;

  /* Outputs for Atomic SubSystem: '<Root>/TurnLights_Algorithm' */
  /* DiscretePulseGenerator: '<S1>/Pulse Generator' */
  rtb_PulseGenerator = ((TurnLights_Algorithm_DW.clockTickCounter < 1) &&
                        (TurnLights_Algorithm_DW.clockTickCounter >= 0));
  if (TurnLights_Algorithm_DW.clockTickCounter >= 1) {
    TurnLights_Algorithm_DW.clockTickCounter = 0;
  } else {
    TurnLights_Algorithm_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Pulse Generator' */

  /* Logic: '<S2>/NOT_HAZARD' incorporates:
   *  Inport: '<Root>/HZ_SW'
   */
  rtb_NOT_HAZARD = !TurnLights_Algorithm_U.HZ_SW;

  /* Logic: '<S2>/AND2' incorporates:
   *  Inport: '<Root>/LH_TL_SW'
   *  Inport: '<Root>/RH_TL_SW'
   *  Logic: '<S2>/NOT_LH'
   *  Logic: '<S2>/NOT_RH'
   */
  rtb_Switch_tmp = !TurnLights_Algorithm_U.RH_TL_SW;
  rtb_Switch_tmp_0 = !TurnLights_Algorithm_U.LH_TL_SW;

  /* Switch: '<S2>/Switch' incorporates:
   *  Inport: '<Root>/HZ_SW'
   *  Logic: '<S2>/AND2'
   */
  rtb_Switch = ((rtb_Switch_tmp_0 || rtb_Switch_tmp) &&
                TurnLights_Algorithm_U.HZ_SW);

  /* Logic: '<S1>/AND' incorporates:
   *  Inport: '<Root>/LH_TL_SW'
   *  Logic: '<S1>/LeftSide_Enable'
   *  Logic: '<S2>/AND'
   */
  TurnLights_Algorithm_Y.LH_Front_TL = ((rtb_PulseGenerator != 0) &&
    ((TurnLights_Algorithm_U.LH_TL_SW && rtb_Switch_tmp && rtb_NOT_HAZARD) ||
     rtb_Switch));

  /* Logic: '<S1>/AND1' incorporates:
   *  Inport: '<Root>/RH_TL_SW'
   *  Logic: '<S1>/RightSide_Enable'
   *  Logic: '<S2>/AND1'
   */
  TurnLights_Algorithm_Y.RH_Front_TL = ((rtb_PulseGenerator != 0) &&
    ((rtb_Switch_tmp_0 && TurnLights_Algorithm_U.RH_TL_SW && rtb_NOT_HAZARD) ||
     rtb_Switch));

  /* Outport: '<Root>/LH_Rear_TL' incorporates:
   *  Logic: '<S1>/NOT'
   */
  TurnLights_Algorithm_Y.LH_Rear_TL = TurnLights_Algorithm_Y.LH_Front_TL;

  /* Outport: '<Root>/RH_Rear_TL' incorporates:
   *  Logic: '<S1>/NOT2'
   */
  TurnLights_Algorithm_Y.RH_Rear_TL = TurnLights_Algorithm_Y.RH_Front_TL;

  /* End of Outputs for SubSystem: '<Root>/TurnLights_Algorithm' */
}

/* Model initialize function */
void TurnLights_Algorithm_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void TurnLights_Algorithm_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
