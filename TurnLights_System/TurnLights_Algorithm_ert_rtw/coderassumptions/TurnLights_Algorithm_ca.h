/*
 * File: TurnLights_Algorithm_ca.h
 *
 * Abstract: Tests assumptions in the generated code.
 */

#ifndef TURNLIGHTS_ALGORITHM_CA_H
#define TURNLIGHTS_ALGORITHM_CA_H

/* preprocessor validation checks */
#include "TurnLights_Algorithm_ca_preproc.h"
#include "coder_assumptions_hwimpl.h"

/* variables holding test results */
extern CA_ChecksTestResults CA_TurnLights_Algorithm_Res;
extern CA_PWS_TestResults CA_TurnLights_Algorithm_PWSRes;

/* variables holding "expected" and "actual" hardware implementation */
extern const CA_Checks CA_TurnLights_Algorithm_Exp;
extern CA_Checks CA_TurnLights_Algorithm_Act;
extern const int numberOfImportedTypes;

/* entry point function to run tests */
void TurnLights_Algorithm_caRunTests(void);

#endif                                 /* TURNLIGHTS_ALGORITHM_CA_H */
