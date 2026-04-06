/*
 * File: coder_assumptions.h
 *
 * Abstract: Coder assumptions header file
 */

#ifndef CODER_ASSUMPTIONS_H
#define CODER_ASSUMPTIONS_H

/* include model specific checks */
#include "TurnLights_Algorithm_ca.h"

/* global results variable mapping for static code */
#define CA_Expected                    CA_TurnLights_Algorithm_Exp
#define CA_Actual                      CA_TurnLights_Algorithm_Act
#define CA_TestResults                 CA_TurnLights_Algorithm_Res
#define CA_PortableWordSizes_Results   CA_TurnLights_Algorithm_PWSRes

/* entry point function mapping for static code */
#define CA_Run_Tests                   TurnLights_Algorithm_caRunTests
#define CA_MODEL_SPECIFIC_CHECKS_ENABLED 0
#endif                                 /* CODER_ASSUMPTIONS_H */
