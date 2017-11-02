/**
 * @license    BSD 3-Clause
 * @copyright  microHAL
 * @version    $Id$
 * @brief
 *
 * @authors    kamil
 * created on: 15-08-2017
 * last modification: 15-08-2017
 *
 * @copyright Copyright (c) 2017, microHAL
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 *     1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 *     2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the
 *        documentation and/or other materials provided with the distribution.
 *     3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this
 *        software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* **************************************************************************************************************************************************
 * INCLUDES
 */

#include "TouchController.h"
#include "TouchControllerInternals.h"

//==============================================================================
// TSL Common Parameters placed in RAM or ROM
// --> external declaration in tsl_conf.h
//==============================================================================
TSL_Params_T TSL_Params = {
    TSLPRM_ACQ_MIN,
    TSLPRM_ACQ_MAX,
    TSLPRM_CALIB_SAMPLES,
    TSLPRM_DTO,
#if TSLPRM_TOTAL_TKEYS > 0
    TouchLib::Internals::TKeys_StateMachine,  // Default state machine for TKeys
    &TouchLib::Internals::TKeys_Methods,      // Default methods for TKeys
#endif
#if TSLPRM_TOTAL_LNRTS > 0
    TouchLib::Internals::LinRots_StateMachine,  // Default state machine for LinRots
    &TouchLib::Internals::LinRots_Methods       // Default methods for LinRots
#endif
};

namespace TouchLib {

namespace Internals {
static void ErrorStateProcess(void) {}
static void OffStateProcess(void) {}

// Data (RAM)
TSL_ChannelData_T Channels_Data[TSLPRM_TOTAL_CHANNELS];

//==============================================================================
// TouchKeys
//==============================================================================
CONST TSL_State_T TKeys_StateMachine[] = {
    // Calibration states
    /*  0 */ {TSL_STATEMASK_CALIB, TSL_tkey_CalibrationStateProcess},
    /*  1 */ {TSL_STATEMASK_DEB_CALIB, TSL_tkey_DebCalibrationStateProcess},
    // Release states
    /*  2 */ {TSL_STATEMASK_RELEASE, TSL_tkey_ReleaseStateProcess},
#if TSLPRM_USE_PROX > 0
    /*  3 */ {TSL_STATEMASK_DEB_RELEASE_PROX, TSL_tkey_DebReleaseProxStateProcess},
#else
    /*  3 */ {TSL_STATEMASK_DEB_RELEASE_PROX, 0},
#endif
    /*  4 */ {TSL_STATEMASK_DEB_RELEASE_DETECT, TSL_tkey_DebReleaseDetectStateProcess},
    /*  5 */ {TSL_STATEMASK_DEB_RELEASE_TOUCH, TSL_tkey_DebReleaseTouchStateProcess},
#if TSLPRM_USE_PROX > 0
    // Proximity states
    /*  6 */ {TSL_STATEMASK_PROX, TSL_tkey_ProxStateProcess},
    /*  7 */ {TSL_STATEMASK_DEB_PROX, TSL_tkey_DebProxStateProcess},
    /*  8 */ {TSL_STATEMASK_DEB_PROX_DETECT, TSL_tkey_DebProxDetectStateProcess},
    /*  9 */ {TSL_STATEMASK_DEB_PROX_TOUCH, TSL_tkey_DebProxTouchStateProcess},
#else
    /*  6 */ {TSL_STATEMASK_PROX, 0},
    /*  7 */ {TSL_STATEMASK_DEB_PROX, 0},
    /*  8 */ {TSL_STATEMASK_DEB_PROX_DETECT, 0},
    /*  9 */ {TSL_STATEMASK_DEB_PROX_TOUCH, 0},
#endif
    // Detect states
    /* 10 */ {TSL_STATEMASK_DETECT, TSL_tkey_DetectStateProcess},
    /* 11 */ {TSL_STATEMASK_DEB_DETECT, TSL_tkey_DebDetectStateProcess},
    // Touch state
    /* 12 */ {TSL_STATEMASK_TOUCH, TSL_tkey_TouchStateProcess},
    // Error states
    /* 13 */ {TSL_STATEMASK_ERROR, ErrorStateProcess},
    /* 14 */ {TSL_STATEMASK_DEB_ERROR_CALIB, TSL_tkey_DebErrorStateProcess},
    /* 15 */ {TSL_STATEMASK_DEB_ERROR_RELEASE, TSL_tkey_DebErrorStateProcess},
    /* 16 */ {TSL_STATEMASK_DEB_ERROR_PROX, TSL_tkey_DebErrorStateProcess},
    /* 17 */ {TSL_STATEMASK_DEB_ERROR_DETECT, TSL_tkey_DebErrorStateProcess},
    /* 18 */ {TSL_STATEMASK_DEB_ERROR_TOUCH, TSL_tkey_DebErrorStateProcess},
    // Other states
    /* 19 */ {TSL_STATEMASK_OFF, OffStateProcess}};

// Methods for "extended" type (ROM)
CONST TSL_TouchKeyMethods_T TKeys_Methods = {TSL_tkey_Init, TSL_tkey_Process};

CONST TSL_State_T LinRots_StateMachine[] = {
    // Calibration states
    /*  0 */ {TSL_STATEMASK_CALIB, TSL_linrot_CalibrationStateProcess},
    /*  1 */ {TSL_STATEMASK_DEB_CALIB, TSL_linrot_DebCalibrationStateProcess},
    // Release states
    /*  2 */ {TSL_STATEMASK_RELEASE, TSL_linrot_ReleaseStateProcess},
#if TSLPRM_USE_PROX > 0
    /*  3 */ {TSL_STATEMASK_DEB_RELEASE_PROX, TSL_linrot_DebReleaseProxStateProcess},
#else
    /*  3 */ {TSL_STATEMASK_DEB_RELEASE_PROX, 0},
#endif
    /*  4 */ {TSL_STATEMASK_DEB_RELEASE_DETECT, TSL_linrot_DebReleaseDetectStateProcess},
    /*  5 */ {TSL_STATEMASK_DEB_RELEASE_TOUCH, TSL_linrot_DebReleaseTouchStateProcess},
#if TSLPRM_USE_PROX > 0
    // Proximity states
    /*  6 */ {TSL_STATEMASK_PROX, TSL_linrot_ProxStateProcess},
    /*  7 */ {TSL_STATEMASK_DEB_PROX, TSL_linrot_DebProxStateProcess},
    /*  8 */ {TSL_STATEMASK_DEB_PROX_DETECT, TSL_linrot_DebProxDetectStateProcess},
    /*  9 */ {TSL_STATEMASK_DEB_PROX_TOUCH, TSL_linrot_DebProxTouchStateProcess},
#else
    /*  6 */ {TSL_STATEMASK_PROX, 0},
    /*  7 */ {TSL_STATEMASK_DEB_PROX, 0},
    /*  8 */ {TSL_STATEMASK_DEB_PROX_DETECT, 0},
    /*  9 */ {TSL_STATEMASK_DEB_PROX_TOUCH, 0},
#endif
    // Detect states
    /* 10 */ {TSL_STATEMASK_DETECT, TSL_linrot_DetectStateProcess},
    /* 11 */ {TSL_STATEMASK_DEB_DETECT, TSL_linrot_DebDetectStateProcess},
    // Touch state
    /* 12 */ {TSL_STATEMASK_TOUCH, TSL_linrot_TouchStateProcess},
    // Error states
    /* 13 */ {TSL_STATEMASK_ERROR, ErrorStateProcess},
    /* 14 */ {TSL_STATEMASK_DEB_ERROR_CALIB, TSL_linrot_DebErrorStateProcess},
    /* 15 */ {TSL_STATEMASK_DEB_ERROR_RELEASE, TSL_linrot_DebErrorStateProcess},
    /* 16 */ {TSL_STATEMASK_DEB_ERROR_PROX, TSL_linrot_DebErrorStateProcess},
    /* 17 */ {TSL_STATEMASK_DEB_ERROR_DETECT, TSL_linrot_DebErrorStateProcess},
    /* 18 */ {TSL_STATEMASK_DEB_ERROR_TOUCH, TSL_linrot_DebErrorStateProcess},
    // Other states
    /* 19 */ {TSL_STATEMASK_OFF, OffStateProcess}};

// Methods for "extended" type (ROM)
CONST TSL_LinRotMethods_T LinRots_Methods = {TSL_linrot_Init, TSL_linrot_Process, TSL_linrot_CalcPos};

// Data (RAM)
TSL_LinRotData_T LinRots_Data[TSLPRM_TOTAL_LNRTS];

// Parameters (RAM)
TSL_LinRotParam_T LinRots_Param[TSLPRM_TOTAL_LNRTS];
}
}
